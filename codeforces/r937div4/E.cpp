#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = (int)1e9;

void run_case() {
    int N;
    std::cin >> N;

    std::string S;
    std::cin >> S;

    std::vector<int> div;
    for(int f = 1; f * f <= N; f++) {
        if(N % f == 0) {
            div.push_back(f);
            if(N / f != f) {
                div.push_back(N / f);
            }
        }
    }

    int ans = INF;
    for(int d : div) {
        int cnt = 0;
        int t = N / d;
        for(int i = 0; i < d; i++) {
            std::array<int, 26> f = {};
            int max_f = 0;
            for(int j = i; j < N; j += d) {
                max_f = std::max(max_f, ++f[S[j] - 'a']);
            } 
            cnt += t - max_f;
        }

        if(cnt <= 1) {
            ans = std::min(ans, d);
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
