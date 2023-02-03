#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

using namespace std;

void run_case() {
    int N;
    cin >> N;

    string S;
    cin >> S;

    set<char> s;
    vector<int> save(N, 0);
    for(int i = 0; i < N; i++) {
        s.insert(S[i]);
        save[i] = s.size();
    }

    int ans = 0;
    s = set<char>();
    for(int i = N - 1; i >= 0; i--) {
        s.insert(S[i]); 

        int l = i == 0 ? 0 : save[i - 1];
        int r = s.size();
        ans = max(ans, l + r);
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
