#include<stdio.h>
#include"conio2.h"
#include"car.h"
#include<string.h>
void addAdmin()
{
    FILE *fp=fopen("admin.bin","rb");
    if(fp==NULL)
    {
        fp=fopen("admin.bin","wb");
        User u[2]={{"admin","test","Ravi"},{"super","demo","Anil"}};
        fwrite(u,sizeof(u),1,fp);
    }
    fclose(fp);
}
User * getInput()
{
    int i;
    clrscr();
    textcolor(YELLOW);
    gotoxy(32,1);
    printf("CAR RENTAL SYSTEM\n");
    for(i=1; i<=80; i++)
        printf("%c",247);
    gotoxy(32,5);
    printf("* LOGIN PANEL *");
    gotoxy(1,7);
    textcolor(LIGHTCYAN);
    for(i=1; i<80; i++)
        printf("%c",247);
    gotoxy(1,15);
    for(i=1; i<80; i++)
        printf("%c",247);
    gotoxy(60,8);
    textcolor(WHITE);
    printf("Press 0 to exit");
    gotoxy(25,10);
    textcolor(LIGHTCYAN);
    printf("Enter user id:");
    textcolor(WHITE);
    static User usr;
    fflush(stdin);
    fgets(usr.userid,20,stdin);
    char *pos;
    pos=strchr(usr.userid,'\n');
    if(pos!=NULL)
    {
         *pos='\0';
    }
    if(strcmp(usr.userid,"0")==0)
    {
        textcolor(LIGHTRED);
        gotoxy(30,17);
        printf("Login Cancelled!");
        getch();
        textcolor(YELLOW);
        return NULL;
    }
        gotoxy(25,11);
        textcolor(LIGHTCYAN);
        printf("Enter Password:");
        fflush(stdin);
        i=0;
        textcolor(WHITE);
      int e,d;
      e=d=0;
    for(;;)
    {
        textcolor(WHITE);
        usr.pwd[i]=getch();
        if(usr.pwd[i]==13)
        {
            break;
        }
       if(usr.pwd[i]=='\b')
       {
            if(d!=e)
                {
                    printf("\b");
                    printf(" ");
                    printf("\b");
                    d++;
                }
        }
            if(usr.pwd[i]!='\b')
            {
                printf("*");
                e++;
                i++;
            }
    }
    usr.pwd[i]='\0';
    if(strcmp(usr.pwd,"0")==0)
    {
        textcolor(LIGHTRED);
        gotoxy(30,17);
        printf("Login Cancelled!");
        getch();
        textcolor(YELLOW);
        return NULL;
    }
        getch();
        return &usr;
}
int checkUserExist(User u,char * usertype)
{
    if(strlen(u.userid)==0||strlen(u.pwd)==0)
    {
        gotoxy(28,20);
        textcolor(LIGHTRED);
        printf("Both fields are mandotory.Try again!");
        getch();
        gotoxy(28,20);
        printf("\t\t\t\t\t\t\t");
        return 0;
    }
    FILE *fp;
    if(strcmp(usertype,"admin")==0)
    {
        fp=fopen("admin.bin","rb");
    }
    else
    {
        fp=fopen("emp.bin","rb");
    }
    if(fp==NULL)
    {
        gotoxy(28,20);
        textcolor(LIGHTRED);
        printf("Sorry! can not open the file");
        getch();
        gotoxy(28,20);
        printf("\t\t\t\t\t\t\t");
        return -1;
    }
    int found=0;
    User user;
    while(fread(&user,sizeof(user),1,fp)==1)
    {
        if(strcmp(u.userid,user.userid)==0 && strcmp(u.pwd,user.pwd)==0)
        {
            found=1;
            break;
        }
    }
    if(found==0)
    {
        gotoxy(28,20);
        textcolor(LIGHTRED);
        printf("Invalid! UserId/password.try again");
        getch();
        gotoxy(28,20);
        printf("\t\t\t\t\t\t\t");
    }
    else
    {
        gotoxy(28,20);
        textcolor(GREEN);
        printf("Login sucessful!");
        getch();
        gotoxy(28,20);
        printf("\t\t\t\t\t\t\t");
    }
    fclose(fp);
    return found;
}
int adminMenu()
{
    int i;
    int choice;
    textcolor(LIGHTRED);
    gotoxy(32,2);
    printf("CAR RENTAL SYSTEM");
    textcolor(LIGHTGREEN);
    gotoxy(35,6);
    printf("ADMIN MENU\n");
    for(i=0;i<=80;i++)
        printf("*");
    gotoxy(32,8);
    textcolor(WHITE);
    printf("1. Add Employee");
    gotoxy(32,9);
    printf("2. View Employee");
    gotoxy(32,11);
    printf("3. Add Car Details");
    gotoxy(32,10);
    printf("4. Show Car Details");
    gotoxy(32,12);
    printf("5. Delete Employee");
    gotoxy(32,13);
    printf("6. Delete Car Details");
    gotoxy(32,14);
    printf("7. Exit");
    gotoxy(32,16);
    printf("Enter choice:");
    scanf("%d",&choice);
    return choice;
}
void addEmployee()
{
    char empid[10]={"EMP-"};
    char temp[20];
    char choice;
    char *pos;
    User u;
    int i;
    FILE *fp=fopen("emp.bin","ab+");
    fseek(fp,0,SEEK_END);
    long total_rec=ftell(fp)/sizeof(User);
    /*if(total_rec!=0)
    {
        fseek(fp,-60,SEEK_END);
        fread(temp,sizeof(temp),1,fp);
        printf("temp is%s",temp);
        getch();
        pos=strchr(temp,'-');
        total_rec=atoi(pos+1);
        printf("\ntotal rec is %d",total_rec);
        getch();
    }*/
    total_rec++;
    sprintf(u.userid,"EMP-%d",total_rec);
    fseek(fp,0,SEEK_END);
    do
    {
        clrscr();
        gotoxy(32,2);
        textcolor(LIGHTRED);
        printf("CAR RENTAL APP");
        gotoxy(1,3);
        textcolor(LIGHTGREEN);
        for(i=0;i<=80;i++)
              printf("~");
        gotoxy(25,5);
        textcolor(WHITE);
        printf("***** ADD EMPLOYEE DETAILS *****");
        gotoxy(1,8);
        textcolor(YELLOW);
        printf("Enter Employee Name:");
        fflush(stdin);
        textcolor(WHITE);
        fgets(u.name,20,stdin);
        pos=strchr(u.name,'\n');
        if(pos!=NULL)
        {
            *pos='\0';
        }
        textcolor(YELLOW);
        printf("Enter Employee Pwd:");
        fflush(stdin);
        textcolor(WHITE);
        fgets(u.pwd,20,stdin);
        pos=strchr(u.pwd,'\n');
        if(pos!=NULL)
        {
            *pos='\0';
        }
        fwrite(&u,sizeof(u),1,fp);
        gotoxy(30,15);
        textcolor(LIGHTGREEN);
        printf("EMPLOYEE ADDED SUCESSFULLY!\n");
        printf("EMPLOYEE ID is %s",u.userid);
        getch();
        gotoxy(1,20);
        textcolor(LIGHTRED);
        printf("Do you want to add employee(Y/N)?");
        textcolor(WHITE);
        fflush(stdin);
        scanf("%c",&choice);
        if(choice=='N')
            break;
        total_rec++;
        sprintf(u.userid,"EMP-%lu",total_rec);
    }while(1);
    fclose(fp);
}

void addCarDetails()
{
    char carid[10]={"CARID-"};
    char temp[10];
    char opt;
    Car c;
    FILE *fp=fopen("car.bin","ab+");
    fseek(fp,0,SEEK_END);
    long total_rec=ftell(fp)/sizeof(Car);
    total_rec++;
    sprintf(temp,"%lu",total_rec);
    strcat(carid,temp);
    strcpy(c.car_id,carid);
    do
    {
         clrscr();
         gotoxy(32,2);
         textcolor(LIGHTRED);
         printf("CAR RENTAL APP");
         gotoxy(1,3);
         textcolor(LIGHTGREEN);
         int i;
         for(i=0;i<=80;i++)
               printf("~");
         gotoxy(25,5);
         textcolor(WHITE);
         printf("***** ADD CAR DETAILS *****");
         gotoxy(1,8);
         textcolor(YELLOW);
         printf("Enter Car Model : ");
         fflush(stdin);
         textcolor(WHITE);
         fgets(c.car_name,50,stdin);
         char *pos;
         pos=strchr(c.car_name,"\n");
         if(pos!=NULL)
         {
             *pos='\0';
         }
         textcolor(YELLOW);
         printf("Enter Car Capacity : ");
         textcolor(WHITE);
         fflush(stdin);
         scanf("%d",&c.capacity);
         textcolor(YELLOW);
         printf("Enter Car Count : ");
         textcolor(WHITE);
         fflush(stdin);
         scanf("%d",&c.car_count);
         textcolor(YELLOW);
         printf("Enter Car price for per day : ");
         textcolor(WHITE);
         fflush(stdin);
         scanf("%d",&c.price);
         fwrite(&c,sizeof(c),1,fp);
         gotoxy(30,15);
         textcolor(LIGHTGREEN);
         printf("EMPLOYEE ADDED SUCCESSFULLY!");
         printf("\nCAR ID IS :- %s",c.car_id);
         getch();
         gotoxy(1,20);
         textcolor(LIGHTRED);
         printf("DO YOU WANT TO ADD MORE CAR DETAILS(Y/N)? :");
         textcolor(WHITE);
         fflush(stdin);
         scanf("%c",&opt);
         if(opt=='N')
             break;
        total_rec++;
        sprintf(c.car_id,"CARID-%d",total_rec);
    }while(1);
    fclose(fp);
}

void viewEmployee()
{
    clrscr();
    FILE *fp=fopen("emp.bin","rb");
    User ur;
    int i;
    textcolor(YELLOW);
    gotoxy(32,1);
    printf("CAR RENTAL SYSTEM\n");
    for(i=0;i<80;i++)
        printf("%c",247);
    gotoxy(30,5);
    printf("* EMPLOYEE DETAILS *");
    textcolor(LIGHTGREEN);
    gotoxy(1,7);
    for(i=0;i<80;i++)
        printf("%c",247);
    if(fp==NULL)
    {
        gotoxy(31,9);
        textcolor(LIGHTRED);
        printf("Sorry! NO employee added yet!");
        getch();
        return;
    }
    gotoxy(1,8);
    printf(" Employee ID\t\t\tName\t\t\tPassword");
    gotoxy(1,9);
    for(i=0;i<80;i++)
        printf("%c",247);
    int row=10;
    textcolor(YELLOW);
    while(fread(&ur,sizeof(ur),1,fp)==1)
    {
        gotoxy(2,row);
        printf("%s",ur.userid);
        gotoxy(33,row);
        printf("%s",ur.pwd);
        gotoxy(57,row);
        printf("%s",ur.pwd);
        row++;
    }
    fclose(fp);
    getch();
}
int deleteEmp()
{
    FILE *fp1=fopen("emp.bin","rb");
    char empid[10];
    int i,result;
    textcolor(YELLOW);
    gotoxy(32,1);
    printf("CAR RENTAL SYSTEM\n");
    for(i=0;i<79;i++)
        printf("%c",247);
    gotoxy(29,5);
    printf("* DELETE EMPLOYEE RECORD *");
    gotoxy(1,7);
    textcolor(LIGHTGREEN);
    for(i=0;i<79;i++)
        printf("%c",247);
    gotoxy(1,12);
    textcolor(LIGHTGREEN);
     for(i=0;i<79;i++)
        printf("%c",247);
    if(fp1==NULL)
    {
        textcolor(LIGHTRED);
        gotoxy(32,10);
        printf("No Employee added yet!");
        return -1;
    }
    FILE *fp2=fopen("temp.bin","wb");
     if(fp2==NULL)
    {
        textcolor(LIGHTRED);
        gotoxy(32,10);
        printf("Sorry ! Cannot create temp file");
        return -1;
    }
    gotoxy(10,9);
    textcolor(YELLOW);
    printf("Enter Employee ID to delete the record:");
    textcolor(WHITE);
    scanf("%s",empid);
    User u;
    int found=0;
    while(fread(&u,sizeof(u),1,fp1)==1)
    {
        if(strcmp(u.userid,empid)!=0)
            fwrite(&u,sizeof(u),1,fp2);
        else
            found=1;
    }
    fclose(fp1);
    fclose(fp2);
    if(found==0)
     {
        remove("temp.bin");
     }
     else
     {
         result=remove("emp.bin");
         if(result!=0)
            return 2;
         result=rename("temp.bin","emp.bin");
         if(result!=0)
            return 2;
     }
     return found;
}
int empMenu()
{
    int choice,i;
    textcolor(LIGHTRED);
    gotoxy(32,2);
    printf("CAR RENTAL SYSYTEM");
    gotoxy(35,6);
    printf("EMPLOYEE MENU\n");
    for(i=1;i<=80;i++)
        printf("*");
    textcolor(YELLOW);
    gotoxy(32,8);
    printf("1.Rent A Car");
    gotoxy(32,9);
    printf("2.Booking Details");
    gotoxy(32,10);
    printf("3.Available Car Details");
    gotoxy(32,11);
    printf("4.Show All Car Details");
    gotoxy(32,12);
    printf("5.UpdateReturnCarDetails:");
    gotoxy(32,13);
    printf("6.Exit");
    gotoxy(32,16);
    printf("Enter choice:");
    scanf("%d",&choice);
    return choice;
}
int selectCarModel()
{
    char choice[20];
    FILE *fp=fopen("car.bin","rb");
    int flag;
    int rowno=9;
    Car c;
    gotoxy(34,rowno);
    while(fread(&c,sizeof(c),1,fp)==1)
    {
        if(c.car_count>0)
        {
            printf("%s. %s",c.car_id,c.car_name);
            gotoxy(34,++rowno);
        }
    }
    if(c.car_count==0)
    {
        fclose(fp);
       return -2;
    }

    gotoxy(34,rowno+2);
    printf("Enter your choice(0 to quit):");
    while(1)
    {
        flag=0;
        scanf("%s",&choice);
            if(choice==0)
            {
                fclose(fp);
                 return 0;
             }
            rewind(fp);
            while(fread(&c,sizeof(c),1,fp)==1)
            {
                if((strcmp(c.car_id,choice)==0)&&c.car_count>0)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==1)
            {
                fclose(fp);
                return flag;
            }
          gotoxy(37,rowno+4);
          textcolor(LIGHTRED);
          printf("Wrong ! Input");
          getch();
          gotoxy(35,rowno+4);
          printf("\t\t\t\t\t\t");
          gotoxy(52,rowno+2);
          printf("t\t\t\t\t");
          gotoxy(52,rowno+2);
          textcolor(WHITE);
        }
}
void showCarDetails()
{
    clrscr();
    FILE *fp=fopen("car.bin","rb");
    Car cr;
    int i;
    textcolor(YELLOW);
    gotoxy(32,1);
    printf("CAR RENTAL SYSTEM\n");
    for(i=0;i<80;i++)
        printf("%c",247);
    gotoxy(30,5);
    printf("* CAR DETAILS *");
    textcolor(LIGHTGREEN);
    gotoxy(1,7);
    for(i=0;i<80;i++)
        printf("%c",247);
    if(fp==NULL)
    {
        gotoxy(31,9);
        textcolor(LIGHTRED);
        printf("Sorry! NO car added yet!");
        getch();
        return;
    }
    gotoxy(1,8);
    printf("Car Id\t    Car Name\t        Capacity\t    Car Count \t\t  Price");
    gotoxy(1,9);
    for(i=0;i<80;i++)
        printf("%c",247);
    int row=10;
    textcolor(YELLOW);
    while(fread(&cr,sizeof(cr),1,fp)==1)
    {
        gotoxy(1,row);
        printf("%s",cr.car_id);

        gotoxy(13,row);
         printf("%s",cr.car_name);

        gotoxy(32,row);
         printf("%d",cr.capacity);

        gotoxy(53,row);
         printf("%d",cr.car_count);

        gotoxy(74,row);
         printf("%d",cr.price);

        row++;
    }
    fclose(fp);
    getch();
}
int deleteCarDetails()
{
     FILE *fp1=fopen("car.bin","rb");
    char carid[10];
    int i,result;
    textcolor(YELLOW);
    gotoxy(32,1);
    printf("CAR RENTAL SYSTEM\n");
    for(i=0;i<79;i++)
        printf("%c",247);
    gotoxy(29,5);
    printf("* DELETE CAR RECORD *");
    gotoxy(1,7);
    textcolor(LIGHTGREEN);
    for(i=0;i<79;i++)
        printf("%c",247);
    gotoxy(1,12);
    textcolor(LIGHTGREEN);
     for(i=0;i<79;i++)
        printf("%c",247);
    if(fp1==NULL)
    {
        textcolor(LIGHTRED);
        gotoxy(32,10);
        printf("No Car added yet!");
        return -1;
    }
    FILE *fp2=fopen("temp.bin","wb");
     if(fp2==NULL)
    {
        textcolor(LIGHTRED);
        gotoxy(32,10);
        printf("Sorry ! Cannot create temp file");
        return -1;
    }
    gotoxy(10,9);
    textcolor(YELLOW);
    printf("Enter Car ID to delete the record:");
    textcolor(WHITE);
    scanf("%s",carid);
    Car c;
    int found=0;
    while(fread(&c.car_id,sizeof(c),1,fp1)==1)
    {
        if(strcmp(c.car_id,carid)!=0)
            fwrite(&c,sizeof(c),1,fp2);
        else
            found=1;
    }
    fclose(fp1);
    fclose(fp2);
    if(found==0)
     {
        remove("temp.bin");
     }
     else
     {
         result=remove("car.bin");
         if(result!=0)
            return 2;
         result=rename("temp.bin","car.bin");
         if(result!=0)
            return 2;
     }
     return found;
}
int isValidDate(struct tm dt)
{
    time_t obj=time(0);
    struct tm *p=localtime(&obj);
    if(dt.tm_year>=2021&&dt.tm_year<=2022&&dt.tm_year>=1900+p->tm_year)
    {
        if(dt.tm_mon>=1&&dt.tm_mon<=12&&dt.tm_mon>=1+p->tm_mon)
        {
            if(dt.tm_mday>=p->tm_mday&&((dt.tm_mday>=1)&&(dt.tm_mday<=31))&&((dt.tm_mon==1)||(dt.tm_mon==3)||(dt.tm_mon==5)||(dt.tm_mon==7)||(dt.tm_mon==8)||(dt.tm_mon==10)||(dt.tm_mon==12)))
              return 1;
            else if(dt.tm_mday>=p->tm_mday&&(dt.tm_mday>=1&&dt.tm_mday<=30)&&(dt.tm_mon==4||dt.tm_mon==6||dt.tm_mon==9||dt.tm_mon==11))
                return 1;
            else if(dt.tm_mday>=p->tm_mday&&(dt.tm_mday>=1&&dt.tm_mday<=28)&&(dt.tm_mon==2))
            return 1;
             else if(dt.tm_mday>=p->tm_mday&&(dt.tm_mday>=1&&dt.tm_mday<=29)&&dt.tm_mon==2&&(dt.tm_year%400==0||dt.tm_year%4==0&&dt.tm_mon%100!=0))
                return 1;
        }
    }
    return 0;
}
void updateCarCount(int c_id)
{
    char cid[ ]={"CARID-"};
    strcat(cid,c_id);
    FILE *fp=fopen("car.bin","rb+" );
    if(fp==NULL)
    {
         printf("Sorry! File cannot be opened!");
         return;
    }
    Car C;
    while(fread(&C,sizeof(Car),1,fp)==1)
    {
        if(strcmp(C.car_id,cid)==0)
        {
               int x=C.car_count;
               x--;
               fseek(fp,-8,SEEK_CUR);
               fwrite(&x,sizeof(int),1,fp);
               break;
        }
    }
    fclose(fp);
}
void bookedCarDetails()
{
    clrscr();
    FILE *fp=fopen("customer.bin","rb");
    Customer_Car_Details CC;
    int i;
    textcolor(YELLOW);
    gotoxy(32,1);
    printf("CAR RENTAL SYSTEM");
    for(i=0;i<=79;i++)
          printf("%c",247);
    gotoxy(31,5);
    printf("* BOOKED CAR DETAILS *");
    gotoxy(1,7);
    textcolor(LIGHTGREEN);
     for(i=0;i<=79;i++)
          printf("%c",247);
    gotoxy(1,8);
    printf("MODEL\t    Cust Name\t   Pick Up\t   Drop \t\t  S_Date\t    E_Date");
    gotoxy(1,9);
    textcolor(LIGHTGREEN);
     for(i=0;i<=79;i++)
          printf("%c",247);
    int row=10;
    textcolor("YELLOW");
    while(fread(&CC,sizeof(Customer_Car_Details),1,fp)==1)
    {
        gotoxy(1,row);
        printf("%s",getCarName(CC.Car_id));

        gotoxy(13,row);
         printf("%s",CC.Cust_name);

        gotoxy(27,row);
         printf("%s",CC.pick);

        gotoxy(44,row);
         printf("%s",CC.drop);

        gotoxy(58,row);
         printf("%d-%d-%d",CC.sd.tm_mday,CC.sd.tm_mon,CC.sd.tm_year);

        gotoxy(70,row);
        printf("%%d-%d-%d",CC.ed.tm_mday,CC.ed.tm_mon,CC.ed.tm_year);

        row++;
    }
    fclose(fp);
    getch();
}
char* getCarName(int cid)
{
    char c_id[]={"CARID-"};
    strcat(c_id,cid);
    FILE *fp=fopen("car.bin","rb");
    if(fp==NULL)
    {
        printf("Sorry! File cannot be opened");
        return NULL;
    }
    static Car C;
    while(fread(&C,sizeof(C),1,fp)==1)
    {
        if(strcmp(C.car_id,c_id)==0)
        {
            break;
        }
    }
    fclose(fp);
    return C.car_name;
}
int rentCar()
    {

     Customer_Car_Details CC;
     char pick[30],drop[30];
     int c,i;
     textcolor(LIGHTRED);
     gotoxy(32,2);
     printf("CAR RENTAL SYSTEM");
     textcolor(LIGHTGREEN);
     gotoxy(35,6);
     printf("EMPLOYEE MENU\n");
     for(i=1;i<=80;i++)
        printf("*");
     textcolor(YELLOW);
     gotoxy(32,8);
     c=selectCarModel();
    if(c==0||c==-2)
    {
        return c;
    }
     CC.Car_id=c;
     clrscr();
     textcolor(LIGHTRED);
     gotoxy(32,2);
     printf("CAR RENTAL SYSTEM");
     textcolor(LIGHTGREEN);
     gotoxy(35,6);
     printf("EMPLOYEE MENU\n");
     for(i=1;i<=80;i++)
        printf("*");
     gotoxy(1,17);
     for(i=1;i<=80;i++)
        printf("*");
     textcolor(YELLOW);
     gotoxy(27,9);
     printf("Enter Customer Name:");
     fflush(stdin);
     textcolor(WHITE);
     fgets(CC.Cust_name,30,stdin);
     char *pos;
     pos=strchr(CC.Cust_name,'\n');
     *pos='\0';
     gotoxy(27,10);
     textcolor(WHITE);
     printf("Enter pickup point:");
     fflush(stdin);
     fgets(CC.pick,30,stdin);
     pos=strchr(CC.pick,'\n');
     *pos='\0';
     textcolor(YELLOW);
     gotoxy(27,11);
     printf("Enter drop point:");
     fflush(stdin);
     fgets(CC.drop,30,stdin);
     pos=strchr(CC.drop,'\n');
     *pos='\0';
     gotoxy(27,12);
     textcolor(YELLOW);
     printf("Enter start date(dd/mm/yyyy):");
     textcolor(WHITE);
     do
     {
          scanf("%d/%d/%d",&CC.sd.tm_mday,&CC.sd.tm_mon,&CC.sd.tm_year);
          int datevalid=isValidDate(CC.sd);
          if(datevalid==1)
             break;
          gotoxy(27,18);
          textcolor(LIGHTRED);
          printf("Wrong Date");
          getch();
          gotoxy(27,18);
          printf("\t\t\t\t");
          gotoxy(56,12);
          printf("\t\t\t\t");
          gotoxy(56,12);
          textcolor(WHITE);

     }while(1);
    gotoxy(27,13);
     textcolor(YELLOW);
     printf("Enter end date(dd/mm/yyyy):");
     textcolor(WHITE);
     do
     {
          scanf("%d/%d/%d",&CC.ed.tm_mday,&CC.ed.tm_mon,&CC.ed.tm_year);
          int datevalid=isValidDate(CC.ed);
          if(datevalid==1)
             break;
          gotoxy(27,18);
          textcolor(LIGHTRED);
          printf("Wrong Date");
          getch();
          gotoxy(27,18);
          printf("\t\t\t\t");
          gotoxy(54,13);
          printf("\t\t\t");
          gotoxy(54,13);
          textcolor(WHITE);
     }while(1);


     FILE *fp;
     fp=fopen("customer.bin","ab");
     if(fp==NULL)
     {
         gotoxy(27,18);
         printf("Sorry file cannot be opened!");
         return -1;
     }
     fwrite(&CC,sizeof(Customer_Car_Details),1,fp);
     gotoxy(27,18);
     textcolor(WHITE);
     printf("Booking done for Car %d",CC.Car_id);
     getch();
     fclose(fp);
     updateCarCount(CC.Car_id);
     bookedCarDetails();
     return 1;
    }
void availCarDetails()
{

    FILE*fp=fopen("car.bin","rb");
    Car C;
    int i;
    textcolor(YELLOW);
    gotoxy(32,1);
    textcolor(GREEN);
    printf("CAR RENTAL SYSTEM\n");
    for(i=1;i<=80;i++)
        printf("%c",247);
    gotoxy(32,5);
    textcolor(YELLOW);
    printf("* AVAILABLE CAR DETAILS *");
    gotoxy(1,7);
    textcolor(GREEN);
     for(i=1;i<=80;i++)
        printf("%c",247);
 ;
    if(fp==NULL)
        {
               gotoxy(32,8);
               textcolor(LIGHTRED);
               printf("Sorry! File Cannot be opened");
               getch();
               return ;
        }
       gotoxy(1,8);
       printf("CAR ID\t   MODEL\t\t   CAPACITY\tAVAILABLE\tPRICE/DAY");
       gotoxy(1,9);
       for(i=1;i<=80;i++)
           printf("%c",247);
           int row=0;
           textcolor(YELLOW);
           while(fread(&C,sizeof(C),1,fp)==1)
           {
               if(C.car_count>0)
               {
                   gotoxy(2,row);
                   printf("%s",C.car_id);
                   gotoxy(13,row);
                   printf("%s",C.car_name);
                   gotoxy(35,row);
                   printf("%d",C.capacity);
                   gotoxy(50,row);
                   printf("%d",C.car_count);
                   gotoxy(68,row);
                   printf("%d",C.price);
                   row++;
               }
           }
        fclose(fp);
}
void updateReturnCarDetails()
{
     char cid[ 20];
     int i;
    textcolor(YELLOW);
    gotoxy(32,1);
    printf("CAR RENTAL SYSTEM");
    for(i=0;i<=79;i++)
          printf("%c",247);
    gotoxy(27,5);
    printf("* UPDATE REYURN CAR DETAILS *");
    gotoxy(1,7);
    textcolor(LIGHTGREEN);
     for(i=0;i<=79;i++)
          printf("%c",247);
    gotoxy(27,9);
    textcolor(YELLOW);
    printf("Enter Car id:");
     scanf("%s",&cid);
    FILE *fp=fopen("car.bin","rb+" );
    if(fp==NULL)
    {
         printf("Sorry! File cannot be opened!");
         return;
    }
    Car C;
    int r=0;
    while(fread(&C,sizeof(Car),1,fp)==1)
    {
        if(strcmp(C.car_id,cid)==0)
        {
               int x=C.car_count;
               x++;
               fseek(fp,-8,SEEK_CUR);
               fwrite(&x,sizeof(int),1,fp);
               r=1;
               break;
        }
    }
    if(r==1)
        {
             textcolor(YELLOW);
            gotoxy(27,12);
            printf("Details Udated");
            getch();
        }
        else
       {
            textcolor(RED);
            gotoxy(27,12);
            printf("Unsucessul Details Udated");
           getch();
        }
    fclose(fp);
    return ;
}
