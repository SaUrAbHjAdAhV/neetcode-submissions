class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int billfive = 0;
        int billten = 0;

        for(auto bill : bills){
            if(bill == 5){
                billfive++;
            }
            else if(bill == 10){
                if(billfive == 0){
                    return false;
                }
                billfive--;
                billten++;
            }
            else{
                if(billfive == 0){
                    return false;
                }
                else if(billten == 0 && billfive < 3){
                    return false;
                }
                else if(billten == 0){
                    billfive = billfive - 3;
                }
                else{
                    billten--;
                    billfive--;
                }
            }
        }
        return true;
    }
};