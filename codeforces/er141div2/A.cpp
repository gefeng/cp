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

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    vector<int> ans(N);
    if(N % 2 == 0) {
        for(int i = 0, j = 0; j < N; i += 1, j += 2) {
            ans[j] = A[i];
        }

        for(int i = N - 1, j = 1; j < N; i -= 1, j += 2) {
            ans[j] = A[i];
        }
    } else {
        for(int i = 0, j = 0; j < N; i += 1, j += 2) {
            ans[j] = A[i];
        }

        for(int i = N - 1, j = 1; j < N; i -= 1, j += 2) {
            ans[j] = A[i];
        }
    }

    int sum = 0;
    for(int i = 0; i < N; i++) {
        if(sum == ans[i]) {
            cout << "NO" << '\n';
            return;
        } 
        sum += ans[i];
    }

    cout << "YES" << '\n';
    for(int i = 0; i < N; i++) {
        cout << ans[i] << " \n"[i == N - 1];
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
