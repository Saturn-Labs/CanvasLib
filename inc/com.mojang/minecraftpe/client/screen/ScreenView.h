#pragma once
#include "com.mojang/minecraftpe/client/render/MinecraftUIRenderContext.h"

namespace Minecraft
{
    class ScreenView
    {
    public:
        void setupAndRender(UIRenderContext& renderContext);
    };
}