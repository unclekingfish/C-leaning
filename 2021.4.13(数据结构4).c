//浮点型在内存中的存储
int main()
{
    int n=9;
    float *pFloat =(float *)&n;
    printf("n=%d\n",n);
    printf("pFloat= %f\n",*pFloat);

    *pFloat =9.0;
    printf("num=%d\n",n);
    printf("*pFloat= %f\n",*pFloat);
    return 0;
}
//answer :
//n=9
//pFloat= 0.000000
//num=1091567616
//*pFloat= 9.000000

//二进制的浮点数v在内存中可以写成下面形式：
//(-1)^S*M*2^E
//(-1)^S表示符号位，当s=0,v为正数；当s=1，v为负数。
//M表示有效数字，大于等于1，小于2
//2^E表示指数位

//9.0 
//1001.0 二进制
//（-1）^0 *1.001*2^3
//(-1)^0  *  M  *2^E

//IEEE 754规定 ： 对于32位的浮点数 ，最高的1位是符号位s,接着的8位是指数e，剩下的23位有效位为有效数字m
//对于64位的浮点数，最高位是符号位s,接着的是11位是指数e，剩下的52位为有效数字m

int main()
{
    float f=5.5;
    //5.5
    //101.1 二进制
    //(-1)^0*1.011*2^2
    //s=0
    //m=1.011
    //e=2   //2+127 =129  129的二进制是10000001
    //0 10000001 01100000000000000000000
    //0100 0000 1011 0000 0000 0000 0000 0000 
    //0x40b00000

    return 0;
}

//解析：
int main()
{
    int n=9;
    //00000000000000000000000000001001  -补码
    //
    float *pFloat =(float *)&n;
    printf("n=%d\n",n); //9
    printf("pFloat= %f\n",*pFloat);
    //00000000000000000000000000001001 看作浮点数
    //0 00000000 00000000000000000001001 
    //（-1）^0 * 0.00000000000000000000001001 * 2^-126
    //答案无限接近0

    *pFloat =9.0;
    //1001.0
    //1.001*2^3
    //(-1)^0*1.001*2^3
    //e =3   3+127 =130  130的二进制是 10000010
    // 0 10000010 00100000000000000000000
    printf("num=%d\n",n);
    //01000001000100000000000000000000
    //打印的是十进制， 上面的二进制数转化为10进制数是 1091567616
    printf("*pFloat= %f\n",*pFloat);
    return 0;
}