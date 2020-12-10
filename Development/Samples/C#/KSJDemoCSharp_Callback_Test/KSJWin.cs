using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.InteropServices;

namespace KSJ_Win
{
    class KSJWin
    {
        [DllImport("kernel32.dll")]
        public extern static short QueryPerformanceCounter(ref long x);
        [DllImport("kernel32.dll")]
        public extern static short QueryPerformanceFrequency(ref long x);
        [DllImport("kernel32.dll", CharSet = CharSet.Auto)]
        public static extern void OutputDebugString(string message);
    }
}
