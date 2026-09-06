class Solution {
public:
   void getAllSubsets(vector<int>&nums,vector<int>&ans,int i,vector<vector<int>>&allsubsets){
        if(i==nums.size()){
            allsubsets.push_back({ans});
            return;

        }
        ans.push_back(nums[i]);
        getAllSubsets(nums,ans,i+1,allsubsets);
        ans.pop_back();
        int index=i+1;
        while(index<nums.size() && nums[index]==nums[index-1])
        index++;
        getAllSubsets(nums,ans,index,allsubsets);

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>allsubsets;
        vector<int>ans;
        getAllSubsets(nums,ans,0,allsubsets);
        return allsubsets;
        
    }
};