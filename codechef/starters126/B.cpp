#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int64_t ans = 0;
    std::map<int64_t, int> m;
    for(int i = 0; i < N; i++) {
        if(A[i] > 1) {
            if(((int64_t)A[i] * 3) % (A[i] - 1) == 0) {
                int64_t x = (int64_t)A[i] * 3 / (A[i] - 1);
                if(m.find(x) != m.end()) {
                    ans += m[x];
                }
            }
        }

        m[A[i]] += 1;
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
