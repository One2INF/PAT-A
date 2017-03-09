/*--------------------------------------------------

	2017/03/06
	A1124 Raffle for Weibo Followers
	题意：M个帖子，第一个win为S，之后每第N个win；
             若有获奖者重复，则++；

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

	int Forwards_Number, Skip_Number, Index;//跟帖数，间隔，第一个win的下标
	cin >> Forwards_Number >> Skip_Number >> Index;

	if (Forwards_Number < Index)//若帖数不够，则输出
	{
		cout << "Keep going...\n";
		return 0;
	}

	string Nickname[1001];//输入各个用户名
	for (int i = 1; i <= Forwards_Number; ++i)	
		cin >> Nickname[i];

	int Count_Winner = 0;//已获奖人数
	string Winner_Name[1001];//已获奖者序列
	bool Ifsame;//是否已获奖
	while (Index <= Forwards_Number)
	{
		do
		{
			Ifsame = false;
			for (int j = 1; j <= Count_Winner; ++j)
				if (Nickname[Index] == Winner_Name[j])
				{
					Ifsame = true;
					++Index;//相同，判断下一个
					if (Index == Forwards_Number + 1)//寻找下个溢出时，结束程序
						return 0;
					break;
				}
		} while (Ifsame);//循环查询选中的用户是否获奖
	
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
