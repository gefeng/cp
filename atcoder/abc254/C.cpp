#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    vector<bool> vis(N, false);
    for(int i = 0; i < N; i++) {
        if(vis[i]) {
            continue;
        }

        vector<int> v;
        for(int j = i; j < N; j += K) {
            vis[j] = true;
            v.push_back(A[j]);
        }

        sort(v.begin(), v.end());

        for(int j = i, k = 0; j < N; j += K, k++) {
            A[j] = v[k];
        }
    }

    for(int i = 1; i < N; i++) {
        if(A[i] < A[i - 1]) {
            cout << "No" << '\n';
            return;
        }       
    }

    cout << "Yes" << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
