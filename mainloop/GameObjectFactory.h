#pragma once
#include "GameObject.h"
#include <nlohmann/json.hpp>
#include <string>

class GameObjectFactory {
public:
    // Cr�e un GameObject en fonction du type sp�cifi�
    static ESGI::GameObject* CreateGameObject(const std::string& type);

    // Convertit un GameObject en JSON pour la sauvegarde
    static nlohmann::json GameObjectToJson(const ESGI::GameObject* gameObject);
};
