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

void pr( vector<vector<char>> &mp){
    for (int i = 0; i < mp.size(); i++){
        for (int j = 0; j < mp[i].size(); j++){
            cout << mp[i][j];
        }
        cout << endl;
    }
    cout << endl;
}


int main(){
    vector<vector<char>> mp;
    string line;
    fstream f = fstream("in.txt");
    vector<char> c;
    while (getline(f,line)){
        for (int i= 0 ; i < line.size(); i++){
            c.push_back(line[i]);
        }
        mp.push_back(c);
        c.clear();
    }

    int n = mp.size(), m = mp[0].size();
    bool ok = 1;    
    int sol = 0;
    while(ok){
        ok = 0;
        sol++;
        vector<vector<char>> pm (n, vector<char>(m, '.'));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (mp[i][j] == '>' && mp[i][(j + 1) % m] == '.'){
                    pm[i][j] = '.';
                    pm[i][(j + 1) % m] = '>';
                    j++;
                    ok = 1;
                } else {
                    pm[i][j] = mp[i][j];
                }
                
            }
        }
       mp = pm;
        for (int j = 0; j < m; j++){
            for (int i = 0; i < n; i++){
                if (mp[i][j] == 'v' && mp[(i + 1)%n][j] == '.'){
                    pm[(i + 1)%n][j] = 'v';
                    pm[i][j] = '.';
                    ok = 1;
                    i++;
                } else {
                    pm[i][j] = mp[i][j];
                }
            }
        }
        mp = pm;
        cout << sol << endl;
        //pr(mp);
    }
    
    cout << sol << endl;
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
