#pragma once
#include <memory>
#include <vector>

#include "Exporting.h"
#include "Scene.h"

namespace Minecraft
{
    class ScreenView;
    class MinecraftUIRenderContext;
}

namespace CanvasLib
{
    class Screen;
    struct Texture2D;
    struct FVector2;
    struct Color32;
    
    class LIBRARY Canvas
    {
        Screen* mScreen;
        FVector2 mUIRectSize = FVector2(640, 360);
        
    public:
        explicit Canvas(Screen* screen);
        void DrawImage(const Texture2D& texture, const FVector2& position, const FVector2& size, const FVector2& uvPosition, const FVector2& uvSize);
        void DrawRectangle(const FVector2& position, const FVector2& size, const Color32& color, int thickness);
        void FillRectangle(const FVector2& position, const FVector2& size, const Color32& color);
        FVector2 GetCanvasPercentSize(const FVector2& percent);
        Screen* GetScreen();
    };
}
