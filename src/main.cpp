#include "main.hpp"

void game_loop(game_loop_t orig) {
    orig();

    static bool initialized = false;
    if (initialized || !rakhook::initialize())
        return;

    dwSAMPBase = (DWORD)GetModuleHandle("samp.dll");

    rakhook::on_receive_rpc += [](unsigned char &id, RakNet::BitStream *bs) -> bool {
        if (id == 61)
        {
            bs->IgnoreBits(24);

            unsigned char caption_size;
            bs->Read(caption_size);

            // More info: https://sampwiki.blast.hk/wiki/Limits
            if (!caption_size || caption_size > 64)
            {
                addToChatWindow("Invalid caption length", 9022306);
                return false;
            }
        }
        return true;
    };

    initialized = true;
}

void addToChatWindow(const char* text, DWORD color)
{
    if (!dwSAMPBase)
        return;

    if (!text)
        return;

    DWORD chat_info = dwSAMPBase + 0x21A0E4;
    DWORD func = dwSAMPBase + 0x64010;

    __asm
    {
        MOV eax, dword ptr[chat_info]
        MOV ecx, dword ptr[eax]
        PUSH 0
        PUSH color
        PUSH 0
        PUSH text
        PUSH 8
        CALL func
    }
}

std::unique_ptr<cyanide::polyhook_x86<game_loop_t, decltype(&game_loop)>> game_loop_hook;

samp_rce_fix::samp_rce_fix() {
    if (!rakhook::samp_addr() || rakhook::samp_version() == rakhook::samp_ver::unknown)
        return;

    game_loop_hook = std::make_unique<typename decltype(game_loop_hook)::element_type>(std::bit_cast<game_loop_t>(0x53BEE0), std::move(&game_loop));
    game_loop_hook->install();
}

samp_rce_fix samp_rce_fix_;