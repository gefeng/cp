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
    LL A, S;
    cin >> A >> S;

    if(S < A) {
        cout << "No" << '\n';
        return;
    }

    int carry = 0;
    for(LL i = 0LL; i < 60LL; i++) {
        if(A & (1LL << i)) {
            if(S & (1LL << i)) {
                if(carry == 0) {
                    cout << "No" << '\n';
                    return;
                }
            } else {
                if(carry == 1) {
                    cout << "No" << '\n';
                    return;
                }
            }
            carry = 1;
        } else {
            if(S & (1LL << i)) {
                carry = 0; 
            }
        }
    }

    cout << "Yes" << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--) {
        run_case();
    }
}
