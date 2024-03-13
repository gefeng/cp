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

    std::vector<int64_t> A(N);
    std::vector<int64_t> B(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    std::vector<int64_t> eve_a;
    std::vector<int64_t> eve_b;
    std::vector<int64_t> odd_a;
    std::vector<int64_t> odd_b;

    int64_t sum_a = 0;
    int64_t sum_b = 0;
    for(int i = 0; i < N; i++) {
        sum_a += A[i];
        sum_b += B[i];
        if(i % 2 == 0) {
            eve_a.push_back(sum_a);
            eve_b.push_back(sum_b);
        } else {
            odd_a.push_back(sum_a);
            odd_b.push_back(sum_b);
        }
    }

    if(sum_a != sum_b) {
        std::cout << "No" << '\n';
        return;
    }

    std::sort(eve_a.begin(), eve_a.end());
    std::sort(eve_b.begin(), eve_b.end());
    std::sort(odd_a.begin(), odd_a.end());
    std::sort(odd_b.begin(), odd_b.end());

    int n = eve_a.size();
    int m = odd_a.size();
    for(int i = 0; i < n; i++) {
        if(eve_a[i] != eve_b[i]) {
            std::cout << "No" << '\n';
            return;
        }
    }

    for(int i = 0; i < m; i++) {
        if(odd_a[i] != odd_b[i]) {
            std::cout << "No" << '\n';
            return;
        }
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
