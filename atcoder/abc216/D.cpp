#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

void run_case() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> A(M);
    for(int i = 0; i < M; i++) {
        int K;
        cin >> K;

        A[i].resize(K);
        for(int j = 0; j < K; j++) {
            cin >> A[i][j];
        }

        reverse(A[i].begin(), A[i].end());
    }

    map<int, int> m1;
    map<int, vector<int>> m2; 
    queue<pair<int, int>> q;
    for(int i = 0; i < M; i++) {
        int c = A[i][A[i].size() - 1];
        m1[c] += 1;
        m2[c].push_back(i);
        
        if(m1[c] == 2) {
            m1.erase(c);
            vector<int>& v = m2[c];
            q.emplace(v[0], v[1]);
            A[v[0]].pop_back();
            A[v[1]].pop_back();
            m2.erase(c);
        }
    }

    while(!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        int x = cur.first;
        int y = cur.second;

        if(A[x].size()) {
            int c = A[x][A[x].size() - 1]; 
            m1[c] += 1;
            m2[c].push_back(x);

            if(m1[c] == 2) {
                m1.erase(c);
                vector<int>& v = m2[c];
                q.emplace(v[0], v[1]);
                A[v[0]].pop_back();
                A[v[1]].pop_back();
                m2.erase(c);
            }
        }
        if(A[y].size()) {
            int c = A[y][A[y].size() - 1]; 
            m1[c] += 1;
            m2[c].push_back(y);

            if(m1[c] == 2) {
                m1.erase(c);
                vector<int>& v = m2[c];
                q.emplace(v[0], v[1]);
                A[v[0]].pop_back();
                A[v[1]].pop_back();
                m2.erase(c);
            }
        }
    }

    for(int i = 0; i < M; i++) {
        if(A[i].size()) {
            cout << "No" << '\n';
            return;
        }
    }

    cout << "Yes" << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
