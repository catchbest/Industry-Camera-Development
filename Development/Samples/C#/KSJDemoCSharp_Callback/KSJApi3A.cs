using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.InteropServices;

namespace KSJ_API3A
{
    class KSJApi3A
    {
        // 设置自动曝光的区域，这个区域是相对预览图像的左上角像素位置
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_AESetRegion(int nChannel, int nX, int nY, int nW, int nH);
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_AESetMaxCount(int nChannel, int nMaxCount);

        // 自动曝光回调函数
        public delegate void KSJ_AECALLBACK(bool bSuccess, int nRValue, int nGValue, int nBValue, IntPtr lpContext);
        // 定义自动曝光操作结束后的回调函数，当自动曝光结束时，KSJ开发包会自动调用AECallback用户指定的回调函数
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_AWBSetCallback(int nChannel, KSJ_AECALLBACK fpAWBCallback, IntPtr lpContext);
        // 开始或终止自动曝光调节
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_AEStart(int nChannel, bool bStart, int nMaxCount, int nTarget);
        // 设置自动白平衡区域，这个区域是相对预览图像的左上角像素位置
         [DllImport("KSJApi.dll")]
        public static extern int KSJ_AWBSetRegion(int nChannel, int nX, int nY, int nW, int nH);
        // 自动白平衡回调函数
         public delegate void KSJ_AWBCALLBACK(bool bSuccess, int nRValue, int nGValue, int nBValue, IntPtr lpContext);
        // 定义自动白平衡（操作硬件）操作结束后的回调函数，当自动曝光结束时，KSJ开发包会自动调用AECallback用户指定的回调函数
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_AWBSetCallback(int nChannel, KSJ_AWBCALLBACK fpAWBCallback, IntPtr lpContext);
        // 开始或终止自动白平衡调节
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_AWBStart(int nChannel, bool bStart, int nMaxCount, int nRTarget, int nGTarget, int nBTarget);
        // 设置聚焦评估区域
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_AFSetRegion(int nChannel, int nX, int nY, int nW, int nH);
        // 聚焦评估回调函数, nValue为返回的评估值
        public delegate void KSJ_AFCALLBACK( int nValue, IntPtr lpContext );
        // 设置聚焦评估回调
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_AFSetCallback(int nChannel, KSJ_AFCALLBACK fpAFCallback, IntPtr lpContext);
        // 开始或终止聚焦评估
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_AFStart(int nChannel, bool bStart);
        // 硬件自动曝光
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_AECSetEnable ( int nChannel, bool bEnable  );
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_AECGetEnable ( int nChannel, ref bool bEnable  );
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_AECSetRange ( int nChannel, ushort usMin,  ushort usMax  );
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_AECGetRange ( int nChannel, ref ushort usMin, ref ushort usMax );
        // 得到自动曝光调节的当前曝光值
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_AECGetCur ( int nChannel, ref ushort usCurGain  );
        // 硬件自动增益
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_AGCSetEnable ( int nChannel, bool bEnable  );
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_AGCGetEnable ( int nChannel, ref bool bEnable  );
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_AGCSetRange ( int nChannel, ushort usMin,  ushort usMax  );
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_AGCGetRange ( int nChannel, ref ushort usMin, ref ushort usMax );
        // 得到自动增益调节的当前增益值
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_AGCGetCur ( int nChannel, ref ushort usCurGain  );
    }
}
