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
    int N, K;
    std::cin >> N >> K;
    
    std::vector<std::string> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    if(N < 3) {
        std::cout << 0 << '\n';
        return;
    }

    std::map<std::string, std::vector<int>> m;
    for(int i = 0; i < N; i++) {
        m[A[i]].push_back(i);
    }
    
    int64_t ans = 0;
    int sum = 'S' + 'E' + 'T';
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            std::string t(K, '?');
            for(int k = 0; k < K; k++) {
                if(A[i][k] == A[j][k]) {
                    t[k] = A[i][k];
                } else {
                    t[k] = (char)(sum - A[i][k] - A[j][k]);
                }
            } 
            if(m.find(t) != m.end()) {
                ans += m[t].end() - std::upper_bound(m[t].begin(), m[t].end(), j);
            }
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    run_case();
}
