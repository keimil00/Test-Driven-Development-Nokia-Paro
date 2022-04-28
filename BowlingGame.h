#pragma once

class BowlingGame
{
public:
	void roll(int pins) {
        rolls.push_back(pins);
    }

    bool isSpare (int rollNumber) {
        return rollNumber - 1 >= 0 and rolls[rollNumber-1] + rolls[rollNumber] == 10;
    }

    bool isStrike (int rollNumber) {
        return rollNumber >= 0 and rolls[rollNumber] == 10;
    }

	int getScore() {
        int score = 0;
        int roundNumber = 1;
        int throwNumber = 1;
        for (int i = 0; i < rolls.size(); ++i) {

            score += rolls[i];

            if (throwNumber == 2 and isSpare(i)) {
                score += rolls[i + 1];
            } else if (throwNumber == 1 and isStrike(i)) {
                score += rolls[i + 1] + rolls[i + 2];
                throwNumber = 2;
            }
            if(throwNumber == 1){ throwNumber++; }
            else {
                roundNumber++;
                throwNumber = 1;
            }
            if(roundNumber > 10) { i = rolls.size(); }
        }
        return score;
    }


private:
    std::vector<int> rolls;

};

