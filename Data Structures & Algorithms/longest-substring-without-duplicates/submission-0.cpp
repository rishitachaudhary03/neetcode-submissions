class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res=0;
        int l=0;
        unordered_set<char> charset;
        for(int r =0; r<s.size(); r++){
            while(charset.find(s[r]) != charset.end()){
                charset.erase(s[l]);
                l++;
            }
            charset.insert(s[r]);
            res = max(res,r-l+1);
        }
        return res;
    }
};
