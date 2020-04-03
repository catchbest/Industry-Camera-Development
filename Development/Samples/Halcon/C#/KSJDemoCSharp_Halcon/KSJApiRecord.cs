using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.InteropServices;

namespace KSJApi_Record
{
    class KSJApiRecord
    {
        // Start or Stop Record. Must Start Preview, Record FOV is equal to Preivew FOV.
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_RecordStart(int nChannel, bool bStart, float fRecordRate, string pFileName);
        // Start or Stop Record if Show Compossor Selection Dialog. Must Start Preview, Record FOV is equal to Preivew FOV.
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_RecordStartEx(int nChannel, bool bStart, float fRecordRate, string pFileName, bool bShowCompossorSelection);

        // Start or Stop Record Use KSJ_RecordAddOneFrame to Add Frame Data.
        // Note: nWidth, nHeight, nBitCount must equal to KSJ_RecordAddOneFrame's parameter
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_RecordStartExEx(int nChannel, bool bStart, float fRecordRate, int nWidth, int nHeight, int nBitCount, string pFileName, bool bShowCompossorSelection);
        // Add one Frame after call KSJ_RecordStartExEx.
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_RecordAddOneFrame(int nChannel, byte[] pFrameData, int nFrameNum, int nWidth, int nHeight, int nBitcount);
        // Get Record Status.
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_RecordStatusGet(int nChannel, ref bool bStart);
    }
}
