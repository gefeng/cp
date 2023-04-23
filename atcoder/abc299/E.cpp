#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> G(N);
    for(int i = 0; i < M; i++) {
        int U, V;
        std::cin >> U >> V;

        U -= 1;
        V -= 1;
        G[U].push_back(V);
        G[V].push_back(U);
    }

    int K;
    std::cin >> K;

    std::vector<std::pair<int, int>> A(K);
    for(int i = 0; i < K; i++) {
        std::cin >> A[i].first >> A[i].second;
        A[i].first -= 1;
    }

    std::vector<int> color(N, -1);
    for(auto& p : A) {
        int v = p.first;
        int d = p.second;

        std::queue<int> q;
        std::vector<bool> vis(N, false);
        
        q.push(v);
        vis[v] = true;

        int cur_d = 0;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                int cur = q.front();
                q.pop();

                if(cur_d < d) {
                    color[cur] = 0;
                }
                if(cur_d == d && color[cur] == -1) {
                    color[cur] = 1;
                }

                for(int nei : G[cur]) {
                    if(!vis[nei]) {
                        vis[nei] = true;
                        q.push(nei);
                    }
                }
            }

            if(++cur_d > d) {
                break;
            }
        }
    }

    for(auto& p : A) {
        int v = p.first;
        int d = p.second;

        std::queue<int> q;
        std::vector<bool> vis(N, false);
        
        q.push(v);
        vis[v] = true;

        int cur_d = 0;
        bool ok = false;
        while(!q.empty()) {
            int sz = q.size();

            while(sz--) {
                int cur = q.front();
                q.pop();
                
                if(cur_d < d && color[cur]) {
                    std::cout << "No" << '\n';
                    return;
                }

                if(cur_d == d && color[cur]) {
                    ok = true;
                }

                for(int nei : G[cur]) {
                    if(!vis[nei]) {
                        vis[nei] = true;
                        q.push(nei);
                    }
                }
            }

            if(++cur_d > d) {
                break;
            }
        }

        if(!ok) {
            std::cout << "No" << '\n';
            return;
        }
    }

    std::cout << "Yes" << '\n';
    std::string ans = "";

    if(K) {
        for(int i = 0; i < N; i++) {
            if(color[i] == 1) {
                ans.push_back('1');
            } else {
                ans.push_back('0');
            }
        }
    } else {
        for(int i = 0; i < N; i++) {
            ans.push_back('1');
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
