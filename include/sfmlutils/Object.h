#ifndef OBJECT_H
#define OBJECT_H

#include <SFML/Graphics.hpp>

class Object
{
public:
    virtual void Render(sf::RenderWindow &window) {}
    virtual void PhysicsUpdate(float fixedDeltaTime) {}
    virtual void Update(float deltaTime) {}
};

#endif // OBJECT_H
