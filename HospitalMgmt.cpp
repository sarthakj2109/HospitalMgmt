/*
  Hospital Management System
	By - Sarthak Jain
	Roll No - 27
*/

#include<iostream.h>    //for input and output stream regulation
#include<process.h>     //for exit()
#include<string.h>      //for strlen() and strcmp()
#include<conio.h>       //for getch() and clrscr()

class all               //declaration for class "all"
{
private:
	struct address
	{
		int house;
		char city[30],dist[30],state[30],street[30],country[30];
	};
	struct age
	{
		int day,month,year;
	};
	struct patient_info
	{
		age A1;              //nested structure inplemented
		address AD1;         //nested structure implemented
		int sex,reg_no,bld_group,martial_status;
		char name[50];
	}PI[100];            //Structure variable declared to store info of 100 patients
	int task;
protected:             //declaration of functions
	void search_menu();
	void search_city();
	void exit_function();
	void search_show_info();
	void search_blood_group();
	void enter_patient_info();
	void show_patient_detail();
	void after_search_options();
public:
	void tasks();
	void software_detail();
	int s_group;
	int s_choice;
	char ch;
	char answer;
	char answer1;
	char s_city[30];
	char exit_answer;
	char after_search_answer;
};                      //end of class "all"

class date              //declaration for class "date"
{
private:
	int date,month,year;
public:
	void enter_date();
	void show_date();
};                      //end of class "date"

class dob               //declaration for class "dob"
{
private:
	struct dob1
	{
		int date,month, year,rem;
	}DOB11[100];
public:
	char birth_answer;
	void show_date();
	void enter_date();
	void search_show_date();
};                      //end of class "dob"

class temp              //declaration for class "temp"
{
public:
	int m,i,j,k,d,e,f,rem,temp,count,regis,index,entry,serial,attempt,current;
	int d_index,ssi_count,show_count,search_index,search_count,current_year;
	int search_number,entry_index[100];
	int after_search_choice;
	char enter_now;
	char duplicate_answer;
	char after_search_answer;
temp()                //constructor for temp invoked
{
	i=0,j=0,d=0,e=0,f=0,serial=0,current=0,d_index=0,ssi_count=0,show_count=0;
};                    //end of constructor for temp
};                      //end of class "temp"

all A1;                 //object for class "all" declared
date D1;                //object for class "date" declared
dob DOB1;               //object for class "dob" declared
temp T1;                //object for class "temp" declared

void main()             //main function
{
	T1.count=0;
	for(T1.m=1;T1.m<=100;T1.m++)    //default index value set to -1 for each entry
	{
		T1.entry_index[T1.m]=-1;
	}
	cout<<"Welcome to...\n";
	cout<<"\n\n\t\t\t***HOSPITAL MANAGEMENT SOFTWARE***\n";
	cout<<"\t\t\t       Developed By Sarthak Jain       \n";
	D1.enter_date();
	A1.tasks();
}                       //end of main function

void all::tasks()
{
	clrscr();
	T1.attempt=0;
	T1.d_index=0;
	D1.show_date();
	cout<<"\n\n\t\t\t***HOSPITAL MANAGEMENT SOFTWARE***"<<"\n";
	cout<<"\t\t\t       By Sarthak Jain       \n";
	cout<<"\n\t\t\t ***Hospital Management Tasks***\n";
	cout<<"\t\t\t *******************************\n";
	cout<<"\n\n\tPlease  select a task to do....\n";
	cout<<"\n\n\t1. Enter a new patient information \n";
	cout<<"\t2. View detail of existing patient \n";
	cout<<"\t3. Search by city or blood group\n";
	cout<<"\t4. About \n";
	cout<<"\t5. Exit \n\n\n";
	cout<<"Enter your task serial : ";
	cin>>task;
	switch(task)
	{
		case 1:
		A1.enter_patient_info();
		break;

		case 2:
		A1.show_patient_detail();
		break;

		case 3:
		A1.search_menu();
		break;


		case 4:
		A1.software_detail();
		break;

		case 5:
		A1.exit_function();
		break;

		default:
		cout<<"\n\tInvalid task serial !!!\n";
		cout<<"\tValid options are 1-5 !!!\n";
		cout<<"\tPress any key to return to the main task menu....\n";
		getch();
		clrscr();
		A1.tasks();

	}		     //end of switch for task
}                       //end of  function

void date::enter_date()
{
	cout<<"\n\nPlease enter the current date ...\n";
	cout<<"Year  : ";
	cin>>year;
	while(year<1000||year>10000)
	{
		cout<<"Invalid input for year !!!"<<"\n"<<"Please enter the year correctly : ";
		cin>>year;
	}
	T1.current_year=year;
	cout<<"Month : ";
	cin>>month;
	while(month<1||month>12)   //if month is greater then 12 or less then 1
	{
		cout<<"\nInvalid input for month !!!\n";
		cout<<"Please enter the month correctly : ";
		cin>>month;
	}
	cout<<"Date  : ";
	switch(month)
	{
		case 1:	case 3:	case 5:	case 7:  case 8:  case 10:  case 12:
		cin>>date;
		while(date<1||date>31)   //for months with 31 days
		{
			cout<<"Invalid date !!!\n";
			cout<<"Enter the date again : ";
			cin>>date;
		}
		break;

		case 2:			   //for february month
		cin>>date;
		if(year%4==0)
		{
			while(date<1||date>29)    //for leap year
			{
				cout<<"Invalid date !!!\n";
				cout<<"Again enter the date : ";
				cin>>date;
			}
		}
		else
		{
			while(date<1||date>28)    //for non-leap year
			{
				cout<<"Invalid date !!!\n";
				cout<<"Again enter the date : ";
				cin>>date;
			}
		}
		break;
		default:                           //for other months with 30 days
		cin>>date;
		while(date<1||date>30)
		{
			cout<<"\aInvalid date !!!"<<"\n";
			cout<<"Again enter the date : "<<"\n";
			cin>>date;
		}
	}	           	         //end of switch
}                       		//end of  function

void date::show_date()
{
	clrscr();
	cout<<"Hello....\n It's ";
	cout<<date;
	T1.rem=date%10;
	switch(date)
	{
	case 11:  case 12:  case 13:  case 14:  case 15:  case 16:  case 17:
	case 18:  case 19:  case 20:
		cout<<"th ";
		goto over;
	}
	switch(T1.rem)
	{
		case 1: cout<<"st "; break;
		case 2: cout<<"nd "; break;
		case 3: cout<<"rd "; break;
		default: cout<<"th ";
	}                      //end of switch
	over:                  //label for jump statement
	switch(month)
	{
		case 1: cout<<"January , "; break;
		case 2: cout<<"February , "; break;
		case 3: cout<<"March , "; break;
		case 4: cout<<"April , "; break;
		case 5: cout<<"May , "; break;
		case 6: cout<<"June , "; break;
		case 7: cout<<"July , "; break;
		case 8: cout<<"August , "; break;
		case 9: cout<<"September , "; break;
		case 10: cout<<"October , "; break;
		case 11: cout<<"November , "; break;
		case 12: cout<<"December , "; break;
	}                      //end of switch
	cout<<year<<"\n";

}                        //end of  function
void all::enter_patient_info()
{
	clrscr();
	int flag=1;
	if(T1.current==100)       //to avoid overflow of data in the database
	{
		cout<<"\n\n\n\t Database is full !!! ";
		cout<<"\n\t Sorry, you cannot enter any more information !!! ";
		cout<<"\n\t Information of maximum 100 patients can be entered !!!! ";
		cout<<"\n\t Press any key to return to the main menu.... ";
		getch();
		A1.tasks();
	}
	answer='y';
	if(T1.count==0)
	{
		T1.serial=1;
	}
	else
	{
		T1.i=T1.serial;
	}
	for(T1.i=T1.serial;answer=='y'||answer=='Y';T1.i++)
	{
		cout<<"";
		T1.current++;
		PI[T1.i].reg_no=T1.i;
		T1.temp=T1.serial;
		clrscr();
		T1.entry_index[T1.i]=1;
		cout<<"\n\n\t ***ENTERING INFORMATION FOR PATIENT SERIAL NUMBER "<<T1.i<<" ***\n";
		cin.get(ch);
		cout<<"\nRegistration Number : "<<PI[T1.i].reg_no<<"\n\n";
		cout<<"Enter the name of patient : ";
		cin.getline(PI[T1.i].name,50);
		while(strlen(PI[T1.i].name)==0)
		{
			cout<<"\nPlease enter a name : ";      //if enter is pressed before netering a name
			cin.getline(PI[T1.i].name,50);
			cout<<"\n";
		}
		for(T1.k=1;T1.k<T1.serial;T1.k++)         //loop to avoid duplicate entries
		{
			if(strcmp(PI[T1.i].name,PI[T1.k].name)==0)  //if match is found
			{
				if(T1.entry_index[T1.k]==0)             //if entry is already deleted
				{
					continue;
				}       //if entry still exists
				else
				{
					T1.current-=1;                          //current no. of entries remains same
					cout<<"\n\n\n\tThe patient is already admitted in the hospital !!!";
					cout<<"\n\tWant to view info of this registration number in detail (Y/N) : ";
					cin>>T1.duplicate_answer;
					while(T1.duplicate_answer!='Y'&&T1.duplicate_answer!='y'&&T1.duplicate_answer!='N'&&T1.duplicate_answer!='n')
					{
						cout<<"\n\t\aPlease re enter a correct option (Y/N) : ";
						cin>>T1.duplicate_answer;
					}
					if(T1.duplicate_answer=='y'||T1.duplicate_answer=='Y')
					{
						T1.entry_index[T1.i]=-1;
						T1.regis=T1.k;
						T1.d_index=1;
						A1.show_patient_detail();
					}
					else
						A1.tasks();

				}
			}
		}                     //end of "for loop" to prevent duplicate entries
		cout<<"\nSex ( 1-Male , 2-Female ) : ";
		cin>>PI[T1.i].sex;
		while(PI[T1.i].sex!=1&&PI[T1.i].sex!=2)
		{
			cout<<"\nInvalid input for sex of patient !!!";
			cout<<"\nSex : ";
			cin>>PI[T1.i].sex;
		}
		cout<<"\nMartial status( 1-Married , 2-Single ) : ";
		cin>>PI[T1.i].martial_status;
		while(PI[T1.i].martial_status<1||PI[T1.i].martial_status>2)
		{
			cout<<"\nInvalid input for martial status !!!"<<"\n";
			cout<<"Enter a valid martial status : "<<"\n";
			cin>>PI[T1.i].martial_status;
		}
		cin.get(ch);
		cout<<"\n *** Blood group ***\n";
		cout<<"1. A+ \n"<<"2. A- \n"<<"3. B+ \n"<<"4. B- \n"<<"5. AB+ \n"<<"6. AB- \n"<<"7. O+ \n"<<"8. O- \n";
		cout<<"\nEnter the patient's blood group : ";
		cin>>PI[T1.i].bld_group;
		cin.get();
		switch(PI[T1.i].bld_group)
  		{
   			case 1:   case 2:   case 3:   case 4:   case 5:   case 6:   case 7:   case 8:      break;
           		default:           
				while(PI[T1.i].bld_group!=1&&PI[T1.i].bld_group!=2&&PI[T1.i].bld_group!=3&&PI[T1.i].bld_group!=4&&
                 			PI[T1.i].bld_group!=5&&PI[T1.i].bld_group!=6&&PI[T1.i].bld_group!=7&&PI[T1.i].bld_group!=8)
           			{
            				cout<<"Invalid input !!!"<<"\n";
           				cout<<"Please enter a valid Blood Group : "<<"\n";
            				cin>>PI[T1.i].bld_group;
           			}            //end of while
           
  		}                     //end of switch
  		cin.get();
		cout<<"\n\n ***ENTERING ADDRESS**\n";
		cout<<"House number : ";
		cin>>PI[T1.i].AD1.house;
		while(PI[T1.i].AD1.house<=0)
		{
			cout<<"\nInvalid input for house number !!!";
			cout<<"\nAgain enter the house number : ";
			cin>>PI[T1.i].AD1.house;
		}
		cin.get(ch);
		cout<<"Street : ";
		cin.getline(PI[T1.i].AD1.street,30);
		while(strlen(PI[T1.i].AD1.street)==0) 		//if enter is pressed before input for street
		{
			cout<<"\nPlease enter a street : ";
			cin.getline(PI[T1.i].AD1.street,50);
			cout<<"\n";
		}
		cout<<"City : ";
		cin.getline(PI[T1.i].AD1.city,30);
		while(strlen(PI[T1.i].AD1.city)==0)
		{
			cout<<"\nPlease enter a city : ";      //if enter is pressed before input for city
			cin.getline(PI[T1.i].AD1.city,50);
			cout<<"\n";
		}
		cout<<"District : ";
		cin.getline(PI[T1.i].AD1.dist,30);
		while(strlen(PI[T1.i].AD1.dist)==0)
		{
			cout<<"\nPlease enter a district : ";  //if enter is pressed before input for district
			cin.getline(PI[T1.i].AD1.dist,30);
			cout<<"\n";
		}
		cout<<"State : ";
		cin.getline(PI[T1.i].AD1.state,30);
		while(strlen(PI[T1.i].AD1.state)==0)
		{
			cout<<"\nPlease enter a state : ";     //if enter is pressed before input for state
			cin.getline(PI[T1.i].AD1.state,50);
			cout<<"\n";
		}
		cout<<"Country : ";
		cin.getline(PI[T1.i].AD1.country,30);
		while(strlen(PI[T1.i].AD1.country)==0)
		{
			cout<<"\nPlease enter a country : ";   //if enter is pressd before input for country
			cin.getline(PI[T1.i].AD1.country,50);
			cout<<"\n";
		}
		DOB1.enter_date();
		cin.get(ch);
		cout<<"\n\nWant to enter information for another patient (Y/N) ? ";
		cin>>answer;
		while(answer!='Y'&&answer!='y'&&answer!='N'&&answer!='n')
		{
			cout<<"\a\nPease re-enter a correct option (Y/N) : ";
			cin>>answer;
		}
		cout<<"\n";
		T1.count++;
		T1.serial++;
	}                     //end of "for loop" for entering information

	clrscr();
	A1.tasks();
}                       //end of  function

void dob::enter_date()
{
	cout<<"\n\n *** Date of birth ***\n";
	cout<<"Year  : ";
	cin>>DOB11[T1.temp].year;
	while(DOB11[T1.temp].year>T1.current_year)  //to ensure that the year of birth
	{                                           //gets entered correctly
		cout<<"Invalid input for year !!!";
		cout<<"\nThe date of birth cannot be after the current system date !!! ";
		cout<<"\nPlease enter the year correctly : ";
		cin>>DOB11[T1.temp].year;
		cout<<"\n";
	}
	while(DOB11[T1.temp].year<1000)
	{
		cout<<"Invalid input for year !!! ";
		cout<<"\nThe year of birth must be of 4 digits!!!";
		cout<<"\nPlease enter the year correctly : ";
		cin>>DOB11[T1.temp].year;
		cin.get();
		cout<<"\n";
	}
	cout<<"Month : ";
	cin>>DOB11[T1.temp].month;
	cin.get();
	while(DOB11[T1.temp].month<1||DOB11[T1.temp].month>12)
	{
		cout<<"Invalid input for month !!!\n";
		cout<<"Again enter the month : ";
		cin>>DOB11[T1.temp].month;
		cin.get();
	}
	cout<<"Date  : ";
	switch(DOB11[T1.temp].month)
	{
		case 1:  case 3:  case 5:  case 7:  case 8:  case 10:  case 12:
		cin>>DOB11[T1.temp].date;           //for months with 31 days
		while(DOB11[T1.temp].date<1||DOB11[T1.temp].date>31)
		{
			cout<<"Invalid date !!!\n";
			cout<<"Again enter the date : ";
			cin>>DOB11[T1.temp].date;
			cin.get();
			cout<<"\n";
		}
		break;

		case 2:                                //for february
		cin>>DOB11[T1.temp].date;
		cin.get();
		if(DOB11[T1.temp].year%4==0)
		{
			while(DOB11[T1.temp].date<1||DOB11[T1.temp].date>29)  //for leap year
			{
				cout<<"Invalid date !!!\n";
				cout<<"Again enter the date : ";
				cin>>DOB11[T1.temp].date;
				cin.get();
				cout<<"\n";
			}
		}
		else
		{
			while(DOB11[T1.temp].date<1||DOB11[T1.temp].date>28)  //for non-leap year
			{
				cout<<"Invalid date !!!\n";
				cout<<"Again enter the date : ";
				cin>>DOB11[T1.temp].date;
				cin.get();
				cout<<"\n";
			}
		}
		break;

		default:
		cin>>DOB11[T1.temp].date;            //for other months
		while(DOB11[T1.temp].date<1||DOB11[T1.temp].date>30)
		{
			cout<<"Invalid date !!!\n";
			cout<<"Again enter the date : ";
			cin>>DOB11[T1.temp].date;
			cin.get();
			cout<<"\n";
		}
	}		                  //end of switch
}                       //end of  function

void all::show_patient_detail()
{
	clrscr();
	if(T1.d_index==1)
	{
		T1.d_index=0;
		cout<<"\n";
		goto direct;
	}
	if(T1.current==0)
	{
		cout<<"\n\n";
		cout<<"\tDatabase is empty !!!\n";
		cout<<"\tPlease enter some information first. \n";
		cout<<"\n\n\tDo you want to enter now (Y/N) : ";
		cin>>T1.enter_now;
		cin.get();
		while(T1.enter_now!='Y'&&T1.enter_now!='y'&&T1.enter_now!='N'&&T1.enter_now!='n')
		{
		cout<<"\n\tPlease enter a correct option (Y/N) : ";
		cin>>T1.enter_now;
		cin.get();
		}
		if(T1.enter_now=='y'||T1.enter_now=='Y')
		{
			A1.enter_patient_info();
		}
		else
		{
			A1.tasks();
		}
	}
	cout<<"\n\t\t****** CURRENT DATEBASE ENTRIES ******\n\n";
	cout<<"\t\tRegistration no.       Name of patient\n\n";
	for(T1.j=1;T1.j<100;T1.j++)
	{
		if(T1.entry_index[T1.j]==1)
		{
			cout<<"\t\t\t"<<T1.j<<"\t\t"<<PI[T1.j].name<<"\n";
		}
		else
		{
			continue;
		}
	}
	cout<<"\n\n\t\tPress 0 to return to main menu.... ";
	cout<<"\n\n\n\tEnter registration number : ";
	cin>>T1.regis;
	clrscr();
	cout<<"\n\n";
	cin.get();
	if(T1.regis==0)
	{
		A1.tasks();
	}
	T1.show_count++;
	direct:                //label for "goto" jump statement
	if(T1.regis<=0)
	{
		T1.attempt++;
		if(T1.attempt==3)
		{
			cout<<"\n\n\tYou have entered wrong registration number 3 times\n";
			cout<<"\tAccess Denied!!! \n";
			cout<<"\tPlease try again later.\n";
			cout<<"\tPress any key to exit to main task menu...\n";
			getch();
			clrscr();
			A1.tasks();
		}
		cout<<"\n\tSorry, invalid registration number !!! ";
		cout<<"\n\tRegistration number starts from 1";
		cout<<"\n\n\tPress any key to continue.....";
		getch();
		A1.show_patient_detail();
	}
	if(T1.regis>0&&T1.regis<T1.serial&&T1.entry_index[T1.regis]==0)
	{
		cout<<"\n\tSorry, the patient has left the hospital.";
		cout<<"\tPress any key to exit to main task menu..."<<"\n";
		getch();
		clrscr();
		A1.tasks();
	}
	cout<<"\n\tPress any key to continue..."<<"\n";
	getch();

	if((T1.regis<0||T1.regis>=T1.serial)&&T1.entry_index[T1.regis]==-1)
	{
		T1.attempt++;
		if(T1.attempt!=3)
		{
			cout<<"\n\n\tSorry, the registration number is invalid ."<<"\n";
			T1.entry=T1.serial-1;
			if(T1.entry==1)
			{
				cout<<"\tOnly 1 record has been added .\n";
			}
			else
			{
				cout<<"\tOnly "<<T1.entry<<" records have been added .\n";
			}
		}
	A1.show_patient_detail();
	}
	if(T1.regis>0&&T1.regis<T1.serial&&T1.entry_index[T1.regis]==1)
	{
		T1.attempt=0;
		cout<<"\n\t  ***INFORMATION FOR PATIENT REGISTRATION NUMBER "<<T1.regis<<"***\n\n";
		cout<<"\tName           : "<<PI[T1.regis].name<<"\n";
		cout<<"\tSex            : ";
		if(PI[T1.regis].sex==1)
			cout<<"Male "<<"\n";
		if(PI[T1.regis].sex==2)
			cout<<"Female "<<"\n";
		cout<<"\tBlood Group    : ";
		switch(PI[T1.regis].bld_group)
		{
			case 1: cout<<"A+\n"; break;
			case 2: cout<<"A-\n"; break;
			case 3: cout<<"B+\n"; break;
			case 4: cout<<"B-\n"; break;
			case 5: cout<<"AB+\n"; break;
			case 6: cout<<"AB-\n"; break;
			case 7: cout<<"O+\n"; break;
			case 8: cout<<"O-\n"; break;
		}	//end of switch

		cout<<"\tDate of birth  : ";
		DOB1.show_date();
		cout<<"\tMartial Status : ";
		if(PI[T1.regis].martial_status==1)
			cout<<"Married "<<"\n";
		else
			cout<<"Single "<<"\n";
		cout<<"\n\t\t**ADDRESS**"<<"\n";
		cout<<"\n\tHouse no. : "<<PI[T1.regis].AD1.house;
		cout<<"\n\tStreet    : "<<PI[T1.regis].AD1.street;
		cout<<"\n\tCity      : "<<PI[T1.regis].AD1.city;
		cout<<"\n\tDistrict  : "<<PI[T1.regis].AD1.dist;
		cout<<"\n\tState     : "<<PI[T1.regis].AD1.state;
		cout<<"\n\tCountry   : "<<PI[T1.regis].AD1.country;

	}
	T1.d_index=0;
	cout<<"\n\n\n\n\tWant to view detail of another patient (Y/N) : ";
	cin>>answer1;
	while(answer1!='Y'&&answer1!='y'&&answer1!='N'&&answer1!='n')
	{
		cout<<"\a\tPease re-enter a correct option (Y/N) ? ";
		cin>>answer1;
	}
	clrscr();
	if(answer1=='Y'||answer1=='y')
		A1.show_patient_detail();
	else
		A1.tasks();
}                       //end of  function

void dob::show_date()
{
	cout<<DOB11[T1.regis].date;
	T1.rem=DOB11[T1.regis].date%10;
	switch(DOB11[T1.regis].date)
	{
	case 11:  case 12:  case 13:  case 14:  case 15:  case 16:  case 17:
	case 18:  case 19:  case 20:
		cout<<"th ";
		goto over;
	}
	switch(T1.rem)
	{
		case 1: cout<<"st "; break;
		case 2: cout<<"nd "; break;
		case 3: cout<<"rd "; break;
		default: cout<<"th ";
	 }
	over:
	switch(DOB11[T1.regis].month)
	{
		case 1: cout<<"January , "; break;
		case 2: cout<<"February , "; break;
		case 3: cout<<"March , "; break;
		case 4: cout<<"April , "; break;
		case 5: cout<<"May , "; break;
		case 6: cout<<"June , "; break;
		case 7: cout<<"July , "; break;
		case 8: cout<<"August , "; break;
		case 9: cout<<"September , "; break;
		case 10: cout<<"October , "; break;
		case 11: cout<<"November , "; break;
		case 12: cout<<"December , "; break;
	}                      //end of switch
	cout<<DOB11[T1.regis].year<<"\n";
}                       //end of  function

void all::software_detail()
{
	clrscr();
	cout<<"\n\n\n\t\t\t ***SOFTWARE DETAILS***\n";
	cout<<"\n\n\tDeveloper                : Sarthak Jain"<<"\n";
	cout<<"\tProgramming Language     : C++ "<<"\n";
	cout<<"\tCompiler used            : Turbo C++ "<<"\n";
	cout<<"\tProject Title            : Hospital Management System"<<"\n";
	cout<<"\n\tThank you for using the system..."<<"\n";
	cout<<"\n\n\n\tPress any key to return to the main task menu......."<<"\n";
	getch();
	A1.tasks();
}                       //end of  function

void all::search_menu()
{
	T1.ssi_count=0;
	if(T1.current==0)
	{
		clrscr();
		cout<<"\n\n\n";
		cout<<"\tDatabase in empty !!!"<<"\n";
		cout<<"\tPlease enter some information first. "<<"\n";
		cout<<"\n\n\tDo you want to enter now (Y/N) : ";
		cin>>T1.enter_now;
		while(T1.enter_now!='Y'&&T1.enter_now!='y'&&T1.enter_now!='N'&&T1.enter_now!='n')
		{
			cout<<"\n\tPlease enter a correct option (Y/N) : ";
			cin>>T1.enter_now;
		}
		if(T1.enter_now=='y'||T1.enter_now=='Y')
			A1.enter_patient_info();
		else
			A1.tasks();
	}
	T1.search_number=0;
	clrscr();
	cout<<"\n\n\t\t***SEARCH MENU***"<<"\n\n\n";
	cout<<"\t\t   1. Search by city  "<<"\n";
	cout<<"\t\t   2. Search by blood group  "<<"\n";
	cout<<"\t\t   3. Return to main menu  "<<"\n";
	cout<<"\n\t Enter your choice : ";
	cin>>s_choice;
	cin.get();
	clrscr();
	switch(s_choice)
	{
		case 1:
		T1.search_index=1;
		cout<<"\n\t\t***SEARCHING BY CITY***\n";
		cout<<"\n\n\tEnter city : ";
		cin.getline(s_city,30);
		cout<<"\n\n\n";
		while(strlen(s_city)==0)   //if enter is pressed before input for city
		{
		     cout<<"\n\tPlease enter a city : ";
		     cin.getline(s_city,30);
		}
		A1.search_city();
		break;

		case 2:
		T1.search_index=2;
		cout<<"\n\t\t***SEARCHING BY BLOOD GROUP***\n";
		cout<<"\n\n\t\t***BLOOD GROUP MENU***\n\n";
		cout<<"\t1. A+\n\t2. A-\n\t3. B+\n\t4. B- \n\t5. AB+ \n\t6. AB-\n";
		cout<<"\t7. O+ \n\t8. O- \n";
		cout<<"\n\tEnter the serial of your required group : ";
		cin>>s_group;
		while(s_group!=1&&s_group!=2&&s_group!=3&&s_group!=4&&
			s_group!=5&&s_group!=6&&s_group!=7&&s_group!=8)
		{
			cout<<"\n\tInvalid search criteria !!!"<<"\n";
			cout<<"\tValid serials are 1 to 8."<<"\n";
			cout<<"\tEnter a valid blood group : \a";
			cin>>s_group;
		}
		cout<<"\n\n\n";
		A1.search_blood_group();
		break;

		case 3: A1.tasks(); break;

		default:
		cout<<"\n\n  Invalid search criteria !!!"<<"\n";
		cout<<"  Valid options are 1 and 2 !!!"<<"\n";
		cout<<"  Press any key to return to the main searching menu....."<<"\n";
		getch();
		A1.search_menu();
		break;
	 }                      //end of switch
}                       //end of  function

void all::search_city()
{
	T1.search_count=0;
	T1.search_number++;
	clrscr();
	cout<<"\n\n\n";
	for(T1.index=1;T1.index<T1.serial;T1.index++)
	{
		if((strcmp(PI[T1.index].AD1.city,s_city))==0)
		{
			if(T1.entry_index[T1.index]==0)
				continue;
			if(T1.search_count==0)
				cout<<"\t\tRegistration no.       Name of patient\n\n";
			cout<<"\n\t\t\t"<<T1.index<<"\t\t"<<PI[T1.index].name;
			T1.search_count++;
		}
	}
	if(T1.search_number==1)
	{
		cout<<"\n\n\t\tSearch is complete !!!\n";
		if(T1.search_count==0)
		{
			cout<<"\t\tNo result found !!!\n";
			cout<<"\t\tPress any key to continue.....";
			getch();
			A1.after_search_options();
		}
		if(T1.search_count>=1)
		{
			cout<<"\t\t"<<T1.search_count<<" result(s) found !!!\n";
		}
	}

	if(T1.search_number==1)
	{
		cout<<"\n\n\t\tWant to view in detail (Y/N) : ";
		cin>>after_search_answer;
		while(after_search_answer!='y'&&after_search_answer!='Y'&&after_search_answer!='N'&&after_search_answer!='n')
		{
			cout<<"\n\t\tPlease enter a correct option (Y/N)";
			cin>>after_search_answer;
		}
		if(after_search_answer=='y'||after_search_answer=='Y')
		{
			cout<<"\n\t\tFor which registration number : ";
			cin>>T1.index;
			A1.search_show_info();
		}
		else
			A1.after_search_options();

	}
	else
	{
		cout<<"\n\t\tWhich registration number : ";
		cin>>T1.index;
		A1.search_show_info();
	}
}                       //end of  function

void all::search_blood_group()
{
	T1.search_count=0;
	T1.search_number++;
	clrscr();
	cout<<"\n\n\n";
	for(T1.index=1;T1.index<T1.serial;T1.index++)
	{
		if(s_group==PI[T1.index].bld_group)
		{
			if(T1.entry_index[T1.index]==0)
				continue;
			if(T1.search_count==0)
				cout<<"\t\tRegistration no.       Name of patient\n\n";
			cout<<"\n\t\t       "<<T1.index<<"\t\t"<<PI[T1.index].name;
			T1.search_count++;
		}
	}
	if(T1.search_number==1)
	{
		cout<<"\n\t  Search is complete !!! "<<"\n";
		if(T1.search_count==0)
		{
			cout<<"\t\t  No matching result found !!!"<<"\n\n\n";
			cout<<"\t\t  Press any key to continue.....";
			getch();
			A1.after_search_options();
		}
		if(T1.search_count>=1)
		{
			cout<<"\t\t  "<<T1.search_count<<" result(s) found !!! "<<"\n\n\n";
		}

	}
	if(T1.search_number==1)
	{
		cout<<"\n\n\t\tWant to view in detail(Y/N) : ";
		cin>>after_search_answer;
		cin.get();
		while(after_search_answer!='y'&&after_search_answer!='Y'&&after_search_answer!='N'&&after_search_answer!='n')
		{
			cout<<"\n\t\tPlease enter a correct option .";
			cout<<"\n\t\tDo you want to view in detail : ";
			cin>>after_search_answer;
		}
		if(after_search_answer=='y'||after_search_answer=='Y')
		{
			cout<<"\n\n\t\tWhich registration number : ";
			cin>>T1.index;
			cin.get();
			A1.search_show_info();
		}
		else
			A1.after_search_options();
	}
	else
	{
		cout<<"\n\n\n\t\tWhich registration number : ";
		cin>>T1.index;
		cin.get();
		A1.search_show_info();
	}
}                       //end of  function

void all::search_show_info()
{
	T1.ssi_count++;
	clrscr();
	cout<<"\n\n";
	if(T1.index<=0)
	{
		if(T1.ssi_count==3)
		{
			clrscr();
			cout<<"\n\n\tYou have entered wrong choice 3 times!!!!";
			cout<<"\n\tPress any key for more options......\a";
			getch();
			A1.after_search_options();
		}
		cout<<"\n\n\tSorry, invalid registration number !!!";
		cout<<"\n\tRegistration number starts from 1 ";
		cout<<"\n\tPress any key to continue.........\n";
		getch();
	}

	if(T1.entry_index[T1.index]==-1||T1.index>=T1.serial)
	{
		if(T1.ssi_count==3)
		{
			clrscr();
			cout<<"\n\n\tYou have entered wrong choice 3 times!!!!";
			cout<<"\n\tPress any key for more options......\a";
			getch();
			A1.after_search_options();
		}
		cout<<"\n\n\t\tSorry, the registration number in invalid ."<<"\n";
		T1.entry=T1.serial-1;
		if(T1.entry==1)
			cout<<"\t\tOnly 1 record has been added .\n";
		else
			cout<<"\t\tOnly "<<T1.entry<<" records have been added .\n";

		cout<<"\t\tPress any key to continue....\a"<<"\n";
		getch();
		T1.ssi_count=0;
	}

	cout<<"\n\t  ***INFORMATION FOR PATIENT REGISTRATION NUMBER "<<T1.index<<"***\n\n";
	cout<<"\tName           : "<<PI[T1.index].name<<"\n";
	cout<<"\tSex            : ";
	if(PI[T1.index].sex==1)
		cout<<"Male "<<"\n";
	if(PI[T1.index].sex==2)
		cout<<"Female "<<"\n";
	cout<<"\tBlood Group    : ";
	switch(PI[T1.index].bld_group)
	{
			case 1: cout<<"A+\n"; break;
			case 2: cout<<"A-\n"; break;
			case 3: cout<<"B+\n"; break;
			case 4: cout<<"B-\n"; break;
			case 5: cout<<"AB+\n"; break;
			case 6: cout<<"AB-\n"; break;
			case 7: cout<<"O+\n"; break;
			case 8: cout<<"O-\n"; break;
	}	//end of switch

	cout<<"\tDate of birth  : ";
		DOB1.search_show_date();
	cout<<"\tMartial Status : ";
	if(PI[T1.index].martial_status==1)
		cout<<"Married "<<"\n";
	else
		cout<<"Single "<<"\n";
	cout<<"\n\t          **ADDRESS**"<<"\n";
	cout<<"\n\tHouse no.      : "<<PI[T1.index].AD1.house;
	cout<<"\n\tStreet         : "<<PI[T1.index].AD1.street;
	cout<<"\n\tCity           : "<<PI[T1.index].AD1.city;
	cout<<"\n\tDistrict       : "<<PI[T1.index].AD1.dist;
	cout<<"\n\tState          : "<<PI[T1.index].AD1.state;
	cout<<"\n\tCountry        : "<<PI[T1.index].AD1.country;
	cout<<"\n\n\n\tWant to view info of another patient within search results (Y/N) ? ";
	cin>>after_search_answer;
	while(after_search_answer!='Y'&&after_search_answer!='y'&&after_search_answer!='N'&&after_search_answer!='n')
	{
		cout<<"\n\tPlease enter a correct option (Y/N) : ";
		cin>>after_search_answer;
	}
	if(after_search_answer=='y'||after_search_answer=='Y')
	{
		switch(T1.search_index)
		{
			case 1:		A1.search_city();	break;
			case 2:		A1.search_blood_group(); break;
		}                     //end of switch
	}
	else
		A1.after_search_options();
}                       //end of  function

void dob::search_show_date()
{
	cout<<DOB11[T1.index].date;
	T1.rem=DOB11[T1.index].date%10;
	switch(DOB11[T1.index].date)
	{
		case 11:  case 12:  case 13:  case 14:  case 15:  case 16:  case 17:
		case 18:  case 19:  case 20:
		cout<<"th ";
		goto over;
	}	      //end of switch
	switch(T1.rem)
	{
		case 1: cout<<"st "; break;
		case 2: cout<<"nd "; break;
		case 3: cout<<"rd "; break;
		default: cout<<"th ";
	 }
	over:
	switch(DOB11[T1.index].month)
	{
		case 1: cout<<"January , "; break;
		case 2: cout<<"February , "; break;
		case 3: cout<<"March , "; break;
		case 4: cout<<"April , "; break;
		case 5: cout<<"May , "; break;
		case 6: cout<<"June , "; break;
		case 7: cout<<"July , "; break;
		case 8: cout<<"August , "; break;
		case 9: cout<<"September , "; break;
		case 10: cout<<"October , "; break;
		case 11: cout<<"November , "; break;
		case 12: cout<<"December , "; break;
	}                      //end of switch
	cout<<DOB11[T1.index].year<<"\n";
}                       //end of  function

void all::after_search_options()
{
	clrscr();
	cout<<"\n\n\n\n\t\tWHAT DO U WANT TO DO NOW ?"<<"\n";
	cout<<"\t\t1. Search again  "<<"\n";
	cout<<"\t\t2. Return to main task menu  "<<"\n";
	cout<<"\n\tEnter your choice : ";
	cin>>T1.after_search_choice;
	cout<<"\n";
	switch(T1.after_search_choice)
	{
		case 1:
			T1.ssi_count=0;
			A1.search_menu();
		break;
		case 2:
			T1.ssi_count=0;
			A1.tasks();
		break;
		default:
			cout<<"\n\n\tInvalid option requested !!!"<<"\n";
			cout<<"\tPress any key to return to the main searching menu..."<<"\n";
			getch();
			A1.search_menu();
	}		                  //end of switch
}                       //end of  function

void all::exit_function()
{
	clrscr();
	if(T1.serial==0)
	{
		cout<<"\n\n\n\n\tYou have not used the software.";
		cout<<"\n\tIt is recommended that you do not exit.";
		cout<<"\n\tPress any key to continue......\a";
		getch();
		clrscr();
		cout<<"\n\n\n\tAre you sure you want to exit (Y/N) ? ";
		cin>>exit_answer;
		while(exit_answer!='Y'&&exit_answer!='y'&&exit_answer!='N'&&exit_answer!='n')
		{
			cout<<"\n\n\tInvalid input !!! ";
			cout<<"\n\tPease re-enter a correct option (Y/N) : \a";
			cin>>exit_answer;
		}
		if(exit_answer=='y'||exit_answer=='Y')
			exit(0);
		else
			A1.tasks();

	}
	
cout<<"\n\tThank you for using the system..."<<"\n";
	cout<<"\n\n\n\tPress any key to continue........"<<"\n";
	getch();
	clrscr();
	cout<<"\n\n\n\tAre you sure you want to exit (Y/N) ? ";
	cin>>exit_answer;
	while(exit_answer!='Y'&&exit_answer!='y'&&exit_answer!='N'&&exit_answer!='n')
	{
		cout<<"\n\n\tInvalid input !!! ";
		cout<<"\n\tPease re-enter a correct option (Y/N) : \a";
		cin>>exit_answer;
	}
	if(exit_answer=='y'||exit_answer=='Y')
		exit(0);

	else
		A1.tasks();

} 
                   //end of  function
