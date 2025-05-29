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
    std::vector<int> B(N);

    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    
    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }
    
    int cnt_0 = 0;
    int cnt_1 = 0;
    for(int i = 0; i < N; i++) {
        if(A[i] < B[i]) {
            if(!cnt_1) {
                std::cout << "NO" << '\n';
                return;
            }
        } else if(A[i] > B[i]) {
            if(!cnt_0) {
                std::cout << "NO" << '\n';
                return;
            }
        }

        if(A[i] == 1) {
            cnt_1 += 1;
        } else if(A[i] == -1) {
            cnt_0 += 1;
        }
    }

    std::cout << "YES" << '\n';
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
