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
        for(int i=1;i<100000;i++){
            count=(count*10+1)%K;
            if(count == 0){
                return i+1;
            }
        }
        return -1;
    }
};