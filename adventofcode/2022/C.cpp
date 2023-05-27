#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    std::string S;
    

    int sum = 0;
    std::vector<std::string> group;
    while(std::getline(std::cin, S)) {
        group.push_back(S);
        
        if(group.size() == 3) {
            for(char c1 = 'a', c2 = 'A'; c1 <= 'z'; c1++, c2++) {
                bool found = true;
                for(int i = 0; i < 3; i++) {
                    if(group[i].find(c1) == std::string::npos) {
                        found = false; 
                        break;
                    }
                }

                if(found) {
                    sum += c1 - 'a' + 1;
                    break;
                }

                found = true;
                for(int i = 0; i < 3; i++) {
                    if(group[i].find(c2) == std::string::npos) {
                        found = false; 
                        break;
                    }
                }

                if(found) {
                    sum += c2 - 'A' + 27;
                    break;
                }
            }

            group = std::vector<std::string>();
        }
    }

    std::cout << sum << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
