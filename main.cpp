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

void placeShip(Coordinates x, Coordinates y, bool arr[10][10]) {
    for (int i = x.x; i < y.x; i++) {
        for (int j = x.y; j < y.y; j++) {
            arr[i][j] = true;
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

    initialization(field1);
    initialization(field2);

//    std::cout << "Player 1, enter coordinates : ";
//    std::cin >> x.x >> y.y >> x.x >> y.y;
//    placeShip(x, y, field1);
    char dir = 0;

    int x = 0;
    int y = 0;


    while (dir != 'e') {
        std::cin >> dir;
        if (dir == 'w') {
            y--;
        }
        if (dir == 's') {
            y++;
        }
        if (dir == 'a') {
            x--;
        }
        if (dir == 'd') {
            x++;
        }
        if ((checkCoordinates(y)) && checkCoordinates(x)) {
            field1[y][x] = true;
            displayField(field1);
            continue;
        } else {
            std::cout << "out of bounds";
            break;
        }
    }

    //displayField(field1);
}
