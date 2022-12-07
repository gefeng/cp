#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

using namespace std;

struct node {
    int val;
    int nxt;
    int pre;
    node() {}
    node(int val) : val(val), nxt(-1), pre(-1) {}
};

void run_case() {
    int N, Q;
    cin >> N >> Q;

    map<int, node> m;
    for(int i = 0; i < N; i++) {
        m[i] = node(i);
    }

    for(int i = 0; i < Q; i++) {
        int T;
        cin >> T;
        if(T == 1) {
            int X, Y;
            cin >> X >> Y;
            X -= 1;
            Y -= 1;

            node& x = m[X];
            node& y = m[Y];
            x.nxt = Y;
            y.pre = X;
        } else if(T == 2) {
            int X, Y;
            cin >> X >> Y;
            X -= 1;
            Y -= 1;
            
            node& x = m[X];
            node& y = m[Y];
            x.nxt = -1;
            y.pre = -1;
        } else {
            int X;
            cin >> X;
            X -= 1;

            vector<int> v;
            int cur = X;
            while(m[cur].pre != -1) {
                cur = m[cur].pre;
            }
            
            while(cur != -1) {
                v.push_back(cur);
                cur = m[cur].nxt;
            }

            int sz = v.size();
            cout << sz << ' ';
            for(int j = 0; j < sz; j++) {
                cout << v[j] + 1 << " \n"[j == sz - 1];
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
