#include "CanvasLib/Canvas.h"

#include <Zenova/Log.h>

#include "CanvasLib/Screen.h"
#include "CanvasLib/Common/Color32.h"
#include "CanvasLib/Common/FVector2.h"
#include "CanvasLib/Input/Input.h"
#include "com.mojang/minecraftpe/client/render/MinecraftUIRenderContext.h"
#include "com.mojang/minecraftpe/common/Vec2.h"

namespace CanvasLib
{
    Canvas::Canvas(Screen* screen) :
        mScreen(screen)
    {
    }

    void Canvas::DrawImage(const Texture2D& texture, const FVector2& position, const FVector2& size, const FVector2& uvPosition, const FVector2& uvSize)
    {
        Screen& screen = *GetScreen();
        Minecraft::MinecraftUIRenderContext& renderContext = screen.GetMinecraftUIRenderContext();
        renderContext.drawImage(texture.NativeTextureHandle, *(glm::vec2*)&position, *(glm::vec2*)&size, *(glm::vec2*)&uvPosition, *(glm::vec2*)&uvSize, 0);
    }

    void Canvas::DrawRectangle(const FVector2& position, const FVector2& size, const Color32& color, int thickness)
    {
        Screen& screen = *GetScreen();
        Minecraft::MinecraftUIRenderContext& renderContext = screen.GetMinecraftUIRenderContext();
        Minecraft::RectangleArea area = { position.x, position.x + size.x, position.y, position.y + size.y };
        Minecraft::mce::Color mceColor = color.getMCEColor();
        renderContext.drawRectangle(area, mceColor, mceColor.a, thickness);
    }

    void Canvas::FillRectangle(const FVector2& position, const FVector2& size, const Color32& color)
    {
        Screen& screen = *GetScreen();
        Minecraft::MinecraftUIRenderContext& renderContext = screen.GetMinecraftUIRenderContext();
        Minecraft::RectangleArea area = { position.x, position.x + size.x, position.y, position.y + size.y };
        Minecraft::mce::Color mceColor = color.getMCEColor();
        renderContext.fillRectangle(area, mceColor, mceColor.a);
    }

    FVector2 Canvas::GetCanvasPercentSize(const FVector2& percent)
    {
        Screen& screen = *GetScreen();
        Minecraft::MinecraftUIRenderContext& renderContext = screen.GetMinecraftUIRenderContext();
        FVector2 uiSize = *(FVector2*)&renderContext.getClientInstance().getGuiData().mScreenSizeData.mClientUIScreenSize;
        return uiSize * percent;
    }

    Screen* Canvas::GetScreen()
    {
        return mScreen;
    }
}
