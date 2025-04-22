#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int cnt = 0;
    int bal = 0;
    for(int i = 0; i < N; i++) {
        bal += A[i] <= K ? -1 : 1;
        if(bal < 0) {
            cnt += 1;
        }
    }

    if(cnt > 1) {
        std::cout << "Yes" << '\n';
        return;
    }

    bal = 0;
    cnt = 0;
    for(int i = N - 1; i >= 0; i--) {
        bal += A[i] <= K ? -1 : 1;
        if(bal < 0) {
            cnt += 1;
        }
    }

    if(cnt > 1) {
        std::cout << "Yes" << '\n';
        return;
    }

    bal = 0;
    cnt = 0;
    for(int i = 0; i < N; i++) {
        bal += A[i] <= K ? -1 : 1;
        if(bal == 0) {
            cnt += 1;
        }
    }

    if(cnt > 1) {
        std::cout << "Yes" << '\n';
        return;
    }

    bal = 0;
    cnt = 0;
    for(int i = N - 1; i >= 0; i--) {
        bal += A[i] <= K ? -1 : 1;
        if(bal == 0) {
            cnt += 1;
        }
    }

    if(cnt > 1) {
        std::cout << "Yes" << '\n';
        return;
    }
    
    int p_1 = -1;
    int p_2 = -1;
    bal = 0;
    for(int i = 0; i < N; i++) {
        bal += A[i] <= K ? -1 : 1;
        if(bal <= 0) {
            p_1 = i;
            break;
        }
    }

    bal = 0;
    for(int i = N - 1; i >= 0; i--) {
        bal += A[i] <= K ? -1 : 1;
        if(bal <= 0) {
            p_2 = i;
            break;
        }
    }

    if(p_1 != -1 && p_2 != -1 && p_2 - p_1 > 1) {
        std::cout << "Yes" << '\n';
        return;
    }

    std::cout << "No" << '\n';
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
