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

    std::vector<std::string> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<std::string> B(M);
    for(int i = 0; i < M; i++) {
        std::cin >> B[i]; 
    }
    
    std::map<std::string, int> m;
    std::vector<int> C(M + 1);
    for(int i = 0; i <= M; i++) {
        std::cin >> C[i];
    }

    for(int i = 0; i < M; i++) {
        m[B[i]] = C[i + 1];
    }

    int ans = 0;
    for(int i = 0; i < N; i++) {
        if(m.find(A[i]) == m.end()) {
            ans += C[0];
        } else {
            ans += m[A[i]];
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
