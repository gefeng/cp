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
    int sum = 0;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        sum += A[i];
    }

    for(int i = 1; i < N; i++) {
        if(A[i] == -1 && A[i - 1] == -1) {
            cout << sum + 4 << '\n';
            return;
        }
    }

    for(int i = 1; i < N; i++) {
        if(A[i] * A[i - 1] == -1) {
            cout << sum << '\n';
            return;
        }
    }

    cout << sum - 4 << '\n';
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
