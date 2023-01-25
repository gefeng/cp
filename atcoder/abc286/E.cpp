#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

using namespace std;
using LL = long long;

const LL INF = (LL)2e18;

void run_case() {
    int N;
    cin >> N;
    
    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<string> G(N);
    for(int i = 0; i < N; i++) {
        cin >> G[i];
    }

    vector<vector<LL>> d(N, vector<LL>(N, INF));
    for(int i = 0; i < N; i++) {
        d[i][i] = 0LL;
        for(int j = 0; j < N; j++) {
            if(G[i][j] == 'Y') {
                d[i][j] = 1LL;
            } 
        }
    }
    
    for(int k = 0; k < N; k++) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(d[i][k] != INF && d[k][j] != INF) {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
    }

    vector<vector<LL>> v(N, vector<LL>(N, 0LL));
    for(int i = 0; i < N; i++) {
        v[i][i] = A[i];
        for(int j = 0; j < N; j++) {
            if(G[i][j] == 'Y') {
                v[i][j] = A[i] + A[j];
            }
        }
    }
    
    for(int k = 0; k < N; k++) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(d[i][k] != INF && d[k][j] != INF && d[i][k] + d[k][j] == d[i][j]) {
                    v[i][j] = max(v[i][j], v[i][k] + v[k][j] - A[k]);
                }
            }
        }
    }

    int Q;
    cin >> Q;
    for(int i = 0; i < Q; i++) {
        int U, V;
        cin >> U >> V;
        U -= 1;
        V -= 1;
        
        if(d[U][V] == INF) {
            cout << "Impossible" << '\n';
        } else {
            cout << d[U][V] << ' ' << v[U][V] << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
