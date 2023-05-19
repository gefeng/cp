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

    int cnt_eve = 0;
    for(int i = 0; i < N; i++) { 
        if(A[i] % 2 == 0) {
            cnt_eve += 1;
        }
    }

    if(cnt_eve == N || cnt_eve == 0) {
        std::cout << "YES" << '\n';
        return;
    }

    int cnt_odd = 0;
    for(int i = 0; i < N; i++) {
        if(A[i] % 2 == 0) {
            if(cnt_odd == 0) {
                std::cout << "NO" << '\n';
                return;
            } 
        } else {
            cnt_odd += 1;
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
