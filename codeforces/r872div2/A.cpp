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
    std::cin >> S;

    int n = S.size();
    bool ok = false;
    for(int i = 0; i < n; i++) {
        if(S[i] != S[0]) {
            ok = true;
            break;
        }
    }

    if(!ok) {
        std::cout << -1 << '\n';
        return;
    }

    std::cout << n - 1 << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
