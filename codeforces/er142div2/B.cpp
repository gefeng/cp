#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    array<int, 4> A{0};
    
    for(int i = 0; i < 4; i++) {
        cin >> A[i];
    }

    if(A[1] > A[2]) {
        swap(A[1], A[2]);
    }

    int ans = A[0];
    int a = A[0];
    int b = A[0];
    int d = min(A[1], A[2]);

    if(a) {
        A[1] -= d;
        A[2] -= d;
        ans += 2 * d;
    }

    d = min(a, A[2]);
    ans += d;
    a -= d;
    b += d;
    A[2] -= d;

    d = min(min(a, b) + 1, A[2] + A[3]);
    ans += d;

    cout << ans << '\n';
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
