class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need, have;
        for (char c : t) need[c]++;

        int required = need.size();  // distinct chars to satisfy
        int formed = 0;              // how many are currently satisfied

        int left = 0, minLen = INT_MAX, minL = 0;

        for (int right = 0; right < (int)s.size(); right++) {
            char c = s[right];
            have[c]++;

            // did adding this char satisfy a needed character?
            if (need.count(c) && have[c] == need[c])
                formed++;

            // shrink from the left while the window is valid
            while (formed == required) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minL = left;
                }
                have[s[left]]--;
                if (need.count(s[left]) && have[s[left]] < need[s[left]])
                    formed--;
                left++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(minL, minLen);
    }
};