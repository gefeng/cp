#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

struct fenwick_tree {
    int n;
    vector<int> ft;
    fenwick_tree(int _n) : n(_n + 1) {
        ft.resize(n, 0);
    }

    void update(int i, int v) {
        for(++i; i < n; i += i & -i) {
            ft[i] += v;
        }
    }

    int query(int i) {
        int res = 0;
        for(++i; i > 0; i -= i & -i) {
            res += ft[i];
        }
        return res;
    }
};

void run_case() {
    int N, Q;
    cin >> N >> Q;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    map<int, vector<int>> m;
    for(int i = 0; i < N; i++) {
        m[A[i]].push_back(i);
    }

    vector<array<int, 3>> points;
    for(auto& [_, v] : m) {
        int sz = v.size();
        if(sz > 1) {
            for(int i = 0; i < sz - 1; i++) {
                points.push_back({v[i], v[i + 1], 0});
            }
        }
    }

    vector<pair<int, int>> queries(Q);
    for(int i = 0; i < Q; i++) {
        int L, R;
        cin >> L >> R;
        L -= 1;
        R -= 1;

        queries[i].first = L;
        queries[i].second = R;

        points.push_back({L, R, 1});
    }

    auto cmp = [](const auto& a, const auto& b) {
        if(a[0] == b[0]) {
            return a[2] < b[2];
        } 
        return a[0] > b[0];
    };

    sort(points.begin(), points.end(), cmp);

    fenwick_tree ft(N + 5);
    map<pair<int, int>, int> res_m;

    for(auto& p : points) {
        if(p[2] == 0) {
            ft.update(p[1], 1);
        } else {
            int res = p[1] - p[0] + 1; 
            res -= ft.query(p[1]);
            res_m[{p[0], p[1]}] = res;
        }
    }

    for(int i = 0; i < Q; i++) {
        cout << res_m[{queries[i].first, queries[i].second}] << '\n';

    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
