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
    
    int n = S.length();
    char c = S[n - 1];
    if(c >= '0' && c <= '2') {
        cout << S.substr(0, n - 2) + "-" << '\n';
    } else if(c >= '3' && c <= '6') {
        cout << S.substr(0, n - 2) << '\n';
    } else {
        cout << S.substr(0, n - 2) + "+" << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
