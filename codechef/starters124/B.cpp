#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

int gcd(int a, int b) {
    if(a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

void run_case() {
    int L, R;
    std::cin >> L >> R;

    std::vector<int> ans;
    for(int i = L + 1; i <= R; i++) {
        ans.push_back(i);
    }
    ans.push_back(L);

    int n = R - L + 1;
    if(gcd(ans.back(), R) != 1) {
        for(int i = 0; i < n - 1; i++) {
            if(gcd(ans[i], R) == 1 && gcd(L, i + L) == 1) {
                std::swap(ans[i], ans[n - 1]);
                break;
            }     
        }

        if(gcd(ans.back(), R) != 1) {
            std::cout << -1 << '\n';
            return;
        }
    } 

    for(int i = 0; i < n; i++) {
        std::cout << ans[i] << " \n"[i == n - 1];
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
