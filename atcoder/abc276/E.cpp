#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

using namespace std;

const array<int, 4> DR{0, 1, 0, -1};
const array<int, 4> DC{1, 0, -1, 0};

struct dsu {
    int n;
    vector<int> p;
    vector<int> w;
    dsu(int n) : n(n) {
        p.resize(n, -1);
        w.resize(n, 1);
    }
    
    int find(int i) {
        if(p[i] < 0) {
            return i;
        }
        return p[i] = find(p[i]);
    }

    void unite(int i, int j) {
        int x = find(i);
        int y = find(j);
        if(x == y) {
            return;
        }
        if(w[x] >= w[y]) {
            p[y] = x;
            w[x] += w[y];
        } else {
            p[x] = y;
            w[y] += w[x];
        }
    }
};

void run_case() {
    int M, N;
    cin >> M >> N;

    vector<string> G(M);
    for(int i = 0; i < M; i++) {
        cin >> G[i];
    }

    int sr = 0;
    int sc = 0;

    dsu uf(M * N);
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            if(G[i][j] == '#') {
                continue;
            }
            if(G[i][j] == 'S') {
                sr = i;
                sc = j;
                continue;
            }
            for(int d = 0; d < 4; d++) {
                int ni = i + DR[d];
                int nj = j + DC[d];

                if(ni >= 0 && nj >= 0 && ni < M && nj < N && G[ni][nj] == '.') {
                    uf.unite(i * N + j, ni * N + nj);
                }
            }
        } 
    }

    set<int> seen;
    int cnt = 0;
    for(int i = 0; i < 4; i++) {
        int r = sr + DR[i];
        int c = sc + DC[i];
        if(r >= 0 && c >= 0 && r < M & c < N && G[r][c] == '.') {
            cnt += 1;
            seen.insert(uf.find(r * N + c));
        }
    } 

    if(cnt > 1 && seen.size() < cnt) {
        cout << "Yes" << '\n';
    } else {
        cout << "No" << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
