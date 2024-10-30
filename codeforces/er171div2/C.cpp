#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

constexpr int64_t INF = int64_t(2e18);

void run_case() {
    int N;
    std::cin >> N;

    std::string S;
    std::cin >> S;

    int64_t ans = 0;
    std::vector<int> free(N, 0);
    std::vector<int> s0;
    std::set<int> s1;
    S[0] = '0';
    for(int i = 0; i < N; i++) {
        if(S[i] == '0') {
            s0.push_back(i);
        } else {
            s1.insert(i);
        }
    }
    for(int i = N - 1; i >= 0; i--) {
        if(S[i] == '1') {
            if(s1.find(i) == s1.end()) {
                continue;
            }
            s1.erase(i);
            while(!s0.empty() && s0.back() > i) {
                s0.pop_back();         
            }
            if(!s0.empty()) {
                free[i] = 1;
                s0.pop_back();
            } else {
                if(!s1.empty()) {
                    s1.erase(s1.begin()); 
                    free[i] = 1;
                }
            }
        }
    }

    for(int i = 0; i < N; i++) {
        if(!free[i]) {
            ans += i + 1;
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
