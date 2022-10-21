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
    int par;
    node(int v, int p) : val(v), par(p) {}
};

void run_case() {
    int Q;
    cin >> Q;

    vector<pair<int, int>> A(Q, {0, 0});
    for(int i = 0; i < Q; i++) {
        string S;
        cin >> S;
        
        if(S == "ADD") {
            A[i].first = 0; 
            cin >> A[i].second;
        } else if(S == "DELETE") {
            A[i].first = 1;
        } else if(S == "SAVE") {
            A[i].first = 2;
            cin >> A[i].second;
        } else {
            A[i].first = 3; 
            cin >> A[i].second;
        }
    }

    map<int, int> m;
    vector<node> t;
    int cur = 0;

    t.reserve(Q);
    t.emplace_back(-1, -1);
    for(int i = 0; i < Q; i++) {
        pair<int, int>& q = A[i];
        int o = q.first;
        int x = q.second;
        if(o == 0) {
            t.emplace_back(x, cur);
            cur = t.size() - 1;
        } else if(o == 1) {
            if(cur) {
                cur = t[cur].par;
            }
        } else if(o == 2) {
            m[x] = cur;
        } else {
            cur = m[x];
        }

        cout << t[cur].val << " \n"[i == Q - 1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
