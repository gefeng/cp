#include <iostream>
#include <array>
#include <cstring>
#include <string>

using namespace std;

array<int, 4> DR{-1, 0, 1, 0};
array<int, 4> DC{0, 1, 0, -1};
bool vis[9][9];

bool can_drop(int r, int c, int d) {
    int r_1 = r + DR[d];
    int c_1 = c + DC[d];
    int r_2 = r + DR[(d + 1) % 4];
    int c_2 = c + DC[(d + 1) % 4];
    int r_3 = r + DR[(d + 3) % 4];
    int c_3 = c + DC[(d + 3) % 4];
    return vis[r_1][c_1] && !vis[r_2][c_2] && !vis[r_3][c_3];
}

int dfs(string& S, int i, int r, int c, int d) {
    if(i == 48 && r == 7 && c == 1) {
        return 1;
    }
    if(r == 7 && c == 1) {
        return 0;
    }
    if(can_drop(r, c, d)) {
        return 0;
    }

    vis[r][c] = true;

    int cnt = 0;
    if(S[i] == '?') {
        for(int j = 0; j < 4; j++) {
            int nr = r + DR[j];
            int nc = c + DC[j];
            if(!vis[nr][nc]) {
                cnt += dfs(S, i + 1, nr, nc, j);
            }
        } 
    } else {
        int j = 0;
        if(S[i] == 'U') j = 0;
        else if(S[i] == 'R') j = 1;
        else if(S[i] == 'D') j = 2;
        else j = 3;
        int nr = r + DR[j];
        int nc = c + DC[j];
        if(!vis[nr][nc]) {
            cnt += dfs(S, i + 1, nr, nc, j);   
        }
    }

    vis[r][c] = false;

    return cnt;
}

void run_case() {
    string S;
    cin >> S;
    
    memset(vis, false, sizeof(vis));
    for(int i = 0; i < 9; i++) {
        vis[0][i] = true;
        vis[8][i] = true;
        vis[i][0] = true;
        vis[i][8] = true;
    }
    
    cout << dfs(S, 0, 1, 1, 0) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
