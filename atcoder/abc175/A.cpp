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

    int ans = 1;
    if(S == "RRR") {
        ans = 3; 
    } else if(S == "RRS" || S == "SRR") {
        ans = 2;
    } else if(S == "SSS") {
        ans = 0;
    } else {
        ans = 1;
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
