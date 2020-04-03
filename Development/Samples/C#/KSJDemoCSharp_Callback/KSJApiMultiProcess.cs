using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.InteropServices;

namespace KSJApi_MultiProcess
{
    class KSJApiMultiProcess
    {
                // 参考“凯视佳工业相机内部API函数说明书（多进程控制相机篇）”
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_Open(int nChannel);
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_Close(int nChannel);

        // 关闭指定索引的设备，注意所有第一个参数为nChannle的函数都会自动打开指定的相机，如果不关闭指定相机，那么在多进程下是不能操作这台相机的。
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_DeviceClose(int nChannel);
        public enum KSJ_DEVICESTATUS { KSJ_DS_CLOSE, KSJ_DS_OPEN };
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_DeviceGetStatus(int nChannel, ref KSJ_DEVICESTATUS pDs);

    }
}
