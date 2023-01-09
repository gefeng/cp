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

    int M;
    cin >> M;

    vector<int> C(M);
    for(int i = 0; i < M; i++) {
        cin >> C[i];
    }

    for(int i = 0; i < N; i++) {
        if(B[i] > A[i]) {
            cout << "NO" << '\n';
            return;
        }
    }

    vector<int> pre(N, -1);
    vector<int> nxt(N, N);

    vector<int> s;
    for(int i = 0; i < N; i++) {
        while(!s.empty() && B[s.back()] <= B[i]) {
            s.pop_back();
        }  

        if(!s.empty()) {
            pre[i] = s.back();
        }

        s.push_back(i);
    }

    s = vector<int>();
    for(int i = N - 1; i >= 0; i--) {
        while(!s.empty() && B[s.back()] <= B[i]) {
            s.pop_back();
        }  

        if(!s.empty()) {
            nxt[i] = s.back();
        }

        s.push_back(i);
    }

    map<int, set<pair<int, int>>> m;
    for(int i = 0; i < N; i++) {
        int l = pre[i] + 1;
        int r = nxt[i] - 1;
        if(A[i] == B[i]) continue;
        m[B[i]].insert({l, r});
    }

    map<int, int> r_m;
    for(int x : C) {
        r_m[x] += 1;
    }

    for(auto& [k, v] : m) {
        //cout << k << ' ' << v.size() << '\n';
        if(r_m.find(k) == r_m.end() || r_m[k] < v.size()) {
            //cout << k << '\n';
            cout << "NO" << '\n';
            return;
        }     
    }

    cout << "YES" << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        run_case();
    }
}
