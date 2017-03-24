// Reverse Integer
class Solution {
public:
    int reverse(int x) {
        long int y = x;
        vector<int> c;
        int flag = y > 0 ? 1 : -1;
        y = abs(y);
        while(y != 0){
            c.push_back(y % 10);
            y = y / 10;
        }
        long int z = 0;
        for(int i = 0; i < c.size(); ++i){
            z = 10 * z + c[i];
        }
        z = z * flag;
        if(z > pow(2,31) - 1 || z < - pow(2,31)){
            z = 0;
        }
        return z;
    }
};
