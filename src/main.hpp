#ifndef SAMP_RCE_FIX_HPP
#define SAMP_RCE_FIX_HPP

#include <iostream>
#include <memory>
#include "RakHook/rakhook.hpp"
#include "RakNet/BitStream.h"
#include "RakNet/PacketEnumerations.h"

DWORD dwSAMPBase = 0;

using game_loop_t = void (*)();

void game_loop(game_loop_t orig);
void addToChatWindow(const char* text, DWORD color);

class samp_rce_fix {
public:
    samp_rce_fix();
};

#endif // SAMP_RCE_FIX_HPP
