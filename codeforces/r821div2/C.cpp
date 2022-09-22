#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int N;
    cin >> N;

    vector<int> A(N, 0);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    if(N == 1) {
        cout << 0 << '\n';
        return;
    }

    vector<pair<int, int>> seq; 

    seq.emplace_back(0, N - 1);
    if((A[0] + A[N - 1]) & 1) {
        A[N - 1] = A[0];
    } else {
        A[0] = A[N - 1];
    }

    for(int i = 1; i < N - 1; i++) {
        if((A[i] + A[0]) & 1) {
            seq.emplace_back(0, i);
        } else {
            seq.emplace_back(i, N - 1);
        }
    }

    int m = seq.size();
    cout << m << '\n';
    for(int i = 0; i < m; i++) {
        cout << seq[i].first + 1 << ' ' << seq[i].second + 1 << '\n';
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
