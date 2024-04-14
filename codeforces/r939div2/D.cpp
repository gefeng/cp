#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void dfs(int len, int l, std::vector<std::pair<int, int>>& ans) {
    if(len <= 0) {
        return;
    }
    if(len == 1) {
        return;
    }

    dfs(len - 1, l, ans);
    ans.emplace_back(l, l + len - 1);
    ans.emplace_back(l, l + len - 2);
    dfs(len - 1, l, ans);
}

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int64_t max_sum = 0;
    int mask = 0;
    for(int i = 0; i < (1 << N); i++) {
        int64_t sum = 0;
        for(int j = 0; j < N; ) {
            if(i & (1 << j)) {
                int k = j;
                while(j < N && (i & (1 << j))) {
                    j += 1;
                }

                int len = j - k;
                sum += (int64_t)len * len; 
            } else {
                sum += A[j];
                j += 1;
            }
        }

        if(sum > max_sum) {
            max_sum = sum;
            mask = i;
        }
    }

    std::vector<std::pair<int, int>> ans;
    for(int i = 0; i < N; ) {
        if(mask & (1 << i)) {
            int j = i;
            int zero = 0;
            while(i < N && (mask & (1 << i))) {
                if(A[i] == 0) {
                    zero = 1;
                }
                i += 1;
            }

            int len = i - j;
            int l = j;
            int r = i - 1;
            
            ans.emplace_back(l, r);
            if(zero) {
                ans.emplace_back(l, r);
            }
            dfs(len, l, ans);
            ans.emplace_back(l, r);
        } else {
            i += 1;
        }
    }

    int size = ans.size();
    std::cout << max_sum << ' ' << size << '\n';
    for(int i = 0; i < size; i++) {
        std::cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << '\n'; 
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
