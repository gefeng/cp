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
    int N;
    std::cin >> N;

    std::vector<std::vector<int>> G(N);
    for(int i = 0; i < N - 1; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        
        G[U].push_back(V);
        G[V].push_back(U);
    }

    int max_d = 0;
    std::vector<int> diameter;
    for(int i = 0; i < N; i++) {
        int d = 0;
        std::queue<int> q;
        std::vector<int> vis(N, 0);
        std::vector<int> pre(N, -1);
        
        q.push(i);
        vis[i] = 1;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                int v = q.front();
                q.pop();
                
                for(int nei : G[v]) {
                    if(!vis[nei]) {
                        vis[nei] = 1;
                        q.push(nei);
                    }
                }
            }
            d += 1;
        }

        if(d > max_d) {
            max_d = d;
            q = std::queue<int>();
            vis = std::vector<int>(N, 0);
            diameter.clear();
            q.push(i);
            vis[i] = 1;
            d = 0;
            bool found = false;
            while(!q.empty()) {
                int sz = q.size();
                while(sz--) {
                    int v = q.front();
                    q.pop();
                    if(d + 1 == max_d) {
                        found = true;
                        int cur = v;
                        while(cur != -1) {
                            diameter.push_back(cur);
                            cur = pre[cur];
                        }
                        break;
                    }

                    for(int nei : G[v]) {
                        if(!vis[nei]) {
                            vis[nei] = 1;
                            q.push(nei);
                            pre[nei] = v;
                        }
                    }
                }

                if(found) {
                    break;
                }
                d += 1;
            } 
        }
    }

    std::vector<int> ans(N, -1);
    int size = diameter.size();
    int cnt_red = 0;
    int cnt_blue = 0;
    for(int i = 0; i < size / 2; i++) {
        ans[diameter[i]] = 1;
        cnt_red += 1;
    }
    
    for(int i = size / 2; i < size; i++) {
        ans[diameter[i]] = 0;
        cnt_blue += 1;
    }

    for(int i = 0; i < N; i++) {
        if(ans[i] == -1) {
            if(cnt_red <= cnt_blue) {
                ans[i] = 1;
                cnt_red += 1;
            } else {
                ans[i] = 0;
                cnt_blue += 1;
            }
        }
    }

    std::string s(N, 'R');
    for(int i = 0; i < N; i++) {
        if(ans[i] == 0) {
            s[i] = 'B';
        }
    }

    std::cout << s << '\n';
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
