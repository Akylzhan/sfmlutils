#ifndef APP_H
#define APP_H

#include <memory>
#include <vector>

#include <SFML/Graphics.hpp>

//#include "Object.h"
#include "sfmlutils/Object.h"

class App final
{
public:
    App(int windowWidth = 600, int windowHeight = 400);
    ~App();

    App(const App &) = delete;
    App(App &&) = delete;

    App &operator=(const App &) = delete;
    App &operator=(App &&) = delete;

    void run();

    void addObject(std::unique_ptr<Object> object);

    int WindowWidth; // TODO invoke event when window size changes
    int WindowHeight;

private:
    sf::RenderWindow Window;

    std::vector<std::shared_ptr<Object>> Objects;
};

#endif // APP_H
