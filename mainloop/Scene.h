#pragma once

#include <vector>
#include "GameObject.h" 

class Scene {
public:
    Scene();
    ~Scene();

    void AddObject(ESGI::GameObject* obj);
    void RemoveObject(ESGI::GameObject* obj);
    void Update(float deltaTime);
    void Render();

private:
    std::vector<ESGI::GameObject*> gameObjects;
};
