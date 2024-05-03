#include "Scene.h"
#include "GameObject.h"

Scene::Scene() {
   std::vector<ESGI::GameObject*> pool;
}

Scene::~Scene() {
    // Destructeur
    for (auto* obj : gameObjects) {
        delete obj;  // Assurez-vous de gérer correctement la mémoire
    }
    gameObjects.clear();
}

void Scene::AddObject(ESGI::GameObject* obj) {
    gameObjects.push_back(obj);
}

void Scene::RemoveObject(ESGI::GameObject* obj) {
    auto it = std::remove(gameObjects.begin(), gameObjects.end(), obj);
    if (it != gameObjects.end()) {
        delete* it;
        gameObjects.erase(it);
    }
}

void Scene::Update(float deltaTime) {
    for (auto* obj : gameObjects) {
        obj->Update(deltaTime);
    }
}

/*
void Scene::Render() {
    for (auto* obj : gameObjects) {
        obj->Render();
    }
}

*/
