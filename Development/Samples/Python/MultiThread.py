#!/usr/bin/python3

import numpy as np
import cv2
from ctypes import *
import os.path
import sys
import os
import signal
import threading
import time
import datetime
import win32gui
import win32con

#加载模块
os.environ['path'] += ';..\\..\\KSJApi.Bin\\x64';

libKsj = WinDLL("KSJApi64.dll")

libc = cdll.LoadLibrary('msvcrt.dll')

#相机初始化
libKsj.KSJ_Init()

#获取相机的数目
camCount = libKsj.KSJ_DeviceGetCount()
print("cam count: %d" % (camCount))

#获取相加的设备等
usDeviceType = c_int()
nSerials = c_int()
usFirmwareVersion = c_int()
libKsj.KSJ_DeviceGetInformation(0, byref(usDeviceType), byref(nSerials), byref(usFirmwareVersion))
print("Device Type = %d" % (usDeviceType.value))
print("Serials = %d" % (nSerials.value))
print("FirmwareVersion = %d" % (usFirmwareVersion.value))

#获取相机的实际参数
nWidth = c_int()
nHeight = c_int()
nBitCount = c_int()
libKsj.KSJ_CaptureGetSizeEx(0, byref(nWidth), byref(nHeight), byref(nBitCount))
print("width = %d" % (nWidth.value))
print("height = %d" % (nHeight.value))
print("bitcount = %d" % (nBitCount.value))

#开取内存空间
# 保留内存的大小
gBufferSize = c_int()
gBufferSize = int(nWidth.value * nHeight.value * nBitCount.value / 8);

gpProcessImageData = create_string_buffer(gBufferSize)

gnWidth = nWidth
gnHeight =  nHeight
gnBitCount= nBitCount

# 标记图像处理线程是否等待数据
# 标记图像缓存里面数据是否已经满了

nThreadFlag = c_int()

def view_image():
    global g_BufferIsFull,lock
    def wndProc(hwnd, msg, wParam, lParam):
        if msg == win32con.WM_SIZE: print("message: WM_SIZE")
        if msg == win32con.WM_PAINT: print("message: WM_PAINT")
        if msg == win32con.WM_CLOSE: print("message: WM_CLOSE")
        if msg == win32con.WM_DESTROY:
            timer_continue = 0
            print("message: WM_DESTROY")
            win32gui.PostQuitMessage(0)
        return win32gui.DefWindowProc(hwnd, msg, wParam, lParam)

    def preViewCallBack(pImageData, nWidth0, nHeight0, nBitCount0, pParam):
        global g_BufferIsFull, gpProcessImageData,nbufferSize,gnWidth,gnHeight,gnBitCount
        # 图像是空的，可以把图像拷贝过去
        if g_BufferIsFull == 0:
            print("copy to buffer....")
            memmove(byref(gpProcessImageData), pImageData, gBufferSize)
            gnWidth = nWidth0
            gnHeight = nHeight0
            gnBitCount = nBitCount0
            g_BufferIsFull = 1
    # 注册一个窗口类
    wc = win32gui.WNDCLASS()
    wc.lpszClassName = 'MyWindow'
    wc.hbrBackground = win32con.COLOR_BTNFACE + 1  # 这里颜色用法有点特殊，必须+1才能得到正确的颜色
    wc.lpfnWndProc = wndProc  # 可以用一个函数，也可以用一个字典
    class_atom = win32gui.RegisterClass(wc)

    # 设置回调
    CamCall = CFUNCTYPE(None, c_longlong, c_int, c_int, c_int, c_longlong)
    cpreViewCallBack = CamCall(preViewCallBack)
    libKsj.KSJ_PreviewSetCallback(0, cpreViewCallBack, c_longlong(0))

    # 创建窗口
    hwnd = win32gui.CreateWindow(class_atom, u'wkkShow', win32con.WS_OVERLAPPEDWINDOW,0, 0, 600, 400,0,0, 0, None)
    # 设置预览窗口
    libKsj.KSJ_PreviewSetPos(0, hwnd , 0, 0, 600, 400)
    # 把窗口显示出来
    win32gui.ShowWindow(hwnd, win32con.SW_SHOWNORMAL)
    # 开启预览
    libKsj.KSJ_PreviewStart(0,1)

    # 进入窗口消息循环
    win32gui.PumpMessages()



def Pro_image():
    global count_tickq, g_BufferIsFull,lock
    global gpProcessImageData, gnWidth, gnHeight, gnBitCount

    while nThreadFlag:        
        #lock.acquire()
        # 有新的图像了，开始处理
        if g_BufferIsFull == 1:
            if count_tickq == 1:
                pBmpfile = create_string_buffer(b'test01.bmp', 64)
                retValue = libKsj.KSJ_HelperSaveToBmp(byref(gpProcessImageData), gnWidth, gnHeight, gnBitCount, byref(pBmpfile))
            if count_tickq == 2:
                pBmpfile = create_string_buffer(b'test02.bmp', 64)
                retValue = libKsj.KSJ_HelperSaveToBmp(byref(gpProcessImageData), gnWidth, gnHeight, gnBitCount, byref(pBmpfile))
            if count_tickq == 3:
                pBmpfile = create_string_buffer(b'test03.bmp', 64)
                retValue = libKsj.KSJ_HelperSaveToBmp(byref(gpProcessImageData), gnWidth, gnHeight, gnBitCount, byref(pBmpfile))
            if count_tickq == 4:
                pBmpfile = create_string_buffer(b'test04.bmp', 64)
                retValue = libKsj.KSJ_HelperSaveToBmp(byref(gpProcessImageData), gnWidth, gnHeight, gnBitCount, byref(pBmpfile))
            if count_tickq == 5:
                pBmpfile = create_string_buffer(b'test05.bmp', 64)
                retValue = libKsj.KSJ_HelperSaveToBmp(byref(gpProcessImageData), gnWidth, gnHeight, gnBitCount, byref(pBmpfile))
            if count_tickq == 6:
                pBmpfile = create_string_buffer(b'test06.bmp', 64)
                retValue = libKsj.KSJ_HelperSaveToBmp(byref(gpProcessImageData), gnWidth, gnHeight, gnBitCount, byref(pBmpfile))
            if count_tickq == 7:
                pBmpfile = create_string_buffer(b'test07.bmp', 64)
                retValue = libKsj.KSJ_HelperSaveToBmp(byref(gpProcessImageData), gnWidth, gnHeight, gnBitCount, byref(pBmpfile))
            if count_tickq == 8:
                count_tick = 0
                pBmpfile = create_string_buffer(b'test08.bmp', 64)
                retValue = libKsj.KSJ_HelperSaveToBmp(byref(gpProcessImageData), gnWidth, gnHeight, gnBitCount, byref(pBmpfile))
            count_tickq = count_tickq + 1
            g_BufferIsFull = 0
        time.sleep(0.01)

        #lock.release()


def QuitAll():
    global nThreadFlag
    print("exit")
    nThreadFlag = 0


if __name__ == '__main__':

    lock = threading.Lock()
    g_BufferIsFull = 0
    count_tickq = 0
    nThreadFlag = 1
    
    try:
        signal.signal(signal.SIGINT, QuitAll)
        a1 = threading.Thread(target=view_image)
        a2 = threading.Thread(target=Pro_image)

        a1.start()
        a2.start()

        while nThreadFlag > 0:
            pass

    except Exception as exc:
        print(exc)






