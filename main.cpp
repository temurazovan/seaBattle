#include <iostream>
#include "function.cpp"

int main() {
    bool map1[10][10];
    bool map2[10][10];
    Coordinates begin{}, end{};
    Decks ship1, ship2;
    int x, y;

    initialization(map1);
    initialization(map2);

    while (!isFilled(ship1) && !isFilled(ship2)) {
        std::cout << "Player 1, enter coordinates [x][y] [x1][y1]: ";
        std::cin >> begin.x >> begin.y >> end.x >> end.y;
        while (!checkCoordinates(begin, end, map1)) {
            std::cin >> begin.x >> begin.y >> end.x >> end.y;
        }
        if (shipCounter(deckCounter(begin, end), ship1)) {
            placeShip(begin, end, map1);
        }

        std::cout << "Player 2, enter coordinates [x][y] [x1][y1]: ";
        std::cin >> begin.x >> begin.y >> end.x >> end.y;
        while (!checkCoordinates(begin, end, map2)) {
            std::cin >> begin.x >> begin.y >> end.x >> end.y;
        }
        if (shipCounter(deckCounter(begin, end), ship2)) {
            placeShip(begin, end, map2);
        }
    }

    while (!win(map1) || !win(map2)) {
        std::cout << "Player 1, enter coordinates [x][y] [x1][y1] to bomb ship: ";
        std::cin >> x >> y;
        while (checkBombCoordinates(x, y) && map2[x - 1][y - 1]) {
            bombShip(x, y, map2);
            displayMap(map2);
            std::cout << "Player 1, enter coordinates [x][y] [x1][y1] to bomb ship: ";
            std::cin >> x >> y;
        }

        std::cout << "Player 2, enter coordinates [x][y] [x1][y1] to bomb ship: ";
        std::cin >> x >> y;
        while (checkBombCoordinates(x, y) && map1[x - 1][y - 1]) {
            bombShip(x, y, map1);
            displayMap(map1);
            std::cout << "Player 2, enter coordinates [x][y] [x1][y1] to bomb ship: ";
            std::cin >> x >> y;
        }
    }

    return 0;
}
