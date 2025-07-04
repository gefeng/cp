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

    std::string S;
    std::cin >> S;

    std::vector<std::vector<int>> seq(2);
    std::vector<int> ans(N, -1);
    int k = 0;
    for(int i = 0; i < N; i++) {
        int c = S[i] - '0';
        if(seq[c ^ 1].empty()) {
            seq[c].push_back(k);
            ans[i] = k;
            k += 1;
        } else {
            ans[i] = seq[c ^ 1].back();
            seq[c ^ 1].pop_back();
            seq[c].push_back(ans[i]);
        }
    } 

    std::cout << k << '\n';
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
