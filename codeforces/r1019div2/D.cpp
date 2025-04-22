#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void dfs(int N, std::vector<int>& A, int t, int l, int r, std::vector<int>& ans) {
    if(l == r) {
        for(int i = 0; i < N; i++) {
            if(ans[i] == -1) {
                ans[i] = l;
                return;
            }
        }
    }

    int cnt = 0;
    int seen = 0;
    int first = -1;
    for(int i = 0; i < N; i++) {
        if(A[i] == t) {
            cnt += 1;
            seen = 1;
        } else {
            if((A[i] == -1 || A[i] > t) && seen) {
                first = first == -1 ? i : first;
            }
        }
    }
    if(t % 2 == 1) {
        int p = r - cnt + 1;
        for(int i = 0, j = r, k = p; i < N; i++) {
            if(A[i] == t) {
                if(i < first) {
                    ans[i] = j--;
                } else {
                    ans[i] = k++;
                }
            }
        }
        
        dfs(N, A, t + 1, l, p - 1, ans);
    } else {
        int p = cnt + l - 1;
        for(int i = 0, j = l, k = p; i < N; i++) {
            if(A[i] == t) {
                if(i < first) {
                    ans[i] = j++;
                } else {
                    ans[i] = k--;
                }
            }
        }

        dfs(N, A, t + 1, p + 1, r, ans);
    }
}

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> ans(N, -1);
    dfs(N, A, 1, 1, N, ans);

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
