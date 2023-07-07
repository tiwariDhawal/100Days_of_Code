class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int i = 0;
        int j = 0;
        int count = 0;
        int maxi = INT_MIN;
        int maxi2 = INT_MIN;
        
        int n = answerKey.size();
        
        
        while(j<answerKey.size()){
            if(answerKey[j] == 'F'){
                count++;
            }
            while(i < n && count > k ){
                if(answerKey[i] == 'F'){
                    count--;
                }
                i++;
            }
            maxi = max(maxi , j - i + 1);
            j++;
        }
        j = 0;
        i = 0;
        count = 0;
        while(j<answerKey.size()){
            if(answerKey[j] == 'T'){
                count++;
            }
            while(i < n && count > k ){
                if(answerKey[i] == 'T'){
                    count--;
                }
                i++;
            }
            maxi = max(maxi , j - i + 1);
            j++;
        }

        return max(maxi,maxi2);
        
    }
};
