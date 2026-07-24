#include <iostream>
using namespace std;

// ===== USE 1: Static Local Variables =====
// Retains value between function calls (initialized once, persists across calls)
void incrementCounter() {
    static int counter = 0;  // Initialized only on first call, persists thereafter
    counter++;  // Increments and keeps value between calls
    cout << "Counter: " << counter << endl;  // Output increases each call
}

// ===== USE 2: Static Global Variables =====
// Limited to internal linkage (visible only in this translation unit)
static int globalSecret = 100;  // Cannot be accessed from other .cpp files
void showGlobalSecret() {
    cout << "Global Secret: " << globalSecret << endl;  // Only accessible here
}

// ===== USE 3: Static Member Variables =====
// Shared across all instances of the class (belongs to class, not object)
class BankAccount {
public:
    static int totalAccounts;  // Shared by all instances; declared here, defined outside
    int balance;  // Non-static: each instance has its own
    
    // Constructor increments shared static variable
    BankAccount(int initialBalance) : balance(initialBalance) {
        totalAccounts++;  // All instances share this counter
    }
};

int BankAccount::totalAccounts = 0;  // Define and initialize static member outside class

// ===== USE 4: Static Member Functions =====
// Called without an object instance; can only access static members
class MathUtils {
public:
    static int add(int a, int b) {  // No 'this' pointer; callable as MathUtils::add()
        return a + b;  // Can only access static data, not instance data
    }
};

// ===== Main Demo =====
int main() {
    cout << "=== Static Local Variables ===" << endl;
    incrementCounter();  // Counter: 1
    incrementCounter();  // Counter: 2
    incrementCounter();  // Counter: 3
    
    cout << "\n=== Static Global Variables ===" << endl;
    showGlobalSecret();  // Global Secret: 100
    
    cout << "\n=== Static Member Variables ===" << endl;
    BankAccount acc1(5000);  // totalAccounts = 1
    cout << "Total Accounts: " << BankAccount::totalAccounts << endl;  // Access via class name
    BankAccount acc2(3000);  // totalAccounts = 2
    cout << "Total Accounts: " << BankAccount::totalAccounts << endl;  // Updated for all instances
    
    cout << "\n=== Static Member Functions ===" << endl;
    int result = MathUtils::add(10, 20);  // Called without object instance
    cout << "10 + 20 = " << result << endl;  // Static function result
    
    return 0;
}
