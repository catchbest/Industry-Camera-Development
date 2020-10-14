#!/usr/bin/python3

import numpy as np
import time
import datetime
from ctypes import *
import os.path
import sys
import os
import time as tm
import win32con
import win32gui
import threading

msvcrt = cdll.msvcrt

os.environ['path'] += ';..\\..\\KSJApi.Bin\\x64';

    
libKsj = WinDLL("KSJApi64.dll")

libKsj.KSJ_Init()

camCount = libKsj.KSJ_DeviceGetCount()
print("cam count: %d" % (camCount))


count_tick = c_int()

usDeviceType = c_int()
nSerials = c_int()
usFirmwareVersion = c_int()
# 取得第一个(0)相机的信息
libKsj.KSJ_DeviceGetInformation(0, byref(usDeviceType), byref(nSerials), byref(usFirmwareVersion))
print("Device Type = %d" % (usDeviceType.value))
print("Serials = %d" % (nSerials.value))
print("FirmwareVersion = %d" % (usFirmwareVersion.value))

count_tick = 0

# 取得第一个相机的图像尺寸
nWidth = c_int()
nHeight = c_int()
nBitCount = c_int()
libKsj.KSJ_CaptureGetSizeEx(0, byref(nWidth), byref(nHeight), byref(nBitCount))
print("width = %d" % (nWidth.value))
print("height = %d" % (nHeight.value))
print("bitcount = %d" % (nBitCount.value))



# 用来标识是否要停止定时线程
timer_continue = 1


# 1秒定时，用来显示帧率
fFrameRateCapture = c_float()
fFrameRateShow = c_float()

def fun_timer():
    libKsj.KSJ_PreviewGetFrameRateEx(0, byref(fFrameRateCapture), byref(fFrameRateShow))
    print("Capture: %.2ffps " % (fFrameRateCapture.value))
    if timer_continue:
        global timer
        timer = threading.Timer(1, fun_timer)
        timer.start()

# 启动定时器
timer = threading.Timer(1, fun_timer)

# 窗口消息处理
def wndProc(hwnd, msg, wParam, lParam):
    if msg == win32con.WM_SIZE: print("message: WM_SIZE")
    if msg == win32con.WM_PAINT: print("message: WM_PAINT")
    if msg == win32con.WM_CLOSE: print("message: WM_CLOSE")
    if msg == win32con.WM_DESTROY:
        timer_continue = 0
        print("message: WM_DESTROY")
        win32gui.PostQuitMessage(0)
    return win32gui.DefWindowProc(hwnd, msg, wParam, lParam)


# 预览回调函数，可以进行图像处理
def preViewCallBack(pImageData, nWidth0, nHeight0, nBitCount0, pParam):
    global count_tick
    if count_tick == 1:
        pBmpfile = create_string_buffer(b'test01.bmp', 64)
        retValue = libKsj.KSJ_HelperSaveToBmp(pImageData, nWidth0, nHeight0, nBitCount0, byref(pBmpfile))
    if count_tick == 2:
        pBmpfile = create_string_buffer(b'test02.bmp', 64)
        retValue = libKsj.KSJ_HelperSaveToBmp(pImageData, nWidth0, nHeight0, nBitCount0, byref(pBmpfile))
    if count_tick == 3:
        pBmpfile = create_string_buffer(b'test03.bmp', 64)
        retValue = libKsj.KSJ_HelperSaveToBmp(pImageData, nWidth0, nHeight0, nBitCount0, byref(pBmpfile))
    if count_tick == 4:
        pBmpfile = create_string_buffer(b'test04.bmp', 64)
        retValue = libKsj.KSJ_HelperSaveToBmp(pImageData, nWidth0, nHeight0, nBitCount0, byref(pBmpfile))
    if count_tick == 5:
        pBmpfile = create_string_buffer(b'test05.bmp', 64)
        retValue = libKsj.KSJ_HelperSaveToBmp(pImageData, nWidth0, nHeight0, nBitCount0, byref(pBmpfile))
    if count_tick == 6:
        pBmpfile = create_string_buffer(b'test06.bmp', 64)
        retValue = libKsj.KSJ_HelperSaveToBmp(pImageData, nWidth0, nHeight0, nBitCount0, byref(pBmpfile))
    if count_tick == 7:
        pBmpfile = create_string_buffer(b'test07.bmp', 64)
        retValue = libKsj.KSJ_HelperSaveToBmp(pImageData, nWidth0, nHeight0, nBitCount0, byref(pBmpfile))
    if count_tick == 8:
        count_tick = 0
        pBmpfile = create_string_buffer(b'test08.bmp', 64)
        retValue = libKsj.KSJ_HelperSaveToBmp(pImageData, nWidth0, nHeight0, nBitCount0, byref(pBmpfile))
    count_tick = count_tick + 1



# 注册一个窗口类
wc = win32gui.WNDCLASS()
wc.lpszClassName = 'MyWindow'
wc.hbrBackground = win32con.COLOR_BTNFACE+1 #这里颜色用法有点特殊，必须+1才能得到正确的颜色
wc.lpfnWndProc = wndProc #可以用一个函数，也可以用一个字典
class_atom=win32gui.RegisterClass(wc)
# 创建窗口
hwnd = win32gui.CreateWindow(
    class_atom, u'KSJShow', win32con.WS_OVERLAPPEDWINDOW,
    0, 0, 600, 400,
    0,0, 0, None)

# 设置预览窗口
libKsj.KSJ_PreviewSetPos(0, hwnd, 0, 0, 600, 400);

# 设置回调
CamCall = CFUNCTYPE(None, c_longlong, c_int, c_int, c_int, c_longlong)
cpreViewCallBack = CamCall(preViewCallBack)
libKsj.KSJ_PreviewSetCallback(0, cpreViewCallBack, c_longlong(0))

# 把窗口显示出来
win32gui.ShowWindow(hwnd, win32con.SW_SHOWNORMAL)

# 开启预览
libKsj.KSJ_PreviewStart(0, 1)
timer.start()

# 进入窗口消息循环
win32gui.PumpMessages()

timer_continue = 0
libKsj.KSJ_PreviewStart(0, 0)

libKsj.KSJ_UnInit()

print("===== end =====")

