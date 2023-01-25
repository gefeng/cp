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

    string ans = "";
    for(int i = 0; i < N; i++) {
        if(S[i] == 'n' && i + 1 < N && S[i + 1] == 'a') {
            ans.append("nya");
            i += 1;
        } else {
            ans.push_back(S[i]);
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
