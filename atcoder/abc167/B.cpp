#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int A, B, C, K;
    cin >> A >> B >> C >> K;

    int ans = 0;
    if(K <= A) {
        ans = K;
    } else if(K > A && K - A <= B) {
        ans = A;
    } else {
        ans = A - (K - A - B);
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
