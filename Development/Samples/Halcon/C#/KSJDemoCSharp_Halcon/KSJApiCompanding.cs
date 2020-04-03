using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.InteropServices;

namespace KSJApi_Companding
{
    class KSJApiCompanding
    {
        // 参考“凯视佳工业相机API函数说明书（查找表篇）”
        // Related API KSJ_GetADCResolution to Get Valid bits of 16bits
        // Please KSJ_QueryFunction ( KSJ_SUPPORT_LUT_DOWNLOAD ) to Get if support download LUT
        // KtbFile Must Created by KSJShow. Download 16 to 8 Look Up Data to Camera, it will lost when power off.
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_LutFileDownload(int nChannel, string pszKtbFile);
        // Download 16 to 8 Look Up Data to Camera, it will lost when power off.
        [DllImport("KSJApi.dll")]
        public static extern int  KSJ_LutDataDownload( int nChannel, byte[] pData, int nBytes   );
        // Enable LUT
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_LutSetEnable( int nChannel, bool bEnable   );
        // Get If LUT Enable
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_LutGetEnable( int nChannel, ref bool pbEnable );

        // Please KSJ_QueryFunction ( KSJ_SUPPORT_GAMMA_LUT_DOWNLOAD ) to Get if support download Gamma LUT
        // KtbFile Must Created by KSJShow. Download 16 to 16 Gamma Look Up Data to Camera, it will lost when power off.
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_GammaLutFileDownload( int nChannel, string pszKtbFile );
        // Download Gamma Look Up Data to Camera, it will lost when power off.
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_GammaLutDataDownload( int nChannel, byte []pData, int nWords );
        // Enable Gamma LUT
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_GammaLutSetEnable( int nChannel, bool bEnable   );
        // Get If Gamma LUT Enable
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_GammaLutGetEnable( int nChannel, ref bool pbEnable );

        // 灵敏度模式设置（使用截取8位方式）
        public enum KSJ_SENSITIVITYMODE 
        {
            KSJ_LOW = 0, 
            KSJ_MID, 
            KSJ_HIGH, 
            KSJ_HIGHER, 
            KSJ_HIGHEST 
        };
        // Related API KSJ_GetADCResolution
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_SensitivitySetMode(int nChannel, KSJ_SENSITIVITYMODE SensitivityMode);
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_SensitivityGetMode(int nChannel, ref KSJ_SENSITIVITYMODE pSensitivityMode);
    }
}
