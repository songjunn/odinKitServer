#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // 从 Windows 头中排除极少使用的资料

#ifdef _WIN32
// Windows 头文件:
#include <windows.h>
#include <Mmsystem.h>
#endif

// import
#include "shared.h"
#include "PacketDefine.h"
#include "MainServer.h"
#include "LuaEngine.h"
