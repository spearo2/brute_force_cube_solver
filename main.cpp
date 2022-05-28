/*
compile with g++ main.cpp -std=c++11 -pthread
*/

#include <iostream>
#include <thread>
#include "decisionTree.h"
using namespace std;

#define WHITE 0
#define GREEN 1
#define RED  2
#define BLUE 3
#define ORANGE  4
#define YELLOW  5

DecisionTree graph;
bool d_flag = false;
bool t_flag = false;
void makeIntro();
int fillUpCube(Element *a, string input[6]);
void makeTestCase (string input[6]);
bool Print_thread();
void thread_Print(int index);
bool inorder_print_thread(Element* ptr, int index);
bool returned = false;
void signal_found();



int main(int argc, char *argv[]) {
    

    if (argc == 2) {
        if (argv[1] == string("-d")) {
            d_flag = true;
        } else if (argv[1] == string("-t")) {
            t_flag = true;
        } else {
            cout << "Invalid argument" << endl;
            return 0;
        }
    }
   
    Element* a = new Element(-1);
    makeIntro();
    string input[6];
    
    /* 
    If you want to test the program, and you don't have cube in your hand mute 51~62 lines and use the makeTestCase(input) function
    */

    cout << endl <<"Enter the color of the FRONT side of your current cube state: ";
    cin >> input[FRONT];
    cout << endl <<"Enter the color of the BACK side of your current cube state: ";
    cin >> input[BACK];
    cout << endl <<"Enter the color of the LEFT side of your current cube state: ";
    cin >> input[LEFT];
    cout << endl <<"Enter the color of the RIGHT side of your current cube state: ";
    cin >> input[RIGHT];
    cout << endl <<"Enter the color of the TOP side of your current cube state: ";
    cin >> input[TOP];
    cout << endl <<"Enter the color of the BOTTOM side of your current cube state: ";
    cin >> input[BOTTOM];
    
    //makeTestCase(input); // unmute this to use the test case
    fillUpCube(a, input);
    
    graph.root = a;
    if (d_flag) {
        graph.d_flag = true;
    } else if (t_flag) {
        graph.t_flag = true;
    }


    thread thread_terminate(signal_found);
    if (!t_flag)
        thread_terminate.detach();

    if (t_flag) {
        while (!Print_thread()) {
        graph.make_decision(graph.root);
        } 
    } else {
        while (!graph.Print()) {
            graph.make_decision(a);
        }
    }
    if (t_flag)
        thread_terminate.join();
    return 0;


}

bool Print_thread() {
        thread thread0(thread_Print,0);        
        thread thread1(thread_Print,1);
        thread thread2(thread_Print,2);
        thread thread3(thread_Print,3);
        thread thread4(thread_Print,4);
        thread thread5(thread_Print,5);
        thread thread6(thread_Print,6);
        thread thread7(thread_Print,7);
        thread thread8(thread_Print,8);
        thread thread9(thread_Print,9);
        thread thread10(thread_Print,10);
        thread thread11(thread_Print,11);
        thread0.join();
        thread1.join();
        thread2.join();
        thread3.join();
        thread4.join();
        thread5.join();
        thread6.join();
        thread7.join();
        thread8.join();
        thread9.join();
        thread10.join();
        thread11.join();
        if (returned) {
            return true;
        } else {
            return false;
        }

}
void signal_found() {
    if (t_flag)
        return;
    while (!returned);
    exit(1);
        
}

void thread_Print(int index) {
    if(inorder_print_thread(graph.root,index)) {
        cout << "solution found!" <<endl;
        int temp = graph.solution.size();
        for(int i = 0; i < temp; i++) {
            switch(graph.solution.top()) {
                case 6:
                    cout << "TL ";
                    break;
                case 7:
                    cout << "TR ";
                    break;
                case 8:
                    cout << "BL ";
                    break;
                case 9:
                    cout << "BR ";
                    break;
                case 10:
                    cout << "RU ";
                    break;
                case 11:
                    cout << "RD ";
                    break;
                case 12:
                    cout << "LU ";
                    break;
                case 13:
                    cout << "LD ";
                    break;
                case 14:
                    cout << "FC ";
                    break;
                case 15:
                    cout << "FA ";
                    break;
                case 16:
                    cout << "BC ";
                    break;
                case 17:
                    cout << "BA ";
                    break;
                default:
                    cout << "";
                    break;
            }
            graph.solution.pop();
        }
    returned = true;
    } 
    return;
}

bool inorder_print_thread(Element* ptr, int index) {
    if (ptr) {
        int i = index;
            if (graph.inorder_print(ptr->childs[i])) {
                graph.solution.push(ptr->previousRotate);
                return true;
            }

            if (ptr->childs[i] == NULL) {
                if (graph.check_cube(ptr)) {
                    returned = true;
                    graph.solution.push(ptr->previousRotate);
                    //print_cube(ptr);
                    return true;
                }
            }
    }
    return false;
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

    if (t_flag)
        cout<<"thread mode selected!"<<endl;
    else if (d_flag)
        cout<<"display mode selected!"<<endl << "performance may decrease"<<endl;
}



void makeTestCase (string input[6]) {
    input[0] = "rogbgybwr";
    input[1] = "wyogbwgrw";
    input[2] = "ywbborogy";
    input[3] = "wwbbrogry";
    input[4] = "gorowrybo";
    input[5] = "ogwyygbyr";
    // //TR
    // input[0] = "wwwoooooo";
    // input[1] = "rrrrrryyy";
    // input[2] = "rrrwwwwww";
    // input[3] = "oooyyyyyy";
    // input[4] = "ggggggggg";
    // input[5] = "bbbbbbbbb";

    //TL
    // input[0] = "yyyoooooo";
    // input[1] = "rrrrrrwww";
    // input[2] = "ooowwwwww";
    // input[3] = "rrryyyyyy";
    // input[4] = "ggggggggg";
    // input[5] = "bbbbbbbbb";
    
    //RU
    // input[0] = "ggoggoggo";
    // input[1] = "bbrbbrbbr";
    // input[2] = "wwwwwwwww";
    // input[3] = "yyyyyyyyy";
    // input[4] = "rrgrrgrrg";
    // input[5] = "oobooboob";

     //BR
    // input[0] = "oooooowww";
    // input[1] = "yyyrrrrrr";
    // input[2] = "wwwwwwrrr";
    // input[3] = "yyyyyyooo";
    // input[4] = "ggggggggg";
    // input[5] = "bbbbbbbbb";

    //BL
    // input[0] = "ooooooyyy";
    // input[1] = "wwwrrrrrr";
    // input[2] = "wwwwwwooo";
    // input[3] = "yyyyyyrrr";
    // input[4] = "ggggggggg";
    // input[5] = "bbbbbbbbb";


    //FC
    // input[0] = "ooooooooo";
    // input[1] = "rrrrrrrrr";
    // input[2] = "wwbwwbwwb";
    // input[3] = "gyygyygyy";
    // input[4] = "ggggggwww";
    // input[5] = "yyybbbbbb";

    //Complete
    // input[0] = "ooooooooo";
    // input[1] = "rrrrrrrrr";
    // input[2] = "wwwwwwwww";
    // input[3] = "yyyyyyyyy";
    // input[4] = "ggggggggg";
    // input[5] = "bbbbbbbbb";

    //TRRD
    // input[0] = "wwgoogoog";
    // input[1] = "rrbrrbyyb";
    // input[2] = "rrrwwwwww";
    // input[3] = "oyyoyyoyy";
    // input[4] = "ggrggrggy";
    // input[5] = "bbwbbobbo";

    //FA DL RU FC
    // input[0] = "booyoobbb";
    // input[1] = "gwgrrgrry";
    // input[2] = "wwwwwboow";
    // input[3] = "ybbyyyyyy";
    // input[4] = "ggoggoogg";
    // input[5] = "rrrwbrwbr";

    //TR LU BC BL
    // input[0] = "ybbyooggw";
    // input[1] = "bbyrrgwww";
    // input[2] = "gbbybbyoo";
    // input[3] = "oobggwgrr";
    // input[4] = "rrrowwoww";
    // input[5] = "yyoyygrrg";

    //random 5
    // input[0] = "booyooyyy";
    // input[1] = "woorrgrry";
    // input[2] = "wwwwwbbbb";
    // input[3] = "ybbyyygwg";
    // input[4] = "ggoggoogg";
    // input[5] = "rrrrbbrww";

    // //RU TL BR LU BL FA
    // input[0] = "ybgyoybby";
    // input[1] = "rbbgrworw";
    // input[2] = "bwoowoyoo";
    // input[3] = "rrgrygrgw";
    // input[4] = "ywoogggyw";
    // input[5] = "wwbbbygrr";
}

