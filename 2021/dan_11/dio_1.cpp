#define el '\n'

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <set>

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

  vector<int> X = {1, -1, 0, 0, 1, 1, -1, -1}, 
              Y = {0, 0, 1, -1, 1, -1, -1, 1};

set<pair<int, int>> st;
int  flash = 0;
void dfs(vector<vector<int>> &mat, int x, int y){
    if (st.count({x,y})) return;
     flash++;
    st.insert({x,y});
     mat[x][y]++;
    for (int i = 0; i < 8; i++){
        int nx = x + X[i], ny = y + Y[i];
        if (nx >= 0 && nx < mat.size() && ny >= 0 && ny < mat[0].size()){
            mat[nx][ny]++;
            if (mat[nx][ny] > 9){
               
                dfs(mat, nx, ny);
            } 
        }
    }
}


int main(){
    fstream f = fstream("in_1.txt");
    string line;



    vector<string> v;
    vector<vector<int>> mat;
    vector<int> w;
    while(getline(f,line)){
        v.push_back(line);

        for (int i = 0; i < line.size(); i++){
            w.push_back(line[i] - '0');
        }
        mat.push_back(w);
        w.clear();
    }

     vector<vector<int>> mat2;
   
    int t = 500;
    while(t--){
         mat2 = mat;
    for (int i = 0; i < mat.size(); i++){
        for (int j = 0; j < mat[i].size(); j++){
            mat2[i][j] += 1;
        }        
    }
    st.clear();
    for (int i = 0; i < mat.size(); i++){
        for (int j = 0; j < mat[i].size(); j++){
            if (mat2[i][j] > 9){
                dfs(mat2, i, j);
            }
        }        
    }
    int count = 0;
    for (int i = 0; i < mat.size(); i++){
        for (int j = 0; j < mat[i].size(); j++){
            if (mat2[i][j] > 9){
                mat2[i][j] = 0;
                count++;
            }   
        }        
    }
  
    mat = mat2;
    mat2.clear();
    cout << 500 - t << endl;
    for (int i = 0; i < mat.size(); i++){
        for (int j = 0; j < mat[0].size(); j++){
            cout << mat[i][j]<<" ";
        }
        cout << el;
    }
      if (count == mat.size() * mat[0].size()) break;
    }
    cout <<  flash << endl;


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
