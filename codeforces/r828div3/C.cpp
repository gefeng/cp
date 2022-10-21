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
    char C;
    cin >> N >> C;

    string S;
    cin >> S;

    int last_g = -1;
    for(int i = 0; i < N; i++) {
        if(S[i] == 'g') {
            last_g = i;
            break;
        }
    }

    int ans = 0;
    for(int i = N - 1; i >= 0; i--) {
        if(S[i] == 'g') {
            last_g = i;
        }
        if(S[i] == C) {
            if(last_g < i) {
                ans = max(ans, last_g - i + N);
            } else {
                ans = max(ans, last_g - i);
            }
        }
    }

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
