#include "Hooks.h"
#include "Hooks.h"
#include "Hooks.h"
#include "generated/initcpp.h"
#include "CanvasLib/Screen.h"
#include "CanvasLib/Input/Input.h"
#include "com.mojang/minecraftpe/client/input/MinecraftInputHandler.h"
#include "com.mojang/minecraftpe/client/screen/scene/UIScene.h"
#include "com.mojang/minecraftpe/common/ResourceLocation.h"
#include "com.mojang/minecraftpe/common/TexturePtr.h"
#include "com.mojang/minecraftpe/math/Color.h"
#include "com.mojang/minecraftpe/client/input/event/ButtonEventData.h"

namespace CanvasLib
{
    namespace Hooks
    {
        //InputHandler::tick -> __tick
        void _tick(InputHandler* self, MinecraftGame& game, ClientInstance& client, ControllerIDtoClientMap& map, int i0)
        {
            __tick(self, game, client, map, i0);
        }
        
        //MinecraftInputHandler::_registerInputHandlers -> ___registerInputHandlers
        void __registerInputHandlers(MinecraftInputHandler* self)
        {
            ___registerInputHandlers(self);
            self->getInputHandler().registerPointerLocationHandler(Input::PointerLocationEvent);
            self->getInputHandler().registerButtonDownHandler("button.pointer_pressed", Input::PointerDownEvent, false);
            self->getInputHandler().registerButtonUpHandler("button.pointer_pressed", Input::PointerUpEvent, false);
            Zenova_Info("Registered all input handlers!");
        }
        
        //ScreenView::setupAndRender -> __setupAndRender
        void _setupAndRender(ScreenView* self, MinecraftUIRenderContext& renderContext)
        {
            if (!Screen::ScreenInstance)
            {
                Screen::ScreenInstance = new Screen(self, &renderContext);
            }
            Screen::ScreenInstance->Update(self, &renderContext);
            __setupAndRender(self, renderContext);
        }
    }
    
    namespace HookManager
    {
        void Initialize()
        {
            Zenova_Hook(ScreenView::setupAndRender, &Hooks::_setupAndRender, &Hooks::__setupAndRender);
            Zenova_Hook(InputHandler::tick, &Hooks::_tick, &Hooks::__tick);
            Zenova_VHook(MinecraftInputHandler, _registerInputHandlers, &Hooks::__registerInputHandlers, &Hooks::___registerInputHandlers);
        }
        
        void Shutdown()
        {
            using namespace Hooks;

            
        }
    }
}
