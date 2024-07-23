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

