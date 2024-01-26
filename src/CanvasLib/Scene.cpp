#include "CanvasLib/Scene.h"
#include "Zenova/Log.h"

namespace CanvasLib
{
    Scene::Scene(const std::string& identifier) :
        mSceneIdentifier(identifier) {}

    void Scene::DrawAll(Canvas& canvas)
    {
        for (auto&[identifier, element] : *this)
        {
            element->Draw(*this, canvas);
        }
    }

    UIElement* Scene::AddUIElement(const std::string& identifier, UIElement* element)
    {
        if (mUIElements.find(identifier) == mUIElements.end())
        {
            mUIElements.insert({ identifier, element });
        }
        return mUIElements[identifier];
    }

    UIElement* Scene::GetUIElement(const std::string& identifier)
    {
        if (mUIElements.find(identifier) != mUIElements.end())
        {
            return mUIElements[identifier];
        }
        return nullptr;
    }

    void Scene::RemoveUIElement(const std::string& identifier)
    {
        if (mUIElements.find(identifier) != mUIElements.end())
        {
            mUIElements.erase(identifier);
        }
    }

    ElementAlignment Scene::GetChildAlignment()
    {
        return mElementsAlignment;
    }

    void Scene::SetChildAlignment(const ElementAlignment& alignment)
    {
        mElementsAlignment = alignment;
    }

    std::string Scene::GetIdentifier() const
    {
        return mSceneIdentifier;
    }

    UIElementMap::iterator Scene::begin()
    {
        return mUIElements.begin();
    }
    UIElementMap::iterator Scene::end()
    {
        return mUIElements.end();
    }
    UIElementMap::const_iterator Scene::begin() const
    {
        return mUIElements.begin();
    }
    UIElementMap::const_iterator Scene::end() const
    {
        return mUIElements.end();
    }
}
