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
    int64_t M;
    std::cin >> N >> M;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int64_t sum = 0;
    for(int x : A) {
        sum += x;
    }

    if(sum <= M) {
        std::cout << "infinite" << '\n';
        return;
    }

    int lo = 0;
    int hi = int(1e9);
    int ans = 0;
    while(lo <= hi) {
        int mid = (lo + hi) >> 1;
        
        sum = 0;
        for(int x : A) {
            sum += std::min(mid, x);
        }
        
        if(sum <= M) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
