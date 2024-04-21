#include <iostream>
#include <string>

// Define constant for maximum transactions
const int MAX_TRANSACTIONS = 50;

// Declare arrays to store sales records
int transactionNo[MAX_TRANSACTIONS]; // Array to store transaction numbers
std::string cookieType[MAX_TRANSACTIONS]; // Array to store types of cookies sold
int quantitySold[MAX_TRANSACTIONS]; // Array to store quantities sold
double pricePerUnit[MAX_TRANSACTIONS]; // Array to store prices per unit
std::string customerName[MAX_TRANSACTIONS]; // Array to store customer names
int numTransactions = 0; // Variable to track the number of transactions

// Function prototypes
void recordSales(); // Function to record sales
double calculateTotalRevenue(); // Function to calculate total revenue
void displaySalesRecords(); // Function to display sales records
void findSalesByCustomer(); // Function to find sales by customer
void updateSalesRecord(); // Function to update sales record

// Main function
int main() {
    char choice; // Variable to store user choice
    do { // Using do...while loop for menu
        std::cout << "\n===== Cookie Sales Management System =====\n" << std::endl;
        std::cout << "1. Record Sales\n"
                  << "2. Calculate Total Revenue\n"
                  << "3. Display Sales Records\n"
                  << "4. Find Sales by Customer\n"
                  << "5. Update Sales Record\n"
                  << "6. Exit\n"<< std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) { // Switch statement to handle user choice
            case '1':
                recordSales(); // Call recordSales function
                break;
            case '2':
                std::cout << "Total Revenue: RM" << calculateTotalRevenue() << std::endl; // Call calculateTotalRevenue function and display total revenue
                break;
            case '3':
                displaySalesRecords(); // Call displaySalesRecords function
                break;
            case '4':
                findSalesByCustomer(); // Call findSalesByCustomer function
                break;
            case '5':
                updateSalesRecord(); // Call updateSalesRecord function
                break;
            case '6':
                std::cout << "Exiting program." << std::endl; // Display exit message
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl; // Display message for invalid choice
        }
    } while (choice != '6'); // Continue loop until user chooses to exit

    return 0;
}

// Function definitions

// Function to record sales
void recordSales() {
    if (numTransactions >= MAX_TRANSACTIONS) { // Check if maximum transactions limit reached
        std::cout << "Maximum transactions limit reached." << std::endl; // Display message if limit reached
        return;
    }

    // Prompt user to enter sales details
    std::cout << "Enter transaction number: ";
    std::cin >> transactionNo[numTransactions];

    std::cout << "Enter cookie type: ";
    std::cin >> cookieType[numTransactions];

    std::cout << "Enter quantity sold: ";
    std::cin >> quantitySold[numTransactions];

    std::cout << "Enter price per unit: RM";
    std::cin >> pricePerUnit[numTransactions];

    std::cout << "Enter customer name: ";
    std::cin >> customerName[numTransactions];

    numTransactions++; // Increment number of transactions
}

// Function to calculate total revenue
double calculateTotalRevenue() {
    double totalRevenue = 0.0; // Variable to store total revenue
    for (int i = 0; i < numTransactions; ++i) { // Loop through all transactions
        totalRevenue += quantitySold[i] * pricePerUnit[i]; // Calculate total revenue
    }
    return totalRevenue; // Return total revenue
}

// Function to display sales records
void displaySalesRecords() {
    std::cout << "Transaction No\tCookie Type\tQuantity\tPrice/Unit\tCustomer Name\tTotal Revenue"<<std::endl; // Display header for sales records
    for (int i = 0; i < numTransactions; ++i) { // Loop through all transactions
        double total = quantitySold[i] * pricePerUnit[i]; // Calculate total revenue for each transaction
        // Display sales records
        std::cout << transactionNo[i] << "\t\t" << cookieType[i] << "\t\t" << quantitySold[i]
                  << "\t\t" << pricePerUnit[i] << "\t\t" << customerName[i] << "\t\t" << total << std::endl;
    }
}

// Function to find sales by customer
void findSalesByCustomer() {
    std::string customer; // Variable to store customer name
    std::cout << "Enter customer name: ";
    std::cin >> customer; // Prompt user to enter customer name

    std::cout << "Sales records for " << customer << ":" << std::endl; // Display header for sales records
    std::cout << "Transaction No\tCookie Type\tQuantity\tPrice/Unit\tTotal Revenue" << std::endl; // Display header for sales records
    for (int i = 0; i < numTransactions; ++i) { // Loop through all transactions
        if (customerName[i] == customer) { // Check if customer name matches
            double total = quantitySold[i] * pricePerUnit[i]; // Calculate total revenue for each transaction
            // Display sales records for customer
            std::cout << transactionNo[i] << "\t\t" << cookieType[i] << "\t\t" << quantitySold[i]
                      << "\t\t" << pricePerUnit[i] << "\t\t" << total << std::endl;
        }
    }
}

// Function to update sales record
void updateSalesRecord() {
    int transactionNumber; // Variable to store transaction number to update
    std::cout << "Enter transaction number to update: ";
    std::cin >> transactionNumber; // Prompt user to enter transaction number

    for (int i = 0; i < numTransactions; ++i) { // Loop through all transactions
        if (transactionNo[i] == transactionNumber) { // Check if transaction number matches
            // Prompt user to enter updated sales details
            std::cout << "Enter updated cookie type: ";
            std::cin >> cookieType[i];

            std::cout << "Enter updated quantity sold: ";
            std::cin >> quantitySold[i];

            std::cout << "Enter updated price per unit: ";
            std::cin >> pricePerUnit[i];

            std::cout << "Enter updated customer name: ";
            std::cin >> customerName[i];

            std::cout << "Sales record updated successfully." << std::endl; // Display success message
            return;
        }
    }
    std::cout << "Transaction number not found." << std::endl; // Display message if transaction number not found
}

