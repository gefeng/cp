#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>
#include <numeric>

constexpr int INF = static_cast<int>(2e9);

void run_case() {
    int N;
    std::cin >> N;

    std::array<int, 3> A = {};
    std::array<int, 3> B = {};
    for(int i = 0; i < 3; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < 3; i++) {
        std::cin >> B[i];
    }


    auto get_result = [](int x, int y) {
        if(x == y) {
            return 0;
        }
        if(x == 0) {
            return y == 1 ? 1 : 2;
        }
        if(x == 1) {
            return y == 2 ? 1 : 2;
        }
        
        return y == 0 ? 1 : 2;
    };
    
    std::array<int, 3> p = {0, 1, 2};
    std::array<int, 3> pa = {0, 1, 2};

    int min_win = INF;
    int max_win = 0;

    do {
        int cnt_max = 0;
        std::array<int, 3> a(A);
        std::array<int, 3> b(B);
        for(int i = 0; i < 3; i++) {
            int x = p[pa[i]];
            int d = std::min(a[x], b[i]);
            a[x] -= d;
            b[i] -= d;
            int res = get_result(x, i);
            if(res == 1) {
                cnt_max += d;
            }
        }

        for(int i = 0; i < 3; i++) {
            int x = p[pa[i]];
            for(int j = 0; j < 3; j++) {
                int res = get_result(x, j);
                if(res == 1) {
                    cnt_max += std::min(a[x], b[j]);
                }
            }
        }

        max_win = std::max(max_win, cnt_max);
    } while(std::next_permutation(pa.begin(), pa.end()));

    std::ranges::sort(pa);
    do {
        int cnt_min = 0; 
        std::array<int, 3> a(A);
        std::array<int, 3> b(B);
        
        for(int i = 0; i < 3; i++) {
            int x = p[pa[i]];
            for(int j = 0; j < 3; j++) {
                int res = get_result(x, j);
                if(res == 0 || res == 2) {
                    int d = std::min(a[x], b[j]); 
                    a[x] -= d;
                    b[j] -= d;
                }
            }
        }

        cnt_min = std::accumulate(a.begin(), a.end(), 0); 
        min_win = std::min(min_win, cnt_min);
        
    } while(std::next_permutation(pa.begin(), pa.end()));
    
    std::cout << min_win << ' ' << max_win << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
