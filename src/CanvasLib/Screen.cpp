#include "CanvasLib/Screen.h"

#include "com.mojang/minecraftpe/client/render/MinecraftUIRenderContext.h"

namespace CanvasLib
{
    Screen* Screen::ScreenInstance = nullptr;
    std::vector<RenderFunction> Screen::RenderFunctionEvents = {};
    
    Screen::Screen(Minecraft::ScreenView* screenView, Minecraft::MinecraftUIRenderContext* renderContext) :
        mScreenView(screenView), mRenderContext(renderContext), mCanvas(Canvas(this))
    {
    }

    Minecraft::MinecraftUIRenderContext& Screen::GetMinecraftUIRenderContext()
    {
        return *mRenderContext;
    }

    Minecraft::ScreenView& Screen::GetMinecraftScreenView()
    {
        return *mScreenView;
    }

    Canvas& Screen::GetCanvas()
    {
        return mCanvas;
    }

    void Screen::Update(Minecraft::ScreenView* screenView, Minecraft::MinecraftUIRenderContext* renderCtx)
    {
        mScreenView = screenView;
        mRenderContext = renderCtx;
        
        for (const auto& renderEvent : RenderFunctionEvents)
        {
            renderEvent(mCanvas);
        }
    }

    void Screen::AddRenderEvent(RenderFunction callback)
    {
        auto it = std::find(RenderFunctionEvents.begin(), RenderFunctionEvents.end(), callback);
        if (it == RenderFunctionEvents.end())
            RenderFunctionEvents.push_back(callback);
    }

    void Screen::RemoveRenderEvent(RenderFunction callback)
    {
        auto it = std::find(RenderFunctionEvents.begin(), RenderFunctionEvents.end(), callback);
        if (it != RenderFunctionEvents.end())
        {
            RenderFunctionEvents.erase(it);
        }
    }

    Screen* Screen::GetInstance()
    {
        return ScreenInstance;
    }
}
