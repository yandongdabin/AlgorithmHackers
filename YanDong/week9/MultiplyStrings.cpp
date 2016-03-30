
/**         AC  8ms     **/
class Solution {
public:
	string multiply(string num1, string num2) {
		int *a = new int[num1.length()];
		int *b = new int[num2.length()];
		for(int i = 0;i<num1.length();++i){
			a[i] = num1[num1.length()-i-1] - '0';
		}
		for(int i = 0;i<num2.length();++i){
			b[i] = num2[num2.length()-i-1] - '0';
		}
		int *c = new int[num1.length() + num2.length()];
		for(int i=0;i<num1.length() + num2.length();++i){
			c[i] = 0;
		}
		int rest = 0;
		for(int i = 0;i<num2.length();++i){
			rest = 0;
			for(int j = 0;j<num1.length();++j){
				int tmp = rest + a[j] * b[i] + c[i+j];
				c[i+j] = tmp % 10;
				rest = tmp / 10;
			}
			if(rest!=0){
				c[i+num1.length()] = rest;
			}
		}
		int len = num1.length()+num2.length();
		while(len>1 && c[len-1]==0) len-=1;
		string s(len,'0');
		for(int i=0;i<len;++i){
			s[i] = c[len-i-1] + '0';
		}
		delete a;
		delete b;
		delete c;
		return s;
	}
};
