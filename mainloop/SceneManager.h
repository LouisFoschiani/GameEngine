#pragma once

#include <string>
#include "Scene.h"
#include "GameObjectFactory.h"
#include "nlohmann/json.hpp"
#include <fstream>
#include <iostream>

    class SceneManager {
    public:

        SceneManager();
        ~SceneManager() {
            for (Scene* scene : sceneVector)
            {
                delete scene;
            }
        }
        std::vector<Scene*> sceneVector;
        bool LoadScene(const std::string& filename);
        void CreateScene(int poolSize);
        void SaveScene(Scene* scene, const std::string& filename);

    private:
        void processTransformComponent(GameObject* gameObject, const nlohmann::json& componentData);
        void processRendererComponent(GameObject* gameObject, const nlohmann::json& componentData);
        void processScriptComponent(GameObject* gameObject, const nlohmann::json& componentData);
        // Ajoutez des méthodes pour d'autres types de composants si nécessaire
    };
