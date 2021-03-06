#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

数据类型有很多种如 字符类型，整形，浮点型，双精度浮点型等
但是没有字符串类型！

字符串是：双引号引起来一串的字符称为字符串面值，简称字符串 如"abcd"  "hello world"  ""（空字符串）

那么如何表示字符串类型呢？
用双引号（英文）引用一串字符（或这空白）




int main()
{
	char ar1[] = "abc" ;
	char ar2[] = { 'a','b','c' };
	printf("%s\n",ar1);
	printf("%s\n",ar2);
	return 0;
}

上述代码打印结果：
abc
abc烫烫烫烫蘟bc



为什么第一个成果而第二个是乱码呢？
通过F10单步执行 在“调试”选项选择“窗口”再选择“监视”到“监视1”就可以调用监视窗口
输入你要监视的项目，再通过F10走完程序，你会发现“ar1”其实是有4个元素组成的'a' 'b' 'c' '\0'
而“ar2”则有3个元素组成'a' 'b' 'c'."ar1"比"ar2"多了个'\0'(\0这是字符串结束的标志)
当我们输入字符串的时候其是不止是'a''b''c'3个元素，末尾还有个'\0'(\0其实也是个字符，不过这个字符的值是0）
“ar2”中当打印了'a''b''c'3个字符后后面没有\0这个结束标志，机器就会一直打印知道出现0（具体多少不知道）
所以才会出现烫烫的结果。


Fix

int main()
{
	char ar1 []= "abc";
	char ar2 []= { 'a','b','c','\0'};   //  0也是可以作为\0，不过最好是放\0
	printf("%s\n",ar1);
	printf("%s\n",ar2);

	return 0;
}


字符串的结束标志是一个\0的转义字符。在计算字符串长度的时候\0是结束标志，不算作为字符串内容。



小知识点

数据在计算机存储的时候，存储的是二进制，给字符编值，再变成二进制数进行存储

比如
'\0' - 0
'a'  - 97   97就是代表a
'A'  - 67

每个字符都编值叫二次编码，这些码值就叫ASCII 码值（ASCII表每个字符都有对应的值）



int main()
{
	char ar1[] = "abc";
	char ar2[] = { 'a','b','c' };
	printf("%d\n", strlen(ar1));//strlen -string length 即计算字符串的长度
	printf("%d\n", strlen(ar2));

	return 0;
}


打印的结果是3；15
分析：第一个ar1，是一个字符串。当计算了abc3个值后还存在有一个\0，结束计算
      第二个ar2 则在计算完字符abc后它没有0或者\0结束计算，就仍然会计算下去直到找到0或者\0才结束。
	  
总结：所以第一个数组的常度是该字符串的字符长度；而第二个数组的长度则为随机值
