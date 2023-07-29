#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = 1e9;

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int64_t> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    bool inc = true;
    bool has_pos = A[0] > 0;
    for(int i = 1; i < N; i++) {
        if(A[i] < A[i - 1]) {
            inc = false;
        }
        if(A[i] > 0) {
            has_pos = true;
        }
    }

    if(inc) {
        std::cout << 0 << '\n';
        return;
    }

    std::vector<std::pair<int, int>> ans;

    if(has_pos) {
        int p = -1;
        for(int i = 0; i < N; i++) {
            if(A[i] > 0) {
                p = i;
                break;
            }
        }

        for(int i = 0; i < 6; i++) {
            A[p] += A[p];
            ans.emplace_back(p, p);
        }

        for(int i = 0; i < N; i++) {
            if(A[i] < 0) {
                A[i] += A[p]; 
                ans.emplace_back(i, p);
            } 

            if(i) {
                A[i] += A[i - 1];
                ans.emplace_back(i, i - 1);
            }
        }
    } else {
        for(int i = N - 2; i >= 0; i--) {
            A[i] = A[i] + A[i + 1];
            ans.emplace_back(i, i + 1);
        } 
    }


    int sz = ans.size();
    std::cout << sz << '\n';

    for(int i = 0; i < sz; i++) {
        std::cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << '\n';
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
