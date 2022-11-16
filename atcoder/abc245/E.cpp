#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

using namespace std;

void run_case() {
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i].first;
    }

    for(int i = 0; i < N; i++) {
        cin >> A[i].second;
    }

    vector<pair<int, int>> B(M);
    for(int i = 0; i < M; i++) {
        cin >> B[i].first;
    }

    for(int i = 0; i < M; i++) {
        cin >> B[i].second;
    }
    
    sort(A.begin(), A.end(), greater<pair<int, int>>());
    sort(B.begin(), B.end(), greater<pair<int, int>>());

    map<int, int> m;
    for(int i = 0, j = 0; i < N; i++) {
        while(j < M && B[j].first >= A[i].first) {
            m[B[j++].second] += 1;
        } 

        auto it = m.lower_bound(A[i].second);
        if(it == m.end()) {
            cout << "No" << '\n';
            return;
        }

        if(--(it->second) == 0) {
            m.erase(it);
        } 
    }

    cout << "Yes" << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
