#include <vector>
#include "Game.h"
#include "DialogSystem.h"

Game game;

std::vector<std::string> DialogSystem::all_complate_dialog{ std::vector<std::string>() };

int main()
{
    game.play_game();

    return 0;
}
//Dima