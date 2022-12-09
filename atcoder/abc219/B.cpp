#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    array<string, 3> A;
    for(int i = 0; i < 3; i++) {
        cin >> A[i];
    }

    string T;
    cin >> T;

    string ans = "";
    for(char c : T) {
        ans.append(A[c - '0' - 1]); 
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
