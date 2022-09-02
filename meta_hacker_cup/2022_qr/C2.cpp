#include <iostream>
#include <fstream>
#include <vector>
#include <array>
#include <string>

using namespace std;

ifstream in;
ofstream out;

void gen(string& cur, vector<string>& all) {
    if(cur.length() == 10) {
        all.push_back(cur);
        return;
    }
    
    cur.push_back('.');
    gen(cur, all);
    cur.pop_back();

    cur.push_back('-');
    gen(cur, all);
    cur.pop_back();
}

void run_case(int T) {
    int N;
    in >> N;
    
    string S;
    in >> S;

    vector<string> all;
    all.reserve(1 << 10);
   
    string cur = "";
    gen(cur, all);

    int cnt = N - 1;
    out << "Case #" << T << ":\n";
    for(string s : all) {
        if(S.length() > 10) {
            auto pos = S.rfind(s);
            if(pos == string::npos || pos != S.length() - 10) {
                out << s << '\n';
                cnt--;
            }
        } else {
            auto pos = s.rfind(S);
            if(pos == string::npos || pos != s.length() - S.length()) {
                out << s << '\n';
                cnt--;
            }
        }

        if(cnt == 0) {
            break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    in.open("input.txt");
    out.open("output.txt");

    int T;
    in >> T;
    for(int t = 1; t <= T; t++) {
        run_case(t);
    }

    in.close();
    out.close();
}
