#pragma once

namespace Minecraft
{
    struct RectangleArea
    {
        float xFrom;
        float xTo;
        float yFrom;
        float yTo;

        bool checkIntersection(float x, float y) const
        {
            bool xIntersection = x >= xFrom && x <= xTo;
            bool yIntersection = y >= yFrom && y <= yTo;
            return xIntersection && yIntersection;
        }
    };
}
