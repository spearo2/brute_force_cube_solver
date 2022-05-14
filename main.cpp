#include <iostream>
#include "decisionTree.h"
using namespace std;


#define WHITE 0
#define GREEN 1
#define RED  2
#define BLUE 3
#define ORANGE  4
#define YELLOW  5


void makeIntro();
int fillUpCube(Element *a, string input[6]);
void makeTestCase (string input[6]);



int main(int argc, char *argv[]) {
   
    Element* a = new Element(-1);
    makeIntro();
    string input[6];
    // cout << endl <<"Enter the color of the FRONT side of your current cube state: ";
    // cin >> input[FRONT];
    // cout << endl <<"Enter the color of the BACK side of your current cube state: ";
    // cin >> input[BACK];
    // cout << endl <<"Enter the color of the LEFT side of your current cube state: ";
    // cin >> input[LEFT];
    // cout << endl <<"Enter the color of the RIGHT side of your current cube state: ";
    // cin >> input[RIGHT];
    // cout << endl <<"Enter the color of the TOP side of your current cube state: ";
    // cin >> input[TOP];
    // cout << endl <<"Enter the color of the BOTTOM side of your current cube state: ";
    // cin >> input[BOTTOM];
    makeTestCase(input);
    fillUpCube(a, input);
    DecisionTree graph;
    graph.root = a;

    
     while (!graph.Print()) {
         graph.make_decision(a);
     }
        
    // int i, j, k;
    // for (i = 0; i < 6; i++) {
    //     for (j = 0; j < 3; j++) {
    //         for (k = 0; k < 3; k++) {
    //             cout << graph.root->cube[i][j][k] << " ";
                
    //         }
    //     }
    // }
    return 0;


}


int fillUpCube(Element *a, string input[6]) {

    int i, j, k;
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 3; k++) {
                switch(input[i][j*3+k]) {
                    case 'w':
                        a->cube[i][j][k] = WHITE;
                        break;
                    case 'g':
                        a->cube[i][j][k] = GREEN;
                        break;
                    case 'r':
                        a->cube[i][j][k] = RED;
                        break;
                    case 'b':
                        a->cube[i][j][k] = BLUE;
                        break;
                    case 'o':
                        a->cube[i][j][k] = ORANGE;
                        break;
                    case 'y':
                        a->cube[i][j][k] = YELLOW;
                        break;
                    default:
                        cout << "Invalid input" << endl;
                        return 1;
                }
                
            }
        }
    }
    return 0;
}

void makeIntro () {
    cout <<"              __                       __                                 "<<endl<<"  _______  __/ /_  ___     _________  / /   _____  _____                  "<<endl<<" / ___/ / / / __ \\/ _ \\   / ___/ __ \\/ / | / / _ \\/ ___/                  "<<endl<<"/ /__/ /_/ / /_/ /  __/  (__  ) /_/ / /| |/ /  __/ /                      "<<endl<<"\\___/\\__,_/_.___/\\___/  /____/\\____/_/ |___/\\___/_/                       "<<endl<<"   ___  ____________ _______  __ __ ___                                   "<<endl<<"  |__ \\<  /__  / __ <  / __ \\/ // /|__ \\                                  "<<endl<<"  __/ // /  / / / / / / / / / // /___/ /                                  "<<endl<<" / __// /  / / /_/ / / /_/ /__  __/ __/                                   "<<endl<<"/____/_/__/_/\\____/_/\\____/  /_/ /____/                     __            "<<endl<<"  / ____/ /_  ____ _____  ____ _____ _____  ____  ____ _   / /   ___  ___ "<<endl<<" / /   / __ \\/ __ `/ __ \\/ __ `/ __ `/ __ \\/ __ \\/ __ `/  / /   / _ \\/ _ \\"<<endl<<"/ /___/ / / / /_/ / / / / /_/ / /_/ / /_/ / / / / /_/ /  / /___/  __/  __/"<<endl<<"\\____/_/ /_/\\__,_/_/ /_/\\__, /\\__, /\\____/_/ /_/\\__, /  /_____/\\___/\\___/ "<<endl<<"                       /____//____/            /____/                     "<<endl<<endl;
    cout << "   _ _ _"<<endl<<"  /_/_/_/\\"<<endl<<" /_/_/_/\\/\\"<<endl<<"/_/_/_/\\/\\/\\"<<endl<<"\\_\\_\\_\\/\\/\\/"<<endl<<" \\_\\_\\_\\/\\/"<<endl<<"  \\_\\_\\_\\/"<<endl;
    cout<<endl<<"Welcome to the cube solver!"<<endl<<endl<<"Face one side of your cube towrads you, and now it is the front side"<<endl;
    cout<<"type the colors of the cube in the following order:"<<endl;
    cout<<"  _ _ _"<<endl<<" |1|2|3|"<<endl<<"  _ _ _"<<endl<<" |4|5|6|"<<endl<<"  _ _ _"<<endl<<" |7|8|9|"<<endl<<"  _ _ _"<<endl;
    cout<<endl<<"Red: r, Green: g, Blue: b, Orange: o, Yellow: y, White: w"<<endl;
    cout<<"Please dont't type any spaces between colors"<<endl;
}



void makeTestCase (string input[6]) {
    // input[0] = "rogbgybwr";
    // input[1] = "wyogbwgrw";
    // input[2] = "ywbborogy";
    // input[3] = "wwbbrogry";
    // input[4] = "gorowrybo";
    // input[5] = "ogwyygbyr";

    input[0] = "rrrrrrbbb";
    input[1] = "ooogggggg";
    input[2] = "bbbbbbggg";
    input[3] = "oooooorrr";
    input[4] = "wwwwwwwww";
    input[5] = "yyyyyyyyy";
    
}

