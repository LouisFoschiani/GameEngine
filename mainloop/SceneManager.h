#pragma once

#include <string>
#include "Scene.h"
#include "Engine.h"
#include "GameObjectFactory.h"
#include "nlohmann/json.hpp"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <filesystem>


    class SceneManager {
    public:

        SceneManager() {

            CreateScene(1024, "DefaultScene");

        };
        ~SceneManager() {
            delete activeScene;
        }
        static Scene* activeScene;
        static Engine* engine;
        static bool LoadScene(const std::string& filename);
        static void CreateScene(int poolSize, std::string name);
        static void SaveScene(Scene* scene);
        static void LinkEngine(Engine* engine);

    private:
        static void processTransformComponent(GameObject* gameObject, const nlohmann::json& componentData);
        static void processRendererComponent(GameObject* gameObject, const nlohmann::json& componentData);
        static void processScriptComponent(GameObject* gameObject, const nlohmann::json& componentData);
        // Ajoutez des méthodes pour d'autres types de composants si nécessaire
    };
