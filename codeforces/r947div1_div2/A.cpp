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

    int cnt = 0;
    for(int i = 1; i < N; i++) {
        if(A[i] < A[i - 1]) {
            cnt += 1;
        }
    }

    if(cnt == 0) {
        std::cout << "Yes" << '\n';
        return;
    }

    if(cnt > 1) {
        std::cout << "No" << '\n';
        return;
    } 

    std::cout << (A.back() <= A[0] ? "Yes" : "No") << '\n';
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
