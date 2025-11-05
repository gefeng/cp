#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    //1 3 2 _ 4 5 
    int N;
    std::cin >> N;

    std::string S;
    std::cin >> S;
    
    int pre = -1;
    std::vector<int> ans(N);
    
    if(S[0] == '0') {
        std::cout << -1 << '\n';
        return;
    }

    ans[0] = 1;
    for(int i = 1, j = 1; i < N ; i++) {
        if(S[i] == '0') {
            if(pre == -1) {
                pre = i;
                j += 1;
            }
            if(j >= N) {
                std::cout << -1 << '\n';
                return;
            }
            ans[j++] = i + 1;
        } else {
            if(pre == -1) {
                if(j >= N) {
                    std::cout << -1 << '\n';
                    return;
                }
                ans[j++] = i + 1;
            } else {
                ans[pre] = i + 1;
                pre = -1;
            }
        }
    }

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
