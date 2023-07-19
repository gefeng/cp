#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    int x = C - A;
    int y = D - B;
    if(y >= 0 && (x <= 0 || x <= y)) {
        cout << abs(x - y) + abs(y) << '\n';
    } else {
        cout << -1 << '\n';
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
