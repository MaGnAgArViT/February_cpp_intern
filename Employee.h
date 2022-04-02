#include<iostream>

using namespace std;

template <class T>
class Employee{
	protected:
		int id;
		string name;
		int age;
	public:
		void set_name(string n)
		{
			name = n;
		}
		void set_id(int i)
		{
			id = i;
		}
		void set_age(int i)
		{
			age = i;
		}
		int ret_id()
		{
			return id;
		}
		int ret_age()
		{
			return age;
		}
		string ret_name()
		{
			return name;
		}
		void add_employee(int i,string n,int a)
		{
			id = i;
			name = n;
			age = a;
		}
		void edit_name(string n)
		{
			char c;
			cout<<"\n\t\t\t\tRecord of id : "<<id;
			cout<<"\n\t\t\t\tName : "<<name;
			cout<<"\n\t\t\t\tAge : "<<age;
			cout<<"\n\t\t\t\tAre You Sure To Rename (Y/N) :";
			cin>>c;
			if(c == 'Y' || c == 'y')
				name = n;
		}
		void edit_age(int a)
		{
			char c;
			cout<<"\n\t\t\t\tRecord of id : "<<id;
			cout<<"\n\t\t\t\tName : "<<name;
			cout<<"\n\t\t\t\tAge : "<<age;
			cout<<"\n\t\t\t\tAre You Sure To Edit Age (Y/N) :";
			cin>>c;
			if(c == 'Y' || c == 'y')
				age = a;
		}
		void operator = (Employee temp)
		{
			id = temp.id;
			age = temp.age;
			name = temp.name;
		}
		void display() 
		{
			cout<<"\n\t\t\t"<<id<<"\t"<<name<<"\t\t\t"<<age;
		}
};
