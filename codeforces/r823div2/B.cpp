#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

void run_case() {
    int N;
    cin >> N;

    vector<int> A(N, 0);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<int> B;
    B.reserve(2 * N);
    for(int i = 0; i < N; i++) {
        int T;
        cin >> T;
        B.push_back(A[i] - T);
        B.push_back(A[i] + T);
    }

    sort(B.begin(), B.end());

    double x = (double)(B[0] + B[2 * N - 1]) / 2;
    cout << setprecision(20) << x << '\n';
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
