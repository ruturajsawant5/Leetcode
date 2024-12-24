class Solution {
public:
    void sortColors(vector<int>& nums) {
        int start = 0;
        int current = 0;
        int end = nums.size() - 1;

        while(current <= end)
        {
            if(nums[current] == 0)
            {
                std::swap(nums[start], nums[current]);
                start++;
                current++;
            }
            else if(nums[current] == 2)
            {
                std::swap(nums[current], nums[end]);
                end--;
                //WHY NO current++ is interesting
                //If current++ were used after swapping with end, 
                //the array would remain unsorted in some cases because nums[current] is skipped.
            }
            else
             current++;
        }
        
    }
};