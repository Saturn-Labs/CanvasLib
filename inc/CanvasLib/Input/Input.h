#pragma once
#include "../Exporting.h"
#include "../Common/Vector2.h"

namespace Minecraft
{
    class ClientInstance;
    struct PointerLocationEventData;
    enum class FocusImpact;
}

namespace CanvasLib
{
    class LIBRARY Input
    {
    public:
        static Vector2 ScreenMousePosition;
        static Vector2 UIMousePosition;

    public:
        static void PointerLocationEvent(const Minecraft::PointerLocationEventData& data, Minecraft::FocusImpact impact, Minecraft::ClientInstance& clientInstance);
        static void PointerDownEvent(Minecraft::FocusImpact impact, Minecraft::ClientInstance& clientInstance);
        static void PointerUpEvent(Minecraft::FocusImpact impact, Minecraft::ClientInstance& clientInstance);
    };
}
