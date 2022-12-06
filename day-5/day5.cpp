#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>


void part1() {
    std::ifstream file("input.txt");
    std::string line;
    std::vector<char> crates[9];

    while (std::getline(file, line)) {
        if (line.substr(1, 1) == "1") break;
        for (int i = 0; i < 9; i++) {
            if (line.substr(4*i + 1, 1) == " ") continue;
            crates[i].push_back(line[4*i + 1]);
        }
    }
    
    for (int i = 0; i < 9; i++) {
        std::reverse(crates[i].begin(), crates[i].end());
    }
    
    int num, from, to;
    std::string ignore;
    while (file >> ignore >> num >> ignore >> from >> ignore >> to) {
        for (int i = 0; i < num; i++) {
        crates[to - 1].push_back(crates[from - 1].back());
        crates[from - 1].pop_back();
    }
    }

    for (int i = 0; i < 9; i++) {
        std::cout << crates[i].back();
    }
    std::cout << std::endl;
}

void part2() {
    std::ifstream file("input.txt");
    std::string line;
    std::vector<char> crates[9];

    while (std::getline(file, line)) {
        if (line.substr(1, 1) == "1") break;
        for (int i = 0; i < 9; i++) {
            if (line.substr(4*i + 1, 1) == " ") continue;
            crates[i].push_back(line[4*i + 1]);
        }
    }
    
    for (int i = 0; i < 9; i++) {
        std::reverse(crates[i].begin(), crates[i].end());
    }
    
    int num, from, to;
    std::string ignore;
    while (file >> ignore >> num >> ignore >> from >> ignore >> to) {
        int size = crates[from - 1].size();
        for (int i = num; i > 0; i--) 
            crates[to - 1].push_back(crates[from - 1][size - i]);
        for (int i = 0; i < num; i++) 
            crates[from - 1].pop_back();
    }

    for (int i = 0; i < 9; i++) {
        std::cout << crates[i].back();
    }
    std::cout << std::endl;
}

int main() {
    part1();
    part2();
}
