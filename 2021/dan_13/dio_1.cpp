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



class graf
{
private:
    /* data */
public:
    vector<string> smal, big;
    graf(/* args */){};
    ~graf();

};


map<string, graf *> mp;
int  sol = 0;
map<string, int> ok;
vector<vector<string>> sols;
vector<string> sss;
bool dva = 0;
string w;
void dfs(string &s){
    cout << s<<endl;
    if (s == "end") {sol++; sss.push_back(s); sols.push_back(sss); sss.pop_back(); return ;}
    sss.push_back(s);
   
    for (auto v: mp[s] -> big){
        dfs(v);
    }

    for (auto v: mp[s] -> smal){
        if (v == "start") continue;
        if (dva == 0){
            ok[v]++;
            if (ok[v] >= 2) {dva = 1; w = v;}
            dfs(v);
            ok[v]--;
            if (ok[v] < 2 && v == w) dva = 0;
        } else{
            if (ok[v]) continue;
            ok[v]++;
            dfs(v);
            ok[v]--;
        }
    }
    sss.pop_back();
    return ;
}

void print(vector<vector<bool>> &mat){
    int k = 0; 
    for (int i = 0; i < mat.size(); i++){
        for (int j = 0; j < mat[0].size(); j++){
            if (mat[i][j]) cout <<"#"; else cout <<'.';
        //    cout << mat[i][j];
        //     if (mat[i][j] ) k++;
        }
        cout << endl;
    }
    //cout << k << endl;
}



int main(){
    fstream f = fstream("int_2.txt");
    string line;

    vector<vector<bool>> mat(2000, vector<bool>(2000, 0));
    vector<pair<bool, int>> pii;
    bool ok = 0;
    int  x = 0, y = 0; 
    while(getline(f,line)){
    
        if (line.size() == 0){ ok = 1; continue;}
        if (ok == 0){
            vector<string> v = parse(line, ',');
            mat[stoi(v[1])][stoi(v[0])] = 1;
            x = max(x, stoi(v[1]));
            y = max(y, stoi(v[0]));
        } else {
            vector<string> v = parse(line, '=');
            pii.push_back({(v[0].back() == 'x'), stoi(v[1])});
        }
    }


    mat.resize(x + 1, vector<bool>(y + 1));
   
  vector<vector<bool>> ma;
    for (int i = 0; i <pii.size(); i++){
        ma = mat;
        if (pii[i].first){
            int k = pii[i].second;

            for (int x = 0; x < mat.size(); x++){
               for (int y = 0; y < mat[0].size(); y++){
                   if (y - k > 0 && 2*k - y >= 0){
                        ma[x][2*k - y] =   mat[x][y] + mat[x][2*k - y];
                        ma[x][y]= 0;
                   }else if (y - k == 0){
                    ma[x][y] = 0;
                   }
               }
                ma.resize(mat.size(), vector<bool>(k));

            }
        } else {
            int k = pii[i].second ;
            for (int x = 0; x < mat.size(); x++){
               for (int y = 0; y < mat[0].size(); y++){
                   if (x - k > 0 && 2*k - x >= 0){
                        ma[2*k - x][y] =  mat[x][y] + mat[2*k - x][y];
                         ma[x][y] = 0;
                   } else if (x == k){
                    ma[x][y] = 0;
                   }
               }
            }
            ma.resize(k, vector<bool>(mat[0].size()));
        }
        mat = ma;
       
    }
     print(mat);
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
