#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(N);
    std::vector<int> B(M);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < M; i++) {
        std::cin >> B[i];
    }
    
    int max_v = 0;
    int min_v = 0;
    if(N % 2 == 0) {
        for(int x : A) {
            max_v ^= x;
        } 

        std::array<int, 31> cnt = {};
        for(int x : A) {
            for(int i = 30; i >= 0; i--) {
                if(x & (1 << i)) {
                    cnt[i] += 1;
                }
            }
        }

        for(int i = 30; i >= 0; i--) {
            if(cnt[i] % 2 == 1) {
                bool can_set = false;
                for(int x : B) {
                    if(x & (1 << i)) {
                       can_set = true;
                       break;
                    }
                }

                if(!can_set) {
                    min_v |= 1 << i; 
                }
            }
        }
    } else {
        for(int x : A) {
            min_v ^= x;
        }

        std::array<int, 31> cnt = {};
        for(int x : A) {
            for(int i = 30; i >= 0; i--) {
                if(x & (1 << i)) {
                    cnt[i] += 1;
                }
            }
        }

        for(int i = 30; i >= 0; i--) {
            if(cnt[i] % 2 == 0) {
                bool can_set = false;
                for(int x : B) {
                    if(x & (1 << i)) {
                        can_set = true;
                        break;
                    }
                }

                if(can_set) {
                    max_v |= 1 << i;
                }
            } else {
                max_v |= 1 << i;
            }
        }
    }

    std::cout << min_v << ' ' << max_v << '\n';
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
