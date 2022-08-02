#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;
using LL = long long;

void dfs(vector<vector<array<int, 3>>>& g, vector<LL>& ans, int cur, LL sum_a, LL sum_b, vector<LL>& prefix) {
    if(cur != 1) {
        int res = upper_bound(prefix.begin(), prefix.end(), sum_a) - prefix.begin();
        ans[cur] = res;
    }

    for(array<int, 3>& c : g[cur]) {
        prefix.push_back(sum_b + c[2]);
        dfs(g, ans, c[0], sum_a + c[1], sum_b + c[2], prefix);
        prefix.pop_back();
    }
}

void run_case() {
    int N;
    cin >> N;

    vector<vector<array<int, 3>>> g(N + 1);
    for(int i = 2; i <= N; i++) {
        int P, A, B;
        cin >> P >> A >> B;
        g[P].push_back({i, A, B});
    }
   
    vector<LL> ans(N + 1, 0);
    vector<LL> prefix;
    dfs(g, ans, 1, 0LL, 0LL, prefix);

    for(int i = 2; i <= N; i++) {
        cout << ans[i] << " \n"[i == N];
    }
}

int main() {
    ios::sync_with_stdio(false);        // de-sync with c stream
    cin.tie(0);                         // disable flushing of std::cout
    
    int t = 0;
    cin >> t;
    while(t--) {
        run_case();
    }
}
