#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

struct node {
    string _c;
    int _d;
    int _u;
    node() {
    }
    node(string c, int d, int u) : _c(c), _d(d), _u(u) {
    }
};

bool same(node& a, node& b) {
    return a._u == b._u;
}

void run_case(int T) {
    int N;
    cin >> N;
    vector<node> A(N);
    vector<node> sort_A(N);
    vector<node> sort_B(N);
    
    for(int i = 0; i < N; i++) {
        string C;
        int D, U;
        cin >> C >> D >> U;

        A[i] = node(C, D, U);
        sort_A[i] = node(C, D, U);
        sort_B[i] = node(C, D, U);
    }

    auto cmp_1 = [](const node& a, const node& b) {
        if(a._c == b._c) {
            return a._u < b._u;
        }
        return a._c < b._c;
    };

    auto cmp_2 = [](const node& a, const node& b) {
        if(a._d == b._d) {
            return a._u < b._u;
        }
        return a._d < b._d;
    };

    sort(sort_A.begin(), sort_A.end(), cmp_1);
    sort(sort_B.begin(), sort_B.end(), cmp_2);

    int ans = 0;
    for(int i = 0; i < N; i++) {
        if(same(sort_A[i], sort_B[i])) {
            ans++;
        }
    }
    
    cout << "Case #" << T << ": " << ans << '\n';
}

int main() {
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++) {
        run_case(t);
    }
}
