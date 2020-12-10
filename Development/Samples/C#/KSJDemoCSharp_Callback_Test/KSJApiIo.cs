using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.InteropServices;

namespace KSJApi_Io
{
    class KSJApiIo
    {
        public enum KSJ_SNAPBUTTONSTATUS 
        { 
            KSJ_UP, 
            KSJ_DOWN 
        };
        // Get Snap Pin Status
        // When KSJ_SUPPORT_GPIO_NORMAL is True, KSJ_SUPPORT_SNAP_BUTTON will Enable after Set External Trigger Pin as Normal Input Pin.
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_SnapButtonStatus( int nChannel, ref KSJ_SNAPBUTTONSTATUS pSnapButtonStatus );

        // 设置GPIO引脚的输入输出状态，btDirection位寻址，BIT0对应GPIO0, BIT1对应GPIO1, BIT2对应GPIO2, BIT3对应GPIO3(=1表示此GPIO输出，=0表示此GPIO输入)
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_GpioSetDirection( int nChannel, byte btDirection );
        // 获取GPIO引脚的输入输出状态，pbtDirection位寻址，BIT0对应GPIO0, BIT1对应GPIO1, BIT2对应GPIO2, BIT3对应GPIO3(=1表示此GPIO输出，=0表示此GPIO输入)
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_GpioGetDirection( int nChannel, ref byte pbtDirection );

        // 控制GPIO引脚输出，只有btDirection相应位设置为1的引脚才能通过此函数控制引脚输出。btGpioStatus位寻址，BIT0对应GPIO0, BIT1对应GPIO1, BIT2对应GPIO2, BIT3对应GPIO3(=1表示此GPIO输出TTL高电平，=0表示此GPIO输出TTL低电平)
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_GpioSetStatus   ( int nChannel, byte btGpioStatus );
        // 读取GPIO引脚状态，*pbtGpioStatus位寻址，BIT0对应GPIO0, BIT1对应GPIO1, BIT2对应GPIO2, BIT3对应GPIO3(=1表示此GPIO输出TTL高电平，=0表示此GPIO输出TTL低电平)
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_GpioGetStatus   ( int nChannel, ref byte pbtGpioStatus );

        // About Flash. nMode not valid.
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_FlashControlSet(int nChannel, bool bEnable, bool bInvert, int nMode);
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_FlashControlGet(int nChannel, ref bool pbEnable, ref bool pbInvert, ref int pnMode);

        public enum KSJ_FLASHMODE
        {
            KSJ_FM_TROW,
            KSJ_FM_SIMULTANEOUSEXPOSURE,
            KSJ_FM_SHUTTERWIDTH
        };
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_FlashSetMode(int nChannel, KSJ_FLASHMODE FlashMode);
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_FlashGetMode(int nChannel, ref KSJ_FLASHMODE pFlashMode);

        // 如下函数只适用于YYO型号相机(帧存带光耦)
        // 通过查询功能调用如下函数
        // 注意：在外触发模式下，不可以设置为KSJ_GPIOIN_NORMAL，必须切换到非外触发模式时设置。
        // 在用户调用设置为外触发模式时，自动设置为KSJ_GPIOIN_EXTERNALTRIGGER。
        // KSJ_QueryFunction (KSJ_SUPPORT_GPIO_NORMAL)
        // When call KSJ_GpioSetDirection(, bit0 = 0 ) == KSJ_GpioInModeSet(, KSJ_GPIOIN_NORMAL)
        // When call KSJ_GpioSetDirection(, bit0 = 1 ) == KSJ_GpioInModeSet(, KSJ_GPIOIN_EXTERNALTRIGGER)
        public enum KSJ_GPIOIN_MODE 
        { 
            KSJ_GPIOIN_EXTERNALTRIGGER, 
            KSJ_GPIOIN_NORMAL
        };
        // 外触发输入引脚默认为外触发输入，也可以设置为普通IO输入，通过读取函数进行读取。
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_GpioInModeSet(int nChannel, KSJ_GPIOIN_MODE GpioInMode);
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_GpioInModeGet(int nChannel, ref KSJ_GPIOIN_MODE pGpioInMode);
        // 当外触发输入引脚作为普通IO时，可以通过此函数进行读取，BIT0为该引脚电平状态。1为高电平，0为低电平。
        // 注意：只有在设置为KSJ_GPIOIN_NORMAL模式下才可以读取。
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_GpioInStatusGet(int nChannel, ref byte pbtValue);

        // 通过查询KSJ_SUPPORT_FLASHOUT_ASIO功能调用如下函数
        // When call KSJ_GpioSetDirection(, bit1 = 1 ) == KSJ_GpioOutModeSet(, KSJ_GPIOOUT_FLASH)
        // When call KSJ_GpioSetDirection(, bit1 = 0 ) == KSJ_GpioOutModeSet(, KSJ_GPIOOUT_NORMAL)
        // 
        public enum KSJ_GPIOOUT_MODE
        { 
            KSJ_GPIOOUT_FLASH, 
            KSJ_GPIOOUT_NORMAL 
        };
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_GpioOutModeSet(int nChannel, KSJ_GPIOOUT_MODE GpioOutMode);
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_GpioOutModeGet(int nChannel, ref KSJ_GPIOOUT_MODE pGpioOutMode);

        // 注意：只有在KSJ_NORMAL_OUT模式下，才可以设置。
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_GpioOutStatusSet(int nChannel, byte btValue);

        // 设置滤波时间，单位为Us，如果设置为0，则硬件将以200ns进行滤波。
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_GpioFilterSet(int nChannel, ushort wFilterTimeUs);
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_GpioFilterGet(int nChannel, ref ushort pwFilterTimeUs);

    }
}
