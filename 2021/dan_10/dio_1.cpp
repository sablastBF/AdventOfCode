#define el '\n'

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <set>

using namespace std;
vector<int> X = {1, -1, 0, 0}, Y = {0, 0, 1, -1};

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


int main(){
    fstream f = fstream("in_1.txt");
    string line;



    vector<string> v;

    while(getline(f,line)){
        v.push_back(line);
    }

//     ): 3 points.
// ]: 57 points.
// }: 1197 points.
// >    
    map<char, int> mp;
      map<char, int> ss;
   
 

    vector<vector<char>> sol;
    vector<char> vv;
    for (int i = 0; i < v.size(); i++){
        cout << v[i]<< endl;
        vector<char> c;
        vv.clear();
        for (int j = 0; j < v[i].size(); j++){

            if (v[i][j] == '(' || v[i][j] == '[' || v[i][j] == '{' || v[i][j] == '<') c.push_back(v[i][j]);
            else {
                if (c.size() && ((v[i][j] == ')' && c.back() == '(') || (v[i][j] == ']' && c.back() == '[') ||  (v[i][j] == '}' && c.back() == '{') ||  (v[i][j] == '>' && c.back() == '<'))){
                    c.pop_back();
                } else {
                    c.clear();
                    break;
                    while(c.size() && !((v[i][j] == ')' && c.back() == '(') || (v[i][j] == ']' && c.back() == '[') ||  (v[i][j] == '}' && c.back() == '{') ||  (v[i][j] == '>' && c.back() == '<'))){
                        cout << c.back()<<" "<< v[i][j]<<endl;
                        vv.push_back(c.back());
                        c.pop_back();
                    }
                    cout << i<<" "<< v[i][j]<<" "<< c.back() << endl;
                    ss[v[i][j]]++;
                }
            }
        }
        while (c.size()){
             vv.push_back(c.back());
            c.pop_back();
        }
        
        if (vv.size())
        sol.push_back(vv);
        c.clear();
    }
    mp['('] = 1;
    mp['['] = 2;
    mp['{'] = 3;
    mp['<'] = 4;

    vector<long> ww;
    long w = 0;
    for (int i = 0; i < sol.size(); i++){
        w = 0;
        for (int j = 0; j < sol[i].size(); j++){
          w*=5;
          w+=mp[sol[i][j]];
          cout << sol[i][j]<< " ";
        }
        cout << endl;
        cout << w << endl;
        ww.push_back(w);
        cout << endl;
    }
    sort(ww.begin(), ww.end());
    cout << ww[ww.size() / 2]<< endl;
    //cout << sol << endl;
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
