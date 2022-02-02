class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,double>> car(n);
        for(int i=0; i<n; i++) {
            double time = ((target - position[i])*1.0)/speed[i];
            car[i] = {position[i], time};
        }
        sort(car.begin(), car.end());
        double tt = car[n-1].second;
        int ans = 1;
        for(int i=n-2; i>=0; i--) {
            if(car[i].second>tt) {
                ans++;
                tt = car[i].second;
            }
        }
        return ans;
    }
};