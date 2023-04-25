#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int MAX = 1e9;

int gcd(int a, int b) {
    if(a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

void run_case() {
    int A, B;
    std::cin >> A >> B;

    if(A == 0 && B == 0) {
        std::cout << 1 << '\n';
        std::cout << 0 << ' ' << 0 << '\n';
        return;
    }

    int g = gcd(A, B);
    
    std::vector<std::pair<int, int>> ans;
    if(g != 1) {
        for(int i = -1; i <= 1; i++) {
            bool found = false;
            for(int j = -1; j <= 1; j++) {
                if(A + i >= 0 && A + i <= MAX && B + j >= 0 && B + j <= MAX && gcd(A + i, B + j) == 1) {
                    ans.emplace_back(A + i, B + j);
                    found = true;
                    break;
                }
            }

            if(found) {
                break;
            }
        } 
    }
    ans.emplace_back(A, B);
    
    std::cout << ans.size() << '\n';
    for(int i = 0; i < ans.size(); i++) {
        std::cout << ans[i].first << ' ' << ans[i].second << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
