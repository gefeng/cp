#include <iostream>
#include <array>
#include <vector>

using namespace std;

void run_case() {
    int H, W;
    cin >> H >> W;

    vector<string> G(H);
    for(int i = 0; i < H; i++) {
        cin >> G[i];
    }

    int r = 0;
    int c = 0;
    array<char, 4> D = {'U', 'D', 'L', 'R'};
    array<int, 4> DR = {-1, 1, 0, 0};
    array<int, 4> DC = {0, 0, -1, 1};
    while(true) {
        int d = 0;
        for(; d < 4; d++) {
            if(G[r][c] == D[d]) {
                break;
            }
        }

        G[r][c] = '*';

        int nr = r + DR[d];
        int nc = c + DC[d];

        if(nr < 0 || nc < 0 || nr == H || nc == W) {
            cout << r + 1 << ' ' << c + 1 << '\n';
            break;
        }
        if(G[nr][nc] == '*') {
            cout << -1 << '\n'; 
            break;
        }

        r = nr;
        c = nc;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
