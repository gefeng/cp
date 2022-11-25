#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

LL f(LL a, LL b, LL c, LL d) {
    return (a - c) * (a - c) + (b - d) * (b - d);
} 

void run_case() {
    LL A, B, C, D;
    cin >> A >> B >> C >> D;

    for(int i = -1; i < 2; i += 2) {
        for(int j = -2; j < 5; j += 4) {
            if(f(A + i, B + j, C, D) == 5LL) {
                cout << "Yes" << '\n';
                return;
            } 
        }
    }

    for(int i = -2; i < 5; i += 4) {
        for(int j = -1; j < 2; j += 2) {
            if(f(A + i, B + j, C, D) == 5LL) {
                cout << "Yes" << '\n';
                return;
            } 
        }
    }
    cout << "No" << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
