class Solution {
public:
    int passThePillow(int n, int time) {
        int index=1;
        bool st = true;
        for(int i=1;i<=time;i++){
            if(index==n) st = false;
            if(index==1) st = true;
            if(st==true) index++;
            else index--;
        }
        return index;
    }
};