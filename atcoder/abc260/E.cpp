#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

using namespace std;
using LL = long long;

void run_case() {
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> A(N, {0, 0});
    for(int i = 0; i < N; i++) {
        cin >> A[i].first >> A[i].second;
    }
    
    vector<vector<int>> in_which(M + 1); 
    for(int i = 0; i < N; i++) {
        in_which[A[i].first].push_back(i);
        in_which[A[i].second].push_back(i);
    }

    vector<int> delta(M + 3, 0); // differ array
    int r = 1;
    int l_bound = M;
    for(pair<int, int>& p : A) {
        r = max(r, p.first);
        l_bound = min(l_bound, p.second);
    }

    for(int l = 1; l <= l_bound; l++) {
        delta[r - l + 1] += 1;
        delta[M - l + 2] -= 1;
        
        // shrink l 
        for(int p : in_which[l]) {
            r = max(r, A[p].second);
        }
    }

    for(int i = 1; i <= M; i++) {
        delta[i] += delta[i - 1];
        cout << delta[i] << " \n"[i == M];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
