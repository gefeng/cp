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

    string s = "ABCDEF";
    
    string ans;
    while(N) {
        int hex_d = N % 16;
        if(hex_d > 9) {
            ans.push_back(s[hex_d - 10]);
        } else {
            ans.push_back((char)(hex_d + '0'));
        }
        N /= 16;
    }

    while(ans.size() != 2) {
        ans.push_back('0');
    }

    reverse(ans.begin(), ans.end());

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
