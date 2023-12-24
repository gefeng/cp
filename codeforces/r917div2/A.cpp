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

    int cnt_neg = 0;
    int cnt_zero = 0;
    for(int i = 0; i < N; i++) {
        if(A[i] < 0) {
            cnt_neg += 1;
        } 
        if(A[i] == 0) {
            cnt_zero += 1;
        }
    }

    if(cnt_neg % 2 == 1 || cnt_zero) {
        std::cout << 0 << '\n';
        return;
    }

    std::cout << 1 << '\n' << 1 << ' ' << 0 << '\n';
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
