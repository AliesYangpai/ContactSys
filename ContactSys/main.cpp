#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;


void showMenu()  {

	cout << "*************************" << endl;
	cout << "***** 1�������ϵ�� ******" << endl;
	cout << "***** 2����ʾ��ϵ�� ******" << endl;
	cout << "***** 3��ɾ����ϵ�� ******" << endl;
	cout << "***** 4��������ϵ�� ******" << endl;
	cout << "***** 5���޸���ϵ�� ******" << endl;
	cout << "***** 6�������ϵ�� ******" << endl;
	cout << "***** 0���˳�ͨѶ¼ ******" << endl;
	cout << "*************************" << endl;
}

void showSys()
{
	short select = -1;
	do
	{
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1:  // 1�������ϵ��
			break;
		case 2:  // 2����ʾ��ϵ��
			break;
		case 3:  // 3��ɾ����ϵ��
			break;
		case 4:  // 4��������ϵ��
			break;
		case 5:  // 5���޸���ϵ��
			break;
		case 6:  // 6�������ϵ��
			break;
		case 0:  // 0���˳�ͨѶ¼
			cout << "�ټ�" << endl;
			system("pause");
			break;
		}
	} while (select != 0);
}

int main() 
{
	showSys();
	return 0;
}
