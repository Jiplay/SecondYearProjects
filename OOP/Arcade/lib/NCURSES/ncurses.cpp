/*
** EPITECH PROJECT, 2021
** B-OOP-400-PAR-4-1-arcade-ibrahim.zafar
** File description:
** ncurses
*/

#include "ncurses.hpp"
#include <iostream>

Ncurses::Ncurses()
{
}

extern "C" Ncurses* create_object()
{
    return new Ncurses;
}

extern "C" void destroy_object( Ncurses* object )
{
    delete object;
}

int Ncurses::mainLoop()
{
    
}

void Ncurses::destroyWindow()
{
    endwin();
}

int Ncurses::getCommand()
{
    return 0;
}

int Ncurses::menu()
{
    curs_set(0);
    noecho();
    cbreak();
    int x,y;
    getmaxyx(stdscr,y,x);
    WINDOW * menuwin = newwin(y-6, x-1, 0, 0);
    box(menuwin, 0, 0);
    refresh();
    wrefresh(menuwin);
    keypad(menuwin, true);

    std::string choices[4] = {"Main Menu", "Pacman", "Nibbler", "Quit"};
    int choice;
    int highlight = 0;
    int currentWindow = 0;

    while(1) {
        if (currentWindow == 0) {
            for (int i = 0; i < 4; i++) {
                if (i ==highlight)
                    wattron(menuwin, A_REVERSE);
                mvwprintw(menuwin, i+1, 1, choices[i].c_str());
                wattroff(menuwin, A_REVERSE);
            }
            choice = wgetch(menuwin);
            switch(choice) {
                case KEY_UP:
                    highlight--;
                    if(highlight == -1)
                        highlight = 0;
                    break;
                case KEY_DOWN: 
                    highlight++;
                    if(highlight == 4)
                        highlight = 3;
                    break;
                default:
                    break;
            }
            if (choice == 10) {
                if (highlight == 0)
                    {destroyWindow(); return 3;}
                if (highlight == 1)
                    {destroyWindow(); return 11;}  // Pacman Ncurses
                if (highlight == 2)
                    {destroyWindow(); return 13;}  // Nibbler Ncurses
                if (highlight == 3)
                    {destroyWindow(); return 0;}
            }
        }
    }
}

Serpent::Serpent()
{
    Serpent(0, 0);
}

Serpent::Serpent(int yPos, int xPos)
{
     y = yPos;
     x = xPos;
}

void Ncurses::setGame()
{
    initscr();
    curs_set(0);
    noecho();
    cbreak();
    nodelay(stdscr, true);
    keypad(stdscr, true);
    srand(time(NULL));
    //debut du jeu position ordre et score
    int score;
    getmaxyx(stdscr, yMax, xMax);
    y = yMax/2;
    x = xMax/2;
    direction = 'l';
    score = 0;
    //creatoin du serpent
    int i = 0;
    while (i < 4) {
        Serpent serpent;
        serpent = {yMax/2, x};
        snake.push_back(serpent);
        i++;
    }
}

void Ncurses::createFood()
{
    //place des char au hasard mais assez loin des bords aka la nourriture
    char chFood = '@';
    food.y = rand() % (borderY+sizeY-2) +1;
    food.x = rand() % (borderX+sizeX-2) +1;
    mvaddch(food.y, food.x, chFood);
}

void Ncurses::gameWindow()
{
    //set up la window pour le jeux
    nibblerwin = newwin( yMax-6, xMax-1, 0, 0);
    refresh();
    box(nibblerwin, 0, 0);
    wrefresh(nibblerwin);
    getmaxyx(nibblerwin, sizeY, sizeX);
    getbegyx(nibblerwin, borderY, borderX);
}

void Ncurses::scoreWindow()
{
    //set up la window pour display le score et quitter
    scorewin = newwin( 5, xMax-1, yMax-6, 0);
    refresh();
    box(scorewin, 0, 0);
    wrefresh(scorewin);
}

void Ncurses::gameScreen(int screen)
{
    //chaque window pour score et jeu
    switch(screen){
        case 1:
            gameWindow();
            break;
        case 2:
            scoreWindow();
            break;
        default:
            break;
    }
}

int Ncurses::hit()
{
    int score = 0;

    for(i = snake.begin(); i != snake.end(); i++){
    //capturer food
        if( i->x == food.x && i->y == food.y ){
            Serpent tail;
            tail.y = snake.back().y;
            tail.x = snake.back().x;
            snake.push_back(tail);
            createFood();
            score += 1;
            return 1;
        }
    // taper queue ou bord == mort
        if ((i->x == x && i->y == y) || (i->x > (borderX+sizeX)-2 || i->x <= borderX || i->y > (borderY+sizeY)-2   || i->y <= borderY))
            return 2;
    }
    //else
    return 0;
}

int Ncurses::move()
{
    //toucher les fleches pour deplacer personnage
    int ch;
    ch = getch();
    switch(ch){
        case KEY_UP:
            if( direction != 'd')
                direction = 'u';
            break;
        case KEY_DOWN:
            if( direction != 'u')
                direction = 'd';
            break;
        case KEY_LEFT:
            if( direction != 'r')
                direction = 'l';
            break;
        case KEY_RIGHT:
            if( direction != 'l')
                direction = 'r';
            break;
        case 'q':
            return 0;
            break;
        default:
            break;
    }

    switch(direction){
        case 'u':
            y--;
            break;
        case 'd':
            y++;
            break;
        case 'l':
            x--;
            break;
        case 'r':
            x++;
            break;
    }
    //2 = mourrir
    if(hit() == 2){
        return 0;
    }

    //avancer le serpent et effacer ses traces derrieres
    snake.push_front({y, x});
    mvaddch(snake.back().y, snake.back().x, ' ');
    snake.pop_back();

    //print le serpent
    char chBody = 'o';
    for(i = snake.begin(); i != snake.end(); i++){
        mvaddch(i->y, i->x, chBody);
    }
    //vitesse serpent
    usleep(100000);
    return 1;
}

void Ncurses::endGame()
{
    //terminer
    mvwprintw(nibblerwin, sizeY/2, sizeX/2-8, "GAME OVER");
    wrefresh(nibblerwin);
    usleep(1000000);
    endwin();
}


int Ncurses::gameLoop()
{
    //affichage du jeu
    clear();
    gameScreen(1);
    gameScreen(2);
    createFood();

    while(move()){
        refresh();
        mvwprintw(scorewin, 1, 2, "Score: %d ", snake.size()-4);//*8);
        mvwprintw(scorewin, 2, 2, "Press 'q' to leave");
        wrefresh(nibblerwin);
        wrefresh(scorewin);
    };
    endGame();
    return (snake.size()-4);
}


int Ncurses::createWindow()
{
    initscr();
    return(menu());
}
