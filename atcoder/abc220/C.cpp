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

    LL X;
    cin >> X;

    LL sum = 0LL;
    for(int x : A) {
        sum += x;
    }

    LL a = X / sum;
    LL b = X % sum;
    LL ans = a * N;
    for(int i = 0; i < N; i++) {
        if(b < 0LL) {
            break;
        }
        b -= A[i];
        ans += 1LL;
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
