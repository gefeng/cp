#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int A, B;
    cin >> A >> B;

    int d = min(abs(A), abs(B));
    int ans = d * 2;
    
    if(abs(A) - d > 0) {
        ans += 1 + (abs(A) - d - 1) * 2;
    } else if(abs(B) - d > 0) {
        ans += 1 + (abs(B) - d - 1) * 2;
    }

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
