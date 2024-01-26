#pragma once
#include "InputHandler.h"

namespace Minecraft
{
    class MinecraftInputHandler
    {
        InputHandler& mInputHandler;
        
    public:
        virtual ~MinecraftInputHandler();
    private:
        virtual void filler00();
    public:
        virtual void _registerInputHandlers();
    private:

    public:
        InputHandler& getInputHandler()
        {
            return mInputHandler;
        }
    };
}
