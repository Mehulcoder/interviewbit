string temp = "";
unordered_map<char, string> keypad = {
    { '1', "1" },
    { '2', "abc" },
    { '3', "def" },
    { '4', "ghi" },
    { '5', "jkl" },
    { '6', "mno" },
    { '7', "pqrs" },
    { '8', "tuv" },
    { '9', "wxyz" },
    { '0', "0" }
};
void backtracking(string digits, int i, vector<string>& res)
{
    if (digits[i] - '0' > -1 && digits[i] - '0' < 10)
    {    
        string str = keypad[digits[i]];
        for (auto j = 0; j<str.length(); ++j)
        {
            temp += str[j]; 
            if (i == digits.length() - 1)
                res.emplace_back(temp);
            else
                backtracking(digits, i+1, res);
            temp.pop_back(); 
        }
    }
}
vector<string> Solution::letterCombinations(string A) {
    vector<string> res;
    backtracking(A, 0, res);
    return res;
}