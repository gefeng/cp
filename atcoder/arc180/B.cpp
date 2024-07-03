#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, K;
    std::cin >> N >> K;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        A[i] -= 1;
    }

    std::vector<std::pair<int, int>> ans;
    std::vector<int> solved(N, 0);
    while(true) {
        bool end = true;
        for(int i = K; i < N; i++) {
            if(!solved[i]) {
                end = false;
            }
        }

        if(end) {
            break;
        }

        int max_v = -1;
        int max_p = -1;
        for(int i = K; i < N; i++) {
            if(solved[i]) {
                continue;
            }
            
            if(A[i] > max_v) {
                max_v = A[i];
                max_p = i;
            } 
        }

        while(true) {
            int min_v = N;
            int min_p = -1;
            for(int i = 0; i <= max_p - K; i++) {
                if(A[i] < min_v && A[i] > max_v) {
                    min_v = A[i];
                    min_p = i;
                } 
            }

            if(min_p != -1) {
                std::swap(A[min_p], A[max_p]);
                max_v = min_v;
                ans.emplace_back(min_p, max_p);
            } else {
                break;
            }
        }

        solved[max_p] = 1;
    }

    int n = ans.size();
    std::cout << n << '\n';
    for(int i = 0; i < n; i++) {
        std::cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
