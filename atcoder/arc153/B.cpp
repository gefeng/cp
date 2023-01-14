#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int H, W;
    cin >> H >> W;

    vector<string> G(H);
    for(int i = 0; i < H; i++) {
        cin >> G[i];
    }

    int Q;
    cin >> Q;
    vector<int> X(Q);
    vector<int> Y(Q);
    for(int i = 0; i < Q; i++) {
        cin >> X[i] >> Y[i];
    }

    int lr = 0;
    int rr = W - 1;
    int lc = 0;
    int rc = H - 1;
    for(int i = 0; i < Q; i++) {
        int x = X[i];
        int y = Y[i];

        if((lr + 1) % W == rr) {
            lr = (lr - y + 1 + W) % W;
            rr = (rr + W - y - 1) % W;
        } else {
            lr = (lr + y - 1) % W;
            rr = (rr - W + y + 1 + W) % W;
        }
        
        if((lc + 1) % H == rc) {
            lc = (lc - x + 1 + H) % H;
            rc = (rc + H - x - 1) % H;
        } else {
            lc = (lc + x - 1) % H;
            rc = (rc - H + x + 1 + H) % H;
        }
    }

    vector<int> r(W);
    vector<int> c(H);
    if((lr + 1) % W == rr) {
        for(int i = 0, j = lr; i < W; i++, j = (j - 1 + W) % W) {
            r[j] = i;
        }
    } else {
        for(int i = 0, j = lr; i < W; i++, j = (j + 1) % W) {
            r[j] = i;
        }
    }
    if((lc + 1) % H == rc) {
        for(int i = 0, j = lc; i < H; i++, j = (j - 1 + H) % H) {
            c[j] = i;
        }
    } else {
        for(int i = 0, j = lc; i < H; i++, j = (j + 1) % H) {
            c[j] = i;
        }
    }

    vector<string> ans(H);
    for(int i = 0; i < H; i++) {
        ans[i] = G[i];
    }

    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            ans[c[i]][r[j]] = G[i][j];
        }
    }

    for(int i = 0; i < H; i++) {
        cout << ans[i] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
