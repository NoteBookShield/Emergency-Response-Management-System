#include <stdio.h>
#include <string.h>

#define MAX 100
#define UNIT 5
int n;

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
char *getType(int type)
{
    switch (type)
    {
    case 1:
        return "Medical";
    case 2:
        return "Fire";
    case 3:
        return "Accident";
    case 4:
        return "Crime";
    case 5:
        return "Disaster";
    default:
        return "Unknown";
    }
}
char *getStatus(int status)
{
    switch (status)
    {
    case 1:
        return "Pending";
    case 2:
        return "Assigned";
    case 3:
        return "On The Way";
    case 4:
        return "Completed";
    case 5:
        return "Cancelled";
    default:
        return "Unknown";
    }
}
void saveData()
{
    FILE *fp;

    fp = fopen("erms.dat", "wb");

    if (fp == NULL)
    {
        printf("Unable to save data!\n");
        return;
    }

    fwrite(&count, sizeof(int), 1, fp);

    fwrite(e, sizeof(struct Emergency), count, fp);

    fclose(fp);
}
void loadData()
{
    FILE *fp;

    fp = fopen("erms.dat", "rb");

    if (fp == NULL)
    {
        return;
    }

    if (fread(&count, sizeof(int), 1, fp) != 1)
    {
        count = 0;
        fclose(fp);
        return;
    }

    if (count < 0 || count > MAX)
    {
        count = 0;
        fclose(fp);
        return;
    }

    if (fread(e, sizeof(struct Emergency),
              count, fp) != (size_t)count)
    {
        count = 0;
        fclose(fp);
        return;
    }

    fclose(fp);

    nextID = 101;

    for (int i = 0; i < count; i++)
    {
        if (e[i].id >= nextID)
        {
            nextID = e[i].id + 1;
        }
    }
}
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
    e[count].status = 1;

    printf("\nEmergency reported successfully!\n");
    printf("Your Emergency ID: %d\n", e[count].id);

    count++;
    nextID++;
    saveData();
}
void publicReports()
{

    printf("\n========== PUBLIC EMERGENCY REPORTS ==========\n");

    if (count == 0)
    {
        printf("No emergency reports available!\n");
        return;
    }

    printf("%s \t%-25s %-10s %s\n",
           "ID", "Location", "Type", "Status");

    for (int i = 0; i < count; i++)
    {
        printf("%d \t%-25.23s %-10s %s\n",
               e[i].id,
               e[i].location,
               getType(e[i].type),
               getStatus(e[i].status));
    }

    printf("\nTotal Reports: %d\n", count);
}

int main()
{
    loadData();
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

        case 2:
            publicReports();
            break;

            // case 3:
            //     adminLogin();
            //     break;

        case 4:
            printf("\nThank you for using ERMS!\n");
            printf("Your Safety Is Our Priority.\n");
            break;
        }

    } while (choice != 4);

    return 0;
}
