#include <iostream>
#include <array>
#include <vector>

using namespace std;

bool can_place(int row, int col, array<bool, 8>& c, array<bool, 15>& d_1, array<bool, 15>& d_2) {
    return !c[col] && !d_1[row - col + 7] && !d_2[row + col];
}

int dfs(array<string, 8>& G, int row, array<bool, 8>& c, array<bool, 15>& d_1, array<bool, 15>& d_2) {
    if(row == 8) {
        return 1;
    }

    int tot = 0;
    for(int i = 0; i < 8; i++) {
        if(G[row][i] != '*' && can_place(row, i, c, d_1, d_2)) {
            c[i] = true;
            d_1[row - i + 7] = true;
            d_2[row + i] = true;

            tot += dfs(G, row + 1, c, d_1, d_2);

            c[i] = false;
            d_1[row - i + 7] = false;
            d_2[row + i] = false;
        }
    }

    return tot;
}

void run_case() {
    array<string, 8> G;
    
    for(int i = 0; i < 8; i++) {
        cin >> G[i];
    }

    array<bool, 8> col{false};
    array<bool, 15> diag_1{false};
    array<bool, 15> diag_2{false};

    cout << dfs(G, 0, col, diag_1, diag_2) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
