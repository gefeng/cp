#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M, K;
    std::cin >> N >> M >> K;

    std::string S;
    std::cin >> S;

    int rounds = std::min(N, M);
    std::vector<int> row(N, -1);
    std::vector<int> col(M, -1);
    std::vector<int> who(rounds, -1);
    for(int i = 0, j = 0; i < rounds; i++, j = (j + 1) % K) {
        int c = S[j] - 'A';
        row[i] = i;
        col[i] = i;
        who[i] = c;
    }

    int cnt_a = 0;
    int cnt_b = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            int v = std::max(row[i], col[j]); 
            if(who[v]) {
                cnt_b += 1;
            } else {
                cnt_a += 1;
            }
        }
    }

    //std::cout << cnt_a << ' ' << cnt_b << '\n';
    if(cnt_a == cnt_b) {
        std::cout << "Draw" << '\n';
        return;
    }

    std::cout << (cnt_a > cnt_b ? "Alice" : "Bob") << '\n';
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
