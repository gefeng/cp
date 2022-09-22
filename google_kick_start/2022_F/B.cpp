#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& G, int cur, int p, int dep, vector<int>& cnt) {
    if(cnt.size() <= dep) {
        cnt.push_back(0);
    } 

    cnt[dep]++;

    for(int nei : G[cur]) {
        if(nei != p) {
            dfs(G, nei, cur, dep + 1, cnt);
        }
    }
}

void run_case(int T) {
    int N, Q;
    cin >> N >> Q;

    vector<vector<int>> G(N);
    for(int i = 0; i < N - 1; i++) {
        int U, V;
        cin >> U >> V;
        U--;
        V--;
        G[U].push_back(V);
        G[V].push_back(U);
    }

    int sum = 0;
    for(int i = 0; i < Q; i++) {
        int X;
        cin >> X;
        sum++;
    }

    vector<int> cnt;
    dfs(G, 0, -1, 0, cnt);

    int sz = cnt.size();
    int ans = 0;
    for(int i = 0; i < sz; i++) {
        if(sum >= cnt[i]) {
            ans += cnt[i]; 
            sum -= cnt[i];
        } else {
            break;
        }
    }

    cout << "Case #" << T << ": " << ans << '\n';
}

int main() {
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++) {
        run_case(t);
    }
}
