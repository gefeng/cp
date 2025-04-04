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

    N *= 2;
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int ans = 0;
    std::set<std::pair<int, int>> seen;
    
    for(int i = 0; i < N - 1; i++) {
        int x = A[i];
        int y = A[i + 1];
        
        if(seen.find({x, y}) != seen.end()) {
            ans += 1;
            continue;
        }

        if(seen.find({y, x}) != seen.end()) {
            if(i && A[i - 1] != x && A[i - 1] != y) {
                ans += 1;
            }
        }

        seen.emplace(x, y);
    }

    std::cout << ans << '\n';
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
