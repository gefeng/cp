#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> diff(N, -1);
    for(int i = 0; i < N;) {
        int j = i; 
        while(i < N && A[i] == A[j]) {
            i += 1;
        }

        for(int k = j; k < i; k++) {
            diff[k] = j - 1;
        }
    } 

    int Q;
    std::cin >> Q;

    for(int i = 0; i < Q; i++) {
        int L, R;
        std::cin >> L >> R;
        L -= 1;
        R -= 1;

        if(diff[R] == -1 || diff[R] < L) {
            std::cout << -1 << ' ' << -1 << '\n';
        } else {
            std::cout << R + 1 << ' ' << diff[R] + 1 << '\n';
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
