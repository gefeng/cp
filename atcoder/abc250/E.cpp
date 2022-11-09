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
    vector<int> B(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        cin >> B[i];
    }

    int Q;
    cin >> Q;

    vector<pair<int, int>> C(Q);
    for(int i = 0; i < Q; i++) {
        cin >> C[i].first >> C[i].second;
    }

    set<int> s_1;
    set<int> s_2;
    vector<pair<int, int>> save(N, {-1, -1});
    for(int i = 0, l = 0, r = 0; i < N; i++) {
        s_1.insert(A[i]);
        while(l < N && s_2.find(A[i]) == s_2.end()) {
            s_2.insert(B[l++]);
        }

        if(s_2.find(A[i]) == s_2.end()) {
            break;
        }

        if(s_1.size() == s_2.size()) {
            save[i].first = l; 

            r = max(r, l);
            while(r < N && s_2.find(B[r]) != s_2.end()) {
                r += 1;
            }

            save[i].second = r;
        }
    }

    for(auto& q : C) {
        if(q.second >= save[q.first - 1].first && q.second <= save[q.first - 1].second) {
            cout << "Yes" << '\n';
        } else {
            cout << "No" << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
