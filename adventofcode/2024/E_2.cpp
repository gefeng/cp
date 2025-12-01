#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>

bool is_digit(char c) {
    return c >= '0' && c <= '9';
}

int next_int(std::string& s, int& p) {
    int x = 0;
    int n = s.size();
    while(p < n && (!is_digit(s[p]))) {
        p += 1;
    }

    if(p == n) {
        return -1;
    }

    while(p < n && is_digit(s[p])) {
        x = x * 10 + s[p] - '0';
        p += 1;
    }

    return x;
}

std::vector<int> topological_sort(std::map<int, std::set<int>>& g) {
    std::vector<int> order;
    std::map<int, int> degree;
    std::queue<int> q;

    for(auto& [v, a] : g) {
        for(int u : a) {
            degree[u] += 1;
        }
    }

    for(auto& [v, _] : g) {
        if(degree.find(v) == degree.end()) {
            q.push(v); 
        }
    }

    while(!q.empty()) {
        int v = q.front();
        q.pop();

        order.push_back(v);
        
        for(int u : g[v]) {
            if(--degree[u] == 0) {
                q.push(u);
            }
        }
    }

    return order;
}

void run_case() {
    int ans = 0;
    bool reading_rules = true;
    std::map<int, std::set<int>> m;

    for(std::string S; std::getline(std::cin, S); ) {
        if(S.empty()) {
            reading_rules = false;
            // order = topological_sort(m);
            // for(int i = 0; i < order.size(); i++) {
            //     pos[order[i]] = i;
            // }
            continue;
        }

        if(reading_rules) {
            int p = 0;
            int x = next_int(S, p);
            int y = next_int(S, p); 
            m[x].insert(y);
        } else {
            std::vector<int> a;
            int p = 0;
            while(true) {
                int x = next_int(S, p);
                if(x == -1) {
                    break;
                }
                a.push_back(x);
            }

            int n = a.size();
            std::vector<int> b(n);
            std::vector<int> c;
            std::map<int, std::set<int>> g;
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(i != j) {
                        if(m[a[i]].find(a[j]) != m[a[i]].end()) {
                            g[a[i]].insert(a[j]);
                        }
                    }
                }    
            }

            std::vector<int> order = topological_sort(g);
            std::map<int, int> pos;
            for(int i = 0; i < n; i++) {
                pos[order[i]] = i;
            }

            for(int i = 0; i < n; i++) {
                b[i] = pos[a[i]];
            }

            c = b;
            std::sort(c.begin(), c.end());
            if(c != b) {
                ans += order[c[n / 2]];
            }
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
