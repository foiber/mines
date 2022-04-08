#include <SFML/Graphics.hpp>
#include <ctime>

#include "Game.hpp"

int main()
{
    srand(time(NULL));

    Game game(8, 8, 10);

    game.print();

    return 0;
}
