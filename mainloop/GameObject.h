#pragma once
#include "InfraStructure.h"
#include "Component.h"
#include <vector> 
#include "TransformComponent.h"
#include "BehaviourComponent.h"
#include <iostream>

namespace ESGI
{
	struct GameObject : public InfraStructure
	{

	private:
		std::vector<Component*> components;

		GameObject();
		~GameObject();
		void Update(float deltaTime);
		
		static int currentIndex;
		static int poolSize;

		static void CreatePool(int size);
		
		static void ResetPool();
		static void DestroyPool();


		bool Initialize() final;

		void DeInitialize() final;

		// ce n'est pas une fonction virtuelle !
		void Update();


	public:
		static GameObject* Allocate();
		void AddComponent(Component* component);
		std::vector<Component*>& GetComponents();

	};


}