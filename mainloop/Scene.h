#pragma once

#include <vector>
#include "GameObject.h" 
#include <cassert>

namespace ESGI {
    class Scene {
    public:
        Scene(int poolSize) : poolSize(poolSize) {
            pool = new GameObject*[poolSize];
        }
        ~Scene() {

            for (int i = 0; i < poolSize; ++i) {
                delete pool[i];
            }

            delete[] pool;
        }

        void RemoveObject(GameObject* obj);
        bool AddObject(GameObject* obj) const;
        void Update(float deltaTime);
        void Render();
        void ResetPool();
        void DestroyPool();
        int FindSpace() const;

    private:
        const int poolSize;
        int currentIndex = 0;
        GameObject** pool;
    };

}