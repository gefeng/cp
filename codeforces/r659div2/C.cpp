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

    std::string S, T;
    std::cin >> S >> T;

    std::vector<std::vector<int>> freq(20, std::vector<int>(20, 0));
    for(int i = 0; i < N; i++) {
        if(S[i] == T[i]) {
            continue;
        }
        if(S[i] > T[i]) {
            std::cout << -1 << '\n';
            return;
        }

        freq[T[i] - 'a'][S[i] - 'a'] += 1;
    }

    int ans = 0;
    for(int i = 1; i < 20; i++) {
        for(int j = 0; j < i; j++) {
            if(freq[i][j] == 0) {
                continue;
            }
            for(int k = i + 1; k < 20; k++) {
                int f = freq[k][j];
                freq[k][j] = 0;
                freq[k][i] += f;
            }
            ans += 1;
        }
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
