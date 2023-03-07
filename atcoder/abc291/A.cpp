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

    int ans = 0;
    for(int i = 0; i < S.size(); i++) {
        if(S[i] >= 'A' && S[i] <= 'Z') {
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
