#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

using namespace std;

void run_case() {
    int N;
    cin >> N;
 
    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
 
    vector<array<int, 3>> p;
    vector<array<int, 3>> q;
    set<int> s;
    for(int i = 0; i < N; i++) {
        if(s.find(A[i]) == s.end()) {
            s.insert(A[i]);
            p.push_back({A[i], A[i], i});
            q.push_back({1, A[i], i});
        } else {
            if(A[i] - 1 < 1) {
                cout << "NO" << '\n';
                return;
            }
 
            p.push_back({1, A[i] - 1, i});
            q.push_back({A[i], A[i], i});
        }
    }
 
    auto cmp = [](const auto& a, const auto& b) {
        return a[1] - a[0] < b[1] - b[0];
    };
    sort(p.begin(), p.end(), cmp);
    sort(q.begin(), q.end(), cmp);
 
    set<int> available;
    for(int i = 1; i <= N; i++) {
        available.insert(i);
    }
 
    vector<int> ans_p(N);
    for(int i = 0; i < N; i++) {
        int l = p[i][0];
        int r = p[i][1];
        if(r == l) {
            if(available.find(l) != available.end()) {
                ans_p[p[i][2]] = l;
                available.erase(l);
            } else {
                cout << "NO" << '\n';
                return;
            }
        } else {
            auto it = available.lower_bound(l); 
            if(it == available.end() || (*it) > r) {
                cout << "NO" << '\n';
                return;
            }
 
            ans_p[p[i][2]] = *it;
            available.erase(it);
        }
    }
 
    available = set<int>();
    for(int i = 1; i <= N; i++) {
        available.insert(i);
    }
 
    vector<int> ans_q(N);
    for(int i = 0; i < N; i++) {
        int l = q[i][0];
        int r = q[i][1];
        if(r == l) {
            if(available.find(l) != available.end()) {
                ans_q[q[i][2]] = l;
                available.erase(l);
            } else {
                cout << "NO" << '\n';
                return;
            }
        } else {
            auto it = available.lower_bound(l); 
            if(it == available.end() || (*it) > r) {
                cout << "NO" << '\n';
                return;
            }
 
            ans_q[q[i][2]] = *it;
            available.erase(it);
        }
    }
 
    cout << "YES" << '\n';
    for(int i = 0; i < N; i++) {
        cout << ans_p[i] << " \n"[i == N - 1];
    }
 
    for(int i = 0; i < N; i++) {
        cout << ans_q[i] << " \n"[i == N - 1];
    }
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
