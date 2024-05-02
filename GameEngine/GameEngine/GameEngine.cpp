#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <cassert>

// Component base class
class Component {
public:
    virtual ~Component() {
        std::cout << "Component destroyed" << std::endl;
    }
    virtual void update() = 0;
};

// Transform component
class TransformComponent : public Component {
public:
    float x, y, z;
    void update() override {
        // Debugging output for transformations
        std::cout << "Updating Transform Component: Position(" << x << ", " << y << ", " << z << ")" << std::endl;
    }
};

// Behavior component (example)
class BehaviorComponent : public Component {
public:
    void update() override {
        std::cout << "Updating Behavior Component" << std::endl;
    }
};

// GameObject class
class GameObject {
public:
    std::vector<Component*> components;
    std::string tag;

    GameObject(const std::string& tag) : tag(tag) {
        std::cout << "GameObject created with tag: " << tag << std::endl;
    }

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
        std::cout << "Updating GameObject: " << tag << std::endl;
        for (auto comp : components) {
            comp->update();
        }
    }

    ~GameObject() {
        std::cout << "Destroying GameObject: " << tag << std::endl;
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
        assert(obj != nullptr && "Attempt to add a null GameObject to the scene");
        objects.push_back(obj);
        std::cout << "GameObject added to scene: " << obj->tag << std::endl;
    }

    void removeObject(GameObject* obj) {
        assert(obj != nullptr && "Attempt to remove a null GameObject from the scene");
        auto it = std::remove(objects.begin(), objects.end(), obj);
        if (it != objects.end()) {
            std::cout << "GameObject removed from scene: " << obj->tag << std::endl;
            objects.erase(it, objects.end());
            delete obj;
        }
    }

    ~Scene() {
        std::cout << "Cleaning up Scene" << std::endl;
        for (auto obj : objects) {
            delete obj;
        }
        objects.clear();
    }

    void update() {
        std::cout << "Updating Scene" << std::endl;
        for (auto obj : objects) {
            obj->update();
        }
    }
};

// Global scene instance
Scene mainScene;

// Main game loop with debugging
void gameLoop() {
    std::cout << "Game loop started" << std::endl;
    while (true) {
        mainScene.update();
        // Add a break condition or input check here to stop the loop for debugging
    }
}

int main() {
    GameObject* player = new GameObject("player");
    player->components.push_back(new TransformComponent());
    player->components.push_back(new BehaviorComponent());

    mainScene.addObject(player);

    // Debug: Show initial setup
    std::cout << "Starting game loop" << std::endl;
    gameLoop();

    return 0;
}
