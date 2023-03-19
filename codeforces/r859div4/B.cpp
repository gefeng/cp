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

    int sum = 0;
    int sum_eve = 0;
    for(int i = 0; i < N; i++) {
        sum += A[i];
        if(A[i] % 2 == 0) {
            sum_eve += A[i];
        }
    }

    bool ans = sum_eve > sum - sum_eve;
    cout << (ans ? "YES" : "NO") << '\n';
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
