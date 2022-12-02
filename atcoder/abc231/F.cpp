#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;
using LL = long long;

struct fenwick_tree {
    int sz;
    vector<int> ft;

    fenwick_tree(int n) : sz(n + 1) {
        ft.resize(sz, 0); 
    }

    void update(int i, int x) {
        for(i++; i < sz; i += i & -i) {
            ft[i] += x;
        }
    }

    int query(int i) {
        int res = 0;
        for(i++; i > 0; i -= i & -i) {
            res += ft[i];
        }
        return res;
    }

    int query(int l, int r) {
        return query(r) - query(l - 1);
    }
};

// coordinates compression
void compress(vector<int>& a) {
    set<int> s(a.begin(), a.end());
    
    int id = 0;
    map<int, int> m;
    for(int x : s) {
        m[x] = id++;
    }
    
    for(int& x : a) {
        x = m[x];
    }
}

void run_case() {
    int N;
    cin >> N;
    
    vector<int> A(N);
    vector<int> B(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        cin >> B[i];
    }

    compress(A);
    compress(B);

    map<int, vector<int>> m;
    for(int i = 0; i < N; i++) {
        m[A[i]].push_back(B[i]);
    }

    fenwick_tree ft(N + 5);
    LL ans = 0;
    for(auto& [_, v] : m) {
        for(int x : v) {
            ft.update(x, 1);
        } 

        for(int x : v) {
            ans += ft.query(x, N + 4);
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
