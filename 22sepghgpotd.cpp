class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
          int n = arr.size();
        vector<int> left(n), right(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        // Clear stack
        while (!st.empty()) st.pop();

        // Next Smaller Element (NSE)
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        // Result array (1-based indexing for window size)
        vector<int> ans(n + 1, 0);

        // For each element, find its window length and update answer
        for (int i = 0; i < n; i++) {
            int len = right[i] - left[i] - 1;   // window size where arr[i] is min
            ans[len] = max(ans[len], arr[i]);
        }

        // Fill missing values by propagating from right to left
        for (int i = n - 1; i >= 1; i--) {
            ans[i] = max(ans[i], ans[i + 1]);
        }

        // Erase dummy 0th index
        ans.erase(ans.begin());

        return ans;
        
    }
};

