#include "SceneManager.h"
#include <fstream>
#include <iostream>

bool SceneManager::loadScene(const std::string& filename) {
    std::ifstream file(filename);
    nlohmann::json j;
    file >> j;

    Scene scene;
    for (const auto& item : j["gameObjects"]) {
        ESGI::GameObject* gameObject = new ESGI::GameObject();  // ou une méthode de votre pool si utilisé
        for (const auto& comp : item["components"]) {
            const std::string& type = comp["type"];
            if (type == "Transform") {
                processTransformComponent(gameObject, comp);
            }
            else if (type == "Renderer") {
                processRendererComponent(gameObject, comp);
            }
            else if (type == "Script") {
                processScriptComponent(gameObject, comp);
            }
            // Ajoutez des else if pour d'autres types de composants ici
        }
        scene.AddObject(gameObject);
    }

    sceneVector.push_back(scene);
    return true;
}

void SceneManager::processTransformComponent(ESGI::GameObject* gameObject, const nlohmann::json& componentData) {
    // Process logic for transform component
}

void SceneManager::processRendererComponent(ESGI::GameObject* gameObject, const nlohmann::json& componentData) {
    // Process logic for renderer component
}

void SceneManager::processScriptComponent(ESGI::GameObject* gameObject, const nlohmann::json& componentData) {
    // Process logic for script component
}
