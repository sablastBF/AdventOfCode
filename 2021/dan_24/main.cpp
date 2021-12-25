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


vector<string> parse(string &v){
    vector<string> s;
    string str;
    for (int i = 0; i < v.size(); i++){
        if (v[i] == ' ') {
            if (str.size())
            s.push_back(str);
            str.clear();
        } else{ 
        str.push_back(v[i]);
        }
    }
    if (str.size())
        s.push_back(str);
    return s;
}

map<string, int> vk;

vector<int> do_f(vector<vector<string>> &str, vector<int> v){
    int sec = 0;
    for (int i = 1; i< str.size(); i++){
        //for (int i = 0 )
        if (str[i].back() >= "w" && str[i].back() <= "z"){
            sec = v[vk[str[i].back()]];
        } else {
            sec = stoi(str[i].back());
        }
        if (str[i][0] == "add"){
            v[vk[str[i][1]]] += sec;
        } else  if (str[i][0] == "mul") {
            v[vk[str[i][1]]] *= sec;
        } else  if (str[i][0] == "div"){
            if (sec == 0) return {-1};
            v[vk[str[i][1]]] /= sec;
        } else if (str[i][0] == "mod"){
            if (sec <= 0 ||  v[vk[str[i][1]]] < 0) return {-1};
            v[vk[str[i][1]]] %= sec;
        } else  if (str[i][0] == "eql"){
            v[vk[str[i][1]]] = (v[vk[str[i][1]]]  == sec);
        }
    }

    return v;
}

void pr(vector<int> &v){
    for (int i = 0; i < 4; i++){
        cout << v[i]<<" ";
    }
    cout << endl;
}

int main(){
    fstream f = fstream("in.txt");
    string line, kart;
    vector<vector<vector<string>>> fun;
    vector<vector<string>> v;

    while(getline(f,line)){
        if (line[0] == 'i'){
            if (v.size())
            fun.push_back(v);
            v.clear();
        } 
         v.push_back(parse(line));
    }
    fun.push_back(v);


    vk["w"] = 0;
    vk["x"] = 1;
    vk["y"] = 2;
    vk["z"] = 3;


    for (int i = 0; i < fun.size(); i++){
        for (int j = 0; j < fun[i].size(); j++){
            for (int z = 0; z < fun[i][j].size(); z++){
                cout << fun[i][j][z]<<" ";
            }
            cout << endl;
        }
        cout << endl;
    }
    cout << endl;

    int n = 1;
    vector<int> g;
    for (int n = 0; n < 1; n++){

        for (int i = 0; i <= 9; i++){
            for (int j = 0; j <= 9; j++){
                for (int z = 0; z <= 9; z++){
                    for (int k = 0; k <= 9; k++){

                        g=  do_f(fun.back(),{i,j,z,k});
                        if (g.size() != 4) continue;
                        if (g[3] != 0) continue;
                        cout << i<<" "<< j<<" "<< z << " "<<k << endl;
                        pr(g);
                    }
                }
            }
        }

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
