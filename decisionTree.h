#include <iostream>
#include <queue>

#define FRONT 0
#define BACK 1
#define LEFT 2
#define RIGHT 3
#define TOP 4
#define BOTTOM 5
#define TL 6
#define TR 7
#define BL 8
#define BR 9
#define RU 10
#define RD 11
#define LU 12
#define LD 13
#define FC 14
#define FA 15
#define BC 16
#define BA 17

using namespace std;
class Element{
  public: 
    int previousRotate;
    int cube[6][3][3];
    Element *  childs [12];
    int node_depth;

    Element(int rotate) {
        previousRotate = rotate;
        for (int i = 0; i < 12; i++) {
            childs[i] = NULL;
        }
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    cube[i][j][k] = 0;
                }
            }
        }
    }
};

class DecisionTree{

    public:
        int depth;
        Element* root;
        queue<int> solution;
        DecisionTree();
        ~DecisionTree();
        bool IsEmpty();
        void delete_tree (Element * tree);
        bool inorder_print(Element * ptr);
        bool check_cube(Element *ptr);
        bool Print();
        void expand_decision(Element *ptr, int cnt);
        void extend_branch(Element *ptr);
        void make_decision(Element *ptr);
        Element* makeTRnode(Element *a);
        Element* makeTLnode(Element *a);
        Element* makeRUnode(Element *a);
        Element* makeRDnode(Element *a);
        Element* makeLUnode(Element *a);
        Element* makeLDnode(Element *a);
        Element* makeBRnode(Element *a);
        Element* makeBLnode(Element *a);
        Element* makeFCnode(Element *a);
        Element* makeFAnode(Element *a);
        Element* makeBCnode(Element *a);
        Element* makeBAnode(Element *a);
        void print_cube (Element * node);
};

DecisionTree::DecisionTree() {
    depth = 1;
    root = NULL;
}

DecisionTree::~DecisionTree() {
    delete_tree(root);
    root = NULL;
}   

void DecisionTree::delete_tree(Element *ptr) {
    if(ptr) {
        for (int i = 0; i < 12; i++) {
            delete_tree(ptr->childs[i]);
        }
        delete(ptr);
    }
}

bool DecisionTree::IsEmpty() {
    return (root == NULL);
}

bool DecisionTree::Print() {
    if(inorder_print(root)) {
        cout << "solution found!" <<endl;
        int temp = solution.size();
        for(int i = 0; i < temp; i++) {
            switch(solution.front()) {
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
            solution.pop();
        }
        return 1;
    }
    return 0;
}

bool DecisionTree::inorder_print(Element* ptr) {
    if (ptr) {
        for (int i = 0; i<12; i++) {
            if (inorder_print(ptr->childs[i])) {
                solution.push(ptr->previousRotate);
                //print_cube(ptr);
                return true;
            }
            if (ptr->childs[i] == NULL) {
                
                if (check_cube(ptr)) {
                    solution.push(ptr->previousRotate);
                    //print_cube(ptr);
                    return true;
                }
                    
            }
        }
    } 
    return false;
    
}    


bool DecisionTree::check_cube(Element *ptr) {
    
    for (int i = 0; i < 6; i++) {
            
        if(ptr->cube[i][0][0] == ptr->cube[i][0][1] && ptr->cube[i][0][0] == ptr->cube[i][0][2] && ptr->cube[i][0][0] == ptr->cube[i][1][0] && ptr->cube[i][0][0] == ptr->cube[i][1][1] && ptr->cube[i][0][0] == ptr->cube[i][1][2] && ptr->cube[i][0][0] == ptr->cube[i][2][0] && ptr->cube[i][0][0] == ptr->cube[i][2][1] && ptr->cube[i][0][0] == ptr->cube[i][2][2]) {
            
        } else return false;
            
        
    }
    return true;
}
void DecisionTree::make_decision(Element *ptr) {
   
    cout<<"browsing "<<depth<<" rotation"<<endl;
   
    depth++;
    expand_decision(ptr,1);
}

void DecisionTree::expand_decision(Element *ptr, int cnt) {
    
    if (ptr) {
        
        for (int i = 0; i<12; i++) {
            expand_decision(ptr->childs[i],cnt+1);
            if (ptr->childs[i] == NULL && cnt == depth-1)
                extend_branch(ptr);
            
        }
        
    } 
}
void DecisionTree::extend_branch(Element *ptr) {
    if (ptr) {
        for (int i = 0; i < 12; i++) {
            if (ptr->childs[i] == NULL) {
                switch (i) {
                    case 0:
                        if (ptr->previousRotate != TR) 
                            ptr->childs[i] = makeTRnode(ptr);
            
                        break;
                    case 1:
                        if (ptr->previousRotate != TL) 
                            ptr->childs[i] = makeTLnode(ptr);
                        break;
                    case 2:
                        if (ptr->previousRotate != LU) 
                            ptr->childs[i] = makeLUnode(ptr);
                        break;
                    case 3:
                        if (ptr->previousRotate != LD) 
                            ptr->childs[i] = makeLDnode(ptr);
                        break;
                    case 4:
                        if (ptr->previousRotate != RU) 
                            ptr->childs[i] = makeRUnode(ptr);
                        break;
                    case 5:
                        if (ptr->previousRotate != RD) 
                            ptr->childs[i] = makeRDnode(ptr);
                        break;
                    case 6:
                        if (ptr->previousRotate != BL) 
                            ptr->childs[i] = makeBLnode(ptr);
                        break;
                    case 7:
                        if (ptr->previousRotate != BR) 
                            ptr->childs[i] = makeBRnode(ptr);
                        break;
                    case 8:
                        if (ptr->previousRotate != FC) 
                            ptr->childs[i] = makeFCnode(ptr);
                        break;
                    case 9:
                        if (ptr->previousRotate != FA) 
                            ptr->childs[i] = makeFAnode(ptr);
                        break;
                    case 10:
                        if (ptr->previousRotate != BC) 
                            ptr->childs[i] = makeBCnode(ptr);
                        break;
                    case 11:
                        if (ptr->previousRotate != BA) 
                            ptr->childs[i] = makeBAnode(ptr);
                        break;
                }
                
            }
        }
    }
}

Element* DecisionTree::makeTRnode(Element *a) {
    Element * temp = new Element(TR);
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k<3; k++) {
                temp->cube[i][j][k] = a->cube[i][j][k];
            }
        }
    }
    swap(temp->cube[FRONT][0], temp->cube[RIGHT][0]);
    swap(temp->cube[FRONT][0], temp->cube[BACK][2]);
    swap(temp->cube[FRONT][0], temp->cube[LEFT][0]);

    swap(temp->cube[TOP][0][0], temp->cube[TOP][0][2]);
    swap(temp->cube[TOP][0][0], temp->cube[TOP][2][2]);
    swap(temp->cube[TOP][0][0], temp->cube[TOP][2][0]);

    swap(temp->cube[TOP][0][1], temp->cube[TOP][1][2]);
    swap(temp->cube[TOP][0][1], temp->cube[TOP][2][1]);
    swap(temp->cube[TOP][0][1], temp->cube[TOP][1][0]);
    temp->previousRotate = TR;

    return temp;

}

Element* DecisionTree::makeTLnode(Element *a) {
    Element * temp = new Element(TL);
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k<3; k++) {
                temp->cube[i][j][k] = a->cube[i][j][k];
            }
        }
    }
    // print_cube(temp);
    swap(temp->cube[FRONT][0], temp->cube[LEFT][0]);
    swap(temp->cube[FRONT][0], temp->cube[BACK][2]);
    swap(temp->cube[FRONT][0], temp->cube[RIGHT][0]);
    
    swap(temp->cube[TOP][0][0], temp->cube[TOP][2][0]);
    swap(temp->cube[TOP][0][0], temp->cube[TOP][2][2]);
    swap(temp->cube[TOP][0][0], temp->cube[TOP][0][2]);

    swap(temp->cube[TOP][0][1], temp->cube[TOP][1][0]);
    swap(temp->cube[TOP][0][1], temp->cube[TOP][2][1]);
    swap(temp->cube[TOP][0][1], temp->cube[TOP][1][2]);
    // print_cube(temp);
    return temp;

}
Element* DecisionTree::makeRUnode(Element *a) {
    Element * temp = new Element(TR);
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k<3; k++) {
                temp->cube[i][j][k] = a->cube[i][j][k];
            }
        }
    }
    // print_cube(temp);
    swap(temp->cube[FRONT][0][2], temp->cube[TOP][0][2]);
    swap(temp->cube[FRONT][0][2], temp->cube[BACK][0][2]);
    swap(temp->cube[FRONT][0][2], temp->cube[BOTTOM][0][2]);

    swap(temp->cube[FRONT][1][2], temp->cube[TOP][1][2]);
    swap(temp->cube[FRONT][1][2], temp->cube[BACK][1][2]);
    swap(temp->cube[FRONT][1][2], temp->cube[BOTTOM][1][2]);

    swap(temp->cube[FRONT][2][2], temp->cube[TOP][2][2]);
    swap(temp->cube[FRONT][2][2], temp->cube[BACK][2][2]);
    swap(temp->cube[FRONT][2][2], temp->cube[BOTTOM][2][2]);

    swap(temp->cube[RIGHT][0][0], temp->cube[RIGHT][0][2]);
    swap(temp->cube[RIGHT][0][0], temp->cube[RIGHT][2][2]);
    swap(temp->cube[RIGHT][0][0], temp->cube[RIGHT][2][0]);

    swap(temp->cube[RIGHT][0][1], temp->cube[RIGHT][1][2]);
    swap(temp->cube[RIGHT][0][1], temp->cube[RIGHT][2][1]);
    swap(temp->cube[RIGHT][0][1], temp->cube[RIGHT][1][0]);
    // print_cube(temp);
    return temp;

}
Element* DecisionTree::makeRDnode(Element *a) {
    Element * temp = new Element(RD);
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k<3; k++) {
                temp->cube[i][j][k] = a->cube[i][j][k];
            }
        }
    }
    swap(temp->cube[FRONT][0][2], temp->cube[BOTTOM][0][2]);
    swap(temp->cube[FRONT][0][2], temp->cube[BACK][0][2]);
    swap(temp->cube[FRONT][0][2], temp->cube[TOP][0][2]);

    swap(temp->cube[FRONT][1][2], temp->cube[BOTTOM][1][2]);
    swap(temp->cube[FRONT][1][2], temp->cube[BACK][1][2]);
    swap(temp->cube[FRONT][1][2], temp->cube[TOP][1][2]);

    swap(temp->cube[FRONT][2][2], temp->cube[BOTTOM][2][2]);
    swap(temp->cube[FRONT][2][2], temp->cube[BACK][2][2]);
    swap(temp->cube[FRONT][2][2], temp->cube[TOP][2][2]);

    swap(temp->cube[RIGHT][0][0], temp->cube[RIGHT][2][0]);
    swap(temp->cube[RIGHT][0][0], temp->cube[RIGHT][2][2]);
    swap(temp->cube[RIGHT][0][0], temp->cube[RIGHT][0][2]);

    swap(temp->cube[RIGHT][0][1], temp->cube[RIGHT][1][0]);
    swap(temp->cube[RIGHT][0][1], temp->cube[RIGHT][2][1]);
    swap(temp->cube[RIGHT][0][1], temp->cube[RIGHT][1][2]);

    return temp;

}
Element* DecisionTree::makeLUnode(Element *a) {
    Element * temp = new Element(LU);
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k<3; k++) {
                temp->cube[i][j][k] = a->cube[i][j][k];
            }
        }
    }
    // print_cube(temp);
    swap(temp->cube[FRONT][0][0], temp->cube[TOP][0][0]);
    swap(temp->cube[FRONT][0][0], temp->cube[BACK][0][0]);
    swap(temp->cube[FRONT][0][0], temp->cube[BOTTOM][0][0]);

    swap(temp->cube[FRONT][1][0], temp->cube[TOP][1][0]);
    swap(temp->cube[FRONT][1][0], temp->cube[BACK][1][0]);
    swap(temp->cube[FRONT][1][0], temp->cube[BOTTOM][1][0]);

    swap(temp->cube[FRONT][2][0], temp->cube[TOP][2][0]);
    swap(temp->cube[FRONT][2][0], temp->cube[BACK][2][0]);
    swap(temp->cube[FRONT][2][0], temp->cube[BOTTOM][2][0]);

    swap(temp->cube[LEFT][0][0], temp->cube[LEFT][2][0]);
    swap(temp->cube[LEFT][0][0], temp->cube[LEFT][2][2]);
    swap(temp->cube[LEFT][0][0], temp->cube[LEFT][0][2]);

    swap(temp->cube[LEFT][0][1], temp->cube[LEFT][1][0]);
    swap(temp->cube[LEFT][0][1], temp->cube[LEFT][2][1]);
    swap(temp->cube[LEFT][0][1], temp->cube[LEFT][1][2]);
    // print_cube(temp);
    return temp;
}
Element* DecisionTree::makeLDnode(Element *a) {
    Element * temp = new Element(LD);
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k<3; k++) {
                temp->cube[i][j][k] = a->cube[i][j][k];
            }
        }
    }
    // print_cube(temp);
    swap(temp->cube[FRONT][0][0], temp->cube[BOTTOM][0][0]);
    swap(temp->cube[FRONT][0][0], temp->cube[BACK][0][0]);
    swap(temp->cube[FRONT][0][0], temp->cube[TOP][0][0]);

    swap(temp->cube[FRONT][1][0], temp->cube[BOTTOM][1][0]);
    swap(temp->cube[FRONT][1][0], temp->cube[BACK][1][0]);
    swap(temp->cube[FRONT][1][0], temp->cube[TOP][1][0]);

    swap(temp->cube[FRONT][2][0], temp->cube[BOTTOM][2][0]);
    swap(temp->cube[FRONT][2][0], temp->cube[BACK][2][0]);
    swap(temp->cube[FRONT][2][0], temp->cube[TOP][2][0]);

    swap(temp->cube[LEFT][0][0], temp->cube[LEFT][0][2]);
    swap(temp->cube[LEFT][0][0], temp->cube[LEFT][2][2]);
    swap(temp->cube[LEFT][0][0], temp->cube[LEFT][2][0]);

    swap(temp->cube[LEFT][0][1], temp->cube[LEFT][1][2]);
    swap(temp->cube[LEFT][0][1], temp->cube[LEFT][2][1]);
    swap(temp->cube[LEFT][0][1], temp->cube[LEFT][1][0]);
    // print_cube(temp);
    return temp;
}
Element* DecisionTree::makeBRnode(Element *a) {
    Element * temp = new Element(BR);
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k<3; k++) {
                temp->cube[i][j][k] = a->cube[i][j][k];
            }
        }
    }
    // print_cube(temp);
    swap(temp->cube[FRONT][2], temp->cube[RIGHT][2]);
    swap(temp->cube[FRONT][2], temp->cube[BACK][0]);
    swap(temp->cube[FRONT][2], temp->cube[LEFT][2]);

    swap(temp->cube[BOTTOM][0][0], temp->cube[BOTTOM][0][2]);
    swap(temp->cube[BOTTOM][0][0], temp->cube[BOTTOM][2][2]);
    swap(temp->cube[BOTTOM][0][0], temp->cube[BOTTOM][2][0]);

    swap(temp->cube[BOTTOM][0][1], temp->cube[BOTTOM][1][2]);
    swap(temp->cube[BOTTOM][0][1], temp->cube[BOTTOM][2][1]);
    swap(temp->cube[BOTTOM][0][1], temp->cube[BOTTOM][1][0]);
    // print_cube(temp);
    return temp;
}
Element* DecisionTree::makeBLnode(Element *a) {
    Element * temp = new Element(BL);
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k<3; k++) {
                temp->cube[i][j][k] = a->cube[i][j][k];
            }
        }
    }
    swap(a->cube[FRONT][2], a->cube[LEFT][2]);
    swap(a->cube[FRONT][2], a->cube[BACK][0]);
    swap(a->cube[FRONT][2], a->cube[RIGHT][2]);
    
    swap(temp->cube[BOTTOM][0][0], temp->cube[BOTTOM][2][0]);
    swap(temp->cube[BOTTOM][0][0], temp->cube[BOTTOM][2][2]);
    swap(temp->cube[BOTTOM][0][0], temp->cube[BOTTOM][0][2]);

    swap(temp->cube[BOTTOM][0][1], temp->cube[BOTTOM][1][0]);
    swap(temp->cube[BOTTOM][0][1], temp->cube[BOTTOM][2][1]);
    swap(temp->cube[BOTTOM][0][1], temp->cube[BOTTOM][1][2]);

    return temp;

}
Element* DecisionTree::makeFCnode(Element *a) {
    Element * temp = new Element(FC);
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k<3; k++) {
                temp->cube[i][j][k] = a->cube[i][j][k];
            }
        }
    }
    // print_cube(temp);
    swap(temp->cube[FRONT][0][0], temp->cube[FRONT][0][2]);
    swap(temp->cube[FRONT][0][0], temp->cube[FRONT][2][2]);
    swap(temp->cube[FRONT][0][0], temp->cube[FRONT][2][0]);

    swap(temp->cube[FRONT][0][1], temp->cube[FRONT][1][2]);
    swap(temp->cube[FRONT][0][1], temp->cube[FRONT][2][1]);
    swap(temp->cube[FRONT][0][1], temp->cube[FRONT][1][0]);

    swap(temp->cube[TOP][2][0], temp->cube[RIGHT][0][0]);
    swap(temp->cube[TOP][2][0], temp->cube[BOTTOM][0][2]);
    swap(temp->cube[TOP][2][0], temp->cube[LEFT][2][2]);

    swap(temp->cube[TOP][2][1], temp->cube[RIGHT][1][0]);
    swap(temp->cube[TOP][2][1], temp->cube[BOTTOM][0][1]);
    swap(temp->cube[TOP][2][1], temp->cube[LEFT][1][2]);

    swap(temp->cube[TOP][2][2], temp->cube[RIGHT][2][0]);
    swap(temp->cube[TOP][2][2], temp->cube[BOTTOM][0][0]);
    swap(temp->cube[TOP][2][2], temp->cube[LEFT][0][2]);
    // print_cube(temp);
    return temp;
}
Element* DecisionTree::makeFAnode(Element *a) {
    Element * temp = new Element(FA);
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k<3; k++) {
                temp->cube[i][j][k] = a->cube[i][j][k];
            }
        }
    }
    // print_cube(temp);
    swap(temp->cube[FRONT][0][0], temp->cube[FRONT][2][0]);
    swap(temp->cube[FRONT][0][0], temp->cube[FRONT][2][2]);
    swap(temp->cube[FRONT][0][0], temp->cube[FRONT][0][2]);

    swap(temp->cube[FRONT][0][1], temp->cube[FRONT][1][0]);
    swap(temp->cube[FRONT][0][1], temp->cube[FRONT][2][1]);
    swap(temp->cube[FRONT][0][1], temp->cube[FRONT][1][2]);

    swap(temp->cube[TOP][2][0], temp->cube[LEFT][2][2]);
    swap(temp->cube[TOP][2][0], temp->cube[BOTTOM][0][2]);
    swap(temp->cube[TOP][2][0], temp->cube[RIGHT][0][0]);

    swap(temp->cube[TOP][2][1], temp->cube[LEFT][1][2]);
    swap(temp->cube[TOP][2][1], temp->cube[BOTTOM][0][1]);
    swap(temp->cube[TOP][2][1], temp->cube[RIGHT][1][0]);

    swap(temp->cube[TOP][2][2], temp->cube[LEFT][0][2]);
    swap(temp->cube[TOP][2][2], temp->cube[BOTTOM][0][0]);
    swap(temp->cube[TOP][2][2], temp->cube[RIGHT][2][0]);
    // print_cube(temp);
    return temp;
}
Element* DecisionTree::makeBCnode(Element *a) {
    Element * temp = new Element(BC);
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k<3; k++) {
                temp->cube[i][j][k] = a->cube[i][j][k];
            }
        }
    }
    // print_cube(temp);
    swap(temp->cube[BACK][0][0], temp->cube[BACK][2][0]);
    swap(temp->cube[BACK][0][0], temp->cube[BACK][2][2]);
    swap(temp->cube[BACK][0][0], temp->cube[BACK][0][2]);

    swap(temp->cube[BACK][0][1], temp->cube[BACK][1][0]);
    swap(temp->cube[BACK][0][1], temp->cube[BACK][2][1]);
    swap(temp->cube[BACK][0][1], temp->cube[BACK][1][2]);

    swap(temp->cube[TOP][0][0], temp->cube[RIGHT][0][2]);
    swap(temp->cube[TOP][0][0], temp->cube[BOTTOM][2][2]);
    swap(temp->cube[TOP][0][0], temp->cube[LEFT][2][0]);

    swap(temp->cube[TOP][0][1], temp->cube[RIGHT][1][2]);
    swap(temp->cube[TOP][0][1], temp->cube[BOTTOM][2][1]);
    swap(temp->cube[TOP][0][1], temp->cube[LEFT][1][0]);

    swap(temp->cube[TOP][0][2], temp->cube[RIGHT][2][2]);
    swap(temp->cube[TOP][0][2], temp->cube[BOTTOM][2][0]);
    swap(temp->cube[TOP][0][2], temp->cube[LEFT][0][0]);
    // print_cube(temp);
    return temp;
}
Element* DecisionTree::makeBAnode(Element *a) {
    Element * temp = new Element(BA);
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k<3; k++) {
                temp->cube[i][j][k] = a->cube[i][j][k];
            }
        }
    }
    // print_cube(temp);
    swap(temp->cube[BACK][0][0], temp->cube[BACK][0][2]);
    swap(temp->cube[BACK][0][0], temp->cube[BACK][2][2]);
    swap(temp->cube[BACK][0][0], temp->cube[BACK][2][0]);

    swap(temp->cube[BACK][0][1], temp->cube[BACK][1][2]);
    swap(temp->cube[BACK][0][1], temp->cube[BACK][2][1]);
    swap(temp->cube[BACK][0][1], temp->cube[BACK][1][0]);

    swap(temp->cube[TOP][0][0], temp->cube[LEFT][2][0]);
    swap(temp->cube[TOP][0][0], temp->cube[BOTTOM][2][2]);
    swap(temp->cube[TOP][0][0], temp->cube[RIGHT][0][2]);

    swap(temp->cube[TOP][0][1], temp->cube[LEFT][1][0]);
    swap(temp->cube[TOP][0][1], temp->cube[BOTTOM][2][1]);
    swap(temp->cube[TOP][0][1], temp->cube[RIGHT][1][2]);

    swap(temp->cube[TOP][0][2], temp->cube[LEFT][0][0]);
    swap(temp->cube[TOP][0][2], temp->cube[BOTTOM][2][0]);
    swap(temp->cube[TOP][0][2], temp->cube[RIGHT][2][2]);

//    print_cube(temp);
    return temp;
}

void DecisionTree::print_cube (Element * node) {
    int i, j, k;
    for (i = 0; i < 6; i++) {
        switch(i) {
            case 0:
                cout << "front side" << endl;
                break;
            case 1:
                cout << "back side" << endl;
                break;
            case 2:
                cout << "left side" << endl;
                break;
            case 3:
                cout << "right side" << endl;
                break;
            case 4:
                cout << "top side" << endl;
                break;
            case 5:
                cout << "bottom side" << endl;
                break;
        }
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 3; k++) {
                switch(node->cube[i][j][k]) {
                    case 0:
                        cout << "W ";
                        break;
                    case 1:
                        cout << "G ";
                        break;
                    case 2:
                        cout << "R ";
                        break;
                    case 3:
                        cout << "B ";
                        break;
                    case 4:
                        cout << "O ";
                        break;
                    case 5:
                        cout << "Y ";
                        break;
                }
            }
            cout << endl;
        }
        cout <<endl;
    }
    cout << "------------------------------" << endl;
}

