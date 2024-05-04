#include "SceneManager.h"

namespace ESGI {



    bool SceneManager::LoadScene(const std::string& filename) {
        std::ifstream file(filename);
        nlohmann::json j;
        file >> j;

        Scene* scene = new Scene(1024);
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

            // Si la scène est déjà pleine, on détruit l'objet
            if (!scene->AddObject(gameObject)) {
                delete gameObject;
            }
        }

         sceneVector.push_back(scene);
        return true;
    }

    void SceneManager::CreateScene(int poolSize)
    {
        Scene* scene = new Scene(poolSize);
        sceneVector.push_back(scene);
    }

    void SceneManager::SaveScene(Scene& scene, const std::string& filename) {
        nlohmann::json sceneJson;


        for (int i = 0; i < scene.GetPoolSize(); ++i) {
            if (scene.GetPool()[i] != NULL) {
                sceneJson["content"].push_back(GameObjectFactory::GameObjectToJson(scene.GetPool()[i]));  // Assurez-vous que chaque composant a une méthode ToJson()
            }
        }

        // Écrire le JSON dans un fichier
        std::ofstream file(filename);
        if (file.is_open()) {
            file << sceneJson.dump(4);  // Utilisez une indentation de 4 espaces pour la lisibilité
            file.close();
        }
        else {
            std::cerr << "Failed to open file for writing: " << filename << std::endl;
        }
    }

    void SceneManager::processTransformComponent(ESGI::GameObject* gameObject, const nlohmann::json& componentData) {
        // Vérifiez d'abord si le GameObject et le JSON sont valides
        if (!gameObject || componentData.is_null()) {
            std::cerr << "Marche pas le TransformComponent" << std::endl;
            return;
        }

        float x = componentData.value("x", 0.0f);
        float y = componentData.value("y", 0.0f);
        float z = componentData.value("z", 0.0f);

        TransformComponent* transform = new TransformComponent(x,y,z);
        gameObject->AddComponent(transform);


    }


    void SceneManager::processRendererComponent(ESGI::GameObject* gameObject, const nlohmann::json& componentData) {
        // Process logic for renderer component
    }

    void SceneManager::processScriptComponent(ESGI::GameObject* gameObject, const nlohmann::json& componentData) {
        // Process logic for script component
    }

}