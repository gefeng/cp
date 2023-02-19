#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int N, K;
    cin >> N >> K;

    string S;
    cin >> S;

    string ans = "";
    for(int i = 0; i < N; i++) {
        if(S[i] == 'o') {
            if(K) {
                ans.push_back('o');
                K -= 1;
            } else {
                ans.push_back('x');
            }
        } else {
            ans.push_back('x');
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
