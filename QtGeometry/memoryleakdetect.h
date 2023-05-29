#pragma once
/*************处理内存泄漏******************/
#ifdef _WIN32  //跨平台，判断当前是否是windows

#define USING_VLD 0

#if USING_VLD == 1
#include "vld.h"
#endif

#endif // _WIN32
