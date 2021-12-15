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
        //     if (mat[i][j] ) k++;
        }
        cout << endl;
    }
    //cout << k << endl;
}



int main(){
    fstream f = fstream("in_1.txt");
    string line;

    vector<vector<bool>> mat(2000, vector<bool>(2000, 0));
    vector<pair<bool, int>> pii;
    bool ok = 0;
    string p;
    int  x = 0, y = 0; 
    map<string, string> mp;
    map<string, long long> ma, mm;
    string s;
    while(getline(f,line)){
    
        if (line.size() == 0){ ok = 1; continue;}
        if (ok == 0){
           p = line;
        } else {
            vector<string> v = parse(line, '-');
            
            s.clear();
            s.push_back(v[1].back());
            v[0].pop_back();
            mp[v[0]] = s;

        }
    }
    s.clear();
    for (int i = 0; i < p.length() - 1; i++){
        s.push_back(p[i]);
        s.push_back(p[i+ 1]);
        ma[s]++;
        s.clear();
    }

    int n = 40;
    string ne;
    while(n--){
        for (auto [key, val]: ma){
            string s1, s2;
            s1.push_back(key[0]); s1.push_back(mp[key][0]);
            s2.push_back(mp[key][0]); s2.push_back(key[1]);

            mm[s1] += ma[key];
            mm[s2]+= ma[key];
        }
        ma = mm;
        mm.clear();
          for (auto [key, val]: ma){
              cout << key << " "<< val << endl;
          }
          cout << endl;
       // cout << p << endl;
    }
    vector< long long> v(26, 0);
    for (auto [key, val]: ma){
        cout << key[0]<<" "<< key[1]<<endl;
        v[key[1] - 'A']+=val;
    }
  
    long long  M = 0, m = 9223372036854775807;
    for (int i = 0; i < v.size(); i++){
        M = max(v[i], M);
        if (v[i] != 0)
        m = min(v[i], m);
    }
    cout << M<<" "<<m<<" "<<M - m << endl;
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
