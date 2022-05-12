class Solution {
public:
    
    void permuteUnique ( vector<vector<int>>  &ans, vector<int> &temp,  map<int, int> &map, int n)
    {
        if(n<=0)
        {
            ans.push_back(temp);
            return;
        }
        
        for(auto &it: map)
        {
            if(it.second <= 0) continue;
            
            it.second--;
            
            temp.push_back(it.first);
            
            permuteUnique( ans, temp, map, n-1);
            
            temp.pop_back();
            
            it.second++;
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> temp;
        map<int, int> map;
        
        
        for(int i: nums)
        {
            if(map.find(i)==map.end()) map[i]=0;
            map[i]++;
        }
        
        permuteUnique( ans, temp, map, nums.size());
        
        return ans;
    }
};