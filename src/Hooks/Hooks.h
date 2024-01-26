#pragma once
#include <Zenova.h>

#include "com.mojang/minecraftpe/client/input/MinecraftInputHandler.h"
#include "com.mojang/minecraftpe/client/screen/ScreenView.h"
using namespace Minecraft;

namespace CanvasLib
{
    namespace Hooks
    {
        inline void (*__tick)(InputHandler* self, MinecraftGame& game, ClientInstance& client, ControllerIDtoClientMap& map, int i0) = nullptr;
        void _tick(InputHandler* self, MinecraftGame& game, ClientInstance& client, ControllerIDtoClientMap& map, int i0);
        
        inline void (*___registerInputHandlers)(MinecraftInputHandler* self) = nullptr;
        void __registerInputHandlers(MinecraftInputHandler* self);
        
        inline void(*__setupAndRender)(ScreenView* self, MinecraftUIRenderContext& renderContext) = nullptr;
        void _setupAndRender(ScreenView* self, MinecraftUIRenderContext& renderContext);
    }
    
    namespace HookManager
    {
        void Initialize();
        void Shutdown();
    }
}
