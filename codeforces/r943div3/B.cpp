#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::string S, T;
    std::cin >> S >> T;
    
    int ans = 0;
    for(int i = 0, j = 0; i < N; i++) {
        while(j < M && S[i] != T[j]) {
            j += 1;
        }
        if(j == M) {
            break;
        }
        ans = i + 1;
        j += 1;
    }

    std::cout << ans << '\n';
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
