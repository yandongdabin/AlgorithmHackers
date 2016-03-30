/****************/
/*  AC 48ms     */
/**special case:
1-(1-(2+(1-2)))
(1)+(0)-(3)
基本处理策略：
遇到操作符栈顶是+或者- 操作数运算入栈 （特殊的在算完()中的之后）
遇到)运算直到操作符栈顶是(
*/
/****************/
#include<stack>
#include<string>
#include<iostream>
using namespace std;
class Solution {
public:
    bool isAlpha(char c){
        return c >= '0' && c <= '9';
    }
    int subcall(stack<int> &_operand,stack<char> &_operator){
        char curTop = _operator.top();
        int x = _operand.top();
        _operand.pop();
        int y = _operand.top();
        _operand.pop();
        switch(curTop){
        case '+':
                _operand.push(x + y);
                break;
        case '-':
                _operand.push(y - x);
                break;
        }
        _operator.pop(); // pop + or -
    }
    int calculate(string s) {
        stack<int> _operand;
        stack<char> _operator;
        int base = 10;
        int i = 0;
        while(i < s.length()){
            cout<<"index:"<<i<<endl;
            cout<<s[i]<<endl;
            if(s[i] == '+' || s[i] == '-' || s[i] == '('){
                i += 1;
                _operator.push(s[i]);
            }
            else if(s[i] == ' ') {
                i += 1;
                continue;
            }else if(isAlpha(s[i])){
                int number = 0;
                while(i<s.length() && isAlpha(s[i])){
                    number = number * base + s[i] - '0';
                    i += 1;
                }
                cout<<number<<endl;
                if(_operator.empty() || _operator.top()=='('){
                    _operand.push(number);
                }
                else if(_operator.top() == '+'){
                    _operator.pop();
                    int x = _operand.top();
                    _operand.push(number+x);
                }else if(_operator.top()=='-'){
                    _operator.pop();
                    int x =  _operand.top();
                    _operand.push(x - number);
                }
            }else if(s[i] == ')'){
                while(_operator.top()!='('){
                   subcall(_operand,_operator);
                }
                _operator.pop(); //pop (

            }
        }
        while(!_operator.empty()){
            subcall(_operand,_operator);
        }
        return _operand.top();
    }
};
int main(){
    string s = "100+1";
    Solution sol;
    int ret = sol.calculate(s);
    cout<<ret<<endl;
    return 0;
}
