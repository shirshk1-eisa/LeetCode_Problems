class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int i=0;
        int ans = nums[0]+nums[1]+nums[2];
        
        for(i=0;i<n-1;i++){
            int j=i+1;
             int k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(abs(ans-target)>abs(sum-target) )
                    ans=sum;
                if (sum < target)
                j++;
                else if (sum > target)
                k--;
                else
                return sum;
            }
    

        }
        return ans;

}
};