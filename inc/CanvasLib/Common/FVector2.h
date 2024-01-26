#pragma once
#include "../Exporting.h"

namespace CanvasLib
{
    struct LIBRARY FVector2
    {
        float x;
        float y;

        FVector2();
        FVector2(float x, float y);
        FVector2(float scalar);

        static FVector2 Zero;

        FVector2 operator/(const FVector2& vector) const;
        FVector2 operator*(const FVector2& vector) const;
    };
}
