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
    int A, B, C, X;
    cin >> A >> B >> C >> X;

    double ans = 0.0;
    if(X <= A) {
        ans = 1.0; 
    } else if(X > A && X <= B) {
        ans = (double)C / (B - A);
    } else {
        ans = 0.0;
    }

    cout << setprecision(19) << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
