#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int N;
    cin >> N;

    int x = 0;
    int y = 0;
    int z = 1;
    int diff = 0;
    while(N) {
        int d = N % 10;

        if(d % 2 == 0) {
            x += z * (d / 2);
            y += z * (d / 2);
        } else {
            if(diff == 0) {
                x += z * ((d + 1) / 2);
                y += z * (d / 2);
                diff += 1;
            } else {
                x += z * (d / 2);
                y += z * ((d + 1) / 2);
                diff -= 1;
            }
        }

        N /= 10;
        z *= 10;
    }
    
    cout << x << ' ' << y << '\n';
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
