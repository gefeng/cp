#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

constexpr int INF = (int)1e9;

void run_case() {
    int N;
    std::cin >> N;

    std::string S;
    std::cin >> S;
    
    std::vector<int> A(N);
    std::vector<int> s(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        A[i] -= 1;

        s[i] = S[i] - '0';
    }

    std::vector<int> indegree(N, 0);
    for(int i = 0; i < N; i++) {
        indegree[A[i]] += 1;
    }

    std::queue<int> q;
    std::vector<int> vis(N, 0);
    for(int i = 0; i < N; i++) {
        if(indegree[i] == 0) {
            q.emplace(i);
        }
    }
    
    int ans = 0;
    std::vector<int> op;
    while(!q.empty()) {
        int v = q.front();
        q.pop();

        vis[v] = 1;

        if(s[v] == 1) {
            ans += 1;
            op.push_back(v);
            s[v] = 0;
            s[A[v]] ^= 1;
        }

        if(--indegree[A[v]] == 0) {
            q.emplace(A[v]);
        }
    }

    for(int i = 0; i < N; i++) {
        if(vis[i]) {
            continue;
        }

        std::vector<int> cycle;
        std::vector<int> state;
        int v = i;
        int st = -1;
        while(!vis[v]) {
            cycle.push_back(v);
            state.push_back(s[v]);
            vis[v] = 1;
            if(s[v] == 1) {
                st = st == -1 ? state.size() - 1 : st;
            }
            v = A[v];
        }

        if(st == -1) {
            continue;
        }

        int min_v = INF;
        int cnt1 = 0;
        int cnt2 = 0;
        int n = state.size();
        std::vector<int> c_state(state);
        std::vector<int> a;
        std::vector<int> b;
        for(int i = 0; i < n; i++) {
            if(c_state[(st + i) % n] == 1) {
                c_state[(st + i) % n] = 0;
                c_state[(st + i + 1) % n] ^= 1;
                cnt1 += 1;
                a.push_back(cycle[(st + i) % n]);
            }
        }

        if(c_state[st] == 0) {
            min_v = cnt1;  
        }

        c_state = std::vector<int>(state);
        for(int i = 1; i < n; i++) {
            if(c_state[(st + i) % n] == 1) {
                c_state[(st + i) % n] = 0;
                c_state[(st + i + 1) % n] ^= 1;
                cnt2 += 1;
                b.push_back(cycle[(st + i) % n]);
            }
        }

        if(c_state[st] == 0) {
            min_v = std::min(min_v, cnt2);
        }

        if(min_v == INF) {
            std::cout << -1 << '\n';
            return;
        }
        
        ans += min_v;
        if(min_v == cnt1) {
            for(int x : a) {
                op.push_back(x);
            }    
        } else {
            for(int x : b) {
                op.push_back(x);
            }
        }
    } 

    std::cout << ans << '\n'; 
    for(int i = 0; i < ans; i++) {
        std::cout << op[i] + 1 << " \n"[i == ans - 1];
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
