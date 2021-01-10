#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;


void showMenu()  {

	cout << "*************************" << endl;
	cout << "***** 1、添加联系人 ******" << endl;
	cout << "***** 2、显示联系人 ******" << endl;
	cout << "***** 3、删除联系人 ******" << endl;
	cout << "***** 4、查找联系人 ******" << endl;
	cout << "***** 5、修改联系人 ******" << endl;
	cout << "***** 6、清空联系人 ******" << endl;
	cout << "***** 0、退出通讯录 ******" << endl;
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
		case 1:  // 1、添加联系他
			break;
		case 2:  // 2、显示联系人
			break;
		case 3:  // 3、删除联系人
			break;
		case 4:  // 4、查找联系人
			break;
		case 5:  // 5、修改联系人
			break;
		case 6:  // 6、清空联系人
			break;
		case 0:  // 0、退出通讯录
			cout << "再见" << endl;
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
