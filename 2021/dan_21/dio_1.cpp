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

int f(int p1, int p2){
    
    int s1 = 0, s2 = 0;
    int kocka = 1;
    int broj = 0;
    p1--;
    p2--;
    int i = 0;
    while (s1 < 1000 && s2 < 1000){   
        for (int j = 0; j < 3; j++){
            if (i % 2 == 0)
            p1 = (p1 + kocka)% 10;
            else 
            p2 = (p2 + kocka) % 10;
            kocka = (kocka ) % 100 + 1;
            broj++;
        }   
        if (i % 2 == 0)
        s1 += p1 + 1;
        else
        s2+= p2 + 1;
        i++;
    }
    cout << s1 <<" "<< s2 <<" "<< broj<<" "<<s1*broj<< endl;

    return 0;
}

void pr(vector<vector<long long>> &dp){
    for (int i = 0; i < dp.size(); i++){
        cout << i + 1<<" ";
        for (int j = 0; j < dp[i].size(); j++){
            cout << dp[i][j]<<" ";
        }
        cout << endl;
    }
}

vector<long long> v(10, 0);
vector<vector<long long> > poz(11, vector<long long>(11, 0));

vector<pair<long long, long long> >  solve(int p){
    int n = 50;
    vector<vector<vector<long long> > > dp(13, vector<vector<long long>> (n,vector<long long >(11, 0)));
    dp[0][0][p] = 1;
    //za svako bacanje
    vector<pair<long long, long long >> pii;
    pii.push_back({27,0});
    for (int i = 1; i < 12; i++){
        // za saku pozicjiu
        for (int j = 1; j < 11; j++){
            // j -> pcetna pozicija
            // k -> krajnja pozicija
            for (int k = 1; k < 11; k++){
                // z -> broj bodov
                for (int z = 0; z < 23; z++){

                    dp[i][z + k][k] += poz[j][k] * dp[i - 1][z][j];
                }
            }
        }
        long long iz = 0, pob = 0;
        for (int j = 1; j< 11; j++){
            for (int z = 0; z < n;z++){
                if (z >=21){
                    pob += dp[i][z][j];
                    dp[i][z][j] = 0;
                } else {
                    iz += dp[i][z][j];
                }
            }
        }
        pii.push_back({iz,pob});
    }
    // for (int i = 0; i < 12; i++){
    //     for (int z = 0;z < 22; z++){
    //         cout << z <<": ";
    //         for (int j = 1; j< 11; j++){
    //             cout << dp[i][z][j]<<" ";
    //         }
    //         cout << endl;
    //     }
    //     cout << "**************"<<endl;
    // }
    return pii;
}

int main(){
    // fstream f = fstream("in_1.txt");
    // string line, kart;
    int p1 = 2, p2 = 8;
    
    for (int i = 1; i <= 3; i++){
        for (int j = 1; j <= 3; j++){
            for (int k = 1; k <= 3; k++){
                v[i + j + k]++;
            }
        }
    }
    for (int i = 1; i < 11; i++){
        for (int j = 1; j < 11; j++){
            poz[i][j] = v[(j - i + 10)%10];
        }
    }
    
    vector<pair<long long, long long> >  p_1= solve(p1);
    vector<pair<long long, long long> >  p_2 = solve(p2);

    long long s1 = 0, s2 = 0;
    for (int i = 1; i < p_1.size(); i++){
        s1 += p_1[i].second * p_2[i - 1].first;
    }
     for (int i = 1; i < p_1.size(); i++){
        s2 += p_2[i].second * p_1[i].first;
    }
    cout << s1 <<" "<<s2<<endl;
    return 0;
}

//448334087359 1046370946297
//
//444356092776315 341960390180808
//444356092776315 341960390180808
//106768284484217 
//63041043110262



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
