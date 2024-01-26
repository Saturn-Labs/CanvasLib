#include "CanvasLib/Common/Vector2.h"

namespace CanvasLib
{
    Vector2::Vector2() :
        x(0), y(0)
    {
    }

    Vector2::Vector2(float x, float y) :
        x(x), y(y)
    {
    }

    Vector2::Vector2(float scalar) :
        x(scalar), y(scalar)
    {
    }

    Vector2 Vector2::Zero = Vector2(0);
}