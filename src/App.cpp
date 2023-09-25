#include "sfmlutils/App.h"

App::App(int windowWidth, int windowHeight)
    : WindowWidth(windowWidth)
    , WindowHeight(windowHeight)
    , Window{sf::VideoMode(windowWidth, windowHeight), "App"}
{
}

App::~App() {}

void App::run()
{
    const float fixedDeltaTime = 0.02;
    sf::Clock clock;

    float accumulator = 0;

    while (Window.isOpen()) {
        sf::Event event;
        while (Window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                Window.close();
            }
        }

        // physics
        float deltaTime = clock.restart().asSeconds();
        accumulator += deltaTime;

        while (accumulator >= fixedDeltaTime) {
            // run physics
            for (const auto &object : Objects) {
                object->PhysicsUpdate(fixedDeltaTime);
            }
            accumulator -= fixedDeltaTime;
        }

        // update
        for (const auto &object : Objects) {
            object->Update(deltaTime);
        }

        // render
        Window.clear();

        for (const auto &object : Objects) {
            object->Render(Window);
        }

        Window.display();
    }
}

void App::addObject(std::unique_ptr<Object> object)
{
    Objects.emplace_back(std::move(object));
}
