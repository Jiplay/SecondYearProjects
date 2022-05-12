/*
** EPITECH PROJECT, 2021
** B-OOP-400-PAR-4-1-arcade-ibrahim.zafar
** File description:
** nibbler
*/

#include "nibbler.hpp"

// Serpent::Serpent()
// {
//     Serpent(0, 0);
// }

// Serpent::Serpent(int yPos, int xPos)
// {
//      y = yPos;
//      x = xPos;
// }

extern "C" Nibbler* create_object()
{
    return new Nibbler;
}

extern "C" void destroy_object( Nibbler* object )
{
    delete object;
}

void Nibbler::setGame()
{
//     initscr();
//     curs_set(0);
//     noecho();
//     cbreak();
//     nodelay(stdscr, true);
//     keypad(stdscr, true);
//     srand(time(NULL));
//     //debut du jeu position ordre et score
//     int score;
//     getmaxyx(stdscr, yMax, xMax);
//     y = yMax/2;
//     x = xMax/2;
//     direction = 'l';
//     score = 0;
//     //creatoin du serpent
//     int i = 0;
//     while (i < 4) {
//         Serpent serpent;
//         serpent = {yMax/2, x};
//         snake.push_back(serpent);
//         i++;
//     }
}

// void Nibbler::createFood()
// {
//     //place des char au hasard mais assez loin des bords aka la nourriture
//     char chFood = '@';
//     food.y = rand() % (borderY+sizeY-2) +1;
//     food.x = rand() % (borderX+sizeX-2) +1;
//     mvaddch(food.y, food.x, chFood);
// }

// void Nibbler::gameWindow()
// {
//     //set up la window pour le jeux
//     nibblerwin = newwin( yMax-6, xMax-1, 0, 0);
//     refresh();
//     box(nibblerwin, 0, 0);
//     wrefresh(nibblerwin);
//     getmaxyx(nibblerwin, sizeY, sizeX);
//     getbegyx(nibblerwin, borderY, borderX);
// }

// void Nibbler::scoreWindow()
// {
//     //set up la window pour display le score et quitter
//     scorewin = newwin( 5, xMax-1, yMax-6, 0);
//     refresh();
//     box(scorewin, 0, 0);
//     wrefresh(scorewin);
// }

// void Nibbler::gameScreen(int screen)
// {
//     //chaque window pour score et jeu
//     switch(screen){
//         case 1:
//             gameWindow();
//             break;
//         case 2:
//             scoreWindow();
//             break;
//         default:
//             break;
//     }
// }

int Nibbler::hit()
{
//     int score = 0;

//     for(i = snake.begin(); i != snake.end(); i++){
//     //capturer food
//         if( i->x == food.x && i->y == food.y ){
//             Serpent tail;
//             tail.y = snake.back().y;
//             tail.x = snake.back().x;
//             snake.push_back(tail);
//             createFood();
//             score += 1;
//             return 1;
//         }
//     // taper queue ou bord == mort
//         if ((i->x == x && i->y == y) || (i->x > (borderX+sizeX)-2 || i->x <= borderX || i->y > (borderY+sizeY)-2   || i->y <= borderY))
//             return 2;
//     }
//     //else
//     return 0;
}

int Nibbler::move()
{
//     //toucher les fleches pour deplacer personnage
//     int ch;
//     ch = getch();
//     switch(ch){
//         case KEY_UP:
//             if( direction != 'd')
//                 direction = 'u';
//             break;
//         case KEY_DOWN:
//             if( direction != 'u')
//                 direction = 'd';
//             break;
//         case KEY_LEFT:
//             if( direction != 'r')
//                 direction = 'l';
//             break;
//         case KEY_RIGHT:
//             if( direction != 'l')
//                 direction = 'r';
//             break;
//         case 'q':
//             return 0;
//             break;
//         default:
//             break;
//     }

//     switch(direction){
//         case 'u':
//             y--;
//             break;
//         case 'd':
//             y++;
//             break;
//         case 'l':
//             x--;
//             break;
//         case 'r':
//             x++;
//             break;
//     }
//     //2 = mourrir
//     if(hit() == 2){
//         return 0;
//     }

//     //avancer le serpent et effacer ses traces derrieres
//     snake.push_front({y, x});
//     mvaddch(snake.back().y, snake.back().x, ' ');
//     snake.pop_back();

//     //print le serpent
//     char chBody = 'o';
//     for(i = snake.begin(); i != snake.end(); i++){
//         mvaddch(i->y, i->x, chBody);
//     }
//     //vitesse serpent
//     usleep(100000);
//     return 1;
}

void Nibbler::endGame()
{
//     //terminer
//     mvwprintw(nibblerwin, sizeY/2, sizeX/2-8, "GAME OVER");
//     wrefresh(nibblerwin);
//     usleep(1000000);
//     endwin();
}


void Nibbler::gameLoop()
{
//     //affichage du jeu
//     clear();
//     gameScreen(1);
//     gameScreen(2);
//     createFood();

//     while(move()){
//         refresh();
//         mvwprintw(scorewin, 1, 2, "Score: %d ", snake.size()-4);//*8);
//         mvwprintw(scorewin, 2, 2, "Press 'q' to leave");
//         wrefresh(nibblerwin);
//         wrefresh(scorewin);
//     };
//     endGame();
}

int Nibbler::game(bool t)
{
    int score = 0;

    if (t == Library::ncurses_) {
        _temp = new dlopen_encapsulated("lib/arcade_ncurses.so", false);
        _temp->open();
        ILibs *libs = _temp->getAlibs();
        libs->setGame();
        score = libs->gameLoop();
        return score;
    } else {
        _temp = new dlopen_encapsulated("lib/arcade_sfml.so", false);
        _temp->open();
        ILibs *libs = _temp->getAlibs();
        score = libs->mainLoop();
        return score;
    }
}
