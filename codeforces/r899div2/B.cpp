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

    std::vector<std::vector<int>> A(N);
    for(int i = 0; i < N; i++) {
        int K;
        std::cin >> K;
        A[i].resize(K, 0);
        for(int j = 0; j < K; j++) {
            std::cin >> A[i][j];
        }
    }

    int ans = 0;
    for(int i = 1; i <= 50; i++) {
        std::set<int> have;
        for(int j = 0; j < N; j++) {
            int n = A[j].size();
            for(int k = 0; k < n; k++) {
                if(A[j][k] == i) {
                    have.insert(j);
                    break;
                }
            }
        }

        if(have.empty()) {
            continue;
        }
        
        std::set<int> s;
        for(int j = 0; j < N; j++) {
            if(have.find(j) == have.end()) {
                int n = A[j].size();
                for(int k = 0; k < n; k++) {
                    s.insert(A[j][k]);
                }
            }
        }

        ans = std::max(ans, (int)s.size());
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
