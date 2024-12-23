bool FindSumOfThree(vector<int> nums, int target)
{
   std::sort(nums.begin(), nums.end());
   
   for(int i = 0; i < nums.size() - 2; i++)
   {
      int l = i + 1;
      int r = nums.size() - 1;
    
      while(l < r)
      {
        int sum = nums[i] + nums[l] + nums[r];
        if(sum == target)
          return true;
        else if(sum < target)
          l++;
        else 
          r--;
      }
    
   }
   
   return false;
}