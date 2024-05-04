#include "Scene.h"

namespace ESGI {

    void Scene::RemoveObject(GameObject* obj) {
        
        delete obj;

    }

    bool Scene::AddObject(GameObject* obj) const {

        int index = FindSpace();

        if (index != -1) {
            pool[index] = obj;

            return true;
        }

        return false;
        

    }


    void Scene::Update(float deltaTime) {
        
        for (int i = 0; i < poolSize; ++i) {
            pool[i]->Update(deltaTime);
        }
    }

    void Scene::ResetPool()
    {
        delete[] pool;
        pool = new GameObject*[poolSize];

    }

    void Scene::DestroyPool()
    {
        delete[] pool;
    }

    int Scene::FindSpace() const
    {

        for (int i = 0; i < poolSize; ++i) {
            if (pool[i] == NULL)
                return i;
        }


        return -1;
    }

    void Scene::Debug()
    {

        for (int i = 0; i < poolSize; ++i) {
            if (pool[i] != NULL) {
                for each (auto component in pool[i]->GetComponents())
                {
                    component->Debug();
                }
            }
        }

    }

    /*
    void Scene::Render() {
        for (auto* obj : gameObjects) {
            obj->Render();
        }
    }

    */


}