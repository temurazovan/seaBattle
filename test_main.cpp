#include "function.cpp"
#include <gtest/gtest.h>

TEST(SeaBattle, ShipCounter) {
    Decks ship;

    EXPECT_TRUE(shipCounter(1, ship));
    EXPECT_EQ(ship.singleDeck, 1);
    EXPECT_EQ(ship.doubleDeck, 0);
    EXPECT_EQ(ship.threeDeck, 0);
    EXPECT_EQ(ship.fourDeck, 0);

    EXPECT_TRUE(shipCounter(4, ship));
    EXPECT_EQ(ship.singleDeck, 1);
    EXPECT_EQ(ship.doubleDeck, 0);
    EXPECT_EQ(ship.threeDeck, 0);
    EXPECT_EQ(ship.fourDeck, 1);

    EXPECT_FALSE(shipCounter(4, ship));
    EXPECT_EQ(ship.singleDeck, 1);
    EXPECT_EQ(ship.doubleDeck, 0);
    EXPECT_EQ(ship.threeDeck, 0);
    EXPECT_EQ(ship.fourDeck, 1);
}

TEST(SeaBattle, IsFilledPositive) {
    Decks deck = {4, 3, 2, 1};
    EXPECT_TRUE(isFilled(deck));
}

TEST(SeaBattle, IsFilledNegative) {
    Decks deck = {4, 2, 0, 0};
    EXPECT_FALSE(isFilled(deck));
}

TEST(SeaBattle, Win) {
    State arr[10][10] = {
            true, false, true, false, true, true, true, false, false, false,
            false, false, true, false, false, false, false, false, false, false,
            true, false, false, false, true, true, true, false, false, false,
            false, false, true, false, false, false, false, false, false, false,
            true, false, true, false, false, false, false, false, false, false,
            false, false, false, false, false, false, false, false, false, false,
            true, false, true, false, false, false, false, false, false, false,
            false, false, true, false, false, false, false, false, false, false,
            false, false, false, false, false, false, false, false, false, false,
            false, false, false, false, false, false, true, true, true, true
    };
    EXPECT_FALSE(win(arr));
}

TEST(SeaBattle, WinPositive) {
    bool arr[10][10] = {
            false, false, false, false, false, false, false, false, false, false,
            false, false, false, false, false, false, false, false, false, false,
            false, false, false, false, false, false, false, false, false, false,
            false, false, false, false, false, false, false, false, false, false,
            false, false, false, false, false, false, false, false, false, false,
            false, false, false, false, false, false, false, false, false, false,
            false, false, false, false, false, false, false, false, false, false,
            false, false, false, false, false, false, false, false, false, false,
            false, false, false, false, false, false, false, false, false, false,
            false, false, false, false, false, false, false, false, false, false
    };

    EXPECT_TRUE(win(arr));
}

TEST(SeaBattle, BombShipPositive) {
    bool arr[10][10] = {
            true, false, true, false, true, true, true, false, false, false,
            false, true, true, false, false, false, false, false, false, false,
            true, false, false, false, true, true, true, false, false, false,
            false, false, true, false, false, false, false, false, false, false,
            true, false, true, false, false, false, false, false, false, false,
            false, false, false, false, false, false, false, false, false, false,
            true, false, true, false, false, false, false, false, false, false,
            false, false, true, false, false, false, false, false, false, false,
            false, false, false, false, false, false, false, false, false, false,
            false, false, false, false, false, false, true, true, true, true
    };
    bombShip(1, 1, arr);
    EXPECT_FALSE(arr[0][0]);
    EXPECT_TRUE(arr[1][1]);
}

TEST(SeaBattle, CheckBombCoordPositive) {
    EXPECT_TRUE(checkBombCoordinates(10, 10));
}

TEST(SeaBattle, DeckCounter) {
    Coordinates begin = {7, 4};
    Coordinates end = {7, 7};
    EXPECT_EQ(deckCounter(begin, end), 4);
}

TEST(SeaBattle, DeckCounterNegative) {
    Coordinates begin = {7, 4};
    Coordinates end = {7, 4};
    EXPECT_EQ(deckCounter(begin, end), 1);
}



