#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

using namespace std;

void run_case() {
    int N;
    cin >> N;

    set<string> s;
    for(int i = 0; i < N; i++) {
        string S;
        cin >> S;

        s.insert(S);
    }

    cout << s.size() << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
