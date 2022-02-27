#include<iostream>
#include<windows.h>
#include<conio.h>
#include<string>
#include"Employee.h"
#include"Department.h"

using namespace std;

template<class T>
class EmployeeManagement : public Employee<T>
{
	private:
		int size;
		int count;
		EmployeeManagement<T> *rec;
	public:
		void add_memb();
		void edit_memb(string type);
		void delete_rec();
		void disp()
		{
			cout<<"\n\t\t\tID\tName\t\t\t\tAge";
			for(int i=0 ; i<count ; i++)
				rec[i].display();
		}
		void sort();
		void menu();
		void head();
};

template<class T>
void EmployeeManagement<T>::add_memb()
{
	if(count>=size-1)
	{
		cout<<"\t\t\t\tOverflow occured!!";
		return;
	}
	string n;
	int a;
	cout<<"\t\t\t\tEnter new name : ";
	fflush(stdin);
	getline(cin,n);
	for(int i=0 ; i<count ; i++)
	{
		if(rec[i].ret_name()==n)
		{
			cout<<"\t\t\t\tRecord already exist!!";
			return;
		}
	}
	fflush(stdin);
	cout<<"\t\t\t\tenter age : ";
	cin>>a;
	int max;
	(count == 0)?max=0:max=rec[count-1].id;
	rec[count++].add_employee(max+1,n,a);
}

template<class T>
void EmployeeManagement<T>::edit_memb(string type)
{
	int id;
	string n;
	int a;
	bool flag;
	if(type == "name")
	{
		cout<<"\t\t\t\tEnter id : ";
		cin>>id;
		cout<<"\t\t\t\tEnter new name : ";
		fflush(stdin);
		getline(cin,n);
		flag = true;
		for(int i=0 ; i<count&&flag ; i++)
		{
			if(rec[i].ret_name()==n)
			{
				cout<<"\t\t\t\tRecord already exist!!";
				flag = false;
				break;
			}
		}
		if(flag)
		{
			flag = true;
			for(int i=0 ; i<count ; i++)
			if(id == rec[i].ret_id())
			{
				flag = false;
				rec[i].edit_name(n);
				break;	
			}
			if(flag)
			cout<<"\t\t\t\trecord not found!!";
		}
	}
	if(type == "age")
	{
		cout<<"\t\t\t\tEnter id : ";
		cin>>id;
		cout<<"\t\t\t\tEnter new age : ";
		cin>>a;
		flag = true;
		for(int i=0 ; i<count ; i++)
			if(id == rec[i].ret_id())
			{
				flag = false;
				rec[i].edit_age(a);
				break;	
			}
		if(flag)
		cout<<"record not found!!";
	}
}

template<class T>
void EmployeeManagement<T>::delete_rec()
{
	int id;
	bool flag = true;
	char c;
	cout<<"\t\t\t\tEnter id : ";
	cin>>id;
	for(int i=0 ; i<count ; i++)
		if(id == rec[i].ret_id())
		{
			flag = false;
			cout<<"\n\t\t\t\tRecord of id : "<<rec[i].ret_id();
			cout<<"\n\t\t\t\tName : "<<rec[i].ret_name();
			cout<<"\n\t\t\t\tAre You Sure To delete this record (Y/N) :";
			cin>>c;
			if(c == 'Y' || c == 'y')
			{
				for(int j=i ; i<count-1 ; i++)
				{
					rec[i].set_name(rec[i+1].ret_name());
					rec[i].set_id(rec[i+1].ret_id());
					rec[i].set_age(rec[i+1].ret_age());
				}
				count--;
			}
			break;	
		}
	if(flag)
		cout<<"record not found!!";
}

template<class T>
void EmployeeManagement<T>::sort()
{
	EmployeeManagement<T> temp;
	for(int i=1 ; i<count ; i++)
	{
		temp.set_name(rec[i].ret_name());
		temp.set_id(rec[i].ret_id());
		temp.set_age(rec[i].ret_age());
		int j=i-1;
		while(temp.ret_name()<rec[j].ret_name() && j>-1)
		{
			rec[j+1].set_name(rec[j].ret_name());
			rec[j+1].set_id(rec[j].ret_id());
			rec[j+1].set_age(rec[j].ret_age());
			j--;
		}
		rec[j+1].set_name(temp.ret_name());
		rec[j+1].set_id(temp.ret_id());
		rec[j+1].set_age(temp.ret_age());
	}
}

template<class T>
void EmployeeManagement<T>::menu()
{
	system("CLS");
	cout<<"\n\t\t\t\t\tMenu";
	cout<<"\n\t\t\t\tEnter 1 : To add employee";
	cout<<"\n\t\t\t\tEnter 2 : To edit name";
	cout<<"\n\t\t\t\tEnter 3 : To edit age";
	cout<<"\n\t\t\t\tEnter 4 : To delete";
	cout<<"\n\t\t\t\tEnter 5 : To list all employees";
	cout<<"\n\t\t\t\tEnter 6 : To sort all among name";
	cout<<"\n\t\t\t\tEnter e : To Exit";
}

template<class T>
void EmployeeManagement<T>::head()
{
	count = 0;
	cout<<"\t\t\t\tenter size of array : ";
	cin>>size;
	rec = new EmployeeManagement<int>[size];
	char choice;
	do
	{
		menu();
		cout<<"\n\t\t\t\tEnter your choice : ";
		cin>>choice;
		switch(choice)
		{
			case'1':add_memb();
					break;
			case'2':edit_memb("name");
					break;
			case'3':edit_memb("age");
					break;
			case'4':delete_rec();
					break;
			case'5':disp();
					break;
			case'6':sort();
					break;
			case'e':
			case'E':cout<<"\t\t\t\tGood Bye!!";
					return;
			default:cout<<"\t\t\t\tInvalid Choice!!";
		}
		getch();
	}
	while(true);
}

template<class T>
class DepartmentManagement : public Department<T>
{
	private:
		int size;
		int count;
		DepartmentManagement<T> *rec;
	public:
		void add_dept();
		void edit_dept();
		void delete_rec();
		void disp()
		{
			cout<<"\n\t\t\tID\tName";
			for(int i=0 ; i<count ; i++)
				rec[i].display();
		}
		void sort();
		void menu();
		void head();
};

template<class T>
void DepartmentManagement<T>::add_dept()
{
	if(count>=size-1)
	{
		cout<<"\t\t\t\tOverflow occured!!";
		return;
	}
	string n;
	cout<<"\t\t\t\tEnter new name : ";
	fflush(stdin);
	getline(cin,n);
	for(int i=0 ; i<count ; i++)
	{
		if(rec[i].ret_name()==n)
		{
			cout<<"\t\t\t\tRecord already exist!!";
			return;
		}
	}
	int max;
	(count == 0)?max=0:max=rec[count-1].id;
	rec[count++].add_department(max+1,n);
}

template<class T>
void DepartmentManagement<T>::edit_dept()
{
	int id;
	string n;
	bool flag;
	cout<<"\t\t\t\tEnter id : ";
	cin>>id;
	cout<<"\t\t\t\tEnter new name : ";
	fflush(stdin);
	getline(cin,n);
	for(int i=0 ; i<count ; i++)
	{
		if(rec[i].ret_name()==n)
		{
			cout<<"\t\t\t\tRecord already exist!!";
			flag = false;
			return;
		}
	}
	flag = true;
	for(int i=0 ; i<count ; i++)
	if(id == rec[i].ret_id())
	{
		flag = false;
		rec[i].edit_name(n);
		break;	
	}
	if(flag)
		cout<<"\t\t\t\trecord not found!!";
}

template<class T>
void DepartmentManagement<T>::delete_rec()
{
	int id;
	bool flag = true;
	char c;
	cout<<"\t\t\t\tEnter id : ";
	cin>>id;
	for(int i=0 ; i<count ; i++)
		if(id == rec[i].ret_id())
		{
			flag = false;
			cout<<"\n\t\t\t\tRecord of id : "<<rec[i].ret_id();
			cout<<"\n\t\t\t\tName : "<<rec[i].ret_name();
			cout<<"\n\t\t\t\tAre You Sure To delete this record (Y/N) :";
			cin>>c;
			if(c == 'Y' || c == 'y')
			{
				for(int j=i ; i<count-1 ; i++)
				{
					rec[i].set_name(rec[i+1].ret_name());
					rec[i].set_id(rec[i+1].ret_id());
				}
				count--;
			}
			break;	
		}
	if(flag)
		cout<<"record not found!!";
}

template<class T>
void DepartmentManagement<T>::sort()
{
	EmployeeManagement<T> temp;
	for(int i=1 ; i<count ; i++)
	{
		temp.set_name(rec[i].ret_name());
		temp.set_id(rec[i].ret_id());
		int j=i-1;
		while(temp.ret_name()<rec[j].ret_name() && j>-1)
		{
			rec[j+1].set_name(rec[j].ret_name());
			rec[j+1].set_id(rec[j].ret_id());
			j--;
		}
		rec[j+1].set_name(temp.ret_name());
		rec[j+1].set_id(temp.ret_id());
	}
}

template<class T>
void DepartmentManagement<T>::menu()
{
	system("CLS");
	cout<<"\n\t\t\t\t\tMenu";
	cout<<"\n\t\t\t\tEnter 1 : To add department";
	cout<<"\n\t\t\t\tEnter 2 : To edit name";
	cout<<"\n\t\t\t\tEnter 3 : To delete";
	cout<<"\n\t\t\t\tEnter 4 : To list all departments";
	cout<<"\n\t\t\t\tEnter 5 : To sort all among name";
	cout<<"\n\t\t\t\tEnter e : To Exit";
}

template<class T>
void DepartmentManagement<T>::head()
{
	count = 0;
	cout<<"\t\t\t\tenter size of array : ";
	cin>>size;
	rec = new DepartmentManagement<T>[size];
	char choice;
	do
	{
		menu();
		cout<<"\n\t\t\t\tEnter your choice : ";
		cin>>choice;
		switch(choice)
		{
			case'1':add_dept();
					break;
			case'2':edit_dept();
					break;
			case'3':delete_rec();
					break;
			case'4':disp();
					break;
			case'5':sort();
					break;
			case'e':
			case'E':cout<<"\t\t\t\tGood Bye!!";
					return;
			default:cout<<"\t\t\t\tInvalid Choice!!";
		}
		getch();
	}
	while(true);
}

void menu()
{
	system("CLS");
	cout<<"\n\t\t\t\t\tMenu";
	cout<<"\n\t\t\t\tEnter 1 : For employee";
	cout<<"\n\t\t\t\tEnter 2 : For department";
	cout<<"\n\t\t\t\tEnter e : To Exit";
}

void head()
{
	EmployeeManagement<int> e;
	DepartmentManagement<int> d;
	char ch;
	do
	{
		menu();
		cout<<"\n\t\t\t\tEnter your choice : ";
		cin>>ch;
		switch(ch)
		{
			case'1':e.head();
					break;
			case'2':d.head();
					break;
			case'e':
			case'E':cout<<"\t\t\t\tGood Bye!!";
					return;
			default:cout<<"\t\t\t\tInvalid Choice!!";
		}
		getch();
	}
	while(true);
}

int main()
{
	head();
	return 0;
}
