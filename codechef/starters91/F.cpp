#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using LL = long long;

void run_case() {
    int N, Q;
    std::cin >> N >> Q;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> d(N + 1, 0);
    for(int i = 0; i < Q; i++) {
        int L, R;
        std::cin >> L >> R;
        
        L -= 1;
        R -= 1;

        d[L] += 1;
        d[R + 1] -= 1;
    }

    int sum = 0;
    std::vector<std::pair<int, int>> v(N);
    for(int i = 0; i < N; i++) {
        sum += d[i];
        v[i] = {sum, i};
    } 

    std::sort(v.begin(), v.end(), std::greater<std::pair<int, int>>());
    std::sort(A.begin(), A.end(), std::greater<int>());

    std::vector<int> ans(N);
    LL x = 0LL;
    for(int i = 0; i < N; i++) {
        ans[v[i].second] = A[i]; 
        x += 1LL * A[i] * v[i].first;
    }

    std::cout << x << '\n';
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
