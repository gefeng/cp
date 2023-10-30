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

    std::sort(A.begin(), A.end());
    
    if(A[0] == A.back()) {
        std::cout << "Yes" << '\n';
        return;
    }

    int cnt = 0;
    for(int i = 0; i < N;) {
        int j = i;
        while(i < N && A[j] == A[i]) {
            i += 1;
        }
        cnt += 1;
    }

    if(cnt > 2) {
        std::cout << "No" << '\n';
        return;
    }

    cnt = 0;
    for(int i = 0; i < N; i++) {
        if(A[i] == A[0]) {
            cnt += 1;
        } else {
            break;
        }
    }

    if(N % 2 == 0) {
        std::cout << (cnt == N / 2 ? "Yes" : "No") << '\n';
    } else {
        std::cout << (std::abs(cnt - (N - cnt)) == 1 ? "Yes" : "No") << '\n';
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
