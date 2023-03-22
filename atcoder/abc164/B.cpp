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

    int t = 0;
    while(true) {
        if(t == 0) {
            C -= B;
            if(C <= 0) {
                break;
            }
        } else {
            A -= D;
            if(A <= 0) {
                break;
            }
        }
        t ^= 1;
    }

    if(A <= 0) {
        cout << "No" << '\n';
    } else {
        cout << "Yes" << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
