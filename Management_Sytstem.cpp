#include<iostream>
using namespace std;
class employee
{
	private:
	string name;
	float rate;
	int day;
	float taxes=0.13;
	float health=0.12;
	int overtime;
	int bonus=0;
	public:
	void getemployee ()
	{
		string x;
		cout<<"Enter employees name:";
		cin>>name;
		cout<<"Enter employee rate per day : ";
		cin>>rate;
		cout<<"Enter number of days worked : ";
		cin>>day;
		cout<<"Type yes if the employee worked overtime, else type no : ";
		cin>>x;
		if(x=="yes")
		{
			cout<<"Type the number of days the employee worked : ";
			cin>>overtime;
		}
		else
		{
			overtime=0;
		}
		if(day+overtime>=5)
		{
			cout<<"You have worked more than 5 days and here is a small bonus $20 and for every 5 days you get a 20$ bonus\n";
			bonus=20*((day+overtime)/5);
		}
	}
    void showemployee()
	{
		cout << "name : " << name<<endl;
		cout << "rate : " << rate<<endl;
		cout << "days : " << day+overtime<<endl;
		cout << "bonus : "<< bonus<<endl;
	}
	float salary()
	{
		return (rate*(day+overtime)-((taxes+health)*(rate*(day+overtime)))+bonus);
	}
	int getbonus()
	{
		return bonus;
	}
	int getday()
	{
		return day+overtime;
	}
};
int main()
{
	int n,y=0;
	cout<<"Enter number of employees : ";
	cin>>n;
	employee x[n];
	for ( int i = 0; i < n ; i++)
	{
		x[i].getemployee();
	}
	for (int i = 0; i < n-1 ; i++ )
	{
		if(x[y].salary()<x[i+1].salary())
		{
			y=i+1;
		}
	}
	cout<<"The employee with the highest salary is : \n";
	x[y].showemployee();
	y=0;
	for (int i = 0; i < n-1 ; i++ )
	{
		if(x[y].getbonus()<x[i+1].getbonus())
		{
			y=i+1;
		}
	}
	cout<<"The employee with the highest bonus is : \n";
	x[y].showemployee();
	y=0;
	for (int i = 0; i < n-1 ; i++ )
	{
		if(x[y].getday()<x[i+1].getday())
		{
			y=i+1;
		}
	}
	cout<<"The employee with the most days worked is : \n";
	x[y].showemployee();
}
