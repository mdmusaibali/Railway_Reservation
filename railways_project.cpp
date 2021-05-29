#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
FILE *fp;
char date[20];
void delete1();
void booking();
int indexOf(FILE *fp, const char *name, int *line, int *col);
int main()
{
    char a[50], passwd[50], str[1000], *a1, *passwd1, *a2, *passwd2, a3[50], passwd3[50], *p, name[50];
    cout<<"Enter date: ";
    gets(date);
    a1 = "musaib";
    passwd1 = "musaib1";
    a2 = "collector";
    passwd2 = "collector1";

    int ch, ch1, ch3;
LOOP:
    do
    {
        cout << "----------------------------------------------------------------------\n";
        cout << "|                   WELCOME TO INDIAN RAILWAYS                       |\n";
        cout << "|     OO O o o o...      ______________________ _________________    |\n";
        cout << "|    O     ____          |                    | |               |    |\n";
        cout << "|   ][_n_i_| (   ooo___  |                    | |               |    |\n";
        cout << "|  (__________|_[______]_|____________________|_|_______________|    |\n";
        cout << "|    0--0--0      0  0      0       0     0        0        0        |\n";
        cout << "|Select your category                                                |\n";
        cout << "|1.booking clerk                                                     |\n";
        cout << "|2.Ticket Collector                                                  |\n";
        cout << "|3.Exit                                                              |\n";
        cout << "----------------------------------------------------------------------\n";
        cout << "Choice: ";
        cin>>ch;
        switch (ch)
        {
        case 1:
        LOOP1:
            cout << "\nFor authentication purpose you are required to enter your user id and password\n";
            cout << "User id: ";
            cin >> a;
            cout << "\nPassword: ";
            cin >> passwd;
            if ((strcmp(a, a1) == 0) && (strcmp(passwd, passwd1) == 0))
            {
                cout << "\n\nWELCOME BACK " << a1;
                do
                {

                    cout << "\nWhat would you like to do here?\n\n";
                    cout << "1.Book ticket\n2.Delete all the records of booking\n3.Back\n";
                    cout << "Choice: ";
                    cin >> ch1;
                    switch (ch1)
                    {
                    case 1:
                        booking();
                        break;
                    case 3:
                        goto LOOP;
                        break;
                    case 2:
                        delete1();
                        break;
                    default:
                        cout << "Invalid choice";

                        break;
                    }
                } while (ch != 2);
            }
            else
            {
                cout << "\nInvalid user id or password!";
                cout << "\nTry Again!!";
                goto LOOP1;
            }
            break;
        case 3:
            exit(0);
            break;
        case 2:
        LOOP4:
            cout << "\nFor authentication purpose you are required to enter your user id and password\n";
            cout << "User id: ";
            cin >> a3;
            cout << "\nPassword: ";
            cin >> passwd3;
            if ((strcmp(a2, a3) == 0) && (strcmp(passwd2, passwd3) == 0))
            {
                cout << "\nWELCOME BACK " << a3 << "\n";
                do
                {
                LOOP3:
                    cout << "\nWhat would you like to do?\n";
                    cout << "\n1.Check Reservations\n2.Back\n";
                    cout<<"Enter your choice: ";
                    cin >> ch3;
                    switch (ch3)
                    {
                    case 1:
                        fseek(stdin, 0, SEEK_END);
                        fp = fopen(date, "r");
                        cout << "\nEnter the mobile number of passenger to check reservation: ";
                        cin >> name;
                        int line, col;
                        indexOf(fp, name, &line, &col);
                        if (line != -1)
                            printf("%s has a reservation", name);
                        else
                            printf("%s does not exists.", name);
                        goto LOOP3;
                        break;
                    case 2:
                        goto LOOP;
                        break;
                    default:
                        cout << "Invalid input\n";
                        goto LOOP3;
                        break;
                    }
                } while (ch != 2);
            }
            else
            {
                cout << "\nInvalid user id or password!";
                cout << "\nTry Again!!";
                goto LOOP4;
            }
            break;

        default:
            cout << "Invalid choice";
        }

    } while (ch != 3);
}
void booking()
{
    fseek(stdin, 0, SEEK_END);
    char name[40];
    char number[20];
    char gender;
    cout << "Enter the name of passanger: ";
    fgets(name, 40, stdin);
    cout << "Gender(M/F): ";
    cin >> gender;
    cout << "Enter you mobile number: ";
    cin >> number;
    fp = fopen(date, "a");
    fprintf(fp, "Name: %s\nGender: %c\nMobile Number: %s\n------------------------------\n", name, gender, number);
    fclose(fp);
}

void delete1()
{

    remove(date);
}
int indexOf(FILE *fp, const char *name, int *line, int *col)
{
    char str[1000];
    char *pos;
    *line = -1;
    *col = -1;
    while ((fgets(str, 1000, fp)) != NULL)
    {
        *line += 1;
        pos = strstr(str, name);
        if (pos != NULL)
        {
            *col = (pos - str);
            break;
        }
    }
    if (*col == -1)
        *line = -1;

    return *col;
}
