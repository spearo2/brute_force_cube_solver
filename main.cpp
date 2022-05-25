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
void makeIntro();
int fillUpCube(Element *a, string input[6]);
void makeTestCase (string input[6]);
bool Print_thread();
void inorder_print_thread(Element* ptr, int index);
bool returned = false;



int main(int argc, char *argv[]) {
    bool d_flag = false;
    bool t_flag = false;

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

    graph.root = a;
    if (d_flag) {
        graph.d_flag = true;
    } else if (t_flag) {
        graph.t_flag = true;
    }



    if (t_flag) {
        while (!Print_thread()) {
        graph.make_decision(graph.root);
    }
            
       
    } else {
        while (!graph.Print()) {
            graph.make_decision(a);
        }
    }
    
    return 0;


}

bool Print_thread() {
        thread thread0(inorder_print_thread,graph.root,0);        
        thread thread1(inorder_print_thread,graph.root,1);
        thread thread2(inorder_print_thread,graph.root,2);
        thread thread3(inorder_print_thread,graph.root,3);
        thread thread4(inorder_print_thread,graph.root,4);
        thread thread5(inorder_print_thread,graph.root,5);
        thread thread6(inorder_print_thread,graph.root,6);
        thread thread7(inorder_print_thread,graph.root,7);
        thread thread8(inorder_print_thread,graph.root,8);
        thread thread9(inorder_print_thread,graph.root,9);
        thread thread10(inorder_print_thread,graph.root,10);
        thread thread11(inorder_print_thread,graph.root,11);
        
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

void inorder_print_thread(Element* ptr, int index) {
    if (ptr) {
        if(returned)
            return;
        int i = index;
            if (graph.inorder_print(ptr->childs[i])) {
                graph.solution.push(ptr->previousRotate);
            }

            if (ptr->childs[i] == NULL) {
                
                if (graph.check_cube(ptr)) {
                    returned = true;
                    graph.solution.push(ptr->previousRotate);
                    //print_cube(ptr);
                    return;
                }
            }
    }
    if(returned) {
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
    exit(1);
    } 
    return;
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
    input[0] = "ooooooooo";
    input[1] = "rrrrrrrrr";
    input[2] = "wwwwwwwww";
    input[3] = "yyyyyyyyy";
    input[4] = "ggggggggg";
    input[5] = "bbbbbbbbb";

    //TRRD
    // input[0] = "wwgoogoog";
    // input[1] = "rrbrrbyyb";
    // input[2] = "rrrwwwwww";
    // input[3] = "oyyoyyoyy";
    // input[4] = "ggrggrggy";
    // input[5] = "bbwbbobbo";

    //TRRDBR
    // input[0] = "wwgoogwww";
    // input[1] = "yyorrbyyb";
    // input[2] = "rrrwwwbrr";
    // input[3] = "oyyoyyoog";
    // input[4] = "ggrggrggy";
    // input[5] = "bbbbbboow";

    //TRLUBCBL
    input[0] = "ybbyooggw";
    input[1] = "bbyrrgwww";
    input[2] = "gbbybbyoo";
    input[3] = "oobggwgrr";
    input[4] = "rrrowwoww";
    input[5] = "yyoyygrrg";
}

