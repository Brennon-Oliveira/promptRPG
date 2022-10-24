
#include "Game.h"
#include <new>
#include <ncurses.h>
#include <string>
#include <iostream>
#include <locale.h>
#include "../history/Prolog.h"

using namespace std;

Game::Game(){
    setlocale(LC_ALL, "fr_FR.UTF-8");
    initscr();
    curs_set(0);
    noecho();
    keypad(stdscr, TRUE);
    cbreak();
    Prolog::inicialization();

    Game::player = new Player();

     
    endwin();
}

string Game::question(char question[], char options[][255], int optionsSize){
    curs_set(0);
    noecho();
    int ch;
    int selectedOption = 0;
    do
    {
        clear();
        printw("%s:\n\n", question);
        
        if(ch == KEY_DOWN && selectedOption < 3){
            selectedOption++;
        }
        if(ch == KEY_UP && selectedOption > 0){
            selectedOption--;
        }

        for(int i = 0; i < 4; i++){
            if(selectedOption == i) printw("> ");
            printw("%d %s\n", i+1, &options[i]);
        }

        refresh();
    }
    while ((ch = getch()) != 10);
    string result(options[selectedOption]);
    return result;
}

string Game::input(char question[]){
    curs_set(1);
    echo();
    printw("%s\n\n", question);
    char input[255];

    scanw("%s",input);

    string result(input);

    return result;
}

void Game::dialog(char text[]){
    clear();
    noecho();
    curs_set(0);
    int ch;
    printw(text);
    printw("\nPressione Enter para prosseguir...");
    while ((ch = getch()) != 10);
}
