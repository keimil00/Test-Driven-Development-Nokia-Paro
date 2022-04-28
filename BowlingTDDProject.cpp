#include "catch/catch.hpp"
#include "BowlingGame.h"

class SimpleCalculator {
public:
    int add(int a, int b) {
        return a + b;
    }
};

TEST_CASE("SimpleCalculator_add_test") {
    SimpleCalculator testObj;

    REQUIRE( testObj.add(2, 2) == 4);
    REQUIRE( testObj.add(2, 4) == 6);
}

TEST_CASE("BowlingGame2Rounds0pins"){
    BowlingGame game;
    game.roll(0);
    game.roll(0);
    REQUIRE(game.getScore() == 0);
}
TEST_CASE("BowlingGame2RoundsWith1pin"){
    BowlingGame game;
    game.roll(1);
    game.roll(1);
    REQUIRE(game.getScore() == 2);
}

TEST_CASE("BowlingGame2RoundsWith1Spare"){
    BowlingGame game;
    game.roll(5);
    game.roll(5);

    game.roll(9);
    game.roll(0);

    REQUIRE(game.getScore() == 28);
}

TEST_CASE("BowlingGame10RoundsWithAllSpare"){
    BowlingGame game;
    for (int i = 0; i < 10; ++i) {
        game.roll(9);
        game.roll(1);
    }
    game.roll(9);

    REQUIRE(game.getScore() == 190);
}

TEST_CASE("BowlingGame10RoundsWithAll1"){
    BowlingGame game;
    for (int i = 0; i < 10; ++i) {
        game.roll(1);
        game.roll(1);
    }

    REQUIRE(game.getScore() == 20);
}

TEST_CASE("BowlingGame10RoundsWithAllStrike"){
    BowlingGame game;
    for (int i = 0; i < 12; ++i) {
        game.roll(10);
    }

    REQUIRE(game.getScore() == 300);
}

TEST_CASE("BowlingGame10RoundsWithVariousPins"){
    BowlingGame game;

    game.roll(1);
    game.roll(4);

    game.roll(4);
    game.roll(5);

    game.roll(6);
    game.roll(4);

    game.roll(5);
    game.roll(5);

    game.roll(10);

    game.roll(0);
    game.roll(1);

    game.roll(7);
    game.roll(3);

    game.roll(6);
    game.roll(4);

    game.roll(10);

    game.roll(2);
    game.roll(8);

    game.roll(6);

    REQUIRE(game.getScore() == 133);
}