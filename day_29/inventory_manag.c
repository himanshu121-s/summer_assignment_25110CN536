#include <stdio.h>

struct Product
{
    int id;
    char name[50];
    int quantity;
    float price;
};

int main()
{
    struct Product products[100];

    int count = 0;
    int choice;
    int searchId;
    int found;
    int i, j;
    int sellQuantity;

    do
    {
        printf("\n====================================\n");
        printf("      INVENTORY MANAGEMENT SYSTEM\n");
        printf("====================================\n");

        printf("1. Add Product\n");
        printf("2. Display All Products\n");
        printf("3. Search Product\n");
        printf("4. Update Product\n");
        printf("5. Sell Product\n");
        printf("6. Delete Product\n");
        printf("7. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                if (count >= 100)
                {
                    printf("Inventory is full!\n");
                    break;
                }

                printf("\nEnter Product ID: ");
                scanf("%d", &products[count].id);

                printf("Enter Product Name: ");
                scanf(" %[^\n]", products[count].name);

                printf("Enter Quantity: ");
                scanf("%d", &products[count].quantity);

                printf("Enter Price: ");
                scanf("%f", &products[count].price);

                count++;

                printf("Product added successfully!\n");
                break;

            case 2:
                if (count == 0)
                {
                    printf("\nNo products available.\n");
                }
                else
                {
                    printf("\n===== ALL PRODUCTS =====\n");

                    for (i = 0; i < count; i++)
                    {
                        printf("\nProduct %d\n", i + 1);
                        printf("Product ID: %d\n",
                               products[i].id);
                        printf("Name: %s\n",
                               products[i].name);
                        printf("Quantity: %d\n",
                               products[i].quantity);
                        printf("Price: %.2f\n",
                               products[i].price);
                        printf("Total Value: %.2f\n",
                               products[i].quantity *
                               products[i].price);
                    }
                }
                break;

            case 3:
                printf("\nEnter Product ID to search: ");
                scanf("%d", &searchId);

                found = 0;

                for (i = 0; i < count; i++)
                {
                    if (products[i].id == searchId)
                    {
                        printf("\nProduct Found!\n");
                        printf("Product ID: %d\n",
                               products[i].id);
                        printf("Name: %s\n",
                               products[i].name);
                        printf("Quantity: %d\n",
                               products[i].quantity);
                        printf("Price: %.2f\n",
                               products[i].price);

                        found = 1;
                        break;
                    }
                }

                if (found == 0)
                {
                    printf("Product not found!\n");
                }
                break;

            case 4:
                printf("\nEnter Product ID to update: ");
                scanf("%d", &searchId);

                found = 0;

                for (i = 0; i < count; i++)
                {
                    if (products[i].id == searchId)
                    {
                        printf("Enter New Product Name: ");
                        scanf(" %[^\n]", products[i].name);

                        printf("Enter New Quantity: ");
                        scanf("%d", &products[i].quantity);

                        printf("Enter New Price: ");
                        scanf("%f", &products[i].price);

                        printf("Product updated successfully!\n");

                        found = 1;
                        break;
                    }
                }

                if (found == 0)
                {
                    printf("Product not found!\n");
                }
                break;

            case 5:
                printf("\nEnter Product ID to sell: ");
                scanf("%d", &searchId);

                found = 0;

                for (i = 0; i < count; i++)
                {
                    if (products[i].id == searchId)
                    {
                        printf("Enter quantity to sell: ");
                        scanf("%d", &sellQuantity);

                        if (sellQuantity <= 0)
                        {
                            printf("Invalid quantity!\n");
                        }
                        else if (sellQuantity >
                                 products[i].quantity)
                        {
                            printf("Insufficient stock!\n");
                        }
                        else
                        {
                            products[i].quantity -= sellQuantity;

                            printf("Product sold successfully!\n");
                            printf("Remaining Quantity: %d\n",
                                   products[i].quantity);

                            printf("Total Sale Amount: %.2f\n",
                                   sellQuantity *
                                   products[i].price);
                        }

                        found = 1;
                        break;
                    }
                }

                if (found == 0)
                {
                    printf("Product not found!\n");
                }
                break;

            case 6:
                printf("\nEnter Product ID to delete: ");
                scanf("%d", &searchId);

                found = 0;

                for (i = 0; i < count; i++)
                {
                    if (products[i].id == searchId)
                    {
                        for (j = i; j < count - 1; j++)
                        {
                            products[j] = products[j + 1];
                        }

                        count--;

                        printf("Product deleted successfully!\n");

                        found = 1;
                        break;
                    }
                }

                if (found == 0)
                {
                    printf("Product not found!\n");
                }
                break;

            case 7:
                printf("\nExiting Inventory Management System...\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 7);

    return 0;
}