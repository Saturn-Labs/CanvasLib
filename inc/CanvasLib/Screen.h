#pragma once
#include <vector>

#include "Canvas.h"
#include "Exporting.h"


namespace CanvasLib
{
    typedef void(*RenderFunction)(Canvas&);
    class LIBRARY Screen
    {
        Minecraft::ScreenView* mScreenView = nullptr;
        Minecraft::MinecraftUIRenderContext* mRenderContext = nullptr;
        Canvas mCanvas;

        static std::vector<RenderFunction> RenderFunctionEvents;
        
    public:
        static Screen* ScreenInstance;
        Screen(Minecraft::ScreenView* screenView, Minecraft::MinecraftUIRenderContext* renderContext);
        Minecraft::MinecraftUIRenderContext& GetMinecraftUIRenderContext();
        Minecraft::ScreenView& GetMinecraftScreenView();
        Canvas& GetCanvas();
        void Update(Minecraft::ScreenView* screenView, Minecraft::MinecraftUIRenderContext* renderCtx);
        static void AddRenderEvent(RenderFunction callback);
        static void RemoveRenderEvent(RenderFunction callback);
        
    public:
        static Screen* GetInstance();
    };
}
