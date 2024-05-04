#include "GameObjectFactory.h"
#include "TransformComponent.h"
#include "BehaviorComponent.h"
#include <iostream>

// Implémentation de la méthode pour créer un GameObject en fonction du type
ESGI::GameObject* GameObjectFactory::CreateGameObject(const std::string& type) {
    ESGI::GameObject* obj = ESGI::GameObject::Allocate();
    if (!obj) {
        std::cerr << "Failed to allocate GameObject" << std::endl;
        return nullptr;
    }

    // Exemple de la configuration des composants en fonction du type
    if (type == "Player") {
        auto* transform = new TransformComponent();
        transform->position.x = 100;  // Position initiale du joueur
        transform->position.y = 100;
        obj->AddComponent(transform);

        auto* behavior = new BehaviorComponent();  // Supposons que ce comportement soit spécifique au joueur
        obj->AddComponent(behavior);
    }
    else if (type == "Enemy") {
        auto* transform = new TransformComponent();
        transform->position.x = -100;  // Position initiale de l'ennemi
        transform->position.y = -100;
        obj->AddComponent(transform);

        auto* behavior = new BehaviorComponent();  // Supposons un comportement différent pour l'ennemi
        obj->AddComponent(behavior);
    }
    else {
        // Configuration par défaut pour les GameObject non spécifiés
        auto* transform = new TransformComponent();
        transform->position.x = 0;
        transform->position.y = 0;
        obj->AddComponent(transform);
    }

    return obj;
}

// Conversion d'un GameObject en JSON
nlohmann::json GameObjectFactory::GameObjectToJson(const ESGI::GameObject* gameObject) {
    nlohmann::json j;
    j["type"] = "GameObject";
    for (const auto& comp : gameObject->components) {
        j["components"].push_back(comp->ToJson());  // Assurez-vous que chaque composant a une méthode ToJson()
    }
    return j;
}
