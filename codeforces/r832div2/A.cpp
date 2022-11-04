#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

void run_case() {
    int N;
    cin >> N;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    LL sum_1 = 0LL;
    LL sum_2 = 0LL;
    for(int i = 0; i < N; i++) {
        if(A[i] < 0) {
            sum_1 += A[i];
        } else {
            sum_2 += A[i];
        }
    }

    cout << abs(abs(sum_1) - sum_2) << '\n';
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
