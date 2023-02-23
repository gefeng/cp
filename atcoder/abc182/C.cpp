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

    vector<int> digits;
    while(N) {
        digits.push_back(N % 10);
        N /= 10;
    }

    int sz = digits.size();
    int ans = sz + 1;
    for(int i = 1; i < (1 << sz); i++) {
        int cnt = 0;
        int sum = 0;
        for(int j = 0; j < sz; j++) {
            if(i & (1 << j)) {
                cnt += 1;
                sum += digits[j];
            }
        }

        if(sum % 3 == 0) {
            ans = min(ans, sz - cnt);
        }
    }

    cout << (ans == sz + 1 ? -1 : ans) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
