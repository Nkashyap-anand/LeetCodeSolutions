class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
       
        vector<vector<int>> ans;
        vector<int> curr;

        sort(nums.begin(), nums.end());
        
        powerset(nums, 0, curr, ans);
        
        return ans;     
    }
    
    void powerset(vector<int>& nums, int index,  vector<int>& curr, vector<vector<int>>& ans)
    {
       ans.push_back(curr);
        
        for(int i=index; i<nums.size(); i++)
        {
            if(i!= index && nums[i] == nums[i-1]) continue;
            
            curr.push_back(nums[i]);
            powerset(nums, i+1, curr, ans);
             curr.pop_back();
        }
    }
};