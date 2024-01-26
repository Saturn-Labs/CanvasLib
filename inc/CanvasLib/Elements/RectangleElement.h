#pragma once
#include "UIElement.h"
#include "../Common/Color32.h"

namespace CanvasLib
{
    class LIBRARY RectangleElement : public UIElement
    {
        Color32 mColor = Color32::White;
        
    public:
        RectangleElement(const FVector2& position, const FVector2& size, const Color32& color);
        void Draw(Scene& scene, Canvas& canvas) override;
    };
}
