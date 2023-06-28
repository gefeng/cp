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
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<LL> sleep(N, 0LL);
    for(int i = 1; i < N; i++) {
        if(i % 2 == 0) {
            sleep[i] = sleep[i - 1] + A[i] - A[i - 1];
        } else {
            sleep[i] = sleep[i - 1];
        }
    } 

    int Q;
    std::cin >> Q;
    
    for(int i = 0; i < Q; i++) {
        int L, R;
        std::cin >> L >> R;
        
        auto it1 = std::lower_bound(A.begin(), A.end(), L);
        auto it2 = std::lower_bound(A.begin(), A.end(), R);

        LL res = sleep[it2 - A.begin()] - sleep[it1 - A.begin()];    
        
        if(*it1 > L && (it1 - A.begin()) % 2 == 0) {
            res += *it1 - L; 
        }

        if(*it2 > R && (it2 - A.begin()) % 2 == 0) {
            res -= *it2 - R;
        }

        std::cout << res << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
