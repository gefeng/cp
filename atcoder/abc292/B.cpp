#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int N, Q;
    cin >> N >> Q;

    vector<int> cnt_y(200, 0);
    vector<int> cnt_r(200, 0);
    for(int i = 0; i < Q; i++) {
        int T, X;
        cin >> T >> X;
        if(T == 1) {
            cnt_y[X] += 1;
        } else if(T == 2) {
            cnt_r[X] += 1;
        } else {
            cout << (cnt_y[X] > 1 || cnt_r[X] > 0 ? "Yes" : "No") << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
