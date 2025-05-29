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

    std::string S;
    std::cin >> S;

    std::vector<std::vector<int>> seq;

    while(true) {
        std::vector<int> now;
        for(int i = 0; i < N - 1; i++) {
            if(S[i] == 'R' && S[i + 1] == 'L') {
                now.push_back(i);
            }
        } 

        if(now.empty()) {
            break;
        }

        for(int p : now) {
            S[p] = 'L';
            S[p + 1] = 'R';
        }

        seq.push_back(now);
    }

    int size = seq.size();
    if(K < size) {
        std::cout << -1 << '\n';
        return;
    }

    std::vector<std::vector<int>> ans;
    int extra = K - size;
    for(int i = 0; i < size; i++) {
        int m = seq[i].size();
        if(m == 1) {
            ans.emplace_back();
            ans.back().push_back(seq[i][0]);
            continue;
        }
        
        int j = 0;
        while(extra && j < m - 1) {
            ans.emplace_back();
            ans.back().push_back(seq[i][j++]);
            extra -= 1;
        }

        ans.emplace_back();
        while(j < m) {
            ans.back().push_back(seq[i][j++]);
        }
    }

    if(extra) {
        std::cout << -1 << '\n';
        return;
    }

    assert(ans.size() == K);

    for(int i = 0; i < K; i++) {
        int m = ans[i].size();
        std::cout << m << ' ';
        for(int j = 0; j < m; j++) {
            std::cout << ans[i][j] + 1 << " \n"[j == m - 1];
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
