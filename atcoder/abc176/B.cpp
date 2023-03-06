#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    string N;
    cin >> N;

    int sum = 0;
    for(char c : N) {
        sum += c - '0'; 
    }

    cout << (sum % 9 == 0 ? "Yes" : "No") << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
