#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <ranges>

void part1() {
    std::ifstream input("input.txt");
    
    std::string tmp = "";
    size_t count = 0;
    char c;

    while (input >> c && tmp.size() != 4) {
        count++;
        size_t duplicate = tmp.find(c);
        tmp.push_back(c);
        if (duplicate != std::string::npos) 
            tmp = tmp.substr(duplicate + 1);
    }
    std::cout << count << "\n";
}

void part2() {
    std::ifstream input("input.txt");
    
    std::string msg = "";
    size_t count = 0;
    char c;

    while (input >> c && msg.size() != 14) {
        count++;
        size_t duplicate = msg.find(c);
        msg.push_back(c);
        if (duplicate != std::string::npos) 
            msg = msg.substr(duplicate + 1);
    }
    std::cout << count << "\n";
}

int main() {
    part1();
    part2();
}
