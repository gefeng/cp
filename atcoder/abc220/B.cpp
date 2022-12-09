#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

LL to_10(string s, LL K) {
    LL res = 0LL;
    for(char c : s) {
        res *= K;
        res += c - '0';
    }
    return res;
}

void run_case() {
    int K;
    string A, B;
    cin >> K >> A >> B;

    cout << to_10(A, K) * to_10(B, K) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
