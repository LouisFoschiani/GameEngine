#pragma once

#include <vector>
#include "Component.h"
#include <string>

class GameObject;

    class Scene {
    public:

        int GetPoolSize() const;
        std::string name;

        GameObject* GetPool();

        Scene(int poolSize, const std::string n);
        ~Scene() {

            delete pool;
        }

        void RemoveObject(GameObject* obj);
        void Update(float deltaTime);
        void Render();
        GameObject* Allocate();
        void ResetPool();
        void DestroyPool();
        int FindSpace() const;

        void Debug();
        std::string GetName() const;


    private:
        const int poolSize;
        int currentIndex = 0;
        GameObject* pool;
    };
