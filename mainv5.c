#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<time.h>
#include<unistd.h>
#include<ctype.h>
#include<stdlib.h>
#include<windows.h>


void gotoxy(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

void sleeps(long int interval)
{
    for(int i=0;i<interval*1000;i++);
}

FILE *fpr;
FILE *us;
FILE *ad;

int u, b;

struct add
{
    char add[100];
    char house_no[100];
    char fname[100];
    char lname[100];
    long long int ophone;
    char rtype[20];
    int cost;
    int q;
    char status[15];
    int n; 
};

struct cus
{
    char cfname[20];
    char clname[20];
    char address[50];
    long long int cph;
    int age;
    int mem;
    char marital_sts[20];
    char job[20];
    int rent;
};

void login_type();
void admin_type();
void admin_menu();
void add_house();
void view_house();
void view_customer();
void remove_house();
void commission();
void ch_adpass();
void user_type();
void user_menu();
void rent_house();
void add_details();
void cancel();
void ch_urpass();

void main()
{
    int i=0;
    time_t t;
	time(&t);
	
    system("cls");

    gotoxy(40, 10);
    for(u=0; u<63; u++)
    {
        printf("=");
    }
    gotoxy(40, 11);
    for(u=0; u<63; u++)
    {
        printf("=");
    }

    for(b = 12; b<25; b++)
    {
        gotoxy(40, b);
        printf("|");
        for(u=0; u<61; u++)
        {
            printf(" ");
        }   
        printf("|");
    }

    gotoxy(40, 25);
    for(u=0; u<63; u++)
    {
        printf("=");
    }
    gotoxy(40, 26);
    for(u=0; u<63; u++)
    {
        printf("=");
    }

    gotoxy(60, 16);
    printf(" %c", 201); 
    for(int i=0;i<19;i++)
    {
        printf("%c",205);sleeps(10000);
    }
    printf("%c\n",187);
    gotoxy(60, 17);
    printf(" %cHOUSE RENTAL SYSTEM",186);
    printf("%c\n",186);
    gotoxy(60, 18);
    printf(" %c",200);
    for(int i=0;i<19;i++)
    {
        printf("%c",205);sleeps(10000);
    }
    printf("%c\n",188);

    gotoxy(41, 21);
    for(u=0; u<61; u++)
    {
        printf("=");
    } 
    gotoxy(42, 22);
    printf("Press any key to continue..");
    gotoxy(41, 23);
    for(u=0; u<61; u++)
    {
        printf("=");
    } 
    gotoxy(42, 24);
    printf("Current date and time : %s",ctime(&t));
    getch();
    login_type();
    system("cls");
}

void login_type()
{
    char sel;
    time_t t;
	time(&t);

    while(1)
    {
        system("cls");
        gotoxy(40, 10);
        for(u=0; u<63; u++)
        {
            printf("=");
        }
        gotoxy(40, 11);
        for(u=0; u<63; u++)
        {
            printf("=");
        }

        for(b = 12; b<25; b++)
        {
            gotoxy(40, b);
            printf("|");
            for(u=0; u<61; u++)
            {
                printf(" ");
            }   
            printf("|");
        }

        gotoxy(40, 25);
        for(u=0; u<63; u++)
        {
            printf("=");
        }
        gotoxy(40, 26);
        for(u=0; u<63; u++)
        {
            printf("=");
        }

        gotoxy(41, 23);
        for(u=0; u<61; u++)
        {
            printf("=");
        } 
        gotoxy(42, 24);
        printf("Current date and time : %s",ctime(&t));

        gotoxy(55, 13);
        printf("\tSelect Login Type :");

        gotoxy(41, 14);
        printf("--------------");
        gotoxy(41, 15);
        printf("1.      Admin");
        gotoxy(41, 16);
        printf("--------------");
        gotoxy(41, 17);
        printf("2.      User");
        gotoxy(41, 18);
        printf("--------------");
        gotoxy(41, 19);
        printf("3.      Exit");
        gotoxy(41, 20);
        printf("--------------");
        gotoxy(41, 21);
        printf(": ");
        scanf("%d", &sel);
        fflush(stdin);

        switch (sel)
        {
        case 1:
            system("cls");
            admin_type();
            system("cls");
            break;
        case 2:
            system("cls");
            user_type();
            system("cls");
            break;
        case 3:
            system("cls");
            gotoxy(40, 10);
            for(u=0; u<63; u++)
            {
                printf("=");
            }
            gotoxy(40, 11);
            for(u=0; u<63; u++)
            {
                printf("=");
            }

            gotoxy(40, 19);
            for(u=0; u<63; u++)
            {
                printf("=");
            }
            gotoxy(40, 20);
            for(u=0; u<63; u++)
            {
                printf("=");
            }
            gotoxy(50, 13);
            printf(" || Thank You for Using our Service ||");
            gotoxy(50, 14);
            printf("--------------------------------------");
            gotoxy(50, 15);
            printf(" || System will close in 5 seconds. ||");
            sleep(5);
            exit(0);
            break;

        default:
            break;
        }
    }
}

void admin_type()
{
    char lgname[30], lgpword[20], un[30], pd[20];
    time_t t;
	time(&t);
    int i = 0;
    int a = 0;
    char c = ' ';

    fpr = fopen("admin.dat", "r");
    if(fpr == NULL)
    {
        fpr = fopen("admin.dat", "w");
        system("cls");

        gotoxy(40, 10);
        for(u=0; u<63; u++)
        {
            printf("=");
        }
        gotoxy(40, 11);
        for(u=0; u<63; u++)
        {
            printf("=");
        }

        gotoxy(40, 19);
        for(u=0; u<63; u++)
        {
            printf("=");
        }
        gotoxy(40, 20);
        for(u=0; u<63; u++)
        {
            printf("=");
        }

        gotoxy(50, 13);
        printf(" || Admin not Registered. ||");
        gotoxy(50, 14);
        printf("----------------------------");
        gotoxy(50, 15);
        printf(" Press any Key to Continue..");
        getch();
        system("cls");

        gotoxy(40, 10);
        for(u=0; u<63; u++)
        {
            printf("=");
        }
        gotoxy(40, 11);
        for(u=0; u<63; u++)
        {
            printf("=");
        }

        for(b = 12; b<25; b++)
        {
            gotoxy(40, b);
            printf("|");
            for(u=0; u<61; u++)
            {
                printf(" ");
            }   
            printf("|");
        }

        gotoxy(40, 25);
        for(u=0; u<63; u++)
        {
            printf("=");
        }
        gotoxy(40, 26);
        for(u=0; u<63; u++)
        {
            printf("=");
        }

        gotoxy(41, 23);
        for(u=0; u<61; u++)
        {
            printf("=");
        } 
        gotoxy(42, 24);
        printf("Current date and time : %s",ctime(&t));

        gotoxy(55, 13);
        printf("\t\xB2\xB2\xB2 Register Admin \xB2\xB2\xB2");

        gotoxy(41, 15);
        printf("\xB2| Create Username and Password |\xB2");
        gotoxy(41, 16);
        printf("Enter UserName: ");
        gotoxy(41, 17);
        printf("> ");
        scanf("%s", lgname);
        gotoxy(41, 18);
        printf("Enter Password: ");
        gotoxy(41, 19);
        printf("> ");
        scanf("%s", lgpword);

        fprintf(fpr,"%s %s",lgname,lgpword);
        fclose(fpr);

        gotoxy(41, 21);
        printf("Registration Successfull!");
        gotoxy(41, 22);
        printf("Press any key to continue...");
        getch();
        system("cls");
    }
    fscanf(fpr,"%s %s",lgname,lgpword);
    do
    {
        gotoxy(40, 10);
        for(u=0; u<63; u++)
        {
            printf("=");
        }
        gotoxy(40, 11);
        for(u=0; u<63; u++)
        {
            printf("=");
        }

        for(b = 12; b<25; b++)
        {
            gotoxy(40, b);
            printf("|");
            for(u=0; u<61; u++)
            {
                printf(" ");
            }   
            printf("|");
        }

        gotoxy(40, 25);
        for(u=0; u<63; u++)
        {
            printf("=");
        }
        gotoxy(40, 26);
        for(u=0; u<63; u++)
        {
            printf("=");
        }

        gotoxy(41, 23);
        for(u=0; u<61; u++)
        {
            printf("=");
        } 
        gotoxy(42, 24);
        printf("Current date and time : %s",ctime(&t));

        gotoxy(55, 13);
        printf("\t\xB2\xB2\xB2 Admin Login \xB2\xB2\xB2");

        gotoxy(41, 15);
        printf("-----------------");
        gotoxy(41, 16);
        printf(" UserName:       ");
        gotoxy(41, 17);
        printf("-----------------");
        gotoxy(41, 18);
        printf("-----------------");
        gotoxy(41, 19);
        printf(" Password:       ");
        gotoxy(41, 20);
        printf("-----------------");
        gotoxy(60, 16);
        scanf("%s", un);
        gotoxy(60, 19);
        while (i<15)
        {
            pd[i] = getch();
            c = pd[i];
            if(c==13)
            {
                break;
            }
            else if(c == 8)
            {
                if(i > 0)
                {
                    i--;
                    printf("\b \b");
                }
            }
            else
            {
                printf("*");
            }
            i++;
        }
        pd[i] = '\0';
        i = 0;

        {
            if(strcmp(lgname, un)==0 && strcmp(lgpword, pd)==0)
            {
                gotoxy(51, 21);
                printf("Login Sucessfull....");
                gotoxy(51, 22);
                printf("Press any key to continue:");
                getch();
                system("cls");
                admin_menu();
            }
            else
            {   
                gotoxy(51, 21);
                printf("Sorry Login Unsucessfull....");
                gotoxy(51, 22);
                printf("Press any key to continue:");
                a++;
                getch();
                system("cls");  
            }
        }
    }
    while(a<=4);
    {
        gotoxy(40, 10);
        for(u=0; u<63; u++)
        {
            printf("=");
        }
        gotoxy(40, 11);
        for(u=0; u<63; u++)
        {
            printf("=");
        }

        gotoxy(40, 19);
        for(u=0; u<63; u++)
        {
            printf("=");
        }
        gotoxy(40, 20);
        for(u=0; u<63; u++)
        {
            printf("=");
        }

        gotoxy(50, 13);
        printf(" || Wrong Login Info for 5 Times.... ||");
        gotoxy(50, 14);
        printf("--------------------------------------");
        gotoxy(50, 15);
        printf(" || System Will Close in Few Seconds ||");
        fclose(fpr);
        sleep(3);
        exit(0);
    }  
}

void admin_menu()
{
    time_t t;
    time(&t);
    int choice;

    while(1)
    {
        system("cls");
        gotoxy(50, 2);
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 |MAIN-MENU| \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        gotoxy(30, 3);
        for(u=0; u<81; u++)
        {
            printf("=");
        }   
        for(b = 4; b<30; b++)
        {
            gotoxy(30, b);
            printf("|");
            for(u=0; u<79; u++)
            {
                printf(" ");
            }
            printf("|");
        }         
        gotoxy(30, 30);
        for(u=0; u<81; u++)
        {
            printf("=");
        }

        gotoxy(57, 4);
        printf("\xB2\xB2\xB2\xB2\xB2\xB2 [ ADMIN ] \xB2\xB2\xB2\xB2\xB2\xB2");

        gotoxy(32, 6);
        printf("*Select and Enter Your Choice From Menu*");

        gotoxy(31, 28);
        for(u=0; u<79; u++)
        {
            printf("=");
        }
        gotoxy(31,29);
        printf("Current date and time : %s",ctime(&t));

        gotoxy(31, 8);
        printf("-----------------------------");
        gotoxy(31, 9);
        printf(" [1]. >> Add a House");
        gotoxy(31, 10);
        printf("-----------------------------");
        gotoxy(31, 11);
        printf(" [2]. >> View House");
        gotoxy(31, 12);
        printf("-----------------------------");
        gotoxy(31, 13);
        printf(" [3]. >> Customer's Details");
        gotoxy(31, 14);
        printf("-----------------------------");
        gotoxy(31, 15);
        printf(" [4]. >> Remove Record");
        gotoxy(31, 16);
        printf("-----------------------------");
        gotoxy(31, 17);
        printf(" [5]. >> Calculate Commission");
        gotoxy(31, 18);
        printf("-----------------------------");
        gotoxy(31, 19);
        printf(" [6]. >> Change Password");
        gotoxy(31, 20);
        printf("-----------------------------");
        gotoxy(31, 21);
        printf(" [7]. >> Switch To User");
        gotoxy(31, 22);
        printf("-----------------------------");
        gotoxy(31, 23);
        printf(" [8]. >> Exit");
        gotoxy(31, 24);
        printf("-----------------------------");
        gotoxy(31, 25);
        printf(" [Select]: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                system("cls");
                add_house();
                system("cls");
                break;
            case 2:
                system("cls");
                view_house();
                system("cls");
                break;
            case 3:
                system("cls");
                view_customer();
                system("cls");
                break;
            case 4:
                system("cls");
                remove_house();
                system("cls");
                break;
            case 5:
                system("cls");
                commission();
                system("cls");
                break;
            case 6:
                system("cls");
                ch_adpass();
                system("cls");
                break;
            case 7:
                system("cls");
                user_type();
                system("cls");
                break;
            case 8:
                system("cls");
                gotoxy(40, 10);
                for(u=0; u<63; u++)
                {
                    printf("=");
                }
                gotoxy(40, 11);
                for(u=0; u<63; u++)
                {
                    printf("=");
                }

                gotoxy(40, 19);
                for(u=0; u<63; u++)
                {
                    printf("=");
                }
                gotoxy(40, 20);
                for(u=0; u<63; u++)
                {
                    printf("=");
                }
                gotoxy(50, 13);
                printf(" || Thank You for Using our Service ||");
                gotoxy(50, 14);
                printf("--------------------------------------");
                gotoxy(50, 15);
                printf(" || System will close in 5 seconds. ||");
                sleep(5);
                exit(0);
                break;

            default:
                system("cls");
                gotoxy(40, 10);
                for(u=0; u<63; u++)
                {
                    printf("=");
                }
                gotoxy(40, 11);
                for(u=0; u<63; u++)
                {
                    printf("=");
                }

                gotoxy(40, 19);
                for(u=0; u<63; u++)
                {
                    printf("=");
                }
                gotoxy(40, 20);
                for(u=0; u<63; u++)
                {
                    printf("=");
                }

                gotoxy(50, 13);
                printf(" || Incorrect Input Entered.. ||");
                gotoxy(50, 14);
                printf("--------------------------------");
                gotoxy(50, 15);
                printf(" || Press any key to continue: ||");
                getch();
                system("cls");
                break;
        }
    } 
}

void add_house()
{
    struct add h;
    int j = 1;
    int i = 0;
    char c;
    int d;
    char aa;
    int count = 0;

    time_t t;
	time(&t);

    house:
    {
        system("cls");
        gotoxy(30, 2);
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Add a House \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        gotoxy(10, 3);
        for(u=0; u<81; u++)
        {
           printf("=");
        }
        for(b = 4; b<30; b++)
        {
            gotoxy(10, b);
            printf("|");
            for(u=0; u<79; u++)
            {
                printf(" ");
            }
            printf("|");
        }
        gotoxy(10, 30);
        for(u=0; u<81; u++)
        {
            printf("=");
        }
        gotoxy(11, 28);

        for(u=0; u<79; u++)
        {
            printf("-");
        }
        gotoxy(11, 29);
        printf("Current date and time : %s",ctime(&t));

        gotoxy(35, 5);
        printf("-->ENTER HOUSE\'S DETAILS<--");

        ad = fopen("House.txt", "r");
        if ( ad == NULL )
        {
            h.n = 0;
        }
        while(fscanf(ad,"%d %s %s %s %s %lld %s %d %d\n", &h.n, h.add, h.house_no, h.fname, h.lname, &h.ophone, h.rtype, &h.cost, &h.q) != EOF);
        fclose(ad);
        {
            h.q = 0;
            h.n = h.n + 1;

            gotoxy(11, 7);
            printf("House Id: [%d]", h.n);

            gotoxy(11, 9);
            printf("Enter Location :");
            gotoxy(55, 9 );
            printf("| Use '_' for Space |");
            gotoxy(11, 10);
            printf("> ");
            //scanf("%s", h.add);
            while(1)
            {
                c = getch();            
                if(c == 13){
                    h.add[i]='\0';
                    i = 0;
                    break;                                        
                }
                else if(c == 8){
                    if(i > 0){
                        i--;
                        printf("\b \b");
                    }
                }
                else if(c == 32)
                {
                    continue;
                }
                else{
                    h.add[i] = c;
                    i++;
                    printf("%c",c);            
                }
            }

            gotoxy(11, 11);
            printf("Street No: ");
            gotoxy(11, 12);
            printf("> ");
            scanf("%s", h.house_no);

            gotoxy(11, 13);
            printf("Owner\'s Name : ");
            gotoxy(55, 13 );
            printf("| First Name<space>Last Name |");
            gotoxy(11, 14);
            printf("> ");
            scanf("%s %s", h.fname,  h.lname);

            gotoxy(11, 15);
            printf("Owner\'s Phone no: ");
            phn:
            {
                gotoxy(11, 16);
                printf("> ");
                scanf("%lld", &h.ophone);
                fflush(stdin);
            }
            
            tp:
            {
                gotoxy(11, 17);
                printf("Room Type :");
                gotoxy(35, 17);
                printf("|| [1. Single Room] | [2. Double Room] | [3. Flat] ||");

                gotoxy(11, 18);
                printf("> ");
                scanf("%d", &d);
                fflush(stdin);
            }
            switch(d)
            {
                case 1:
                strcpy(h.rtype, "Single");
                break;
                
                case 2:
                strcpy(h.rtype, "Double");
                break;

                case 3:
                strcpy(h.rtype, "Flat");
                break;

                default:
                gotoxy(36, 18);
                printf("Invalid Option Re-Enter>");
                goto tp;
                break;
            }

            gotoxy(11, 19);
            printf("Price of Room: ");
            gotoxy(11, 20);
            printf("> ");
            scanf("%d", &h.cost);
            fflush(stdin);
        }
    }
    check:
    {
        system("cls");
        gotoxy(40, 10);
        for(u=0; u<63; u++)
        {
            printf("=");
        }
        gotoxy(40, 11);
        for(u=0; u<63; u++)
        {
            printf("=");
        }

        for(b = 12; b<25; b++)
        {
            gotoxy(40, b);
            printf("|");
            for(u=0; u<61; u++)
            {
                printf(" ");
            }   
            printf("|");
        }

        gotoxy(40, 25);
        for(u=0; u<63; u++)
        {
            printf("=");
        }
        gotoxy(40, 26);
        for(u=0; u<63; u++)
        {
            printf("=");
        }

        gotoxy(41, 23);
        for(u=0; u<61; u++)
        {
            printf("=");
        } 
        gotoxy(42, 24);
        printf("Current date and time : %s",ctime(&t));

        gotoxy(55, 13);
        printf("\tConfirm House's Details: [%d]", h.n);

        gotoxy(41, 15);
        printf("Location:      >> %s", h.add);
        gotoxy(41, 16);
        printf("Street No:     >> %s", h.house_no);
        gotoxy(41, 17);
        printf("Owner's Name:  >> %s %s", h.fname, h.lname);
        gotoxy(41, 18);
        printf("Phone No:      >> %lld", h.ophone);
        gotoxy(41, 19);
        printf("Room Type:     >> %s", h.rtype);
        gotoxy(41, 20);
        printf("Total Price:   >> %d", h.cost);
        gotoxy(41, 21);
        for(u=0; u<61; u++)
        {
            printf("-");
        }
        
        gotoxy(41, 22);
        printf("[Y/y] if [Yes] || [N/n] if [No] || [Esc] to [Exit]: ");
        aa = getch();
        if(aa == 'y' || aa == 'Y')
        {
            ad = fopen("House.txt", "a");
            fprintf(ad,"%d %s %s %s %s %lld %s %d %d\n", h.n, h.add, h.house_no, h.fname, h.lname, h.ophone, h.rtype, h.cost, h.q);
            fclose(ad);
            goto conf;
        }
        else if(aa == 'n' || aa == 'N')
        {
            goto house;
        }
        else if(aa == 27)
        {
            return;
        }
        else
        {
            goto check;
        }

        conf:
        {
            system("cls");
            gotoxy(40, 10);
            for(u=0; u<63; u++)
            {
                printf("=");
            }
            gotoxy(40, 11);
            for(u=0; u<63; u++)
            {
                printf("=");
            }

            for(b = 12; b<25; b++)
            {
                gotoxy(40, b);
                printf("|");
                for(u=0; u<61; u++)
                {
                    printf(" ");
                }   
                printf("|");
            }

            gotoxy(40, 25);
            for(u=0; u<63; u++)
            {
                printf("=");
            }
            gotoxy(40, 26);
            for(u=0; u<63; u++)
            {
                printf("=");
            }

            gotoxy(41, 23);
            for(u=0; u<61; u++)
            {
                printf("=");
            } 
            gotoxy(42, 24);
            printf("Current date and time : %s",ctime(&t));

            gotoxy(55, 13);
            printf("\t-----------------------");
            gotoxy(55, 14);
            printf("\tHouse Sucessfully Added");
            gotoxy(55, 15);
            printf("\t-----------------------");

            gotoxy(41, 16);
            printf("Do you want to add another house?<");
            gotoxy(41, 17);
            printf("> [Y/y] = Yes");
            gotoxy(41, 18);
            printf("> [N/n] = No");
            gotoxy(11, 19);
            c = getch();
            if(c == 'y' || c == 'Y')
            {
                goto house;
            }
            else if(c == 'n' || c == 'N')
            {
            }
            else
            {
                gotoxy(20, 26);
                goto conf;
            }
        }
    }
}

void view_house()
{
    struct add h;

    b = 6;
    system("cls");
    gotoxy(55, 2);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 View House \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

    gotoxy(21, 3);
    for(u=0; u<110; u++)
    {
        printf("=");
    }
    gotoxy(21, 40);
    for(u=0; u<110; u++)
    {
     printf("=");
    }
    
    gotoxy(22, 4);
    printf("House Id");
    gotoxy(35, 4);
    printf("Location");
    gotoxy(50, 4);
    printf("Street No");
    gotoxy(63, 4);
    printf("Owner\'s Name");
    gotoxy(83, 4);
    printf("Phone No");
    gotoxy(94, 4);
    printf("Room Type");
    gotoxy(110, 4);
    printf("Price");
    gotoxy(120, 4);
    printf("Status");
      
    gotoxy(21, 5);
    for(u=0; u<110; u++)
    {
        printf("=");
    }

    ad = fopen("House.txt", "r");
    while((fscanf(ad,"%d %s %s %s %s %lld %s %d %d\n", &h.n, h.add, h.house_no, h.fname, h.lname, &h.ophone, h.rtype, &h.cost, &h.q)) != EOF)
    {
        if(h.q == 2)
        {
            strcpy(h.status, "[Removed]");
        }
        else if(h.q == 1)
        {
            strcpy(h.status, "[Rented]");
        }
        else if(h.q == 0)
        {
            strcpy(h.status, "[Available]");
        }

        gotoxy(23, b);
        printf("[%d]", h.n);
        gotoxy(34, b);
        printf("%s", h.add);
        gotoxy(52, b);
        printf("%s", h.house_no);
        gotoxy(64, b);
        printf("%s %s", h.fname, h.lname);
        gotoxy(82, b);
        printf("%lld", h.ophone);
        gotoxy(95, b);
        printf("%s", h.rtype);
        gotoxy(110, b);
        printf("%d", h.cost);
        gotoxy(118, b);
        //printf("s", h.q);
        printf("%s", h.status);
        b++;
    }
    fclose(ad);
    
    gotoxy(50,39);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(21, 41);
    printf("-->Enter any key to continue >");
    getch();
}

void view_customer()
{
    struct cus g;
    
    b = 6;
    system("cls");
    gotoxy(55, 2);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 View Customer \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

    gotoxy(21, 3);
    for(u=0; u<110; u++)
    {
        printf("=");
    }
    gotoxy(21, 40);
    for(u=0; u<110; u++)
    {
     printf("=");
    }

    gotoxy(25, 4);
    printf("Customer's Name");
    gotoxy(45, 4);
    printf("Phone No");
    gotoxy(57, 4);
    printf("Permanent Address");
    gotoxy(77, 4);
    printf("Age");
    gotoxy(83, 4);
    printf("Members");
    gotoxy(92, 4);
    printf("Job/Occupation");
    gotoxy(109, 4);
    printf("Status");
    gotoxy(120, 4);
    printf("H-Id/C-Code");

    gotoxy(21, 5);
    for(u=0; u<110; u++)
    {
        printf("=");
    }

    us = fopen("Customer.txt", "r");
    while((fscanf(us,"%s %s %s  %lld %d %d %s %s %d\n", g.cfname, g.clname, g.address, &g.cph, &g.age, &g.mem, g.marital_sts, g.job, &g.rent)) != EOF)
    {
        gotoxy(24, b);
        printf("%s %s", g.cfname, g.clname);
        gotoxy(44, b);
        printf("%lld", g.cph);
        gotoxy(57, b);
        printf("%s", g.address);
        gotoxy(77, b);
        printf("%d", g.age);
        gotoxy(85, b);
        printf("%d", g.mem);
        gotoxy(94, b);
        printf("%s", g.job);
        gotoxy(108, b);
        printf("%s", g.marital_sts);
        gotoxy(123, b);
        printf("%d", g.rent);
        b++;
    } 
    fclose(us);

    gotoxy(50, 39);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(21, 41);
    printf("-->Enter any key to continue >");
    getch();

}

void remove_house()
{
    struct add h;
    time_t t;
	time(&t);
    int house_id, i;
    char op;

    rem:
    {
        system("cls");
        gotoxy(50, 3);
        for(u=0; u<61; u++)
        {
            printf("=");
        }
        for(b = 4; b<20; b++)
        {
            gotoxy(50, b);
            printf("|");
            for(u=0; u<59; u++)
            {
                printf(" ");
            }
            printf("|");
        }
        gotoxy(50, 20);
        for(u=0; u<61; u++)
        {
            printf("=");
        }

        gotoxy(65, 5);
        printf("\tSELECT REMOVE TYPE:");
        gotoxy(51, 18);
        printf("-------------------------------------------------");
        gotoxy(51, 19);
        printf("Current date and time : %s",ctime(&t));

        gotoxy(51, 7);
        printf("--------------");
        gotoxy(51, 8);
        printf("[1]. House Id");
        gotoxy(51, 9);
        printf("--------------");
        gotoxy(51, 10);
        printf("[2]. Format");
        gotoxy(51, 11);
        printf("--------------");
        gotoxy(51, 12);
        printf("[3]. Exit");
        gotoxy(51, 13);
        printf("--------------");
        tp:
        {
            gotoxy(51, 14);
            printf("> ");

            scanf("%d", &i);
            fflush(stdin);
        }
        switch (i)
        {
        case 1:
            {
                gotoxy(50, 3);
                for(u=0; u<61; u++)
                {
                    printf("=");
                }
                for(b = 4; b<20; b++)
                {
                    gotoxy(50, b);
                    printf("|");
                    for(u=0; u<59; u++)
                    {
                        printf(" ");
                    }
                    printf("|");
                }
                gotoxy(50, 20);
                for(u=0; u<61; u++)
                {
                    printf("=");
                }

                gotoxy(55, 5);
                printf("\tREMOVE HOUSE RECORD :");
                gotoxy(51, 18);
                printf("-------------------------------------------------");
                gotoxy(51, 19);
                printf("Current date and time : %s",ctime(&t));

                gotoxy(51, 7);
                printf("--------------");
                gotoxy(51, 9);
                printf("--------------");
                gotoxy(51, 8);
                printf("Enter House Id: ");
                scanf("%d", &house_id);
                fflush(stdin);

                ad = fopen("House.txt", "r+");
                while((fscanf(ad,"%d %s %s %s %s %lld %s %d %d\n", &h.n, h.add, h.house_no, h.fname, h.lname, &h.ophone, h.rtype, &h.cost, &h.q)) != EOF)
                {
                    if(house_id == h.n )
                    {
                        while(h.q == 0)
                        {
                            h.q = 2;
                            fseek(ad, -3, SEEK_CUR);
                            fprintf(ad, "%d", h.q);
                            fclose(ad);

                            gotoxy(51, 13);
                            printf("====================================");
                            gotoxy(51, 14);
                            printf("[House Id %d removed successfully]", house_id);
                            gotoxy(51, 15);
                            printf("==================================");
                            gotoxy(51, 16);
                            printf("[---Press any key to continue.--]");
                            gotoxy(51, 17);
                            printf("====================================");
                            getch();
                            return;
                        }
                        while(h.q == 1)
                        {
                            gotoxy(51, 13);
                            printf("====================================");
                            gotoxy(51, 14);
                            printf("  House Id (%d) currently Rented   ", house_id);
                            gotoxy(51, 15);
                            printf(" Cannot Remove Requested House Id ");
                            gotoxy(51, 16);
                            printf(" ----Press any key to continue.---");
                            gotoxy(51, 17);
                            printf("====================================");
                            getch();
                            return;   
                        }
                    }
                }
                if(house_id != h.n)
                {
                    gotoxy(51, 14);
                    printf("==================================");
                    gotoxy(51, 15);
                    printf("-->>Invalid House Id[ Wrong Input ]");   
                    gotoxy(51, 16);
                    printf("-->>[  Enter Any Key To Continue  ]");
                    gotoxy(51, 17);
                    printf("==================================");
                    getch();
                    system("cls");
                    return;
                }
            }
            break;
        
        case 2:
            {
                system("cls");
                piece:
                {
                    gotoxy(40, 11);
                    for(u=0; u<63; u++)
                    {
                        printf("=");
                    }

                    for(b = 12; b<20; b++)
                    {
                        gotoxy(40, b);
                        printf("|");
                        for(u=0; u<61; u++)
                        {
                            printf(" ");
                        }   
                        printf("|");
                    }

                    gotoxy(40, 20);
                    for(u=0; u<63; u++)
                    {
                        printf("=");
                    }

                    gotoxy(41, 23);
                    for(u=0; u<61; u++)
                    {
                        printf("=");
                    } 
                    gotoxy(42, 24);
                    printf("Current date and time : %s",ctime(&t));

                    gotoxy(47, 13);
                    printf(" Continue Formating All House and Customer Record ");
                    
                    gotoxy(41, 15);
                    printf("[Y/y] if YES  >>");
                    gotoxy(41, 16);
                    printf("[N/n] if No   >>");
                    gotoxy(41, 17);
                    printf("[Esc] if Exit >>");
                    gotoxy(41, 18);
                    op = getch();
                    if ( op == 'Y' || op == 'y')
                    {
                        goto wano;
                    }
                    else if( op == 'N' || op == 'n')
                    {
                        system("cls");
                        return;
                    }
                    else if( op == 27)
                    {
                        system("cls");
                        gotoxy(50, 13);
                        printf(" || Thank You for Using our Service ||");
                        gotoxy(50, 14);
                        printf("--------------------------------------");
                        gotoxy(50, 15);
                        printf(" || System will close in 5 seconds. ||");
                        sleep(5);
                        exit(0);
                    }
                    else
                    {
                        goto piece;
                    }
                }
                wano:
                {
                    remove("Customer.txt");
                    remove("House.txt");
                    system("cls");
                    gotoxy(45, 5);
                    printf("=========================");
                    gotoxy(45, 6);
                    printf("=========================");
                    gotoxy(45, 7);
                    printf("   All Record Formated");
                    gotoxy(45, 8);
                    printf("=========================");
                    gotoxy(45, 9);
                    printf("=========================");
                    gotoxy(45,10);
                    printf("Enter any key............");
                    gotoxy(45, 11);
                    printf("=========================");
                    gotoxy(45, 12);
                    printf("=========================");
                    getch();
                    system("cls");
                    return;
                }
            }
            break;

        case 3:
            break;

        default:
            gotoxy(26, 18);
            printf("Invalid Option Re-Enter>");
            goto tp;
            break;
        }
    }
}

void commission()
{
    struct add h;
    int amt;
    int per;
    int yy, i;

    time_t t;
	time(&t);

    commission:
    {
        gotoxy(50, 3);
        for(u=0; u<61; u++)
        {
            printf("=");
        }
        for(b = 4; b<20; b++)
        {
            gotoxy(50, b);
            printf("|");
            for(u=0; u<59; u++)
            {
                printf(" ");
            }
        printf("|");
        }
        gotoxy(50, 20);
        for(u=0; u<61; u++)
        {
        printf("=");
        }

        gotoxy(60, 5);
        printf("\t[Calculate Commission]");
        gotoxy(51, 18);
        printf("------------------------------------------------");
        gotoxy(51, 19);
        printf("Current date and time : %s",ctime(&t));
        gotoxy(51, 7);
        printf("Enter House Id: ");
        scanf("%d", &i);
        fflush(stdin);

        ad = fopen("House.txt", "r");
        while((fscanf(ad,"%d %s %s %s %s %lld %s %d %d\n", &h.n, h.add, h.house_no, h.fname, h.lname, &h.ophone, h.rtype, &h.cost, &h.q)) != EOF)
        {
            if(i == h.n )
            {
                goto cal;
            }
        }
    }

    cal:
    {
        if(h.q == 1)
        {   
            gotoxy(51, 8);
            printf("House Id: [%d]", h.n);
            gotoxy(51, 9);
            printf("Enter Commission (in percent): ");
            scanf("%d", &per);
            amt = (per * h.cost)/100;
            gotoxy(51, 10);
            printf("Total Commission Amount is: %d", amt);
            gotoxy(51, 11);
            printf("Enter any key to continue..");
            getch();
        }
        else
        {
            gotoxy(51, 15);
            printf("=>>>> Invalid Id:");
            gotoxy(51, 16);
            printf("House Not Rented Or Not Available");
            gotoxy(51, 17);
            printf("Enter any key to continue.........");
            getch();
        }
        fclose(ad);

    }
}

void ch_adpass()
{
    char lgname[30], lgpword[20], un[30], pd[20];
    time_t t;
	time(&t);

    ad = fopen("admin.dat", "w");
    if(ad == NULL)
    {
        printf("Error opening File!");
        exit(1);
    }
    fscanf(ad,"%s %s",lgname,lgpword);

    system("cls");
    gotoxy(40, 10);
    for(u=0; u<63; u++)
    {
        printf("=");
    }
    gotoxy(40, 11);
    for(u=0; u<63; u++)
    {
        printf("=");
    }

    for(b = 12; b<25; b++)
    {
        gotoxy(40, b);
        printf("|");
        for(u=0; u<61; u++)
        {
            printf(" ");
        }   
        printf("|");
    }

    gotoxy(40, 25);
    for(u=0; u<63; u++)
    {
        printf("=");
    }
    gotoxy(40, 26);
    for(u=0; u<63; u++)
    {
        printf("=");
    }

    gotoxy(41, 23);
    for(u=0; u<61; u++)
    {
        printf("=");
    } 
    gotoxy(42, 24);
    printf("Current date and time : %s",ctime(&t));

    gotoxy(55, 13);
    printf("\t\xB2\xB2\xB2 Change Admin's Login Info \xB2\xB2\xB2");

    gotoxy(41, 15);
    printf("\xB2| Create New Username and Password |\xB2");
    gotoxy(41, 16);
    printf("-------------------");
    gotoxy(41, 17);
    printf("Enter New UserName:       ");
    gotoxy(41, 18);
    printf("-------------------");
    gotoxy(41, 19);
    printf("-------------------");
    gotoxy(41, 20);
    printf("Enter New Password:       ");
    gotoxy(41, 21);
    printf("-------------------");
    gotoxy(75, 17);
    scanf("%s", lgname);
    gotoxy(75, 20);
    scanf("%s", lgpword);
    fprintf(ad,"%s %s",lgname, lgpword);
    fclose(ad);
    gotoxy(45, 22);
    printf("Enter any Key to Continue");
    getch();
}

void user_type()
{
    char lgname[30], lgpword[20], un[30], pd[20];
    time_t t;
	time(&t);
    int i = 0;
    int a = 0;
    char c = ' ';

    fpr = fopen("user.dat", "r");
    if(fpr == NULL)
    {
        fpr = fopen("user.dat", "w");
        system("cls");

        gotoxy(40, 10);
        for(u=0; u<63; u++)
        {
            printf("=");
        }
        gotoxy(40, 11);
        for(u=0; u<63; u++)
        {
            printf("=");
        }

        gotoxy(40, 19);
        for(u=0; u<63; u++)
        {
            printf("=");
        }
        gotoxy(40, 20);
        for(u=0; u<63; u++)
        {
            printf("=");
        }

        gotoxy(55, 14);
        printf(" || User not Registered.. ||");
        gotoxy(55, 15);
        printf("----------------------------");
        gotoxy(55, 16);
        printf(" Press any Key to Continue..");
        getch();
        system("cls");

        gotoxy(40, 10);
        for(u=0; u<63; u++)
        {
            printf("=");
        }
        gotoxy(40, 11);
        for(u=0; u<63; u++)
        {
            printf("=");
        }

        for(b = 12; b<25; b++)
        {
            gotoxy(40, b);
            printf("|");
            for(u=0; u<61; u++)
            {
                printf(" ");
            }   
            printf("|");
        }

        gotoxy(40, 25);
        for(u=0; u<63; u++)
        {
            printf("=");
        }
        gotoxy(40, 26);
        for(u=0; u<63; u++)
        {
            printf("=");
        }

        gotoxy(41, 23);
        for(u=0; u<61; u++)
        {
            printf("=");
        } 
        gotoxy(42, 24);
        printf("Current date and time : %s",ctime(&t));

        gotoxy(55, 13);
        printf("\t\xB2\xB2\xB2 Register User \xB2\xB2\xB2");

        gotoxy(41, 15);
        printf("\xB2| Create Username and Password |\xB2");
        gotoxy(41, 16);
        printf("Enter UserName: ");
        gotoxy(41, 17);
        printf("> ");
        scanf("%s", lgname);
        gotoxy(41, 18);
        printf("Enter Password: ");
        gotoxy(41, 19);
        printf("> ");
        scanf("%s", lgpword);

        fprintf(fpr,"%s %s",lgname,lgpword);
        fclose(fpr);

        gotoxy(41, 21);
        printf("Registration Successfull!");
        gotoxy(41, 22);
        printf("Press any key to continue...");
        getch();
        system("cls");
    }
    fscanf(fpr,"%s %s",lgname,lgpword);
    do
    {
        gotoxy(40, 10);
        for(u=0; u<63; u++)
        {
            printf("=");
        }
        gotoxy(40, 11);
        for(u=0; u<63; u++)
        {
            printf("=");
        }

        for(b = 12; b<25; b++)
        {
            gotoxy(40, b);
            printf("|");
            for(u=0; u<61; u++)
            {
                printf(" ");
            }   
            printf("|");
        }

        gotoxy(40, 25);
        for(u=0; u<63; u++)
        {
            printf("=");
        }
        gotoxy(40, 26);
        for(u=0; u<63; u++)
        {
            printf("=");
        }

        gotoxy(41, 23);
        for(u=0; u<61; u++)
        {
            printf("=");
        } 
        gotoxy(42, 24);
        printf("Current date and time : %s",ctime(&t));

        gotoxy(55, 13);
        printf("\t\xB2\xB2\xB2 User Login \xB2\xB2\xB2");

        gotoxy(41, 15);
        printf("-----------------");
        gotoxy(41, 16);
        printf(" UserName:       ");
        gotoxy(41, 17);
        printf("-----------------");
        gotoxy(41, 18);
        printf("-----------------");
        gotoxy(41, 19);
        printf(" Password:       ");
        gotoxy(41, 20);
        printf("-----------------");
        gotoxy(60, 16);
        scanf("%s", un);
        gotoxy(60, 19);
        while (i<15)
        {
            pd[i] = getch();
            c = pd[i];
            if(c==13)
            {
                break;
            }
            else if(c == 8)
            {
                if(i > 0)
                {
                    i--;
                    printf("\b \b");
                }
            }
            else
            {
                printf("*");
            }
            i++;
        }
        pd[i] = '\0';
        i = 0;

        {
            if(strcmp(lgname, un)==0 && strcmp(lgpword, pd)==0)
            {
                gotoxy(51, 21);
                printf("Login Sucessfull....");
                gotoxy(51, 22);
                printf("Press any key to continue:");
                getch();
                system("cls");
                user_menu();
            }
            else
            {   
                gotoxy(51, 21);
                printf("Sorry Login Unsucessfull....");
                gotoxy(51, 22);
                printf("Press any key to continue:");
                a++;
                getch();
                system("cls");  
            }
        }
    }
    while(a<=4);
    {
        gotoxy(40, 10);
        for(u=0; u<63; u++)
        {
            printf("=");
        }
        gotoxy(40, 11);
        for(u=0; u<63; u++)
        {
            printf("=");
        }

        gotoxy(40, 19);
        for(u=0; u<63; u++)
        {
            printf("=");
        }
        gotoxy(40, 20);
        for(u=0; u<63; u++)
        {
            printf("=");
        }

        gotoxy(50, 13);
        printf(" || Wrong Login Info for 5 Times.... ||");
        gotoxy(50, 14);
        printf("--------------------------------------");
        gotoxy(50, 15);
        printf(" || System Will Close in Few Seconds ||");
        fclose(fpr);
        sleep(3);
        exit(0);
    }  
}

void user_menu()
{
    time_t t;
    time(&t);
    int choice;

    while(1)
    {
        gotoxy(50, 2);
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 |MAIN-MENU| \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        gotoxy(30, 3);
        for(u=0; u<81; u++)
        {
            printf("=");
        }   
        for(b = 4; b<30; b++)
        {
            gotoxy(30, b);
            printf("|");
            for(u=0; u<79; u++)
            {
                printf(" ");
            }
            printf("|");
        }         
        gotoxy(30, 30);
        for(u=0; u<81; u++)
        {
            printf("=");
        }

        gotoxy(60, 5);
        printf("\xB2\xB2\xB2 [ USER ] \xB2\xB2\xB2");

        gotoxy(50, 6);
        printf("*Select and Enter Your Choice From Menu*");

        gotoxy(31, 28);
        for(u=0; u<79; u++)
        {
            printf("-");
        }
        gotoxy(31,29);
        printf("Current date and time : %s",ctime(&t));

        gotoxy(31, 8);
        printf("-----------------------------");
        gotoxy(31, 9);
        printf(" [1]. >> View House");
        gotoxy(31, 10);
        printf("-----------------------------");
        gotoxy(31, 11);
        printf(" [2]. >> Rent a House");
        gotoxy(31, 12);
        printf("-----------------------------");
        gotoxy(31, 13);
        printf(" [3]. >> Cancel");
        gotoxy(31, 14);
        printf("-----------------------------");
        gotoxy(31, 15);
        printf(" [4]. >> Change Password");
        gotoxy(31, 16);
        printf("-----------------------------");
        gotoxy(31, 17);
        printf(" [5]. >> Switch To Admin");
        gotoxy(31, 18);
        printf("-----------------------------");
        gotoxy(31, 19);
        printf(" [6]. >> Exit");
        gotoxy(31, 20);
        printf("-----------------------------");
        gotoxy(31, 21);
        printf(" [Select]: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                system("cls");
                view_house();
                system("cls");
                break;

            case 2:
                system("cls");
                rent_house();
                system("cls");
                break;

            case 3:
                system("cls");
                cancel();
                system("cls");
                break;

            case 4:
                system("cls");
                ch_urpass();
                system("cls");
                break;

            case 5:
                system("cls");
                admin_type();
                system("cls");
                break;

            case 6:
                system("cls");
                gotoxy(40, 10);
                for(u=0; u<63; u++)
                {
                    printf("=");
                }
                gotoxy(40, 11);
                for(u=0; u<63; u++)
                {
                    printf("=");
                }

                gotoxy(40, 19);
                for(u=0; u<63; u++)
                {
                    printf("=");
                }
                gotoxy(40, 20);
                for(u=0; u<63; u++)
                {
                    printf("=");
                }
                gotoxy(50, 13);
                printf(" || Thank You for Using our Service ||");
                gotoxy(50, 14);
                printf("--------------------------------------");
                gotoxy(50, 15);
                printf(" || System will close in 5 seconds. ||");
                sleep(5);
                exit(0);
                break;

            default:
                system("cls");
                gotoxy(40, 10);
                for(u=0; u<63; u++)
                {
                    printf("=");
                }
                gotoxy(40, 11);
                for(u=0; u<63; u++)
                {
                    printf("=");
                }

                gotoxy(40, 19);
                for(u=0; u<63; u++)
                {
                    printf("=");
                }
                gotoxy(40, 20);
                for(u=0; u<63; u++)
                {
                    printf("=");
                }

                gotoxy(50, 13);
                printf(" || Incorrect Input Entered.. ||");
                gotoxy(50, 14);
                printf("--------------------------------");
                gotoxy(50, 15);
                printf(" || Press any key to continue: ||");
                getch();
                system("cls");
                break;
        }
    } 
}
void rent_house()
{
    time_t t;
    time(&t);
    FILE *ad1;

    int i;
    char op;
    char aa;
    struct add h;
    struct cus g;

    one:
    {
        gotoxy(40, 11);
        for(u=0; u<63; u++)
        {
            printf("=");
        }

        for(b = 12; b<20; b++)
        {
            gotoxy(40, b);
            printf("|");
            for(u=0; u<61; u++)
            {
                printf(" ");
            }   
            printf("|");
        }

        gotoxy(40, 20);
        for(u=0; u<63; u++)
        {
            printf("=");
        }

        gotoxy(41, 23);
        for(u=0; u<61; u++)
        {
            printf("=");
        } 
        gotoxy(42, 24);
        printf("Current date and time : %s",ctime(&t));

        gotoxy(55, 13);
        printf("\tDo You Want To Continue Renting ?");
        
        gotoxy(41, 15);
        printf("[Y/y] if YES  >>");
        gotoxy(41, 16);
        printf("[N/n] if No   >>");
        gotoxy(41, 17);
        printf("[Esc] if Exit >>");
        gotoxy(41, 18);
        op = getch();
        if ( op == 'Y' || op == 'y')
        {
            system("cls");
            goto book;
            system("cls");
        }
        else if( op == 'N' || op == 'n')
        {
            system("cls");
            return;
        }
        else if( op == 27)
        {
            system("cls");
            gotoxy(50, 13);
            printf(" || Thank You for Using our Service ||");
            gotoxy(50, 14);
            printf("--------------------------------------");
            gotoxy(50, 15);
            printf(" || System will close in 5 seconds. ||");
            sleep(5);
            exit(0);
        }
        else
        {
            goto one;
        }
    }

    book:
    {
        gotoxy(50, 3);
        for(u=0; u<61; u++)
        {
            printf("=");
        }
        for(b = 4; b<20; b++)
        {
            gotoxy(50, b);
            printf("|");
            for(u=0; u<59; u++)
            {
                printf(" ");
            }
            printf("|");
        }
        gotoxy(50, 20);
        for(u=0; u<61; u++)
        {
            printf("=");
        }

        gotoxy(65, 5);
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Rent a House \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        gotoxy(51, 18);
        printf("-------------------------------------------------");
        gotoxy(51, 19);
        printf("Current date and time : %s",ctime(&t));

        gotoxy(51, 7);
        printf("\xB2\xB2\xB2 [ Select House Id ] \xB2\xB2\xB2");
        gotoxy(51, 9);
        printf("--------------");
        gotoxy(51, 10);
        printf("=>Enter      :");
        gotoxy(51, 11);
        printf("--------------");
        gotoxy(67, 10);
        scanf("%d", &i);
        fflush(stdin);

        ad = fopen("House.txt", "r+");
        while((fscanf(ad,"%d %s %s %s %s %lld %s %d %d\n", &h.n, h.add, h.house_no, h.fname, h.lname, &h.ophone, h.rtype, &h.cost, &h.q)) != EOF)
        {
            if(i == h.n)
            {
                system("cls");
                if(h.q == 0)
                {   
                    system("cls");
                    gotoxy(31, 15);
                    printf("-->>");   
                    gotoxy(32, 16);
                    printf("Enter Any Key To Add Customer's Details>..");
                    getch();
                    system("cls");
                    add_details(i);
                    h.q = 1;
                    fseek(ad, -3, SEEK_CUR);
                    fprintf(ad, "%d", h.q);
                    system("cls");
                    break;
                }
                else if(h.q == 1)
                {
                    system("cls");
                    gotoxy(31, 14);
                    printf("--------------------------------------");
                    gotoxy(31, 15);
                    printf("-->>Invalid House Id[ Already Rented ]");   
                    gotoxy(32, 16);
                    printf("-->>[   Enter Any Key To Continue   ]");
                    gotoxy(31, 17);
                    printf("--------------------------------------");
                    getch();
                    system("cls");
                    break;           
                }
                else if(h.q == 2)
                {
                    system("cls");
                    gotoxy(31, 14);
                    printf("--------------------------------------");
                    gotoxy(31, 15);
                    printf("-->>Invalid House Id[ Removed ]");   
                    gotoxy(32, 16);
                    printf("-->>[   Enter Any Key To Continue   ]");
                    gotoxy(31, 17);
                    printf("--------------------------------------");
                    getch();
                    system("cls");
                    break;      
                }                   
            }
        }
        if(i != h.n) 
        {
            system("cls");
            gotoxy(31, 14);
            printf("------------------------------------");
            gotoxy(31, 15);
            printf("-->>Invalid House Id [ Wrong Input ]");   
            gotoxy(32, 16);
            printf("-->>[  Enter Any Key To Continue  ]");
            gotoxy(31, 17);
            printf("------------------------------------");
            getch();
            system("cls");
            return;
        }
        fclose(ad);
        return;
    }
}

void add_details(int x)
{
    struct cus g;
    char ny[2];
    time_t t;
    time(&t);
    char ca;
    int i , c, j, aa;
    int k = 0;
    g.rent = x;

    details:
    {
        system("cls");
        gotoxy(30, 2);
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Add  Details \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        gotoxy(10, 3);
        for(u=0; u<81; u++)
        {
            printf("=");
        }
        for(b = 4; b<30; b++)
        {
            gotoxy(10, b);
            printf("|");
            for(u=0; u<79; u++)
            {
                printf(" ");
            }
            printf("|");
        }
        gotoxy(10, 30);
        for(u=0; u<81; u++)
        {
            printf("=");
        }

        gotoxy(11, 28);
        for(u=0; u<79; u++)
        {
            printf("-");
        }
        gotoxy(11,29);
        printf("Current date and time : %s",ctime(&t));
        gotoxy(32, 4);
        printf("\xB2\xB2\xB2 |ENTER CUSTOMER'S DETAILS| \xB2\xB2\xB2");

        gotoxy(11, 6);
        printf("--------------------------");
        gotoxy(11, 7);
        printf(">> [ENTER YOUR NAME]      : ");
        gotoxy(61, 7);
        printf("|First Name<space>Last Name|");
        gotoxy(11, 8);
        printf("--------------------------");
        gotoxy(41, 7);
        scanf("%s %s", g.cfname,  g.clname);

        gotoxy(11, 9);
        printf(">> [ENTER PHONE NO]       : ");
        gotoxy(11, 10);
        printf("--------------------------");
        gotoxy(41, 9);
        scanf("%lld", &g.cph);
        fflush(stdin);

        gotoxy(11, 11);
        printf(">> [PERMANENT ADDRESS]    : ");
        gotoxy(61, 11);
        printf("| Use '_' for Space |");
        gotoxy(11, 12);
        printf("--------------------------");
        gotoxy(41, 11);
        //scanf("%s", g.address);
        while(1)
        {
            ca = getch();            
            if(ca == 13){
                g.address[k]='\0';
                k = 0;
                break;                                        
            }
            else if(ca == 8){
                if(k > 0){
                    i--;
                    printf("\b \b");
                }
            }
            else if(ca == 32)
            {
                continue;
            }
            else
            {
                g.address[k] = ca;
                k++;
                printf("%c",ca);            
            }
        }

        gotoxy(11, 13);
        printf(">> [ENTER YOUR AGE]       : ");
        gotoxy(11, 14);
        printf("--------------------------");
        gotoxy(41, 13);
        scanf("%d", &g.age);
        fflush(stdin);

        gotoxy(11, 15);
        printf(">> [OCCUPATION/JOB]       : ");
        gotoxy(11, 16);
        printf("--------------------------");
        gotoxy(41, 15);
        scanf("%s", g.job);

        gotoxy(11, 17);
        printf(">> [TOTAL FAMILY MEMBERS] : ");
        gotoxy(11, 18);
        printf("--------------------------");
        gotoxy(41, 17);
        scanf("%d", &g.mem);
        fflush(stdin);

        gotoxy(11, 19);
        printf(">> [MARITAL STATUS(Y/N)]  : ");
        gotoxy(11, 20);
        printf("--------------------------");
        gotoxy(41, 19);
        scanf("%s", ny);
        if((!strcmp(ny, "Y")) || (!strcmp(ny, "y")))
        {
            strcpy(g.marital_sts, "Married");
        }
        else if((!strcmp(ny, "N")) || (!strcmp(ny, "n")))
        {
            strcpy(g.marital_sts, "Unmarried");
        }
        else
        {
            printf("[Wrong Input : Status Saved as 'Undeclared']");
            strcpy(g.marital_sts, "Undeclared");
        }

        onepiece:
        {
            system("cls");
            gotoxy(40, 10);
            for(u=0; u<63; u++)
            {
                printf("=");
            }
            gotoxy(40, 11);
            for(u=0; u<63; u++)
            {
                printf("=");
            }

            for(b = 12; b<25; b++)
            {
                gotoxy(40, b);
                printf("|");
                for(u=0; u<61; u++)
                {
                    printf(" ");
                }   
                printf("|");
            }

            gotoxy(40, 25);
            for(u=0; u<63; u++)
            {
                printf("=");
            }
            gotoxy(40, 26);
            for(u=0; u<63; u++)
            {
                printf("=");
            }

            gotoxy(41, 23);
            for(u=0; u<61; u++)
            {
                printf("=");
            } 
            gotoxy(42, 24);
            printf("Current date and time : %s",ctime(&t));

            gotoxy(55, 13);
            printf("\tConfirm Your Details:");

            gotoxy(41, 14);
            printf("Address:       >> %s", g.address);
            gotoxy(41, 15);
            printf("Name:          >> %s %s", g.cfname, g.clname);
            gotoxy(41, 16);
            printf("Age:           >> %d", g.age);
            gotoxy(41, 17);
            printf("Phone No:      >> %lld", g.cph);
            gotoxy(41, 18);
            printf("Occupation:    >> %s", g.job);
            gotoxy(41, 19);
            printf("Members:       >> %d", g.mem);
            gotoxy(41, 20);
            printf("Status:        >> %s", g.marital_sts);
            gotoxy(41, 21);
            for(u=0; u<61; u++)
            {
                printf("-");
            }
            
            gotoxy(41, 22);
            printf("[Y/y] if [Yes] || [N/n] if [No] || [Esc] to [Exit]: ");
            aa = getch();
            if(aa == 'y' || aa == 'Y')
            {
                us = fopen("Customer.txt", "a");
                fprintf(us,"%s %s %s  %lld %d %d %s %s %d\n", g.cfname, g.clname, g.address, g.cph, g.age, g.mem, g.marital_sts, g.job, g.rent);
                fclose(us);
            }
            else if(aa == 'n' || aa == 'N')
            {
                goto details;
            }
            else if(aa == 27)
            {
                return;
            }
            else
            {
                goto onepiece;
            }
        }

        system("cls");
        gotoxy(40, 10);
        for(u=0; u<63; u++)
        {
            printf("=");
        }
        gotoxy(40, 11);
        for(u=0; u<63; u++)
        {
            printf("=");
        }

        gotoxy(40, 19);
        for(u=0; u<63; u++)
        {
            printf("=");
        }
        gotoxy(40, 20);
        for(u=0; u<63; u++)
        {
            printf("=");
        }

        gotoxy(50, 13);
        printf("| Details added successfully |");
        gotoxy(50, 14);
        printf("----------------------------");
        gotoxy(50, 15);
        printf(" Your Customer Code Is: %d", g.rent);
        gotoxy(50, 16);
        printf("----------------------------");
        gotoxy(50, 17);
        printf(" Press any Key to Continue..");
        getch();
        system("cls");

    }
}

void cancel()
{
    time_t t;
    time(&t);
    long long int temp_cph;
    int temp_rent;

    int i;
    int l = 0;
    struct add h;
    struct cus g;

    can:
    {
        system("cls");
        gotoxy(30, 3);
        for(u=0; u<61; u++)
        {
            printf("=");
        }
        for(b = 4; b<20; b++)
        {
            gotoxy(30, b);
            printf("|");
            for(u=0; u<59; u++)
            {
                printf(" ");
            }
            printf("|");
        }
        gotoxy(30, 20);
        for(u=0; u<61; u++)
        {
            printf("=");
        }

        gotoxy(45, 5);
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Cancel \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        gotoxy(31, 18);
        printf("-------------------------------------------------");
        gotoxy(31, 19);
        printf("Current date and time : %s",ctime(&t));

        gotoxy(31, 7);
        printf("-------------------");
        gotoxy(31, 8);
        printf("Enter Phone Number : ");
        gotoxy(31, 9);
        printf("-------------------");

        gotoxy(52, 8);
        scanf("%lld", &temp_cph);
        fflush(stdin);
    
        gotoxy(31, 10);
        printf("Enter Customer Code:");
        gotoxy(31, 11);
        printf("-------------------");
        gotoxy(52, 10);
        scanf("%d", &temp_rent);
        fflush(stdin);

        us = fopen("Customer.txt", "r+");
        while((fscanf(us,"%s %s %s  %lld %d %d %s %s %d\n", g.cfname, g.clname, g.address, &g.cph, &g.age, &g.mem, g.marital_sts, g.job, &g.rent)) != EOF)
        {
            if(temp_rent == g.rent)
            {
                if(temp_cph == g.cph)
                {
                    ad = fopen("House.txt", "r+");
                    while((fscanf(ad,"%d %s %s %s %s %lld %s %d %d\n",&h.n, h.add, h.house_no, h.fname, h.lname, &h.ophone, h.rtype, &h.cost, &h.q)) != EOF)
                    {
                        while(temp_rent == h.n)
                        {
                            g.rent = 0;
                            fseek(us, -3, SEEK_CUR);
                            fprintf(us, "%d", g.rent);
                            fclose(us);

                            h.q = 0;
                            fseek(ad, -3, SEEK_CUR);
                            fprintf(ad, "%d", h.q);
                            fclose(ad);

                            gotoxy(31, 15);
                            printf("-->>");   
                            gotoxy(32, 16);
                            printf("| Sucessfully Canceled |");
                            gotoxy(32, 17);
                            printf("Press any key to Continue.");
                            getch();
                            return;
                        }
                    } 
                }
           }
        }
        if(temp_rent != g.rent || temp_cph != g.cph)
        {
            gotoxy(31, 14);
            printf("-------------------------------------------------------");
            gotoxy(31, 15);
            printf("Invaild Entry (Either [Not Rented] or [Not Available] )");
            gotoxy(31, 16);
            printf("        Enter Any Key To Continue..");
            gotoxy(31, 17);
            printf("-------------------------------------------------------");
            getch();
            return;
        }

    }
}

void ch_urpass()
{
    char lgname[30], lgpword[20], un[30], pd[20];
    time_t t;
	time(&t);

    ad = fopen("user.dat", "w");
    if(ad == NULL)
    {
        printf("Error opening File!");
        exit(1);
    }
    fscanf(ad,"%s %s",lgname,lgpword);

    system("cls");
    gotoxy(40, 10);
    for(u=0; u<63; u++)
    {
        printf("=");
    }
    gotoxy(40, 11);
    for(u=0; u<63; u++)
    {
        printf("=");
    }

    for(b = 12; b<25; b++)
    {
        gotoxy(40, b);
        printf("|");
        for(u=0; u<61; u++)
        {
            printf(" ");
        }   
        printf("|");
    }

    gotoxy(40, 25);
    for(u=0; u<63; u++)
    {
        printf("=");
    }
    gotoxy(40, 26);
    for(u=0; u<63; u++)
    {
        printf("=");
    }

    gotoxy(41, 23);
    for(u=0; u<61; u++)
    {
        printf("=");
    } 
    gotoxy(42, 24);
    printf("Current date and time : %s",ctime(&t));

    gotoxy(55, 13);
    printf("\t\xB2\xB2\xB2 Change User's Login Info \xB2\xB2\xB2");

    gotoxy(41, 15);
    printf("\xB2| Create New Username and Password |\xB2");
    gotoxy(41, 16);
    printf("-------------------");
    gotoxy(41, 17);
    printf("Enter New UserName:       ");
    gotoxy(41, 18);
    printf("-------------------");
    gotoxy(41, 19);
    printf("-------------------");
    gotoxy(41, 20);
    printf("Enter New Password:       ");
    gotoxy(41, 21);
    printf("-------------------");
    gotoxy(75, 17);
    scanf("%s", lgname);
    gotoxy(75, 20);
    scanf("%s", lgpword);
    fprintf(ad,"%s %s",lgname, lgpword);
    fclose(ad);
    gotoxy(45, 22);
    printf("Enter any Key to Continue");
    getch();
}