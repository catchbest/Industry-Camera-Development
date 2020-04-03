using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.InteropServices;

namespace KSJApi_TriggerMode
{
    class KSJApiTriggerMode
    {
        	// Trigger Mode
        public enum KSJ_TRIGGERMODE
        {
            KSJ_TRIGGER_INTERNAL,
            KSJ_TRIGGER_EXTERNAL,
            KSJ_TRIGGER_SOFTWARE,
            KSJ_TRIGGER_FIXFRAMERATE
        };

        // Set Trigger Mode
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_TriggerModeSet(int nChannel, KSJ_TRIGGERMODE TriggerMode);
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_TriggerModeGet(int nChannel, ref KSJ_TRIGGERMODE pTriggerMode);

        public enum KSJ_TRIGGERSTATUS
        {
            KSJ_NO,
            KSJ_HAVE
        };

        // Get Frame Buffer Status. Has One or more Frame or None. Maybe return RET_NOTSUPPORT.
        // When Fpga Version is not 0.0, This Function should support.
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_TriggerStatusGet(int nChannel, ref KSJ_TRIGGERSTATUS pTriggerStatus);

        // Empty Frame Buffer. Not Support When In KSJ_TRIGGER_SOFTWARE Mode.
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_EmptyFrameBuffer(int nChannel);

        // Same to call KSJ_EmptyFrameBuffer before KSJ_CaptureRawData. Not Support When In KSJ_TRIGGER_SOFTWARE Mode.
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_CaptureRawDataAfterEmptyFrameBuffer(int nChannel, ref byte pRawData);
        // Same to call KSJ_EmptyFrameBuffer before KSJ_CaptureRgbData. Not Support When In KSJ_TRIGGER_SOFTWARE Mode.
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_CaptureRgbDataAfterEmptyFrameBuffer(int nChannel, ref byte pRgbData);
        // Same to call KSJ_EmptyFrameBuffer before KSJ_CaptureRgbDataEx. Not Support When In KSJ_TRIGGER_SOFTWARE Mode.
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_CaptureRgbDataExAfterEmptyFrameBuffer(int nChannel, ref byte pRgbData, ref int pnWidth, ref int pnHeight, ref int pnBitCount);


        // Fixed Frame Rate when in KSJ_TRIGGER_FIXFRAMERATE mode. Maybe Return RET_NOTSUPPORT.
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_SetFixedFrameRateEx(int nChannel, float fFrameRate);
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_GetFixedFrameRateEx(int nChannel, ref float pfFrameRate);

        public enum KSJ_TRIGGERMETHOD
        {
            KSJ_TRIGGER_FALLINGEDGE,
            KSJ_TRIGGER_RISINGEDGE,
            KSJ_TRIGGER_HIGHLEVEL,
            KSJ_TRIGGER_LOWLEVEL
        };
        // Set Trigger Method when in KSJ_TRIGGER_EXTERNAL mode.
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_TriggerMethodSet(int nChannel, KSJ_TRIGGERMETHOD  TriggerMethod);
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_TriggerMethodGet(int nChannel, ref KSJ_TRIGGERMETHOD pTriggerMethod);

        // Set Trigger Delay when in KSJ_TRIGGER_EXTERNAL. May be Return RET_NOTSUPPORT.
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_TriggerDelayGetRange(int nChannel, ref ushort wMin, ref ushort wMax);
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_TriggerDelaySet(int nChannel, ushort wDelay);
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_TriggerDelayGet(int nChannel, ref ushort pwDelay);

        // Set Read action timeout (ms). Influence capture and preview.
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_CaptureSetTimeOut(int nChannel, uint dwTimeOut);
        // Get Read action image timeout (ms).
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_CaptureGetTimeOut(int nChannel, ref uint pdwTimeOut);

        // Set If recover device when Read Fail. It will Influence capture and preview.
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_CaptureSetRecover(int nChannel, bool bRecover);
        // Get If recover device when Read Fail.
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_CaptureGetRecover(int nChannel, ref bool pbRecover);

        // Set timeout and recover at the same time
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_CaptureSetTimeOutEx(int nChannel, uint dwTimeOut, bool bRecover);
        // Get timeout and recover at the same time
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_CaptureGetTimeOutEx(int nChannel, ref uint pdwTimeOut, ref bool pbRecover);

    }
}
