#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> nxt_smaller(N, N);
    std::vector<int> s;
    for(int i = N - 1; i >= 0; i--) {
        while(!s.empty() && A[s.back()] > A[i]) {
            s.pop_back();
        }
        if(!s.empty()) {
            nxt_smaller[i] = s.back();
        }
        s.push_back(i);
    }

    std::vector<int> nxt_min(N, N);
    int p = N - 1;
    for(int i = N - 1; i >= 0; i--) {
        nxt_min[i] = p;
        if(A[i] < A[p]) {
            p = i;
        }
    }
    
    int cur = 0;
    int64_t ans = 0;
    while(cur != N - 1) {
        int nxt = nxt_smaller[cur];
        if(nxt == N) {
            nxt = nxt_min[cur];
            ans += (int64_t)(N - 1 - cur) * A[nxt];
        } else {
            ans += (int64_t)(nxt - cur) * A[cur];
        }
        cur = nxt;
    }

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
