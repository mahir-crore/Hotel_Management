#ifndef FOOD_MENU_H
#define FOOD_MENU_H

#include <iostream>
using namespace std;

struct MenuItem {
    string name;
    int price;
};

const MenuItem menu[] = {
    {"Tea", 10}, {"Spl Tea", 15}, {"Nes Coffee", 30}, {"Filter Coffee", 30},
    {"Poha", 25}, {"Upma", 35}, {"Sevai Upma", 50}, {"Vada Pav", 50},
    {"Bread Patties", 40}, {"Vada Sambhar", 40}, {"Medu Vada Sambhar", 40},
    {"Sabudana Vada", 50}, {"Sabudana Khichadi", 50}, {"Idli(3)", 60},
    {"Idli Fry Masala", 60}, {"Misal", 60}, {"Puri Bhaji", 50},
    {"Batata Bhaji", 50}, {"Kanda Bhaji", 30}, {"Mix Bhaji", 50},
    {"Sada Dosa", 30}, {"Masala Dosa", 50}, {"Big Masala Dosa", 80},
    {"Rawa Dosa", 50}, {"Mysore Masala Dosa", 80}, {"Cheese Masala Dosa", 80},
    {"Paneer Masala Dosa", 100}, {"Atithi Spl Masala Dosa", 80},
    {"Onion Uttapa", 100}, {"Tomato Cheese Uttapa", 100}, {"Tomato Omlete", 80},
    {"Coconut Uttapa", 80},
    {"Veg Fried Rice", 120}, {"Schezwan Fried Rice", 130},
    {"Mushroom Fried Rice", 140}, {"Hong Kong Fried Rice", 140},
    {"Singapuri Fried Rice", 140}, {"Veg. Hakka Noodles", 140},
    {"Schezwan Noodles", 130}, {"Hong Kong Noodles", 130},
    {"Singapuri Noodle", 140}, {"Tripple Sz. Fried Rice", 180},
    {"Veg 65", 140}, {"Veg Chilly", 150}, {"Veg Manchurian", 130},
    {"Gobi Manchurian", 150}, {"Paneer 65", 150},
    {"Paneer Chilly", 170}, {"Paneer Manchurian", 150},
    {"Veg Crispy", 150}, {"Mushroom/Babycorn 65", 150},
    {"Mushroom/Babycorn Chilly", 150},
    {"Aloo Paratha", 70}, {"Methi Paratha", 70},
    {"Gobi Paratha", 80}, {"Paneer Paratha", 80},
    {"Cheese Paratha", 90}, {"Desi Ghee Aloo Paratha", 90},
    {"Desi Ghee Butter Aloo Paratha", 90},
    {"Desi Ghee Cheese Aloo Paratha", 90},
    {"Desi Ghee Gobi Paratha", 90},
    {"Desi Ghee Paneer Paratha", 99}
};

const int menuSize = sizeof(menu) / sizeof(menu[0]);

void displayMenu() {
    cout << "\n===== FOOD MENU =====\n";
    for (int i = 0; i < menuSize; i++) {
        cout << i + 1 << ". " << menu[i].name << " - Rs. " << menu[i].price << "\n";
    }
}

int getProductPrice(int choice) {
    if (choice >= 1 && choice <= menuSize) {
        return menu[choice - 1].price;
    }
    return 0;
}

#endif
