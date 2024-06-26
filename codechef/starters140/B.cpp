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
    int N, M;
    std::cin >> N >> M;
    
    std::vector<int> A(N);
    std::vector<int> B(N);
    
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    std::map<int, int> m;
    for(int i = 0; i < N; i++) {
        m[A[i] % M] += 1; 
    }

    int64_t ans = 0;
    for(int i = 0; i < N; i++) {
        int t = (M - (B[i] % M)) % M;
        if(m.find(t) != m.end()) {
            ans += m[t];
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
