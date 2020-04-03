using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.InteropServices;

namespace KSJ_Api16Bits
{
    class KSJApi16Bits
    {
        // Get AD Resolution. Valid bits in 16 bits.
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_GetADCResolution(int nChannel, ref int pnADCResolution);
        // Set 16bits Transfer, Image Data Bytes Number doubled.
        [DllImport("KSJApi.dll")]
        public static extern int  KSJ_SetData16Bits(int nChannel, bool bEnable);
        // Get If 16bits Transfer
        [DllImport("KSJApi.dll")]
        public static extern int  KSJ_GetData16Bits(int nChannel, ref bool bEnable);
        // Get Capture Image Information. nBitsPerSample = 8 when not 16bits. = 16 when 16 bits.
        // Allocate Capture buffer according to these information.
        [DllImport("KSJApi.dll")]
        public static extern int  KSJ_CaptureGetSizeExEx(int nChannel, ref int pnWidth, ref int pnHeight, ref int pnBitCount, ref int nBitsPerSample);
        // Save to Tiff Format.
        // When Not 16Bits, nBitPerSample = 8; When 16 Bits, nBitPerSample = 16
        // when BitCount = 8, nSamplesPerPixel = 1; When Bitcount = 24, nSamplesPerPixel = 3; When Bitcount = 32, nSamplesPerPixel = 4
        [DllImport("KSJApi.dll")]
        public static extern int  KSJ_HelperSaveToTiff(ref byte pData, int nWidth, int nHeight, int nBitPerSample, int nSamplesPerPixel, string pszFileName);
    }
}
