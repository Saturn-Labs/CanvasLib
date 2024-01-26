#pragma once
#include <map>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

#include "Exporting.h"
#include "Elements/UIElement.h"
#include "Math/ElementAlignment.h"

namespace CanvasLib
{
    typedef std::unordered_map<std::string, UIElement*> UIElementMap;
    class LIBRARY Scene
    {
        std::string mSceneIdentifier;
        ElementAlignment mElementsAlignment = { VerticalAlignment::Top, HorizontalAlignment::Left };
        UIElementMap mUIElements = {};
        
    public:
        explicit Scene(const std::string& identifier);
        void DrawAll(Canvas& canvas);
        UIElement* AddUIElement(const std::string& identifier, UIElement* element);
        UIElement* GetUIElement(const std::string& identifier);
        void RemoveUIElement(const std::string& identifier);
        ElementAlignment GetChildAlignment();
        void SetChildAlignment(const ElementAlignment& alignment);
        std::string GetIdentifier() const;
        
    public:
        UIElementMap::iterator begin();
        UIElementMap::iterator end();
        UIElementMap::const_iterator begin() const;
        UIElementMap::const_iterator end() const;
    };
}
