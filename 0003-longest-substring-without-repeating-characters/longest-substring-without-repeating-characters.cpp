class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> chars;
int left = 0, right = 0, res = 0;
while (right < s.length()) {
  chars[s[right]]++;            // expand
  while (chars[s[right]] > 1) { // invalid?
    chars[s[left]]--; left++;   // shrink
  }
  res = max(res, right - left + 1);
  right++;
}
return res;
    }
};