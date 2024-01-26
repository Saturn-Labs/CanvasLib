#include "CanvasLib/Common/IVector2.h"

namespace CanvasLib
{
    IVector2::IVector2() :
        x(0), y(0)
    {
    }

    IVector2::IVector2(int x, int y) :
        x(x), y(y)
    {
    }

    IVector2::IVector2(int scalar) :
        x(scalar), y(scalar)
    {
    }

    IVector2 IVector2::Zero = IVector2(0);
}