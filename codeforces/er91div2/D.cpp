#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M, X, K, Y;
    std::cin >> N >> M >> X >> K >> Y;

    std::vector<int> A(N);
    std::vector<int> B(M);
    
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < M; i++) {
        std::cin >> B[i];
    }

    if(M > N) {
        std::cout << -1 << '\n';
        return;
    }

    auto cal = [&](int l, int r) {
        int x = l == -1 ? 0 : A[l];
        int y = r == N ? 0 : A[r];
        int len = r - l - 1;        

        if(len == 0) {
            return 0LL;
        }

        int max_v = 0;
        for(int i = l + 1; i < r; i++) {
            max_v = std::max(max_v, A[i]); 
        }

        if(len < K && std::max(x, y) < max_v) {
            return -1LL; 
        }

        int64_t cost = 0;
        if(Y * K <= X) {
            if(std::max(x, y) > max_v) {
                cost = static_cast<int64_t>(Y) * len;
            } else {
                cost = X + static_cast<int64_t>(len - K) * Y;
            }
        } else {
            cost = static_cast<int64_t>(len % K) * Y + static_cast<int64_t>(len / K) * X;
        }
        return cost;
    };

    int pre = -1;
    int i = 0;
    int j = 0;
    int64_t ans = 0;
    for(; i < N && j < M; i++) {
        if(A[i] == B[j]) {
            int64_t cost = cal(pre, i); 
            if(cost == -1) {
                std::cout << -1 << '\n';
                return;
            }
            ans += cost;
            pre = i;
            j += 1;
        }
    }

    if(j != M) {
        std::cout << -1 << '\n';
        return;
    }

    if(i != N) {
        int64_t cost = cal(pre, N);
        if(cost == -1) {
            std::cout << -1 << '\n';
            return;
        }
        ans += cost;
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
