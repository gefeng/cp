#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int MAX = 100;

void run_case() {
    int N;
    std::cin >> N;

    std::string ans = "";
    bool bad = false;
    for(int i = 0; i < N; i++) {
        char C;
        int64_t L;
        std::cin >> C >> L;
        
        if(L + ans.size() > MAX) {
            bad = true;
        }

        if(!bad) {
            ans += std::string(L, C);
        }
    }

    std::cout << (bad ? "Too Long" : ans) << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
