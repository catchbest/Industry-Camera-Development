using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.InteropServices;

namespace KSJApi_Matrix
{
    class KSJApiMatrix
    {
        // SWB - Software White Balance; HWB - Hardware White Balance
        public enum KSJ_WB_MODE
        {
            KSJ_WB_DISABLE,
            KSJ_SWB_PRESETTINGS,
            KSJ_SWB_AUTO_ONCE,
            KSJ_SWB_AUTO_CONITNUOUS,
            KSJ_SWB_MANUAL,
            KSJ_HWB_PRESETTINGS,
            KSJ_HWB_AUTO_ONCE,
            KSJ_HWB_AUTO_CONITNUOUS,
            KSJ_HWB_MANUAL
        };

        // Set White Balance Matrix Mode
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_WhiteBalanceSet(int nChannel, KSJ_WB_MODE WbMode);
        // Get White Balance Matrix Mode
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_WhiteBalanceGet(int nChannel, ref KSJ_WB_MODE pWbMode);

        // Set nPhi when KSJ_SWB_AUTO_ONCE or KSJ_SWB_AUTO_CONITNUOUS
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_WhiteBalanceAutoSet(int nChannel, int nPhi);
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_WhiteBalanceAutoGet(int nChannel, ref int pnPhi);


        // Set when KSJ_SWB_MANUAL or KSJ_HWB_MANUAL
        // Rw = fMatrix[0] * R, Gw = fMatrix[1] * G, Bw = fMatrix[1] * B
        // Range 0 - 5
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_WhiteBalanceMatrixSet(int nChannel, float[] fMatrix);
        // You can get current White Balance Matrix on Image
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_WhiteBalanceMatrixGet(int nChannel, float[] fMatrix);

        // Call Callback Function When KSJ_AWB_AUTO_ONCE or KSJ_AWB_AUTO_CONITNUOUS Done. Finall Matrix will Return.
        public delegate void KSJ_WB_CALLBACK(float[] fMatrix, IntPtr lpContext);
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_WhiteBalanceAutoSetCallBack(int nChannel, KSJ_WB_CALLBACK    pfCallBack, IntPtr lpContext);      // The nPhi decide auto calculate Matrix.

        // Call Callback Function When KSJ_AWB_AUTO_ONCE or KSJ_AWB_AUTO_CONITNUOUS Done. Finall Matrix will Return.
        public delegate void KSJ_WB_CALLBACK_EX(float fMatrixR, float fMatrixG, float fMatrixB, IntPtr lpContext);
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_WhiteBalanceAutoSetCallBackEx(int nChannel, KSJ_WB_CALLBACK_EX pfCallBackEx, IntPtr lpContext);

        public enum KSJ_COLOR_TEMPRATURE 
        { 
            KSJ_CT_5000K, 
            KSJ_CT_6500K, 
            KSJ_CT_2800K 
        };
        // Set Preseting White Balance Matrix according to Color Temprature when in KSJ_SWB_PRESETTINGS or KSJ_HWB_PRESETTINGS.
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_WhiteBalancePresettingSet(int nChannel, KSJ_COLOR_TEMPRATURE WbPresetting);
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_WhiteBalancePresettingGet(int nChannel, ref KSJ_COLOR_TEMPRATURE pWbPresetting);


        // SCCM - Software Color Correction Matrix; HCCM - Hardware Color Correction Matrix
        public enum KSJ_CCM_MODE
        {
            KSJ_CCM_DISABLE,
            KSJ_SCCM_PRESETTINGS,
            KSJ_SCCM_MANUAL,
            KSJ_HCCM_PRESETTINGS,
            KSJ_HCCM_MANUAL
        };

        [DllImport("KSJApi.dll")]
        public static extern int KSJ_ColorCorrectionSet(int nChannel, KSJ_CCM_MODE CcmMode);
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_ColorCorrectionGet(int nChannel, ref KSJ_CCM_MODE pCcmMode);


        // Set Color Correction Matrix when in KSJ_SCCM_MANUAL or KSJ_HCCM_MANUAL
        // Rc = fMatrix[0][0] * Rw + fMatrix[0][1] * Gw + fMatrix[0][2] * Bw
        // Range -5 - 5
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_ColorCorrectionMatrixSet(int nChannel, float[][] fMatrix);
        // Get current Color Correction Matrix on Image
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_ColorCorrectionMatrixGet(int nChannel, float[][] fMatrix);


        // Set Preseting Color Correction Matrix according to Color Temprature when KSJ_SCCM_PRESETTINGS or KSJ_HCCM_PRESETTINGS.
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_ColorCorrectionPresettingSet(int nChannel, KSJ_COLOR_TEMPRATURE CcmPresetting);
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_ColorCorrectionPresettingGet(int nChannel, ref KSJ_COLOR_TEMPRATURE pCcmPresetting);


    }
}
