#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    string S;
    cin >> S;

    for(int i = 0; i < S.size(); i++) {
        if(S[i] == '0') {
            S[i] = '1';
        } else {
            S[i] = '0';
        }
    }

    cout << S << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
