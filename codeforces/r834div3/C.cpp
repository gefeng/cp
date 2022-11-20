#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int L, R, X, A, B;
    cin >> L >> R >> X >> A >> B;
    
    if(A > B) {
        swap(A, B);
    }

    if(A == B) {
        cout << 0 << '\n';
        return;
    }

    if(abs(A - B) >= X) {
        cout << 1 << '\n';
        return;
    }

    if(A - L >= X && B - L >= X) {
        cout << 2 << '\n';
        return;
    }

    if(R - A >= X && R - B >= X) {
        cout << 2 << '\n';
        return;
    }

    if(A - L >= X && R - L >= X && R - B >= X) {
        cout << 3 << '\n';
        return;
    }

    if(R - A >= X && R - L >= X && B - L >= X) {
        cout << 3 << '\n';
        return;
    }

    cout << -1 << '\n';
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
