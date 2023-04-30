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

    std::vector<int> ans;
    std::vector<bool> used(N + 1, false);

    int rem = 0;
    for(int l = 0, r = N - 1; l <= r; l += 1, r -= 1) {
        if(rem < l) {
            int x = l - rem; 
            if(used[x]) {
                std::cout << -1 << '\n';
                return;
            }
            used[x] = true;
            ans.push_back(x);
            rem = l;
        } else {
            int x = N + l - rem;
            if(used[x]) {
                std::cout << -1 << '\n';
                return;
            }
            used[x] = true;
            ans.push_back(x);
            rem = l;
        } 

        if(l != r) {
            if(rem < r) {
                int x = r - rem; 
                if(used[x]) {
                    std::cout << -1 << '\n';
                    return;
                }
                used[x] = true;
                ans.push_back(x);
                rem = r;
            } else {
                int x = N + r - rem;
                if(used[x]) {
                    std::cout << -1 << '\n';
                    return;
                }
                used[x] = true;
                ans.push_back(x);
                rem = r;
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
