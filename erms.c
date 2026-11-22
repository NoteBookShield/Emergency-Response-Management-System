#include <stdio.h>
#include <string.h>

#define MAX 100
#define UNIT 5
int n;

/* Emergency structure */
struct Emergency
{
    int id;
    char name[50];
    char phone[20];
    char location[50];
    int type;
    char description[100];
    int status;
    int assigned[UNIT];
};

/* Unit structure */
struct Unit
{
    int id;
    char name[30];
    int total;
};

/* Global variables */
struct Emergency e[MAX];

struct Unit u[UNIT] = {
    {101, "Ambulance", 100},
    {102, "Fire Service", 100},
    {103, "Police", 100},
    {104, "Rescue Team", 100},
    {105, "Disaster Team", 100}};
int count = 0;
int nextID = 101;

void reportEmergency()
{
    
    if (count >= MAX)
    {
        printf("Maximum emergency reports reached!\n");
        return;
    }
    printf("\n========== REPORT EMERGENCY ==========\n");
    e[count].id = nextID;
    printf("Enter Name: ");
    scanf(" %[^\n]", e[count].name);

    printf("Enter Phone: ");
    scanf(" %[^\n]", e[count].phone);

    printf("Enter Location: ");
    scanf(" %[^\n]", e[count].location);
    printf("\nSelect Emergency Type:\n");
    printf("1. Medical\n");
    printf("2. Fire\n");
    printf("3. Accident\n");
    printf("4. Crime\n");
    printf("5. Disaster\n");

    printf("Select Emergency Type: ");
    scanf("%d", &e[count].type);

    if (e[count].type == -1)
    {
        return;
    }

    printf("Enter Description: ");
    scanf(" %[^\n]", e[count].description);

   

    printf("\nEmergency reported successfully!\n");
    printf("Your Emergency ID: %d\n", e[count].id);

    count++;
    nextID++;
}
int main()
{
    int choice = 0;
    do
    {
        printf("\n========================================\n");
        printf("  EMERGENCY RESPONSE MANAGEMENT SYSTEM\n");
        printf("                 ERMS\n");
        printf("========================================\n");

        printf("1. Report an Emergency\n");
        printf("2. View Emergency Reports\n");
        printf("3. Admin Login\n");
        printf("4. Exit\n");

        printf("----------------------------------------\n");

        printf("Enter Your Choice: ");
        scanf("%d", &choice);
        if (choice < 1 || choice > 4)
        {
            printf("\nInvalid choice! Please enter a number from 1 to 4.\n");
            continue;
        }

        if (choice == -1)
        {
            printf("\nInput ended. Exiting ERMS.\n");
            break;
        }

        switch (choice)
        {

        case 1:
            reportEmergency();
            break;

            // case 2:
            //     publicReports();
            //     break;

            // case 3:
            //     adminLogin();
            //     break;

        case 4:
            printf("\nThank you for using ERMS!\n");
            printf("Your Safety Is Our Priority.\n");
            break;
        }

    } while (choice != 4);

    return 1;
}
