#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <numeric>

std::vector<int> dfs(int N, std::vector<std::string>& A, std::vector<int> all) {
    std::string& s = A[all[0]];

    std::vector<int> lhs;
    std::vector<int> rhs;
    for(int x : all) {
        if(x == all[0]) {
            continue; 
        }
        if(s[x] == '0') {
            lhs.push_back(x);
        } else {
            rhs.push_back(x);
        }
    }
    
    std::vector<int> merge;

    if(!lhs.empty()) {
        std::vector<int> res = dfs(N, A, lhs);
        for(int x : res) {
            merge.push_back(x);
        }
    }
    
    merge.push_back(all[0]);

    if(!rhs.empty()) {
        std::vector<int> res = dfs(N, A, rhs);
        for(int x : res) {
            merge.push_back(x);
        }
    }

    return merge;
}

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::string> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> ans;
    std::vector<int> all(N, 0);
    std::iota(all.begin(), all.end(), 0);

    ans = dfs(N, A, all);
    
    for(int i = 0; i < N; i++) {
        std::cout << ans[i] + 1 << " \n"[i == N - 1];
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
