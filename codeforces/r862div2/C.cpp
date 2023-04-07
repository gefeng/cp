#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using LL = long long;

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<LL> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<std::array<LL, 3>> B(M);
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < 3; j++) {
            std::cin >> B[i][j];
        }
    }

    std::sort(A.begin(), A.end());
   
    for(auto& p : B) {
        LL a = p[0];
        LL b = p[1];
        LL c = p[2];

        if(a * c < 0) {
            std::cout << "NO" << '\n';
            continue;
        }

        double k1 = (double)b - sqrt(4.0 * a * c);
        double k2 = (double)b + sqrt(4.0 * a * c);
        
        auto it = upper_bound(A.begin(), A.end(), k1);

        if(it != A.end() && *it < k2) {
            std::cout << "YES" << '\n' << *it << '\n';
        } else {
            std::cout << "NO" << '\n';
        }
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
