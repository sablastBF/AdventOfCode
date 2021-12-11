#define el '\n'

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <set>

using namespace std;

int cmp(string &s1, string &s2){
    int x = 0, y = 0;
    int sol = 0;
    while (x < s1.length() && y < s2.length()){
        if (s1[x] == s2[y]) {sol++; x++; y++;}
        else if (s1[x] < s2[y]) x++;
        else y++;
    }

    return sol;
}

vector<string> parse(string &v, char del){
    vector<string> sol;
    string s;
    for (int i = 0; i < v.size(); i++){
        if (v[i] == del){
            if (s.length())
            sol.push_back(s);
            s.clear();
        } else{
            s.push_back(v[i]);
        }
    }
    sol.push_back(s);
    return sol;
}

void print(vector<string> &s){
    for (int i = 0; i < s.size();i++){
        cout << s[i] << " ";
    }
    cout << el;
}

vector<int> X = {1, -1, 0, 0}, Y = {0, 0, 1, -1};
int counttt  = 0;
int fsol = 0;
set<pair<int, int>> st;
void dfs(vector<string> &v, int x, int y){
    if (st.count({x,y})) return;
    st.insert({x,y});
   if (x >= 0 && x < v.size() && y >= 0 && y < v[0].size()){
       if (v[x][y] != '9') counttt++;
       else return;
       for (int z = 0; z < 4;z++){
           dfs(v, x+ X[z], y + Y[z]);
       }

   }

   return ;
}
int main(){

    fstream f = fstream("in.txt");
    string line;
 
    vector<string> bin;
    vector<string> dec;
    bool ok = 0;
    int sol = 0;
    vector<string> v;

    while(getline(f,line)){
        v.push_back(line);
    }
    int soll = 0;
    vector<int> sss;
    for (int i = 0; i < v.size(); i++){
        for (int j = 0; j < v[i].size(); j++){
            bool notok = 0;
            for (int z = 0; z < 4; z++){
            
                int nx = i+ X[z], ny =  j+  Y[z];
                if (nx >= 0 && nx < v.size() && ny >= 0 && ny < v[0].size()){
                    if (v[nx][ny] <= v[i][j]){
                        notok = 1;
                        break;
                    }
                }
            }
            if (!notok){
                dfs(v, i,j);
                sss.push_back(counttt);
                counttt = 0;               
            }
        }
    }
    sort(sss.begin(), sss.end());
    int kk = 1;
    for (int i = sss.size() -3 ; i < sss.size(); i++){
        cout << sss[i] << endl;
        kk *= sss[i];
    }
    cout << kk << endl;
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
