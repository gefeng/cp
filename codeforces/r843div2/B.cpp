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
    int N;
    cin >> N;

    vector<vector<int>> A(N);

    for(int i = 0; i < N; i++) {
        int K;
        cin >> K;
        A[i].resize(K, 0); 
        for(int j = 0; j < K; j++) {
            cin >> A[i][j];
        }
    }

    map<int, int> m;
    for(int i = 0; i < N; i++) {
        int k = A[i].size();
        for(int j = 0; j < k; j++) {
            m[A[i][j]] += 1;
        }
    }

    for(int i = 0; i < N; i++) {
        int k = A[i].size();
        bool can_rem = true;
        for(int j = 0; j < k; j++) {
            if(m[A[i][j]] == 1) {
                can_rem = false;
                break;
            } 
        }

        if(can_rem) {
            cout << "YES" << '\n';
            return;
        }
    }

    cout << "NO" << '\n';
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
