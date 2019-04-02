//
//  Advisor.cpp
//  
//
//  Created by Jose Monge on 3/29/19.
//

#include "Advisor.hpp"

class Advisor {
    
private:
    string room;
    string phone_num;
    //vector<Student> advisees;
    
    
public:
    /*
     *  Displays the advisor menu.
     *  Does not handle input
     */
    static void printMenu() {
        
        cout << "========== Menu ==========\n\n";
        cout << " [1] Show all Advisees\n";
        cout << " [2] Search\n";
        cout << " [3] Notes\n";
        cout << " [4] Add Advisee\n";
        cout << " [5] Remove Advisee\n";
        cout << " [6] Move Advisees\n";
        cout << " [7] Search Non-Advisees\n";
        cout << " [8] Show all Advisors\n";
        cout << " [9] Show by Major\n";
        cout << " [0] Quit\n\n";
        cout << "==========================\n\n";
    }
    
    /*
     *  main.cpp should call this function and pass int value
     *  entered by the user.
     *  Advisor handles everything from here and returns to main.cpp
     *  when task is complete
     */
    void handleMenuSelection(int selection) {
        
        switch (selection) {
            case 1:
                printAdviseeList(advisees);
                break;
            case 2:
                search();
                break;
            case 3:
                printNotesMenu();
                break;
            case 4:
                addAdvisee();
                break;
            case 5:
                removeAdvisee();
                break;
            case 6:
                moveAdvisees();
                break;
            case 7:
                searchNonAdvisee();
                break;
            case 8:
                printAdviseeList();
                break;
            case 9:
                showMajorDetails();
                break;
            case 0:
                return;
                break;
            default:
                cout << "Error: Input invalid\n";
        }
    }
    
    /*
     *  Displays detail list of students in given vector.
     *  Should be called by printMenu() to view all advisees
     *  and search() to only show search results
     */
    static void printAdviseeList(vector<Student> advisees) {
        
        //code will go here
    }
    
    /*
     *  Prompts and conducts search.
     *  Should use printAdviseeList() to show results
     */
    void search() {
        
        //code will go here
    }
    
    /*
     *  Handles input
     */
    void printNotesMenu() {
        
        cout << "========== Notes ==========\n\n";
        cout << " [1] View Notes\n";
        cout << " [2] New Note\n";
        cout << " [0] Back/n/n";
        cout << "===========================/n/n";
        
        int selection;
        //I plan to make a method somewhere (maybe in User) that can
        //get user input and validate based on a given range
        //selection = getMenuInput(0, 2);
        
        switch (selection) {
            case 1:
                showNotes();
                break;
            case 2:
                addNote();
                break;
            case 0:
                return;
                break;
            default:
                "Error: input invalid\n";
        }
    }
    
    void showNotes() {
        
        //code will go here
    }
    
    void addNote() {
        
        //code will go here
    }
    
    /*
     *  Prompt for student ID.
     *  Search for student and handle adding them
     */
    void addAdvisee() {
        
        //code will go here
    }
    
    /*
     *  Prompt for student ID.
     *  Search and handle removing them
     *  Don't actually delete student's data jus remove them from
     *  advisee list
     */
    void removeAdvisee() {
        
        //code wil go here
    }
    
    /*
     * Moves students specified by major
     */
    void moveAdvisees() {
        
        //code will go here
    }
    
    /*
     *  Search student by ID that is not on Advisee list.
     *  Should only display name, ID and Advisor
     *  Do not use printAdviseeList()
     */
    void searchNonAdvisee() {
        
        //code will go here
    }
    
    /*
     *  Prints detailed list of all advisors
     */
    static void printAdvisorList() {
        
        //code will go here
    }
    
    /*
     *  Prompts for major.
     *  Displays count and average GPA
     */
    void showMajorDetails() {
        
        //code will go here
    }
};
