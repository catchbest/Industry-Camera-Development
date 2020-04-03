using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.InteropServices;

namespace KSJApi_Custom
{
    class KSJApiCustom
    {
         // 将pData(宽度为nWidth, 高度为nHeight, 比特位数为nBitCount)的图像数据缩放为宽度为nStretchWidh, 高度为nStretchHeight的数据并填充到用户分配的pStretchData缓冲区,比特位数不变
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_HelperStretchBmp(byte[] pData, int nWidth, int nHeight, int nBitCount, byte[] pStretchData, int nStretchWidth, int nStretchHeight);
        // 根据图像的比特深度得到BMP图像的文件头,信息头,及颜色表总的字节数目
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_HelperGetBmpFileHeaderSize(int nBitCount, ref int pnTotalBytes);
        // 得到BMP图像的文件头和信息头
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_HelperGetBmpFileHeader(int nWidth, int nHeight, int nBitCount, IntPtr pHeader);
        // 采集一帧图像到系统剪贴板
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_CaptureRgbDataToClipboard(int nChannel);
    }
}
