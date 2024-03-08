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

    std::vector<int64_t> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int64_t p2 = 2;
    for(int i = 0; i < 60; i++) {
        bool same = true;
        for(int64_t x : A) {
            if(x % p2 != A[0] % p2) {
                same = false;
                break;
            }
        } 

        if(!same) {
            std::cout << p2 << '\n';
            return;
        }

        p2 *= 2;
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
