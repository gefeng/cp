#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int N, X;
    cin >> N >> X;

    string S;
    cin >> S;

    int ans = X;
    for(char c : S) {
        if(c == 'o') {
            ans += 1;
        } else {
            ans = max(0, ans - 1);
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
