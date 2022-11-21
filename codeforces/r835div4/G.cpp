#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

using namespace std;

void dfs_1(vector<vector<pair<int, int>>>& G, int A, int B, int cur, int pre, int sum, set<int>& s) {
    s.insert(sum);

    for(auto& nei : G[cur]) {
        if(nei.first != pre && nei.first != B) {
            dfs_1(G, A, B, nei.first, cur, sum ^ nei.second, s);
        }
    }
}

bool dfs_2(vector<vector<pair<int, int>>>& G, int cur, int pre, int sum, set<int>& s) {
    if(pre != -1) {
        if(s.find(sum) != s.end()) {
            return true;
        }
    }

    for(auto& nei : G[cur]) {
        if(nei.first != pre) {
            if(dfs_2(G, nei.first, cur, sum ^ nei.second, s)) {
                return true;
            }
        }
    }

    return false;
}

void run_case() {
    int N, A, B;
    cin >> N >> A >> B;

    A -= 1;
    B -= 1;

    vector<vector<pair<int, int>>> G(N);
    for(int i = 0; i < N - 1; i++) {
        int U, V, W;
        cin >> U >> V >> W;
        U -= 1;
        V -= 1;
        
        G[U].emplace_back(V, W);
        G[V].emplace_back(U, W);
    }

    set<int> s;
    dfs_1(G, A, B, A, -1, 0, s);

    cout << (dfs_2(G, B, -1, 0, s) ? "YES" : "NO") << '\n';
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
