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

    int cnt_one = 0;
    for(int i = 0; i < N; i++) {
        cnt_one += A[i];
    }
    
    if(cnt_one == 0) {
        std::cout << (N % 4 == 0 ? "Yes" : "No") << '\n';
        return;
    }

    if(N % 4 != 2) {
        std::cout << "Yes" << '\n';
        return;
    } 

    if(cnt_one == 1) {
        std::cout << "No" << '\n';
        return;
    }

    std::vector<int> one;
    for(int i = 0; i < N; i++) {
        if(A[i] == 1) {
            one.push_back(i);
        }
    }

    int n = one.size();
    for(int i = 0; i < n; i++) {
        int d = std::abs(one[i] - one[(i - 1 + n) % n]);
        if(d % 2 == 1) {
            std::cout << "Yes" << '\n';
            return;
        } 
    }

    std::cout << "No" << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
