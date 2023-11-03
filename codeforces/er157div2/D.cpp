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

    std::vector<int> A(N - 1);
    for(int i = 0; i < N - 1; i++) {
        std::cin >> A[i];
    }

    std::vector<int> save(N, 0);
    int sum = 0;
    for(int i = 1; i < N; i++) {
        sum ^= A[i - 1];    
        save[i] = sum;
    }

    std::vector<int> bit_cnt(30, 0);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 30; j++) {
            bit_cnt[j] += (i & (1 << j)) ? 1 : 0;
        }
    }
    
    int b0 = 0;
    for(int i = 0; i < 30; i++) {
        int cnt = 0;
        for(int j = 1; j < N; j++) {
            int b = (save[j] & (1 << i)) ? 1 : 0;
            if(b) {
                cnt += 1;
            }
        }
        if(cnt != bit_cnt[i]) {
            b0 |= 1 << i; 
        }
    }

    std::cout << b0 << ' ';
    int pre = b0;
    for(int i = 1; i < N; i++) {
        int cur = pre ^ A[i - 1];
        std::cout << cur << " \n"[i == N - 1];
        pre = cur;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
