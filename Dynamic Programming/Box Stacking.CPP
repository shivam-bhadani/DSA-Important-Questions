struct Box {
    int height, width, length;
};

static bool compare(Box a, Box b) {
    return a.length*a.width > b.length*b.width ? true : false;
}

int maxHeight(int height[],int width[],int length[],int n)
{
    vector<Box> data(3*n);
    int idx = 0;
    for(int i=0; i<n; i++) {
        data[idx].height = height[i];
        data[idx].width = max(width[i], length[i]);
        data[idx].length = min(width[i], length[i]);
        idx++;
        data[idx].height = width[i];
        data[idx].width = max(height[i], length[i]);
        data[idx].length = min(height[i], length[i]);
        idx++;
        data[idx].height = length[i];
        data[idx].width = max(height[i], width[i]);
        data[idx].length = min(height[i], width[i]);
        idx++;
    }
    
    // Sorting according to area
    sort(data.begin(), data.end(), compare);
    
    // Finding Longest Decreasing Subsequence of length and width
    vector<int> dp(3*n);
    for(int i=0; i<3*n; i++) {
        dp[i] = data[i].height;
    }
    int ans = 0;
    for(int i=0; i<3*n; i++) {
        for(int j=0; j<i; j++) {
            if(data[j].length > data[i].length && data[j].width > data[i].width) {
                dp[i] = max(dp[i], dp[j] + data[i].height);
            }
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}