/*---------------------------------------------------------------

PAT A1125 Chain the Ropes
���⣺���ӻ�����ۣ����Σ�halved�����룬����ܵ���󳤶ȣ�
��⣺ȨΪ 1/2�ĺն�������ȡ��С��������Գ��µĽڵ㣻
��ϰһ�¿�������

---------------------------------------------------------------*/

#include<iostream>
#include<fstream>
#include<math.h>

using namespace std;
//���������Ӷ�O(nlog(n))
void Quick_Sort(int(&Sequence)[10001], const int& Left, const int& Right)
{
	if (Left >= Right)
		return;
	int Low = Left, High = Right;
	Sequence[0] = Sequence[Low]; //ȡ0λΪ����
	while (Low < High)
	{
		while (Low < High && Sequence[High] >= Sequence[0])//��� 
			--High;
		Sequence[Low] = Sequence[High];
		while (Low < High && Sequence[Low] <= Sequence[0])//�ұ�
			++Low;
		Sequence[High] = Sequence[Low];
	}
	Sequence[Low] = Sequence[0];              //�����λ

	int Center = Low;
	Quick_Sort(Sequence, Left, Center - 1);   //�ݹ��������
	Quick_Sort(Sequence, Center + 1, Right);  //�����ڵݹ齨�������ַ��ݹ��ѯ
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

	//	for (int i = 1; i <= Number; ++i)   //�鿴���������Ƿ���ȷ
	//		cout << Segments[i] << ' ';

	double Sum = Segments[1];
	for (int i = 2; i <= Number; ++i)
		Sum = 0.5 * (Sum + Segments[i]);

	cout << floor(Sum);                     //ȡ�����
	 
#ifdef _DEBUG
	cin.close();
	cout.close();
#endif

	return 0;
}