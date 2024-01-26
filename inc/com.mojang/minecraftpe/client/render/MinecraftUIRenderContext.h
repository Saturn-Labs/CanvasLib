#pragma once
#include "UIRenderContext.h"
#include "com.mojang/minecraftpe/client/ClientInstance.h"
#include "com.mojang/minecraftpe/client/screen/scene/UIScene.h"
#include "com.mojang/minecraftpe/math/Color.h"
#include "com.mojang/minecraftpe/math/RectangleArea.h"

class IClientInstance;
class ScreenContext;

namespace Minecraft
{
    class MinecraftUIRenderContext : public UIRenderContext
    {
        ClientInstance& mClientInstance;
        ScreenContext& mScreenContext;
        
    public:
        MinecraftUIRenderContext(IClientInstance&, ScreenContext&, const UIScene&);
        virtual ~MinecraftUIRenderContext();
        virtual float getLineLength(Font&, const std::string&, float, bool);
        virtual float getTextAlpha();
        virtual void setTextAlpha(float);
        virtual void drawDebugText(const RectangleArea&, const std::string&, const mce::Color&, float, ui::TextAlignment, const TextMeasureData&, const CaretMeasureData&);
        virtual void drawText(Font&, const RectangleArea&, const std::string&, const mce::Color&, float, ui::TextAlignment, const TextMeasureData&, const CaretMeasureData&);
        virtual void flushText(float);
        virtual void drawImage(const mce::TexturePtr&, const glm::tvec2<float, (glm::precision)0>&, const glm::tvec2<float, (glm::precision)0>&, const glm::tvec2<float, (glm::precision)0>&, const glm::tvec2<float, (glm::precision)0>&);
        virtual void drawNineslice(const mce::TexturePtr&, const NinesliceInfo&);
        virtual void flushImages(const mce::Color&, float, const HashedString&);
        virtual void beginSharedMeshBatch(ComponentRenderBatch&);
        virtual void endSharedMeshBatch(ComponentRenderBatch&);
        virtual void drawRectangle(const RectangleArea&, const mce::Color&, float, int);
        virtual void fillRectangle(const RectangleArea&, const mce::Color&, float);
        virtual void increaseStencilRef();
        virtual void decreaseStencilRef();
        virtual void resetStencilRef();
        virtual void fillRectangleStencil(const RectangleArea&);
        virtual void enableScissorTest(const RectangleArea&);
        virtual void disableScissorTest();
        virtual void setClippingRectangle(const RectangleArea&);
        virtual void setFullClippingRectangle();
        virtual void saveCurrentClippingRectangle();
        virtual void restoreSavedClippingRectangle();
        virtual RectangleArea getFullClippingRectangle();
        virtual void updateCustom(CustomRenderComponent*);
        virtual void renderCustom(CustomRenderComponent*, int, RectangleArea&);
        virtual void cleanup();
        virtual void removePersistentMeshes();
        virtual std::shared_ptr<mce::TexturePtr> getTexture(const ResourceLocation&, bool);
        virtual void getZippedTexture(const Core::Path&, const ResourceLocation&, bool);
        virtual void unloadTexture(const mce::TexturePtr&);
        virtual void getUITextureInfo(const ResourceLocation&, bool);
        virtual void touchTexture(const ResourceLocation&);
        virtual int getMeasureStrategy();
        virtual void snapImageSizeToGrid(glm::tvec2<float, (glm::precision)0>&);
        virtual void snapImagePositionToGrid(glm::tvec2<float, (glm::precision)0>&);

        ClientInstance& getClientInstance() const
        {
            return mClientInstance;
        }

        ScreenContext& getScreenContext() const
        {
            return mScreenContext;
        }
    };
}