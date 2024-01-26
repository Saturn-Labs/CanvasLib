#pragma once
#include "com.mojang/minecraftpe/common/HashedString.h"
#include "CanvasLib/Minecraft/ResourceLocation.h"
#include "glm/vec2.hpp"
#include <memory>

namespace Minecraft
{
    namespace ui
    {
        enum class TextAlignment : uint8_t
        {
            Left = 0x0,
            Right = 0x1,
            Center = 0x2
        };
    }

    namespace Core
    {
        class Path;
    }

    struct TextMeasureData {
        float fontSize;
        int linePadding;
        bool renderShadow;
        bool showColorSymbol;
        bool hideHyphen;
    };

    struct CaretMeasureData {
        int position;
        bool shouldRender;
    };

    namespace mce
    {
        class TexturePtr;
        class Color;
    }

    struct RectangleArea;
    class CustomRenderComponent;
    class Font;

    class NinesliceInfo;
    class ComponentRenderBatch;

    class UIRenderContext
    {
    public:
        virtual ~UIRenderContext() = 0;
        virtual float getLineLength(Font&, const std::string&, float, bool) = 0;
        virtual float getTextAlpha() = 0;
        virtual void setTextAlpha(float) = 0;
        virtual void drawDebugText(const RectangleArea&, const std::string&, const mce::Color&, float, ui::TextAlignment, const TextMeasureData&, const CaretMeasureData&) = 0;
        virtual void drawText(Font&, const RectangleArea&, const std::string&, const mce::Color&, float, ui::TextAlignment, const TextMeasureData&, const CaretMeasureData&) = 0;
        virtual void flushText(float) = 0;
        virtual void drawImage(const mce::TexturePtr& texture, const glm::vec2& position, const glm::vec2& size, const glm::vec2& uvPos, const glm::vec2& uvSize, int32_t) = 0;
        virtual void drawNineslice(const mce::TexturePtr&, const NinesliceInfo&) = 0;
        virtual void flushImages(const mce::Color&, float, const HashedString&) = 0;
        virtual void beginSharedMeshBatch(ComponentRenderBatch&) = 0;
        virtual void endSharedMeshBatch(ComponentRenderBatch&) = 0;
        virtual void drawRectangle(const RectangleArea&, const mce::Color&, float, int) = 0;
        virtual void fillRectangle(const RectangleArea&, const mce::Color&, float) = 0;
        virtual void increaseStencilRef() = 0;
        virtual void decreaseStencilRef() = 0;
        virtual void resetStencilRef() = 0;
        virtual void fillRectangleStencil(const RectangleArea&) = 0;
        virtual void enableScissorTest(const RectangleArea&) = 0;
        virtual void disableScissorTest() = 0;
        virtual void setClippingRectangle(const RectangleArea&) = 0;
        virtual void setFullClippingRectangle() = 0;
        virtual void saveCurrentClippingRectangle() = 0;
        virtual void restoreSavedClippingRectangle() = 0;
        virtual RectangleArea getFullClippingRectangle() = 0;
        virtual void updateCustom(CustomRenderComponent*) = 0;
        virtual void renderCustom(CustomRenderComponent*, int, RectangleArea&) = 0;
        virtual void cleanup() = 0;
        virtual void removePersistentMeshes() = 0;
        virtual mce::TexturePtr getTexture(const ResourceLocation& location, bool) = 0;
        virtual void getZippedTexture(const Core::Path&, const ResourceLocation&, bool) = 0;
        virtual void unloadTexture(const mce::TexturePtr&) = 0;
        virtual void getUITextureInfo(const ResourceLocation&, bool) = 0;
        virtual void touchTexture(const ResourceLocation&) = 0;
        virtual int getMeasureStrategy() = 0;
        virtual void snapImageSizeToGrid(glm::tvec2<float, (glm::precision)0>&) = 0;
        virtual void snapImagePositionToGrid(glm::tvec2<float, (glm::precision)0>&) = 0;
    };
}