#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

// Forward declarations
class GameObject;

// Component base class
class Component {
public:
    virtual ~Component() {}
    virtual void update() = 0;
};

// Transform component
class TransformComponent : public Component {
public:
    float x, y, z;
    void update() override {
        // Update transform logic here
    }
};

// Behavior component (example)
class BehaviorComponent : public Component {
public:
    void update() override {
        // Behavior update logic
    }
};

// GameObject class
class GameObject {
public:
    std::vector<Component*> components;
    std::string tag;

    GameObject(const std::string& tag) : tag(tag) {}

    template <typename T>
    T* getComponent() {
        for (auto comp : components) {
            T* casted = dynamic_cast<T*>(comp);
            if (casted) {
                return casted;
            }
        }
        return nullptr;
    }

    void update() {
        for (auto comp : components) {
            comp->update();
        }
    }

    ~GameObject() {
        for (auto comp : components) {
            delete comp;
        }
        components.clear();
    }
};

// Scene management
class Scene {
private:
    std::vector<GameObject*> objects;

public:
    void addObject(GameObject* obj) {
        objects.push_back(obj);
    }

    void removeObject(GameObject* obj) {
        auto it = std::remove(objects.begin(), objects.end(), obj);
        objects.erase(it, objects.end());
        delete obj;
    }

    ~Scene() {
        for (auto obj : objects) {
            delete obj;
        }
        objects.clear();
    }

    void update() {
        for (auto obj : objects) {
            obj->update();
        }
    }
};

// Global scene
Scene mainScene;

// Main game loop
void gameLoop() {
    while (true) {
        mainScene.update();
        // Additional game loop logic such as rendering, input handling, etc.
    }
}

int main() {
    // Game initialization code
    GameObject* player = new GameObject("player");
    player->components.push_back(new TransformComponent());
    player->components.push_back(new BehaviorComponent());

    mainScene.addObject(player);

    // Start the game loop
    gameLoop();

    return 0;
}
