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

    string S;
    cin >> S;

    vector<pair<int, int>> A(Q, {0, 0});
    for(int i = 0; i < Q; i++) {
        cin >> A[i].first >> A[i].second;
    }

    int delta = 0;
    for(int i = 0; i < Q; i++) {
        int o = A[i].first;
        int x = A[i].second;

        if(o == 1) {
            delta = (delta + x) % N;
        } else {
            cout << S[(N - delta + x - 1) % N] << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
