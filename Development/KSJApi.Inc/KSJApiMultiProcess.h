#ifndef __KSJ_API_MULTI_PROCESS_H__
#define __KSJ_API_MULTI_PROCESS_H__

// #pragma message("Include KSJApiMultiProcess.h") 

#ifdef KSJAPI_EXPORTS
#define KSJ_API __declspec(dllexport)
#elif defined KSJAPI_STATIC
#define KSJ_API
#else
#define KSJ_API __declspec(dllimport)
#endif


#ifdef __cplusplus
extern "C"{
#endif

	//-----------------------------------------------------------------------------
    // 函数：KSJ_DeviceClose
    // 功能：关闭指定索引的设备，如果不关闭指定相机，那么在多进程下是不能操作这台相机的
    // 参数：
	//       nIndex： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_DeviceClose(int nIndex);

	enum KSJ_DEVICESTATUS { KSJ_DS_CLOSE, KSJ_DS_OPEN };//设备在当前进程中的开启关闭状态的枚举类型
	
	//-----------------------------------------------------------------------------
    // 函数：KSJ_DeviceGetStatus
    // 功能：获取设备在当前进程中的开启关闭状态
    // 参数：
	//       nIndex： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	//       pDs： 输出，获取相机在当前进程中的开启关闭状态
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_DeviceGetStatus(int nIndex, KSJ_DEVICESTATUS *pDs);



#ifdef __cplusplus
}
#endif

#endif