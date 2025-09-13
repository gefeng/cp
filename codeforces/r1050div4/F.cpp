#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <numeric>

constexpr int INF = static_cast<int>(2e9);

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<std::vector<int>> A(N);
    int max_c = 0;
    for(int i = 0; i < N; i++) {
        int K;
        std::cin >> K;
        max_c = std::max(max_c, K);
        A[i].resize(K, 0);
        for(int j = 0; j < K; j++) {
            std::cin >> A[i][j];
        }
    }

    std::vector<int> ans;
    std::vector<int> rows(N, 0);
    std::iota(rows.begin(), rows.end(), 0);

    int c = 0;
    while(c < max_c && !rows.empty()) {
        std::vector<int> now(rows); 
        std::vector<int> prefix;
        int p = -1;
        int cc = c;
        while(true) {
            int min_v = INF;
            int cnt = 0;
            int which = -1;
            std::vector<int> prefix;
            for(int r : now) {
                if(A[r].size() - 1 < cc) {
                    which = r;
                    break;
                }
                if(A[r][cc] < min_v) {
                    min_v = A[r][cc];
                    cnt = 1;
                    which = r;
                } else if(A[r][cc] == min_v) {
                    cnt += 1; 
                }
            }

            if(min_v != INF) {
                prefix.push_back(min_v);
                if(cnt == 1) {
                    p = which;
                    break;
                }
                
                std::vector<int> nxt;
                for(int r : now) {
                    if(A[r].size() - 1 >= cc && A[r][cc] == min_v) {
                        nxt.push_back(r);
                    }
                }
                now = std::move(nxt);
                cc += 1;
            } else {
                p = which;
                break;
            }
        }

        for(int i = c; i < A[p].size(); i++) {
            ans.push_back(A[p][i]);
        }
        c = A[p].size();

        std::vector<int> nrows;
        for(int r : rows) {
            if(r != p && A[r].size() > A[p].size()) {
                nrows.push_back(r);
            }
        }
        rows = std::move(nrows);
    }

    int n = ans.size();
    assert(n == max_c);
    for(int i = 0; i < n; i++) {
        std::cout << ans[i] << " \n"[i == n - 1];
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
