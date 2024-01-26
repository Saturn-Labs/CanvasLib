#pragma once

namespace CanvasLib
{
    enum class VerticalAlignment
    {
        Top,
        Center,
        Bottom
    };
    
    enum class HorizontalAlignment
    {
        Left,
        Center,
        Right
    };
    
    struct ElementAlignment
    {
        VerticalAlignment YAlignment = VerticalAlignment::Top;
        HorizontalAlignment XAlignment = HorizontalAlignment::Left;

        FVector2 GetAlignmentOffset() const
        {
            FVector2 alignment = FVector2::Zero;

            switch (YAlignment)
            {
            case VerticalAlignment::Top:
                alignment.y = 0.0f;
                break;
            case VerticalAlignment::Center:
                alignment.y = 0.5f;
                break;
            case VerticalAlignment::Bottom:
                alignment.y = 1.0f;
                break;
            }

            switch (XAlignment)
            {
            case HorizontalAlignment::Left:
                alignment.x = 0.0f;
                break;
            case HorizontalAlignment::Center:
                alignment.x = 0.5f;
                break;
            case HorizontalAlignment::Right:
                alignment.x = 1.0f;
                break;
            }

            return alignment;
        }
    };
}