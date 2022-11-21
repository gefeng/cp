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

    int ans = 0;
    for(int i = 0; i < N; i++) {
        if(S[i] - 'a' > ans) {
            ans = S[i] - 'a';
        }
    }

    cout << ans + 1 << '\n';
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
