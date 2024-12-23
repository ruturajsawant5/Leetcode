class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        while(l < r)
        {
            int sum = nums[l] + nums[r];
            if(sum == target)
                return (vector<int>({l+1, r+1}));
            else if(sum < target)
                l++;
            else
                r--;
        }

        return (vector<int>({l+1, r+1}));
    }
};