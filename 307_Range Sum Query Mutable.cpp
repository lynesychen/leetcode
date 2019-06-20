class NumArray {
public:
    vector<int> v;
    vector<int> sum;
    int n;
    int lowbit(int x){
        return x&(-x);
    }
    NumArray(vector<int>& nums) {
        n = nums.size();
        sum.resize(n+1);
        v.resize(n+1);
        for(int i=0;i<n;++i){
            v[i+1]=nums[i];
            init(i+1,nums[i]);
        }
    }
    void init(int i, int val){
        while (i<=n){
            sum[i]+=val;
            i+=lowbit(i);
        }
    }
    void update(int i, int val) {
        int t=val-v[i+1]; //ȡֵ��С ת���ɵ������ߵ���
        v[i+1]=val; //��ԭ����ֵ����Ϊ����ֵ
        if(t==0){ //Ϊ0����Ҫ�����κβ���
            return;
        }
        init(i+1,t); //����
    }
    int getsum(int i){
        int res=0;
        while (i>0){
            res+=sum[i];
            i-=lowbit(i);
        }
        return res;
    }
    int sumRange(int i, int j) {
        return getsum(j+1)-getsum(i);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */