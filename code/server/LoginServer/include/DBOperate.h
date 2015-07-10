#pragma once
#include "commdata.h"


GuestID g_LoadGuestFactID(int worldID);
bool g_GetGuestByDevice(const char* device, GuestID& gid);
bool g_SaveGuest(const char* device, GuestID gid);
