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
    LL N;
    cin >> N;

    string ans = "";
    while(N > 0) {
        N -= 1;
        ans.push_back((char)(N % 26 + 'a'));
        N /= 26LL;
    }

    reverse(ans.begin(), ans.end());

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
