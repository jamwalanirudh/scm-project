#include <stdio.h>
#include <stdlib.h>

#define CUSTOMERS_MAX 100

typedef struct {
    int id;
    char name[50];
    int prev_reading;
    int curr_reading;
    int units_consumed;
    float bill_amount;
} customer;

customer customers[CUSTOMERS_MAX]; // array to store all customers
int num_customers = 0; // current number of customers

void add_customer() {
    if (num_customers >= CUSTOMERS_MAX) {
        printf("Error: Maximum number of customers reached\n");
        return;
    }
    
    customer c;
    c.id = num_customers + 1; // assign unique ID to customer
    printf("Enter customer name: ");
    scanf("%s", c.name);
    printf("Enter previous reading (in kWh): ");
    scanf("%d", &c.prev_reading);
    printf("Enter current reading (in kWh): ");
    scanf("%d", &c.curr_reading);
    
    c.units_consumed = c.curr_reading - c.prev_reading;
    
    if (c.units_consumed < 0) {
        printf("Error: Invalid readings (previous reading must be less than current reading)\n");
        return;
    }
    
    if (c.units_consumed <= 100) {
        c.bill_amount = c.units_consumed * 3.0;
    } else if (c.units_consumed <= 200) {
        c.bill_amount = 100 * 3.0 + (c.units_consumed - 100) * 4.0;
    } else if (c.units_consumed <= 300) {
        c.bill_amount = 100 * 3.0 + 100 * 4.0 + (c.units_consumed - 200) * 5.0;
    } else {
        c.bill_amount = 100 * 3.0 + 100 * 4.0 + 100 * 5.0 + (c.units_consumed - 300) * 6.0;
    }
    
    customers[num_customers] = c;
    num_customers++;
    
    printf("Customer added successfully\n");
}

void print_customer(customer c) {
    printf("%d\t%s\t%d\t%d\t%d\t%.2f\n", c.id, c.name, c.prev_reading, c.curr_reading, c.units_consumed, c.bill_amount);
}

void list_customers() {
    printf("ID\tName\tPrev Reading\tCurr Reading\tUnits Consumed\tBill Amount\n");
    for (int i = 0; i < num_customers; i++) {
        print_customer(customers[i]);
    }
}

int main() {
    int choice;
    do {
        printf("\nElectricity Bills Management\n");
        printf("1. Add customer\n");
        printf("2. List customers\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_customer();
                break;
            case 2:
                list_customers();
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Error: Invalid choice\n");
        }
    } while (choice != 3);
    
    return 0;
}
