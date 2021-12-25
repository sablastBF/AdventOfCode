#define el '\n'

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <queue>
#include <climits>
using namespace std;

vector<int> parse(string &v, char del){
    vector<int> sol;
    string s;
    for (int i = 0; i < v.size(); i++){
        if (v[i] == del){
            cout << s << endl;
            if (s.length())
            sol.push_back(stoi(s));
            s.clear();
        } else{
            s.push_back(v[i]);
        }
    }
     if (s.length())
    sol.push_back(stoi(s));
    return sol;
}
void pr(vector<pair<int,int>> &v){
    int x_min = INT_MAX,x_max = 0,y_min = INT_MAX,y_max = 0;
     for (auto [x,y]: v){
            x_min = min(x_min, x);
            x_max = max(x_max, x);
            y_min = min(y_min, y);
            y_max = max(y_max, y);
        }
    x_min = -x_min;
    y_min = -y_min;
    vector<vector<char>> c(x_max + x_min + 1, vector<char>(y_max + y_min + 1,'.'));
    for (auto [x,y]: v){
            c[x + x_min][y + y_min] = '#'; 
        }
    for (int i = 0; i < c.size(); i++){
        for (int j = 0; j < c[i].size(); j++){
            cout << c[i][j];
        }
        cout << endl;
    }
}


int main(){
    fstream f = fstream("in_1.txt");
    string line, kart;
    bool first_line = 0;
    set<pair<int, int>> st;
    vector<pair<int, int>> v;
    int x = 0;
    int x_min = INT_MAX,x_max = 0,y_min = INT_MAX,y_max = 0;

    while(getline(f,line)){
        if (first_line == 0){
            first_line = 1;
            kart = line;
        } else {
            for (int y = 0; y < line.size(); y++){
                if (line[y] == '#') {

                    st.insert({x,y});
                    v.push_back({x,y});
                }
            }
            x++;
        }
    }
    int n = 50;
    set<pair<int, int> > st_next;
    vector<pair<int, int>> v_next;
    bool taraba = 1;
    for (int q = 0; q < n; q++){
        for (int i = 0; i < v.size(); i++){
            for (int x1 = -1;x1 <= 1; x1++){
                for (int y1 = -1; y1 <= 1; y1++){
                    int X = v[i].first + x1, Y = v[i].second + y1;
                    int broj = 0;
                    for (int y2 = -1; y2 <= 1; y2++){
                            for (int x2 = -1; x2 <= 1; x2++){
                                int nx = X + y2, ny = Y + x2;
                                broj = broj * 2;
                                if (taraba && st.count({nx,ny})){
                                broj += 1; // uvjek ako je #
                                }
                                else if (!taraba && st.count({nx,ny}) == 0)broj += 1;
                                
                            }
                        }
                        //zavisi o iducoj iteraciji i zadatku
                    if ((kart[broj] == '#' && !taraba) || (kart[broj] == '.' && taraba) ) {
                        if (st_next.count({X,Y}) == 0){
                            st_next.insert({X,Y});
                            v_next.push_back({X,Y});
                        }
                    }
                }
            }
        }
        st.clear();
        v.clear();
        st = st_next;
        v = v_next;
        //pr(v);
        st_next.clear();
        v_next.clear();
      
        if (taraba == 1){
            taraba = (kart[0] == '.');
        } else {
            taraba = (kart.back() == '.');   
        }
        cout << taraba << endl;
        cout << v.size() << endl;
    }
    
    return 0;
}


/*
//
//             *
//                               *
//                         *  _|_
//                         .-' * '-. *
//                        /       * \
//                     *  ^^^^^|^^^^^
//                         .~. |  .~.
//                        / ^ \| / ^ \
//                       (|   |J/|   |)
//                       '\   /`"\   /`
//             -- '' -'-'  ^`^    ^`^  -- '' -'-'
*/
