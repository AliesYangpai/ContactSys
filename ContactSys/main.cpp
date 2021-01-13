#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#define MAX_CAPACITY_OF_CONTACTS_BOOK 1000
using namespace std;


struct Person
{
	string name;
	short age;
	string  gender;
	string phone;
	string address;
};

struct ContactsBook 
{
	struct Person personArr[MAX_CAPACITY_OF_CONTACTS_BOOK];
	short current_size = 0; // 当前的人数列表数量
};

void showText(const char* p_text)
{
	cout << p_text << endl;
}

// 添加联系人
void addContact(ContactsBook * p_cb)
{
	if (p_cb->current_size == MAX_CAPACITY_OF_CONTACTS_BOOK)
	{
		cout << "通讯录人数已满" << endl;
		return;
	}
	cout << "请输入姓名：" << endl;
	string name;
	cin >> name;
	p_cb->personArr[p_cb->current_size].name = name;
	
	cout << "请输入性别：" << endl;
	cout << "1--男" << endl;
	cout << "2--女" << endl;
	short sex;
	while (true) 
	{
		cin >> sex;
		if (sex == 1) 
		{
			p_cb->personArr[p_cb->current_size].gender = "男";
			break;
		}
		if (sex == 2) 
		{
			p_cb->personArr[p_cb->current_size].gender = "女";
			break;
		}
		cout << "输入错误，请重新输入性别：" << endl;
		cout << "1--男" << endl;
		cout << "2--女" << endl;
	}

	cout << "请输入年龄：" << endl;
	short age;
	cin >> age;
	p_cb->personArr[p_cb->current_size].age = age;


	cout << "请输入电话号码：" << endl;
	string phone;
	cin >> phone;
	p_cb->personArr[p_cb->current_size].phone = phone;

	cout << "请输入地址：" << endl;
	string adr;
	cin >> adr;
	p_cb->personArr[p_cb->current_size].address = adr;
	p_cb->current_size++;
	cout << "~~~ 添加成功 ~~~" << endl;
	system("pause"); // 按任意键继续 
	system("cls"); // 清屏操作
}

short isExist(const ContactsBook * p_cb, string enterName)
{
	short result = -1;
	for (int i = 0; i < p_cb->current_size; i++)
	{
		if (p_cb->personArr[i].name == enterName)
		{
			result = i;
			break;
		}
	}
	return result;
}


/*
   删除联系人，这里我们按照姓名来删除联系人
*/
void delContact(ContactsBook * p_cb) 
{
	string name;
	cout << " 请输入要删除的人员姓名：" << endl;
	cin >> name;
	int index = isExist(p_cb, name);
	if (index != -1)
	{
		for (int i = index ;i <p_cb->current_size ; i++)
		{
			p_cb->personArr[i] = p_cb->personArr[i+1];
		}
		--p_cb->current_size;
		cout << "~~~删除成功~~~" << endl;
	}
	else
	{
		cout << " 查无此人" << endl;
	}
	system("pause");
	system("cls");
	
}

/*
 显示单个信息
*/
void showSingleContact(const Person* p_person)
{
	cout << p_person->name << "\t";
	cout << p_person->gender << "\t";
	cout << p_person->age << "\t";
	cout << p_person->phone << "\t";
	cout << p_person->address << endl;
}
/*
  此处就按照练习人姓名搜索
*/
void doSelectContact(ContactsBook * p_cb) 
{
	cout << " 请输入联系人完整姓名：" << endl;
	string name;
	cin >> name;
  int index =isExist(p_cb,name);
	if (index != -1)
	{
		cout << " 查询结果如下：" << endl;
		showSingleContact(&(p_cb->personArr[index]));
	}
	else
	{
		cout << " 无此联系人" << endl;
	}
	system("pause");
	system("cls");

}

void showAllContacts(ContactsBook* p_cb)
{
	if (p_cb->current_size == 0)
	{
		cout << " 暂无联系人" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << " 查询结果如下：" << endl;
	for (int i = 0; i < p_cb->current_size; i++)
	{
	 Person person =p_cb->personArr[i];
	 showSingleContact(&person);
	}
	system("pause");
	system("cls");

}


void doModifyContact(ContactsBook* p_cb)  

{
	cout << " 请输入要修改的联系人姓名：" << endl;
	string name;
	cin >> name;
	int	index = isExist(p_cb, name);

	if (index != -1)
	{
		cout << " 要修改的人员信息如下：" << endl;
		showSingleContact(&(p_cb->personArr[index]));
		
		cout << " 请输入新姓名：" << endl;
		string newName;
		cin >> newName;
		p_cb->personArr[index].name = newName;

		cout << " 请输入新性别" << endl;
		while (true)
		{
			cout << "1--男" << endl;
			cout << "2--女" << endl;
			short newGender;
			cin >> newGender;
			if (newGender == 1 || newGender == 2)
			{
				p_cb->personArr[index].gender = newGender == 1 ? "男" : "女";
				break;
			}
			cout << " 输入不合法，请重新输入：" << endl;
		}

		cout << " 请输入新年龄：" << endl;
		short newAge;
		cin >> newAge;
		p_cb->personArr[index].age = newAge;


		cout << " 请输入新的电话号码：" << endl;
		string newNum;
		cin >> newNum;
		p_cb->personArr[index].phone = newNum;

		cout << " 请输入新的地址：" << endl;
		string newAddress;
		cin >> newAddress;
		p_cb->personArr[index].address = newAddress;

		cout << "~~更新完成~~" << endl;

		system("pause");
		system("cls");
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}


void doClearAllContacts(ContactsBook * p_cb) 
{
	cout << " 确认清空联系人吗？（Y/N）" << endl;
	char enter;
	cin >> enter;
	if (enter == 'Y')
	{
		for (int i = 0; i < p_cb->current_size; i++)
		{
			//p_cb->personArr[i] = { 0 };
			memset(&(p_cb->personArr[i]),0,sizeof(p_cb->personArr[i]));
		}
	
		p_cb->current_size = 0;
		cout << "联系人已清空" << endl;
	}

	system("pause");
	system("cls");
}

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

void showSys(ContactsBook* p_cb)
{
	short select = -1;
	do
	{
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1:  // 1、添加联系人
			addContact(p_cb);
			break;
		case 2:  // 2、显示联系人
			showAllContacts(p_cb);
			break;
		case 3:  // 3、删除联系人
			delContact(p_cb);
			break;
		case 4:  // 4、查找联系人
			doSelectContact(p_cb);
			break;
		case 5:  // 5、修改联系人
			doModifyContact(p_cb);
			break;
		case 6:  // 6、清空联系人
			doClearAllContacts(p_cb);
			break;
		case 0:  // 0、退出通讯录
			cout << "再见" << endl;
			system("pause");
			break;
		default:
			cout << "无效输入，清重新输入~" << endl;
			system("pause");
			system("cls");
			break;
		}
	} while (select != 0);
}

int main() 
{
	ContactsBook cb;
	showSys(&cb);
	return 0;
}
