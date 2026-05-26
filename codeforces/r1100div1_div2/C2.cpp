#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t INF = static_cast<int64_t>(2e18);

void run_case() {
    int N;
    std::cin >> N;
 
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> ans;
    
    std::vector<int64_t> suffix(N + 1, 0);
    for(int i = 1; i <= N; i++) {
        suffix[i] = suffix[i - 1] + A[N - i];
    }

    int64_t prefix = 0;
    int64_t max_s = suffix[N];
    int p = -1;
    for(int i = 0; i < N; i++) {
        if(A[i] > 0) {
            int64_t cand = prefix + suffix[N - 1 - i] - A[i];
            if(cand > max_s) {
                max_s = cand;
                p = i;
            }
        }
        prefix += std::abs(A[i]);
    }

    if(p == -1) {
        std::cout << 0 << '\n';
        return;
    }

    for(int i = 0; i < p; i++) {
        if(A[i] < 0) {
            continue;
        }
        int j = i;
        while(i + 1 < p && A[i + 1] > 0) {
            i++;
        }
        ans.push_back(i);
        if(j - 1 >= 0) {
            ans.push_back(j - 1);
        }
    }
    ans.push_back(p);

    int size = ans.size();
    std::cout << size << '\n';
    for(int i = 0; i < size; i++) {
        std::cout << ans[i] + 1 << " \n"[i == size - 1];
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
