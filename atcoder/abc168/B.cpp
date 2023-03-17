#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int K;
    cin >> K;

    string S;
    cin >> S;

    if(S.size() <= K) {
        cout << S << '\n';
    } else {
        string ans = S.substr(0, K) + "...";
        cout << ans << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
