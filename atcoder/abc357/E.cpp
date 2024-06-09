#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        A[i] -= 1;
    }

    std::vector<int64_t> dp(N, 0);
    std::vector<int> vis(N, 0);
    for(int i = 0; i < N; i++) {
        if(vis[i]) {
            continue;
        }

        bool is_cycle = false;
        std::set<int> s;
        std::vector<int> path;
        int cur = i;
        while(true) {
            if(vis[cur]) {
                break;
            }
            if(s.find(cur) != s.end()) {
                is_cycle = true;
                break;
            }
            s.insert(cur);
            path.push_back(cur);
            cur = A[cur];
        }

        if(!is_cycle) {
            for(int i = path.size() - 1; i >= 0; i--) {
                int v = path[i];
                dp[v] += dp[A[v]] + 1;
            }
        } else {
            s = std::set<int>();
            int len = 0;
            while(s.find(cur) == s.end()) {
                len += 1;
                s.insert(cur);
                cur = A[cur]; 
            }
            
            s = std::set<int>();
            while(s.find(cur) == s.end()) {
                dp[cur] = len;
                s.insert(cur);
                cur = A[cur];
            }

            int first = -1;
            for(int i = path.size() - 1; i >= 0; i--) {
                int x = path[i];
                if(s.find(x) == s.end() && s.find(A[x]) != s.end()) {
                    first = i;
                    break;
                }
            }
            
            for(int i = first; i >= 0; i--) {
                int v = path[i];
                dp[v] += dp[A[v]] + 1;
            } 
        }

        for(int x : path) {
            vis[x] = 1;
        }
    }

    int64_t ans = 0; 
    for(int i = 0; i < N; i++) {
        ans += dp[i];
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
