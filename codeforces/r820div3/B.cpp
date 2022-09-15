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
    string S;
    cin >> N >> S;

    string ans = "";
    for(int i = N - 1; i >= 0; i--) {
        int x = 0;
        if(S[i] == '0') {
            x = (S[i - 1] - '0') + 10 * (S[i - 2] - '0'); 
            i -= 2;
        } else {
            x = S[i] - '0';
        }

        ans.push_back((char)('a' + x - 1));
    }

    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        run_case();
    }
}
