#include <iostream>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <string>
#include <cstring>
#include "player.h"
#include "conversationTree.h"
using namespace std;

// CONSTANT
const unsigned int MICROSECONDS = 1000000;
const unsigned short BUILD = 0;
const unsigned short DEXTERITY = 1;
const unsigned short PEOPLE = 2;
const unsigned short INTELLIGENCE = 3;

// FLAGS 
bool has_character = true;

// GLOBAL
char name[50];
char passw[50];
int r;
Player player;

  
// ADDERS
string add_health();
string add_strength();
string add_precision();
string add_agility();
string add_cool();
string add_barter();
string add_science();
string add_engineer();




    // Customize character
    // Present the points you have 3 points available

    // 4 types:
    // Build
    // Dexterity
    // People
    // Intelligence

    // 1 Point gives you 2 point for that specific treat
    // Build
    //      Health
    //      Strength
    // Dexterity
    //      Precision
    //      Agility
    // People
    //      Cool
    //      Barter
    // Intelligence
    //      Science
    //      Engineering

    // For this part the screen will ask you to put a stat in a major
    // Then it will change to the inner which will have 2 points to divide between the two sections

    // Every section will give the player a +10 HP +10 STA
    string build_health[4] = {
        "Improving blood vessel's elasticity...",
        "Optimizing blood oxigenation...",
        "Improving hearth integrity...",
        "Healing damaged blood cells..."
    };

    // Every section will give the player a +10 DMG with Melee and Unarmed
    string build_strength[4] = {
        "Reapiring muscles damage...",
        "Repairing bones damage...",
        "Improving muscle integrity...",
        "Replacing muscles sheath..."
    };

    // Every section will give the player a +10 DMG with guns
    string dex_precision[4] = {
        "Uploading aim software...",
        "Debugging perceptive.us...",
        "Upgrading eye velocity...",
        "Improving eye-hand coordination..."
    };

    // Every section will give the player a +10 in evation
    string dex_agility[4] = {
        "Installing new leg motor...",
        "Repairing foot soles...",
        "Installing improved traction texture...",
        "Adding torque to knees..."
    };

    // Every section will give the player a +10 in charisma
    string people_cool[4] = {
        "Installing acting module...",
        "Improving facial exprecion...",
        "Adding active vocabulary...",
        "Improving color scheme..."
    };

    // Every section will give the player a 2% discount in the store 
    string people_barter[4] = {
        "Adding value module...",
        "Improving money conversion module...",
        "Adding prices are right...",
        "Installing 50 years of antiques row shows knowledge..."
    };

    // Every section will give the player an ability to hack further doors and create new objects
    string int_science[4] = {
        "Adding RAM to memory...",
        "Pushing chemistry book...",
        "Adding a chemical-resistant coat...",
        "Learning hacking fundamentals..."
    };

    // Every section will give the player a +10 Health with sealants and modifiers
    string int_engineer[4] = {
        "Learning motor functionalities...",
        "Reading about dynamic movement...",
        "Everything you need to know about robotics, installed...",
        "Adding double articulated fingers..."
    };



void endl() {
    cout << endl;
}

// Sleep for a period of time in second as given by the argument
void wait(int how_long_in_seconds) {
    usleep(how_long_in_seconds * MICROSECONDS);
}

class Prologue {
    public:
        void play() {
            cout << "The sand burned the soles of their feets." << endl;
            cout << "The sun was at its cusp, its rays attacking the surface of the agent's metalic arms" << endl;
            cout << "Covering the air around with trasparent woobly lines and promises of water." << endl;

            cout << "\n--------------------------------------------\n" << endl;
            cout << "               INCOMING CALL...                 " << endl;
            cout << "\n--------------------------------------------\n" << endl;

            ConversationTree agent_call("Hello Agent! I will need you to visit a house for me.");   

            ConversationTree questioning_branch = agent_call.add_choice(
                "Who are you?", 
                "That is not important",
                "..."
            );

            ConversationTree questioning_branch_press = questioning_branch.add_choice(
                "Press Further",
                "I need to know",
                "You really don't agent"
            );

            questioning_branch_press.add_choice(
                "Accept",
                "Sure, just tell me then",
                "How I said, I need you to go somewhere.\0"
            );

            agent_call.play();
            agent_call.destroy();         
        }
};

void flush() {
    while((getchar()) != '\n');
}


// PROGRAM STRUCTURE
void presentation();
void new_agent();


void add2Stats(unsigned short FLAG, const char* stat);


int main() {
    // presentation();
    Prologue pro;
    pro.play();

    if(r == (int)'A' || r == (int)'a') {
        //new_agent();

        // Play prologue test
        Prologue pro;
        pro.play();


    } else {
        // Fetch file data
        // Call what needs to be called
    }

    return 0;
}




void add2Stats(unsigned short flag, const char* stat) {
    switch(flag) {
        case BUILD:
            if( strcmp(stat, "HEA") == 0 ) {
                cout << "Health Added\n" << endl;
                cout << "\n------------------------------------"<< endl;
                cout << add_health() << endl;
                cout << "------------------------------------\n"<< endl;
                wait(1);

            } else if( strcmp(stat, "STR") == 0 ) {
                cout << "Strength Added\n" << endl;
                cout << "\n------------------------------------"<< endl;
                cout << add_strength() << endl;
                cout << "------------------------------------\n"<< endl;
                wait(1);
            }
            break;
        
        case DEXTERITY:
            if( strcmp(stat, "PRE") == 0 ) {
                cout << "Precision Added\n" << endl;
                cout << "\n------------------------------------"<< endl;
                cout << add_precision() << endl;
                cout << "------------------------------------\n"<< endl;
                wait(1);
            } else if( strcmp(stat, "AGI") == 0 ) {
                cout << "Agility Added\n" << endl;
                cout << "\n------------------------------------"<< endl;
                cout << add_agility() << endl;
                cout << "------------------------------------\n"<< endl;
                wait(1);
            }
            break;

        case PEOPLE:
            if( strcmp(stat, "COO") == 0 ) {
                cout << "Cool Added\n" << endl;
                cout << "\n------------------------------------"<< endl;
                cout << add_cool() << endl;
                cout << "------------------------------------\n"<< endl;
                wait(1);
            } else if( strcmp(stat, "BAR") == 0 ) {
                cout << "Barter Added\n" << endl;
                cout << "\n------------------------------------"<< endl;
                cout << add_barter() << endl;
                cout << "------------------------------------\n"<< endl;
                wait(1);
            }
            break;

        case INTELLIGENCE:
            if( strcmp(stat, "SCI") == 0 ) {
                cout << "Science Added\n" << endl;
                cout << "\n------------------------------------"<< endl;
                cout << add_science() << endl;
                cout << "------------------------------------\n"<< endl;
                wait(1);
            } else if( strcmp(stat, "ENG") == 0 ) {
                cout << "Engineering Added\n" << endl;
                cout << "\n------------------------------------"<< endl;
                cout << add_engineer() << endl;
                cout << "------------------------------------\n"<< endl;
                wait(1);
            }
            break;
    }
}

void presentation() {
    cout << "\n\n--------Welcome to the Bureau of Peace--------" << endl;
    cout << "----------------------------------------------\n"<< endl;
    wait(1);
    cout << "\nEnter your credentials:\n" << endl;
    cout << "Username: ";
    cin.getline(player.private_name, 50);
    cout << "Password: ";
    cin.getline(player.private_passwd, 50);
    endl();
    cout << "loading...\n" << endl;
    wait(1);
    cout << "Welcome " << name << " select what you want to do now." << endl;
    cout << "Write the letter of your option and press enter\n" << endl;


    // Display Menu
    string menu("A) Build a New Agent\n");
    // Only display if the user already has a character
    if( has_character ) {
        menu += "B) Embody Previous Agent\n";
    }

    cout << menu << endl;

    r = getchar();

    while( (r != 97) && (r != 65) && r != (int)'b' && r != (int)'B' )  {
        cout << "Sorry Chumba " <<  (char)r << " is not valid\n" << endl;
        cout << "Try Again\n" << endl;

        flush();
        r = getchar();
    }

    cout << "\n----------- Press Any Button To Continue -----------\n";
    flush();
    getchar();
}


void new_agent() {
    int points = 7;

    cout << "Okay Operator, tell us what kind of modifications " << endl;
    cout << "You want your agent to have." << endl;
    cout << "7 Modification remaining" << endl;
    
    do {
        cout << "\n\n--------Add your points--------\n" << endl;

        cout << "A) Add point to build\n" << endl;
        cout << "B) Add point to dexterity\n" << endl;
        cout << "C) Add point to people\n" << endl;
        cout << "D) Add point to intelligence\n" << endl;

        flush();
        r = getchar();

        switch(r) {
            // A for Build
            case 'A':
            case 'a':          
                do{
                    cout << "\nA) Add point to health" << endl;
                    cout << "B) Add point to strength\n" << endl;
                    flush();
                    r = getchar();
                } while(r != (int)'A' && r != (int)'B');
                
                switch(r) {

                    // A for Health
                    case 'A':
                        if(!player.has_build_health_reached_max_value()) {
                            add2Stats(BUILD, "HEA");
                            cout << --points << " Modification\\s remaining" << endl;
                        } else {
                            cout << "\n!!!!!!!!!!!There are no more upgrades availabe for Health!!!!!!!!!!!!\n" << endl;
                        }
                        break;

                    // B for Strength
                    case 'B':
                        if(!player.has_build_strength_reached_max_value()) {
                            add2Stats(BUILD, "STR");
                            cout << --points << " Modification\\s remaining" << endl;
                        } else {
                            cout << "\n!!!!!!!!!!!There are no more upgrades availabe for Strength!!!!!!!!!!!!\n" << endl;

                        }
                        break;
                }

                break;


            // B for Dexterity
            case 'B':
            case 'b':
                do{
                    cout << "\nA) Add point to Precision" << endl;
                    cout << "B) Add point to Agility\n" << endl;
                    flush();
                    r = getchar();
                } while(r != (int)'A' && r != (int)'B');

                switch(r) {

                    // A for Precision
                    case 'A':
                        if(!player.has_dexterity_perception_reached_max_value()) {
                            add2Stats(DEXTERITY, "PRE");
                            cout << --points << " Modification\\s remaining" << endl;
                        } else {
                            cout << "\n!!!!!!!!!!!There are no more upgrades availabe for Precision!!!!!!!!!!!!\n" << endl;
                        }
                        break;

                    // B for Agility
                    case 'B':
                        if(!player.has_dexterity_agility_reached_max_value()) {
                            add2Stats(DEXTERITY, "AGI");
                            cout << --points << " Modification\\s remaining" << endl;
                        } else {
                            cout << "\n!!!!!!!!!!!There are no more upgrades availabe for Agility!!!!!!!!!!!!\n" << endl;
                        }
                        break;

                }

            break;



            // C for People
            case 'C':
            case 'c':
                do{
                    cout << "\nA) Add point to Cool" << endl;
                    cout << "B) Add point to Barter\n" << endl;
                    flush();
                    r = getchar();
                } while(r != (int)'A' && r != (int)'B');

                switch(r) {

                    // A for Cool
                    case 'A':
                        if(!player.has_people_cool_reached_max_value()) {
                            add2Stats(PEOPLE, "COO");
                            cout << --points << " Modification\\s remaining" << endl;
                        } else {
                            cout << "\n!!!!!!!!!!!There are no more upgrades availabe for Cool!!!!!!!!!!!!\n" << endl;
                        }
                        break;

                    // B for Barter
                    case 'B':
                        if(!player.has_people_barter_reached_max_value()) {
                            add2Stats(PEOPLE, "BAR");
                            cout << --points << " Modification\\s remaining" << endl;
                        } else {
                            cout << "\n!!!!!!!!!!!There are no more upgrades availabe for Barter!!!!!!!!!!!!\n" << endl;
                        }
                        break;
                }

            break;



            // D for Intelligence
            case 'D':
            case 'd':
                do{
                    cout << "\nA) Add point to Science" << endl;
                    cout << "B) Add point to Engineer\n" << endl;
                    flush();
                    r = getchar();
                } while(r != (int)'A' && r != (int)'B');

                switch(r) {

                    // A for Science
                    case 'A':
                        if(!player.has_intelligence_science_reached_max_value()) {
                            add2Stats(INTELLIGENCE, "SCI");
                            cout << --points << " Modification\\s remaining" << endl;
                        } else {
                            cout << "\n!!!!!!!!!!!There are no more upgrades available for Science!!!!!!!!!!!!\n" << endl;
                        }
                        break;

                    // B is for Engineer
                    case 'B':
                        if(!player.has_intelligence_engineering_reached_max_value()) {
                            add2Stats(INTELLIGENCE, "ENG");
                            cout << --points << " Modification\\s remaining" << endl;
                        } else {
                            cout << "\n!!!!!!!!!!!There are no more upgrades availabe for Engineering!!!!!!!!!!!!\n" << endl;
                        }
                        break;
                }

            break;

        }

    } while(points > 0);

    wait(1);
    cout << "-----Your agent has been deployed in initial location. Press 'x' to posess-----\n" << endl;
    flush();
    r = getchar();

    while(r != 'x' && r != 'X') {
        flush();
        r = getchar();
    }

    cout << "Ready in 3 seconds..." << endl;
    wait(1);
    cout << "Ready in 2 seconds..." << endl;
    wait(1);
    cout << "Ready in 1 second...\n\n" << endl;
    wait(1);
}


// STAT ADDERS

string add_health() {
    return build_health[player.increase_build_health_by_one()];
}

string add_strength() {
    return build_strength[player.increase_build_strength_by_one()];
}

string add_precision() {
    return dex_precision[player.increase_dexterity_perception_by_one()];
}
string add_agility() {
    return dex_agility[player.increase_dexterity_agility_by_one()];
}
string add_cool() {
    return people_cool[player.increase_people_cool_by_one()];
}
string add_barter() {
    return people_barter[player.increase_people_barter_by_one()];
}
string add_science() {
    return int_science[player.increase_intelligence_science_by_one()];
}
string add_engineer() {
    return int_engineer[player.increase_intelligence_engineering_by_one()];
}
