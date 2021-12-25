
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

vector<pair<int ,int>> parse(string &line){
    vector<pair<int, int>> p;
    vector<string> v;
    string str;
    for (int i = 0; i < line.size(); i++){
        if (line[i] >= '0' && line[i] <= '9' || line[i] == '-') str.push_back(line[i]);
        else {
            if (str.length())
            v.push_back(str);
            str.clear();
        }
    }

    if (str.length())
            v.push_back(str);

    for (int i = 0; i < v.size(); i+=2){
        p.push_back(
            {stoi(v[i]), stoi(v[i + 1])}
        );
    }
    return p;
}

class el{
    public:
    int first, second;
    bool on = 0;
    el(){}
    el(int x1, int x2, bool o): first{x1}, second{x2}, on{o}{

    }
    ~el(){}
};


// prvi dio zadatka
void f1( vector<el > &x, vector<el > &y, vector<el > &z){
    vector<vector<vector<bool>>> dp(101, vector<vector<bool>>(101, vector<bool>(101, 0)));
    for (int i = 0; i < x.size(); i++){
        for (int  q= x[i].first; q <= x[i].second; q++){
            for (int j = y[i].first; j <= y[i].second; j++){
                for (int k = z[i].first; k <= z[i].second; k++){
                    dp[q + 50][j + 50][k+ 50] = x[i].on;
                }
            }
        }
    }
    int sol = 0;
        for (int  q= 0; q <= 100; q++){
            for (int j =0; j <= 100; j++){
                for (int k = 0; k <= 100; k++){
                    sol += dp[q][j][k];
                }
            }
        }
    
    cout <<"prvi dio " <<sol << endl;
}

// kompresija
void ff(vector<el > &x,  map<long long, long long> &mp2){
    vector<long long> p;
     map<long long, long long> mp;
     set<long long> st;
    for (int i = 0; i < x.size(); i++){
        if (st.count(x[i].first) == 0){
            p.push_back(x[i].first);
            st.insert(x[i].first);
        }

        if (st.count(x[i].second) == 0){
            p.push_back(x[i].second);
            st.insert(x[i].second);
        }
      
    }
    sort(p.begin(), p.end());
    for (int i = p.size() -1; ~i; i--){
        mp[p[i]] = i;
        mp2[i] = p[i];
    }
    for (int i = 0; i < x.size(); i++){
        x[i].first = mp[x[i].first];
        x[i].second = mp[x[i].second];
        x[i].on = x[i].on;
    }  
}   


int fun2(vector<el> &v){
    vector<bool> dp(101, 0);
    for (int i = 0; i < v.size(); i++){
        cout << "x "<<v[i].first<<" "<<v[i].second<<endl;
        for (int j = v[i].first; j <= v[i].second; j++){
            dp[j + 50] = v[i].on;
        }
    }
    int sol = 0;
    for (int i = 0; i < dp.size(); i++) sol += dp[i];
     
    return sol;
}

int fun(vector<pair<el, el> > &p1){
    vector<el> x, y;
    for (int i = 0; i < p1.size(); i++){
        x.push_back(p1[i].first);
        y.push_back(p1[i].second);
    }
    map<long long, long long> mp_y;
    int k = 0;
    
    ff(y, mp_y);
    
    for (int i = 0; i < y.size(); i++){
        k = max(k, y[i].second);
    }
    vector<vector<el> > ss(k+ 1);   
    for (int i = 0; i < y.size();i++){
        for (int j = y[i].first; j <= y[i].second; j++){
            ss[j].push_back(x[i]);
        }
    }
    int sol = 0;
    for (int i =0 ; i < ss.size() - 1; i++){
        if (ss[i].size()){
            cout << "y "<<mp_y[i]<<" "<< mp_y[i + 1] <<" "<< (mp_y[i + 1] - mp_y[i])<<endl;
            sol += fun2(ss[i]) * (mp_y[i + 1] - mp_y[i] );
        }
    }
    //sol+= fun2(ss.back());

    return sol;
}   

int f_do(vector<long long> &v, long long x){
    return lower_bound(v.begin(), v.end(), x) - v.begin();
}

int  main(){
    fstream f = fstream("in_1.txt");
    string line ;
    vector<el> x, y, z;
    vector<long long> xv,yv,zv;
    while (getline(f, line)){
        // parse
        // x, y, z
        vector<pair<int, int>> p = parse(line); 
        x.push_back( el(p[0].first, ++p[0].second, line[1] == 'n'));
        y.push_back( el(p[1].first, ++p[1].second, line[1] == 'n'));
        z.push_back( el(p[2].first, ++p[2].second, line[1] == 'n'));
        xv.push_back(p[0].first);
        xv.push_back(p[0].second);

        yv.push_back(p[1].first);
        yv.push_back(p[1].second);

        zv.push_back(p[2].first);
        zv.push_back(p[2].second);
    }
    sort(xv.begin(), xv.end());
    sort(yv.begin(), yv.end());
    sort(zv.begin(), zv.end());
    int N = xv.size();
    vector<vector<vector<bool>> > dp(N, vector<vector<bool>>(N, vector<bool>(N,0)));
    int x1,x2,y1,y2,z1,z2;
    int q,j,k;
    for (int i = 0; i < x.size(); i++){
         x1 = f_do(xv, x[i].first); x2 = f_do(xv, x[i].second);
         y1 = f_do(yv, y[i].first); y2 = f_do(yv, y[i].second);
         z1 = f_do(zv, z[i].first); z2 = f_do(zv, z[i].second);

        for ( q = x1; q < x2; q++){
            for ( j = y1; j < y2; j++){
                for ( k = z1; k < z2; k++){
                    dp[q][j][k] = x[i].on;
                }
            }
        }
    }
     long long sol = 0;
    for (int  i = 0; i < N - 1; i++){
        for (int  j = 0; j <N - 1; j++){
            for (int  z = 0;z <N-1 ;z++){
                sol +=  (long long)(dp[i][j][z]*(xv[i + 1] - xv[i ] )*(yv[j + 1] - yv[j ] )*(zv[z + 1] - zv[z ] ));
            }
        }
    }
    cout << sol << endl;
    return 0;
}
//2758514936282235
//55034886913147

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
