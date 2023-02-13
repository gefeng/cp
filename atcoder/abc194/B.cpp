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
    vector<int> B(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }

    int ans = 2e5;
    for(int i = 0; i < N; i++) {
        ans = min(ans, A[i] + B[i]);
    }

    for(int i = 0; i < N; i++) {
        int min_b = 2e5;
        for(int j = 0; j < N; j++) {
            if(i != j) {
                min_b = min(min_b, B[j]); 
            } 
        }

        ans = min(ans, max(A[i], min_b));
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
