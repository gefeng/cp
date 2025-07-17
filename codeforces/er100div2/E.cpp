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
    int N, K;
    std::cin >> N >> K;

    std::vector<int> A(N);
    std::vector<std::vector<int>> g1(N);
    std::vector<std::vector<int>> g2(N);
    std::vector<std::vector<int>> g3(N);
    std::vector<int> indegree1(N, 0);
    std::vector<int> indegree2(N, 0);
    for(int i= 0; i < N; i++) {
        std::cin >> A[i];
        A[i] -= 1;
        if(A[i] != -1) {
            g3[A[i]].push_back(i);
            indegree1[i] += 1;
        }
    }

    for(int i = 0; i < K; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        g2[U].push_back(V);
        g3[U].push_back(V);
        indegree1[V] += 1;
        indegree2[V] += 1;
    }

    {
        std::queue<int> q;
        int cnt = 0;
        for(int i = 0; i < N; i++) {
            if(indegree1[i] == 0) {
                q.push(i);
            } 
        }
        while(!q.empty()) {
            int v = q.front();
            q.pop();
            cnt += 1;

            for(int nei : g3[v]) {
                if(--indegree1[nei] == 0) {
                    q.push(nei);
                }
            }
        }
        if(cnt != N) {
            std::cout << 0 << '\n';
            return;
        }
    }

    std::vector<int> head(N, -1);
    int cnt = 0;
    for(int i = 0; i < N; i++) {
        if(indegree2[i] == 0) {
            int v = i;
            while(true) {
                head[v] = i;
                cnt += 1;
                if(g2[v].empty()) {
                    break;
                }
                v = g2[v][0];
            }
        }
    }

    if(cnt != N) {
        std::cout << 0 << '\n';
        return;
    }

    indegree1.assign(N, -1);
    for(int i = 0; i < N; i++) {
        int p = A[i];
        if(p != -1) {
            int u = head[p];
            int v = head[i];
            if(u == v) {
                indegree1[u] = indegree1[u] == -1 ? 0 : indegree1[u];
            } else {
                g1[u].push_back(v);
                indegree1[u] = indegree1[u] == -1 ? 0 : indegree1[u];
                indegree1[v] = indegree1[v] == -1 ? 1 : indegree1[v] + 1;
            }
        } else {
            int u = head[i];
            indegree1[u] = indegree1[u] == -1 ? 0 : indegree1[u];
        }
    }

    std::queue<int> q;
    std::vector<int> ans;
    for(int i = 0; i < N; i++) {
        if(indegree1[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        int v = q.front();
        q.pop();
        
        int now = v;
        while(true) {
            ans.push_back(now);
            if(g2[now].empty()) {
                break;
            }
            now = g2[now][0];
        }

        for(int nei : g1[v]) {
            if(--indegree1[nei] == 0) {
                q.push(nei);
            }
        }
    }

    if(ans.size() != N) {
        std::cout << 0 << '\n';
        return;
    }

    for(int i = 0; i < N; i++) {
        std::cout << ans[i] + 1 << " \n"[i == N - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
