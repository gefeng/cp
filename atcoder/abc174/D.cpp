#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int N;
    cin >> N;

    string S;
    cin >> S;

    for(int i = 0; i < N; i++) {
        if(S[i] == 'R') {
            S[i] = '1';
        } else {
            S[i] = '0';
        }
    }

    string t = S;
    sort(t.begin(), t.end(), greater<int>());

    int ans = 0;
    for(int i = N - 1; i >= 0; i--) {
        if(t[i] == '0' && t[i] != S[i]) {
            ans += 1;
        } 
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
