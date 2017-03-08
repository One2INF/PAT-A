/*---------------------------------------------------------------

PAT A1125 Chain the Ropes
题意：绳子环环相扣，各段（halved）减半，求可能的最大长度；
题解：权为 1/2的赫尔曼树，取最小的两段配对成新的节点；
练习一下快速排序。

---------------------------------------------------------------*/

#include<iostream>
#include<fstream>
#include<math.h>

using namespace std;
//快速排序复杂度O(nlog(n))
void Quick_Sort(int(&Sequence)[10001], const int& Left, const int& Right)
{
	if (Left >= Right)
		return;
	int Low = Left, High = Right;
	Sequence[0] = Sequence[Low]; //取0位为枢轴
	while (Low < High)
	{
		while (Low < High && Sequence[High] >= Sequence[0])//左边 
			--High;
		Sequence[Low] = Sequence[High];
		while (Low < High && Sequence[Low] <= Sequence[0])//右边
			++Low;
		Sequence[High] = Sequence[Low];
	}
	Sequence[Low] = Sequence[0];              //枢轴归位

	int Center = Low;
	Quick_Sort(Sequence, Left, Center - 1);   //递归快速排序
	Quick_Sort(Sequence, Center + 1, Right);  //类似于递归建树，二分法递归查询
}

int main()
{

#ifdef _DEBUG
	ifstream cin("Input.txt");
	ofstream cout("Output.txt");
#endif

	int Number;
	cin >> Number;

	int Segments[10001];
	for (int i = 1; i <= Number; ++i)
		cin >> Segments[i];

	Quick_Sort(Segments, 1, Number);

	//	for (int i = 1; i <= Number; ++i)   //查看快速排序是否正确
	//		cout << Segments[i] << ' ';

	double Sum = Segments[1];
	for (int i = 2; i <= Number; ++i)
		Sum = 0.5 * (Sum + Segments[i]);

	cout << floor(Sum);                     //取整输出
	 
#ifdef _DEBUG
	cin.close();
	cout.close();
#endif

	return 0;
}