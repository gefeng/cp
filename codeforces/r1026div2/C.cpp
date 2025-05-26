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

    std::vector<std::pair<int, int>> B(N);
    for(int i = 0; i < N; i++) {
        std::cin >> B[i].first >> B[i].second;
    }

    auto overlap = [](int l, int r, int x, int y) {
        if(l > x) {
            std::swap(l, x);
            std::swap(r, y);
        }
        return x <= r;
    };

    std::vector<std::pair<int, int>> ranges(N);
    int l = 0;
    int r = 0;
    for(int i = 0; i < N; i++) {
        auto [x, y] = B[i];
        if(A[i] == 0) {
            if(!overlap(l, r, x, y)) {
                std::cout << -1 << '\n';
                return;
            }
            l = std::max(l, x);
            r = std::min(r, y);
        } else if(A[i] == 1) {
            l += 1;
            r += 1;
            if(!overlap(l, r, x, y)) {
                std::cout << -1 << '\n';
                return;
            }
            l = std::max(l, x);
            r = std::min(r, y);
        } else {
            r += 1;
            if(!overlap(l, r, x, y)) {
                std::cout << -1 << '\n';
                return;
            }
            l = std::max(l, x);
            r = std::min(r, y);
        }
        ranges[i] = {l, r};
    }

    int h = ranges.back().second;
    for(int i = N - 1; i >= 0; i--) {
        if(A[i] == 0) {
            continue;
        }
        if(A[i] == 1) {
            h -= 1;
            continue;
        }
        
        int pre = i == 0 ? 0 : ranges[i - 1].second;
        if(pre < h) {
            h -= 1;
            A[i] = 1;
        } else {
            A[i] = 0;
        }
    }

    for(int i = 0; i < N; i++) {
        std::cout << A[i] << " \n"[i == N - 1];
    }
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
