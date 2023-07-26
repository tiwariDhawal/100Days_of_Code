class Solution {
public:
    bool onTime(int &speed,vector<int>&distance,double &hour){
        double time = 0;
        for(int i = 0;i< distance.size()-1;i++){
            time = time + (distance[i]/ speed);
            if(distance[i]%speed != 0){
                time = time + 1;
            }
            else{
                time = time + 0;
            }

        }
        time = time + ((distance[distance.size() - 1] * 1.0)/speed);
        return time <= hour;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        if((double)dist.size() - 1 >= hour){
            return -1;
        }
        int left = 1;
        int right = 1e7;
        while(left <= right){
            int mid = (left + right)/2;
            if(onTime(mid,dist,hour)){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return left;
    }
};
