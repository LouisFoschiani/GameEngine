#include "GameObject.h"
#include "SceneManager.h"
#include <iostream>


GameObject::~GameObject() {
	inUse = false;
	for each (Component * comp in components)
	{
		SceneManager::engine->FreeComponent(comp);
		delete comp;
	}
	components.clear();
}

bool GameObject::IsInUse() const
{
	return inUse;
}

void GameObject::Use()
{
	inUse = true;
}

void GameObject::AddComponent(Component* component)
	{

		components.push_back(component);
		component->Link(this);

		std::string type = component->GetType();

		if (type == "TransformComponent") {

			SceneManager::engine->physicEngine->RegisterComponent(component);

		}else if (type == "BehaviourComponent") {
			SceneManager::engine->behaviourEngine->RegisterComponent(component);
		}

	}

	std::vector<Component*>& GameObject::GetComponents()
	{
		return components;
	}

	void* GameObject::operator new(const size_t size, Scene* scene){
		return scene->Allocate();
	}
