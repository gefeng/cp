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
    int N, D, M;
    std::cin >> N >> D >> M;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> a;
    std::vector<int> b;
    for(int i = 0; i < N; i++) {
        if(A[i] <= M) {
            a.push_back(A[i]);
        } else {
            b.push_back(A[i]);
        }
    }

    std::sort(a.begin(), a.end(), std::greater<int>());
    std::sort(b.begin(), b.end(), std::greater<int>());


    int64_t ans = 0;
    int n = a.size();
    int m = b.size();

    std::vector<int64_t> psum_a(n + 1, 0);
    std::vector<int64_t> psum_b(m + 1, 0);
    for(int i = 0; i < n; i++) {
        psum_a[i + 1] = psum_a[i] + a[i];
    }

    for(int i = 0; i < m; i++) {
        psum_b[i + 1] = psum_b[i] + b[i];
    }

    if(n == N) {
        ans = std::accumulate(a.begin(), a.end(), int64_t(0));
    }

    for(int i = 1; i <= m; i++) {
        int64_t tot = i + int64_t(i - 1) * D;
        if(tot > N) {
            continue;
        }

        int rem = N - tot;
        if(rem > n) {
            int first = n + 1;
            int need = N - first + 1 - tot; 
            if(need > D) {
                continue; 
            }
            tot += need;
        }

        ans = std::max(ans, psum_b[i] + psum_a[N - tot]);
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
