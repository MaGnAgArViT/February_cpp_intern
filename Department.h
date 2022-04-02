#include<iostream>

using namespace std;


template<class T>
class Department{
	protected:
		string name;
		int id;
	public:
		void set_name(string n)
		{
			name = n;
		}
		void set_id(int i)
		{
			id = i;
		}
		int ret_id()
		{
			return id;
		}
		string ret_name()
		{
			return name;
		}
		void add_department(int i,string n)
		{
			id = i;
			name = n;
		}
		void edit_name(string n)
		{
			char c;
			cout<<"\n\t\t\t\tRecord of id : "<<id;
			cout<<"\n\t\t\t\tName : "<<name;
			cout<<"\n\t\t\t\tAre You Sure To Rename (Y/N) :";
			cin>>c;
			if(c == 'Y' || c == 'y')
				name = n;
		}
		void display() 
		{
			cout<<"\n\t\t\t"<<id<<"\t"<<name;
		}
		void operator = (Department temp)
		{
			id = temp.id;
			name = temp.name;
		}
		
};
