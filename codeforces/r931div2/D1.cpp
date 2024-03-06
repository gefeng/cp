#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int MAX = 60;

void run_case() {
    int64_t N, M;
    std::cin >> N >> M;

    int p = -1;
    for(int i = MAX; i >= 0; i--) {
        if(!(N & (1LL << i)) && (M & (1LL << i))) {
            p = i;
            break;
        }
    } 

    if(p == -1) {
        assert((N ^ M) < N);
        std::cout << 1 << '\n' << N << ' ' << M << '\n';
        return;
    }

    for(int i = MAX; i > p; i--) {
        if((N & (1LL << i)) && (M & (1LL << i))) {
            assert((N ^ M) < N);
            std::cout << 1 << '\n' << N << ' ' << M << '\n';
            return;
        }
    }

    int j = -1;
    for(int i = MAX; i > p; i--) {
        if((N & (1LL << i)) && !(M & (1LL << i))) {
            if(j == -1) {
                j = i;
            } else {
                std::cout << 2 << '\n';
                int64_t x = (1LL << j) | (1LL << p);
                assert((N ^ x) < N && (N ^ x ^ M) < (N ^ x));
                std::cout << N << ' ' << (N ^ x) << ' ' << M << '\n';
                return;
            }
        }
    }

    std::cout << -1 << '\n';
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
