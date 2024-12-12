#include <iostream>
#include <cmath> // For std::exp
#include <vector>
#include <ncurses.h>

#define EPSILON_0 8.854187817e-12
using namespace std;
    
    struct Material {
        string name;
        float epsilon_r_min;
        float epsilon_r_max;
    };

    Material materials[] = {
        {"Aluminiumoxid (Al2O3)", 10.0f, 10.0f},
        {"Bariumtitanat", 1000.0f, 100000.0f},
        {"Glas", 5.0f, 12.0f},
        {"Glimmer", 5.0f, 8.0f},
        {"Hartpapier", 3.0f, 3.0f}, // Assuming a fixed value as not shown in the image
        {"Luft, trocken", 1.0006f, 1.0006f},
        {"Papier, ölgetränkt", 4.3f, 4.3f},
        {"Polyethylen (PE)", 2.3f, 2.3f},
        {"Polypropylen (PP)", 2.2f, 2.2f},
        {"Polystyrol (PS)", 2.6f, 2.6f},
        {"Schwefelhexafluorid (SF6)", 1.0f, 1.0f},
        {"Tantaloxid (Ta2O5)", 25.0f, 25.0f},
        {"Transformatoröl", 2.3f, 2.3f},
        {"Wasser, rein", 80.8f, 80.8f}
    };

    //Entladung
    string Uc(float U, float t, float tau) {
        // Exponential decay formula
        string calc = "U * exp(-t / tau) = ";

        string logic = to_string(U * exp(-t / tau));

        return calc + logic;
    }
    string ic(float t, float tau){
        string calc = "(t/tau)* exp(-t/tau) = ";

        string logic = to_string((t/tau)* exp(-t/tau));

        return calc + logic;
    }
    string get_Tau(float R, float c){
        string calc = "R * c = ";

        string logic = to_string(R * c);
        
        return calc + logic;
    }
    string get_Time(float Tau){
        string calc = "Tau * 5= ";

        string logic = to_string(Tau * 5);
        
        return calc + logic;
    }
    string get_Capacity(float A,float Er, float l){
        string calc = "EPSILON_0 * Er * A/l = ";

        string logic = to_string(EPSILON_0 * Er * A/l);
        
        return calc + logic;
    }

    int showMenue(string options_array[]) {
    int index = 0;
    const int options = sizeof(options_array)/ sizeof(options_array[0]);

    initscr();               // Initialize ncurses
    noecho();                // Disable echoing of characters
    cbreak();                // Disable line buffering
    keypad(stdscr, TRUE);    // Enable arrow keys and special keys

    while (true) {
        clear();

        for (int i = 0; i < options; i++)
        {
            if (i == index) {
                attron(A_REVERSE);
            }

            switch (i)
            {
            case 0: printw("random grid");break;
            case 1: printw("manual grid");break;
            }

            if (i== index) {
                attroff(A_REVERSE);
            }
        }
        int key = getch();
        if (key == KEY_DOWN) {
            index = (index - 1 + options) % options;
        } else if (key == KEY_UP) {
            index = (index + 1) % options;
        } else if (key == '\n') { // Enter key
            break;
        }
    }
    endwin(); // End ncurses mode
    return index;
} 


    int main(int argc, char const *argv[]) {

        cout << "Wilkommen zum Ultimativen TEB-Lenzer programm für ET!" << endl;
        
        return 0;
    }