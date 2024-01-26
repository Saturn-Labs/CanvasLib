#include "CanvasLib/Elements/RectangleElement.h"
#include "CanvasLib/Canvas.h"
#include "Zenova/Log.h"

namespace CanvasLib
{
    RectangleElement::RectangleElement(const FVector2& position, const FVector2& size, const Color32& color) :
        mColor(color)
    {
        SetPosition(position);
        SetSize(size);
    }

    void RectangleElement::Draw(Scene& scene, Canvas& canvas)
    {
        canvas.FillRectangle(GetPosition(true), GetSize(), mColor);
    }
}
