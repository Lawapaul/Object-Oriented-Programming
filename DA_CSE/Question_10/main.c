#include <stdio.h>
struct Item {
    float cost;
    int quantity;
};

// Function to calculate total inventory value
float calculate_inventory_value(struct Item items[], int num_items) {
    float total_value = 0.0;
    for (int i = 0; i < num_items; i++) {
        total_value += items[i].cost * items[i].quantity;
    }
    return total_value;
}

// Function to calculate total number of items in inventory
int calculate_total_items(struct Item items[], int num_items) {
    int total_items = 0;
    for (int i = 0; i < num_items; i++) {
        total_items += items[i].quantity;
    }
    return total_items;
}

int main() {
    struct Item inventory[15];
    int num_items = 0;
    printf("Enter information for each item (up to %d items):\n", 15);
    while (num_items < 15) {
        printf("Item %d: Cost and Quantity (separated by space): ", num_items + 1);
        if (scanf("%f %d", &inventory[num_items].cost, &inventory[num_items].quantity) != 2)
            break;
        num_items++;
    }

    float total_value = calculate_inventory_value(inventory, num_items);
    int total_items = calculate_total_items(inventory, num_items);

    printf("\nTotal number of items in inventory: %d\n", total_items);
    printf("Total value of inventory: $%.2f\n", total_value);

    printf("\nEnter changes to the inventory:\n");
    for (int i = 0; i < num_items; i++) {
        printf("Change in quantity for item %d: ", i + 1);
        int change;
        scanf("%d", &change);
        inventory[i].quantity += change;
    }

    total_value = calculate_inventory_value(inventory, num_items);
    total_items = calculate_total_items(inventory, num_items);

    printf("\nUpdated total number of items in inventory: %d\n", total_items);
    printf("Updated total value of inventory: %.2f\n", total_value);

    return 0;
}