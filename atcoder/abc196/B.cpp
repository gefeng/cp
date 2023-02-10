#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    string X;
    cin >> X;

    for(int i = 0; i < X.size(); i++) {
        if(X[i] == '.') {
            cout << X.substr(0, i) << '\n';
            return;
        } 
    }

    cout << X << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
