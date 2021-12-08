#define el '\n'

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

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

int main(){

    fstream f = fstream("in_1.txt");
    string line;
 
    vector<string> bin;
    vector<string> dec;
    bool ok = 0;
    int sol = 0;
    vector<vector<string>> v,v2;
    while(getline(f,line)){
        string broj;

        for (int i = 0; i < line.size(); i++){
            if (line[i] == ' '){
                //cout << broj.size() << endl;
                if (ok){
                    sort(broj.begin(), broj.end());
                    if (broj.size())
                    dec.push_back(broj);
                    broj.clear();
                    continue;
                }
                sort(broj.begin(), broj.end());
                if (broj.size())
                bin.push_back(broj);
                broj.clear();
            } else if (line[i] == '|'){
                ok = 1;
                // broj.push_back(line[i]);
            } else {
                broj.push_back(line[i]);
            }
            // if (ok)
            // cout << broj << endl;
        }
        if (ok && (broj.size() == 2 || broj.size() == 3 || broj.size() == 4|| broj.size() == 7))
        sol++;
        ok = 0;
        sort(broj.begin(), broj.end());
        if (broj.size())
        dec.push_back(broj);
        broj.clear();
        v.push_back(bin);
        v2.push_back(dec);
        bin.clear();
        dec.clear();
    }

    vector<string> s6, s5;
    map<string, int> mp;
    vector<string> st(10);
    int soll = 0;

    for (int i = 0; i < v.size(); i++){
        for (int j = 0;j < v[i].size(); j++){
            if (v[i][j].size() == 2){
                mp[v[i][j]] = 1;
                st[1] = v[i][j];
            } else if(v[i][j].size() == 3){
                mp[v[i][j]] = 7;
                st[7] = v[i][j];
            } else if(v[i][j].size() == 4){
                mp[v[i][j]] = 4;
                st[4] = v[i][j];
            } else if(v[i][j].size() == 7){
                mp[v[i][j]] = 8; 
                st[8] = v[i][j];  
            } else if (v[i][j].size() == 6){
                
                s6.push_back(v[i][j]);
            } else {
                s5.push_back(v[i][j]);
            }
        }

        /// 6
        for (int j = 0; j < s6.size(); j++){
            if (cmp(s6[j], st[1]) == 1) mp[s6[j]] = 6;
            else 
            if (cmp(s6[j], st[4]) == 4) {mp[s6[j]] = 9; st[9] = s6[j];}
            else 
            mp[s6[j]] = 0;
        }


        /// 5
        for (int j = 0; j < s5.size(); j++){
            if (cmp(s5[j], st[9]) == 4) mp[s5[j]] = 2;
            else if (cmp(s5[j], st[1]) == 2) mp[s5[j]] = 3;
            else mp[s5[j]] = 5;
        }
    

        int k = 0;
        for (int j = 0; j < v2[i].size(); j++){
           k*= 10;
           k+= mp[v2[i][j]];
        }

        soll += k;
        s5.clear();
        s6.clear();
        st.clear();
        st.resize(10);
        mp.clear();
    }

    cout << soll << endl;
    
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
