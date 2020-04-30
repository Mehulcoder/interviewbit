/*
                Name: Mehul Chaturvedi
                IIT-Guwahati
*/
/*
                PROBLEM STATEMENT
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

string solve(string A)
{
    vector<string> ans;
    int i = 0;
    // cout << A.size() << '\n';
    while (i < A.size())
    {
        string word = "";

        // int i = 0;
        while (A[i] == ' ' && i < A.size())
        {
            i++;
        }

        if (i >= A.size())
        {
            break;
        }

        while (A[i] != ' ' && i<A.size())
        {
            word += A[i];
            i++;
        }
        // cout << word << '\n';
        ans.push_back(word);
    }
    reverse(ans.begin(), ans.begin()+ans.size());
    string out;
    for (int i = 0; i < ans.size(); i++)
    {
        out += ans[i];
        out += ' ';
    }
    out = out.substr(0, out.size()-1);
    // cout << out << '\n';
    return out;
}

int main(int argc, char **argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a;
    getline(cin,a);

    std::cout << solve(a) << std::endl;

    return 0;
}
