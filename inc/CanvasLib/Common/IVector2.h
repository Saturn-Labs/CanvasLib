#pragma once
#include "../Exporting.h"

namespace CanvasLib
{
    struct LIBRARY IVector2
    {
        int x;
        int y;

        IVector2();
        IVector2(int x, int y);
        IVector2(int scalar);

        static IVector2 Zero;
    };
}
