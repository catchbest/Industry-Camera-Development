using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.InteropServices;

namespace KSJApi_WaterMark
{
    class KSJApiWaterMark
    {
        // 相关功能查询KSJ_SUPPORT_WATERMAK
        public enum KSJ_WATERMARKMODE { KSJ_WMM_TIMESTAMP, KSJ_WMM_DISTINGUISH_EXTERNAL_TRIGGER, KSJ_WMM_ANALYSIS_EXTERNAL_TRIGGER };

        [DllImport("KSJApi.dll")]
        public static extern int KSJ_WaterMarkSetMode(int nChannel, KSJ_WATERMARKMODE WaterMarkMode);
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_WaterMarkGetMode(int nChannel, ref KSJ_WATERMARKMODE pWaterMarkMode);

        [DllImport("KSJApi.dll")]
        public static extern int KSJ_WaterMarkSetEnable(int nChannel, bool bEnable);
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_WaterMarkGetEnable(int nChannel, ref bool pbEnable);

        [DllImport("KSJApi.dll")]
        public static extern int KSJ_WaterMarkGetInfo(int nChannel, ref ushort pwId, ref ulong pdwTimestampLowPart, ref ulong pdwTimestampHighPart);

    }
}
