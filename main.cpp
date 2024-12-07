#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>
#include <vector>

#include "Element.cpp"

using namespace std;

vector<Element> all_the_elements;

Element* findElementFromName(string name) {
    cout << "Size of elements vector" << all_the_elements.size() << endl;
    for(Element& element : all_the_elements) {
        if (element.getName() == name) {
            cout << "Returning element" << endl;
            return &element;
        }
    }
    return nullptr;
}

Element* findElementFromSymbol(string symbol) {
    for(Element element : all_the_elements) {
        if (element.getSymbol() == symbol) {
            return &element;
        }
    }
    return nullptr;
}

Element* findElementFromAtomicNum(int atomicNum) {
    for(Element element : all_the_elements) {
        if (element.getAtomicNum() == atomicNum) {
            return &element;
        }
    }
    return nullptr;
}

void menu() {
    cout << "Please select one of the following\n\n";
    cout << "Option 1: Search element by name.\n";
    cout << "Option 2: Search Element by Symbol.\n";
    cout << "Option 3: Search Element by atomic number\n";
    cout << "Enter your selection as 1, 2, 3, or 4 to QUIT\n";
}


string removeQuotes(const std::string& str) {
    static regex quoteRegex("^\"|\"$"); // Matches leading or trailing quotes
    return regex_replace(str, quoteRegex, "");
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
        int i = 1;
        while (getline(headerStream, header, ',')) {
            headers.push_back(removeQuotes(header));
        }
    }

    // Loop over each line in the file
    while (getline(file, line)) {
        Element element;
        vector<string> row;
        stringstream lineStream(line);

        // Loop over each value in the row
        while (getline(lineStream, cell, ',')) {
            // Put values of single row into array
            row.push_back(removeQuotes(cell));
        }

        for (unsigned int i = 0; i < row.size(); ++i)
        {
            if(row[i] == "") {
                continue;
            }

            if (headers[i] == "Name")
            {
                cout << "Setting element name = " << row[i] << endl;
                element.setName(row[i]);
            }
            else if (headers[i] == "Symbol")
            {
                element.setSymbol(row[i]);
            }
            else if (headers[i] == "Atomic_Number")
            {
                element.setAtomicNum(stoi(row[i]));
            }
            else if (headers[i] == "Group")
            {
                element.setGroup(stoi(row[i]));
            }
            else if (headers[i] == "Atomic_Weight")
            {
                element.setMass(stoi(row[i]));
            }
            else if (headers[i] == "Phase")
            {
                if (row[i] == "Solid")
                {
                    element.setPhase(Phase ::Solid);
                }
                else if (row[i] == "Liquid")
                {
                    element.setPhase(Phase ::Liquid);
                }
                else if (row[i] == "Gas")
                {
                    element.setPhase(Phase ::Gas);
                }
                else
                {
                    element.setPhase(Phase ::Unknown);
                }
            }
        }
        all_the_elements.push_back(element);
    }
}




// Main will start the program, we will pass the proper filename 'elementdatavalues.csv'
int main() {
    string filename = "elements.csv";

    readCSV(filename);

    cout << "Welcome to the C++ Periodic Table 5000, brought to you by C programing and Dmitri Mendeleev: a GMoney production\n\n";

    bool running = true;
    while (running) {

        int selection = -1;
        char repeat;

        menu();

        cin >> selection; 
        if (selection == 1) {
            string name;
            cout << "Enter the Element Name: ";

            cin.ignore();
            cin.clear();
            getline (cin, name);
            cout << "You entered " << name << ", Now using quantum hydrolysis to compute element data\n\n";

            Element *element = findElementFromName(name);
            if (element == nullptr) {
                cout << "Element not found. Please check for spelling and/or scientific validity and try again.";
            } else {
                cout << "The symbol for " << element->getName() << " is: " << element->getSymbol()<< endl; 
                cout << "The atomic mass of " << element->getName() << " is: " << element->getMass() << " g/mol\n";
                // cout << element->getName() << " is in group " << element->getGroup()  << " which means it is a(n) " << element->getType() << endl;
            }
        }
        else if (selection == 2) {
            string symbol;
            cout << "Enter the Element Symbol: ";
            getline (cin, symbol);
            //do option 2
        }
        else if (selection == 3) {
            int atomNum;
            cout << "Enter the Element Symbol: ";
            cin >> atomNum;
            //do option 3
        }
        else if (selection == 4) {
            running = false;  
        }
        else {
            cout << "Please enter a valid input per menu instructions. (1, 2, 3, or 4)\n";
            continue;
        }
        
        cout << "Would you like to search another element? (Y/y or N/n to QUIT)\n";
        cin >> repeat;

        if (tolower(repeat) == 'y') {
            continue;
        }
        else if (tolower(repeat) == 'n') { 
            running = false;
        }

    }
    cout << "Thanks for using this periodic table, see you next time!\n\n";


    //Element user_element = findElementFromName("Helium");
    //cout << "The symbol of that element is " << user_element.getSymbol() << endl;

    return 0;
}