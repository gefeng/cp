#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = int(2e9);

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::string S;
    std::cin >> S;

    std::vector<int> val(N, 0);
    std::vector<int> prefix_max(N + 1, 0);
    std::vector<int> prefix_min(N + 1, 0);
    std::vector<int> suffix_max(N + 1, -INF);
    std::vector<int> suffix_min(N + 1, INF);
    
    int now = 0;
    for(int i = 0; i < N; i++) {
        now += 1 * (S[i] == '-' ? -1 : 1); 
        prefix_max[i + 1] = std::max(prefix_max[i], now);
        prefix_min[i + 1] = std::min(prefix_min[i], now);
        val[i] = now;
    }

    for(int i = N - 1; i >= 0; i--) {
        suffix_max[N - i] = std::max(suffix_max[N - i - 1], val[i]);
        suffix_min[N - i] = std::min(suffix_min[N - i - 1], val[i]);
    } 

    for(int i = 0; i < M; i++) {
        int L, R;
        std::cin >> L >> R;
        L -= 1;
        R -= 1;
        
        int p_min = prefix_min[L]; 
        int p_max = prefix_max[L];
        int s_min = suffix_min[N - R - 1];
        int s_max = suffix_max[N - R - 1];
        
        int vl = L == 0 ? 0 : val[L - 1];
        int vr = val[R];
        int d = vl - vr;
        int res = 0;
    
        if(R != N - 1) {
            s_min += d;
            s_max += d;
            res = std::max(p_max, s_max) - std::min(p_min, s_min) + 1;
        } else {
            res = p_max - p_min + 1;
        }

        std::cout << res << '\n';
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
