#include <iostream>
#include "function.cpp"


int main() {
//    State map1[10][10];
//    State map2[10][10];
    Decks ship1, ship2;
    Coordinates bomb = {0, 0};

//    initialization(map1);
//    initialization(map2);
//
//    while (!isFilled(ship1)) {
//        std::cout << "Player 1, enter coordinates [x][y] [x1][y1]: ";
//        inputShip(map1, ship1);
//        displayMap(map1, false);
//    }
//    while (!isFilled(ship2)) {
//        std::cout << "Player 2, enter coordinates [x][y] [x1][y1]: ";
//        inputShip(map2, ship2);
//        displayMap(map2, false);
//    }

    State map1[10][10] = {State::Ship, State::Empty, State::Empty, State::Empty, State::Ship, State::Ship,State::Empty, State::Ship, State::Ship,State::Empty,
                          State::Empty, State::Ship, State::Empty, State::Empty, State::Empty,State::Empty,State::Empty,State::Empty,State::Empty,State::Ship,
                          State::Empty, State::Empty, State::Ship, State::Empty, State::Ship, State::Ship, State::Empty,State::Empty,State::Empty,State::Ship,
                          State::Empty,State::Empty,State::Empty, State::Ship, State::Empty, State::Empty, State::Empty, State::Empty, State::Empty, State::Ship,
                          State::Empty, State::Empty, State::Empty, State::Empty, State::Empty, State::Empty, State::Empty, State::Empty, State::Empty, State::Empty,
                          State::Ship, State::Ship, State::Ship, State::Empty, State::Ship, State::Ship, State::Ship, State::Ship, State::Empty, State::Empty,
                          State::Empty, State::Empty, State::Empty, State::Empty, State::Empty, State::Empty, State::Empty, State::Empty, State::Empty, State::Empty,
                          State::Empty, State::Empty, State::Empty, State::Empty, State::Empty, State::Empty, State::Empty, State::Empty, State::Empty, State::Empty,
                          State::Empty, State::Empty, State::Empty, State::Empty, State::Empty, State::Empty, State::Empty, State::Empty, State::Empty, State::Empty,
                          State::Empty, State::Empty, State::Empty, State::Empty, State::Empty, State::Empty, State::Empty, State::Empty, State::Empty, State::Empty,
    };
    State map2[10][10] = {State::Ship, State::Empty, State::Empty, State::Empty, State::Ship, State::Ship,State::Empty, State::Ship, State::Ship,State::Empty,
                          State::Empty, State::Ship, State::Empty, State::Empty, State::Empty,State::Empty,State::Empty,State::Empty,State::Empty,State::Ship,
                          State::Empty, State::Empty, State::Ship, State::Empty, State::Ship, State::Ship, State::Empty,State::Empty,State::Empty,State::Ship,
                          State::Empty,State::Empty,State::Empty, State::Ship, State::Empty, State::Empty, State::Empty, State::Empty, State::Empty, State::Ship,
                          State::Empty, State::Empty, State::Empty, State::Empty, State::Empty, State::Empty, State::Empty, State::Empty, State::Empty, State::Empty,
                          State::Ship, State::Ship, State::Ship, State::Empty, State::Ship, State::Ship, State::Ship, State::Ship, State::Empty, State::Empty,
                          State::Empty, State::Empty, State::Empty, State::Empty, State::Empty, State::Empty, State::Empty, State::Empty, State::Empty, State::Empty,
                          State::Empty, State::Empty, State::Empty, State::Empty, State::Empty, State::Empty, State::Empty, State::Empty, State::Empty, State::Empty,
                          State::Empty, State::Empty, State::Empty, State::Empty, State::Empty, State::Empty, State::Empty, State::Empty, State::Empty, State::Empty,
                          State::Empty, State::Empty, State::Empty, State::Empty, State::Empty, State::Empty, State::Empty, State::Empty, State::Empty, State::Empty,
    };
    while (!win(map1) || !win(map2)) {
        // пока координаты проходят проверку И это попадение в корабль
        while (true) {
            std::cout << "Player 1, enter coordinates [x][y] [x1][y1] to bomb ship: ";
            std::cin >> bomb.x >> bomb.y;
            if (checkBombCoordinates(bomb.x, bomb.y) && map2[bomb.x - 1][bomb.y - 1] == State::Ship) {
                bombShip(bomb.x, bomb.y, map2);
                displayMap(map2, true);
            } else if (checkBombCoordinates(bomb.x, bomb.y) && map2[bomb.x - 1][bomb.y - 1] != State::Ship){
                bombShip(bomb.x, bomb.y, map2);
                displayMap(map2, true);
                break;
            } else {
                break;
            }
        }

        // пока координаты проходят проверку И это попадение в корабль
        while (true) {
            std::cout << "Player 2, enter coordinates [x][y] [x1][y1] to bomb ship: ";
            std::cin >> bomb.x >> bomb.y;
            if (checkBombCoordinates(bomb.x, bomb.y) && map1[bomb.x - 1][bomb.y - 1] == State::Ship) {
                bombShip(bomb.x, bomb.y, map1);
                displayMap(map1, true);
            } else if (checkBombCoordinates(bomb.x, bomb.y) && map1[bomb.x - 1][bomb.y - 1] != State::Ship){
                bombShip(bomb.x, bomb.y, map1);
                displayMap(map1, true);
                break;
            } else {
                break;
            }
        }
    }

    return 0;
}



