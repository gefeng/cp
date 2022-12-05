#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    string S, T;
    cin >> S >> T;

    if(S[0] == '#' && S[1] == '.' && T[0] == '.' && T[1] == '#') {
        cout << "No" << '\n';
        return;
    }
    if(S[0] == '.' && S[1] == '#' && T[0] == '#' && T[1] == '.') {
        cout << "No" << '\n';
        return;
    }

    cout << "Yes" << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
