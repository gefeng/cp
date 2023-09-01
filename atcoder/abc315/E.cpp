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
    std::vector<int> indegree(N, 0);

    for(int i = 0; i < N; i++) {
        int M;
        std::cin >> M;

        for(int j = 0; j < M; j++) {
            int P;
            std::cin >> P;
            P -= 1;

            G[P].push_back(i);
            indegree[i] += 1;
        }
    }

    std::vector<std::vector<int>> pre(N);
    std::queue<int> q;
    for(int i = 0; i < N; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    std::vector<int> topo;
    while(!q.empty()) {
        int sz = q.size();
        while(sz--) {
            int v = q.front();
            q.pop();

            topo.push_back(v);

            if(v == 0) {
                break;
            }

            for(int nei : G[v]) {
                pre[nei].push_back(v);
                if(--indegree[nei] == 0) {
                    q.push(nei);
                }
            }
        }
    }

    std::vector<int> ans;
    std::vector<int> read;
    std::vector<int> vis(N, 0);
    read.push_back(0);
    vis[0] = 1;
    while(!read.empty()) {
        std::vector<int> nxt_read;
        for(int b1 : read) {
            for(int b2 : pre[b1]) {
                if(!vis[b2]) {
                    vis[b2] = 1;
                    nxt_read.push_back(b2);
                }
            }
        }

        std::swap(read, nxt_read);
    }

    for(int v : topo) {
        if(vis[v] && v != 0) {
            ans.push_back(v);
        }
    }

    int sz = ans.size();
    for(int i = 0; i < sz; i++) {
        std::cout << ans[i] + 1 << " \n"[i == sz - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
