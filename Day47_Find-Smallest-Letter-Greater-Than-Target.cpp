class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char output;
        for(int i = 0;i< letters.size();i++){
            if(letters[i] > target){
                output = letters[i];
                break;
            }
            
        }
        if(!output){
            return letters[0];
        }
        return output;
    }
};
