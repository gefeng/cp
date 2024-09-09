#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <numeric>

constexpr int LOG = 20;

void run_case() {
    int N, K;
    std::cin >> N >> K;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    auto solve = [&](int t) {
        std::vector<std::vector<int>> jump(LOG, std::vector<int>(N, 0)); 
        std::vector<std::vector<int64_t>> dist(LOG, std::vector<int64_t>(N, 0)); 
        
        for(int i = 0, j = 0, d = 0, sum = 0; i < N; i++) {
            while(sum < t) {
                sum += A[j]; 
                j = (j + 1) % N;
                d += 1;
            }
            jump[0][i] = j;
            dist[0][i] = d;

            sum -= A[i];
            d -= 1;
        }

        for(int i = 1; i < LOG; i++) {
            for(int j = 0; j < N; j++) {
                jump[i][j] = jump[i - 1][jump[i - 1][j]];
                dist[i][j] = dist[i - 1][j] + dist[i - 1][jump[i - 1][j]];
            }
        }

        int res = 0;
        for(int i = 0; i < N; i++) {
            int64_t d = 0;
            int v = i;
            for(int j = LOG - 1; j >= 0; j--) {
                if(K & (1 << j)) {
                    d += dist[j][v]; 
                    v = jump[j][v];
                }
            }
            if(d > N) {
                res += 1; 
            }
        }

        return res;
    };

    int lo = 1;
    int hi = std::accumulate(A.begin(), A.end(), 0);
    int ans_v = 0;
    int ans_c = 0;
    while(lo <= hi) {
        int mid = lo + (hi - lo) / 2;

        int res = solve(mid);
        if(res < N) {
            ans_v = mid;
            ans_c = res;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    std::cout << ans_v << ' ' << ans_c << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
