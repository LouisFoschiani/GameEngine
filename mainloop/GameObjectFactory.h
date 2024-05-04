#pragma once
#include "GameObject.h"
#include "TransformComponent.h"
#include "BehaviourComponent.h"
#include "MoveBehaviour.h"
#include <nlohmann/json.hpp>
#include <string>

    class GameObjectFactory {
    public:
        // Cr�e un GameObject en fonction du type sp�cifi�
        static GameObject* CreateGameObject(const std::string& type);

        // Convertit un GameObject en JSON pour la sauvegarde
        static nlohmann::json GameObjectToJson(GameObject* gameObject);
    };
