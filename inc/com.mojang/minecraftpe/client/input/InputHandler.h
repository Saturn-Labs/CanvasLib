#pragma once
#include <functional>

namespace Minecraft
{
    class MinecraftGame;
    class ClientInstance;
    class ControllerIDtoClientMap;
    enum class FocusImpact;
    struct PointerLocationEventData;
    struct ButtonEventData;

    class InputHandler
    {
    public:
        void registerPointerLocationHandler(std::function<void(const PointerLocationEventData& data, FocusImpact impact, ClientInstance& clientInstance)> eventFn);
        void registerButtonDownHandler(std::string buttonId, std::function<void(FocusImpact, ClientInstance&)> eventFn, bool);
        void registerButtonUpHandler(std::string buttonId, std::function<void(FocusImpact, ClientInstance&)> eventFn, bool);
        void _handleButtonEvent(const ButtonEventData& data, FocusImpact impact, ClientInstance& clientInstance, int id);
        void tick(MinecraftGame&, ClientInstance&, ControllerIDtoClientMap&, int);
    };
}
