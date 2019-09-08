class Solution {
public:
    struct tmp1{
        vector<int> x;
        tmp1(vector<int> a) {x = a;}
        bool operator<(const tmp1& a) const{
            return x[0] + x[1] < a.x[0] + a.x[1]; //´ó¶¥¶Ñ
        }
    };

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> result;
        if(k==0||nums1.size()==0||nums2.size()==0)return result;
        if(k==1){
            result.push_back(vector<int> (nums1[0],nums2[0]));
            return result;
        }
        priority_queue<tmp1> q;
        int size1=nums1.size(), size2=nums2.size();
        vector<int> tmp(2);
        for(int i=0; i < size1; ++i){
            for(int j=0;j<size2;++j){
                //cout<< i <<" "<<j<<endl;
                if(q.size()<k||(!q.empty()&&q.top().x[0]+q.top().x[1]>nums1[i]+nums2[j])){
                    if(q.size()==k)q.pop();
                    tmp[0]=nums1[i],tmp[1]=nums2[j];
                    q.push(tmp);
                }
                else break;
            }
            //if(q.size()==k&&i<size1-1&&nums1[i+1]!=nums1[i])break;
        }
        while(!q.empty()){
            vector<int> a = q.top().x;
            q.pop();
            result.push_back(a);
        }
        return result;
    }
};