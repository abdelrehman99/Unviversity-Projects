#include<iostream>
using namespace std;

class phone
{
	private:
		string name ;
		float price ;
		string status;
		
		public :
			void setphone(string n,float p, string s)
			{
				name = n;
				price =p;
				status=s;
				
			}
			void showphone()
			{
				cout<<"name of phone : "<<name<<endl ;
				cout<<"price of phone : "<<price<<endl ;
				cout<<"status of phone : "<<status<<endl ;
			}
			float prices()
			{
				return price;
			}
			
};
class customer 
{
	private :
		string name;
		string phone;
	public :
	void getcustomer()
	{
		cout<<"Enter customer name : ";cin>>name;
		cout<<"Enter the type of phone the customer deisre (iphone, samsung, oppo, nokia): ";
		cin>>phone;
	}
	string type()
	{
		return phone;	
	}	
};
		int main ()
		{
			int n;
			customer y[4];
			phone iphone[2],samsung[2],oppo[2],nokia[2];
			iphone[0].setphone("iphone 8",10000,"used");
			iphone[1].setphone("iphone x",20000,"new");
			oppo[0].setphone("oppo f9",10000,"used");
			oppo[1].setphone("oppo f8",11000,"new");
			samsung[0].setphone("samsung a70",9500,"new");
			samsung[1].setphone("samsung a50",7500,"new");
			nokia[0].setphone("nokia s1",700,"used");
			nokia[1].setphone("nokia s2",900,"used");
			for(int i = 0 ; i < 4 ; i++)
			{
				y[i].getcustomer();
				for(int j = 0 ; j < 2 ; j++)
				{
						if(y[i].type()=="iphone")
						{
							cout<<j+1<<".";
							iphone[j].showphone();
							if(j==1)
							{
								do
								{
									cout<<"Enter the number of what phone you want ?";
									cin>>n;
									if(n==1)
									{
										cout<<"This will cost you "<<iphone[0].prices()<<" \n";
									}
									else if(n==2)
									{
										cout<<"This will cost you "<<iphone[1].prices()<<" \n";
									}else
									{
										cout<<"Invalid response "<<endl;
									}		
								}while(n!=1 || n!=2);
							}
						}
						else if(y[i].type()=="samsung")
						{
							cout<<j+1<<".";
							samsung[j].showphone();
							if(j==1)
							{
								do
								{
									cout<<"Enter the number of what phone you want ?";
									cin>>n;
									if(n==1)
									{
										cout<<"This will cost you "<<samsung[0].prices()<<" \n";
									}
									else if(n==2)
									{
										cout<<"This will cost you "<<samsung[1].prices()<<" \n";
									}
									else
									{
										cout<<"Invalid response"<<endl;	
									}	
								}while(n!=1 || n!=2);
							}	
						}
						else if(y[i].type()=="oppo")
						{
							cout<<j+1<<".";
							oppo[j].showphone();
							if(j==1)
							{
								do
								{
									cout<<"Enter the number of what phone you want ?";
									cin>>n;
									if(n==1)
									{
										cout<<"This will cost you "<<oppo[0].prices()<<" \n";
									}
									else if(n==2)
									{
										cout<<"This will cost you "<<oppo[1].prices()<<" \n";
									}
									else
									{
										cout<<"Invalid response"<<endl;	
									}	
								}while(n!=1 || n!=2);
							}		
						}
						else if(y[i].type()=="nokia")
						{
							cout<<j+1<<".";
							nokia[j].showphone();
								if(j==1)
								{
									do
									{
										cout<<"Enter the number of what phone you want ?";
										cin>>n;
										if(n==1)
										{
											cout<<"This will cost you "<<nokia[0].prices()<<" \n";
										}
										else if(n==2)
										{
											cout<<"This will cost you "<<nokia[1].prices()<<" \n";
										}
										else
										{
											cout<<"Invalid response"<<endl;											
										}											
									}while(n!=1 || n!=2);	
								}
						}
						else
						{
							cout<<"This phone is not available, enter the phone type again";
							i--;
							break;
						}
				}
			}
		}
