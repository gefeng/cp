#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

const string I = "URDL";

void run_case() {
    int H, W;
    cin >> H >> W;

    int RS, CS;
    cin >> RS >> CS;

    int N;
    cin >> N;

    vector<pair<int, int>> A(N, {0, 0});
    for(int i = 0; i < N; i++) {
        cin >> A[i].first >> A[i].second;
    }
    

    int Q;
    cin >> Q;
    vector<pair<int, int>> B(Q, {0, 0});
    for(int i = 0; i < Q; i++) {
        char C;
        cin >> C;
       
        B[i].first = I.find(C);
        cin >> B[i].second;
    }

    unordered_map<int, vector<int>> m_r;
    unordered_map<int, vector<int>> m_c;
    sort(A.begin(), A.end());
    for(auto& p : A) {
        m_r[p.first].push_back(p.second);
    }

    auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
        if(a.second == b.second) {
            return a.first < b.first;
        }
        return a.second < b.second;
    };
    sort(A.begin(), A.end(), cmp);
    for(auto& p : A) {
        m_c[p.second].push_back(p.first);
    }

    int r = RS;
    int c = CS;
    for(auto& q : B) {
        int d = q.first;
        int t = q.second;

        if(d == 0 || d == 2) {
            vector<int>& col = m_c[c];
            auto it = upper_bound(col.begin(), col.end(), r);

            if(d == 0) {
                if(it == col.begin()) {
                    r = max(1, r - t);
                } else {
                    r = max(*(it - 1) + 1, r - t);
                }
            } else {
                if(it == col.end()) {
                    r = min(H, r + t);
                } else {
                    r = min((*it) - 1, r + t);
                }
            }
        } else {
            vector<int>& row = m_r[r];
            auto it = upper_bound(row.begin(), row.end(), c);

            if(d == 1) {
                if(it == row.end()) {
                    c = min(W, c + t);     
                } else {
                    c = min((*it) - 1, c + t);
                }
            } else {
                if(it == row.begin()) {
                    c = max(1, c - t);
                } else {
                    c = max(*(it - 1) + 1, c - t);
                }
            }
        }

        cout << r << ' ' << c << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
