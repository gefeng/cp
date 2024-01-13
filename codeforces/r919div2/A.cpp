#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N;
    std::cin >> N;
    
    int lo = 0;
    int hi = (int)1e9;
    std::vector<int> a;
    for(int i = 0; i < N; i++) {
        int T, X;
        std::cin >> T >> X;

        if(T == 1) {
            lo = std::max(lo, X);
        } else if(T == 2) {
            hi = std::min(hi, X);
        } else {
            a.push_back(X); 
        }
    }

    int ans = hi - lo + 1;
    for(int x : a) {
        if(x >= lo && x <= hi) {
            ans -= 1;
        }
    }

    std::cout << std::max(0, ans) << '\n';
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
