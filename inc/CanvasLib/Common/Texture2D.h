#pragma once
#include "../Exporting.h"
#include "../Minecraft/TexturePtr.h"
#include <memory>

namespace CanvasLib
{
    struct LIBRARY Texture2D
    {
        Minecraft::mce::TexturePtr NativeTextureHandle;
        Texture2D(Minecraft::mce::TexturePtr texture) : NativeTextureHandle(texture) {}
        Texture2D() = default;
    };
}
