#pragma once

#include <string>
#include "Scene.h"
#include "GameObjectFactory.h"
#include "nlohmann/json.hpp"
#include <fstream>
#include <iostream>

namespace ESGI {
    class SceneManager {
    public:

        SceneManager();
        ~SceneManager() {
            for each (Scene* scene in sceneVector)
            {
                delete scene;
            }
        }
        std::vector<Scene*> sceneVector;
        bool LoadScene(const std::string& filename);
        void CreateScene(int poolSize);
        void SaveScene(Scene& scene, const std::string& filename);

    private:
        void processTransformComponent(ESGI::GameObject* gameObject, const nlohmann::json& componentData);
        void processRendererComponent(ESGI::GameObject* gameObject, const nlohmann::json& componentData);
        void processScriptComponent(ESGI::GameObject* gameObject, const nlohmann::json& componentData);
        // Ajoutez des méthodes pour d'autres types de composants si nécessaire
    };

}