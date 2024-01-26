#include "gui/GuiData.h"

namespace Minecraft
{
    class IClientInstance
    {
        
    };

    class ClientInstance
    {
        char filler00[0x488];
        GuiData& mGuiData;

    public:
        GuiData& getGuiData() const
        {
            return mGuiData;
        }
    };
}
