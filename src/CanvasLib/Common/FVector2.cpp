#include "CanvasLib/Common/FVector2.h"

namespace CanvasLib
{
    FVector2::FVector2() :
        x(0), y(0)
    {
    }

    FVector2::FVector2(float x, float y) :
        x(x), y(y)
    {
    }

    FVector2::FVector2(float scalar) :
        x(scalar), y(scalar)
    {
    }

    FVector2 FVector2::operator/(const FVector2& vector) const
    {
        return { x / vector.x, y / vector.y };
    }

    FVector2 FVector2::operator*(const FVector2& vector) const
    {
        return { x * vector.x, y * vector.y };
    }

    FVector2 FVector2::Zero = FVector2(0);
}