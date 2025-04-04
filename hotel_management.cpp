#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "food_menu.h"

using namespace std;

void displayRooms() {
    cout << "\n===== ROOM OPTIONS =====\n";
    cout << "We have 10 rooms available (showing four types):\n";
    cout << "1. Single Room (300rs - 500rs)\n";
    cout << "2. Double Room (600rs - 1000rs)\n";
    cout << "3. Deluxe Room (1000rs - 2300rs)\n";
    cout << "4. Suite Room (2500rs - 4000rs)\n";
    cout << "Enter your choice (1-4): ";
}

void generateBill(string name, long long phone, int foodTotal, int roomTotal) {
    cout << "\n========= Sir Your Bill  =========\n";
    cout << "Name: " << name << "\n";
    cout << "Contact: " << phone << "\n";
    cout << "Food Total: Rs. " << foodTotal << "\n";
    cout << "Room Rent: Rs. " << roomTotal << "\n";
    cout << "Total Amount: Rs. " << (foodTotal + roomTotal) << "\n";
    cout << "===========================\n";
}

void saveToFile(string name, long long phone, int foodTotal, int roomTotal, int rating, string feedback) {
    ofstream file("hotel_data.txt", ios::app);
    file << "Name: " << name << ", ";
    file << "Phone: " << phone << ", ";
    file << "Food Total: Rs. " << foodTotal << ", ";
    file << "Room Rent: Rs. " << roomTotal << ", ";
    file << "Total Amount: Rs. " << (foodTotal + roomTotal) << ", ";
    file << "Rating: " << rating << ", ";
    file << "Feedback: " << feedback << "\n";
    file.close();
}

int main() {
    int foodTotal = 0, roomTotal = 0, rating, roomChoice;
    string customerName, feedback, foodInput;
    long long phoneNumber;
    
    cout << "\n===== MOST WELCOME  SIR IN OUR HOTEL =====\n";
    cout << "Enter Your Name: ";
    cin >> customerName;
    cout << "Enter Contact Number: ";
    cin >> phoneNumber;
    
    char roomOption, foodOption;
    
    cout << "Do you want to book a room? (y/n): ";
    cin >> roomOption;
    if (roomOption == 'y' || roomOption == 'Y') {
        displayRooms();
        cin >> roomChoice;
        switch(roomChoice) {
            case 1: roomTotal = 400; break;
            case 2: roomTotal = 800; break;
            case 3: roomTotal = 1650; break;
            case 4: roomTotal = 3250; break;
            default:
                cout << "Invalid room choice! No room booked.\n";
                roomTotal = 0;
                break;
        }
        if (roomTotal > 0) {
            cout << "Your room has been booked. Thank you!\n";
        }
    }
    
    cout << "Do you want to order food? (y/n): ";
    cin >> foodOption;
    
    if (foodOption == 'y' || foodOption == 'Y') {
        displayMenu();
        cout << "\nEnter food item numbers separated by commas (e.g., 1,3,5): ";
        cin.ignore();
        getline(cin, foodInput);
        
        stringstream ss(foodInput);
        string item;
        vector<int> foodChoices;
        
        while (getline(ss, item, ',')) {
            foodChoices.push_back(stoi(item));
        }

        for (int choice : foodChoices) {
            if (choice >= 1 && choice <= menuSize) {
                foodTotal += getProductPrice(choice);
            } else {
                cout << "Invalid food choice: " << choice << "\n";
            }
        }
        
        cout << "Total Food Cost: Rs. " << foodTotal << "\n";
    }

    // **Billing before rating**
    char billOption;
    cout << "\nWould you like to generate your bill now? (y/n): ";
    cin >> billOption;

    if (billOption == 'y' || billOption == 'Y') {
        generateBill(customerName, phoneNumber, foodTotal, roomTotal);
    }

    // **Service Rating and Feedback**
    cout << "\nPlease Rate our service  (1-5): ";
    cin >> rating;
    cout << "Optional Feedback: ";
    cin.ignore();
    getline(cin, feedback);
    
    saveToFile(customerName, phoneNumber, foodTotal, roomTotal, rating, feedback);
    
    cout << "\nThank You! Visit Again!\n";
    
    return 0;
}
