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





int main(){
    fstream f = fstream("in_1.txt");
    string line;


    while(getline(f,line)){
        vector<string> v = parse(line, '-');
        cout << v[0]<<" "<< v[1]<<endl;
        if (mp.find(v[0]) == mp.end()) {
            mp[v[0]] = new graf();
        }
        if (mp.find(v[1]) == mp.end()) {
            mp[v[1]] = new graf();
        }

        if (v[1][0] >= 'a' and v[1][0] <= 'z')
        mp[v[0]] -> smal.push_back(v[1]);
        else
        mp[v[0]] -> big.push_back(v[1]);

        if (v[0][0] >= 'a' and v[0][0] <= 'z')
        mp[v[1]] -> smal.push_back(v[0]);
        else
        mp[v[1]] -> big.push_back(v[0]);
        ok[v[0]] = 0;
        ok[v[1]] = 0;

    }

    string ss = "start", s = "end";
    ok[ss] = 3;
    ok[s] = 0;
    dfs(ss);

    set<vector<string>> vv;
    for (int i = 0; i < sols.size(); i++){
        vv.insert(sols[i]);
        for (int j = 0; j < sols[i].size(); j++){
            cout << sols[i][j]<<",";
        }
        cout << endl;
    }
    cout << vv.size() <<" "<< sol << endl;
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
