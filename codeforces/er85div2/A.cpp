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

    std::vector<std::pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first >> A[i].second;
    }

    int plays = 0;
    int clear = 0;
    bool ans = true;
    for(int i = 0; i < N; i++) {
        auto [p, c] = A[i];
        
        if(p < plays || c < clear) {
            ans = false;
            break;
        }
            
        if(p - plays < c - clear) {
            ans = false;
            break;
        }
        
        plays = p;
        clear = c;
    }

    std::cout << (ans ? "YES" : "NO") << '\n';
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
