#pragma once

namespace Minecraft
{
    struct PointerLocationEventData
    {
    private:
        char filler00[0x4];
    public:
        short PointerX;
        short PointerY;
    };
}