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

    std::vector<int> ans(N);
    std::vector<int> seen(N, 0);
    int mex = 0;
    int j = 0;
    for(int i = 0; i < N; i++) {
        int p = mex - A[i]; 
        if(p < 0 || seen[p]) {
            p = mex;
            seen[p] = 1;
            while(j < N && seen[j]) {
                j += 1;
            }
            mex = j;
        } else {
            seen[p] = 1;
            while(j < N && seen[j]) {
                j += 1;
            }
            mex = j;
        }
        ans[i] = p;
    }

    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << " \n"[i == N - 1];
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
