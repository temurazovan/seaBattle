#include <iostream>

enum class State {
    Empty = 0,
    Ship = 1,
    DestroyedShip = 2,
    Miss = 4
};

struct Coordinates {
    int x, y;
};

struct Decks {
    int singleDeck = 0; //кол-во однопалубных кораблей
    int doubleDeck = 0; //кол-во двупалубных
    int threeDeck = 0; //кол-во трехпалубных
    int fourDeck = 0; //кол-во четырехпалубных
};

void initialization(State arr[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            arr[i][j] = State::Empty;
        }
    }
}

void displayMap(State arr[10][10], bool isEnemy) {
    for (int i = 0; i < 10; i++) {
        std::cout << "----------------------------------------" << std::endl;
        for (int j = 0; j < 10; j++) {
            std::cout << "| ";

            char charOutput = ' ';
            switch(arr[i][j]) {
                case State::Ship:
                    charOutput = isEnemy ? ' ' : '#';
                    break;
                case State::DestroyedShip:
                    charOutput = 'X';
                    break;
                case State::Miss:
                    charOutput = '.';
                    break;
                case State::Empty:
                default:
                    charOutput = ' ';
            }
            std::cout << charOutput << " ";
        }
        std::cout << "|" << std::endl;
    }
    std::cout << "----------------------------------------" << std::endl;
}

void placeShip(Coordinates begin, Coordinates end, State arr[10][10]) {
    for (int i = begin.x - 1; i <= end.x - 1; i++) {
        for (int j = begin.y - 1; j <= end.y - 1; j++) {
            if (arr[i][j] == State::Empty) {
                arr[i][j] = State::Ship;
            }
        }
    }
}

bool checkCoordinates(Coordinates first, Coordinates second, State arr[10][10]) {
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
    //если меньше 1 и больше 4х палуб
    if (((abs(first.x - second.x) < 0)) || (abs(first.x - second.x) > 3)
        || (abs(first.y - second.y) < 0) || (abs(first.y - second.y) > 3)) {
        std::cout << "it is impossible to place a ship with so many decks!" << std::endl;
        return false;
    }
    //если ячейка уже занята
    if (arr[first.x - 1][first.y - 1] == State::Ship || arr[second.x - 1][second.y - 1] == State::Ship) {
        std::cout << "This cell is already busy" << std::endl;
        return false;
    }
    return true;
}

// счетчик палуб (количество занятых на поле клеточек одного корабля)
int deckCounter(Coordinates begin, Coordinates end) {
    int counter = 0;
    if (begin.x != end.x) {
        counter = abs(begin.x - end.x) + 1;
    } else {
        counter = abs(begin.y - end.y) + 1;
    }

    return counter;
}

// счетчик кораблей с разным кол-вом палуб
bool shipCounter(int deckCounter, Decks &ship) {
    if (deckCounter == 1 && ship.singleDeck < 4) {
        ship.singleDeck++;
        return true;
    }
    if (deckCounter == 2 && ship.doubleDeck < 3) {
        ship.doubleDeck++;
        return true;
    }
    if (deckCounter == 3 && ship.threeDeck < 2) {
        ship.threeDeck++;
        return true;
    }
    if (deckCounter == 4 && ship.fourDeck < 1) {
        ship.fourDeck++;
        return true;
    }
    std::cout << "There are already many such ships on the map" << std::endl;

    return false;
}

bool isFilled(Decks ship) {
    if (ship.singleDeck == 4 && ship.doubleDeck == 3 && ship.threeDeck == 2 && ship.fourDeck == 1) {
        return true;
    }

    return false;
}

bool win(State arr[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (arr[i][j] == State::Ship) {
                return false;
            }
        }
    }

    return true;
}

void bombShip(int x, int y, State map[10][10]) {
    for (int i = x - 1; i <= x - 1; i++) {
        for (int j = y - 1; j <= y - 1; j++) {
            if (map[i][j] == State::Ship) {
                map[i][j] = State::DestroyedShip;
                std::cout << "Hit!" << std::endl;
            } else if (map[i][j] == State::Empty) {
                map[i][j] = State::Miss;
                std::cout << "Missed!" << std::endl;
            }
        }
    }
}

bool checkBombCoordinates(int x, int y) {
    if ((x < 1 || x > 10) || (y < 1 || y > 10)) {
        std::cout << "Error! Wrong input" << std::endl;
        return false;
    }

    return true;
}

void inputShip(State map[10][10], Decks &ship) {
    Coordinates begin{}, end{};
    std::cin >> begin.x >> begin.y >> end.x >> end.y;
    while (!checkCoordinates(begin, end, map)) {
        std::cin >> begin.x >> begin.y >> end.x >> end.y;
    }
    if (shipCounter(deckCounter(begin, end), ship)) {
        placeShip(begin, end, map);
    }
}