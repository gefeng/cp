#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    array<int, 26> A{0};
    for(int i = 0; i < 26; i++) {
        cin >> A[i];
        A[i] -= 1;
    }

    string ans = "";
    for(int i = 0; i < 26; i++) {
        ans.push_back((char)(A[i] + 'a'));
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
