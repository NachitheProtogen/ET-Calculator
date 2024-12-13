#include <iostream>
#include <cmath> // For std::exp
#include <vector>

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

    float validate_user_retardation(string prompt){
        string input;
        float number;

        while (true) {
            cout << prompt;
            cin >> input;

            try {
                number = stof(input);
                return number;        
            } catch (exception &err) {
                cout << "Das ist keine Nummer, du Hund!" << endl;
            }
        }
    }

int main(int argc, char const *argv[]) {
    cout << "Wilkommen zum Ultimativen TEB-Lenzer programm für ET!\n" << endl;
    cout << "Die Aktuelle funktionsliste ist:\n" << endl;
    cout << "1. Uc, Braucht U, T und Tau,\n" << endl;
    cout << "2. Ic, Braucht T und Tau,\n" << endl;
    cout << "3. get_Tau, Braucht R und c\n" << endl;
    cout << "4. get_Time, Braucht Tau,\n" << endl;
    cout << "5. get Capacity, braucht A Er und l\n" << endl;

    string option;
    int cleaned_option = 0;

    while (true) {
        cout << "Bitte geben Sie eine Zahl ein: ";
        cin >> option;

        try {
            cleaned_option = stoi(option);
            break;
        } catch (exception &err) {
            cout << "Das ist keine Nummer, du Hund!" << endl;
        }
    }

    // Get material names
    int numMaterials = sizeof(materials) / sizeof(materials[0]);
    string materialNames;
    for (int i = 0; i < numMaterials; i++) {
        materialNames += materials[i].name + "\n";
    }

    switch (cleaned_option) {
        case 1: {
            float U = validate_user_retardation("Enter U: ");
            float T = validate_user_retardation("Enter t: ");
            float Tau = validate_user_retardation("Enter Tau: ");
            cout << Uc(U, T, Tau) << endl;
            break;
        }
        case 2: {
            float T = validate_user_retardation("Enter T: ");
            float Tau = validate_user_retardation("Enter Tau: ");
            cout << ic(T, Tau) << endl;
            break;
        }
        case 3: {
            float R = validate_user_retardation("Enter R: ");
            float c = validate_user_retardation("Enter c: ");
            cout << get_Tau(R, c) << endl;
            break;
        }
        case 4: {
            float Tau = validate_user_retardation("Enter Tau: ");
            cout << get_Time(Tau) << endl;
            break;
        }
        case 5: {
            string materialPrompt = "Enter Er the Material: \nAll Materials:\n" + materialNames;
            float A = validate_user_retardation("Enter A: ");
            float Er = validate_user_retardation(materialPrompt);
            float l = validate_user_retardation("Enter l: ");
            int er = static_cast<int>(Er);
            if (er < 1 || er > numMaterials) {
                cout << "Invalid material selection!" << endl;
                break;
            }
            cout << get_Capacity(A, materials[er - 1].epsilon_r_max, l);
            break;
        }
        default:
            cout << "Schreib ne nummer du Profi!!" << endl;
            break;
    }

    return 0;
}