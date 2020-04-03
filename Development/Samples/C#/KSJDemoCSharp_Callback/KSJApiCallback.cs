using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.InteropServices;

namespace KSJApi_Callback
{
    class KSJApiCallback
    {
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_GetADCResolution(int nChannel, ref int pnADCResolution);
        // Preview Callback
        public delegate void KSJ_PREVIEWCALLBACK(IntPtr pImageData, int nWidth, int nHeight, int nBitCount, IntPtr lpContext);
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_PreviewSetCallback(int nChannel, KSJ_PREVIEWCALLBACK pfPreviewCallback, IntPtr lpContext);

        public delegate void KSJ_PREVIEWCALLBACKEX(IntPtr hDC, IntPtr pImageData, int nWidth, int nHeight, int nBitCount, IntPtr lpContext);
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_PreviewSetCallbackEx(int nChannel, KSJ_PREVIEWCALLBACKEX pfPreviewCallbackEx, IntPtr lpContext);

    }
}
