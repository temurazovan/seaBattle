#include <iostream>
#include "function.cpp"


int main() {
    State map1[10][10];
    State map2[10][10];
    Decks ship1, ship2;
    int x, y;

    initialization(map1);
    initialization(map2);

    while (!isFilled(ship1)) {
        std::cout << "Player 1, enter coordinates [x][y] [x1][y1]: ";
        inputShip(map1, ship1);
        displayMap(map1, false);
    }
    while (!isFilled(ship2)) {
        std::cout << "Player 2, enter coordinates [x][y] [x1][y1]: ";
        inputShip(map2, ship2);
        displayMap(map2, false);
    }
    while (!win(map1) || !win(map2)) {
        // пока координаты проходят проверку И это попадение в корабль
        while (true) {
            std::cout << "Player 1, enter coordinates [x][y] [x1][y1] to bomb ship: ";
            std::cin >> x >> y;
            if (checkBombCoordinates(x, y) && map2[x - 1][y - 1] == State::Ship) {
                bombShip(x, y, map2);
                displayMap(map2, true);
            } else {
                break;
            }
        }

        std::cout << "Player 2, enter coordinates [x][y] [x1][y1] to bomb ship: ";
        std::cin >> x >> y;
        // пока координаты проходят проверку И это попадение в корабль
        while (checkBombCoordinates(x, y) && map1[x - 1][y - 1] == State::Ship) {
            bombShip(x, y, map1);
            displayMap(map1, true);
            std::cout << "Player 2, enter coordinates [x][y] [x1][y1] to bomb ship: ";
            std::cin >> x >> y;
        }
    }

    return 0;
}



