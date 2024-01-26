#include "CanvasLib/Elements/ImageElement.h"
#include "CanvasLib/Screen.h"
#include "CanvasLib/Canvas.h"

namespace CanvasLib
{
    ImageElement::ImageElement(const std::string& texture, const FVector2& position, const FVector2& size, const FVector2& uvPosition,
        const FVector2& uvSize) : mTexture(texture), mUVPosition(uvPosition), mUVSize(uvSize)
    {
        
    }

    void ImageElement::Draw(Scene& scene, Canvas& canvas)
    {
        Screen& screen = *canvas.GetScreen();
        canvas.DrawImage(screen.GetTexture(mTexture), GetPosition(true), GetSize(), GetUVPosition(), GetUVSize());
    }

    FVector2 ImageElement::GetUVPosition() const
    {
        return mUVPosition;
    }

    FVector2 ImageElement::GetUVSize() const
    {
        return mUVSize;
    }

    std::string ImageElement::GetTexture() const
    {
        return mTexture;
    }
}
