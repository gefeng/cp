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
    int N, Q;
    cin >> N >> Q;

    vector<int> A(N, 0);
    LL sum_eve = 0LL;
    LL sum_odd = 0LL;
    LL cnt_eve = 0LL;
    LL cnt_odd = 0LL;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        if(A[i] & 1) {
            sum_odd += A[i];
            cnt_odd++;
        } else {
            sum_eve += A[i];
            cnt_eve++;
        }
    }

    for(int i = 0; i < Q; i++) {
        int T, X;
        cin >> T >> X;

        if(T == 0) {
            if(X & 1) {
                sum_odd += sum_eve + cnt_eve * X;
                sum_eve = 0LL;
                cnt_odd = N;
                cnt_eve = 0LL;
            } else {
                sum_eve += X * cnt_eve;
            }
        } else {
            if(X & 1) {
                sum_eve += sum_odd + cnt_odd * X;
                sum_odd = 0LL;
                cnt_odd = 0LL;
                cnt_eve = N;
            } else {
                sum_odd += X * cnt_odd;
            }
        }

        cout << sum_odd + sum_eve << '\n';
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
