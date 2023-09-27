#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>
#include <queue>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::map<int, int> freq;
    for(int x : A) {
        freq[x] += 1;
    }

    std::map<int, std::map<int, int>> g;
    std::map<int, int> indegree;
    std::priority_queue<std::pair<int64_t, int>>  pq;
    std::map<int, int64_t> max_score;
    for(auto [x, v] : freq) {
        std::vector<int> factors;
        for(int f = 1; f * f <= x; f++) {
            if(x % f == 0) {
                if(f != x) {
                    factors.push_back(f);
                }
                if(x / f != f && x / f != x) {
                    factors.push_back(x / f);
                }
            }
        }

        for(int f : factors) {
            if(freq.find(f) != freq.end()) {
                g[x][f] = freq[f];
                indegree[f] += 1;
            }
        }
    }

    for(auto [v, f] : freq) {
        if(indegree.find(v) == indegree.end()) {
            pq.emplace(f, v);
            max_score[v] = f;
        }
    }

    while(!pq.empty()) {
        std::pair<int64_t, int> cur = pq.top();
        pq.pop();
        int64_t s = cur.first;
        int v = cur.second;
        
        if(max_score[v] != s) {
            continue;
        }

        for(auto [nv, w] : g[v]) {
            int64_t ns = s + w;
            if(max_score.find(nv) == max_score.end() || max_score[nv] < ns) {
                max_score[nv] = ns;
                pq.emplace(ns, nv);
            }
        }
    }

    int64_t ans = 0;
    for(auto [v, s] : max_score) {
        ans = std::max(ans, v * s);  
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
