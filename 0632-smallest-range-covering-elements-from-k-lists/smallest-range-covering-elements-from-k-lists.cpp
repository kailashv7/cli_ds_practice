class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<array<int,3>, vector<array<int,3>>, greater<>> pq;
        int curMax = INT_MIN;

        for (int i = 0; i < (int)nums.size(); i++) {
            pq.push({nums[i][0], i, 0});
            curMax = max(curMax, nums[i][0]);
        }

        vector<int> ans = {pq.top()[0], curMax};

        while (true) {
            auto [val, li, ei] = pq.top();
            pq.pop();

            if (ei + 1 >= (int)nums[li].size()) break;

            pq.push({nums[li][ei + 1], li, ei + 1});
            curMax = max(curMax, nums[li][ei + 1]);

            int newMin = pq.top()[0];
            if (curMax - newMin < ans[1] - ans[0])
                ans = {newMin, curMax};
        }

        return ans;
    }
};