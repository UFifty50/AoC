#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <ranges>


void part1() {
    std::ifstream input("input.txt");
    std::string tmp;
    std::string h1;
    std::string h2;
    char c;
    int res = 0;
    
    while (std::getline(input, tmp)) {
        h1 = tmp.substr(0, tmp.length()/2);
        h2 = tmp.substr(tmp.length()/2, tmp.length());
        c = h1[h1.find_first_of(h2)];
        res += (c <= 90) ? c - 38 : c - 96;
    }
    std::cout << res << std::endl;
}

void part2() {
    std::ifstream input("input.txt");
    std::string l1;
    std::string l2;
    std::string l3;
    int res = 0;
    auto intersection = [](std::string s1, std::string s2) {
        std::string res;
        for (auto c : s1) {
            if (s2.find(c) != std::string::npos) {
                res += c;
            }
        }
        return res;
    };
    
    while (std::getline(input, l1)) {
        std::getline(input, l2);
        std::getline(input, l3);
        // find the common character
        char c = intersection(intersection(l1, l2), l3)[0];
        res += (c <= 90) ? c - 38 : c - 96;
        
        
    }
    std::cout << res << std::endl;
}

int main() {
    part1();
    part2();
}
