#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include"conio2.h"
#include"car.h"
int main()
{
    int i,type,k,choice;
    User *usr;
    int result;
    gotoxy(25,10);
    textcolor(YELLOW);
    printf("WELCOME TO CAR RENTAL SYSTEM");
    gotoxy(20,13);
    textcolor(GREEN);
    printf("* RENT A CAR  AND GO WHEREVER YOU NEED *");
    getch();
    textcolor(YELLOW);
    addAdmin();
    while(1)
    {
        clrscr();
        textcolor(RED);
        gotoxy(32,2);
        printf("CAR RENTAL SYSTEM");
        gotoxy(1,8);
        for(i=1;i<=80;i++)
        {
            textcolor(YELLOW);
            printf("*");
        }
        gotoxy(1,18);
        for(i=1;i<=80;i++)
        {
            textcolor(YELLOW);
            printf("*");
        }
             gotoxy(32,10);
             textcolor(RED);
             printf("1.ADMIN");
             gotoxy(32,12);
             textcolor(RED);
             printf("2.EMPLOYEE");
             gotoxy(32,14);
             textcolor(RED);
             printf("3.QUIT");
             gotoxy(32,16);
             textcolor(WHITE);
             printf("Select your role:");
             do
             {
                 scanf("%d",&type);
                 if(type==1)
                {
                    do
                    {
                           usr=getInput();
                           if(usr==NULL)
                             break;
                            else
                            {
                                  k=checkUserExist(*usr,"admin");
                             }
                    }while(k==0);

                    if(k== (-1))
                         break;
                         if(k==(1))
                         {
                             gotoxy(1,20);
                             textcolor(WHITE);
                             printf("Press any key to continue");
                             getch();
                              while(1)
                              {
                                   clrscr();
                                   choice=adminMenu();
                                    if(choice==7)
                                    {
                                        break;
                                    }

                                    switch(choice)
                                    {
                                   case 1:
                                                   clrscr();
                                                   addEmployee();
                                                   break;
                                   case 2:
                                                   clrscr();
                                                   viewEmployee();
                                                   break;
                                   case 3:
                                                   clrscr();
                                                   addCarDetails();
                                                   break;
                                   case 4:
                                                    clrscr();
                                                    showCarDetails();
                                                   break;
                                   case 5:
                                                   clrscr();
                                                   result= deleteEmp();
                                                   gotoxy(15,14);
                                                   if(result==0)
                                                   {
                                                       textcolor(LIGHTRED);
                                                       printf("Sorry! No record found of the given emp found");
                                                   }
                                                   else if(result==-1)
                                                   {
                                                       textcolor(LIGHTGREEN);
                                                       printf("Record deleted sucessfully");
                                                   }
                                                   else if(result==2)
                                                   {
                                                       textcolor(LIGHTRED);
                                                       printf("Error in deletion");
                                                   }
                                                   textcolor(WHITE);
                                                   printf("\nPress key to go back to the main Menu");
                                                    getch();
                                                   break;
                                   case 6:
                                                   clrscr();
                                                    result=deleteCarDetails();
                                                    if(result==0)
                                                   {
                                                       textcolor(LIGHTRED);
                                                       printf("Sorry! No record found of the given car found");
                                                   }
                                                   else if(result==-1)
                                                   {
                                                       textcolor(LIGHTGREEN);
                                                       printf("Record deleted sucessfully");
                                                   }
                                                   else if(result==2)
                                                   {
                                                       textcolor(LIGHTRED);
                                                       printf("Error in deletion");
                                                   }
                                                   textcolor(WHITE);
                                                   printf("\nPress key to go back to the main Menu");
                                                    getch();
                                                     break;
                                   default :
                                          clrscr();
                                         printf("invalid Input!");
                                         getch();

                                    }
                              }
                         }
             }
             else if(type==2)
             {
                  do
                  {
                      usr=getInput();
                      if(usr==NULL)
                        break;
                      else
                      {
                          k=checkUserExist(*usr,"emp");
                      }
                  }while(k==0);
                  if(k== -1)
                    break;
                  if(k==1)
                  {
                      gotoxy(1,20);
                      textcolor(WHITE);
                      printf("Press any key to continue");
                      getch();
                      while(1)
                      {
                          clrscr();
                          choice=empMenu();
                          if(choice==6)
                            break;
                          switch(choice)
                          {
                          case 1:
                                         clrscr();
                                         int rentres;
                                         rentres=rentCar();
                                         if(rentres== -2)
                                         {
                                             textcolor(LIGHTRED);
                                             gotoxy(35,9);
                                             printf("Sorry! All car Booked.Try again later");
                                             getch();
                                         }
                                         else if(rentres==0)
                                         {
                                             textcolor(LIGHTRED);
                                             gotoxy(28,18);
                                             printf("You did not choose.Any car");
                                             getch();
                                         }
                                         break;
                          case 2:
                                          clrscr();
                                          bookedCarDetails();
                                          break;
                          case 3:
                                          clrscr();
                                          availCarDetails();
                                          break;
                          case 4:
                                          clrscr();
                                          showCarDetails();
                                          break;
                          case 5:
                                          clrscr();
                                         updateReturnCarDetails();
                                          break;
                          default:
                                          clrscr();
                                           textcolor(RED);
                                              gotoxy(27,12);
                                          printf("invalid Input!");
                                          getch();
                                          break;
                        }
                  }
                }
             }
             else if(type==3)
             {
                 clrscr();
                 gotoxy(30,13);
                 textcolor(GREEN);
                 printf("THANKS! FOR USING OUR APP");
                 getch();
                 exit(0);
             }
             else
             {
                 gotoxy(30,20);
                 textcolor(RED);
                 printf("Invalid User Input !");
                 getch();
                 gotoxy(30,20);
                 printf("\t\t\t\t");
                 gotoxy(49,16);
                 printf("\t\t\t");
                 textcolor(WHITE);
                 gotoxy(49,16);
             }
        }while(1);
        getch();
    }
    return 0;
}
