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
    int max_v = 0;
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        max_v = std::max(max_v, A[i]);
    }

    std::vector<int> freq(max_v + 1, 0);
    for(int x : A) {
        freq[x] += 1;
    }

    std::vector<int64_t> psum(max_v + 2, 0);
    for(int i = 1; i <= max_v + 1; i++) {
        psum[i] = psum[i - 1] + freq[i - 1];
    } 

    int64_t ans = 0;
    for(int i = 1; i <= max_v; i++) {
        if(freq[i]) {
            int64_t x = 0;
            for(int j = i; j <= max_v; j += i) {
                int l = j == i ? j + 1 : j;
                int r = std::min(max_v, j + i - 1);
                int64_t cnt = psum[r + 1] - psum[l];
                x += cnt * freq[i] * (j / i);
            } 
            ans += x + (int64_t)(freq[i] - 1) * freq[i] / 2;
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
