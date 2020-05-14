/*

                Name: Mehul Chaturvedi
                IIT-Guwahati

*/



#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unordered_map<int, int> umapii;
typedef unordered_map<int, bool> umapib;
typedef unordered_map<string, int> umapsi;
typedef unordered_map<string, string> umapss;
typedef map<string, int> mapsi;
typedef map<pair<int, int>, int> mappiii;
typedef map<int, int> mapii;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef unordered_set<int> useti;

#define debug(x) cout << '>' << #x << ':' << x << endl;
#define uset unordered_set
#define it iterator
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define f first
#define s second
#define MOD 1000000007


bool mySort(pii a, pii b){
    if(a.f!=b.f){
        return a.f>b.f;
    }else{
        return a.s<=b.s;
    }
}




vector<int> Solution::solve(string A, vector<string> &B) {
    vector<int> hehe;
    int start = 0;
    unordered_map<string, int> goodWords;
    string good = "";
    while(start!=A.size()){
        if (A[start] == '_')
        {
            goodWords[good]++;
            good = "";
            start++;
            continue;
        }else{
            good+=A[start];
            start++;
        }
    }
    goodWords[good]++;
    
    vector<int> goodCount;
    for (int i = 0; i < B.size(); ++i)
    {
        string word = "";
        int strt = 0;
        int count = 0;
        while(strt!=B[i].size()){
            if (B[i][strt] == '_')
            {
                if (goodWords[word]!=0)
                {
                    count++;
                }
                strt++;
                word = "";
            }else{
                word+=B[i][strt];
                strt++;
            }
        }

        if (goodWords[word]!=0)
        {
            count++;
        }
        goodCount.push_back(count);
    }
   
    vector<pii> temp;
    for (int i = 0; i < goodCount.size(); ++i)
    {
        temp.push_back(mp(goodCount[i], i));
    }

    sort(all(temp),mySort);

    vector<int> ans;
    for (int i = 0; i < temp.size(); ++i)
    {
        ans.push_back(temp[i].s);
    }
    
    return ans;
}
