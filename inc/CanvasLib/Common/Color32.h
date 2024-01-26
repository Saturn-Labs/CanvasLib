#pragma once
#include "../Exporting.h"

namespace Minecraft::mce
{
    class Color;
}

namespace CanvasLib
{
    struct LIBRARY Color32
    {
        union { int r = 0; int red;   };
        union { int g = 0; int green; };
        union { int b = 0; int blue;  };
        union { int a = 0; int alpha; };
        
        Color32(int r, int g, int b, int a);
        explicit Color32(int rgba);
        Minecraft::mce::Color getMCEColor() const;

        static Color32 White;
    };
}
