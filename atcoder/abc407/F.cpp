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

    std::vector<int> pre(N, -1);
    std::vector<int> nxt(N, N);
    std::vector<int> stk;

    for(int i = 0; i < N; i++) {
        while(!stk.empty() && A[stk.back()] <= A[i]) {
            stk.pop_back();
        }
        if(!stk.empty()) {
            pre[i] = stk.back();
        }
        stk.push_back(i);
    }

    stk.clear();
    for(int i = N - 1; i >= 0; i--) {
        while(!stk.empty() && A[stk.back()] < A[i]) {
            stk.pop_back();
        }
        if(!stk.empty()) {
            nxt[i] = stk.back();
        }
        stk.push_back(i);
    }

    std::vector<int64_t> diff_1(N + 10, 0);
    std::vector<int64_t> diff_2(N + 10, 0);
    std::vector<int64_t> ans(N + 1, 0);

    for(int i = 0; i < N; i++) {
        int l = i - pre[i];
        int r = nxt[i] - i;

        if(l > r) {
            std::swap(l, r);
        }
        
        diff_2[1] += A[i];
        diff_2[l + 1] -= A[i];
        diff_2[r + 1] -= A[i];
        diff_2[l + r + 1] += A[i];
    }

    int64_t sum = 0;
    for(int i = 1; i <= N; i++) {
        sum += diff_2[i];
        diff_1[i] = sum;
    } 

    sum = 0;
    for(int i = 1; i <= N; i++) {
        sum += diff_1[i];
        std::cout << sum << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
