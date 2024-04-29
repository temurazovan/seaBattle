#include <iostream>

struct Coordinates {
    int x, y;
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

bool checkCoordinates(int c) {
    if (c < 0 || c > 9) {
        return false;
    }
    return true;
}

int main() {
    bool field1[10][10];
    bool field2[10][10];
    Coordinates begin{}, end{};

    initialization(field1);
    initialization(field2);

    std::cout << "Player 1, enter coordinates [x][y] [x1][y1]: ";
    std::cin >> begin.x >> begin.y >> end.x >> end.y;
    placeShip(begin, end, field1);


    displayField(field1);
}
