#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int R1, C1, R2, C2;
    cin >> R1 >> C1 >> R2 >> C2;

    if(R1 == R2 && C1 == C2) {
        cout << 0 << '\n';
        return;
    }

    auto f = [](int a, int b, int c, int d) {
        return a + b == c + d || a - b == c - d || abs(a - c) + abs(b - d) <= 3;
    };

    if(f(R1, C1, R2, C2)) {
        cout << 1 << '\n';
        return;
    } 
    

    if((R2 + C2) % 2 == (R1 + C1) % 2) {
        cout << 2 << '\n';
        return;
    }

    for(int i = -4; i <= 4; i++) {
        for(int j = -4; j <= 4; j++) {
            int x = R1 + i;
            int y = C1 + j;
            if(f(R1, C1, x, y) && f(x, y, R2, C2)) {
                cout << 2 << '\n';
                return;
            }
        }
    }

    cout << 3 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
