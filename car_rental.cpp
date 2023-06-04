#include<iostream>
#include<istream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
using namespace std;
void login();
void registr();
void forgot();
void adminlogin();
void add_car();
void del_car();
void details();
void admin();
void user_login();
void cars();
void book_car();
class cardetails
{       

        char company[10];
        char model[10];
        char car_code[5];
        char no_seats[5];
        char rent[6];
        

        public:
                friend void add_car();
                friend void del_car();  
                friend void cars();
                friend void book_car();

                


};

int main()
{
        int choice;
        cout<<"                                                                         Welcome to Car Rental System                               \n\n";
        cout<<"                 ************************************************************       MENU        ***************************************************\n\n";
        cout<<"1.ADMIN LOGIN"<<endl;
        cout<<"2.USER LOGIN"<<endl;
        cout<<"3.USER REGISTER"<<endl;
        cout<<"4.FORGOT PASSWORD (or) USERNAME"<<endl;
        cout<<"5.Exit"<<endl;
        cout<<"\nEnter your choice :";
        cin>>choice;
        cout<<endl;
        switch(choice)
        {       
                case 1:
                        
                        adminlogin();
                        
                        break;
                case 2:
                        login();
                        break;
                case 3:
                        registr();
                        break;
                case 4:
                        forgot();
                        break;
                case 5:
                        system("cls");
                        cout<<"\n\n\n\n\t\t\t\t**************************************  Thank you for visiting  *************************************** \n\n";
                        break;
                default:
                        system("cls");
                        cout<<"You've made a mistake , give it a try again\n"<<endl; 
                        main();
        }
        
}
void adminlogin()
{
        int count;
        string user,pass,u,p;
        system("cls");
        cout<<"\t\t\t\t\tADMIN LOGIN\n"<<endl;
        cout<<"\t\t\t\t\tPlease enter the following details\n"<<endl;
        cout<<"\t\t\t\t\tUSERNAME :";
        cin>>user;
        cout<<"\t\t\t\t\tPASSWORD :";
        cin>>pass;
        
        if(user=="admin" && pass=="pass")
        {
              
                system("cls");
                admin();
                
        }
        else
        {
                cout<<"\nLOGIN ERROR\nPlease check your username and password\n";
                main();
        }
}

void login()
{
        int count;
        string user,pass,u,p;
        system("cls");
        cout<<"\t\t\t\t\tUSER LOGIN\n"<<endl;
        cout<<"\t\t\t\t\tPlease enter the following details\n"<<endl;
        cout<<"\t\t\t\t\tUSERNAME :";
        cin>>user;
        cout<<"\t\t\t\t\tPASSWORD :";
        cin>>pass;

        
        ifstream input("database.txt");
        while(input>>u>>p)
        {
                if(u==user && p==pass)
        
                {
                        count=1;
                        ;
                }
        }
        input.close();
        if(count==1)
        {
                // cout<<"\nHello "<<user<<"\nLOGIN SUCCESSFULL\nWelcome to car rental system\n";
                // cin.get();
                system("cls");
                user_login();
        }
        else
        {
                cout<<"\nLOGIN ERROR\nPlease check your username and password\n";
                main();
        }
}

void registr()
{
        
        string reguser,regpass,ru,rp;
        system("cls");
        cout<<"Enter the username :";
        cin>>reguser;
        cout<<"\nEnter the password :";
        cin>>regpass;
        
        ofstream reg("database.txt",ios::app);
        reg<<reguser<<' '<<regpass<<endl;
        cout<<"\nRegistration Sucessful\n";
        main();
        
        
}

void forgot()
{
        int ch;
        cout<<"Forgotten ? We're here for help\n";
        cout<<"1.Search your id by username"<<endl;
        cout<<"2.Search your id by password"<<endl;
        cout<<"3.Main menu"<<endl;
        cout<<"Enter your choice :";
        cin>>ch;
        switch(ch)
        {
                case 1:
                {
                        int count=0;
                        string searchuser,su,sp;
                        cout<<"\nEnter your remembered username :";
                        cin>>searchuser;
                        
                        ifstream searchu("database.txt");
                        while(searchu>>su>>sp)
                        {
                                if(su==searchuser)
                                {
                                        count=1;
                                }
                        }
                        searchu.close();
                        if(count==1)
                        {
                                cout<<"\n\nAccount found\n";
                                cout<<"\nYour password is "<<sp;
                                cin.get();
                                cin.get();
                                system("cls");
                                main();
                        }
                        else
                        {
                                cout<<"\nSorry, Your userID is not found in our database\n";
                                cout<<"\nPlease kindly contact your system administrator for more details \n";
                                cin.get();
                                cin.get();
                                main();
                        }
                        break;
                }
                case 2:
                {
                        int count=0;
                        string searchpass,su2,sp2;
                        cout<<"\nEnter the remembered password :";
                        cin>>searchpass;
                        
                        ifstream searchp("database.txt");
                        while(searchp>>su2>>sp2)
                        {
                                if(sp2==searchpass)
                                {
                                        count=1;
                                }       
                        }
                        searchp.close();
                        if(count==1)
                        {
                                cout<<"\nYour password is found in the database \n";
                                cout<<"\nYour Id is : "<<su2;
                                cin.get();
                                cin.get();
                                system("cls");
                                main();
                        }
                        else
                        {
                                cout<<"Sorry, We cannot found your password in our database \n";
                                cout<<"\nkindly contact your administrator for more information\n";
                                cin.get();
                                cin.get();
                                main();
                        }
                
                        break;
                }
                
                case 3:
                {
                        cin.get();
                        main();
                }
                default:
                        cout<<"Sorry, You entered wrong choice. Kindly try again"<<endl;
                        forgot();
        }
}
void add_car()
{       cardetails det;
        cout<<"Enter car code:";
        cin>>det.car_code;
        cout<<endl;
        cout<<"Enter car company name:";
        cin>>det.company;
        cout<<endl;
        cout<<"Enter car model:";
        cin>>det.model;
        cout<<endl;
        cout<<"Enter no of seats:";
        cin>>det.no_seats;
        cout<<endl;
        cout<<"Enter the rent of car:";
        cin>>det.rent;


        ofstream reg("car_details.txt",ios::app);
        reg<<det.car_code<<" "<<det.company<<" "<<det.model<<" "<<det.no_seats<<" "<<det.rent<<endl;
}

void del_car()
{       
	int way;
        int flag;
	
	char name[20];
        char id[5];
        
	cout<<"1.To delete by car code"<<endl;
	cout<<"2.To delete by car model name"<<endl;
	
        cout<<"Enter your choice : ";
	cin>>way;	 
	 	if(way==1){
        cout<<"Enter car code to delete : ";
	 	cin>>id;
		 }
	 	else 
		 	if(way==2){
	 		cout<<"Enter car model name to delete : ";
	 	cin>>name;}
	 	cardetails s;
                fstream myfile;
	 	fstream mymyfile;
	 	myfile.open("car_details.txt",ios::in);//read
	 	mymyfile.open("Temp.txt",ios::out);//write

        while(!myfile.eof()){
		        myfile.getline(s.car_code,4,' ');	
			myfile.getline(s.company,15,' ');
	 		myfile.getline(s.model,9,' ');
	 		myfile.getline(s.no_seats,5,' ');
	 		myfile.getline(s.rent,6,'\n');
         	
		 	if(way==1&&strcmp(id,s.car_code	)!=0)
                        {
                                {
                                mymyfile<<s.car_code<<" "<<s.company<<" "<<s.model<<" "<<s.no_seats<<" "<<s.rent<<"\n";
                                } 
                         if(strcmp(id,s.car_code)==0)
                        {
			flag=1;
                         }
                        }else
 		
		 	if(way==2&&strcmp(name,s.model)!=0){{
         
		 	mymyfile<<s.car_code<<" "<<s.company<<" "<<s.model<<" "<<s.no_seats<<" "<<s.rent<<"\n";

		        } if(strcmp(name,s.model)==0){
			flag=1;
 		        }}

        }
        myfile.close();
	mymyfile.close();
        remove("car_details.txt");
        rename("Temp.txt","car_details.txt");
	if(flag==0)
	{
        cout<<"Not found"<<endl;
        }

  		
          
}
void details()
{
        cout<<"details"<<endl;
}
void admin()
{
        int cha;
        cout<<"1.Add car"<<endl;
        cout<<"2.Delete car"<<endl;
        cout<<"3.Rented car details"<<endl;
        cout<<"4.Main Menu"<<endl;
        cout<<"5.Exit"<<endl;
        cout<<"\nEnter your choice :";
        cin>>cha;
        cout<<endl;
        switch(cha)
        {
        case 1: 
                system("cls");
                add_car();
                system("cls");
                admin();
                break;
        case 2:
                system("cls");
                del_car();
                system("cls");
                admin();
                break ;
        case 3:
                system("cls");
                details();
                admin();
                break;
        case 4:
                system("cls");
                main();
        case 5:
                system("cls");
                exit(0);
        
        default:
                break;
        }
}

void user_login()
{
        int cha;
        cout<<"1.Car Details"<<endl;
        cout<<"2.Book Car"<<endl;
        cout<<"3.History"<<endl;
        cout<<"4.Main menu"<<endl;
        cout<<"5.Exit"<<endl;
        cout<<"\nEnter your choice :";
        cin>>cha;
        cout<<endl;
        switch(cha)
        {
        case 1: 
                system("cls");
                cars(); 
                user_login();
                break;
        case 2:
                system("cls");
                cout<<"Book Car\n"<<endl;
                book_car();
                // user_login();
                break ;
        case 3:
                system("cls");
                cout<<"History\n"<<endl;
                user_login();
                break;
        case 4:
                system("cls");
                main();
                break;
                
        case 5:
                exit(0);
        
        default:
                break;
        }
}

void cars()
{
        cardetails s;
        fstream file1;
        file1.open("car_details.txt",ios::in);
        cout<<"CAR CODE"<<"\t"<<"CAR COMPANY"<<"\t"<<"CAR MODEL"<<"\t"<<"No. OF SEATS"<<"\t"<<"RENT(per day)"<<endl;
        while(!file1.eof())
        {
        file1.getline(s.car_code,4,' ');	
        file1.getline(s.company,15,' ');
        file1.getline(s.model,10,' ');
        file1.getline(s.no_seats,5,' ');
        file1.getline(s.rent,6,'\n');


        cout<<s.car_code<<"\t\t"<<s.company<<"\t\t"<<s.model<<"\t\t"<<s.no_seats<<"\t\t"<<s.rent<<endl;
        }
        file1.close();

}

void book(int in,string name,string cc,string com,string cm,int nd)
{
        ofstream reg("book_details.txt",ios::app);
        reg<<in<<"\t"<<name<<"\t"<<cc<<"\t"<<com<<"\t"<<cm<<"\t"<<nd<<endl;
}

void invoice(string cc,string com,string cm,string ns,string ren)
{
        string Name,mb,address,ch;
        int nd,rent,in;
        cout<<"Enter number of days :"<<endl;
        cin>>nd;
        cout<<"Enter your name :"<<endl;
        cin>>Name;
        cout<<"Enter your mobile number :"<<endl;
        cin>>mb;
        cout<<"Enter your address"<<endl;
        cin>>address;

        rent=stoi(ren);
        int count=0;
        string line;
        ifstream file("book_details.txt");
        while(getline(file,line))
                count++;
        in=count+1;
        

        system("cls");

        cout<<"\t\t\t\t\t============= CAR RENTAL SYSTEM CUSTOMER INVOICE ===============\n\n\n"<<endl;
        cout<<"\t\t\t\t\t\t\tInvoice Number :               "<<in<<endl;
        cout<<"\t\t\t\t\t\t\tCustomer Name  :               "<<Name<<endl;
        cout<<"\t\t\t\t\t\t\tMobile Number  :               "<<mb<<endl;
        cout<<"\t\t\t\t\t\t\tAddress        :               "<<address<<endl;
        cout<<"\t\t\t\t\t\t\tCar Code       :               "<<cc<<endl;
        cout<<"\t\t\t\t\t\t\tCar Company    :               "<<com<<endl;
        cout<<"\t\t\t\t\t\t\tCar Model      :               "<<cm<<endl;
        cout<<"\t\t\t\t\t\t\tNo. of seats   :               "<<ns<<endl;
        cout<<"\t\t\t\t\t\t\tRent per day   :               "<<ren<<endl;

        cout<<"\n\n"<<endl;
        cout<<"               \t\t\t\t\tTotal Rental Amount :          "<<rent*nd<<endl;


        book(in,Name,cc,com,cm,nd);


        cout<<"Do you want to continue(y/n)"<<endl;
        cin>>ch;

        if(ch=="y")
        {
                user_login();
        }
        else{
                exit(0);
        }


} 


void book_car()
{
        int nd,cc;
        string c,Name,address,mb,carcode;
        cardetails s;
        fstream file1;
        file1.open("car_details.txt",ios::in);
        cout<<"CAR CODE"<<"\t"<<"CAR COMPANY"<<"\t"<<"CAR MODEL"<<"\t"<<"No. OF SEATS"<<"\t"<<"RENT(per day)"<<endl;
        while(!file1.eof())
        {
        file1.getline(s.car_code,4,' ');	
        file1.getline(s.company,15,' ');
        file1.getline(s.model,10,' ');
        file1.getline(s.no_seats,5,' ');
        file1.getline(s.rent,6,'\n');


        cout<<s.car_code<<"\t\t"<<s.company<<"\t\t"<<s.model<<"\t\t"<<s.no_seats<<"\t\t"<<s.rent<<endl;
        }
        file1.close();

        cout<<"\nEnter Car Code :"<<endl;
        cin>>carcode;




        cout<<"Confirm"<<endl;
        cin>>c;

        if(c=="y")
        {       
                file1.open("car_details.txt",ios::in);
                while(!file1.eof())
                {
                        file1.getline(s.car_code,4,' ');
                        file1.getline(s.company,15,' ');
                        file1.getline(s.model,10,' ');
                        file1.getline(s.no_seats,5,' ');
                        file1.getline(s.rent,6,'\n');

                
                        if(s.car_code==carcode)
                        {
                        
                                invoice(s.car_code,s.company,s.model,s.no_seats,s.rent);
                                break;
                        }
                
                }

                system("cls");
                cout<<"Enter correct car code\n\n"<<endl;
                book_car();	
        }

        else
        {
                book_car();
        }




}


