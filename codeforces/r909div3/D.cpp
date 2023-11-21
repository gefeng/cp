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

    std::sort(A.begin(), A.end());

    int64_t ans = 0;
    std::map<int, int> m;
    for(int i = 0; i < N; i++) {
        int x = A[i];

        if(m.find(x) != m.end()) {
            ans += m[x];
        }

        int cnt = 0;
        while(x % 2 == 0) {
            x /= 2;
            cnt += 1;

            int t = A[i] - cnt;
            if(x % t == 0 && m.find(t) != m.end()) {
                ans += m[t]; 
                //std::cout << A[i] << ' ' << t << '\n';
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
