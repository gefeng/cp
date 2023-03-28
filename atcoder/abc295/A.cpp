#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

void run_case() {
    int N;
    std::cin >> N;

    std::set<std::string> s = {"and", "not", "that", "the", "you"};

    bool ans = false;
    for(int i = 0; i < N; i++) {
        std::string S;
        std::cin >> S;
    
        if(s.find(S) != s.end()) {
            ans = true;
        }
    }

    std::cout << (ans ? "Yes" : "No") << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
