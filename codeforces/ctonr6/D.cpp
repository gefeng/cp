#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

const int INF = (int)1e9;

void run_case() {
    int N, K;
    std::cin >> N;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::cin >> K;
    
    std::vector<int> save_min(N, INF);
    save_min[N - 1] = A[N - 1];
    for(int i = N - 2; i >= 0; i--) {
        save_min[i] = std::min(save_min[i + 1], A[i]);
    }

    std::vector<int> ans(N, 0);
    ans[0] = K / save_min[0];
    int rem = K % save_min[0];
    int cnt = ans[0];

    for(int i = 1; i < N; i++) {
        if(save_min[i] != save_min[i - 1]) {
            cnt = std::min(cnt, rem / (save_min[i] - save_min[i - 1]));
            rem = rem - cnt * (save_min[i] - save_min[i - 1]);
        }

        ans[i] = cnt;
    }

    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << " \n"[i == N - 1];
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
