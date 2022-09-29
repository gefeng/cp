#include <iostream>

using namespace std;

void run_case() {
    string S;
    cin >> S;

    int n = S.length();
    int ans = 1;
    int cnt = 1;
    for(int i = 1; i < n; i++) {
        if(S[i] == S[i - 1]) {
            cnt++;
        } else {
            cnt = 1;
        }
        ans = max(ans, cnt);
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
