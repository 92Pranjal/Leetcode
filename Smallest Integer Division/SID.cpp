class Solution {
public:
    int smallestRepunitDivByK(int K) {
        if(K == 1){
            return 1;
        }
        if(K%2 == 0 || K%5 == 0){
            return -1;
        }
        int num=1;
        int quo=10;
        int newnum=0;
        int flag=true;
        int count=1;
        while(num%K != 0 || flag==false){
            num=num*quo+1;
            flag=true;
            count++;
            if(count == 10){
                break;
            }
        }
        if(count == 10){
            return -1;
        }
        return count;
    }
};