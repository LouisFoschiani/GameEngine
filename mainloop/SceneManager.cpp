#include "SceneManager.h"

    Scene* SceneManager::activeScene = nullptr;
    Engine* SceneManager::engine = nullptr;

    bool SceneManager::LoadScene(const std::string& path) {

        if (SceneManager::activeScene != nullptr)
            SaveScene(SceneManager::activeScene);

        std::ifstream file(path);
        std::filesystem::path filepath(path);
        std::string filename = filepath.filename().string();
        size_t lastindex = filename.find_last_of(".");
        filename = filename.substr(0, lastindex);
        nlohmann::json j;
        file >> j;

        SceneManager::activeScene = new Scene(1024, filename);
        for (const auto& item : j["content"]) {
            GameObject* gameObject = SceneManager::activeScene->Allocate();  // ou une méthode de votre pool si utilisé

            if (gameObject == nullptr) {
                delete gameObject;
                continue;
            }

            for (const auto& comp : item["components"]) {
                nlohmann::json component_json = nlohmann::json::parse(std::string(comp));
                const std::string& type = component_json["type"];

                if (type == "TransformComponent") {
                    processTransformComponent(gameObject, component_json);
                }
                // Ajoutez des else if pour d'autres types de composants ici
            }
        }

        return true;
    }

    void SceneManager::CreateScene(int poolSize, std::string name)
    {
        if (SceneManager::activeScene != nullptr)
            SaveScene(SceneManager::activeScene);
        SceneManager::activeScene = new Scene(poolSize, name);
    }

    void SceneManager::SaveScene(Scene* scene) {
        nlohmann::json sceneJson;

        int count = 0;

        for (int i = 0; i < scene->GetPoolSize(); ++i) {
            if (scene->GetPool()[i].IsInUse()) {
                sceneJson["content"].push_back(GameObjectFactory::GameObjectToJson(&scene->GetPool()[i]));  // Assurez-vous que chaque composant a une méthode ToJson()
                count++;
            }
        }

        if (count == 0) {
            sceneJson["content"].push_back("");            
        }

        
        std::string filename;
        char* buf = nullptr;
        size_t sz = 0;

        if (_dupenv_s(&buf, &sz, "USERPROFILE") == 0 && buf != nullptr)
        {
            filename = std::string(buf) + "\\Desktop\\" + scene->GetName() + ".json";
            free(buf);
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

    void SceneManager::LinkEngine(Engine* engine)
    {
        SceneManager::engine = engine;
    }

    void SceneManager::processTransformComponent(GameObject* gameObject, const nlohmann::json& componentData) {
        // Vérifiez d'abord si le GameObject et le JSON sont valides

        if (!gameObject || componentData.is_null()) {
            std::cerr << "Marche pas le TransformComponent" << std::endl;
            return;
        }

        float x = componentData["position"].value("x", 0.0f);
        float y = componentData["position"].value("y", 0.0f);
        float z = componentData["position"].value("z", 0.0f);


        TransformComponent* transform = new TransformComponent(x,y,z);
        gameObject->AddComponent(transform);

        

    }


    void SceneManager::processRendererComponent(GameObject* gameObject, const nlohmann::json& componentData) {
        // Process logic for renderer component
    }

    void SceneManager::processScriptComponent(GameObject* gameObject, const nlohmann::json& componentData) {
        // Process logic for script component
    }
