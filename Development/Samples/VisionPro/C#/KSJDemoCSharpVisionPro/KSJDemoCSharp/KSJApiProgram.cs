using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.InteropServices;

namespace KSJApi_Program
{
    class KSJApiProgram
    {
        	// 参考“凯视佳工业相机内部API函数说明书（初始化厂商读写区域篇）”
        // Program and Modify Serials
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_SetSerials(int nChannel, byte btSerials);
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_GetSerials(int nChannel, ref byte pbtSerials);

        [DllImport("KSJApi.dll")]
        public static extern int KSJ_WorkingModeProgram(int nChannel, ushort wValue);
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_WorkingModeReadout(int nChannel, ref ushort pValue);

        [DllImport("KSJApi.dll")]
        public static extern int KSJ_WorkingModeExProgram(int nChannel, ushort wValue);
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_WorkingModeExReadout(int nChannel, ref ushort pValue);

        [DllImport("KSJApi.dll")]
        public static extern int KSJ_ColorModeProgram(int nChannel, ushort wValue);
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_ColorModeReadout(int nChannel, ref ushort pValue);
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_SerialsDescProgram(int nChannel, byte[] btDesc);
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_SerialsDescReadout(int nChannel, byte[] btDesc);

        [DllImport("KSJApi.dll")]
        public static extern int KSJ_LutInfoProgram(int nChannel, ushort wValue);
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_LutInfoReadout(int nChannel, ref ushort pValue);

        [DllImport("KSJApi.dll")]
        public static extern int KSJ_GammaLutInfoProgram(int nChannel, ushort wValue);
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_GammaLutInfoReadout(int nChannel, ref ushort pValue);

        [DllImport("KSJApi.dll")]
        public static extern int KSJ_HWBMatrixProgram(int nChannel, float[] fMatrix);
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_HWBMatrixReadout(int nChannel, float[] fMatrix);
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_HWBMatrixUpload(int nChannel, float[] fMatrix);

        [DllImport("KSJApi.dll")]
        public static extern int KSJ_HCCMMatrixProgram(int nChannel, float[][] fMatrix);
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_HCCMMatrixReadout(int nChannel, float[][] fMatrix);
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_HCCMMatrixUpload(int nChannel, float[][] fMatrix);

        [DllImport("KSJApi.dll")]
        public static extern int KSJ_LutFileProgram(int nChannel, string pszFile);
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_LutDataProgram(int nChannel, byte[] pData, int nBytes);
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_LutDataReadout(int nChannel, byte[] pData, ref int pnBytes);

        [DllImport("KSJApi.dll")]
        public static extern int KSJ_GammaLutFileProgram(int nChannel, string pszFile);
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_GammaLutDataProgram(int nChannel, byte[] pData, int nWords);
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_GammaLutDataReadout(int nChannel, byte[] pData, ref int pnWords);

    }
}
