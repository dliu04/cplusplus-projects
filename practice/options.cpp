#include "options.h"

void option_master(int option){
    option = option_selector(option);
    int check = option_checker(option);
    while (check == 0){
        option = option_selector(option);
        check = option_checker(option);
    }

    switch (option) {
        case 1:
            cout << "Option 1 Chosen" << endl;
            break;
        case 2: 
            cout << "Option 2 Chosen" << endl;
            break;
        case 3:
            cout << "Option 3 Chosen" << endl;
            break;
    }
}

int option_selector(int option){
    cout << "1. Case 1" << endl;
    cout << "2. Case 2" << endl;
    cout << "3. Case 3" << endl;
    cout << "Select an option: ";
    cin >> option;
    return option;
}

int option_checker(int option){
    if (option < 1 || option > 3){
        cout << "Invalid option. Please select a valid option." << endl;
        return 0;
    } else {
        return 1;
    }
}