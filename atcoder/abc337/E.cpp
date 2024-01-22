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

    int m = 0;
    int p2 = 1;
    while(p2 < N) {
        m += 1;
        p2 *= 2;
    }

    std::vector<std::vector<int>> have(m);
    for(int i = 1; i <= N; i++) {
        for(int j = 0; j < m; j++) {
            if(i & (1 << j)) {
                have[j].push_back(i);
            }
        } 
    }

    std::cout << m << std::endl;
    for(int i = 0; i < m; i++) {
        int k = have[i].size();
        std::cout << k << ' ';
        for(int j = 0; j < k; j++) {
            std::cout << have[i][j];
            if(j < k - 1) {
                std::cout << ' ';
            }
        }
        std::cout << std::endl;
    }

    std::string S;
    std::cin >> S;

    int ans = 0;
    for(int i = 0; i < m; i++) {
        if(S[i] == '1') {
            ans |= (1 << i); 
        }
    }

    std::cout << (ans == 0 ? N : ans) << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
