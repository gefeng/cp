#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    int hb = 0;
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        for(int j = 8; j >= 0; j--) {
            if(A[i] & (1 << j)) {
                hb = std::max(hb, j);
            }
        }
    }

    std::vector<int> cnt(hb + 1, 0);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j <= hb; j++) {
            if(A[i] & (1 << j)) {
                cnt[j] += 1;
            }
        }
    }

    std::set<int> extra;
    extra.insert(0);
    for(int i = N - 1, j = 0; i >= 0; i--) {
        j ^= A[i];
        extra.insert(j);
    }

    int ans = 0;
    for(int i = 0; i < N; i++) {
        int sum1 = 0;
        for(int j = 0; j <= hb; j++) {
            if(cnt[j] & 1) {
                sum1 |= (1 << j);
            }
        }

        ans = std::max(ans, sum1);

        for(int m : extra) {
            int sum2 = sum1 ^ m;
            ans = std::max(ans, sum2);
        }

        for(int j = 0; j <= hb; j++) {
            if(A[i] & (1 << j)) {
                cnt[j] -= 1;
            }
        }
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
