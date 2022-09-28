#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int X, Y, Z;
    cin >> X >> Y >> Z;

    int ans = -1;
    if(X > 0) {
        if(Y > 0 && Y < X) {
            if(Z < Y) {
                ans = abs(Z);
                ans += abs(X - Z);
            }  
        } else {
            ans = X; 
        }
    } else {
        if(Y < 0 && Y > X) {
            if(Z > Y) {
                ans = abs(Z);
                ans += abs(X - Z);
            } 
        } else {
            ans = -X;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
