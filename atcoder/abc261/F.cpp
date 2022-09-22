#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;
using LL = long long;

array<int, 300005> bit = {0};
void reset() {
    bit.fill(0);
}

void update(int i, int v) {
    for(++i; i < 300005; i += i & -i) {
        bit[i] += v; 
    }
}

void update(int i) {
    update(i, 1);
}

int query(int i) {
    int res = 0;
    for(++i; i > 0; i -= i & -i) {
        res += bit[i];
    }
    return res;
}

int query(int l, int r) {
    return query(r) - query(l - 1);
}

void run_case() {
    int N = 0;
    cin >> N;

    vector<int> C(N);
    vector<int> X(N);
    unordered_map<int, vector<int>> c_map;
    for(int i = 0; i < N; i++) {
        cin >> C[i];
    }

    for(int i = 0; i < N; i++) {
        cin >> X[i]; 
        c_map[C[i]].push_back(X[i]);
    }

    LL ans = 0;
    for(int x : X) {
        ans += query(x + 1, 300000);
        update(x);
    }

    reset();
    for(auto& it : c_map) {
        for(int x : it.second) {
            ans -= query(x + 1, 300000);
            update(x);
        }
        for(int x : it.second) {
            update(x, -1);
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);        // de-sync with c stream
    cin.tie(0);                         // disable flushing of std::cout
    
    run_case();
}
