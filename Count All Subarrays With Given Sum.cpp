int findAllSubarraysWithGivenSum(vector < int > & nums, int k) {
    // Write Your Code Here
    unordered_map<int,int> mep;
        mep[0]=1;
        int count=0,presum=0;
        for(int i=0;i<nums.size();i++){
            
            presum+=nums[i];
            int remove=presum-k;
            count+=mep[remove];
            mep[presum]++;
        }

    
        return count;
    
    }
