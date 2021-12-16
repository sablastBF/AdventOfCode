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
    for (long long i = 0; i < v.size(); i++){
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
    long long k = 0; 
    for (long long i = 0; i < mat.size(); i++){
        for (long long j = 0; j < mat[0].size(); j++){
            //if (mat[i][j]) cout <<"#"; else cout <<'.';
            cout << mat[i][j]<<" ";
        }
        cout << endl;
    }
    //cout << k << endl;
}

map<string, string> mp;


string hex_to_bi(string &s){
    string sol;
    for (long long i = 0; i < s.length(); i++){
        string ss;
        ss.push_back(s[i]);
        sol.append(mp[ss]);
    }

    return sol;
}

long long string_to_int(string &s){
    long long sol = 0;
    long long k = 1;
    for (long long i = s.length() -1; ~i; i--){
        if (s[i] == '1') sol+=k;
        k = k << 1;
    }

    return sol;
}


long long sol1 = 0;
long long inx = 0;

long long ff(string &s){
    cout << s <<" "<< inx <<  endl;
    string ver = s.substr(inx, 3); inx += 3;
    string id = s.substr(inx, 3); inx += 3;
    long long ver_val = string_to_int(ver), id_val = string_to_int(id);
    sol1 += ver_val;

    // literal
    vector<long long> vals;
    if (id_val == 4){
        string v;
        string val;
        while (1){
            v = s.substr(inx + 1, 4); 
            val.append(v);
            inx+=5;
            if (s[inx - 5] == '0') break; 
        }
        cout << val << endl;
        cout <<"vrijednost "<<string_to_int(val) << endl;
        return string_to_int(val);
    } else {
        string v;
        long long k = 15;
        if (s[inx] == '0'){
            inx++;
            v = s.substr(inx, k); inx += k;
            long long p = string_to_int(v);
            long long ddd = p + inx;
            while(inx < ddd){
                vals.push_back(ff(s));
            }

        } else if (s[inx] == '1'){
            k = 11;
            inx++;
            v = s.substr(inx, k);
            long long p = string_to_int(v);
            inx += k;
            while(p--){
                vals.push_back(ff(s));
            }
        }
    }

    // suma
    if (id_val == 0){
        long long sum = 0;
        for (long long val: vals){
            sum += val;
        }
        return sum;
    } else if (id_val == 1){
        long long pr = 1;
        for (long long val: vals){
            pr *= val;
        }
        return pr;
    } else if(id_val == 2){
        return *min_element(vals.begin(), vals.end());
    } else if (id_val == 3){
        return *max_element(vals.begin(), vals.end());
    } else if (id_val == 5){
        return vals[0] > vals[1];
    }  else if (id_val == 6) {
         return vals[0] < vals[1];
    } else if (id_val == 7){
         return vals[0] == vals[1];
    }

    return 0;
}



int main(){
    fstream f = fstream("in_1.txt");
    string line;
    mp["0"] = "0000";
    mp["1"] = "0001";
    mp["2"] = "0010";
    mp["3"] = "0011";
    mp["4"] = "0100";
    mp["5"] = "0101";
    mp["6"] = "0110";
    mp["7"] = "0111";
    mp["8"] = "1000";
    mp["9"] = "1001";
    mp["A"] = "1010";
    mp["B"] = "1011";
    mp["C"] = "1100";
    mp["D"] = "1101";
    mp["E"] = "1110";
    mp["F"] = "1111";

    string s;
    long long sol2 = 0;
    while(getline(f,line)){
        s = hex_to_bi(line);
        cout << s << endl;
        // for (long long i = 0; i < 100; i++){
        //     s.push_back('0');
        // }

        sol2 = ff(s);
    }

    cout <<"Rijesenje 1: "<< sol1 << endl;
    cout <<"Rijesenje 2: "<< sol2 << endl;
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
;