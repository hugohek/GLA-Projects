/*
 * EE312 Simple CRM Project
 *
 * YOUR INFO HERE!
 */

#include "Invent.h"
#include "MyString.h"
#include <assert.h>
#include <stdio.h>

#define MAX_CUSTOMERS 1000
Customer customers[MAX_CUSTOMERS];
int num_customers = 0;

/* you'll probably need several more global variables */
/* and of course, you have a few functions to write */
Customer database[MAX_CUSTOMERS];
int num_books = 0;
int num_dice = 0;
int num_figures = 0;
int num_towers = 0;

// create
String books, dice, figures, towers;
bool stringsInitialized = true;

/*
    Added functions
*/

// 1st find by customer details
int *findItem(String word, Customer &person)
{
    if (StringIsEqualTo(&word, &books))
    {
        return &person.books;
    }
    else if (StringIsEqualTo(&word, &dice))
    {
        return &person.dice;
    }
    else if (StringIsEqualTo(&word, &figures))
    {
        return &person.figures;
    }
    else if (StringIsEqualTo(&word, &towers))
    {
        return &person.towers;
    }
    /* NOT REACHED */
    return 0;
}
// 2nd find by quantity
int *findItem(String word, int quantity)
{
    if (StringIsEqualTo(&word, &books))
    {
        num_books += quantity;
        return &num_books;
    }
    else if (StringIsEqualTo(&word, &dice))
    {
        num_dice += quantity;
        return &num_dice;
    }
    else if (StringIsEqualTo(&word, &figures))
    {
        num_figures += quantity;
        return &num_figures;
    }
    else if (StringIsEqualTo(&word, &towers))
    {
        num_towers += quantity;
        return &num_towers;
    }
    /* NOT REACHED */
    return 0;
}

void updateCustomer(String type, Customer &customer, int q)
{
    if (StringIsEqualTo(&type, &books))
    {
        customer.books += q;
        // return &customer.books;
    }
    else if (StringIsEqualTo(&type, &dice))
    {
        customer.dice += q;
        //  return &customer.dice;
    }
    else if (StringIsEqualTo(&type, &figures))
    {
        customer.figures += q;
        //  return &customer.figures;
    }
    else if (StringIsEqualTo(&type, &towers))
    {
        customer.towers += q;
        //  return &customer.towers;
    }
}
int findCustomer(String name, String item, int q)
{
    if (num_customers <= MAX_CUSTOMERS)
    {
        // String Name = StringCreate(name);
        for (int i = 0; i < num_customers; i++)
        {
            if (StringIsEqualTo(&database[i].name, &name)) // case sensitive
            {
                updateCustomer(item, database[i], q);
                return i; // customer found;
            }
        }
        // customer not found create one if they are purchasing
        if (q > 0)
        {
            database[num_customers].name = StringDup(&name);
            database[num_customers].books = 0;
            database[num_customers].dice = 0;
            database[num_customers].figures = 0;
            database[num_customers].towers = 0;
            updateCustomer(item, database[num_customers], q);
            num_customers++;
        }
    }
    return -1; // DNE
}
int *getItem(String word)
{
    if (StringIsEqualTo(&word, &books))
    {
        return &num_books;
    }
    else if (StringIsEqualTo(&word, &dice))
    {
        return &num_dice;
    }
    else if (StringIsEqualTo(&word, &figures))
    {
        return &num_figures;
    }
    else if (StringIsEqualTo(&word, &towers))
    {
        return &num_towers;
    }
    /* NOT REACHED */
    return 0;
}
Customer *findMax(String type)
{
    Customer *result = 0;
    int max = -1;
    for (int k = 0; k < num_customers; k += 1)
    {
        Customer &person = database[k];
        int *p = findItem(type, person);
        if (*p > max)
        {
            max = *p;
            result = &person;
        }
    }
    return result;
}

/* clear the inventory and reset the customer database to empty */
void reset(void)
{
    for (int i = 0; i < num_customers; i++)
    {
        StringDestroy(&database[i].name);
        database[i].books = 0;
        database[i].dice = 0;
        database[i].figures = 0;
        database[i].towers = 0;
    }
    num_customers = 0;
    num_books = 0;
    num_dice = 0;
    num_figures = 0;
    num_towers = 0;
    StringDestroy(&books);
    StringDestroy(&dice);
    StringDestroy(&figures);
    StringDestroy(&towers);
}
void processSummarize()
{
    printf("There are %d Books %d Dice %d Figures and %d Towers in inventory\n", num_books, num_dice, num_figures, num_towers);
    printf("we have had a total of %d different customers\n", num_customers);

    Customer *mostbooks = findMax(books); // Pointer to the customer who purchased the most books
    Customer *mostdice = findMax(dice);   // Pointer to the customer who purchased the most dice
    Customer *mostfigures = findMax(figures);
    Customer *mosttowers = findMax(towers);
    if (mostbooks->books != 0)
    {
        StringPrint(&mostbooks->name);
        printf(" has purchased the most Books (%d)\n", mostbooks->books);
    }
    else
    {
        printf("no one has purchased any Books\n");
    }
    if (mostdice->dice != 0)
    {
        StringPrint(&mostdice->name);
        printf(" has purchased the most Dice (%d)\n", mostdice->dice);
    }
    else
    {
        printf("no one has purchased any Dice\n");
    }
    if (mostfigures->figures != 0)
    {
        StringPrint(&mostfigures->name);
        printf(" has purchased the most Figures (%d)\n", mostfigures->figures);
    }
    else
    {
        printf("no one has purchased any Figures\n");
    }
    if (mosttowers->towers != 0)
    {
        StringPrint(&mosttowers->name);
        printf(" has purchased the most Towers (%d)\n", mosttowers->towers);
    }
    else
    {
        printf("no one has purchased any Towers\n");
    }
}

void processPurchase()
{
    String name, item;
    int quantity = 0;
    readString(&name);
    readString(&item);
    readNum(&quantity);

    // case
    if (quantity > 0)
    {
        if (StringIsEqualTo(&item, &books))
        {
            if (quantity <= num_books)
            {
                num_books -= quantity;
                findCustomer(name, item, quantity);
            }
            else
            {
                printf("Sorry ");
                StringPrint(&name);
                printf(", we only have %d", *getItem(item));
                StringPrint(&item);
                printf("\n");
            }
        }
        else if (StringIsEqualTo(&item, &dice))
        {
            if (quantity <= num_dice)
            {
                num_dice -= quantity;
                findCustomer(name, item, quantity);
            }
            else
            {
                printf("Sorry ");
                StringPrint(&name);
                printf(", we only have %d ", *getItem(item));
                StringPrint(&item);
                printf("\n");
            }
        }
        else if (StringIsEqualTo(&item, &figures))
        {
            if (quantity <= num_figures)
            {
                num_figures -= quantity;
                findCustomer(name, item, quantity);
            }
            else
            {
                printf("Sorry ");
                StringPrint(&name);
                printf(", we only have %d ", *getItem(item));
                StringPrint(&item);
                printf("\n");
            }
        }
        else if (StringIsEqualTo(&item, &towers))
        {
            if (quantity <= num_towers)
            {
                num_towers -= quantity;
                findCustomer(name, item, quantity);
            }
            else
            {
                printf("Sorry ");
                StringPrint(&name);
                printf(", we only have %d ", *getItem(item));
                StringPrint(&item);
                printf("\n");
            }
        }
    }
    StringDestroy(&name);
    StringDestroy(&item);
}

void processInventory()
{
    books = StringCreate("Books");
    dice = StringCreate("Dice");
    figures = StringCreate("Figures");
    towers = StringCreate("Towers");

    String item;      // name of the item
    int quantity = 0; // num of item to add
    readString(&item);
    readNum(&quantity);
    if (quantity >= 0)
    {
        findItem(item, quantity);
    }
    // printf("We currently have %d Books %d Dice, %d Figures and %d Towers in inventory\n",
    //        num_books, num_dice, num_figures, num_towers);
    StringDestroy(&item); //-> new edit
}

void processReturn()
{
    String name, item;
    int quantity;

    readString(&name);
    readString(&item);
    readNum(&quantity);

    int customerIdx = findCustomer(name, item, 0);
    if (customerIdx == -1)
    {
        printf("Sorry ");
        StringPrint(&name);
        printf(", we do not have you in our database\n");
    }
    else
    {
        // custumer exist
        Customer &customer = database[customerIdx];
        // Check if the customer has enough items to return
        int customer_quantity = *findItem(item, customer);
        // StringPrint(&name);
        //  printf(" - returns %d  Owns %d \n", quantity, customer_quantity);
        if (quantity > customer_quantity)
        {
            StringPrint(&name);
            printf(" , you do not have %d ", quantity);
            StringPrint(&item);
            printf("\n");
            // return;
        }
        else
        {
            // Update customer and inventory
            // quantity *= -1;
            updateCustomer(item, customer, -quantity);
            findItem(item, quantity);
        }
    }
    StringDestroy(&name);
    StringDestroy(&item);
}
