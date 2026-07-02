class Solution {
public:
    int binSearch(vector<int>& numbers, int st, int end, int target){
        while(st <= end){
            int mid = st + (end - st) / 2;
            if(numbers[mid] == target) return mid;
            else if(numbers[mid] < target) st = mid + 1;
            else end = mid - 1;
        }
        return -1;
    }
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int n = numbers.size();
        for(int i = 0; i < n - 1; i++){
            int idx = binSearch(numbers, i + 1, n - 1, target - numbers[i]);
            if(idx != -1){
                ans.push_back(i + 1);
                ans.push_back(idx + 1);
                return ans;
            }
        }
        return ans;
    }
};
