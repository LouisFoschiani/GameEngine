#include "Scene.h"
#include "GameObject.h"

    void Scene::RemoveObject(GameObject* obj) {
        
        delete obj;

    }


    void Scene::Update(float deltaTime) {
        
        for (int i = 0; i < poolSize; ++i) {
            pool[i].Update(deltaTime);
        }
    }

    GameObject* Scene::Allocate()
    {

        int index = FindSpace();

        if (index != -1) {
            pool[index].Use();
            return &pool[index];
        }
        return nullptr;
        
    }

    void Scene::ResetPool()
    {
        delete[] pool;
        pool = new GameObject[poolSize];

    }

    void Scene::DestroyPool()
    {
        delete[] pool;
    }

    int Scene::FindSpace() const
    {

        for (int i = 0; i < poolSize; ++i) {
            if (!pool[i].IsInUse())
                return i;
        }


        return -1;
    }

    void Scene::Debug()
    {

        for (int i = 0; i < poolSize; ++i) {
            if (!pool[i].IsInUse()) {
                for each (auto component in pool[i].GetComponents())
                {
                    component->Debug();
                }
            }
        }

    }

    std::string Scene::GetName() const
    {
        return name;
    }

    int Scene::GetPoolSize() const {
        return poolSize;
    }

    GameObject* Scene::GetPool() {
        return pool;
    }
    Scene::Scene(int poolSize, const std::string n) : poolSize(poolSize), name(n) {

        pool = new GameObject[poolSize];
    }
    /*
    void Scene::Render() {
        for (auto* obj : gameObjects) {
            obj->Render();
        }
    }

    */