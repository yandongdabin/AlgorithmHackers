class Solution {
public:
    //Run Time Limited
    bool isPrime(int n){
        if(n<2)
            return false;
        for(int i=0;i<cnt;++i){
            if(n % store[i] == 0){
                return false;
            }
        }
        return true;
    }
    int countPrimes(int n) {
        cnt = 0;
        int ret = 0;
        for(int i = 1;i<=n;++i){
            if(isPrime(i)){
                store[cnt++]=i;
                ++ret;
            }
        }
        return ret;
    }

private:
    int store[1000];
    int cnt;
};

//AC 84ms
class Solution {
public:
    int countPrimes(int n) {
        int *store = new int[n];
        int ret = 0;
        for(int i=2;i<n;++i)
            store[i] = 1;
        for(int i = 2;i*i<n;++i){
            if(store[i] == 1){
                for(int j = i*i;j<n;j+=i){
                    store[j]=0;
                }
            }
        }
        for(int i = 2;i<n;++i){
            if(store[i]==1)
                ++ret;
        }
        delete store;
        return ret;
    }
};
int main(){
    return 0;
}
