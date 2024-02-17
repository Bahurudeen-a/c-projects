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
account_no:
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
    scanf("%s", &add.name);
    printf("Enter the date of birthday(mm/dd/year): ");
    scanf("%d/%d/%d", &add.dob.month, &add.dob.day, &add.dob.year);
    printf("\nEnter the Age: ");
    scanf("%d", &add.age);
    printf("\nEnter the address: ");
    scanf("%s", &add.address);
    printf("\nEnter the citizenship number: ");
    scanf("%s", &add.citizenship);
    printf("\nEnter the phone number: ");
    scanf("%lf", &add.phone);
    printf("\nEnter the amount to deposite: ");
    scanf("%f", &add.amt);
    printf("\nType of Account: \n\t#Saving\n\t#Current\n\t#Fixed1(for 1 year)\n\t#Fixed2(for 2 years)\n\t#Fixed(for 3 year)\n\nEnter your choice: ");
    scanf("%s", add.acc_type);
    fprintf(ptr, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amt, add.deposite.month, add.deposite.day, add.deposite.year);
    fclose(ptr);
    printf("\nAccount Created successfully!");
add_invalid:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d", &main_exit);
    system("cls");
    if (main_exit == 1)
    {
        menu();
    }
    else if (main_exit == 0)
    {
        close();
    }
    else
    {
        printf("\nInvalid\n");
        goto add_invalid;
    }
}
void view_list()
{
    FILE *view;
    view = fopen("record.dat", "r");
    int test = 0;
    system("cls");
    printf("\nACC_NO\tNAME\t\tADDRESS\t\tPHONE\n");
    while (fscanf(view, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, add.acc_type, &add.amt, &add.deposite.month, &add.deposite.day, &add.deposite.year) != EOF)
    {
        printf("\n%6d\t%10s\t\t\t%10s\t\t%0lf", add.acc_no, add.name, add.address, add.phone);
        test++;
    }
    fclose(view);
    if (test == 0)
    {
        system("cls");
        printf("\nNo RECORDS!!\n");
    }
view_list_invalid:
    printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d", &main_exit);
    system("cls");
    if (main_exit == 1)
    {
        menu();
    }
    else if (main_exit == 0)
    {
        close();
    }
    else
    {
        printf("\nInvalid\n");
        goto view_list_invalid;
    }
}

void edit(void)
{
    int choice, test = 0;
    FILE *old, *newrec;
    old = fopen("record.dat", "r");
    newrec = fopen("new.dat", "w");

    printf("\nEnter the account no of the customer whose info you want to change: ");
    scanf("%d", &upd.acc_no);
    while (fscanf(old, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, add.acc_type, &add.amt, &add.deposite.year) != EOF)
    {
        if (add.acc_no == upd.acc_no)
        {
            test = 1;
            printf("\nWhich information do you want to change: \n1.Address\n2.Phone\n\nEnter your choice(1 for address and 2 for phone):");
            scanf("%d", &choice);
            system("cls");
            if (choice == 1)
            {
                printf("Enter new Address: ");
                scanf("%s", upd.address);
                fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, upd.address, add.citizenship, add.phone, add.acc_type, add.amt, add.deposite.month, add.deposite.day, add.deposite.year);
                system("cls");
                printf("Changes Saved");
            }
            else if (choice == 2)
            {
                printf("Enter the New Phone Number");
                scanf("%lf", &upd.phone);
                fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, upd.phone, add.acc_type, add.amt, add.deposite.month, add.deposite.day, add.deposite.year);
                system("cls");
                printf("Changes Saved");
            }
            else
            {
                fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d,%d", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amt, add.deposite.month, add.deposite.day, add.deposite.year);
            }
        }
        fclose(old);
        fclose(newrec);
        remove("record.dat");
        rename("new.dat", "record.dat");
    }

    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat", "record.dat");

    if (test != 1)
    {
        system("cls");
        printf("\nRecord not found\a\a\a");
    edit_invalid:
        printf("\nEnter 0 to try again, 1 to return main menu and 2 to exit: ");
        scanf("%d", &main_exit);
        system("cls");
        if (main_exit == 1)
        {
            menu();
        }
        else if (main_exit == 2)
        {
            close();
        }
        else if (main_exit == 0)
        {
            edit();
        }
        else
        {
            printf("\nInvalid\a");
            goto edit_invalid;
        }
    }
    else
    {
        printf("\n\nEnter 1 to go to the main menu and 0 to exit: ");
        scanf("%d", &main_exit);
        system("cls");
        if (main_exit == 1)
        {
            menu();
        }
        else
        {
            close();
        }
    }
}

void transact(void)
{
    int choice, test = 0;
    FILE *old, *newrec;
    old = fopen("record.dat", "r");
    newrec = fopen("new.dat", "w");
    printf("Enter the account no of the customer: ");
    scanf("%d", &transaction.acc_no);
    while (fscanf(old, "%d %d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, add.acc_type, &add.amt, &add.deposite.month, &add.deposite.day, &add.deposite.year) != EOF)
    {
        if (add.acc_no == transaction.acc_no)
        {
            test = 1;
            if (strcmp(add.acc_type, "fixed1") == 0 || strcmp(add.acc_type, "fixed2") == 0 || strcmp(add.acc_type, "fixed3" == 0))
            {
                printf("\a\a\a\n\nYOU CANNOT DEPOSITE OR WITHDRAW CASH IN FIXED ACCOUNT!!!!");
                forDelay(1000000000);
                system("cls");
                menu();
            }
            printf("\n\nDo you want to \n1>Deposit\n2.WithDraw\n\nEnter your choice:");
            scanf("%d", &choice);
            if (choice == 1)
            {
                printf("Enter the amount you want to deposite:₹");
                scanf("%f", &transaction.amt);
                add.amt += transaction.amt;
                fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amt, add.deposite.month, add.deposite.day, add.deposite.year);
                printf("\n\nDeposited succesfully!");
            }
            else
            {
                printf("Enter the amount you want to withdraw:₹");
                scanf("%f", &transaction.amt);
                add.amt -= transaction.amt;
                fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amt, add.deposite.month, add.deposite.day, add.deposite.year);
                printf("Withdraw Successful!");
            }
        }
        else
        {
            fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amt, add.deposite.month, add.deposite.day, add.deposite.year);
        }
    }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat", "record.dat");
    if (test != 1)
    {
        printf("\n\nRecord Not Found!!\n");
    transact_invalid:
        printf("\n\nEnter 0 to try again, 1 to return to main menu and 2 to exit");
        scanf("%d", &main_exit);
        system("cls");
        if (main_exit == 0)
        {
            transact();
        }
        else if (main_exit == 1)
        {
            menu();
        }
        else if (main_exit == 2)
        {
            close();
        }
        else
        {
            printf("Invalid!!!");
            goto transact_invalid;
        }
    }
    else
    {
        printf("\nEnter 1 to go to the main_menu and 0 to exit: ");
        scanf("%d", &main_exit);
        system("cls");
        if (main_exit == 1)
        {
            menu();
        }
        else
        {
            close();
        }
    }
}

void erase(void)
{
    FILE *old, *newrec;
    int test = 0;
    old = fopen("record.dat", "r");
    newrec = fopen("new.dat", "w");
    printf("Enter the account no. of the customer you want delete: ");
    scanf("%d", &rem.acc_no);
    while (fscanf(old, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, add.acc_type, &add.amt, &add.deposite.month, &add.deposite.day, &add.deposite.year) != EOF)
    {
        if (add.acc_no != rem.acc_no)
        {
            fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amt, add.deposite.month, add.deposite.day, add.deposite.year);
        }
        else
        {
            test++;
            printf("\nRecord deleted succesfully\n");
        }
    }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat", "record.dat");
    if (test == 0)
    {
        printf("\nRecord not found\a\a\a\n");
    erase_invalid:
        printf("\nEnter 0 to try again, 1 to return to main menu and 2 to exit:");
        scanf("%d", &main_exit);
        if (main_exit == 1)
        {
            menu();
        }
        else if (main_exit == 2)
        {
            close();
        }
        else if (main_exit == 0)
        {
            erase();
        }
        else
        {
            printf("\nInvalid\a");
            goto erase_invalid;
        }
    }
    else
    {
        printf("\nEnter 1 to go to the main menu and 0 to exit: ");
        scanf("%d", &main_exit);
        system("cls");
        if (main_exit == 1)
        {
            menu();
        }
        else
        {
            close();
        }
    }
}