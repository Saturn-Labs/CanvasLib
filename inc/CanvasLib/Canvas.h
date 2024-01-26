#pragma once
#include "Exporting.h"

namespace Minecraft
{
    class ScreenView;
    class MinecraftUIRenderContext;
}

namespace CanvasLib
{
    class Screen;
    struct Vector2;
    struct Color32;
    
    class LIBRARY Canvas
    {
        Screen* mScreen;
        
    public:
        explicit Canvas(Screen* screen);
        void DrawRectanglePercent(const Vector2& position, const Vector2& size, const Color32& color, int thickness);
        void FillRectanglePercent(const Vector2& position, const Vector2& size, const Color32& color);
        Screen* GetScreen();
    };
}
