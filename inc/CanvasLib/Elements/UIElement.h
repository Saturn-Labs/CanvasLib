#pragma once
#include "../Exporting.h"
#include "../Common/FVector2.h"
#include "../Math/ElementAlignment.h"

namespace CanvasLib
{
    class Scene;
    class Canvas;
    class LIBRARY UIElement
    {
        ElementAlignment mSelfAlignment = { VerticalAlignment::Top, HorizontalAlignment::Left };
        FVector2 mPosition = FVector2(0);
        FVector2 mSize = FVector2(1);
        
    public:
        UIElement();
        virtual ~UIElement();
        
        virtual void Draw(Scene& scene, Canvas& canvas) = 0;

        FVector2 GetPosition(bool selfAligned = true) const;
        FVector2 GetSize() const;
        ElementAlignment GetAlignment() const;
        void SetPosition(const FVector2& position);
        void SetSize(const FVector2& size);
        void SetAlignment(const ElementAlignment& alignment);
    };
}
