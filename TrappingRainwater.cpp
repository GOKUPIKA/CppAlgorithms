// Question: Trapping Rain Water
// Platform: LEETCODE
// Difficulty: Hard

// **BEST APPROACH USING 2 POINTER**
// * Time Complexity: O(n)
// * Space Complexity: O(1)


class Solution {
public:

    int trap(vector<int>& height) {
        int n=height.size();
        int left=0;
        int right=n-1;
        int ans=0;
        int maxLeft=0;
        int maxRight=0;
        
        while(left<=right){
            if(height[left]<=height[right]){
                if(height[left]>=maxLeft){
                    maxLeft=height[left];
                }
                else{
                ans+=maxLeft-height[left];
                }
                left++;
            }
            else{
                if(height[right]>=maxRight){
                    maxRight=height[right];
                }
                else{
                    ans+=maxRight-height[right];
                }
                right--;
            }
        }
        return ans;
    }

};

// **EXPLANATION:**
// 1. First we take the 2 pointer left and for traversing the given vector, also maintaining the sum of right way traversal (maxRight) and also the the sum of left way traversal (maxLeft)
// 2. Then we traverse the vector till our left pointer is lower or equal to right pointer.
// 3. In loop we basically check whether to traverse from left or right way direction.
// 4. If we check the current left pointer value is less or equal to height of left then we travese the left pointer else right pointer.


// **BRUTE FORCE APPROACH USING VECTOR**
// * Time Complexity: O(n)
// * Space Complexity: O(n)

class Solution {
public:
    
    int trap(vector<int>&a) {
        int n=a.size();
        int i=1;
        int sum=0;
        vector<int>left,right(n);
        int mx=INT_MIN;
       
        for(auto x:a){
            mx=max(mx,x);
            left.push_back(mx);
        }
        mx=INT_MIN;
       
        for(int i=n-1;i>=0;i--){
            mx=max(mx,a[i]);
            right[i]=mx;
        }
         
        while(i<n-1){            
            int l=left[i-1];
            int r=right[i+1];
            int mx=min(l,r);
            int ans=mx-a[i];
            if(ans>0){
                sum+=ans;
            }
            i++;
        }
        return sum;
    }
    
};

// **EXPLANATION:**
// 1. First we traverse the given vector from left and right way direction while storing the maximum value in that direction in new vector for both left and right seperately
// 2. Then we check for the value from current to the corresponding before and after of the current's value.
