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

    LL T;
    cin >> T;

    vector<int> A(N);
    LL sum = 0LL;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        sum += A[i];
    }

    LL x = T % sum;
    LL ans_i = 0LL;
    LL ans_t = 0LL;
    for(int i = 0; i < N; i++) {
        if(A[i] > x) {
            ans_i = i + 1;
            ans_t = x;
        }

        x -= A[i];

        if(x <= 0) {
            break;
        }
    }

    cout << ans_i << ' ' << ans_t << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
