#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

int hashify(map<vector<int>, int>& m, vector<int>& subtree) {
    sort(subtree.begin(), subtree.end());
    
    if(!m[subtree]) {
        m[subtree] = m.size();
    }
    
    return m[subtree];
}

bool is_sym(vector<int>& subtree) {
    set<int> s;
    for(int hash : subtree) {
        if(s.find(hash) == s.end()) {
            s.insert(hash);
        } else {
            s.erase(hash);
        }
    }
    return s.size() < 2;
}

int dfs(vector<vector<int>>& G, map<vector<int>, int>& m, vector<vector<int>>& levels, int v, int p, int lv) {
    if(lv == levels.size()) {
        levels.emplace_back();
    }

    vector<int> subtree;
    for(int nei : G[v]) {
        if(nei != p) {
            subtree.push_back(dfs(G, m, levels, nei, v, lv + 1));
        }
    }

    int hash = hashify(m, subtree);
    
    levels[lv].push_back(hash);

    return hash;
}

void run_case() {
    int N;
    cin >> N;
    
    vector<vector<int>> G(N);
    for(int i = 0; i < N - 1; i++) {
        int U, V;
        cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].push_back(V);
        G[V].push_back(U);
    }

    map<vector<int>, int> m;
    vector<vector<int>> levels;
    dfs(G, m, levels, 0, -1, 0);

    for(auto& level : levels) {
        set<int> s;
        for(int hash : level) {
            if(s.find(hash) == s.end()) {
                s.insert(hash);
            } else {
                s.erase(hash);
            }
        }

        if(s.size() > 1) {
            cout << "NO" << '\n';
            return;
        }
    }
    
    cout << "YES" << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        run_case();
    }
}
