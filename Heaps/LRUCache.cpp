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

// <{1,1},{4,3}>
list<pii> l1;
unordered_map< int , list< pair<int, int> >::iterator>m1;
int size1;


LRUCache::LRUCache(int capacity) {
    m1.clear();
    l1.clear();
    size1 = capacity;
}

int LRUCache::get(int key) {
    if (m1.find(key)==m1.end())
    {
        return -1;
    }else{
        auto it = m1.at(key);
        pii temp = *it;
        l1.push_front(temp);
        l1.erase(it);
        m1[key] = l1.begin();
        return l1.front().f;
    }

}

void LRUCache::set(int key, int value) {
    if (m1.find(key)!=m1.end())
    {
        l1.erase(m1.at(key));
        l1.push_front(mp(value, key));
        m1[key] = l1.begin();
    }else{
        if (l1.size()<size1)
        {
            l1.push_front(mp(value, key));
            m1[key] = l1.begin();

        }else{
            auto last = l1.back();
            m1.erase(last.s);
            l1.pop_back();
            l1.push_front(mp(value, key));
            m1[key] = l1.begin();
        }
    }
}
