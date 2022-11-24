#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

using namespace std;

void run_case() {
    int N;
    cin >> N;
 
    vector<vector<int>> G(N);
    vector<int> indegree(N, 0);
    for(int i = 0; i < N; i++) {
        string S;
        cin >> S;
 
        for(int j = 0; j < N; j++) {
            if(S[j] == '1') {
                G[i].push_back(j);
                indegree[j] += 1;
            }
        }
    }
 
    vector<vector<int>> ans(N);
    queue<int> q;
    
    for(int i = 0; i < N; i++) {
        if(indegree[i] == 0) {
            q.push(i);
            ans[i].push_back(i);
        }
    }
 
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
 
        for(int nei : G[cur]) {
            ans[nei].push_back(cur);
            if(--indegree[nei] == 0) {
                ans[nei].push_back(nei);
                q.push(nei); 
            }
        } 
    }
 
    for(int i = 0; i < N; i++) {
        int sz = ans[i].size();
        cout << sz << ' ';
 
        for(int j = 0; j < sz; j++) {
            cout << ans[i][j] + 1 << " \n"[j == sz - 1];
        }
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
