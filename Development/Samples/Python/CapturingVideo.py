#!/usr/bin/python3

import numpy as np
import time
import datetime
import cv2
from ctypes import *
import os.path
import sys
import os

os.environ['path'] += ';..\\..\\KSJApi.Bin\\x64';

libKsj = WinDLL("KSJApi64.dll")

libKsj.KSJ_Init()

camCount = libKsj.KSJ_DeviceGetCount()
print("cam count: %d" % (camCount))

usDeviceType = c_int()
nSerials = c_int()
usFirmwareVersion = c_int()
# 取得第一个(0)相机的信息
libKsj.KSJ_DeviceGetInformation(0, byref(usDeviceType), byref(nSerials), byref(usFirmwareVersion))
print("Device Type = %d" % (usDeviceType.value))
print("Serials = %d" % (nSerials.value))
print("FirmwareVersion = %d" % (usFirmwareVersion.value))

# 取得第一个相机的图像尺寸
nWidth = c_int()
nHeight = c_int()
nBitCount = c_int()
libKsj.KSJ_CaptureGetSizeEx(0, byref(nWidth), byref(nHeight), byref(nBitCount))
print("width = %d" % (nWidth.value))
print("height = %d" % (nHeight.value))
print("bitcount = %d" % (nBitCount.value))

# 设置一下曝光500ms
libKsj.KSJ_ExposureTimeSet.argtypes = (c_int, c_float)
libKsj.KSJ_ExposureTimeSet(0, 1000);
fexpTime = c_float()
libKsj.KSJ_ExposureTimeGet(0, byref(fexpTime));
print("fexpTime = %d" % (fexpTime.value))
        

# 做一下flip
bayermode = c_int();
libKsj.KSJ_BayerGetMode(0, byref(bayermode));
libKsj.KSJ_BayerSetMode(0, bayermode.value + 4);
           
		   
libKsj.KSJ_TriggerModeSet(0, 0)
libKsj.KSJ_SetFixedFrameRateEx(0, 30)
 
# 取得第一个相机的触发模式
trigermode = c_int();
libKsj.KSJ_TriggerModeGet(0, byref(trigermode))
print("trigermode =  {0}".format(trigermode.value))

nbufferSize = nWidth.value * nHeight.value * nBitCount.value / 8
pRawData = create_string_buffer(int(nbufferSize))

avi_path = './'
ts = time.time()
st = datetime.datetime.fromtimestamp(ts).strftime('%Y%m%d%H%M%S')
# fourcc = cv2.VideoWriter_fourcc(*'MJPG')
fourcc = cv2.VideoWriter_fourcc(*'XVID')
out = cv2.VideoWriter(avi_path + st+'.avi',fourcc, 10.0, (nWidth.value, nHeight.value))


while 1:
        # 读取图像
        retValue = libKsj.KSJ_CaptureRgbData(0, pRawData)
        # 把内存数据转换成图像格式
        image = np.frombuffer(pRawData, np.uint8).reshape(nHeight.value, nWidth.value, int(nBitCount.value/8))

        if retValue != 1:
                print("capture error code %d" % (retValue))
        else:
                # 保存到视频文件
                out.write(image)
                # 显示图像
                shw_image = cv2.resize(image, (640, 480))
                cv2.imshow('frame',shw_image)
                if cv2.waitKey(30) & 0xFF == ord('q'):
                        break;


out.release()
cv2.destroyAllWindows()

print("===== end =====")

