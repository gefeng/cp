#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <numeric>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int64_t sum = std::accumulate(A.begin(), A.end(), int64_t(0));
    
    if(sum % N != 0) {
        std::cout << "No" << '\n';
        return;
    }

    int64_t sum_eve = 0;
    int64_t sum_odd = 0;
    int cnt_eve = 0;
    int cnt_odd = 0;
    for(int i = 0; i < N; i++) {
        if(i % 2 == 0) {
            sum_eve += A[i];
            cnt_eve += 1;
        } else {
            sum_odd += A[i];
            cnt_odd += 1;
        }
    }

    if(sum_eve % cnt_eve != 0 || sum_odd % cnt_odd != 0) {
        std::cout << "No" << '\n';
        return;
    }

    if(sum_eve / cnt_eve != sum / N || sum_odd / cnt_odd != sum / N) {
        std::cout << "No" << '\n';
        return;
    }

    std::cout << "Yes" << '\n';
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
