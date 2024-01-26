#include "CanvasLib/Input/Input.h"

#include <Zenova/Log.h>

#include "com.mojang/minecraftpe/client/ClientInstance.h"
#include "com.mojang/minecraftpe/client/input/event/PointerLocationEventData.h"

namespace CanvasLib
{
    FVector2 Input::ScreenMousePosition;
    FVector2 Input::UIMousePosition;
    
    void Input::PointerLocationEvent(const Minecraft::PointerLocationEventData& data, Minecraft::FocusImpact impact,
        Minecraft::ClientInstance& clientInstance)
    {
        const Minecraft::ScreenSizeData& screenSizeData = clientInstance.getGuiData().mScreenSizeData;
        
        ScreenMousePosition = FVector2(data.PointerX, data.PointerY);
        UIMousePosition = FVector2(ScreenMousePosition.x * (screenSizeData.mClientUIScreenSize.x / screenSizeData.mClientScreenSize.x), ScreenMousePosition.y * (screenSizeData.mClientUIScreenSize.y / screenSizeData.mClientScreenSize.y));
    }

    void Input::PointerDownEvent(Minecraft::FocusImpact impact, Minecraft::ClientInstance& clientInstance)
    {
        Zenova_Info("Pointer Down!");
    }

    void Input::PointerUpEvent(Minecraft::FocusImpact impact, Minecraft::ClientInstance& clientInstance)
    {
        Zenova_Info("Pointer Up!");
    }
}
