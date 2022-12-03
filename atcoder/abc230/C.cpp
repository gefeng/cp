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
    LL N, A, B;
    cin >> N >> A >> B;

    LL P, Q, R, S;
    cin >> P >> Q >> R >> S;

    for(LL i = P; i <= Q; i++) {
        string s = "";
        for(LL j = R; j <= S; j++) {
            if(i - j == A - B || i + j == A + B) {
                s.push_back('#');
            } else {
                s.push_back('.');
            }
        }

        cout << s << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
