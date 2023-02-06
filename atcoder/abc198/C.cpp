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
    double R, X, Y;
    cin >> R >> X >> Y;
    
    double d = sqrt(X * X + Y * Y);

    
    if(d < R) {
        cout << 2 << '\n'; 
    } else {
        cout << ceil(d / R) << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
