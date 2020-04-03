using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.InteropServices;

namespace KSJApi_Image
{
    class KSJApiImage
    {
        // 坏点校正低阈值和高阈值设置（硬件不支持此设置，由软件处理时有效）
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_BadPixelCorrectionSetThreshold(int nChannel, byte btLow, byte btHigh);
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_BadPixelCorrectionGetThreshold(int nChannel, ref byte pbtLow, ref byte pbtHigh);

        public enum KSJ_THRESHOLD 
        { 
            KSJ_THRESHOLD_LOW, 
            KSJ_THRESHOLD_HIGH 
        };
        // 坏点校正设置及阈值设置，低阈值会过滤更多的坏点
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_BadPixelCorrectionSet(int nChannel, bool bEnable, KSJ_THRESHOLD Threshold);
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_BadPixelCorrectionGet(int nChannel, ref bool pbEnable, ref KSJ_THRESHOLD pThreshold);

        // Same to Parameter KSJ_CONTRAST（-128~128）， Software Preccess, may influence capture efficiency or preivew frame rate.
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_ProcessContrastGetRange(int nChannel, ref int pnMinContrast, ref int pnMaxContrast);
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_ProcessContrastSet(int nChannel, int nContrast);
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_ProcessContrastGet(int nChannel, ref int pnContrast);

        // Same to Parameter KSJ_BRIGHTNESS（-128~128）, Software Preccess, may influence capture efficiency or preivew frame rate.
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_ProcessBrightnessGetRange(int nChannel, ref int pnMinBrightness, ref int pnMaxBrightness);
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_ProcessBrightnessSet(int nChannel, int nBrightness);
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_ProcessBrightnessGet(int nChannel, ref int pnBrightness);

        // Same to Parameter KSJ_SATURATION（-128~128）, Software Preccess, may influence capture efficiency or preivew frame rate.
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_ProcessSaturationGetRange(int nChannel, ref int pnMinSaturation, ref int pnMaxSaturation);
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_ProcessSaturationSet(int nChannel, int nSaturation);
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_ProcessSaturationGet(int nChannel, ref int pnStaturation);

        // 设置Gamma值，范围 -9 - +9
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_GammaGetRange(int nChannel, ref int pnMinGamma, ref int pnMaxGamm);
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_GammaGetValue(int nChannel, ref int pnValue);
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_GammaSetValue( int nChannel, int nValue );

        public enum KSJHueRange
        {
            KSJ_ALL_HUES,
            KSJ_RED_HUES,
            KSJ_YELLOW_HUES,
            KSJ_GREEN_HUES,
            KSJ_CYAN_HUES,
            KSJ_BLUE_HUES,
            KSJ_MAGENTA_HUES
        } ;

        // nHue: -180 ~ 180, nSaturation: -100 ~ 100, nLightness: -100 ~ 100
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_HueSaturationSet(int nChannel, KSJHueRange HueRange, int nHue, int nSaturation, int nLightness);
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_HueSaturationGet(int nChannel, KSJHueRange HueRange, ref int pnHue, ref int pnSaturation, ref int pnLightness);
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_HueSaturationSetEnable(int nChannel, bool bEnable);

    }
}
