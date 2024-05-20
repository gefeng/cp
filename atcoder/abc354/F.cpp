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

    std::vector<int> ans;
    std::vector<int> lis;
    std::vector<int> len(N, 0);
    for(int i = 0; i < N; i++) {
        if(lis.empty() || A[i] > lis.back()) {
            lis.push_back(A[i]);
            len[i] = lis.size();
        } else {
            auto it = std::lower_bound(lis.begin(), lis.end(), A[i]);
            *it = A[i];
            len[i] = it - lis.begin() + 1;
        }
    }

    int max_len = lis.size();
    lis.clear();
    for(int i = N - 1; i >= 0; i--) {
        if(lis.empty() || A[i] < lis.back()) {
            lis.push_back(A[i]);
            if(lis.size() + len[i] - 1 ==  max_len) {
                ans.push_back(i);
            } 
        } else {
            auto it = std::lower_bound(lis.begin(), lis.end(), A[i], std::greater<int>());
            *it = A[i];
            if(it - lis.begin() + len[i] == max_len) {
                ans.push_back(i);
            }
        }
    }

    std::reverse(ans.begin(), ans.end());
    int m = ans.size();
    std::cout << m << '\n';
    for(int i = 0; i < m; i++) {
        std::cout << ans[i] + 1 << " \n"[i == m - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
