#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int N, X;
    cin >> N >> X;

    vector<int> A(N);
    vector<int> B(N);
   
    for(int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }

    int sum = 0;
    for(int i = 0; i < N; i++) {
        sum += A[i] * B[i];
        if(sum > X * 100) {
            cout << i + 1 << '\n';
            return;
        }
    }

    cout << -1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
