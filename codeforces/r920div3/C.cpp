#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, F, A, B;
    std::cin >> N >> F >> A >> B;

    std::vector<int64_t> M(N);
    for(int i = 0; i < N; i++) {
        std::cin >> M[i];
    } 

    int64_t e = F;
    int64_t t = 0;
    for(int i = 0; i < N; i++) {
        int64_t d = M[i] - t;
        int64_t open = d * A;
        
        int64_t cost = std::min(open, (int64_t)B);
        if(e > cost) {
            e -= cost;
            t = M[i];
        } else {
            std::cout << "No" << '\n';
            return;
        }
    }

    std::cout << "Yes" << '\n';
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
