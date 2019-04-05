class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        if(nums.size() == 1){
            return nums[0];
        }
        
        
        int finalans=nums[0],finalans1=nums[1];
        vector<int> fi;
        fi.push_back(finalans);
        fi.push_back(max(finalans1,finalans));
        bool p=true;
        for(int i=2;i<nums.size();i++){
            fi.push_back(max(nums[i]+fi[i-2],fi[i-1]));
            p=false;
        }
        if(p){
            return max(nums[0],nums[1]);
        }
        return fi[fi.size()-1];
            
            
        
    }
};