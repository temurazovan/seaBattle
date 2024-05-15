#include <iostream>

struct Coordinates {
    int x, y;
};

struct Decks {
    int singleDeck = 0; //кол-во однопалубных кораблей
    int doubleDeck = 0; //кол-во двупалубных
    int threeDeck = 0; //кол-во трехпалубных
    int fourDeck = 0; //кол-во четырехпалубных
};

void initialization(bool arr[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            arr[i][j] = false;
        }
    }
}

void displayMap(bool arr[10][10]) {
    for (int i = 0; i < 10; i++) {
        std::cout << "----------------------------------------" << std::endl;
        for (int j = 0; j < 10; j++) {
            std::cout << "| " << arr[i][j] << " ";
        }
        std::cout << "|" << std::endl;
    }
    std::cout << "----------------------------------------" << std::endl;
}

void placeShip(Coordinates begin, Coordinates end, bool arr[10][10]) {
    for (int i = begin.x - 1; i <= end.x - 1; i++) {
        for (int j = begin.y - 1; j <= end.y - 1; j++) {
            if (!arr[i][j]) {
                arr[i][j] = true;
            }
        }
    }
}

bool checkCoordinates(Coordinates first, Coordinates second, bool arr[10][10]) {
    if ((first.x < 1 || first.x > 10)
        || (first.y < 1 || first.y > 10)
        || (second.x < 1 || second.x > 10)
        || (second.y < 1 || second.y > 10)) {
        std::cout << "Error! Wrong input" << std::endl;
        return false;
    }
    if ((first.x != second.x) && (first.y != second.y)) { //если корабли расположены диагонально
        std::cout << "You can't place ship this way" << std::endl;
        return false;
    }
    if (((abs(first.x - second.x) < 0)) || (abs(first.x - second.x) > 3)               //если меньше 1 и больше 4х палуб
        || (abs(first.y - second.y) < 0) || (abs(first.y - second.y) > 3)) {
        std::cout << "it is impossible to place a ship with so many decks!" << std::endl;
        return false;
    }
    if (arr[first.x - 1][first.y - 1] || arr[second.x - 1][second.y - 1]) {    //если ячейка уже занята
        std::cout << "This cell is already busy" << std::endl;
        return false;
    }
    return true;
}

int deckCounter(Coordinates begin, Coordinates end) { //счетчик палуб (количество занятых на поле клеточек одного корабля)
    int counter = 0;
    if (begin.x != end.x) {
        counter = abs(begin.x - end.x) + 1;
    } else {
        counter = abs(begin.y - end.y) + 1;
    }

    return counter;
}

bool shipCounter(int deckCounter, Decks &ship) { // счетчик кораблей с разным кол-вом палуб
    if (deckCounter == 1 && ship.singleDeck <= 4) {
        ship.singleDeck++;
        return true;
    }
    if (deckCounter == 2 && ship.doubleDeck <= 3) {
        ship.doubleDeck++;
        return true;
    }
    if (deckCounter == 3 && ship.threeDeck <= 2) {
        ship.threeDeck++;
        return true;
    }
    if (deckCounter == 4 && ship.fourDeck <= 1) {
        ship.fourDeck++;
        return true;
    }

    return false;
}

bool isFilled(Decks ship) {
    if (ship.singleDeck == 4 && ship.doubleDeck == 3 && ship.threeDeck == 2 && ship.fourDeck == 1) {
        return true;
    }

    return false;
}

bool win(bool arr[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (arr[i][j] != 0) {
                return false;
            }
        }
    }

    return true;
}

void bombShip(Coordinates begin, Coordinates end, bool map[10][10]) {
    for (int i = begin.x - 1; i <= end.x - 1; i++) {
        for (int j = begin.y - 1; j <= end.y - 1; j++) {
            if (map[i][j]) {
                map[i][j] = false;
            }
        }
    }
}

int main() {
    bool map1[10][10];
    bool map2[10][10];
    Coordinates begin{}, end{};
    Decks ship1, ship2;
    Decks bombedShip1, bombedShip2;

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
            displayMap(map1); //удалить после теста
        }
        std::cout << "Player 2, enter coordinates [x][y] [x1][y1]: ";
        std::cin >> begin.x >> begin.y >> end.x >> end.y;

        while (!checkCoordinates(begin, end, map2)) {
            std::cin >> begin.x >> begin.y >> end.x >> end.y;
        }
        if (shipCounter(deckCounter(begin, end), ship2)) {
            placeShip(begin, end, map2);
            displayMap(map2); //удалить после теста
        }
    }

    while (!win(map1) || !win(map2)) {
        std::cout << "Player 1, enter coordinates [x][y] [x1][y1]: ";
        std::cin >> begin.x >> begin.y >> end.x >> end.y;

        while (!checkCoordinates(begin, end, map1)) {
            std::cin >> begin.x >> begin.y >> end.x >> end.y;
        }
        if (shipCounter(deckCounter(begin, end), bombedShip1)) {
            placeShip(begin, end, map1);
            bombShip(begin, end, map1);
            displayMap(map1);
        }

        std::cout << "Player 2, enter coordinates [x][y] [x1][y1]: ";
        std::cin >> begin.x >> begin.y >> end.x >> end.y;

        while (!checkCoordinates(begin, end, map2)) {
            std::cin >> begin.x >> begin.y >> end.x >> end.y;
        }
        if (shipCounter(deckCounter(begin, end), bombedShip2)) {
            placeShip(begin, end, map2);
            bombShip(begin, end, map2);
            displayMap(map2);
        }

    }


}
