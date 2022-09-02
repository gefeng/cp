#include <iostream>
#include <fstream>
#include <vector>
#include <array>
#include <queue>

using namespace std;

ifstream in;
ofstream out;

void run_case(int T) {
    int R, C;
    in >> R >> C;
    
    vector<string> G(R);
    vector<vector<int>> degree(R, vector<int>(C, 0));
    for(int i = 0; i < R; i++) {
        in >> G[i];
        for(int j = 0; j < C; j++) {
            if(G[i][j] == '.') {
                G[i][j] = '*';
            }
        }
    }

    auto valid = [&](int x, int y) { return x >= 0 && y >= 0 && x < R && y < C; };
    array<int, 4> dr{0, 1, 0, -1};
    array<int, 4> dc{1, 0, -1, 0};

    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(G[i][j] == '*' || G[i][j] == '^') {
                for(int d = 0; d < 4; d++) {
                    int ni = i + dr[d];
                    int nj = j + dc[d];
                    if(valid(ni, nj) && (G[ni][nj] == '^' || G[ni][nj] == '*')) {
                        degree[i][j]++;
                    }
                }
            }
        }
    }

    auto bfs = [&]() {
        queue<pair<int, int>> q;

        for(int i = 0; i < R; i++) {
            for(int j = 0; j < C; j++) {
                if(G[i][j] == '*' && degree[i][j] < 2) {
                    q.emplace(i, j);            
                    G[i][j] =  '.';
                }
            }
        } 

        while(!q.empty()) {
            pair<int, int> cur = q.front();
            q.pop();
            int r = cur.first, c = cur.second;

            for(int d = 0; d < 4; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];
                if(nr >= 0 && nc >= 0 && nr < R && nc < C && (G[nr][nc] == '*' || G[nr][nc] == '^')) {
                    degree[nr][nc]--;
                    if(degree[nr][nc] < 2 && G[nr][nc] == '*') {
                        q.emplace(nr, nc);
                        G[nr][nc] = '.';
                    }
                }
            }
        }
    };

    bfs();
    
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(G[i][j] == '^' && degree[i][j] < 2) {
                out << "Case #" << T << ": " << "Impossible" << '\n';
                return;
            }
            if(G[i][j] == '*') {
                G[i][j] = '^';
            }
        }
    }

    out << "Case #" << T << ": " << "Possible" << '\n';
    for(int i = 0; i < R; i++) {
        out << G[i] << '\n';
    } 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    in.open("input.txt");
    out.open("output.txt");

    int T;
    in >> T;
    for(int t = 1; t <= T; t++) {
        run_case(t);
    }

    in.close();
    out.close();
}
