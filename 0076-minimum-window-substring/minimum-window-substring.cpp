class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need, have;
        for(char c : t) need[c]++;
        int required = need.size(), formed = 0;
        int left = 0, minLen = INT_MAX, minL = 0;
        for(int right =0; right < s.size(); right++){
           char c = s[right];
           have[c]++;
        if (need.count(c) && have[c] == need[c])
            formed++;

        while (formed == required){
            if(right - left +1 < minLen)
              minLen = right-left+1, minL = left;
            have[s[left]]--;
            if (need.count(s[left]) && have[s[left]] < need[s[left]]) 
                formed--;
            left++;     
         }}return minLen == INT_MAX ? "" : s.substr(minL, minLen);}};