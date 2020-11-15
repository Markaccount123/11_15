#define _CRT_SECURE_N0_WARNINGS 1
#include<stdio.h>
//对于指针来说真正的难点到底在哪一块，这一次一定要彻底的扫除掉

//1.字符指针
//2.数组指针
//3.指针数组
//4.数组传参和指针传参
//5.函数指针
//6.函数指针数组
//7.指向函数指针数组的指针
//8.回调函数
//9.指针和数组中面试题解析

//字符指针
//int main()
//{
//	char* p = "abcdef";  //这是一个常量字符串，意思并不是把"abcdef"传给指针p，因为在32位平台指针只占4个字节，而这个都有6个
//	//字节了，所以他的意思是把首字符的地址传给了a
//	//printf("%c\n", *p);     a
//	printf("%s\n", p);  //  "abcdef"
//}
//
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "abcdef";
//	char* p1 = "abcdef";
//	char* p2 = "abcdef";
//	if (p1 == p2)
//	{
//		printf("hehe\n");
//	}
//	else
//	{
//		printf("haha\n");        //结果会是hehe 因为他们都是常量字符串，所以两个指针值向的是同一个空间
//	}
//
//	if (arr1 == arr2)
//	{
//		printf("hehe\n");
//	}
//	else
//	{
//		printf("haha\n");
//	}           结果会是haha 因为arr1 和 arr2分别指向了两个不同地址空间
//	return 0;
//}

//2.指针数组 --- 核心是数组，用来存放指针的
//int main()
//{
//	int arr[10] = { 0 }; // 整形数组
//	char ch[5] = { 0 };//字符数组
//	int* parr[4]; //存放整形指针的数组 -- 指针数组
//	char* pch[5];//存放字符指针的数组 -- 指针数组
//}
//指针数组的使用
//int main()
//{
//	int arr1[] = { 1, 2, 3, 4, 5 };
//	int arr2[] = { 2, 3, 4, 5, 6 };
//	int arr3[] = { 3, 4, 5, 6, 7 };
//
//	int* parr[] = { arr1, arr2, arr3 };
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 5; j++)
//		{
//			printf("%d ", *(parr[i] + j));
//		}
//		printf("\n");
//	}
//	return 0;
//}

//3.数组指针 -- 本质是指针
//int main()
//{
//	int* p = NULL; //p是整形指针--指向整形的指针--可以存放整形的地址
//	char* pc = NULL;//pc是字符指针--指向字符的指针--可以存放字符的地址
//	                //数组指针--指向数组的指针--存放数组的地址
//	//arr -- 首元素地址 
//	//&arr[0] --首元素的地址
//	//&arr --数组的地址
//	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int(*p)[10] = &arr; //数组的地址要存起来
//	//如果不加()p会先和[]进行结合就会变成指针数组
//}



//对于二维数组来说，你需要把二维数组想象成为一维数组，第一行是第一个元素，第二行是第二个元素 ...来思考
//void print1(int arr[3][5], int x, int y)
//{
//	int i = 0;
//	for (i = 0; i < x; i++)
//	{
//		int j = 0;
//		for (j = 0; j < y; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//}
//
//void print2(int(*p)[5], int x, int y)
//{
//	int i = 0;
//	for (i = 0; i < x; i++)
//	{
//		int j = 0;
//		for (j = 0; j < y; j++)
//		{
//			printf("%d ", *(*(p + i) + j));
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int arr[3][5] = { { 1, 2, 3, 4, 5 }, { 2, 3, 4, 5, 6 }, { 3, 4, 5, 6, 7 } };
//	print1(arr, 3, 5); // 这里有两种设计方案，对于这个可以认为传过去的是一个二维数组
//	print2(arr, 3, 5); // 这里可以认为arr代表的是第一行的地址，也就是数组指针
//	return 0;
//}
//
//arr[i] == *(arr+i)  以arr为起始地址访问下标为i的元素

//函数指针--是指向函数的指针--存放函数地址的指针
//在函数里面   &函数名  和 函数名  都是函数的地址

//int Add(int x,int y)
//{
//	return x + y;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;//对于传参部分类型一定要表达清楚，但是可以省略参数
//	int(*pa)(int, int) = Add;  // 
//	printf("%d\n", (*pa)(a, b));
//	return 0;
//}
//
//void Print(char* str)
//{
//	printf("%s\n", str);
//}
//int main()
//{
//	void(*p)(char*) = Print;
//	(*p)("hello world");
//	return 0;
//}

//(*(void(*)()) 0) ()   把0地址强制类型转换为void(*)()的函数指针类型，然后解引用，在调用这个函数

//void (*signal(int,void(*)(int)))(int)

//signal是一个函数名，里面的参数一个是int，一个是void(*)(int),然后你去掉函数名和参数，你会发现返回类型是
//void(*                     )(int) 的类型

//所以这里我们可以重命名void(*)(int)类型，可以使代码看起来更加的整洁
//typedef void(*pfun_t)(int);
//typedef unsigned int uint; 
//你认为我们一般重命名应该是把pfun_t放在最后面，但是对于函数指针来重命名是不一样的，他需要放在函数名的位置

//所以我们可以把上面那个晦涩的代码修改为
//pfun_t signed(int, pfun_t);


int Add(int x, int y)
{
	return x + y;
}
int Sub(int x, int y)
{
	return x - y;
}
int Mul(int x, int y)
{
	return x * y;
}
int Div(int x, int y)
{
	return x / y;
}
int main()
{
	//需要一个数组，这个数组可以存放4个函数的地址 --- 函数指针的数组
	int(*pa[4])(int, int) = { Add, Sub, Mul, Div }; // 这里[]的优先级更高所以pa回西安和它结合形成一个数组，剩下的类型就是
	//函数指针类型
	int i = 0;
	for (i = 0; i < 4; i++)
	{
		printf("%d\n", pa[i](2, 3));
	}
	return 0;
}