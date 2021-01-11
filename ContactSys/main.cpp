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
	short current_size = 0; // ��ǰ�������б�����
};


// �����ϵ��
void addContact(ContactsBook * p_cb)
{
	if (p_cb->current_size == MAX_CAPACITY_OF_CONTACTS_BOOK)
	{
		cout << "ͨѶ¼��������" << endl;
		return;
	}
	cout << "������������" << endl;
	string name;
	cin >> name;
	p_cb->personArr[p_cb->current_size].name = name;
	
	cout << "�������Ա�" << endl;
	cout << "1--��" << endl;
	cout << "2--Ů" << endl;
	short sex;
	while (true) 
	{
		cin >> sex;
		if (sex == 1) 
		{
			p_cb->personArr[p_cb->current_size].gender = "��";
			break;
		}
		if (sex == 2) 
		{
			p_cb->personArr[p_cb->current_size].gender = "Ů";
			break;
		}
		cout << "������������������Ա�" << endl;
		cout << "1--��" << endl;
		cout << "2--Ů" << endl;
	}

	cout << "���������䣺" << endl;
	short age;
	cin >> age;
	p_cb->personArr[p_cb->current_size].age = age;


	cout << "������绰���룺" << endl;
	string phone;
	cin >> phone;
	p_cb->personArr[p_cb->current_size].phone = phone;

	cout << "�������ַ��" << endl;
	string adr;
	cin >> adr;
	p_cb->personArr[p_cb->current_size].address = adr;
	p_cb->current_size++;
	cout << "~~~ ��ӳɹ� ~~~" << endl;
	system("pause"); // ����������� 
	system("cls"); // ��������
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
   ɾ����ϵ�ˣ��������ǰ���������ɾ����ϵ��
*/
void delContact(ContactsBook * p_cb) 
{
	string name;
	cout << " ������Ҫɾ������Ա������" << endl;
	cin >> name;
	int index = isExist(p_cb, name);
	if (index != -1)
	{
		for (int i = index ;i <p_cb->current_size ; i++)
		{
			p_cb->personArr[i] = p_cb->personArr[i+1];
		}
		--p_cb->current_size;
		cout << "~~~ɾ���ɹ�~~~" << endl;
	}
	else
	{
		cout << " ���޴���" << endl;
	}
	system("pause");
	system("cls");
	
}


void showAllContacts(ContactsBook* p_cb)
{
	if (p_cb->current_size == 0)
	{
		cout << " ������ϵ��" << endl;
		return;
	}

	for (int i = 0; i < p_cb->current_size; i++)
	{
	 Person person =p_cb->personArr[i];
	// cout << person.name << " " << person.gender << " " << person.age << " " << person.phone << " " << person.address << endl;
	 cout << person.name << "\t";
	 cout << person.gender << "\t";
	 cout << person.age << "\t";
	 cout << person.phone << "\t";
	 cout << person.address << endl;
	}
	system("pause");
	system("cls");

}

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

void showSys(ContactsBook* p_cb)
{
	short select = -1;
	do
	{
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1:  // 1�������ϵ��
			addContact(p_cb);
			break;
		case 2:  // 2����ʾ��ϵ��
			showAllContacts(p_cb);
			break;
		case 3:  // 3��ɾ����ϵ��
			delContact(p_cb);
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
		default:
			cout << "��Ч���룬����������~" << endl;
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
