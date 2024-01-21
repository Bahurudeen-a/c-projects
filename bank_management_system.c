#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int i, j;
int main_exit;
void menu();
struct date
{
    int month, day, year;
};
struct
{
    char name[60];
    int acc_no, age;
    char address[60];
    char citizenship[15];
    double phone;
    char acc_type[10];
    float amt;
    struct date dob;
    struct date deposite;
    struct date withdraw;
} add, upd, check, rem, transaction;
float intrest(float t, float amount, int rate)
{
    float SI;
    SI = (rate * t * amount) / 100.0;
    return SI;
}
void forDelay(int j)
{
    int i, k;
    for (i = 0; i < j; i++)
    {
        k = i;
    }
}
void new_acc()
{
    int choice;
    FILE *ptr;
    ptr = fopen("record.dat", "a+");
    int account_no;
    system("cls");
    printf("\t\t\t\xB2\xB2\xB2 ADD RECORD \xB2\xB2\xB2\xB2");
    printf("\n\n\nEnter Today's Date(mm/dd/yyyy): ");
    scanf("%d/%d/%d", add.deposite.year);
    printf("\nEnter the Account name");
    scanf("%d", &check.acc_no);
    while (fscanf(ptr, "%d %s %d %d %d %d %s %s %lf %s %f %d/%d/%d\n", &add.acc_no, add.name, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, add.acc_type, &add.amt, &add.deposite.day, &add.deposite.year) != EOF)
    {
        if (check.acc_no == add.acc_no)
        {
            printf("Account no. already in use!");
            forDelay(1000000000);
            goto account_no;
        }
    }
    add.acc_no = check.acc_no;
    printf("\nEnter the name: ");
    scanf("%s",&add.name);
    printf("Enter the date of birthday(mm/dd/year): ");
    scanf("%d/%d/%d",&add.dob.month,&add.dob.day,&add.dob.year);
    printf("\nEnter the Age: ");
    scanf("%d",&add.age);
    printf("\nEnter the address: ");
    scanf("%s",&add.address);
}