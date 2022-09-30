#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

void run_case() {
    int N; 
    cin >> N;

    vector<int> B(N, 0);
    for(int i = 0; i < N; i++) {
        cin >> B[i];
    }

    int k = 0;
    int l = 0;
    int r = N + 1;
    for(int i = 0; i < N; i++) {
        int x = i + 1; 
        if(B[i] == 0) {
            r = min(r, x);
        } else if(B[i] == N + 1) {
            l = max(l, x);
        } else {
            if(x > B[i]) {
                l = max(l, B[i]); 
                r = min(r, x);
            } else {
                l = max(l, x);
                r = min(r, B[i]);
            }
        }
    }

    k = l;
    
    vector<vector<int>> g(N + 1);
    vector<int> ind(N + 1, 0);
    vector<int> seg;
    vector<int> ans;
    unordered_set<int> solved;

    for(int i = 0; i < N; i++) {
        if(B[i] > 0 && B[i] <= N) {
            g[B[i]].push_back(i + 1);
            ind[i + 1]++;
            solved.insert(i + 1);
            solved.insert(B[i]);
        }
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for(int i = 1; i <= N; i++) {
        if(solved.find(i) != solved.end() && ind[i] == 0) {
            pq.emplace(g[i].size(), i);        
        }
    }

    while(!pq.empty()) {
        pair<int, int> cur = pq.top();
        pq.pop();

        seg.push_back(cur.second);

        for(int nei : g[cur.second]) {
            if(--ind[nei] == 0) {
                pq.emplace(g[nei].size(), nei);
            }
        }
    }

    ans.reserve(N);
    for(int i = 1; i <= N; i++) {
        if(solved.find(i) == solved.end()) {
            ans.push_back(i);
        }
    }

    for(int x : seg) {
        ans.push_back(x);
    }
    
    cout << k << '\n';
    for(int i = 0; i < N; i++) {
        cout << ans[i] << " \n"[i == N - 1];
    }
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
