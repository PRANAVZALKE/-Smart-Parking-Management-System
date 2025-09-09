#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cctype>
#include <ctime>

using namespace std;

// Structure to represent a parked car
struct Car {
    string plate;
    string owner;
    string entryTime;
    Car* next;
    
    // Constructor for easier initialization
    Car(const string& p, const string& o, const string& time) 
        : plate(p), owner(o), entryTime(time), next(nullptr) {}
};

class ParkingLot {
private:
    Car* head;
    int capacity;
    int count;
    
    // Helper function to get current time as string
    string getCurrentTime() {
        time_t now = time(0);
        char* timeStr = ctime(&now);
        string result(timeStr);
        // Remove newline character
        result.pop_back();
        return result;
    }
    
    // Helper function to normalize plate numbers (uppercase, no spaces)
    string normalizePlate(string plate) {
        // Remove spaces and convert to uppercase
        plate.erase(remove_if(plate.begin(), plate.end(), ::isspace), plate.end());
        transform(plate.begin(), plate.end(), plate.begin(), ::toupper);
        return plate;
    }
    
    // Helper function to validate plate format (basic validation)
    bool isValidPlate(const string& plate) {
        return !plate.empty() && plate.length() >= 3 && plate.length() <= 10;
    }
    
    // Helper function to validate owner name
    bool isValidOwner(const string& owner) {
        return !owner.empty() && owner.length() >= 2;
    }

public:
    // Constructor
    ParkingLot(int cap) : head(nullptr), capacity(cap), count(0) {
        if (cap <= 0) {
            cout << "Warning: Invalid capacity set. Using default capacity of 10.\n";
            capacity = 10;
        }
    }
    
    // Destructor
    ~ParkingLot() {
        clear();
    }
    
    // Clear all cars from parking lot
    void clear() {
        Car* current = head;
        while (current) {
            Car* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
        count = 0;
    }
    
    // Check if parking lot is full
    bool isFull() const {
        return count >= capacity;
    }
    
    // Check if parking lot is empty
    bool isEmpty() const {
        return count == 0;
    }
    
    // Get current occupancy
    int getCurrentCount() const {
        return count;
    }
    
    // Get total capacity
    int getCapacity() const {
        return capacity;
    }
    
    // Get available spots
    int getAvailableSpots() const {
        return capacity - count;
    }
    
    // Check if a car is already parked
    bool isCarParked(const string& plate) {
        string normalizedPlate = normalizePlate(plate);
        Car* current = head;
        while (current) {
            if (normalizePlate(current->plate) == normalizedPlate) {
                return true;
            }
            current = current->next;
        }
        return false;
    }
    
    // Park a car
    bool parkCar(const string& plate, const string& owner) {
        // Input validation
        if (!isValidPlate(plate)) {
            cout << "❌ Invalid plate number! Plate must be 3-10 characters long.\n";
            return false;
        }
        
        if (!isValidOwner(owner)) {
            cout << "❌ Invalid owner name! Name must be at least 2 characters long.\n";
            return false;
        }
        
        if (isFull()) {
            cout << "🚫 Parking lot is full! Cannot park car: " << plate << "\n";
            cout << "💡 Please try again later or find alternative parking.\n";
            return false;
        }
        
        string normalizedPlate = normalizePlate(plate);
        
        // Check for duplicate
        if (isCarParked(normalizedPlate)) {
            cout << "⚠️  Car with plate " << normalizedPlate << " is already parked!\n";
            return false;
        }
        
        // Create new car node and add to front (stack behavior)
        Car* newCar = new Car(normalizedPlate, owner, getCurrentTime());
        newCar->next = head;
        head = newCar;
        count++;
        
        cout << "✅ Car parked successfully!\n";
        cout << "📋 Details: Plate: " << normalizedPlate 
             << ", Owner: " << owner << "\n";
        cout << "🕒 Entry Time: " << newCar->entryTime << "\n";
        cout << "📊 Available spots: " << getAvailableSpots() << "/" << capacity << "\n";
        
        return true;
    }
    
    // Remove a car from parking
    bool exitCar(const string& plate) {
        if (isEmpty()) {
            cout << "❌ Parking lot is empty! No cars to remove.\n";
            return false;
        }
        
        string normalizedPlate = normalizePlate(plate);
        Car* current = head;
        Car* previous = nullptr;
        
        // Search for the car
        while (current) {
            if (normalizePlate(current->plate) == normalizedPlate) {
                // Found the car, remove it
                if (previous) {
                    previous->next = current->next;
                } else {
                    head = current->next;
                }
                
                cout << "✅ Car exited successfully!\n";
                cout << "📋 Details: Plate: " << current->plate 
                     << ", Owner: " << current->owner << "\n";
                cout << "🕒 Entry Time: " << current->entryTime << "\n";
                cout << "🕒 Exit Time: " << getCurrentTime() << "\n";
                
                delete current;
                count--;
                
                cout << "📊 Available spots: " << getAvailableSpots() << "/" << capacity << "\n";
                return true;
            }
            previous = current;
            current = current->next;
        }
        
        cout << "❌ Car with plate " << normalizedPlate << " not found in parking lot.\n";
        return false;
    }
    
    // Search for a specific car
    void searchCar(const string& plate) {
        if (isEmpty()) {
            cout << "❌ Parking lot is empty!\n";
            return;
        }
        
        string normalizedPlate = normalizePlate(plate);
        Car* current = head;
        int position = 1;
        
        while (current) {
            if (normalizePlate(current->plate) == normalizedPlate) {
                cout << "\n🔍 Car Found!\n";
                cout << "📋 Plate: " << current->plate << "\n";
                cout << "👤 Owner: " << current->owner << "\n";
                cout << "🕒 Entry Time: " << current->entryTime << "\n";
                cout << "📍 Position in queue: " << position << "\n";
                return;
            }
            current = current->next;
            position++;
        }
        
        cout << "❌ Car with plate " << normalizedPlate << " not found.\n";
    }
    
    // Display all parked cars
    void display() const {
        if (isEmpty()) {
            cout << "\n📭 Parking lot is empty.\n";
            cout << "📊 Available spots: " << capacity << "/" << capacity << "\n";
            return;
        }
        
        cout << "\n🚗 === ACTIVE PARKED CARS ===\n";
        cout << string(60, '-') << "\n";
        cout << left << setw(5) << "#" 
             << setw(12) << "Plate" 
             << setw(15) << "Owner" 
             << "Entry Time\n";
        cout << string(60, '-') << "\n";
        
        Car* current = head;
        int position = 1;
        
        while (current) {
            cout << left << setw(5) << position
                 << setw(12) << current->plate
                 << setw(15) << current->owner
                 << current->entryTime << "\n";
            current = current->next;
            position++;
        }
        
        cout << string(60, '-') << "\n";
        cout << "📊 Total parked: " << count << "/" << capacity 
             << " | Available: " << getAvailableSpots() << "\n";
    }
    
    // Display parking statistics
    void displayStats() const {
        cout << "\n📈 === PARKING STATISTICS ===\n";
        cout << "🏢 Total Capacity: " << capacity << " spots\n";
        cout << "🚗 Cars Parked: " << count << " vehicles\n";
        cout << "🅿️  Available Spots: " << getAvailableSpots() << " spaces\n";
        cout << "📊 Occupancy Rate: " << fixed << setprecision(1) 
             << (count * 100.0 / capacity) << "%\n";
        
        if (isFull()) {
            cout << "🔴 Status: FULL\n";
        } else if (count > capacity * 0.8) {
            cout << "🟡 Status: Nearly Full\n";
        } else if (count > capacity * 0.5) {
            cout << "🟢 Status: Moderate\n";
        } else {
            cout << "🟢 Status: Plenty of Space\n";
        }
    }
};

// Function to display menu
void displayMenu() {
    cout << "\n🚗 === SMART PARKING MANAGEMENT SYSTEM ===\n";
    cout << "1. 🅿️  Park Car\n";
    cout << "2. 🚪 Exit Car\n";
    cout << "3. 📋 Display All Parked Cars\n";
    cout << "4. 🔍 Search Car\n";
    cout << "5. 📈 View Statistics\n";
    cout << "6. 🧹 Clear All Cars\n";
    cout << "7. ❌ Exit Program\n";
    cout << string(45, '-') << "\n";
    cout << "Enter your choice (1-7): ";
}

// Function to get string input (handles spaces)
string getStringInput(const string& prompt) {
    string input;
    cout << prompt;
    cin.ignore(); // Clear buffer
    getline(cin, input);
    return input;
}

int main() {
    cout << "🚗 Welcome to Smart Parking Management System!\n";
    cout << string(50, '=') << "\n";
    
    int capacity;
    cout << "Enter parking lot capacity: ";
    cin >> capacity;
    
    ParkingLot lot(capacity);
    
    int choice;
    string plate, owner;
    
    do {
        displayMenu();
        cin >> choice;
        
        switch (choice) {
            case 1: // Park Car
                plate = getStringInput("Enter car plate number: ");
                owner = getStringInput("Enter owner name: ");
                lot.parkCar(plate, owner);
                break;
                
            case 2: // Exit Car
                plate = getStringInput("Enter car plate number to exit: ");
                lot.exitCar(plate);
                break;
                
            case 3: // Display All Cars
                lot.display();
                break;
                
            case 4: // Search Car
                plate = getStringInput("Enter car plate number to search: ");
                lot.searchCar(plate);
                break;
                
            case 5: // View Statistics
                lot.displayStats();
                break;
                
            case 6: // Clear All Cars
                {
                    char confirm;
                    cout << "⚠️  Are you sure you want to clear all cars? (y/N): ";
                    cin >> confirm;
                    if (confirm == 'y' || confirm == 'Y') {
                        lot.clear();
                        cout << "✅ All cars have been cleared from the parking lot.\n";
                    } else {
                        cout << "❌ Operation cancelled.\n";
                    }
                }
                break;
                
            case 7: // Exit Program
                cout << "\n👋 Thank you for using Smart Parking Management System!\n";
                cout << "🚗 Drive safely!\n";
                break;
                
            default:
                cout << "❌ Invalid choice! Please enter a number between 1-7.\n";
        }
        
        if (choice != 7) {
            cout << "\nPress Enter to continue...";
            cin.ignore();
            cin.get();
        }
        
    } while (choice != 7);
    
    return 0;
}
