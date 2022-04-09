#include <iostream>
#include <inttypes.h>
#include <random>

class Game
{
private:
    char field[256][256];
    size_t width, height;

public:
    Game(size_t width, size_t height, size_t nmines);

    void print();
    void spawnMines(size_t nmines);
    void countNear();
    ~Game();
};
//jtytdtdrrtddtrrdt
Game::Game(size_t width, size_t height, size_t nmines)
{
    this->width = width;
    this->height = height;

    for (size_t row = 0; row < height; row++)
    {
        for (size_t col = 0; col < height; col++)
        {
            field[row][col] = '0';
        }
    }

    spawnMines(nmines);
    countNear();
}

void Game::spawnMines(size_t nmines)
{
    for (size_t i = 0; i < nmines;)
    {
        size_t row, col;

        row = rand() % height;
        col = rand() % width;

        if (field[row][col] != '*')
        {
            field[row][col] = '*';
            i++;
        }
    }
}

void Game::countNear()
{
    for (size_t row = 0; row < height; row++)
    {
        for (size_t col = 0; col < height; col++)
        {
            if (field[row][col] == '*')
                continue;
            else
            {
                if (field[row - 1][col - 1] == '*')
                    field[row][col]++;

                if (field[row - 1][col] == '*')
                    field[row][col]++;

                if (field[row - 1][col + 1] == '*')
                    field[row][col]++;

                if (field[row][col + 1] == '*')
                    field[row][col]++;

                if (field[row + 1][col + 1] == '*')
                    field[row][col]++;

                if (field[row + 1][col] == '*')
                    field[row][col]++;

                if (field[row + 1][col - 1] == '*')
                    field[row][col]++;

                if (field[row][col - 1] == '*')
                    field[row][col]++;
            }
        }

        std::cout << std::endl;
    }
}

Game::~Game()
{
}

void Game::print()
{
    for (size_t row = 0; row < height; row++)
    {
        for (size_t col = 0; col < height; col++)
        {
            std::cout << field[row][col] << " ";
        }

        std::cout << std::endl;
    }
}
