#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <numeric>

void run_case() {
    int N, D;
    std::cin >> N >> D;

    std::vector<int> par(N, -1);
    std::vector<int> lv(N, 1);
    std::vector<int> depth(N, 0);
    std::vector<int> cnt_c(N, 0);

    int sum = N * (N - 1) / 2;
    if(D > sum) {
        std::cout << "NO" << '\n';
        return;
    }

    for(int i = 1; i < N; i++) {
        par[i] = i - 1;
        cnt_c[i - 1] = 1;
        depth[i] = i;
    }

    while(sum > D) {
        int v = -1;
        int d = -1;
        for(int i = 0; i < N; i++) {
            if(depth[i] > 1 && cnt_c[i] == 0) {
                if((d == -1 || depth[i] < d) && (depth[i] - 1 >= 20 || lv[depth[i] - 1] != 1 << (depth[i] - 1))) {
                    d = depth[i];
                    v = i;
                } 
            }
        }

        if(v == -1) {
            std::cout << "NO" << '\n';
            return;
        }
        
        int p = -1;
        int min_d = -1;
        for(int i = 0; i < N; i++) {
            int dep = depth[i];
            if(dep + 1 < d && d - dep - 1 + D <= sum && cnt_c[i] < 2) {
                if(min_d == -1 || dep < min_d) {
                    p = i;
                    min_d = dep;
                } 
            }
        }

        if(p == -1) {
            std::cout << "NO" << '\n';
            return;
        }

        cnt_c[par[v]] -= 1;
        cnt_c[p] += 1;
        par[v] = p;
        sum -= d - min_d - 1;
        lv[depth[v]] -= 1;
        depth[v] = min_d + 1;
        lv[depth[v]] += 1;
    }

    std::cout << "YES" << '\n';
    for(int i = 1; i < N; i++) {
        std::cout << par[i] + 1 << " \n"[i == N - 1];
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
