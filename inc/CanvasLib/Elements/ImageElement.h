#pragma once
#include <string>

#include "UIElement.h"
#include "../Common/Texture2D.h"

namespace CanvasLib
{
    struct Color32;

    class LIBRARY ImageElement : public UIElement
    {
        std::string mTexture = "";
        FVector2 mUVPosition = FVector2(0);
        FVector2 mUVSize = FVector2(0);
        
    public:
        ImageElement(const std::string& texture, const FVector2& position, const FVector2& size, const FVector2& uvPosition, const FVector2& uvSize);
        void Draw(Scene& scene, Canvas& canvas) override;

        FVector2 GetUVPosition() const;
        FVector2 GetUVSize() const;
        std::string GetTexture() const;
    };
}
