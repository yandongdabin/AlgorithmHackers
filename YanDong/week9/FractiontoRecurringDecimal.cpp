
/*AC  map 20ms*/
/*    unordered_map 16 ms          */
#include<iostream>
#include<map>
#include<string>
#include<cmath>
using namespace std;
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string ret = "0";
        if(numerator==0) return ret;
        int flag = (numerator > 0) ^ (denominator>0);

        /*why */
        long numer = numerator < 0 ? (long)numerator * (-1) : (long)numerator;
        long denom = denominator < 0 ? (long)denominator * (-1) : (long)denominator;

        ret = to_string(numer / denom);

        if(flag != 0){
            ret.insert(0,1,'-');
        }
        long long rest = numer % denom;
        if(rest == 0){
            return ret;
        }
        ret += ".";
        int len = ret.length();
        map<long long,int> re_pos;
        while(rest != 0){
            cout<<rest<<endl;
            if(re_pos.find(rest) != re_pos.end()){
                ret.insert(re_pos[rest],1,'(');
                ret+=")";
                return ret;
            }
            re_pos[rest] = len;
            long long tmp = rest*10 / denom;

            cout<<tmp<<endl;
            ret += to_string(tmp);
            rest = rest*10 % denom;
            len+=1;
        }
        return ret;

    }
};
int main(){
    Solution sol;
    int a;
    int b;
    while(cin>>a && cin>>b){
        string ret = sol.fractionToDecimal(a,b);
        cout<<ret<<endl;
    }

    return 0;
}
