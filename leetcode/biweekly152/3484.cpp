#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

class Spreadsheet {
public:
    std::vector<std::vector<int>> a;
    
    Spreadsheet(int rows) {
        a.resize(rows, std::vector<int>(26, 0));
    }
    
    void setCell(std::string cell, int value) {
        auto [r, c] = to_coord(cell);
        a[r][c] = value;
    }
    
    void resetCell(std::string cell) {
        auto [r, c] = to_coord(cell);
        a[r][c] = 0;
    }
    
    int getValue(std::string formula) {
        std::string sx = "";
        std::string sy = "";
        int x = 0;
        int y = 0;
        
        int n = formula.size();
        int p = 1;
        while(formula[p] != '+') {
            sx.push_back(formula[p++]);
        }
        p += 1;
        while(p != n) {
            sy.push_back(formula[p++]);
        }
        
        if(sx[0] >= 'A' && sx[0] <= 'Z') {
            auto [r, c] = to_coord(sx);
            x = a[r][c];
        } else {
            x = stoi(sx);    
        }
        
        if(sy[0] >= 'A' && sy[0] <= 'Z') {
            auto [r, c] = to_coord(sy);
            y = a[r][c];
        } else {
            y = stoi(sy);
        }
        
        return x + y;
    }
    
    std::pair<int, int> to_coord(std::string& s) {
        int c = s[0] - 'A';
        int r = stoi(s.substr(1, s.size() - 1)) - 1;
        return {r, c};
    }
};
