#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_LENGTH 100
#define LINE_LENGTH 256
#define PRODUCTS 100
#define STATES 52

// Defining a structure at first for the products
typedef struct {
    char name[LINE_LENGTH];
    int amount;
    double unit_price;
    char state[3];
    double total;
    double tax;
} Product;

// Defining a structure at first for the state tax
typedef struct {
    char name[3];
    double tax_rate;
} StateTax;


// Reads the order from the file and puts it in the Product array
void readorder(char *filename, Product *products, int *product_amount);

// Reads tax rate data and puts it in the StateTax array
void readtaxes(char *filename, StateTax *state_taxes);

// Looks up the state abbreviation in the state_taxes array
double gettaxes(char *state, StateTax *state_taxes);

// Calculates the total for each product
void writetotal(Product *products, int product_amount, StateTax *state_taxes, double *total_tax, double *grand_total);

// Writes the invoice
void writeinvoice(char *filename, Product *products, int product_amount, double total_tax, double grand_total);


int main(int a, char **b) {
    // Character arrays for storing the inputs and outputs
    char fileorder[FILE_LENGTH] = "order.txt";
    char taxfile[FILE_LENGTH] = "tax_rate.txt";
    char invoicefile[FILE_LENGTH] = "invoice.txt";
    
    if (a >= 2) {
        strncpy(fileorder, b[1], FILE_LENGTH);
    }
    if (a >= 3) {
        strncpy(taxfile, b[2], FILE_LENGTH);
    }
    if (a >= 4) {
        strncpy(invoicefile, b[3], FILE_LENGTH);
    }
    
    Product products[PRODUCTS];
    int product_amount = 0;
    readorder(fileorder, products, &product_amount);
    
    StateTax state_taxes[STATES];
    readtaxes(taxfile, state_taxes);
    
    double total_tax, grand_total;
    writetotal(products, product_amount, state_taxes, &total_tax, &grand_total);
    
    writeinvoice(invoicefile, products, product_amount, total_tax, grand_total);
    
    return 0;
}


void readorder(char *filename, Product *products, int *product_amount) {
    // Takes the filename
    FILE *fp = fopen(filename, "r");
    
    // If it doesn't open, prints an error and exits the if statement sequence
    if (!fp) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }
    
    char line[LINE_LENGTH];

    // If the file is successfully opened, it runs this while loop which uses sscanf to organize the data on each line into individual variables
    while (fgets(line, LINE_LENGTH, fp)) {
        
        char name[LINE_LENGTH];
        int amount;
        double unit_price;
        char state[3];
        
        sscanf(line, "%[^,], %d, %lf, %s", name, &amount, &unit_price, state);
        
        // Fill the products array with the data from the file
        strncpy(products[*product_amount].name, name, LINE_LENGTH);
        products[*product_amount].amount = amount;
        products[*product_amount].unit_price = unit_price;
        strncpy(products[*product_amount].state, state, 3);
        
        (*product_amount)++;
    }
    
    fclose(fp);
}

double gettaxes(char *state, StateTax *state_taxes) {
    for (int i = 0; i < STATES; i++) {
        if (strcmp(state, state_taxes[i].name) == 0) {
            return state_taxes[i].tax_rate;
        }
    }
    // Print an error message and exit the program if the state is not found
    fprintf(stderr, "Error: state %s not found in tax data.\n", state);
    exit(EXIT_FAILURE);
}


void writetotal(Product *products, int product_amount, StateTax *state_taxes, double *total_tax, double *grand_total) {
    double tax_rate;
    for (int i = 0; i < product_amount; i++) {
        // Calculate the tax rate for the product's state
        tax_rate = gettaxes(products[i].state, state_taxes);
        products[i].tax = products[i].unit_price * products[i].amount * tax_rate;
        products[i].total = products[i].unit_price * products[i].amount + products[i].tax;
        // Updates the total tax and the grand total
        *total_tax += products[i].tax;
        *grand_total += products[i].total;
    }
}


void writeinvoice(char *filename, Product *products, int product_amount, double total_tax, double grand_total) {
    // Opens or creates a text file in write mode
    FILE *fp = fopen(filename, "w");

    // If it doesn't open, prints an error and exits the if statement sequence
    if (!fp) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }
    
    // If the file does open, it proceeds with this sequence below
    fprintf(fp, "Name, Amount, Unit Price, State, Tax, Total\n"); 

    // Prints the details of each product
    for (int i = 0; i < product_amount; i++) {

        // Rounds the tax and total amounts in the print statement
        fprintf(fp, "%s, %d, %.2lf, %s, %.2lf, %.2lf\n",
                products[i].name, products[i].amount, products[i].unit_price,
                products[i].state, products[i].tax, products[i].total);
    }

    // Goes into the files and prints the tax and the grand total
    fprintf(fp, "Total Tax: %.2lf\n", total_tax);
    fprintf(fp, "Grand Total: %.2lf\n", grand_total);
    fclose(fp);
}


void readtaxes(char *filename, StateTax *state_taxes) {
    // Opens a file in read mode
    FILE *fp = fopen(filename, "r");

    // If it doesn't open, prints an error and exits the if statement sequence
    if (!fp) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    // If the file does open, it proceeds with this sequence below
    char line[8];
    int i = 0;

    // Reads the tax rate and stores it in the StateTax array
    while (fgets(line, 8, fp)) {
        // Copies the state abbreviation to the StateTax structure
        strncpy(state_taxes[i].name, line, 3);
        state_taxes[i].name[2] = '\0';

        // Stores the string into tax_rate of the StateTax structure
        state_taxes[i].tax_rate = atof(line + 3);

        // Keeps track of the index count
        i++;
    }
    fclose(fp);
}