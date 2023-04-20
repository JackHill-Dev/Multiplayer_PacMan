#include "Core/Game.h"
#include <SFML/Graphics.hpp>
#include <memory>
int main()
{
    std::shared_ptr<Game> game;
    game = std::make_shared<Game>();

    game->Run();

    return 0;
}