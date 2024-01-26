#include "CanvasLib/Elements/UIElement.h"
#include "CanvasLib/Screen.h"
#include "Zenova/Log.h"
#include <xutility>

namespace CanvasLib
{
    UIElement::UIElement() = default;
    UIElement::~UIElement() = default;

    FVector2 UIElement::GetPosition(bool selfAligned) const
    {
        FVector2 position = mPosition;

        Screen& screen = *Screen::GetInstance();
        Canvas& canvas = screen.GetCanvas();
        FVector2 canvasPercentSize = canvas.GetCanvasPercentSize(screen.GetCurrentScene()->GetChildAlignment().GetAlignmentOffset());

        position.x += canvasPercentSize.x;
        position.y += canvasPercentSize.y;

        if (selfAligned)
        {
            ElementAlignment alignment = GetAlignment();
            position.x -= GetSize().x * alignment.GetAlignmentOffset().x;
            position.y -= GetSize().y * alignment.GetAlignmentOffset().y;
        }
        
        return position;
    }

    FVector2 UIElement::GetSize() const
    {
        return mSize;
    }

    ElementAlignment UIElement::GetAlignment() const
    {
        return mSelfAlignment;
    }

    void UIElement::SetPosition(const FVector2& position)
    {
        mPosition = position;
    }

    void UIElement::SetSize(const FVector2& size)
    {
        mSize = size;
    }

    void UIElement::SetAlignment(const ElementAlignment& alignment)
    {
        mSelfAlignment = alignment;
    }
}
