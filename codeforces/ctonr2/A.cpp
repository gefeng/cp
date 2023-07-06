#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void run_case() {
    int N, M;
    cin >> N >> M;

    string s, t;
    cin >> s >> t;

    bool ans = false;
    for(int i = 0; i <= N - M; i++) {
        if(s[i] == t[0]) {
            ans = true;
            break;
        }
    }

    if(ans) {
        for(int i = 1; i < M; i++) {
            if(s[i + N - M] != t[i]) {
                ans = false;
                break;
            }
        }
    }

    cout << (ans ? "YES" : "NO") << '\n';
}

int main() {
    ios::sync_with_stdio(false);        // de-sync with c stream
    cin.tie(0);                         // disable flushing of std::cout
    
    int t = 0;
    cin >> t;
    while(t--) {
        run_case();
    }
}
