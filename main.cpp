#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "Element.cpp";

using namespace std;

vector<Element> all_the_elements;

void menu() {
    cout << "Please select one of the following\n\n";
    cout << "Option 1: Search element by name.\n";
    cout << "Option 2: Search Element by Symbol.\n";
    cout << "Option 3: Search Element by atomic number\n";
    cout << "Enter your selection as 1, 2, 3, or 4.\n";
}


// This function will, when given a filename, open the file, read it, and populate a list of Elements.
// Input: filename
// Output: void
// Action: set's our global Element list.
void readCSV(const string& filename) {
    vector<Element> elements;
    ifstream file(filename);
    string line, cell;
    if (file.is_open()) {
        while (getline(file, line)) {
            vector<string> row;
            stringstream lineStream(line);

            while (getline(lineStream, cell, ',')) {
                row.push_back(cell);
                // Element myElement(my_symbol, my_name, my_color, my_type, my_phase, my_atomic_number, my_molar_mass, my_group, my_period);
            }
            // elements.push_back();
        }
        file.close();
    } else {
        cerr << "Error opening file!" << endl;
    }

    all_the_elements = elements;
}

Element findElementFromName(string name) {
    for(Element element : all_the_elements) {
        if (element.getName() == name) {
            return element;
        }
    }
}

Element findElementFromSymbol(string symbol) {
    for(Element element : all_the_elements) {
        if (element.getSymbol() == symbol) {
            return element;
        }
    }
}


// Main will start the program, we will pass the proper filename 'elementdatavalues.csv'
int main() {
    string filename = "elementdatavalues.csv";
    readCSV(filename);

    cout << "Welcome to the C++ Periodic Table 5000, brought to you by C programing and Dmitri Mendeleev: a GMoney production\n\n";

    int x = 1;
    while (x == 1) {

        int selection = -1;

        menu();
        
        cin >> selection 
        if (selection == 1) {
            //do option 1
        }
        else if (selection == 2) {
            //do option 2
        }
        else if (selection == 3) {
            //do option 3
        }
        else if (selection == 4) {
            //do option 4
        }

    }


    Element user_element = findElementFromName("Helium");
    cout << "The symbol of that element is " << user_element.getSymbol() << endl;

    return 0;
}