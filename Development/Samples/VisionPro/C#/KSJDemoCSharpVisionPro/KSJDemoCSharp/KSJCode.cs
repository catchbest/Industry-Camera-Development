using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace KSJ_Code
{
    class KSJCode
    {
        // #pragma message("Include KSJCode.h") 
        /*-------------------------------------------------
            Return Code
          ================================================*/
        public const int RET_SUCCESS = 1;   // Function Return Successfully.
        public const int RET_PARAMERROR = -1;   // User's Parameter Passed to API Error.
        public const int RET_MALLOCFAIL = -2;   // Memory Allocated Fail.
        public const int RET_NOTSUPPORT = -3;   // Function not supported by such type camera.
        public const int RET_DEVICENOTEXIST = -4;   // Device doesn't be detected.
        public const int RET_DEVICENOTINIT = -5;   // Device haven't be initialized
        public const int RET_VIOLATION = -6;   // This operation is conflict to other operation.
        public const int RET_NOPRIVILEGE = -7;   // User no privilege
        public const int RET_FAIL = -8;   // Function Return Failed.( Normal Error, no Detail )
        public const int RET_WRONG = -9;   // Same to RET_FAIL.
        public const int RET_RECOVERY_SUCCESS = -10;   // Device is recovered successfully.
        public const int RET_RECOVERY_FAIL = -11;   // Device recovered, but fail.
        public const int RET_BADFRAME = -12;   // Bad Frame comes from sensor, should be skipped. 
        public const int RET_INVALIDFRAME = -13;   // Invalid Frame, Transmission Error, this frame should re-get.
        public const int RET_ZEROFRAME = -14;   // 帧存相机会返回此值，表示采集图像数据0字节，错误的帧
        public const int RET_VERSION_ERROR = -15;   // 版本错误
        public const int RET_TIMEOUT = -16;   // 当设置读取超时之后不进行恢复时，采集函数会返回此数值，而不会返回恢复的状态
        public const int RET_DEVICECLOSED = -17;
    }
}
