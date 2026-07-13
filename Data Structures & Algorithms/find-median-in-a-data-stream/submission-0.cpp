class MedianFinder {
public:
    vector<int> v;
    MedianFinder() {}
    
    void addNum(int num) {
        v.push_back(num);
    }
    
    double findMedian() {
        sort(v.begin(), v.end());
        double ans = 0;
        int n = v.size();
        if(n % 2 == 0){
            double x = v[n / 2] + v[n / 2 - 1];
            ans = x / 2;
        }else{
            ans = v[n / 2];
        }
        return ans;
    }
};
