#include "CanvasLib/Screen.h"
#include "com.mojang/minecraftpe/client/render/MinecraftUIRenderContext.h"
#include "Zenova/Log.h"

namespace CanvasLib
{
    Screen* Screen::ScreenInstance = nullptr;
    std::vector<RenderFunction> Screen::RenderFunctionEvents = {};
    std::vector<ScreenStart> Screen::ScreenStartFunctionEvents = {};
    bool Screen::Started = false;
    
    Screen::Screen(Minecraft::ScreenView* screenView, Minecraft::MinecraftUIRenderContext* renderContext) :
        mScreenView(screenView), mRenderContext(renderContext), mCanvas(Canvas(this))
    {
    }

    Minecraft::MinecraftUIRenderContext& Screen::GetMinecraftUIRenderContext()
    {
        return *mRenderContext;
    }

    Minecraft::ScreenView& Screen::GetMinecraftScreenView()
    {
        return *mScreenView;
    }

    Canvas& Screen::GetCanvas()
    {
        return mCanvas;
    }

    void Screen::Update(Minecraft::ScreenView* screenView, Minecraft::MinecraftUIRenderContext* renderCtx)
    {
        mScreenView = screenView;
        mRenderContext = renderCtx;

        if (!Started)
        {
            Started = true;
            for (const auto& start : ScreenStartFunctionEvents)
            {
                start(*this);
            }
        }
        
        for (const auto& renderEvent : RenderFunctionEvents)
        {
            renderEvent(*this, mCanvas);
        }

        if (mSelectedScene != nullptr)
        {
            mSelectedScene->DrawAll(mCanvas);
        }
    }

    void Screen::AddRenderEvent(RenderFunction callback)
    {
        auto it = std::find(RenderFunctionEvents.begin(), RenderFunctionEvents.end(), callback);
        if (it == RenderFunctionEvents.end())
            RenderFunctionEvents.push_back(callback);
    }

    void Screen::RemoveRenderEvent(RenderFunction callback)
    {
        auto it = std::find(RenderFunctionEvents.begin(), RenderFunctionEvents.end(), callback);
        if (it != RenderFunctionEvents.end())
        {
            RenderFunctionEvents.erase(it);
        }
    }

    void Screen::AddScreenStartEvent(ScreenStart callback)
    {
        auto it = std::find(ScreenStartFunctionEvents.begin(), ScreenStartFunctionEvents.end(), callback);
        if (it == ScreenStartFunctionEvents.end())
            ScreenStartFunctionEvents.push_back(callback);
    }

    void Screen::RemoveScreenStartEvent(ScreenStart callback)
    {
        auto it = std::find(ScreenStartFunctionEvents.begin(), ScreenStartFunctionEvents.end(), callback);
        if (it != ScreenStartFunctionEvents.end())
        {
            ScreenStartFunctionEvents.erase(it);
        }
    }

    Screen* Screen::GetInstance()
    {
        return ScreenInstance;
    }

    Scene* Screen::AddScene(const std::string& identifier, Scene* scene)
    {
        if (mScenes.find(identifier) == mScenes.end())
        {
            mScenes.insert(std::pair(identifier, scene));
        }
        return mScenes[identifier];
    }

    Scene* Screen::GetScene(const std::string& identifier)
    {
        if (mScenes.find(identifier) != mScenes.end())
        {
            return mScenes[identifier];
        }
        return nullptr;
    }

    Scene* Screen::GetCurrentScene()
    {
        return mSelectedScene;
    }

    void Screen::RemoveScene(const std::string& identifier)
    {
        if (mScenes.find(identifier) != mScenes.end())
        {
            mScenes.erase(identifier);
        }
    }

    bool Screen::OpenScene(const std::string& identifier)
    {
        mSelectedScene = GetScene(identifier);
        return mSelectedScene;
    }

    Texture2D& Screen::GetTexture(const std::string& path)
    {
        if (mLoadedTextures.find(path) != mLoadedTextures.end())
        {
            return mLoadedTextures[path];
        }
        mLoadedTextures.insert({ path, Texture2D(mRenderContext->getTexture(ResourceLocation(path), true)) });
        return mLoadedTextures[path];
    }
}
