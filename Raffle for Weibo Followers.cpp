/*--------------------------------------------------

	2017/03/06
	A1124 Raffle for Weibo Followers
	���⣺M�����ӣ���һ��winΪS��֮��ÿ��N��win��
		  ���л����ظ�����++��

--------------------------------------------------*/

#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int main()
{

#ifdef _DEBUG
	ifstream cin("Input.txt");
#endif

	int Forwards_Number, Skip_Number, Index;//���������������һ��win���±�
	cin >> Forwards_Number >> Skip_Number >> Index;

	if (Forwards_Number < Index)//�����������������
	{
		cout << "Keep going...\n";
		return 0;
	}

	string Nickname[1001];//��������û���
	for (int i = 1; i <= Forwards_Number; ++i)	
		cin >> Nickname[i];

	int Count_Winner = 0;//�ѻ�����
	string Winner_Name[1001];//�ѻ�������
	bool Ifsame;//�Ƿ��ѻ�
	while (Index <= Forwards_Number)
	{
		do
		{
			Ifsame = false;
			for (int j = 1; j <= Count_Winner; ++j)
				if (Nickname[Index] == Winner_Name[j])
				{
					Ifsame = true;
					++Index;//��ͬ���ж���һ��
					if (Index == Forwards_Number + 1)//Ѱ���¸����ʱ����������
						return 0;
					break;
				}
		} while (Ifsame);//ѭ����ѯѡ�е��û��Ƿ��
	
		++Count_Winner;
		Winner_Name[Count_Winner] = Nickname[Index];
		cout << Winner_Name[Count_Winner] << endl;
		Index += Skip_Number;
	}

#ifdef _DEBUG
	cin.close();
#endif

	return 0;
}