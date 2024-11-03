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
    cout << "Enter your selection as 1, 2, 3, or 4 to QUIT\n";
}

void namePrompt() {
    string name;
    cout << "Enter the Element Name: ";

    getline (cin, name);
    cout << "You entered " << name << "Now using quantum hydrolysis to compute element data\n\n";

    Element element = findElementFromName(name);
    if (element == NULL) {
        cout << "Element not found. Please check for spelling and/or scientific validity and try again.";
    }

    cout << "The symbol for " << element.getName() << " is: " << element.getSymbol()<< endl; 
    cout << "The atomic mass of " << element.getName() << " is: " << element.getMass() << " g/mol\n";
    cout << element.getName() << " is in group " << element.getGroup()  << " which means it is a(n) " << element.getType() << endl   
}

void symbolPrompt() {
    string symbol;
    cout << "Enter the Element Symbol: ";

    getline (cin, symbol);
    cout << "You entered " << symbol << "Now using quantum hydrolysis to compute element data\n\n";

    Element element = findElementFromSymbol(symbol);
    if (element == NULL) {
        cout << "Element not found. Please check for spelling and/or scientific validity and try again."
    }

    cout << "The name of " << element.getSymbol() << " is: " << element.getName()<< endl; 
    cout << "The atomic mass of " << element.getName() << " is: " << element.getMass() << " g/mol\n";
    cout << element.getName() << " is in group " << element.getGroup()  << " which means it is a(n) " << element.getType() << endl   
}

void atomNumPrompt() {
    int atomNum;
    cout << "Enter the Element's atomic number: ";

    cin >> atomNum;
    cout << "You entered " << atomNum << "Now using quantum hydrolysis to compute element data\n\n";

    Element element = findElementFromAtomicNum(atomNum);
    if (element == NULL) {
        cout << "Element not found. Please check for spelling and/or scientific validity and try again."
    }

    cout << "The name of this element is " << element.getName() << ".";
    cout << "The symbol for " << element.getName() << " is: " << element.getSymbol() << endl; 
    cout << "The atomic mass of " << element.getName() << " is: " << element.getMass() << " g/mol\n";
    cout << element.getName() << " is in group " << element.getGroup()  << " which means it is a(n) " << element.getType() << endl   
}

// This function will, when given a filename, open the file, read it, and populate a list of Elements.
// Input: filename
// Output: void
// Action: set's our global Element list.
void readCSV(const string& filename) {
    vector<Element> elements;
    vector<string> headers;

    ifstream file(filename);

    if (!file.is_open()) {
        throw runtime_error("Could not open file");
    }

    string line, cell;
    // Read the header line
    if (getline(file, line)) {
        istringstream headerStream(line);
        string header;
        while (getline(headerStream, header, ',')) {
            headers.push_back(header);
        }
    }

    while (getline(file, line)) {
            Element element;
            vector<string> row;
            stringstream lineStream(line);

            while (getline(lineStream, cell, ',')) {
                row.push_back(cell);
                //Element myElement(my_symbol, my_name, my_color, my_type, my_phase, my_atomic_number, my_molar_mass, my_group, my_period);
            }

            for(unsigned int i = 0; i < row.size(); ++i ) {
                if (headers[i] == "Name") {
                    element.setName(row[i]);
                }
                else if (headers[i] == "Symbol") {
                    element.setSymbol(row[i]);
                }
                else if (headers[i] == "Atomic_Number") {
                    element.setAtomicNum(stoi(row[i]));
                }
                else if (headers[i] == "Group") {
                    element.setGroup(stoi(row[i]));
                }
                else if (headers[i] == "Atomic_Weight") {
                    element.setMass(stoi(row[i]));
                }
                else if (headers[i] == "Phase") {
                    if(row[i] == "Solid") {
                        element.setPhase(Phase :: Solid);
                    }
                    else if(row[i] == "Liquid") {
                        element.setPhase(Phase :: Liquid);
                    }
                    else if(row[i] == "Gas") {
                        element.setPhase(Phase :: Gas);
                    }
                    else {
                        element.setPhase(Phase :: Unknown);
                    }
                }
                elements.push_back(element);
            }
        }
}

Element findElementFromName(string name) {
    for(Element element : all_the_elements) {
        if (element.getName() == name) {
            return element;
        }
    }
    return NULL;
}

Element findElementFromSymbol(string symbol) {
    for(Element element : all_the_elements) {
        if (element.getSymbol() == symbol) {
            return element;
        }
    }
}

Element findElementFromAtomicNum(int atomicNum) {
    for(Element element : all_the_elements) {
        if (element.getAtomicNum() == atomicNum) {
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
        char repeat;

        menu();

        cin >> selection 
        if (selection == 1) {
            namePrompt();
        }
        else if (selection == 2) {
            string symbol;
            cout << "Enter the Element Symbol: "
            getline (cin, symbol);
            //do option 2
        }
        else if (selection == 3) {
            int atomNum;
            cout << "Enter the Element Symbol: "
            getline (cin, atomNum);
            //do option 3
        }
        else if (selection == 4) {
            cout << "Thanks for using this periodic table, see you next time!\n\n";
            break;  
        }
        else {
            cout << "Please enter a valid input per menu instructions. (1, 2, 3, or 4)\n"
            continue;
        }
        
        cout << "Would you like to search another element? (Y/y or N/n to QUIT)\n";
        cin >> repeat;

        if (tolower(repeat) == 'y') {
            continue;
        }
        else if (tolower(repeat) == 'n') {
            cout << "Thanks for using this periodic table, see you next time!\n\n";
            break;
        }

    }


    //Element user_element = findElementFromName("Helium");
    //cout << "The symbol of that element is " << user_element.getSymbol() << endl;

    return 0;
}