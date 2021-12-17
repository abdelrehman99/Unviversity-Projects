// a program to reserve a flight using class and object
#include<iostream> // library for c++
#include <string.h> // library for strings
using namespace std; // to use cin and cout
class flight // initialize a class called flight
{
private :
    // In here we define the member data of the class
    string name; // define a variable called name of type string to store the flight name
    int number;  // define a variable called number of type int to store the flight number
    float price; // define a variable called price of type float to store the flight price
    string date; // define a variable called date of type string to store the flight date
    string cla;// define a variable called cla of type string to store the flight class
    int order=0;
public :
    // In here we define the member functions of the class
    // define a member function called setflight that takes 5 arguments and does return anything (void)
    void setflight(string n,int num,float p, string d,string c)
    {
        // here we initailize our member data with the values of the function arguments
        name=n;
        number=num;
        price=p;
        date=d;
        cla=c;
    }
    void reflight(int order) // define a member function called show flight that does not return anything (void) and takes no arguments
    {
    // displays the information of the flight
    if(order>0) // we increment the order variable if the flight is booked
        {
            cout<<"Name of country : "<<name<<endl<<
                "number of plane : "<<number<<endl<<
                "Price of ticket : $"<<price<<endl<<
                "Date of depature : "<<date<<endl<<
                "Class of ticket : "<<cla<<endl;
        } else // when the order is not incremented it means that the client didnt book any flights
        {
            cout<<"No flight booked"<<endl;
        }
    }
    void showflight()
    {
        cout<<"Name of country : "<<name<<endl<<
            "number of plane : "<<number<<endl<<
            "Price of ticket : $"<<price<<endl<<
            "Date of depature : "<<date<<endl<<
            "Class of ticket : "<<cla<<endl;
    }
    int condition(string x) // define a function called condition that returns int and takes 1 argument
    {
        // it returns the result of function compare which is a function that compapers 2 strings and returns 0 if they are same
        return (name.compare(x)); // when a function is called the result of the return will be replaced with the function place
    }
    int cl(string g) // define a function called cl that returns int and takes 1 argument
    {
        return (cla.compare(g)); // when a function is called the result of the return will be replaced with the function place
    }
};
class client // define a class of name client
{
private :
    string name;
    string email;
    int age;
    string passid;
    int number=0,book,order=0;
public :
    void getinfio()
    {
        cout<<"Fill the following form : "<<endl<<"Name : ";cin>>name;
        cout<<"Email : ";cin>>email;
        cout<<"Age : ";cin>>age;
        cout<<"Passport Id : ";cin>>passid;
    }
    void ticket()
    {
        cout<<"How many ticekcts you want ?";
        cin>>number;
    }
    void showinfo()
    {
        cout<<"Name : "<<name<<endl;
        cout<<"Email : "<<email<<endl;
        cout<<"Age : "<<age<<endl;
        cout<<"Passport Id : "<<passid<<endl;
        cout<<"Number of tickets : "<<number<<endl;
    }
    void getbook(int h)
    {
        book=h;
        order++;
    }
    int showbook()
    {
        return book;
    }
    int showorder()
    {
        return order;
    }
};
int main()
{
    int u,p;
    cout<<"Enter the number of clients : ";
    cin>>u;
    client x[u];
    flight f[6];
    string c;
    int n,m;
    string t,b;
    f[0].setflight("Uae",867,1230,"1/12/2020","First");
    f[1].setflight("Usa",975,1700,"6/8/2020","Economy");
    f[2].setflight("Qatar",498,988,"8/7/2020","Economy");
    f[3].setflight("Qatar",768,1200,"25/7/2020","First");
    f[4].setflight("Uae",889,900,"5/12/2020","Economy");
    f[5].setflight("Usa",267,2500,"19/8/2020","First");
    for(int i = 0 ; i < u ; i++)
    {
        x[i].getinfio();
        do
        {
            cout<<" The flights available are to Usa,Uae, and Qatar (start with a capital letter), where do you want to travel ? \n";
            cin>>c;
            cout<<" Do you want an Economy or First ticket (start with a capital letter) ? \n";
            cin>>t;
            n=0;
            for(int j = 0 ; j < 6 ; j++)
            {
                if(f[j].condition(c)==0 && (f[j].cl(t)==0))
                {
                    f[j].showflight();
                    m=j;
                    break;
                }
                else
                {
                    n++;
                }
            }
            if(n%6==0 && n!=0)
            {
                cout<<"Sorry these flights are not available at the moment.\n";
            }
        }while(n%6==0 && n!=0);
        cout<<"This is the available flight if you want to book it enter yes otherwise enter no ? \n";
        cin>>b;
        if(b=="Yes"||b=="yes")
        {
            x[i].ticket();
            cout<<"We have sent you an email with the bill, and thank you for trusting our airlines \n";
            x[i].getbook(m);
        }else
        {
            cout<<"Sorry this is the only available flight for your demand"<<endl;
        }
        if(i<u-1)
        {
            cout<<"Moving to the next customer \n";
        }
    }
    cout<<"The system records : "<<endl;
    for(int i = 0 ; i < u ; i ++)
    {
        x[i].showinfo();
        f[(x[i].showbook())].reflight(x[i].showorder());
    }
}
