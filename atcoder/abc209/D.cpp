#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& G, vector<int>& color, int v, int p, int c) {
    color[v] = c;
    
    for(int nei : G[v]) {
        if(nei != p) {
            dfs(G, color, nei, v, c ^ 1);
        }
    }
}

void run_case() {
    int N, Q;
    cin >> N >> Q;

    vector<vector<int>> G(N);
    for(int i = 0; i < N - 1; i++) {
        int U, V;
        cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].push_back(V);
        G[V].push_back(U);
    }

    vector<int> color(N, 0);
    dfs(G, color, 0, -1, 0);

    for(int i = 0; i < Q; i++) {
        int A, B;
        cin >> A >> B;
        A -= 1;
        B -= 1;
        
        if(color[A] == color[B]) {
            cout << "Town" << '\n';
        } else {
            cout << "Road" << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
