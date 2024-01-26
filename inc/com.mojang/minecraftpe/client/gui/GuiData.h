#include "com.mojang/minecraftpe/common/Vec2.h"

namespace Minecraft
{
    struct ScreenSizeData
    {
        Vec2 mTotalScreenSize;
        Vec2 mClientScreenSize;
        Vec2 mClientUIScreenSize;
    };

    struct PointerPosition
    {
        int x;
        int y;
    };
    
    struct GuiData
    {
    private:
        char filler18h[0x18];
    public:
        ScreenSizeData mScreenSizeData;
    private:
    };
    
    static_assert(offsetof(GuiData, mScreenSizeData) == 0x18, "GuiData::mScreenSizeData offset isn't 0x18");
}
