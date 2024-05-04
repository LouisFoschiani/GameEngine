#pragma once
#include "InfraStructure.h"
#include <vector>
#include <iostream>

class Component;

	struct GameObject
	{

	private:
		std::vector<Component*> components;


	public:
		GameObject() = default;
		~GameObject() = default;
		void Update(float deltaTime);
		// ce n'est pas une fonction virtuelle !
		void Update();
		void AddComponent(Component* component);
		std::vector<Component*>& GetComponents();

	};