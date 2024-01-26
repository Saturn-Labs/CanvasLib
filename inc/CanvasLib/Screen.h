#pragma once
#include <vector>

#include "Canvas.h"
#include "Exporting.h"
#include "Common/Texture2D.h"


namespace CanvasLib
{
    typedef void(*ScreenStart)(Screen& screen);
    typedef void(*RenderFunction)(Screen& screen, Canvas& canvas);
    typedef std::unordered_map<std::string, Scene*> SceneMap;
    class LIBRARY Screen
    {
        Minecraft::ScreenView* mScreenView = nullptr;
        Minecraft::MinecraftUIRenderContext* mRenderContext = nullptr;
        std::string mSelectedSceneIdentifier = "";
        Scene* mSelectedScene = nullptr;
        SceneMap mScenes = {};
        Canvas mCanvas;
        std::unordered_map<std::string, Texture2D> mLoadedTextures = {};

        static std::vector<RenderFunction> RenderFunctionEvents;
        static std::vector<ScreenStart> ScreenStartFunctionEvents;
        static bool Started;
        
    public:
        static Screen* ScreenInstance;
        Screen(Minecraft::ScreenView* screenView, Minecraft::MinecraftUIRenderContext* renderContext);
        Minecraft::MinecraftUIRenderContext& GetMinecraftUIRenderContext();
        Minecraft::ScreenView& GetMinecraftScreenView();
        Canvas& GetCanvas();
        void Update(Minecraft::ScreenView* screenView, Minecraft::MinecraftUIRenderContext* renderCtx);
        static void AddRenderEvent(RenderFunction callback);
        static void RemoveRenderEvent(RenderFunction callback);
        static void AddScreenStartEvent(ScreenStart callback);
        static void RemoveScreenStartEvent(ScreenStart callback);
        
    public:
        static Screen* GetInstance();

    public:
        Scene* AddScene(const std::string& identifier, Scene* scene);
        Scene* GetScene(const std::string& identifier);
        Scene* GetCurrentScene();
        void RemoveScene(const std::string& identifier);
        bool OpenScene(const std::string& identifier);
        Texture2D& GetTexture(const std::string& path);
    };
}
