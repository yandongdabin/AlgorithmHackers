int div1(int num,int divider){
    while(num >= divider && num%divider==0){
        num/=divider;
    }
    return num;
}
bool isUgly(int num) {
    if(num < 0) return false;
    num = div1(num,5);
    num = div1(num,3);
    num = div1(num,2);
    return num == 1;
}
