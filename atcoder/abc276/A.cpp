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

    int ans = -1;
    for(int i = S.length() - 1; i >= 0; i--) {
        if(S[i] == 'a') {
            ans = i + 1;
            break;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
