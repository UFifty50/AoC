#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <ranges>

void part1() {
    std::ifstream input("input.txt");
    std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> lines;
    std::string line;
    int count = 0;

    while (std::getline(input, line)) {
        auto pos = line.find('-');
        auto pos2 = line.find(',');
        auto pos3 = line.find('-', pos2);
        lines.push_back({
            {
                std::stoi(line.substr(0, pos)),
                std::stoi(line.substr(pos + 1, pos2 - pos - 1))
            },
            {
                std::stoi(line.substr(pos2 + 1, line.size() - pos2 - 1)),
                std::stoi(line.substr(pos3 + 1, line.size() - pos2 - 1))
            }
        });
    }
    
    // find if a range fits into another rage within a pair
    auto fits = [](auto range, auto pair) {
        return range.first >= pair.first && range.second <= pair.second;
    };

    for (auto line : lines) {
        if (fits(line.first, line.second) || fits(line.second, line.first)) {
            count++;
        }
    }

    std::cout << count << std::endl;

}

void part2() {
    std::ifstream input("input.txt");
    std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> lines;
    std::string line;
    int count = 0;

    while (std::getline(input, line)) {
        auto pos = line.find('-');
        auto pos2 = line.find(',');
        auto pos3 = line.find('-', pos2);
        lines.push_back({
            {
                std::stoi(line.substr(0, pos)),
                std::stoi(line.substr(pos + 1, pos2 - pos - 1))
            },
            {
                std::stoi(line.substr(pos2 + 1, line.size() - pos2 - 1)),
                std::stoi(line.substr(pos3 + 1, line.size() - pos2 - 1))
            }
        });
    }
    
    // find if ranges within a pair overlap
    auto overlaps = [](auto pair) {
        return (
            pair.first.first <= pair.second.first
            && pair.first.second >= pair.second.first)
            || (
                pair.second.first <= pair.first.first
                && pair.second.second >= pair.first.first
                );
    };

    for (auto line : lines) {
        if (overlaps(line)) {
            count++;
        }
    }

    std::cout << count << std::endl;
}

int main() {
    part1();
    part2();
}
            