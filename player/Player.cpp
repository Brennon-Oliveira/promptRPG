#include "Player.h"
#include <ncurses.h>
#include "../game/Game.h"

Player::Player(){
    this->defineName();
    printw("%s",this->name);
}

void Player::defineName(){
    this->name = Game::input("Escolha um nome para seu jogador:");
}

