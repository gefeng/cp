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

    int n = S.length();
    int ans = 0;
    for(int i = n - 1; i >= 0; i--) {
        if(S[i] == '0' && i > 0 && S[i - 1] == '0') {
            i -= 1;
        } 
        ans += 1;
    }
    
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
