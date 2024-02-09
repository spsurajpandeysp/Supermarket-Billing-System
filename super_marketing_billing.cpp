#include<iostream>
#include<fstream>
#include<iomanip>

using namespace std;

class BillingSystem
{
	private:
		int productCode;
		float productPrice;
		float discount;
		string productName;
	public:
		void buyer();
		void menu();
		void administrator();
		void add();
		void edit();
		void remov();
		void list();
		void receipt();
};

void BillingSystem :: menu()
{
	m:
	int choice;
	string email;
	string password;
	cout<<"       CANTEEN MANAGEMENT SYSTEM    "<<endl;
	cout<<endl;
	cout<<"____________________________________"<<endl;
	cout<<"|          MAIN MENU               |"<<endl;
	cout<<"|__________________________________|"<<endl;
	cout<<"|      1-> [Administrator]         |"<<endl;
	cout<<"|      2-> [Customer]              |"<<endl;
	cout<<"|      3-> [Exit]                  |"<<endl;
	cout<<"|      Enter key:                  |";
	cin>>choice;
	switch(choice)
	{
		case 1:
			{
				cout<<"________________________"<<endl;
				cout<<"|      LOGIN PAGE      |"<<endl;
				cout<<"|______________________|"<<endl;
				cout<<"|      Enter Email     |"<<endl;
				cin>>email;
				cout<<"|     Enter  Password  |"<<endl;
				cin>>password;
				if(email=="suraj" && password=="suraj")
				{
					administrator(); 
				}	
				else
				{
					cout<<"Invalid email or password:"<<endl;
				}
				break;
			}
		case 2:
			{
				buyer();
				break;
			}
		case 3:
			{
				exit(0);
			}
		default:
			{
				cout<<"Please select from the given options!"<<endl;
				break;
			}
			
	}
	goto m;	
}
void BillingSystem::administrator()
{
	m:
	int choice;
	cout<<"_______________________________"<<endl;
	cout<<"|         ADMINISTRATOR       |"<<endl;
	cout<<"|_____________________________|"<<endl;
	cout<<"|     1-> Add the product     |"<<endl;
	cout<<"|     2-> Modify the product  |"<<endl;
	cout<<"|     3-> Delete the product  |"<<endl;
	cout<<"|     4-> Back to main menu   |"<<endl;
	cout<<"|     Enter your choice:      |"<<endl;
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			add();
			break;	
		case 2:
			edit();
			break;
		case 3:
			remov();
			break;
		case 4:
			menu();
			break;
		default:
			cout<<"Invalid choice"<<endl;		
	}
	goto m;
}
void BillingSystem::buyer()
{
	m:
	int choice;
	cout<<"___________________________"<<endl;
	cout<<"|        BUYER            |"<<endl;
	cout<<"|_________________________|"<<endl;
	cout<<"|     1->   Buy Product   |"<<endl;
	cout<<"|     2->   Go back       |"<<endl;
	cout<<"|     Enter your choice:  |"<<endl;
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			receipt();
			break;
		case 2:
			menu();
			break;
		default:
			cout<<"Invalid choice:";		
	}
	goto m;
}
void BillingSystem::add()
{
	m:
	fstream data;
	int c;
	int token=0;
	float p;
	float d;
	string n;
	cout<<"______________________________________"<<endl;
	cout<<"|   	     ADD NEW PRODUCT            |"<<endl;
	cout<<"|____________________________________|"<<endl;
	cout<<"| Enter product code of the product: |"<<endl;
	cin>>productCode;
	cout<<"|  Enter name of the product:        |"<<endl;
	cin>>productName;
	cout<<"| Enter Price of the product:        |"<<endl;
	cin>>productPrice;
	cout<<"| Enter Discount on product:         |"<<endl;
	cin>>discount;
	
	data.open("database.txt",ios::in);
	
	if(!data)
	{
		data.open("database.txt",ios::app|ios::out);
		data<<" "<<productCode<<" "<<productName<<" "<<productPrice<<" "<<discount<<endl;
		data.close();
	}
	else
	{
		data>>c>>n>>p>>d;
		while(!data.eof())
		{
			if(c==productCode)
			{
				token++;
			}
			data>>c>>n>>p>>d;
		}
		data.close();
		if(token==1)
		{
			goto m;
		}
		else
		{
			data.open("database.txt",ios::app|ios::out);
			data<<" "<<productCode<<" "<<productName<<" "<<productPrice<<" "<<discount<<endl;
			data.close();
		}
	}
	cout<<"Record inserted "<<endl;	  
}
void BillingSystem:: edit()
{
	fstream data,data1;
	int pkey;
	int token=0;
	int c;
	float p;
	float d;
	string n;
	cout<<"_______________________________________"<<endl;
	cout<<"|           MODIFY THE RECORD         |"<<endl;
	cout<<"|_____________________________________|"<<endl;
	cout<<"|             Product code            |"<<endl;
	cin>>pkey;
	data.open("database.txt",ios::in);
	if(!data)
	{
		cout<<"file doesn't exist!"<<endl;
	}
	else
	{
		data1.open("database1.txt",ios::app|ios::out);
		
		data>>productCode>>productName>>productPrice>>discount;
		while(!data.eof())
		{
			if(pkey==productCode)
			{
				cout<<"Enter product new code:"<<endl;
				cin>>c;
				cout<<"Name of product:"<<endl;
				cin>>n;
				cout<<"Price:"<<endl;
				cin>>p;
				cout<<"Discount"<<endl;
				cin>>d;
				data1<<" "<<c<<" "<<n<<" "<<p<<"  "<<d<<endl;
				cout<<" Record Edited:"<<endl;
				token++;
			}
			else
			{
				data1<<" "<<productCode<<" "<<productName<<" "<<productPrice<<" "<<discount<<endl;
			}
			data>>productCode>>productName>>productPrice>>discount;
			
		}
		data.close();
		data1.close();
		remove("database.txt");
		rename("database1.txt","database.txt");
		if(token==0)
		{
			cout<<"Record not found sorry:"<<endl;
		}
	}
}
void BillingSystem::remov()
{
	fstream data,data1;
	int pkey;
	int token=0;
	cout<<"________________________________"<<endl;
	cout<<"|       DELETE PRODUCT         |"<<endl;
	cout<<"|______________________________|"<<endl;
	cout<<"|      Enter Product code:     |"<<endl;
	cin>>pkey;
	data.open("database.txt",ios::in);
	if(!data)
	{
		cout<<"File doesnt exist"<<endl;
	}
	else
	{
		data1.open("database1.txt",ios::app|ios::out);
		data>>productCode>>productName>>productPrice>>discount;
		while(!data.eof())
		{
			if(productCode==pkey)
			{
				cout<<"Product deleted successfully:"<<endl;
				token++;
			}
			else
			{
				data1<<" "<<productCode<<" "<<productName<<" "<<productPrice<<" "<<discount<<endl;
			}
			data>>productCode>>productName>>productPrice>>discount;
		}
		data.close();
		data1.close();
		remove("database.txt");
		rename("database1.txt","database.txt");
		
		if(token==0)
		{
			cout<<"Record not found:"<<endl;
		}
	}
}
void BillingSystem::list()
{
	fstream data;
	data.open("database.txt",ios::in);
	cout<<endl<<endl;
	cout<<"__________________________________________________"<<endl;
	cout<<"|                LIST OF PRODUCT                 |"<<endl;
	cout<<"|________________________________________________|"<<endl;
	cout<<"|ProductNo   |    Name    |   Price  | Discount  |"<<endl;
	cout<<"|____________|____________|__________|___________|"<<endl;
	
	data>>productCode>>productName>>productPrice>>discount;
	while(!data.eof())
	{
		cout<<" "<<setw(14)<<left<<productCode<<setw(13)<<left<<productName<<setw(11)<<left<<productPrice<<setw(12)<<left<<discount<<endl;
		data>>productCode>>productName>>productPrice>>discount;
	}
	data.close();
}
void BillingSystem:: receipt()
{
	fstream data;
	int  arrc[100];
	int arrq[100];
	int c=0;
	float amount=0;
	float dis=0;
	float total=0;
	char choice;
	data.open("database.txt",ios::in);
	if(!data)
	{
		cout<<"Empty database"<<endl;
	}
	else
	{
		data.close();
		
		list();
		cout<<"_______________________________________"<<endl;
		cout<<"|       PLEASE PLACE THE ORDER        |"<<endl;
		cout<<"|_____________________________________|"<<endl;
	}
	do
	{
		m:
		int token=0;
		cout<<"Enter product code:"<<endl;
		cin>>arrc[c];
		data.open("database.txt",ios::in);
		data>>productCode>>productName>>productPrice>>discount;
		while(!data.eof())
		{
			if(productCode==arrc[c])
			{
				token++;
			}
			data>>productCode>>productName>>productPrice>>discount;
		}
		data.close();
		if(token==0)
		{
			cout<<"This product is not present please try different product:"<<endl;
			goto m;
		}
		cout<<"Enter the product quantity:"<<endl;
		cin>>arrq[c];
		for(int i=0;i<c;i++)
		{
			if(arrc[c]==arrc[i])
			{
				cout<<"Duplicate product code please try again:"<<endl;
				goto m;
			}
		}
		c++;
		cout<<"Do you want to buy another product? if yes then press y else n:"<<endl;
		cin>>choice;
	}while(choice=='y');
	cout<<"_________________________________________________________________________________"<<endl;
	cout<<"|                                 RECEIPT                                       |"<<endl;
	cout<<"|_______________________________________________________________________________|"<<endl;
	cout<<"| PORODUCT NO | PRODUCT NAME  | QUANTITY | PRICE | AMOUNT |AMOUNT WITH DISCOUNT |"<<endl;
	cout<<"|_____________|_______________|__________|_______|________|_____________________|"<<endl;
	for(int i=0;i<c;i++)
	{
		data.open("database.txt",ios::in);
		data>>productCode>>productName>>productPrice>>discount;
		while(!data.eof())
		{
			if(productCode==arrc[i])
			{
				amount=productPrice*arrq[i];
				dis=amount-(amount*discount/100);
				total=total+dis;
				cout<<" "<<setw(14)<<left<<productCode<<setw(16)<<left<<productName<<setw(11)<<left<<arrq[i]<<setw(8)<<left<<productPrice<<setw(9)<<left<<amount<<setw(20)<<left<<dis<<endl;
			}
			data>>productCode>>productName>>productPrice>>discount;
		}
		data.close();
	}
	cout<<endl<<endl;
	cout<<"Total Amount:"<<total<<endl;
}
int main()
{
	BillingSystem obj1;
	obj1.menu();
	return 0;
}