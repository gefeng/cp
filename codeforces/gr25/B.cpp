#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, K;
    std::cin >> N >> K;
    K -= 1;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    auto count = [](std::vector<int>& a, int k) {
        int res = 0;
        int cur = a[0];
        int n = a.size();
        for(int i = 1; i <= k; i++) {
            cur = std::max(cur, a[i]);  
        }

        if(cur == a[k]) {
            res = k == 0 ? 0 : 1;
            for(int i = k + 1; i < n; i++) {
                if(a[i] < a[k]) {
                    res += 1;
                } else {
                    break;
                }
            }
        }

        return res;
    };

    int ans = count(A, K);

    int p = -1;
    for(int i = 0; i < K; i++) {
        if(A[i] > A[K]) {
            p = i;
            break;
        }
    }

    if(p != -1) {
        std::vector<int> a(A);
        std::swap(a[p], a[K]);
        ans = std::max(ans, count(a, p));
    }

    std::swap(A[0], A[K]);
    ans = std::max(ans, count(A, 0));

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
