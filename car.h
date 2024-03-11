#ifndef CAR_H_INCLUDED
#define CAR_H_INCLUDED
#include<time.h>
struct User
{
    char userid[20];
    char pwd[20];
    char name[20];
};
struct addCarDetails
{
    char car_id[10];
    char car_name[38];
    int capacity;
    int car_count;
    int price;
};
struct Customer_Car_Details
{
    int Car_id;
    char Cust_name[30];
    char pick[30];
    char drop[30];

    struct tm sd;
    struct tm ed;
};

typedef struct User User;
typedef struct addCarDetails Car;
typedef struct Customer_Car_Details Customer_Car_Details;

void addAdmin();
User * getInput();
int checkUserExist(User,char*);
int adminMenu();
void addEmployee();
void viewEmployee();
void addCarDetails();
int deleteEmp();
int deleteCarModel();
void showCarDetails();
int deleteCarDetails();
int empMenu();
int selectCarModel();
int isValidDate(struct tm);
void updateCarCount(int);
void bookedCarDetails();
char* getCarName(int);
int rentCar();
void availCarDetails();
void updateReturnCarDetails();
#endif // CAR_H_INCLUDED
