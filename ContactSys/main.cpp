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

void showText(const char* p_text)
{
	cout << p_text << endl;
}

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

/*
 ��ʾ������Ϣ
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
  �˴��Ͱ�����ϰ����������
*/
void doSelectContact(ContactsBook * p_cb) 
{
	cout << " ��������ϵ������������" << endl;
	string name;
	cin >> name;
  int index =isExist(p_cb,name);
	if (index != -1)
	{
		cout << " ��ѯ������£�" << endl;
		showSingleContact(&(p_cb->personArr[index]));
	}
	else
	{
		cout << " �޴���ϵ��" << endl;
	}
	system("pause");
	system("cls");

}

void showAllContacts(ContactsBook* p_cb)
{
	if (p_cb->current_size == 0)
	{
		cout << " ������ϵ��" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << " ��ѯ������£�" << endl;
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
	cout << " ������Ҫ�޸ĵ���ϵ��������" << endl;
	string name;
	cin >> name;
	int	index = isExist(p_cb, name);

	if (index != -1)
	{
		cout << " Ҫ�޸ĵ���Ա��Ϣ���£�" << endl;
		showSingleContact(&(p_cb->personArr[index]));
		
		cout << " ��������������" << endl;
		string newName;
		cin >> newName;
		p_cb->personArr[index].name = newName;

		cout << " ���������Ա�" << endl;
		while (true)
		{
			cout << "1--��" << endl;
			cout << "2--Ů" << endl;
			short newGender;
			cin >> newGender;
			if (newGender == 1 || newGender == 2)
			{
				p_cb->personArr[index].gender = newGender == 1 ? "��" : "Ů";
				break;
			}
			cout << " ���벻�Ϸ������������룺" << endl;
		}

		cout << " �����������䣺" << endl;
		short newAge;
		cin >> newAge;
		p_cb->personArr[index].age = newAge;


		cout << " �������µĵ绰���룺" << endl;
		string newNum;
		cin >> newNum;
		p_cb->personArr[index].phone = newNum;

		cout << " �������µĵ�ַ��" << endl;
		string newAddress;
		cin >> newAddress;
		p_cb->personArr[index].address = newAddress;

		cout << "~~�������~~" << endl;

		system("pause");
		system("cls");
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}


void doClearAllContacts(ContactsBook * p_cb) 
{
	cout << " ȷ�������ϵ���𣿣�Y/N��" << endl;
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
		cout << "��ϵ�������" << endl;
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
			doSelectContact(p_cb);
			break;
		case 5:  // 5���޸���ϵ��
			doModifyContact(p_cb);
			break;
		case 6:  // 6�������ϵ��
			doClearAllContacts(p_cb);
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
