#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, K, PA, PB;
    std::cin >> N >> K >> PA >> PB;
    PA -= 1;
    PB -= 1;
    
    std::vector<int> A(N);
    std::vector<int> B(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        A[i] -= 1;
    }
    
    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    auto get_best_score = [&](int p) {
        std::vector<int> vis(N, 0);
        int64_t max_s = 0;
        int64_t s = 0;
        int64_t t = 0;
        while(!vis[p] && t <= K) {
            max_s = std::max(max_s, s + (K - t) * B[p]);     
            t += 1; 
            s += B[p];
            vis[p] = 1;
            p = A[p];
        }

        return max_s;
    };

    int64_t score_a = get_best_score(PA);
    int64_t score_b = get_best_score(PB);

    if(score_a == score_b) {
        std::cout << "Draw" << '\n';
        return;
    }

    std::cout << (score_a > score_b ? "Bodya" : "Sasha") << '\n';
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
