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
    int64_t sum = 0;
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        sum += A[i];
    }

    std::sort(A.begin(), A.end());

    auto solve = [&](int64_t t1, int64_t t2) {
        //int64_t bal = 0;
        int64_t l = 0;
        int64_t r = 0;
        for(int i = 0; i < N; i++) {
            if(A[i] <= t1) {
                //bal += t1 - A[i];
                l += t1 - A[i];
            }
        } 

        for(int i = N - 1; i >= 0; i--) {
            if(A[i] > t2) {
                r += A[i] - t2;
            } 
        }

        return std::max(l, r);
    };

    std::cout << solve(sum / N, (sum + N - 1) / N) << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
