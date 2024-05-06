#pragma once
#include <vector>
#include <iostream>
#include "Component.h"
#include "Scene.h"
#include "SceneManager.h"

class Component;
class Scene;

class GameObject
	{

	private:
		std::vector<Component*> components;
		bool inUse = false;


	public:
		GameObject() = default;
		~GameObject() {
			inUse = false;
			for each (Component* comp in components)
			{
				delete comp;
			}
		};
		bool IsInUse() const;
		void Update(float deltaTime){}
		// ce n'est pas une fonction virtuelle !
		void Update(){}
		void Use();
		void AddComponent(Component* component);
		std::vector<Component*>& GetComponents();

		void* operator new(const size_t size, Scene* scene);
		void operator delete(void* pointer) {
			// idem code precedent
		}

	};