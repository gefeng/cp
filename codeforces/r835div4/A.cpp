#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

bool is_m(int x, int y, int z) {
    if(y > z) {
        swap(y, z);
    }
    return x >= y && x <= z;
}

void run_case() {
    int A, B, C;
    cin >> A >> B >> C;
    
    if(is_m(A, B, C)) {
        cout << A << '\n';
        return;
    }
    if(is_m(B, A, C)) {
        cout << B << '\n';
        return;
    }
    if(is_m(C, B, A)) {
        cout << C << '\n';
        return;
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
