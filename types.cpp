#ifndef TYPES
#define TYPES

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

class Ships {
    
};

#endif
