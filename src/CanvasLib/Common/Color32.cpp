﻿#include "CanvasLib/Common/Color32.h"
#include "com.mojang/minecraftpe/math/Color.h"

namespace CanvasLib
{
    Color32::Color32(int r, int g, int b, int a) :
        r(r), g(g), b(b), a(a) {}

    Color32::Color32(int rgba) :
        r(rgba), g(rgba), b(rgba), a(rgba) {}

    Minecraft::mce::Color Color32::getMCEColor() const
    {
        return { (float)r / 255.0f, (float)g / 255.0f, (float)b / 255.0f, (float)a / 255.0f };
    }

    Color32 Color32::White = Color32(255);
}
