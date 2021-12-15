#define el '\n'

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <queue>
using namespace std;

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


void print(vector<vector<int>> &mat){
    int k = 0; 
    for (int i = 0; i < mat.size(); i++){
        for (int j = 0; j < mat[0].size(); j++){
            //if (mat[i][j]) cout <<"#"; else cout <<'.';
            cout << mat[i][j]<<" ";
        }
        cout << endl;
    }
    //cout << k << endl;
}




int main(){
    fstream f = fstream("in_1.txt");
    string line;
    vector<vector<int>> dp;
    while(getline(f,line)){
        vector<int> v;
        for (int i = 0; i < line.size(); i++){
            v.push_back(line[i] - '0');
        }    
        dp.push_back(v);
        v.clear();
    }
    // vector<vector<int>> mat(dp.size(), vector<int>(dp[0].size()));
    // mat[0][0] = dp[0][0];
    // for (int i = 1; i < dp.size(); i++) mat[i][0] += mat[i -1][0] + dp[i][0]; 
    // for (int j = 1; j < dp[0].size(); j++) mat[0][j] += mat[0][j - 1] + dp[0][j]; 
    // for (int i = 1; i < dp.size(); i++){
    //     for (int j = 1; j < dp[i].size(); j++){
    //         mat[i][j] = min(mat[i - 1][j], mat[i][j - 1]) + dp[i][j];
    //     }
    // }
    // print(mat);
    set<pair<int, int>> st;
    priority_queue<pair<int, pair<int, int>>, std::vector<pair<int, pair<int, int>>>, std::greater<pair<int, pair<int, int>>>> q;
    q.push({0,{0, 0}});
    
    //vector<vector<int>> d(dp.size()*5, vector<int>(5*dp[0].size(),0));
    while (!q.empty()){
       
        pair<int, pair<int, int>>  w = q.top(); q.pop();
        int cost = w.first;
        int x = w.second.first;
        int y= w.second.second;
        //cout << x <<" "<< y << endl;
         if (st.count({x,y})) continue;
        if (x == 5*dp.size() - 1  && y == 5*dp[0].size() - 1) {
            cout << cost << endl;
            break;
        }
        st.insert({x,y});
        
        for (int i = -1; i <= 1; i++){
            for (int j = -1; j <= 1; j++){
                if (abs(i) == abs(j)) continue;
                if (x + i >= 0 && x + i < 5*dp.size() && y + j >= 0 && y + j < 5*dp[0].size()){
                    if (st.count({x + i , y + j})){
                        continue;
                    }   
                    
                    int ss = dp
                    [(x+i)% (dp.size()) ][ (y +j) % (dp[0].size())]+ (x+i) / dp.size()+ (j + y) /dp[0].size();
                    if (ss > 9) ss = ss % 10 + 1;
                    q.push({ss+ cost,{x + i,y + j}} );
                    //d[x + i][ j + y]  = ss;
                }
            }
        }
    }
    //print(d);

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
