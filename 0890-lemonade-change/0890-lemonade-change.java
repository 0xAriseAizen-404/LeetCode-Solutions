class Solution {
    public boolean lemonadeChange(int[] bills) {
        int five = 0;
        int ten = 0;
        int twenty = 0;
        for(int i=0;i<bills.length;++i){
            int x = bills[i];
            if(x==5) five++;
            if(x==10){
                if(five==0) return false;
                five--;
                ten++;
            }
            if(x==20){
                if(ten==0){
                    if(five<3) return false;
                    else{
                        five=five-3;
                    }
                }
                if(ten>0){
                    if(five==0)return false;
                    if(five>0){
                        ten--;
                        five--;
                    }
                }
            }
        }
        return true;
    }
}