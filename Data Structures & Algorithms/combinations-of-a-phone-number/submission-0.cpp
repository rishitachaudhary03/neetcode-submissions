class Solution {
public:
    vector<string> digitToChar = {"", "", "abc", "def", "ghi", "jkl",
                                  "mno", "qprs", "tuv", "wxyz"};
    vector<string> res;                              
    vector<string> letterCombinations(string digits) {
        if(digits.empty()){
            return res;
        }
        backtracking(0,"",digits);
        return res;
    }
    void backtracking(int i, string curstr,string& digits){
        if(curstr.size()==digits.size()){
            res.push_back(curstr);
            return;
        }
        string chars=digitToChar[digits[i]-'0'];
        for(char c: chars){
            backtracking(i+1,curstr+c,digits);
        }
    }
};
