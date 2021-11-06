#include<stdio.h>
#include<string.h>
#include<conio.h>
struct Info
{
	char name;
	long mbl;
	long amt;
	int ourps;
};
void main()
{
    FILE *p;
    char file_name[10];
    struct Info obj1;
    long damt,wamt;
    int ps;
    int choice;
    
    printf(" 1 For new aacount:");
    printf("\n 2 For old account:");
    scanf("%d",&choice);
    switch(choice)
    {
    	case 1: printf("For new account :\n\n");
    	        printf("Enter your name : ");
    	        scanf("%s",&obj1.name);
    	        printf("Enter your mobile number :");
    	        scanf("%ld",&obj1.mbl);
    	        printf("How many amount you want to deposit at initially :");
    	        scanf("%ld",&obj1.amt);
    	        printf("Set your password :");
    	        scanf("%d",&obj1.ourps);
    	        getch();
    	        
    	        printf("Registration done successfully...");
    	        getch();
    	        
    	        file_name[0]=obj1.name;
    	        strcat(file_name,".txt");
    	        p=fopen(file_name,"w");
    	        fwrite(&obj1,sizeof(obj1),1,p);
    	        fclose(p);
    	        printf("\n Thank you....!!\n");
    	        break;
    	case 2:
		        printf("Enter your name as per account form :");
		        scanf("%s",&obj1.name);
				file_name[0]=getchar();
				file_name[0]=getchar();
				strcat(file_name,".txt");
				p=fopen(file_name,"r");
				printf("\n\nOpened file is %s",file_name);
				fread(&obj1,sizeof(obj1),1,p);
				fclose(p);
				printf("\n\nData are :\nName\t: \t%c \nMobile\t: \t%ld \namount\t: \t%ld \nPW\t:\t%d\n\n",obj1.name,obj1.mbl,obj1.amt,obj1.ourps);
				break;
			}
			getch();
			
			printf("Welcome to your bank Mr./Mrs. : %c",obj1.name);
			printf("\n\n Now you are ready for banking !");
			l1:
			l3:
			getch();
			
			printf("\nEnter your password :");
			scanf("%d",&ps);
			
			if(ps==obj1.ourps)
			{
				printf("\n\n Select one of the option :");
				printf("\n1 For balance check");
				printf("\n2 For Deposit");
				printf("\n3 For withdrawl");
				printf("\n4 exit");
				printf("\n Enter choice :");
				scanf("%d",&choice);
				getch();
				
				switch(choice)
				{
					case 1: printf("\n You select balance check :");
					        printf("\n\n Your bank balance is %ld",obj1.amt);
					        break;
					case 2: printf("\nYou select deposit option :");
					        printf("\n\n How many amount you want to deposit");
							scanf("%ld",&damt);
							obj1.amt=obj1.amt+damt;
							getch();
							
							printf("Deposited Successfully");
							break;
					case 3: printf("\n You select withdrawl option :");
					        l2:
					        printf("\n\nHow many amount you want to withdrawl");
							scanf("%ld",&wamt);
							if(wamt>obj1.amt)
							{
								printf(" Sufficient fund not available");
								goto l2;	
							}
							obj1.amt=obj1.amt-wamt;
							printf("Successfullly withdrawl");
							break;
					case 4: printf("Thank you..!!");
					        goto l5;		        
				}
				getch();
				printf("\n\n Do you want to continue the banking");
				printf("\n1 Yes\n 2 for No\nEnter :");
				scanf("%d",&choice);
				if(choice==1)
				{
					goto l3;
				}
				else if(choice==2)
				{
					goto l4;
				}
				}
				else
				{
					printf("\n\nInvalid password !");
					goto l1;
				}
				l4:
				l5:
				printf("\n\n Thank you for banking with us :");
				p=fopen(file_name,"w");
				fwrite(&obj1,sizeof(obj1),1,p);
				fclose(p);						
	}

