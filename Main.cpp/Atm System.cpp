#include <iostream>
#include <string>
#include <vector> 

class ATM 
{
private:
    double balance = 1000.00; 
    bool isRunning = true;
    std::vector<std::string> transactionHistory; 

public:
    void DisplayBalance()
    {
        std::cout << "Your account balance is: $" << balance << std::endl;
    }

    void Deposit()
    {
        std::cout << "Enter the amount to deposit: $";
        double amount;
        std::cin >> amount;
        if (amount > 0)
        {
            balance += amount; 
            std::cout << "$" << amount << " has been deposited\n" << std::endl;
            transactionHistory.push_back("Deposit: $" + std::to_string(amount));
        }
        else
        {
            std::cout << "Invalid amount. Please enter a positive value" << std::endl;
        }
    }

    void Withdraw()
    {
        std::cout << "Enter the amount to withdraw: $";
        double amount;
        std::cin >> amount;
        if (amount > 0)
        {
            if (balance >= amount)
            {
                balance -= amount;
                std::cout << "$" << amount << " has been withdrawn. Collect dispensed cash below!\n" << std::endl;
                transactionHistory.push_back("Withdrawal: $" + std::to_string(amount));
            }
            else
            {
                std::cout << "Insufficient balance. Please enter a correct amount." << std::endl;
            }
        }
        else
        {
            std::cout << "Invalid amount. Please enter a positive value." << std::endl;
        }
    }

    void DisplayTransactionHistory()
    {
        std::cout << "Transaction History:" << std::endl;
        for (const auto& transaction : transactionHistory)
        {
            std::cout << transaction << std::endl;
        }
    }

    void Run()
    {
        while (isRunning)
        {
            int num01;

            std::cout << "Thank You For Using American Express!\nPlease Insert Your Card Into the Slot.\nPress Enter When It Is Inserted!" << std::endl;
            std::cin.ignore(); 
            std::cin.get();
            std::cout << "Please Enter Your Pin Number to Continue:";
            std::cin >> num01;
            std::string answer;
            std::cout << "You Have Entered: " << num01 << ". Is This Correct, Yes or No?" << std::endl;
            std::cin >> answer;
            if (answer == "No")
            {
                std::cout << "Sorry, this attempt has been cleared due to a false verification.\nYou have been redirected to the start menu!\n" << std::endl;
            }
            else
            {
                bool returnToMainScreen = true;

                while (returnToMainScreen)
                {
                    std::cout << "-------------------------------\n";
                    std::cout << "Please select an option below:" << std::endl;
                    std::cout << "1. Display Balance" << std::endl;
                    std::cout << "2. Deposit" << std::endl;
                    std::cout << "3. Withdraw" << std::endl;
                    std::cout << "4. Display Transaction History" << std::endl;
                    std::cout << "5. Exit" << std::endl;

                    int choice;
                    std::cin >> choice;

                    switch (choice)
                    {
                    case 1:
                        DisplayBalance();
                        break;
                    case 2:
                        Deposit();
                        break;
                    case 3:
                        Withdraw();
                        break;
                    case 4:
                        DisplayTransactionHistory();
                        break;
                    case 5:
                        isRunning = false;
                        returnToMainScreen = false; 
                        std::cout << "Thank you for using American Express." << std::endl;
                        break;
                    default:
                        std::cout << "Please select a valid option." << std::endl;
                        break;
                    }
                }
            }
        }
    }
};

int main()
{
    ATM atm; 
    atm.Run(); 
    return 0;
}