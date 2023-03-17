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

    int d = N % 10;
    string ans = "";
    if(d == 3) {
        ans = "bon";
    } else if(d == 0 || d == 1 || d == 6 || d == 8) {
        ans = "pon";
    } else {
        ans = "hon";
    }
   
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
