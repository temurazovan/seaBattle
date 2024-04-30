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

void displayField(bool arr[10][10]) {
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
    for (int i = begin.x; i <= end.x; i++) {
        for (int j = begin.y; j <= end.y; j++) {
            if (!arr[i][j]) {
                arr[i][j] = true;
            }
        }
    }
}

bool checkCoordinates(Coordinates first, Coordinates second) {
    if ((first.x < 0 || first.x > 9)
        || (first.y < 0 || first.y > 9)
        || (second.x < 0 || second.x > 9)
        || (second.y < 0 || second.y > 9)) {
        std::cout << "Error! Wrong input" << std::endl;
        return false;
    }
    if ((first.x != second.x) && (first.y != second.y)) { //если корабли расположены диагонально
        std::cout << "You can't place ship this way" << std::endl;
        return false;
    }
    if ((first.x - second.x < 0) || (first.x - second.x > 4)               //если меньше 1 и больше 4х палуб
        || (first.y - second.y < 0) || (first.y - second.y > 4)) {
        std::cout << "it is impossible to place a ship with so many decks!" << std::endl;
        return false;
    }
    return true;
}

int deckCounter(Coordinates begin, Coordinates end) { //счетчик палуб
    int counter = 0;
    if (begin.x != end.x) {
        counter = begin.x - end.x;
    } else {
        counter = begin.y - end.y;
    }

    return counter;
}

void shipCounter(int deckCounter) { // счетчик кораблей с разным кол-вом палуб
    Decks ship;
    if (deckCounter == 0) {
        ship.singleDeck++;
    }
    if (deckCounter == 1) {
        ship.doubleDeck++;
    }
    if (deckCounter == 2) {
        ship.threeDeck++;
    }
    if (deckCounter == 3) {
        ship.fourDeck++;
    }
}


int main() {
    bool field1[10][10];
    bool field2[10][10];
    Coordinates begin{}, end{};

    initialization(field1);
    initialization(field2);

    while (true) {
        std::cout << "Player 1, enter coordinates [x][y] [x1][y1]: ";
        std::cin >> begin.x >> begin.y >> end.x >> end.y;
        if (checkCoordinates(begin, end)) {
            shipCounter(deckCounter(begin, end));
            placeShip(begin, end, field1);
        }
        displayField(field1);

        std::cout << "Player 2, enter coordinates [x][y] [x1][y1]: ";
        std::cin >> begin.x >> begin.y >> end.x >> end.y;
        if (checkCoordinates(begin, end)) {
            shipCounter(deckCounter(begin, end));
            placeShip(begin, end, field2);
        }
        displayField(field2);
    }
}
