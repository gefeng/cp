#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int X;
    cin >> X;
    
    string s = to_string(X);
    string t = s;
    swap(t[0], t[2]);
    swap(t[0], t[1]);
    int y = stoi(t);

    t = s;
    swap(t[0], t[1]);
    swap(t[0], t[2]);
    int z = stoi(t);

    cout << X + y + z << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
