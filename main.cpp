#include <iostream>
#include "function.cpp"
//#include "mockdata.cpp"

int main() {
    State map1[10][10];
    State map2[10][10];
    Decks ship1, ship2;

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

    while (true) {
        if (playerTurn("Player 1", map2)) {
            std::cout << "Player 1 is win!";
            break;
        }
        if (playerTurn("Player 2", map1)) {
            std::cout << "Player 2 is win!";
            break;
        }
    }

    return 0;
}
