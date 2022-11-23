#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

bool is_ok(int t) {
    string h = to_string(t / 60);
    string m = to_string(t % 60);
    if(h.size() == 1) {
        h = "0" + h;
    } 
    if(m.size() == 1) {
        m = "0" + m;
    }

    swap(h[1], m[0]);
    
    int hh = stoi(h);
    int mm = stoi(m);
    if(hh < 24 && mm < 60) {
        return true;
    }
    return false;
}

void run_case() {
    int H, M;
    cin >> H >> M;

    int t = H * 60 + M;
    while(true) {
        if(is_ok(t)) {
            cout << t / 60 << ' ' << t % 60 << '\n';
            return;
        } 
        t = (t + 1) % (60 * 24);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
