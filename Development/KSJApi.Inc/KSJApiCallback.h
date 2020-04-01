#ifndef __KSJ_API_CALLBACK_H__
#define __KSJ_API_CALLBACK_H__

// #pragma message("Include KSJApiCallback.h") 

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
    // 函数：KSJ_PREVIEWCALLBACK
    // 功能：回调函数指针的声明
    // 参数：
    //       pImageData：输出，预览图像的数据指针
	//       pnWidth： 输出，返回图像的宽度（像素）
    //       pnHeight：输出，返回图像的高度（像素）
    //       pnBitCount：输出，返回当前视场模式设置下的实际采集图像的位图深度
	//       lpContext： 输出，用户传入的上下文指针，这个指针就是用户调用KSJ_PreviewSetCallback函数时传给lpContext的指针
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	typedef void(CALLBACK *KSJ_PREVIEWCALLBACK)(unsigned char *pImageData, int nWidth, int nHeight, int nBitCount, void *lpContext);
	
	//-----------------------------------------------------------------------------
    // 函数：KSJ_PreviewSetCallback
    // 功能：设置预览回调函数
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       pfPreviewCallback：输入，回调函数指针
	//       lpContext： 输出，用户传入的上下文指针，这个指针就是用户调用KSJ_PreviewSetCallback函数时传给lpContext的指针
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_PreviewSetCallback( int nChannel, KSJ_PREVIEWCALLBACK pfPreviewCallback, void *lpContext );

    //-----------------------------------------------------------------------------
    // 函数：KSJ_PREVIEWCALLBACKEX
    // 功能：回调函数指针的声明
    // 参数：
	//       hDC：输出，KSJApi库创建的内存DC,预览图像已经作为设备无关位图被选入此DC（设备环境句柄）中，用户可以使用此DC并调用GDI函数在此DC（设备环境句柄）上绘制
    //       pImageData：输出，预览图像的数据指针
	//       pnWidth： 输出，返回图像的宽度（像素）
    //       pnHeight：输出，返回图像的高度（像素）
    //       pnBitCount：输出，返回当前视场模式设置下的实际采集图像的位图深度
	//       lpContext： 输出，用户传入的上下文指针，这个指针就是用户调用KSJ_PreviewSetCallback函数时传给lpContext的指针
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
    typedef void(CALLBACK *KSJ_PREVIEWCALLBACKEX)(HDC  hDC, unsigned char *pImageData, int nWidth, int nHeight, int nBitCount, void *lpContext);
	
	//-----------------------------------------------------------------------------
    // 函数：KSJ_PreviewSetCallbackEx
    // 功能：设置预览回调函数
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       pfPreviewCallbackEx：输入，回调函数指针
	//       lpContext： 输出，用户传入的上下文指针，这个指针就是用户调用KSJ_PreviewSetCallback函数时传给lpContext的指针
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_PreviewSetCallbackEx( int nChannel, KSJ_PREVIEWCALLBACKEX pfPreviewCallbackEx, void *lpContext );


#ifdef __cplusplus
}
#endif

#endif