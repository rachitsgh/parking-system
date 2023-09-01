#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUS_SLOT_CAPACITY 5
#define CAR_SLOT_CAPACITY 5
#define BIKE_SLOT_CAPACITY 20
#define AUTO_SLOT_CAPACITY 15

#define BUS_FEE 200
#define CAR_FEE 150
#define BIKE_FEE 50
#define AUTO_FEE 100

struct Customer {
    char name[20];
    int vehicleNumber;
    char date[13];
};

int earnings = 0;
int slots[4] = {BUS_SLOT_CAPACITY, CAR_SLOT_CAPACITY, BIKE_SLOT_CAPACITY, AUTO_SLOT_CAPACITY};
int parked[4] = {0};

struct Customer data[100];

void receipt(const struct Customer *customer) {
    printf("\nReceipt:\n");
    printf("***************************************\n");
    printf("Name: %s\n", customer->name);
    printf("Vehicle Number: %d\n", customer->vehicleNumber);
    printf("Date: %s\n", customer->date);
    printf("***************************************\n");
}

void park(int type) {
    struct Customer current;

    printf("Enter name: ");
    scanf("%s", current.name);

    printf("Enter vehicle number: ");
    scanf("%d", &current.vehicleNumber);

    printf("Enter date(DD/MM/YYYY): ");
    scanf("%s", current.date);

    parked[type]++;
    receipt(&current);
    data[parked[type] - 1] = current;
    earnings += (type == 0) ? BUS_FEE : (type == 1) ? CAR_FEE : (type == 2) ? BIKE_FEE : AUTO_FEE;
}

void checkVehicle() {
    printf("Enter your name: ");
    char name[20];
    scanf("%s", name);

    printf("Enter vehicle number: ");
    int vehicleNumber;
    scanf("%d", &vehicleNumber);

    for (int i = 0; i < 100; i++) {
        if (strcmp(data[i].name, name) == 0 && data[i].vehicleNumber == vehicleNumber) {
            printf("Your vehicle is parked here.\n");
            return;
        }
    }
    printf("Your vehicle is not parked here.\n");
}

int main() {
    printf("Welcome to parking stand\n");

    while (1) {
        printf("\nOptions:\n");
        printf("1. Park a vehicle\n");
        printf("2. Check for a vehicle\n");
        printf("3. Show today's insight\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Select vehicle type: \n");
                printf("1.bus        200inr \t");
                printf("2.car        150inr\n");
                printf("3.auto       100inr\t");
                printf("4.bike       50inr\n");
                int type;
                scanf("%d", &type);

                if (type >= 1 && type <= 4) {
                    if (parked[type - 1] < slots[type - 1]) {
                        park(type - 1);
                    } else {
                        printf("Sorry! Parking slot is not available.\n");
                    }
                } else {
                    printf("Invalid vehicle type.\n");
                }
                break;
                checkVehicle();
                break;

            case 3:
                printf("\nInsight:\n");
                printf("Total earnings: %d\n", earnings);
                for (int i = 0; i < 4; i++) {
                    printf("Total %s parked: %d\n",
                           i == 0 ? "Bus" : (i == 1 ? "Car" : (i == 2 ? "Bike" : "Auto")),
                           parked[i]);
                }
                break;

            case 4:
                printf("Thank you for using our parking stand.\n");
                exit(0);

            default:
                printf("Invalid choice. Please enter a valid option.\n");
                break;
        }
    }

    return 0;
}
