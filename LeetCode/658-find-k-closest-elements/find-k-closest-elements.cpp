class Solution {
public:

    int lowerbound(vector<int> &arr,int x){
        int start = 0, end = arr.size() - 1;
        int ans = end;
        while(start <= end){
            int mid = (start+end) / 2;
            if(arr[mid] >= x){
                ans = mid;
                end = mid - 1;
            }
            else if(x > arr[mid]){
                start = mid + 1;
            }
            else{
                end  = mid - 1;
            }
        }
        return ans;
    }

    vector<int> bs_method(vector<int> &arr, int k,int x){
        // lower bound
        int h = lowerbound(arr, x);
        int l = h - 1;
        while(k--){
            if(l < 0){
                h++;
            }
            else if(h >= arr.size()){
                l--;
            }
            else if(x - arr[l] > arr[h] - x){
                h++;
            }
            else{
                l--;
            }
        }
        return vector<int>(arr.begin() + l, arr.begin() + h);
    }

    vector<int> twopointer(vector<int> &arr, int k, int x){
        int low = 0, high = arr.size()-1;
        while(high - low >= k){
            if(x - arr[low] > arr[high] - x){
                low++;
            }
            else{
                high--;
            }
        }
        vector<int> ans;
        for(int i = low; i <= high; i++){
            ans.push_back(arr[i]);
        }
        return ans;
    }

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        return twopointer(arr,k,x);
    }
};