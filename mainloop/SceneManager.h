#pragma once

#include <string>
#include "Scene.h"
#include "nlohmann/json.hpp"
#include <fstream>
#include <iostream>

namespace ESGI {
    class SceneManager {
    public:

        std::vector<Scene*> sceneVector;
        bool loadScene(const std::string& filename);

    private:
        void processTransformComponent(ESGI::GameObject* gameObject, const nlohmann::json& componentData);
        void processRendererComponent(ESGI::GameObject* gameObject, const nlohmann::json& componentData);
        void processScriptComponent(ESGI::GameObject* gameObject, const nlohmann::json& componentData);
        // Ajoutez des m�thodes pour d'autres types de composants si n�cessaire
    };

}