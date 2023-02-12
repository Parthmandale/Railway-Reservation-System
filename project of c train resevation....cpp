#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>


typedef struct passdetails{
	char name[50];
	int train_num;
	int num_of_seats;
}pd;




/*FUNCTION PROTOTYPE*/

void reservation();							
void viewdetails();							
void cancel();								
void printticket(char name[],int,int,float);	 
void specifictrain(int);						
float charge(int,int);							
void login();

/*MAIN()*/

int main()

{
		system("cls"); 
	printf("\t\t=================================================\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|        -----------------------------          |\n");
	printf("\t\t|           TRAIN TICKET RERS. SYSTEM           |\n");
	printf("\t\t|        -----------------------------          |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|              BROUGHT TO YOU BY                |\n");
	printf("\t\t|  |PARTH MANDALE , AADITYA RAJ , VISHAL KUMAR| |\n");
	printf("\t\t|ROLL NO - 76     ,    45        ,     38       |\n");
	printf("\t\t=================================================\n\n\n");
		
	    
	printf(" \n Press any key to continue:");
	
	getch();	
    system("cls");
	login();
	int menu_choice,choice_return;
	start:
	system("cls");
	printf("\n=================================\n");
	printf("    TRAIN RESERVATION SYSTEM");
	printf("\n=================================");
	printf("\n1>> Reserve A Ticket");
	printf("\n------------------------");
	printf("\n2>> View All Available Trains");
	printf("\n------------------------");
	printf("\n3>> Cancel Reservation");
	printf("\n------------------------");
	printf("\n4>> Exit");
	printf("\n------------------------");
	printf("\n\n-->");
	printf("Enter the number as per your --->>>");
	scanf("%d",&menu_choice);
	switch(menu_choice)
	{
		case 1:
			reservation();		
			break;
		case 2:
			viewdetails();
			printf("\n\nPress any key to go to Main Menu..");
			getch();
			break;
		case 3:
			cancel();
				break;
		case 4:
			
			return(0);
		default:
			printf("\nInvalid choice");
	}
	goto start;
	return(0);
}

/*VIEWDETAILS()*/

void viewdetails(void)
{
	system("cls");
	printf("-----------------------------------------------------------------------------");	
	printf("\nTr.No\tName\t\t\tDestinations\t\tCharges\t\tTime\n");
	printf("-----------------------------------------------------------------------------");
	printf("\n1001\t1st line Express\tMumbai to Goa\t\t\tRs.5000\t\t9am");
	printf("\n1002\t2ndline Express\t\tKanyakumari to Trivandrum\tRs.5000\t\t12pm");
	printf("\n1003\t3rd line Express\tPune to Amravati\t\tRs.4500\t\t8am");
	printf("\n1004\t4th line Express\tDelhi to Bangluru\t\tRs.4500\t\t11am");
	printf("\n1005\t5th line Express\tAkola to Pune\t\t\tRs.4000\t\t7am");
	printf("\n1006\t6th line Express\tHydrabad to Mujafarnagar\tRs.4000\t\t9.30am");
    printf("\n1007\t7th line Express\tgoa to nagpur\t\t\tRs.3500\t\t1pm");	
    printf("\n1008\t8th line Express\tJammu to Ladhakh\t\tRs.3500\t\t4pm");
    printf("\n1009\t9th line Express\tPunjab to Sikhim\t\tRs.6000\t\t3.35pm");
    printf("\n1010\t10th line Express\tOrissa to Himachal\t\tRs.6000\t\t4.15pm");
   
}

/*RESERVATION()*/

void reservation()
{
	char confirm;
	int i=0;
	float charges;
	pd passdetails;
	FILE *fp;
	fp=fopen("seats_reserved.txt","a");
	system("cls");
	
	printf("\nEnter Your Name:> ");
	fflush(stdin);
	gets(passdetails.name);
	
	printf("\nEnter Number of seats:> ");
	scanf("%d",&passdetails.num_of_seats);
	printf("\n\n>>Press Enter To View Available Trains<< ");
	getch();
	system("cls");
	viewdetails();
	printf("\n\nEnter train number:> ");
	start1:
	scanf("%d",&passdetails.train_num);
	if(passdetails.train_num>=1001 && passdetails.train_num<=1010)
	{
		charges=charge(passdetails.train_num,passdetails.num_of_seats);
		printticket(passdetails.name,passdetails.num_of_seats,passdetails.train_num,charges);		
	}
	else
	{
		printf("\nInvalid train Number! Enter again--> ");
		goto start1;
	}
	
	printf("\n\nConfirm Ticket (y/n):>");
	start:
	scanf(" %c",&confirm);
	if(confirm == 'y')
	{
		fprintf(fp,"%s\t\t%d\t\t%d\t\t%.2f\n",&passdetails.name,passdetails.num_of_seats,passdetails.train_num,charges);
		printf("==================");
		printf("\n Reservation Done\n");
		printf("==================");
		printf("\nPress any key to go back to Main menu");
	}
	else
	{
		if(confirm=='n'){
			printf("\nReservation Not done !\nPress any key to go back to  Main menu!");
		}
		else
		{
			printf("\nInvalid choice entered! Enter again-----> ");
			goto start;
		}
	}
	fclose(fp);
	getch();
}

/*CHARGE()*/

float charge(int train_num,int num_of_seats)
{
		if (train_num==1001)
	{
		return(5000.0*num_of_seats);
	}
	if (train_num==1002)
	{
		return(5000.0*num_of_seats);
	}
	if (train_num==1003)
	{
		return(4500.0*num_of_seats);
	}
	if (train_num==1004)
	{
		return(4500.0*num_of_seats);
	}
	if (train_num==1005)
	{
		return(4000.0*num_of_seats);
	}
	if (train_num==1006)
	{
		return(4000.0*num_of_seats);
	}
	if (train_num==1007)
	{
		return(3500.0*num_of_seats);
	}
	if (train_num==1008)
	{
		return(3500.0*num_of_seats);
	}
	if (train_num==1009)
	{
		return(6000.0*num_of_seats);
	}
	if (train_num==1010)
	{
		return(6000.0*num_of_seats);
	}
}


/*PRINTTICKET()*/

void printticket(char name[],int num_of_seats,int train_num,float charges)
{
	system("cls");
	printf("------------------- \n");
	printf("\tTICKET\n");
	printf("-------------------\n\n");
	printf("Name:\t\t\t%s",name);
	printf("\nNumber Of Seats:\t%d",num_of_seats);
	printf("\nTrain Number:\t\t%d",train_num);
	specifictrain(train_num);
	printf("\nCharges:\t\t%.2f",charges);
}

/*SPECIFICTRAIN()*/

void specifictrain(int train_num)
{
	
	if (train_num==1001)
	{
		printf("\nTrain:\t\t\t1st line Express");
		printf("\nDestination:\t\tMumbai to Goa");
		printf("\nDeparture:\t\t9am ");
	}
	if (train_num==1002)
	{
		printf("\nTrain:\t\t\t2nd line Express");
		printf("\nDestination:\t\tKanyakumari to Trivandrum");
		printf("\nDeparture:\t\t12pm");
	}
	if (train_num==1003)
	{
		printf("\nTrain:\t\t\t3rd line Express");
		printf("\nDestination:\t\tPune to Amravati");
		printf("\nDeparture:\t\t8am");
	}
	if (train_num==1004)
	{
		printf("\nTrain:\t\t\t4th line Express");
		printf("\nDestination:\t\Delhi to Bangluru");
		printf("\nDeparture:\t\t11am ");
	}
	if (train_num==1005)
	{
		printf("\nTrain:\t\t\t5th line Express");
		printf("\nDestination:\t\tAkola to Pune");
		printf("\nDeparture:\t\t7am");
	}
	if (train_num==1006)
	{
		printf("\ntrain:\t\t\t6th line Express");
		printf("\nDestination:\t\tChicago to Boston");
		printf("\nDeparture:\t\t9.30am ");
	}
	if (train_num==1007)
	{
		printf("\ntrain:\t\t\t7th line Express");
		printf("\nDestination:\t\tHydrabad to Mujafarnagar");
		printf("\nDeparture:\t\t1pm ");
	}
	if (train_num==1008)
	{
		printf("\ntrain:\t\t\t8th line Express");
		printf("\n Destination:\t\tJammu to Ladhakh");
		printf("\nDeparture:\t\t4pm ");
	}
	if (train_num==1009)
	{
		printf("\ntrain:\t\t\t9th line Express");
		printf("\nDestination:\t\tPunjab to Sikhim");
		printf("\nDeparture:\t\t3.35pm ");
	}
	if (train_num==1010)
	{
		printf("\ntrain:\t\t\t10th line Express");
		printf("\nDestination:\t\tOrissa to Himachal");
		printf("\nDeparture:\t\t1.15 ");
	}
}

void login()
{
	int a=0,i=0;
    char uname[10],c; 
    char pword[10],code[10];
    char user[10]="user";
    char pass[10]="pass";
    do
{
	
    printf("\n  =======================  LOGIN FORM  =======================\n  ");
    printf(" \n                       ENTER USERNAME:-");
	scanf("%s", uname); 
	printf(" \n                       ENTER PASSWORD:-");
	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) 
		break;
	    else 
		printf("*");
	    i++;
	}
	pword[i]='\0';
	
	i=0;
	 
		if(strcmp(uname,"user")==0 && strcmp(pword,"pass")==0)
	{
	printf("  \n\n\n       WELCOME TO OUR SYSTEM !! YOUR LOGIN IS SUCCESSFUL");
	printf("\n\n\n\t\t\t\tPress any key to continue...");
	getch();
	break;
	}
	else
	{
		printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
		a++;
		
		getch();
		system("cls");
	}
}

while (a <= 2);
  if (a > 2)
    {
      printf
	("\nSorry you have entered the wrong username and password for four times!!!");

      getch ();

    }
  system ("cls");
}

void cancel (){
  system ("cls");
  int trainnum;
  printf ("-----------------------\n");
  printf ("Enter the train number: \n");
  printf ("-----------------------\n");
  fflush (stdin);
  scanf ("%i", &trainnum);
  printf ("\n\nCancelled");
  getch ();
}

