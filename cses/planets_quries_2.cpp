#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>

constexpr int LOG = 20;

void run_case() {
    int N, Q;
    std::cin >> N >> Q;

    std::vector<int> A(N);
    std::vector<std::vector<int>> G(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        A[i] -= 1;
        G[A[i]].push_back(i);
    }

    std::map<int, std::set<int>> mc1; 
    std::map<int, int> mc2;
    std::vector<int> vis(N, 0);
    std::vector<int> dist1(N, 0);
    for(int i = 0; i < N; i++) {
        if(vis[i]) {
            continue;
        }

        int cur = i;
        std::set<int> s;
        while(s.find(cur) == s.end() && !vis[cur]) {
            s.insert(cur);
            cur = A[cur];
        }

        if(!vis[cur]) {
            int start = cur;
            int d = 0;
            std::set<int> cycle;
            while(cycle.find(cur) == cycle.end()) {
                cycle.insert(cur);
                mc2[cur] = start;
                dist1[cur] = d++;
                cur = A[cur];
            }

            mc1[start] = cycle;
        }

        for(int v : s) {
            vis[v] = 1;
        }
    }
    
    std::map<int, int> mt;
    std::vector<int> dist2(N, 0);
    for(auto& [st, cycle] : mc1) {
        for(int v : cycle) {
            std::queue<int > q;
            q.push(v);

            int d = 0;
            while(!q.empty()) {
                int sz = q.size();
                while(sz--) {
                    int cur = q.front();
                    q.pop();

                    mt[cur] = v;

                    dist2[cur] = d;

                    for(int nei : G[cur]) {
                        if(cycle.find(nei) == cycle.end()) {
                            q.push(nei);
                        }
                    }
                }
                d += 1;
            }
        } 
    }
    
    std::vector<std::vector<int>> up(LOG + 1, std::vector<int>(N, 0));
    for(int i = 0; i < N; i++) {
        up[0][i] = A[i];
    }

    for(int i = 1; i <= LOG; i++) {
        for(int j = 0; j < N; j++) {
            up[i][j] = up[i - 1][up[i - 1][j]];
        }
    }

    for(int i = 0; i < Q; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;

        if(U == V) {
            std::cout << 0 << '\n';
            continue;
        }

        bool on_cycle_u = mc2.find(U) != mc2.end();
        bool on_cycle_v = mc2.find(V) != mc2.end();
        
        int res = -1;
        if(on_cycle_u && on_cycle_v) {
            if(mc2[U] != mc2[V]) {
                res = -1; 
            } else {
                if(dist1[U] <= dist1[V]) {
                    res = dist1[V] - dist1[U];
                } else {
                    res = mc1[mc2[U]].size() - (dist1[U] - dist1[V]);
                }
            }
        } else if(on_cycle_u) {
            res = -1; 
        } else if(on_cycle_v) {
            int root = mt[U];
            if(mc2[root] != mc2[V]) {
                res = -1;
            } else {
                if(dist1[root] <= dist1[V]) {
                    res = dist1[V] - dist1[root];
                } else {
                    res = mc1[mc2[V]].size() - (dist1[root] - dist1[V]);
                }
                res += dist2[U];
            }
        } else {
            if(mt[U] != mt[V]) {
                res = -1;
            } else {
                int du = dist2[U];
                int dv = dist2[V];
                
                if(du <= dv) {
                    res = -1;
                } else {
                    int d = du - dv;
                    int v = U;
                    for(int j = LOG; j >=0; j--) {
                        if(d & (1 << j)) {
                            v = up[j][v];    
                        }
                    }

                    if(v == V) {
                        res = d;
                    } else {
                        res = -1;
                    }
                }
            }
        }

        std::cout << res << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
