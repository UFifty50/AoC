#include <iostream>
#include <fstream>
#include <string>
#include <map>

#define WIN 6
#define DRAW 3
#define LOSS 0

#define ROCK 1
#define PAPER 2
#define SCISSORS 3


void part1() {
    std::ifstream input("input.txt");
    std::string tmp;
    int score = 0;
    std::map<std::string, int> scores = {
        {"A X", DRAW + ROCK},
        {"A Y", WIN + PAPER},
        {"A Z", LOSS + SCISSORS},
        {"B X", LOSS + ROCK},
        {"B Y", DRAW + PAPER},
        {"B Z", WIN + SCISSORS},
        {"C X", WIN + ROCK},
        {"C Y", LOSS + PAPER},
        {"C Z", DRAW + SCISSORS},
    };
    
    while (std::getline(input, tmp)) {
        auto item = scores.find(tmp);
        if (item != scores.end()) {
            score += item->second;
        }
    }

    std::cout << score << std::endl;
}

void part2() {
    std::ifstream input("input.txt");
    std::string tmp;
    int score = 0;
    std::map<std::string, int> scores = {
        {"A X", LOSS + SCISSORS},
        {"A Y", DRAW + ROCK},
        {"A Z", WIN + PAPER},
        {"B X", LOSS + ROCK},
        {"B Y", DRAW + PAPER},
        {"B Z", WIN + SCISSORS},
        {"C X", LOSS + PAPER},
        {"C Y", DRAW + SCISSORS},
        {"C Z", WIN + ROCK},
    };

    
    while (std::getline(input, tmp)) {
        auto item = scores.find(tmp);
        if (item != scores.end()) {
            score += item->second;
        }
    }

    std::cout << score << std::endl;
}

int main() {
    part1();
    part2();
}
