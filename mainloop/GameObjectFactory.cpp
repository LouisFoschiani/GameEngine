#include "GameObjectFactory.h"

namespace ESGI {
    // Implémentation de la méthode pour créer un GameObject en fonction du type
    GameObject* GameObjectFactory::CreateGameObject(const std::string& type) {
        GameObject* obj = GameObject::Allocate();
        if (!obj) {
            std::cerr << "Failed to allocate GameObject" << std::endl;
            return nullptr;
        }

        // Exemple de la configuration des composants en fonction du type
        if (type == "Player") {
            TransformComponent* transform = new TransformComponent(0, 0, 0);
            obj->AddComponent(transform);

            MoveBehaviour* behaviour = new MoveBehaviour();  // Supposons que ce comportement soit spécifique au joueur
            obj->AddComponent(behaviour);
        }
        else if (type == "Enemy") {
            TransformComponent* transform = new TransformComponent(0, 0, 0);
            obj->AddComponent(transform);

            MoveBehaviour* behavior = new MoveBehaviour();  // Supposons un comportement différent pour l'ennemi
            obj->AddComponent(behavior);
        }
        else {
            // Configuration par défaut pour les GameObject non spécifiés
            TransformComponent* transform = new TransformComponent(0, 0, 0);
            obj->AddComponent(transform);
        }

        return obj;
    }

    // Conversion d'un GameObject en JSON
    nlohmann::json GameObjectFactory::GameObjectToJson(GameObject* gameObject) {
        nlohmann::json j;
        j["type"] = "GameObject";
        for (auto& comp : gameObject->GetComponents()) {
            j["components"].push_back(comp->ToJson());  // Assurez-vous que chaque composant a une méthode ToJson()
        }
        return j;
    }
}