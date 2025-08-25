#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void dfs(std::vector<std::vector<int>>& G, int v, std::vector<int>& size) {
    size[v] += 1;
    for(int nei : G[v]) {
        dfs(G, nei, size); 
        size[v] += size[nei];
    } 
}

void run_case() {
    int N, Q;
    std::cin >> N >> Q;

    std::vector<std::vector<int>> G(N);
    for(int i = 1; i < N; i++) {
        int P;
        std::cin >> P;
        P -= 1;
        G[P].push_back(i);
    } 


    std::vector<int> A(N); 
    std::vector<int> size(N, 0);
    std::vector<int> pos(N, 0);
    std::vector<int> dp(N, 0); 
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        A[i] -= 1;
        pos[A[i]] = i;
    }

    dfs(G, 0, size);
    
    auto check_downwards = [&](int v) {
        int c1 = v * 2 + 1;
        int c2 = v * 2 + 2;
        int l = pos[v];
        int r = pos[v] + size[v] - 1;
        if(r >= N) {
            return false;
        }
        if(c1 < N) {
            if(pos[c1] < l || pos[c1] > r || dp[c1] == 0) {
                return false;
            }
        }
        if(c2 < N) {
            if(pos[c2] < l || pos[c2] > r || dp[c2] == 0) {
                return false;
            }
        }
        return true;
    };

    auto update_upwards = [&](int v) {
        int d = 0;
        while(v > 0) {
            int nv = (v - 1) >> 1; 
            if(check_downwards(nv)) {
                if(dp[nv] == 0) {
                    dp[nv] = 1;
                    d += 1;
                }
            } else {
                if(dp[nv] == 1) {
                    dp[nv] = 0;
                    d -= 1;
                }
            }
            v = nv;
        } 
        return d;
    };

    int cnt = 0;
    for(int i = N - 1; i >= 0; i--) {
        if(check_downwards(i)) {
            dp[i] = 1; 
        } else {
            cnt += 1;
        }
    }

    for(int i = 0; i < Q; i++) {
        int L, R;
        std::cin >> L >> R;
        L -= 1;
        R -= 1;

        int v1 = A[L];
        int v2 = A[R];
        
        if(dp[v1] == 1) {
            dp[v1] = 0;
            cnt += 1;
        }
        
        if(dp[v2] == 1) {
            dp[v2] = 0;
            cnt += 1;
        }

        pos[v1] = R;
        pos[v2] = L;
        std::swap(A[L], A[R]);

        if(check_downwards(v1)) {
            dp[v1] = 1;
            cnt -= 1;
        } else {
            dp[v1] = 0;
        }

        if(check_downwards(v2)) {
            dp[v2] = 1;
            cnt -= 1;
        } else {
            dp[v2] = 0;
        }

        int a = update_upwards(v1);
        int b = update_upwards(v2);

        cnt -= a + b;
        std::cout << (cnt == 0 ? "Yes" : "No") << '\n';
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
