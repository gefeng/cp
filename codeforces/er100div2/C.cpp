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

    std::vector<std::pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first >> A[i].second;
    }

    int64_t t = 0;
    int64_t p = 0;
    int ans = 0;
    for(int i = 0; i < N; ) {
        t = A[i].first;
        int64_t nt = t + std::abs(A[i].second - p);
        if(t == nt) {
            i += 1;            
            ans += 1;
            continue;
        }

        int j = i;
        while(i < N && A[i].first < nt) {
            i += 1;
        }
    
        int d = A[j].second >= p ? 1 : -1;
        for(int k = j; k < i; k++) {
            if(k == j) {
                ans += i - j == 1 ? 1 : 0;
                p = k + 1 < i ? p + (A[k + 1].first - A[k].first) * d : A[j].second;
            } else {
                int64_t np = k + 1 < i ? p + d * (A[k + 1].first - A[k].first) : A[j].second;
                if((A[k].second >= p && A[k].second <= np) || (A[k].second >= np && A[k].second <= p)) {
                    ans += 1;
                }
                p = np;
            }
        }
        t = nt;
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
