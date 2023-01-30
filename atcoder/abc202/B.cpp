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

    string ans = "";
    for(char c : S) {
        if(c == '6') {
            ans.push_back('9');
        } else if(c == '9') {
            ans.push_back('6');
        } else {
            ans.push_back(c);
        }
    }

    reverse(ans.begin(), ans.end());

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
