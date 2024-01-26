#pragma once
#include <memory>

#include "ResourceLocation.h"

namespace Minecraft
{
    class BedrockTextureData {
        char filler[0xa0];
    };

    namespace mce {
        class TexturePtr {
        public:
            std::shared_ptr<BedrockTextureData> mClientTexture;
            ResourceLocation mTextureLocation;

            ~TexturePtr() = default;
        };
    }
}