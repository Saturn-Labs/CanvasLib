#include "CanvasLib/Canvas.h"

#include <Zenova/Log.h>

#include "CanvasLib/Screen.h"
#include "CanvasLib/Common/Color32.h"
#include "CanvasLib/Common/Vector2.h"
#include "CanvasLib/Input/Input.h"
#include "com.mojang/minecraftpe/client/render/MinecraftUIRenderContext.h"
#include "com.mojang/minecraftpe/common/Vec2.h"

namespace CanvasLib
{
    Canvas::Canvas(Screen* screen) :
        mScreen(screen)
    {
    }

    void Canvas::DrawRectanglePercent(const Vector2& position, const Vector2& size, const Color32& color, int thickness)
    {
        Screen& screen = *GetScreen();
        Minecraft::MinecraftUIRenderContext& renderContext = screen.GetMinecraftUIRenderContext();
        Vector2 uiSize = *(Vector2*)&renderContext.getClientInstance().getGuiData().mScreenSizeData.mClientUIScreenSize;

        Vector2 rectPosition = { position.x * uiSize.x, position.y * uiSize.y };
        Vector2 rectSize = { rectPosition.x + size.x * uiSize.x, rectPosition.y + size.y * uiSize.y };
        
        Minecraft::RectangleArea area = { rectPosition.x, rectSize.x, rectPosition.y, rectSize.y };
        Minecraft::mce::Color rectColor = color.getMCEColor();
        renderContext.drawRectangle(area, rectColor, rectColor.a, thickness);
    }

    void Canvas::FillRectanglePercent(const Vector2& position, const Vector2& size, const Color32& color)
    {
        Screen& screen = *GetScreen();
        Minecraft::MinecraftUIRenderContext& renderContext = screen.GetMinecraftUIRenderContext();
        Vector2 uiSize = *(Vector2*)&renderContext.getClientInstance().getGuiData().mScreenSizeData.mClientUIScreenSize;

        Vector2 rectPosition = { position.x * uiSize.x, position.y * uiSize.y };
        Vector2 rectSize = { rectPosition.x + size.x * uiSize.x, rectPosition.y + size.y * uiSize.y };
        
        Minecraft::RectangleArea area = { rectPosition.x, rectSize.x, rectPosition.y, rectSize.y };
        Minecraft::mce::Color rectColor = color.getMCEColor();
        renderContext.fillRectangle(area, rectColor, rectColor.a);
    }

    Screen* Canvas::GetScreen()
    {
        return mScreen;
    }
}
