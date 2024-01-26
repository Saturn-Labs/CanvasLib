#pragma once
#include "../Exporting.h"

namespace CanvasLib
{
    struct LIBRARY Vector2
    {
        float x;
        float y;

        Vector2();
        Vector2(float x, float y);
        Vector2(float scalar);

        static Vector2 Zero;
    };
}
