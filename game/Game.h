#pragma once
#include <string>
#include "../player/Player.h"

class Game{
    public:
        Player* player;

        Game();

        static std::string question(char question[], char options[][255], int optionsSize);

        static std::string input(char question[]);

        static void dialog(char text[]);
};
