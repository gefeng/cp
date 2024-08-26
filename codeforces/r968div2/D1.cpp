#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> A(N);
    for(int i = 0; i < N; i++) {
        int L;
        std::cin >> L;
        A[i].resize(L, 0);
        for(int j = 0; j < L; j++) {
            std::cin >> A[i][j];
        }
    }

    std::vector<std::pair<int, int>> a(N);
    int max_mex = 0;
    for(int i = 0; i < N; i++) {
        std::sort(A[i].begin(), A[i].end());
        int mex1 = 0;
        int mex2 = 0;
        int size = A[i].size(); 
        
        for(int j = 0; j < size; ) {
            int k = j;
            while(j < size && A[i][j] == A[i][k]) {
                j += 1;
            }
            if(A[i][k] == mex1) {
                mex1 += 1;
            } else {
                break;
            }
        }

        for(int j = 0; j < size; ) {
            int k = j;
            while(j < size && A[i][j] == A[i][k]) {
                j += 1;
            }
            if(A[i][k] == mex2) {
                mex2 += 1; 
            } else {
                if(mex2 == mex1) {
                    mex2 += 1;
                }
                if(A[i][k] == mex2) {
                    mex2 += 1; 
                } else {
                    break;
                }
            }
        }

        if(mex1 == mex2) {
            mex2 += 1;
        }
        a[i] = {mex1, mex2};
        max_mex = std::max(max_mex, mex2);
    }

    // std::sort(a.begin(), a.end());
    // std::vector<std::pair<int, int>> b;
    // for(int i = 0; i < N; ) {
    //     int j = i;
    //     int max_v = 0;
    //     while(i < N && a[i].first == a[j].first) {
    //         max_v = std::max(max_v, a[i].second);
    //         i += 1;
    //     }
    //
    //     b.emplace_back(a[j].first, max_v);
    // }
    //
    // int n = b.size();
    // int64_t ans = 0;
    // int max_mex = 0;
    // for(int i = n - 1; i >= 0; i--) {
    //     max_mex = std::max(max_mex, b[i].second);
    //     // int pre = i == 0 ? -1 : b[i - 1].first;
    //     // int cnt = std::max(0, std::min(M, b[i].first) - pre);
    //     // ans += int64_t(cnt) * max_mex; 
    // }

    int64_t ans = 0;
    if(M <= max_mex) {
        ans = int64_t(max_mex) * (M + 1);
    } else {
        ans = int64_t(max_mex) * (max_mex + 1);
        ans += int64_t(max_mex + 1 + M) * (M - max_mex) / 2;
    }

    std::cout << ans << '\n';
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
