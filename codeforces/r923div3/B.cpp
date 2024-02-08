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

    std::vector<std::vector<int>> pos(26);
    for(int i = 0; i < N; i++) {
        if(A[i] == 0) {
            for(int j = 0; j < 26; j++) {
                if(pos[j].empty()) {
                    pos[j].push_back(i);
                    break;
                }
            }
        } else {
            for(int j = 0; j < 26; j++) {
                if(!pos[j].empty() && A[pos[j].back()] == A[i] - 1) {
                    pos[j].push_back(i);
                    break;
                }
            }
        }
    }

    std::string ans(N, '#');
    for(int i = 0; i < 26; i++) {
        for(int j : pos[i]) {
            ans[j] = (char)(i + 'a');
        }
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
