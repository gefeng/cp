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
    
    int n = N;
    N *= 2;
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int cnt_odd = 0;
    for(int i = 0; i < N; i++) {
        if(A[i] % 2 == 1) {
            cnt_odd += 1;
        }
    }

    std::vector<int> removed(N, 0);
    if(cnt_odd % 2 == 1) {
        for(int i = 0; i < N; i++) {
            if(A[i] % 2 == 1) {
                removed[i] = 1;
                break;
            }
        }
        for(int i = 0; i < N; i++) {
            if(A[i] % 2 == 0) {
                removed[i] = 1;
                break;
            }
        }
    } else {
        if(cnt_odd) {
            int cnt = 0;
            for(int i = 0; i < N; i++) {
                if(A[i] % 2 == 1 && cnt < 2) {
                    removed[i] = 1;
                    cnt += 1;
                }
            }
        } else {
            removed[0] = 1;
            removed[1] = 1;
        }
    }

    std::vector<std::pair<int, int>> ans;
    while(ans.size() != n - 1) {
        int p = -1;
        int pre = -1;
        for(int i = 0; i < N; i++) {
            if(removed[i]) {
                continue;
            }
            if(p != -1 && A[i] % 2 == p) {
                ans.emplace_back(pre, i);
                removed[pre] = 1;
                removed[i] = 1;
                break;
            }
            if(p == -1) {
                p = A[i] % 2;
                pre = i;
            }
        }
    }

    assert(ans.size() == n - 1);
    for(int i = 0; i < n - 1; i++) {
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
