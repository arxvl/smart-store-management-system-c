/* SMART STORE INVENTORY MANAGEMENT WITH 
DYNAMIC RESTOCK OPTIMIZATION AND RECEIPT 
GENERATION SYSTEM SIMULATION */

#include <stdio.h>

#define MAX 100 // Maximum number of items in the inventory

/* Structure */
struct Store {
    char code[50];
    char name[50];
    float price;
    int stock;
    int restockThreshold;
}; 
typedef struct Store inventory_item;

/* Function prototypes */
void readInventoryFile(const char *inventoryFile, inventory_item *items);
void readCostumerCartFile(const char *cartFile, inventory_item *items, int itemCount);
void displayInventory(inventory_item *items, int itemCount);

int main() {
    inventory_item items[MAX]; // Array to hold inventory items

}

/* =============== FUNCTIONS =============== */

/* Function to read inventory.txt file */
void readInventoryFile(const char *inventoryFile, inventory_item *items){
    FILE *inventoryFile = fopen("inventory.txt", "r");
    if (inventoryFile == NULL) { // check if inventory.txt file is opened successfully
        printf("Error opening inventory.txt!\n");
        return 1;
    }

    int count = 0;

    while(count <= MAX && fscanf(inventoryFile, "%s %s %f %d %d", items[count].code, items[count].name, 
        &items[count].price, &items[count].stock, &items[count].restockThreshold) == 5) {
        count++;
    }
}