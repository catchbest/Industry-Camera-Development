using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.InteropServices;
using KSJCamera;
namespace KSJApi_MultiFrames
{
    class KSJApiMultiFrames
    {
        // Set Preview MultiFrames Field Of View
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_PreviewSetFieldOfViewEx(int nChannel, int nColStart, int nRowStart, int nColSize, int nRowSize, KSJApiBase.KSJ_ADDRESSMODE ColAddressMode, KSJApiBase.KSJ_ADDRESSMODE RowAddressMode, byte wMultiFrameNum);
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_PreviewGetFieldOfViewEx(int nChannel, ref int pnColStart, ref int pnRowStart, ref int pnColSize, ref int pnRowSize, ref KSJApiBase.KSJ_ADDRESSMODE pColAddressMode, ref KSJApiBase.KSJ_ADDRESSMODE pRowAddressMode, ref byte pwMultiFrameNum);
        // Set Capture MultiFrames Field Of View
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_CaptureSetFieldOfViewEx(int nChannel, int nColStart, int nRowStart, int nColSize, int nRowSize, KSJApiBase.KSJ_ADDRESSMODE ColAddressMode, KSJApiBase.KSJ_ADDRESSMODE RowAddressMode, byte wMultiFrameNum);
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_CaptureGetFieldOfViewEx(int nChannel, ref int pnColStart, ref int pnRowStart, ref int pnColSize, ref int pnRowSize, ref KSJApiBase.KSJ_ADDRESSMODE pColAddressMode, ref KSJApiBase.KSJ_ADDRESSMODE pRowAddressMode, ref byte pwMultiFrameNum);

    }
}
