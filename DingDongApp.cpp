/*  
 * Author: GAslanidis
 *  
 * Open Source Certification:  
 * This project is released under the MIT License.  
 * You are free to reuse, modify, and distribute the code  
 * with proper attribution.  
 *
 */


#include <iostream>
#include <limits>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>

using namespace std;

// struct to hold each influencer and its attributes as members
struct Influencer{
    
    string name;
    string surname;
    string origin;
    char sex;
    int followers;
    int posts;
    int views;
    int engagements;
    int likes;
    int comments;
    int shares;
    double metric;
    double viewsPerPost;
    double engagePerPost;
    double likesPerPost;
    double commentsPerPost;
    double sharesPerPost;
};

// Menu
void displayMenu();
void displayInfluencerDetails(Influencer inf[], int size, bool fileRead);
int getChoice();
void runOption(int& choice, bool& fileRead, bool& hasCalculated, Influencer inf[], int MAX_INFLUENCERS);

// Option 1
void option1(string filename, Influencer inf[], int size, bool& fileRead);
void readFile(string filename, Influencer inf[], int size);
void displayInf(Influencer inf[], int size);

// Option 2
void option2(Influencer inf[], int size, bool& hasCalculated);
void calculatePerPostValues(Influencer inf[], int size, bool& hasCalculated);
void displayPerPostValues(Influencer inf[], int size);

// Option 3
void option3(double limit, Influencer inf[], int size);
double getLimit();
void calculateLKSPerPost(double limit, Influencer inf[], int size, vector<Influencer>& vecInf);
void printInfluencers(vector<Influencer>& vecInf);
void bubbleSort(vector<Influencer>& vecInf);

// Option 4
void option4(Influencer inf[], int size);
double metric(Influencer inf);
void writeFile(string filename, Influencer inf[], int size);
void readFileMetric(string filename, vector<Influencer>& vecInf);
void bubbleSortMetric(vector<Influencer>& vecInf);
void displaySortedByMetric(vector<Influencer> vecInf);

// Option 5
void option5(Influencer inf[], int size, bool hasCalculated);
void promtUserFilter(int& sortField, int& sortOrder);
void readFilePerPostValues(string filename, Influencer inf[], int size, bool hasCalculated, vector<Influencer>& vecInf);
void sortByMetric(vector<Influencer>& vecInf, int sortField, int sortOrder);
void displaySortedByUserFilter(vector<Influencer> vecInf);
void writeFileSortedStats(string filename, vector<Influencer> vecInf);

// Option 6
void option6(Influencer inf[], int size);
void calculateGenderStats(Influencer inf[], int size, int& maleCount, int& femaleCount, double& avgMaleMetric, double& avgFemaleMetric);
void displayGenderStats(int maleCount, int femaleCount, double avgMaleMetric, double avgFemaleMetric);

// Option 7
void option7(Influencer inf[], int size);
string capitalizeFirstLetter(string surname);
    
    
//MAIN__________________________________________________________________________
int main() {
    
    int choice;                         // User's choice for menu
    bool fileRead = false;              // File containing data is read
    const int MAX_INFLUENCERS = 12;     // Array Size - Change this to the amount of influencers
    Influencer inf[MAX_INFLUENCERS];    // Initialize Influencer array
    bool hasCalculated = false;         // To know if per post values have been caluclated
    
    while (choice != -1) {
        
        choice = 100;   // Re-initialize with some value (because "0" is for exiting the program)
        
        displayInfluencerDetails(inf, MAX_INFLUENCERS, fileRead);           // Display will only take place after 
                                                                            //the file has been read at least once
        
        displayMenu();                                                      // Prompt user to give input
        choice = getChoice();                                               // Get Users Choice
        runOption(choice, fileRead, hasCalculated, inf, MAX_INFLUENCERS);   //Run the Option that the User Chose
    }
    
    return 0;
}

//END OF MAIN___________________________________________________________________


//FUNCTIONS_____________________________________________________________________

//-----------------------------------MENU---------------------------------------

// Menu
// Get User Menu choice
int getChoice(){
    
    int choice = 0;
    
    while(true){
        
        cin >> choice;  // Save the choice
            
        // ERROR TRAPPING_______________________________________________________
        cin.sync();
            
        // If input type is invalid 
        if (cin.fail()) {
                
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number between 1 and 6.\n\n";
                
            cin.sync();
        }
        // In case input is of valid type, but there is no such option
        else if (choice < 0 || choice > 7) {
                
            cout << "Invalid choice, please enter a number between 1 and 6.\n\n";
        }
        else{
                
            break;
        }
    }
    
    return choice;
}

// Menu
// To Run an Option Based on User's Choice
void runOption(int& choice, bool& fileRead, bool& hasCalculated, Influencer inf[], int MAX_INFLUENCERS){
    

    // IF choice = 7, exit program
    if (choice == 0) {
            
        cout << "Exiting program.\n";
            
        choice = -1;    // Choice is passed by reference 
                        // Thus it going to change in the main() and exit the program
    }
        
    if (choice == 1) {
            
        option1("social_media_contest_data", inf, MAX_INFLUENCERS, fileRead);
    } 
    else if (choice == 2) {
            
        if (!fileRead) {
                
            cout << "\nPlease read the file first before using this option.\n";
            cout << "Run Option 1!\n\n";
        }
        else{
                
            option2(inf, MAX_INFLUENCERS, hasCalculated);
        }
    } 
    else if (choice == 3) {
            
        if (!fileRead) {
                
            cout << "\nPlease read the file first before using this option.\n";
            cout << "Run Option 1!\n\n";
        }
        else{
                
            option3(getLimit(), inf, MAX_INFLUENCERS);
        }
    } 
    else if (choice == 4) {
            
        if (!fileRead) {
                
            cout << "\nPlease read the file first before using this option.\n";
            cout << "Run Option 1!\n\n";
        }
        else{
                
            option4(inf, MAX_INFLUENCERS);
        }
    } 
    else if (choice == 5) {
            
        if (!fileRead) {
                
            cout << "\nPlease read the file first before using this option.\n";
            cout << "Run Option 1!\n\n";
        }
        else{
                
            option5(inf, MAX_INFLUENCERS, hasCalculated);
        }
    }
    else if (choice == 6) {
            
        if (!fileRead) {
                
            cout << "\nPlease read the file first before using this option.\n";
            cout << "Run Option 1!\n\n";
        }
        else{
             
            option6(inf, MAX_INFLUENCERS);
        }
    }
    else if (choice == 7) {
            
        if (!fileRead) {
                
            cout << "\nPlease read the file first before using this option.\n";
            cout << "Run Option 1!\n\n";
        }
        else{
             
            option7(inf, MAX_INFLUENCERS);
        }
    }
}

// Menu
// Menu Display
void displayMenu() {
    
    cout << "===============================================\n";
    cout << "USER MENU: SOCIAL MEDIA CONTEST DATA STATISTICS\n";
    cout << "===============================================\n";
    cout << "1. Read and display contest stats for the 12 finalists\n";
    cout << "2. Calculate and display per post data values\n";
    cout << "3. Filter and sort data by likes/post\n";
    cout << "4. Display sorted data based on a novel performance metric\n";
    cout << "5. Parametrized sorting, display and saving of processed data\n";
    cout << "6. Compare Men's & Women's Metrics\n";
    cout << "7. Search Participant By Surname\n";
    cout << "0. Exit the program\n";
    cout << "Enter your choice: ";
}

// Menu 
// Display Basic Data on Influencers
void displayInfluencerDetails(Influencer inf[], int size, bool fileRead) {
    
    // If file containing that data has been read, then display the basic of the influencers
    if(fileRead == true){
        
        cout << "Name    | Surname  | Origin  | Sex | Followers | Posts | Views | Engagements | Likes | Comments | Shares\n";
        cout << "----------------------------------------------------------------------------------------------------------\n";
        
        for (int i = 0; i < size; i++) {
            
            cout << inf[i].name << " | "
                 << inf[i].surname << " | "
                 << inf[i].origin << " | "
                 << inf[i].sex << " | "
                 << inf[i].followers << " | "
                 << inf[i].posts << " | "
                 << inf[i].views << " | "
                 << inf[i].engagements << " | "
                 << inf[i].likes << " | "
                 << inf[i].comments << " | "
                 << inf[i].shares << endl;
        }
        
        cout << endl;
    }
}


//-------------------------------OPTION 1---------------------------------------

// Option 1 
void option1(string filename, Influencer inf[], int size, bool& fileRead){
    
    // Reads the file
        // Fills an array with Influencer structs
        readFile(filename, inf, size); 
        fileRead = true;    // This variable is passed by reference
                            // Thus it going to change in the main() and exit the program
                            // Now the program will know that the file has been read
            
        // Displays the array
        displayInf(inf, size);
}

// Option 1
// Influencer Array display
void displayInf(Influencer inf[], int size){

    for(int i=0; i<size; i++){
        
        // Delete or add slashes "/" to display specific data
        cout //<< inf[i].name << " "
             << inf[i].surname << " "
             //<< inf[i].origin << " "
             //<< inf[i].sex << " "
             << inf[i].followers << " "
             << inf[i].posts << " "
             << inf[i].views << " "
             << inf[i].engagements << " "
             << inf[i].likes << " "
             << inf[i].comments << " "
             << inf[i].shares << "\n";
    }
    
    cout << endl;
}


// Option 1
// Read .txt File for Basic Influencer Struct
void readFile(string filename, Influencer inf[], int size){
    
    ifstream readMyFile;
    string line = "";
    string filenameTxt = filename + ".txt";
    int counter = 0;
    
    readMyFile.open(filenameTxt.c_str());   // Open the file
    
    if (readMyFile.fail()) {
        
        cerr << "Error opening input file " << filename << endl;
        exit(1);
    }
    
    // Skip the line with titles
    getline(readMyFile, line);
    
    while(getline(readMyFile, line) && counter < size){
        
        Influencer influencer;  // Initialize a new Influencer struct
        stringstream ss(line);  // Tokenize and assign values from the string
        
        ss >> influencer.name
           >> influencer.surname
           >> influencer.origin
           >> influencer.sex
           >> influencer.followers
           >> influencer.posts
           >> influencer.views
           >> influencer.engagements
           >> influencer.likes
           >> influencer.comments
           >> influencer.shares;
           
        inf[counter] = influencer;  // Save the influencer inside the array
        counter++;                  // Increment counter
    }

    readMyFile.close();
    
    cout << "\nFile Read!" << endl
         << "Influencers Succesfully Initialized!\n\n";
}

//----------------------------END OF OPTION 1-----------------------------------


//-------------------------------OPTION 2---------------------------------------

// Option 2 
void option2(Influencer inf[], int size, bool& hasCalculated){
    
    calculatePerPostValues(inf, size, hasCalculated);
    displayPerPostValues(inf, size);
}

// Option 2
// Calculates the per post Values
void calculatePerPostValues(Influencer inf[], int size, bool& hasCalculated){
    
    for(int i=0; i<size; i++){
        
        inf[i].viewsPerPost = (double)inf[i].views/(double)inf[i].posts;
        inf[i].engagePerPost = (double)inf[i].engagements/(double)inf[i].posts;
        inf[i].likesPerPost = (double)inf[i].likes/(double)inf[i].posts;
        inf[i].commentsPerPost = (double)inf[i].comments/(double)inf[i].posts;
        inf[i].sharesPerPost = (double)inf[i].shares/(double)inf[i].posts;
    }
    
    hasCalculated = true;
}

// Option 2
// Diplays Per Porst Values
void displayPerPostValues(Influencer inf[], int size) {
    
    cout << endl;
    cout << "SURNAME VIW/PST ENG/PST LIK/PST CMT/PST SHR/PST\n";
    
    for (int i = 0; i < size; i++) {
        
        // Calculations are done inside an if statement (case?true:false)
        // to avoid division by 0
        // Set output to fixed-point notation (fixed) and the precision to 2 decimal points
        cout << inf[i].surname << " "
             << fixed << setprecision(2) 
             << (inf[i].posts ? (double)inf[i].views / inf[i].posts : 0) << " "
             << (inf[i].posts ? (double)inf[i].engagements / inf[i].posts : 0) << " "
             << (inf[i].posts ? (double)inf[i].likes / inf[i].posts : 0) << " "
             << (inf[i].posts ? (double)inf[i].comments / inf[i].posts : 0) << " "
             << (inf[i].posts ? (double)inf[i].shares / inf[i].posts : 0) << "\n";
    }
    
    cout << endl;
}

//--------------------------- END OF OPTION 2-----------------------------------


//-------------------------------OPTION 3---------------------------------------

// Option 3
// Encapulation - Handles All Operations (Functions) for Option 3
void option3(double limit, Influencer inf[], int size){
    
    vector<Influencer> vecInf; // Create a temporary filtered vector 
                               // (because size of the filtered array is not known yet)
                               
    calculateLKSPerPost(limit, inf, size, vecInf);
    bubbleSort(vecInf);         // Sort influencers based on LIKES/POST descending
    printInfluencers(vecInf); // Display influencers vector
}

// Option 3
// Get likes per post limit
double getLimit(){
    
    double limit=0.0;

    // Prompt user to give a LIKES/POST Limit
    while (true) {
                
        cout << "Enter LIKES/POST Limit: ";
        cin >> limit;
        
        // Error trapping for invalid input type
        if (cin.fail()) {
            
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore bad input
            cout << "Invalid input!\n";
        }
        else{
            
            break;
        }
    }
    
    return limit;
}

// Option 3
// Diplays Influencers Filtered on a Likes/Post limit
void calculateLKSPerPost(double limit, Influencer inf[], int size, vector<Influencer>& vecInf){
    
    for(int i=0; i<size; i++){
        
        // Save likesPerPost
        // If user has posts : then (double)inf[i].likes / inf[i].posts : else 0
        double likesPerPost = (inf[i].posts ? (double)inf[i].likes / inf[i].posts : 0);
        
        // Check if it is greater or equal to limit
        if(likesPerPost >= limit){
            
            vecInf.push_back(inf[i]); 
        }
    }
}

// Option 3
//Bubble Sort (descending order) for Posts
void bubbleSort(vector<Influencer>& influencers) {
    
    int n = influencers.size();

    // Bubble sort algorithm
    for (int i = 0; i < n - 1; ++i) {
        
        for (int j = 0; j < n - 1 - i; ++j) {
            
            // Calculate likes per post for comparison
            double likesPerPost1 = (influencers[j].posts ? (double)influencers[j].likes / influencers[j].posts : 0);
            double likesPerPost2 = (influencers[j + 1].posts ? (double)influencers[j + 1].likes / influencers[j + 1].posts : 0);

            // Compare based on likes per post
            if (likesPerPost1 < likesPerPost2) {
                
                // Swap influencers if out of order
                swap(influencers[j], influencers[j + 1]);
            }
        }
    }
}

// Option 3
// Function to display filtered influencers (Vector)
void printInfluencers(vector<Influencer>& influencers) {
    
    if (influencers.empty()) {
        cout << "No influencers to display." << endl;
        return;
    }
    
    cout << endl;
    cout << "Name    | Surname  | Origin  | Sex | Likes/Post\n";
    cout << "----------------------------------------------\n";
    
    for (auto& inf : influencers) {
        
        double likesPerPost = (inf.posts ? (double)inf.likes / inf.posts : 0);
        
        cout << inf.name << " | " 
             << inf.surname << " | " 
             << inf.origin << " | " 
             << inf.sex << " | " 
             << fixed << setprecision(2) 
             << likesPerPost << "\n";
    }
    
    cout << endl;
}

//----------------------------END OF OPTION 3-----------------------------------


//-------------------------------OPTION 4---------------------------------------

// Option 4
// Encapulation - Handles All Operations (Functions) for Option 4
void option4(Influencer inf[], int size){
    
    vector<Influencer> vecInf;
    
    writeFile("social_media_contest_processed_data", inf, size);
    readFileMetric("social_media_contest_processed_data", vecInf);
    bubbleSortMetric(vecInf);
    displaySortedByMetric(vecInf);
}

// Option 4
// Display the temporary vector with Metric descending
void displaySortedByMetric(vector<Influencer> influencers) {

    if (influencers.empty()) {
        cout << "No influencers to display." << endl;
        return;
    }
    
    // Display the sorted influencers
    cout << "Name    | Surname  | Origin  | Sex | Metric\n";
    cout << "----------------------------------------------\n";
    for (const auto& inf : influencers) {
        cout << inf.name << " | "
             << inf.surname << " | "
             << inf.origin << " | "
             << inf.sex << " | "
             << fixed << setprecision(2) 
             << inf.metric
             << "\n";
    }
    cout << endl;
}

// Option 4
// Performance Metric Calculation
double metric(Influencer inf){
    
    double influence = 0.0;
    
    // Calculation of metric by "weight" addition
    // Followers have greater weight, than any other statistic
    return influence = 0.3*((double)inf.followers
                       +0.2*(double)inf.views
                       +0.2*(double)inf.engagements
                       +0.1*(double)inf.likes
                       +0.1*(double)inf.comments
                       +0.1*(double)inf.shares)
                       /((double)inf.posts+1);
}

// Option 4
//Bubble Sort (descending order) for Metric
void bubbleSortMetric(vector<Influencer>& influencers) {
    
    int n = influencers.size();

    // Bubble sort algorithm
    for (int i = 0; i < n - 1; ++i) {
        
        for (int j = 0; j < n - 1 - i; ++j) {

            // Compare based on likes per post
            if (influencers[j].metric < influencers[j+1].metric) {
                
                // Swap influencers if out of order
                swap(influencers[j], influencers[j + 1]);
            }
        }
    }
}

// Option 4
// Write to file
void writeFile(string filename, Influencer inf[], int size){
    
    ofstream MyFile(filename + ".txt");
    
    // Set format flags
    MyFile.setf(ios::fixed);
    MyFile.setf(ios::showpoint);
    MyFile.precision(2);
    
    // Write the titles to file first
    MyFile << "Name" << "\t"
           << "Surname" << "\t"
           << "Origin" << "\t"
           << "Sex" << "\t"
           << "Followers" << "\t"
           << "Posts" << "\t"
           << "Views" << "\t"
           << "Engagements" << "\t"
           << "Likes" << "\t"
           << "Comments" << "\t"
           << "Shares"
           << endl;
           
    for(int i=0; i<size; i++){
        
        MyFile << inf[i].name << "\t"
               << inf[i].surname << "\t"
               << inf[i].origin << "\t"
               << inf[i].sex << "\t"
               << inf[i].followers << "\t"
               << inf[i].posts << "\t"
               << inf[i].views << "\t"
               << inf[i].engagements << "\t"
               << inf[i].likes << "\t"
               << inf[i].comments << "\t"
               << inf[i].shares << "\t"
               << metric(inf[i])
                << endl;
                         
        // cout << inf[i].name << " wrote to file with metric " << metric(inf[i].followers,
        //                                                                  inf[i].posts,
        //                                                                  inf[i].views,
        //                                                                  inf[i].engagements,
        //                                                                  inf[i].likes,
        //                                                                  inf[i].comments,
        //                                                                  inf[i].shares) << endl;
    }
    
    cout << endl;
    cout << "File Created Succesfully!\n" << endl;
    
    MyFile.close();
}

// Option 4
// Read File with NEW (metric)
void readFileMetric(string filename, vector<Influencer>& vecInf){
    
    ifstream readMyFile;
    string line = "";
    string filenameTxt = filename + ".txt";
    
    readMyFile.open(filenameTxt.c_str());   // Open the file
    
    if (readMyFile.fail()) {
        cerr << "Error opening input file " << filename << endl;
        exit(1);
    }
    
    // Skip titles line
    getline(readMyFile, line);
    
    while(getline(readMyFile, line)){
        
        Influencer influencer;  // Initialize a new Influencer struct
        stringstream ss(line);  // Tokenize and assign values from the string
        string temp;            // To save values that I dont need to be read (trash)
        
        ss >> influencer.name
           >> influencer.surname
           >> influencer.origin
           >> influencer.sex
           >> temp
           >> temp
           >> temp
           >> temp
           >> temp
           >> temp
           >> temp
           >> influencer.metric;
           
        vecInf.push_back(influencer);
    }
    
    readMyFile.close();
}

//----------------------------END OF OPTION 4-----------------------------------


//-------------------------------OPTION 5---------------------------------------

// Option 5
// Encapulation - Handles All Operations (Functions) for Option 5
void option5(Influencer inf[], int size, bool hasCalculated){
    
    int sortField=0;
    int sortOrder=0;
    vector<Influencer> vecInf;
    
    promtUserFilter(sortField, sortOrder);
    readFilePerPostValues("social_media_contest_data", inf, size, hasCalculated, vecInf);
    sortByMetric(vecInf, sortField, sortOrder);
    displaySortedByUserFilter(vecInf);
    writeFileSortedStats("social_media_sorted_stats", vecInf);
}

// Option 5
// Promt user to choose sorting filters
void promtUserFilter(int& sortField, int& sortOrder){
    
    // Display options for sorting fields
    cout << "\n=== SORT BY FIELD ===\n";
    cout << "Press 1 - Views per post (VIW/PST)\n";
    cout << "Press 2 - Engagements per post (ENG/PST)\n";
    cout << "Press 3 - Likes per post (LIK/PST)\n";
    cout << "Press 4 - Comments per post (CMT/PST)\n";
    cout << "Press 5 - Shares per post (SHR/PST)\n";
    cout << "Press 6 - Performance metric (NEW)\n";
    
    // Get the field to sort by
    while (true) {
        
        cout << "Enter your choice (1-6): ";
        cin >> sortField;
        
        // Error trapping for invalid input type
        if (cin.fail()) {
            
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore bad input
            cout << "Invalid input! Please enter a number between 1 and 6.\n";
        }
        else if (sortField < 1 || sortField > 6) {
            
            cout << "Invalid choice! Please enter a number between 1 and 6.\n";
        }
        else {
            
            break;
        }
    }
    
    // Display options for sort order
    cout << "\n=== SORT ORDER ===\n";
    cout << "Press 1 - Ascending (lowest to highest)\n";
    cout << "Press 2 - Descending (highest to lowest)\n";
    
    // Get sort order
    while (true) {
        
        cout << "Enter your choice (1-2): ";
        cin >> sortOrder;
        
        // Error trapping for invalid input type
        if (cin.fail()) {
            
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore bad input
            cout << "Invalid input! Please enter 1 for ascending or 2 for descending.\n";
        }
        else if (sortOrder < 1 || sortOrder > 2) {
            
            cout << "Invalid choice! Please enter 1 for ascending or 2 for descending.\n";
        }
        else {
            
            break;
        }
    }
}

// Option 5
// Read .txt File and Calculate All Per Post Values
void readFilePerPostValues(string filename, Influencer inf[], int size, bool hasCalculated, vector<Influencer>& vecInf){
    
    ifstream readMyFile;
    string line = "";
    string filenameTxt = filename + ".txt";
    int counter = 0;
    
    readMyFile.open(filenameTxt.c_str());   // Open the file
    
    if (readMyFile.fail()) {
        
        cerr << "Error opening input file " << filename << endl;
        exit(1);
    }
    
    // Skip the line with titles
    getline(readMyFile, line);
    
    while(getline(readMyFile, line) && counter < size){
        
        Influencer influencer;  // Initialize a new Influencer struct
        stringstream ss(line);  // Tokenize and assign values from the string
        string temp;            // to tash data we dont need
        
        int posts;
        int views;
        int engagements;
        int likes;
        int comments;
        int shares;
        
        ss >> temp
           >> temp
           >> temp
           >> temp
           >> temp
           >> posts
           >> views
           >> engagements
           >> likes
           >> comments
           >> shares;
           
        // To avoid division by 0
        if(inf[counter].posts != 0){
            
            // If per post values have been calculated in option 2
            // then proceed to calculate them 
            if(hasCalculated==false){
                
                inf[counter].viewsPerPost = (double)views/(double)posts;
                inf[counter].engagePerPost = (double)engagements/(double)posts;
                inf[counter].likesPerPost = (double)likes/(double)posts;
                inf[counter].commentsPerPost = (double)comments/(double)posts;
                inf[counter].sharesPerPost = (double)shares/(double)posts;
                
                //Un-comment to validate program checks correctly
                //cout << "Calculating values" << endl;
            }
            
            // If metric has not yet been calculated
            if(inf[counter].metric == 0){

                inf[counter].metric = metric(inf[counter]);
            }
        }
        
        vecInf.push_back(inf[counter]); // To be passed on to the sorting function
        
        counter++;                  // Increment counter
    }

    readMyFile.close();
    
    cout << "\nFile Read!" << endl
         << "Influencers Succesfully Initialized!\n\n";
}

// Option 5
// Sorts influencers based on user selection
void sortByMetric(vector<Influencer>& influencers, int sortField, int sortOrder) {
    
    int n = influencers.size();
    
    for (int i = 0; i < n - 1; ++i) {
        
        for (int j = 0; j < n - 1 - i; ++j) {
            
            double value1 = 0.0;
            double value2 = 0.0;
            
            // Determine which field to sort by
            // "VIW/PST"
            if (sortField == 1) {
                
                value1 = influencers[j].viewsPerPost;
                value2 = influencers[j + 1].viewsPerPost;
            } 
            // "ENG/PST"
            else if (sortField == 2) {
                
                value1 = influencers[j].engagePerPost;
                value2 = influencers[j + 1].engagePerPost;
            } 
            // "LIK/PST"
            else if (sortField == 3) {
                
                value1 = influencers[j].likesPerPost;
                value2 = influencers[j + 1].likesPerPost;
            } 
            // "CMT/PST"
            else if (sortField == 4) {
                
                value1 = influencers[j].commentsPerPost;
                value2 = influencers[j + 1].commentsPerPost;
            } 
            // "SHR/PST"
            else if (sortField == 5) {
                
                value1 = influencers[j].sharesPerPost;
                value2 = influencers[j + 1].sharesPerPost;
            } 
            // "NEW"
            else if (sortField == 6) {
                
                value1 = influencers[j].metric;
                value2 = influencers[j + 1].metric;
                
                // Store the calculated metric for later use
                influencers[j].metric = value1;
                influencers[j + 1].metric = value2;
            }
            
            if (sortOrder == 1) {
                
                if(value1 > value2) 
                    swap(influencers[j], influencers[j + 1]);
            }
            else if (sortOrder == 2) {
                
                if(value1 < value2)
                    swap(influencers[j], influencers[j + 1]);
            }
        }
    }
}

// Option 5
// Display the temporary vector with user selected filters
void displaySortedByUserFilter(vector<Influencer> vecInf) {

    if (vecInf.empty()) {
        
        cout << "No influencers to display." << endl;
        return;
    }
    
    // Display the sorted influencers
    cout << "Name    | VIW/PST  | ENG/PST  | LIK/PST | CMT/PST | SHR/PST | NEW\n";
    cout << "-------------------------------------------------------------\n";
    cout << fixed << setprecision(2);
    
    for (const auto& inf : vecInf) {
        
        cout << inf.name << " | "
             << inf.viewsPerPost << " | "
             << inf.engagePerPost << " | "
             << inf.likesPerPost << " | "
             << inf.commentsPerPost << " | "
             << inf.sharesPerPost << " | "
             << inf.metric
             << fixed << setprecision(2) 
             << "\n";
    }
    cout << endl;
}

// Option 5
// Write to file
void writeFileSortedStats(string filename, vector<Influencer> vecInf){
    
    ofstream MyFile(filename + ".txt");
    
    // Set format flags
    MyFile.setf(ios::fixed);
    MyFile.setf(ios::showpoint);
    MyFile.precision(2);
    
    // Write the titles to file first
    MyFile << "Name" << "\t"
           << "VIW/PST" << "\t"
           << "ENG/PST" << "\t"
           << "LIK/PST" << "\t"
           << "CMT/PST" << "\t"
           << "SHR/PST" << "\t"
           << "NEW" << "\t"
           << endl;
           
    for (const auto& inf : vecInf) {
        
        MyFile << inf.name << "\t"
             << inf.viewsPerPost << "\t"
             << inf.engagePerPost << "\t"
             << inf.likesPerPost << "\t"
             << inf.commentsPerPost << "\t"
             << inf.sharesPerPost << "\t"
             << inf.metric
             << "\n";
    }
    
    cout << endl;
    cout << "File Created Succesfully!\n" << endl;
    
    MyFile.close();
}

//----------------------------END OF OPTION 5-----------------------------------


//-------------------------------OPTION 6---------------------------------------

// Option 6 
// Encapulation - Handles All Operations (Functions) for Option 6
void option6(Influencer inf[], int size) {
    
    int maleCount = 0;
    int femaleCount = 0;
    double avgMaleMetric = 0.0;
    double avgFemaleMetric = 0.0;
    
    calculateGenderStats(inf, size, maleCount, femaleCount, avgMaleMetric, avgFemaleMetric);
    displayGenderStats(maleCount, femaleCount, avgMaleMetric, avgFemaleMetric);
}

// Option 6
// Calculate statistics based on gender
void calculateGenderStats(Influencer inf[], int size, int& maleCount, int& femaleCount, double& avgMaleMetric, double& avgFemaleMetric) {
    
    double totalMaleMetric = 0.0, totalFemaleMetric = 0.0;
    
    for (int i = 0; i < size; i++) {
        if (inf[i].sex == 'M' || inf[i].sex == 'm') {
            maleCount++;
            totalMaleMetric += metric(inf[i]);
        } else if (inf[i].sex == 'F' || inf[i].sex == 'f') {
            femaleCount++;
            totalFemaleMetric += metric(inf[i]);
        }
    }
    
    avgMaleMetric = (maleCount > 0) ? totalMaleMetric / maleCount : 0;
    avgFemaleMetric = (femaleCount > 0) ? totalFemaleMetric / femaleCount : 0;
}

// Option 6
// Display gender-based statistics
void displayGenderStats(int maleCount, int femaleCount, double avgMaleMetric, double avgFemaleMetric) {
    
    cout << "\nGender Statistics:\n";
    cout << "-----------------------------------\n";
    cout << "Total Male Candidates: " << maleCount << "\n";
    cout << "Total Female Candidates: " << femaleCount << "\n";
    cout << "Average Performance Metric (Male): " << fixed << setprecision(2) << avgMaleMetric << "\n";
    cout << "Average Performance Metric (Female): " << fixed << setprecision(2) << avgFemaleMetric << "\n";
    cout << "-----------------------------------\n\n";
}

//----------------------------END OF OPTION 6-----------------------------------

//-------------------------------OPTION 7---------------------------------------

// Option 7
// Seacrh user by their surname
void option7(Influencer inf[], int size){
    
    bool found = false;
    string surname = "";
    
    cout << "Search for Surname: " << endl;
    cin >> surname;

    cout << "\nSearch Results for '" << surname << "':\n";
    cout << "-----------------------------------------------\n";
    
    surname = capitalizeFirstLetter(surname);

    for (int i = 0; i < size; i++) {
        
        if (inf[i].surname == surname) {
            
            found = true;
            
            cout << "Name: " << inf[i].name << "\n"
                 << "Surname: " << inf[i].surname << "\n"
                 << "Origin: " << inf[i].origin << "\n"
                 << "Sex: " << inf[i].sex << "\n"
                 << "Followers: " << inf[i].followers << "\n"
                 << "Posts: " << inf[i].posts << "\n"
                 << "Views: " << inf[i].views << "\n"
                 << "Engagements: " << inf[i].engagements << "\n"
                 << "Likes: " << inf[i].likes << "\n"
                 << "Comments: " << inf[i].comments << "\n"
                 << "Shares: " << inf[i].shares << "\n"
                 << "-----------------------------------------------\n\n";
        }
    }

    if (!found) {
        
        cout << "No influencer found with last name '" << surname << "'.\n\n";
    }
}

// Option 7
// This function ensures that when a user searches for an influencer by last name (surname)
// their input is formatted exactly the same way as the names stored in the .txt file
// This avoids issues where mismatches occur due to differences in capitalization.
string capitalizeFirstLetter(string surname) {
    
    if (surname.empty()) {
    
        return surname; // Return empty string if input is empty
    }

    // Convert the first character to uppercase
    surname[0] = toupper(surname[0]);

    // Convert the rest of the characters to lowercase
    for (int i = 1; i < surname.length(); i++) {
        
        surname[i] = tolower(surname[i]);
    }

    return surname;
}

//----------------------------END OF OPTION 7-----------------------------------


// END OF PROGRAM





