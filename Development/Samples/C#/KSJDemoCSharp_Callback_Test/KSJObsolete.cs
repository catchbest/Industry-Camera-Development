using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.InteropServices;

namespace KSJ_Obsolete
{
    class KSJObsolete
    {
        
        // 打开或关闭Gamma校正，即影响预览又影响采集
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_GammaOn(int nChannel, bool bOn);    // Not Support Now.


        // 设置固定帧速(通过设置sensor寄存器,使sensor输出固定帧率)，只有MUC36C/M(MGYY)和MU3E130C/M(CGYY)支持
        // V4.0.86.12版本开始，bEnable参数无效，通过用户设置KSJ_TRIGGER_FIXFRAMERATE模式来决定是否使能。
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_SetFixedFrameRate(int nChannel, bool bEnable, float fFrameRate);
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_GetFixedFrameRate(int nChannel, ref bool pbEnable, ref float pfFrameRate);

        // 闪光灯信号输出到实际相机输出的延时设置（暂不支持）
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_StrobeDelaySet(int nChannel, ushort wDelay);
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_StrobeDelayGet(int nChannel, ref ushort pwDelay);
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_StrobeDelayGetRange(int nChannel, ref ushort wMin, ref ushort wMax);


        // 设置图像传感器的工作方式（暂不支持）
        public enum KSJ_SENSORMODE { KSJ_SM_TRIGGER_MODE, KSJ_SM_FREERUN_MODE, KSJ_SM_GRR_MODE };
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_SensorModeSet(int nChannel, KSJ_SENSORMODE SensorMode);
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_SensorModeGet(int nChannel, ref KSJ_SENSORMODE SensorMode);

        ///////////////////////////////////////////////Color Correction////////////////////////////////////////////////////////////////
        public delegate void KSJ_CCCALLBACK(bool bSuccess, int nRShift, int nGShift, int nBShift, IntPtr lpContext);

        // 如下函数为软件颜色校正
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_ColorCorrectSetCallback( int nChannel, KSJ_CCCALLBACK fpCCCallback, IntPtr lpContext );

        public enum KSJ_COLORCORRECT { KSJ_CC_NONE, KSJ_CC_SHIFTRGB, KSJ_CC_EQRGB, KSJ_CC_EQALL, KSJ_CC_WB };
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_ColorCorrectSet  ( int nChannel, KSJ_COLORCORRECT ColorCorrect, int nRTarget, int nGTarget, int nBTarget );
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_ColorCorrectGet  ( int nChannel, ref KSJ_COLORCORRECT pColorCorrect );
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_ColorCorrectGetEx( int nChannel, ref KSJ_COLORCORRECT pColorCorrect, ref int pnRTarget, ref int pnGTarget, ref int pnBTarget );

        [DllImport("KSJApi.dll")]
        public static extern int KSJ_ColorCorrectTableSave( int nChannel, string pszFileName );
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_ColorCorrectTableLoad(int nChannel, string pszFileName);
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_IsColorCorrectTableLoad( int nChannel, ref bool bLoad );

    }
}
