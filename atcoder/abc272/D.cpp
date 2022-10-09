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
    int N, M;
    cin >> N >> M;
    
    vector<pair<int, int>> sq_sum;
    for(int i = 0; i * i <= M; i++) {
        for(int j = 0; j * j <= M; j++) {
            if(i * i + j * j == M) {
                sq_sum.emplace_back(i, j);
            }
        }
    }
    int m = sq_sum.size();
    

    vector<vector<int>> ans(N, vector<int>(N, -1));
    queue<pair<int, int>> q;
    
    ans[0][0] = 0;
    q.emplace(0, 0); 

    int steps = 1;
    while(!q.empty()) {
        int sz = q.size();
        while(sz--) {
            pair<int, int> cur = q.front();
            q.pop();
            int r = cur.first;
            int c = cur.second;
            
            for(int i = 0; i < m; i++) {
                for(int j = -1; j < 2; j += 2) {
                    for(int k = -1; k < 2; k += 2) {
                        int nr = r + sq_sum[i].first * j;
                        int nc = c + sq_sum[i].second * k;
                        if(nr >= 0 && nc >= 0 && nr < N && nc < N && ans[nr][nc] == -1) {
                            ans[nr][nc] = steps;
                            q.emplace(nr, nc);
                        }
                    }
                }
            }
        }
        steps++;
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << ans[i][j] << " \n"[j == N - 1];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
