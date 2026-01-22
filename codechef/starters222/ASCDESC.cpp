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
    int N, K;
    std::cin >> N >> K;

    std::vector<int> ans(N, 0);

    int offset = sqrt(N);
    int p = 0;
    for(int k = offset - 1; k >= 0; k--) {
        for(int i = k; i < N; i += offset) {
            if(p < N) {
                ans[p++] = i;
            }
        }
    }

    int s = 0;
    std::vector<int> b(N);
    for(int i = 0; i < N; i++) {
        b[ans[i]] = i;
    }

    for(int i = 1; i < N; i++) {
        if(ans[i] > ans[i - 1]) {
            s += 1;
        }
        if(b[i] < b[i - 1]) {
            s += 1;
        }
    }

    for(int i = 0; i < N; i++) {
        std::cout << ans[i] + 1 << " \n"[i == N - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
