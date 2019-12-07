class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int n = timeSeries.size();
        if(n==0) return 0; 
        int sum=0;
        for(int i=1;i<n;i++){
            int diff = timeSeries[i]-timeSeries[i-1];
            sum += (diff<duration)?diff:duration;
        }
        sum += duration;
        return sum;
    }
};
