#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

#ifdef _WIN32
#include <windows.h>
#else
// ANSI escape codes for text color
#define RED_TEXT "\033[1;31m"
#define DEFAULT_TEXT "\033[0m"
#endif

using namespace std;

void centerOutput(const std::string &outputText)
{
    // Get the width of the terminal window
    int terminalWidth = 80; // default width
#ifdef _WIN32
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
    {
        terminalWidth = csbi.dwSize.X;
    }
#endif

    // Calculate the position to center the output
    int outputWidth = outputText.length(); // Use the length of the output text
    int padding = (terminalWidth - outputWidth) / 2;

    // Move the cursor to the center and print the output
#ifdef _WIN32
    std::cout << std::setw(padding) << "" << outputText << std::endl;
#else
    std::cout << RED_TEXT << std::setw(padding) << "" << outputText << DEFAULT_TEXT << std::endl;
#endif
}

std::string centerInput(const std::string &prompt)
{
    // Get the width of the terminal window
    int terminalWidth = 80; // default width
#ifdef _WIN32
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
    {
        terminalWidth = csbi.dwSize.X;
    }
#endif

    // Calculate the position to center the input prompt
    int promptWidth = prompt.length(); // Use the length of the input prompt
    int padding = (terminalWidth - promptWidth) / 2;

    // Move the cursor to the center and print the input prompt
#ifdef _WIN32
    std::cout << std::setw(padding) << "" << prompt;
#else
    std::cout << RED_TEXT << std::setw(padding) << "" << prompt << DEFAULT_TEXT;
#endif

    // Get user input
    std::string userInput;
    getline(cin, userInput);
    return userInput;
}

class ANIMAL
{
private:
    string animalid;
    string name;
    string species;
    string age;
    string health_status;

public:
    void getId()
    {
        animalid = centerInput("Enter Animal Id:         ");
    }

    void display()
    {
        centerOutput("------------------------");
        centerOutput("Animal ID: " + animalid);
        centerOutput("Name: " + name);
        centerOutput("Species: " + species);
        centerOutput("Age: " + age);
        centerOutput("Health Status: " + health_status);
    }

    void display1()
    {
        centerOutput("------------------------");
        centerOutput("Animal ID: " + animalid);
        centerOutput("Name: " + name);
        // centerOutput("Species: " + species);
        // centerOutput("Age: " + age);
        // centerOutput("Health Status: " + health_status);
    }
    void getName()
    {
        name = centerInput("Enter Animal Name:       ");
    }

    void getSpecies()
    {
        species = centerInput("Enter Animal species:     ");
    }

    void getAge()
    {
        age = centerInput("Enter Animal Age:       \t");
    }

    void getHealthStatus()
    {
        health_status = centerInput("Enter Health_Status:      ");
    }

    void saveToFile()
    {
        ofstream outFile("animal_data.txt", ios::app);
        if (outFile.is_open())
        {
            outFile << animalid << "," << name << "," << species << "," << age << "," << health_status << endl;
            outFile.close();
        }
        else
        {
            cout << "Error: Unable to open file for writing." << endl;
        }
    }

    void loadFromFile()
    {
        string AI = centerInput("Enter the Animal id:       ");
        ifstream inFile("animal_data.txt");
        if (inFile.is_open())
        {
            while (getline(inFile, animalid, ',') &&
                   getline(inFile, name, ',') &&
                   getline(inFile, species, ',') &&
                   getline(inFile, age, ',') &&
                   getline(inFile, health_status))
            {
                if (stoi(animalid) == stoi(AI))
                    display();
                // cout << "-------------------------" << endl;
            }
            inFile.close();
        }
        else
        {
            cout << "Error: Unable to open file for reading." << endl;
        }
    }

    void loadFromFile1()
    {
        int countVeg = 0;
        int countNonVeg = 0;

        // Vectors to store animal details
        vector<string> vegAnimals, nonVegAnimals;

        ifstream inFile("animal_data.txt");
        if (inFile.is_open())
        {
            while (getline(inFile, animalid, ',') &&
                   getline(inFile, name, ',') &&
                   getline(inFile, species, ',') &&
                   getline(inFile, age, ',') &&
                   getline(inFile, health_status))
            {
                // Display details based on species
                if (species == "veg")
                {
                    vegAnimals.push_back("Animal ID:" + animalid + "---Animal Name:" + name);
                    display1();
                    countVeg++;
                }
                else if (species == "nonveg")
                {
                    nonVegAnimals.push_back("Animal ID:" + animalid + "---Animal Name:" + name);
                    display1();
                    countNonVeg++;
                }
            }

            // Display the total count of animals
            string totalVegAnimals = to_string(countVeg);
            string totalNonVegAnimals = to_string(countNonVeg);
            string totalAnimals = to_string(countVeg + countNonVeg);

            centerOutput("------------------------");
            centerOutput("TOTAL VEGETARIAN ANIMALS: " + totalVegAnimals);
            centerOutput("TOTAL NON-VEGETARIAN ANIMALS: " + totalNonVegAnimals);
            centerOutput("TOTAL ANIMALS: " + totalAnimals);

            // Display Veg Animals
            centerOutput("Vegetarian Animals:");
            for (const string &vegAnimal : vegAnimals)
            {
                centerOutput(vegAnimal);
            }

            // Display Non-Veg Animals
            centerOutput("Non-Vegetarian Animals:");
            for (const string &nonVegAnimal : nonVegAnimals)
            {
                centerOutput(nonVegAnimal);
            }

            inFile.close();
        }
        else
        {
            cout << "Error: Unable to open file for reading." << endl;
        }
    }
};

class Feeding
{
public:
    string FeedingId;
    string AnimalId;
    string FoodType;
    string Quantity;
    string FeedingTime;
    string FeedingDate;
    string FoodCost;
    double TotalCost;
    string i;
    double cost1;
    double ct; // = 0.0;

public:
    string getFeedingId()
    {
        return FeedingId = centerInput("Enter The FeedingId:       ");
    }

    string getAnimalId()
    {
        return AnimalId = centerInput("Enter The AnimalId:       ");
    }

    string getFoodType()
    {
        return FoodType = centerInput("Enter The FoodType:       ");
    }

    string getQuantity()
    {
        return Quantity = centerInput("Enter The Quantity(KG):       ");
    }

    string getFeedingTime()
    {
        return FeedingTime = centerInput("Enter The FeedingTime:       ");
    }

    string getFeedingDate()
    {
        return FeedingDate = centerInput("Enter The FeedingDate:       ");
    }

    string getFoodCost()
    {
        return FoodCost = centerInput("Enter The FoodCost(per Kg):       ");
    }

    void display()
    {
        centerOutput("Feeding ID: " + FeedingId);
        centerOutput("Animal Id: " + AnimalId);
        centerOutput("Food Type: " + FoodType);
        centerOutput("Quantity (KG): " + Quantity);
        centerOutput("Feeding Time: " + FeedingTime);
        centerOutput("Feeding Date: " + FeedingDate);
        centerOutput("FoodCost(per KG): " + FoodCost);
    }

    void saveToFile()
    {
        ofstream outFile("feeding_data.txt", ios::app);
        if (outFile.is_open())
        {
            outFile << FeedingId << "," << AnimalId << "," << FoodType << "," << Quantity << "," << FeedingTime << "," << FeedingDate << "," << FoodCost << endl;
            outFile.close();
        }
        else
        {
            cout << "Error: Unable to open file for writing." << endl;
        }
    }

    void loadFromFile()
    {
        string FI = centerInput("Enter the feeding id:       ");
        centerOutput("-------------------------");
        ifstream inFile("feeding_data.txt");
        if (inFile.is_open())
        {
            while (getline(inFile, FeedingId, ',') &&
                   getline(inFile, AnimalId, ',') &&
                   getline(inFile, FoodType, ',') &&
                   getline(inFile, Quantity, ',') &&
                   getline(inFile, FeedingTime, ',') &&
                   getline(inFile, FeedingDate, ',') &&
                   getline(inFile, FoodCost))
            {
                if (stoi(FeedingId) == stoi(FI))
                    display();
                centerOutput("-------------------------");
                // cout << "-------------------------" << endl;
            }
            inFile.close();
        }
        else
        {
            cout << "Error: Unable to open file for reading." << endl;
        }
    }
    double cost()
    {
        string inputAnimalId = centerInput("Enter animal id: ");
        centerOutput("-------------------------");

        ifstream inFile("feeding_data.txt");
        if (inFile.is_open())
        {
            while (getline(inFile, FeedingId, ',') &&
                   getline(inFile, AnimalId, ',') &&
                   getline(inFile, FoodType, ',') &&
                   getline(inFile, Quantity, ',') &&
                   getline(inFile, FeedingTime, ',') &&
                   getline(inFile, FeedingDate, ',') &&
                   getline(inFile, FoodCost))
            {
                if (inputAnimalId == AnimalId)
                {
                    // Display the feeding details
                    display();

                    // Calculate and display the total cost
                    TotalCost = stod(Quantity) * stod(FoodCost);
                    centerOutput("Total Cost: " + to_string(TotalCost));
                    centerOutput("-------------------------");

                    inFile.close();
                    return TotalCost;
                }
            }
            inFile.close();
        }
        else
        {
            cout << "Error: Unable to open file for reading." << endl;
        }

        // If the animal ID is not found, return a default value
        return 0.0;
    }

    void calculateFeedingCost()
    {
        ifstream inFile("feeding_data.txt");
        if (inFile.is_open())
        {
            double totalCost = 0.0;
            string currentAnimalId;

            while (getline(inFile, FeedingId, ',') &&
                   getline(inFile, AnimalId, ',') &&
                   getline(inFile, FoodType, ',') &&
                   getline(inFile, Quantity, ',') &&
                   getline(inFile, FeedingTime, ',') &&
                   getline(inFile, FeedingDate, ',') &&
                   getline(inFile, FoodCost))
            {
                if (currentAnimalId.empty())
                {
                    currentAnimalId = AnimalId;
                }

                // If a new animal is encountered, display total cost and reset
                if (currentAnimalId != AnimalId)
                {
                    centerOutput("-------------------------");
                    centerOutput("Total Feeding Cost for Animal ID " + currentAnimalId + ": $" + to_string(totalCost));
                    centerOutput("-------------------------");

                    // Update the cost1 field for the current animal
                    cost1 = totalCost;

                    // Reset for the new animal
                    currentAnimalId = AnimalId;
                    totalCost = 0.0;
                }

                // Calculate and accumulate the total cost
                totalCost += stod(Quantity) * stod(FoodCost);
                ct = ct + totalCost;
            }

            // Display the last animal's total cost
            centerOutput("-------------------------");
            centerOutput("Total Feeding Cost for Animal ID " + currentAnimalId + ": $" + to_string(totalCost));
            centerOutput("-------------------------");

            // Update the cost1 field for the last animal
            cost1 = totalCost;

            inFile.close();
        }

        // centerOutput("The Total Animal Cost of per day:" + to_string(ct));
        else
        {
            cout << "Error: Unable to open file for reading." << endl;
        }
        centerOutput("The Total Animal Cost of per day:" + to_string(ct));
        // centerOutput("DO YOU WANT TO CALCULATE TOTAL COST OF ANY AMOUNT OF DATE(y/n):");
        string awer = centerInput("DO YOU WANT TO CALCULATE TOTAL COST OF ANY AMOUNT OF DATE(y/n):");
        if (awer == "y")
        {
            string countdate = centerInput("Enter the Amount of date:       ");
            double dc = stod(countdate) * ct;
            centerOutput("The Total Animal Cost of" + countdate + "days=" + to_string(dc));
        }
    }
    int budget() // double ct
    {
        double bgt = 100000;
        double finalbgt = 0.0;
        double dcd = 0.0;
        // double upbgt; // Remove this line

        centerOutput("             The Total Budget of the :" + to_string(bgt));

        // string t = centerInput("Do You Want To Update The Budget(y/n) :");
        // if (t == "y")
        // {
        //     string upbgt = centerInput("Enter the adding amount:       ");
        //     bgt += stod(upbgt);
        //     centerOutput("The Total Budget of the :" + to_string(bgt));
        // }

        if (centerInput("               Do You Want To Update The Budget(y/n) :") == "y")
        {
            string upbgt = centerInput("       Enter the adding amount:       ");
            bgt += stod(upbgt);
            centerOutput("             The Total Budget of the :" + to_string(bgt));
        }

        string AnS = centerInput("                       Do You Want to see budget after some days(y/n):");
        if (AnS == "y")
        {
            string cd = centerInput("                Enter the how much days after budget:  ");
            dcd = stod(cd) * ct;

            finalbgt = bgt - dcd;
            centerOutput("How Much budget Will Be Left After " + cd + " Days= " + to_string(finalbgt));
            // centerOutput("Because the calculated cost is " + to_string(finalbgt));
        }
        return finalbgt;
    }

    // void displayWithCost()
    // {
    //     // display(); // Display basic details

    //     // Display feeding cost
    //     // centerOutput("Feeding Cost: $" + to_string(cost1));
    //     // centerOutput("-------------------------");
    // }
};

int main()
{
    ANIMAL a;
    Feeding f;
    string ans, ANS;

    // Set text color (not supported in Dev C++ on Windows)
#ifdef _WIN32
    system("color 17");
#endif

    cout << "\n\n\n\n\n";
    do
    {
        centerOutput("WELCOME TO ZOO CASE STUDY");
        centerOutput("-------------------------");
        centerOutput("1. Add Animal            ");
        centerOutput("2. Feed Animal           ");
        centerOutput("3. Display Animal Details");
        centerOutput(" 4. Display Feeding Details");
        centerOutput("                   5. Total Food Cost(for single Animal):     ");
        centerOutput("                       6. Display Each animal cost And Total cost:     ");
        centerOutput("                7. Display all Animal and count Animals:");
        centerOutput("8.budget:               ");
        centerOutput("9. Exit                  ");

        // Get user input
        string userInput = centerInput("Enter your choice:       ");

        // Convert the string input to an integer
        int choice;
        try
        {
            choice = stoi(userInput);
        }
        catch (const std::invalid_argument &e)
        {
            centerOutput("Invalid choice. Please enter a valid option.");
            return 1;
        }

        // Use a switch statement based on the integer choice
        do
        {
            switch (choice)
            {
            case 1:
                // Code to be executed for option 1
                centerOutput("You selected: Add Animal ");
                centerOutput("-------------------------");
                a.getId();
                a.getName();
                a.getSpecies();
                a.getAge();
                a.getHealthStatus();
                a.saveToFile();
                centerOutput("-------------------------");
                centerOutput("Successfully Add Animal..."); // centerOutput("-------------------------");
                break;
            case 2:
                // Code to be executed for option 2
                centerOutput("You selected: Feed Animal");
                centerOutput("-------------------------");
                f.getFeedingId();
                f.getAnimalId();
                f.getFoodType();
                f.getQuantity();
                f.getFeedingTime();
                f.getFeedingDate();
                f.getFoodCost();
                f.saveToFile(); // Save data to file
                centerOutput("-------------------------");
                centerOutput("Successfully Feed Animal...");
                // centerOutput("-------------------------");
                break;
            case 3:
                // Code to be executed for option 3
                centerOutput("You selected: Display Animal Details:");
                a.loadFromFile();
                break;
            case 4:
                // Code to be executed for option 4
                centerOutput("You selected: Display Feeding Details:");
                f.loadFromFile();
                break;
            case 5:
                // Code to be executed for option 6
                centerOutput("You selected: Calculate Total Cost");
                centerOutput("-------------------------");
                f.cost();
                centerOutput("Total Cost: " + to_string(f.TotalCost));
                centerOutput("-------------------------");
                break;
            case 6:
                // Code to be executed for option 5
                // a.loadFromFile1();
                f.calculateFeedingCost(); // Calculate and display feeding cost
                // f.displayWithCost();
                break;
            case 9:
                a.loadFromFile1();
                break;
            case 8:
                centerOutput("You selected: Exit        ");
                exit(0);
            case 7:
                f.budget(); // f.ct
                break;
            default:
                // Code to be executed if the choice is invalid
                centerOutput("   Invalid choice. Please enter a valid option.");
                break;
            }
            ans = centerInput("   Do you Want to continue...(y/n):");
            centerOutput("   -------------------------------");
        } while (ans == "y");
        ANS = centerInput("         Do you want to Go back to the Home page(y/n):");
        centerOutput("         ----------------------------------------------");
    } while (ANS == "y");
    // Process user input as needed...

    return 0;
};
