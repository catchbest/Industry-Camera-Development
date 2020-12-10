using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.InteropServices;

namespace KSJApi_UserZone
{
    class KSJApiUserZone
    {
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // 参考“凯视佳工业相机内部API函数说明书（用户读写区域篇）”
        public enum KSJ_EEPROM_TYPE { KSJ_24LC64, KSJ_24LC1024, KSJ_24LC128 };

        [DllImport("KSJApi.dll")]
        public static extern int KSJ_EEPROMTypeGet( int nChannel, ref KSJ_EEPROM_TYPE pType );

        [DllImport("KSJApi.dll")]
        public static extern int KSJ_WrEEPROM( int nChannel, ushort uRomAdress, byte btValue   );
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_RdEEPROM( int nChannel, ushort uRomAdress, ref byte pbtValue );

        [DllImport("KSJApi.dll")]
        public static extern int KSJ_WrEEPROMEx( int nChannel, ulong ulRomAdress, byte btValue   );
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_RdEEPROMEx(int nChannel, ulong ulRomAdress, ref byte pbtValue);
    }
}
