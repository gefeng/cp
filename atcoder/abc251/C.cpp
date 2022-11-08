#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

void run_case() {
    int N;
    cin >> N;

    vector<string> A(N);
    map<string, int> score_m;

    for(int i = 0; i < N; i++) {
        string S;
        cin >> S;

        int T;
        cin >> T;

        A[i] = S;
        if(score_m.find(S) == score_m.end()) {
            score_m[S] = T;
        }
    }

    int ans = 0;
    int max_v = 0;
    set<string> seen;
    for(int i = 0; i < N; i++) {
        string s = A[i];
        if(seen.find(s) == seen.end() && score_m[s] > max_v) {
            max_v = score_m[s];
            ans = i + 1;
        } 
        seen.insert(s);
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
