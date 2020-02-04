/***************************************************************************//*!
* *
* * @file math.cpp
* *
* * @version 0.1.0
* *
* * @author Dinger
* *
* * @brief do some calculation of matrix. 
* *
* *******************************************************************************/
#include<iostream>
#include<cmath>
#include<iomanip>
#include<string>
using namespace std;

template<typename T>

int numswap(T &_a, T &_b){
    T _c;
    _c = _a;
    _a = _b;
    _b = _c;
    return 0;
}

class matrix{
    public:
        int row, col;
        float *num;

        matrix(int r, int c){
            row = r;
            col = c;
            num = new float[row*col];
        }

        int id(int r, int c){
            return (r*col+c);
        }

        int rowexchange(int a, int b){
            for(int i=0; i<col; i++)
                numswap(num[id(a, i)], num[id(b, i)]);
            return 0;
        }

        int colexchange(int a, int b){
            for(int i=0; i<row; i++)
                numswap(num[id(i, a)], num[id(i, b)]);
            return 0;
        }

        int rowplus(int a, float k, int b){
            for(int i=0; i<col; i++)
                num[id(a, i)] += k*num[id(b, i)];
            return 0;
        }

        int colplus(int a, float k, int b){
            for(int i=0; i<row; i++)
                num[id(a, i)] += k*num[id(b, i)];
            return 0;
        }

        matrix operator *(matrix& b){
            if(this->col == b.row){
                matrix c(this->row, b.col);
                for(int i=0; i<this->row; i++){
                    for(int j=0; j<b.col; j++){
                        float cnum=0;
                        for(int k=0; k<this->col; k++)
                            cnum += this->num[this->id(i, k)] * b.num[b.id(k, j)];
                        c.num[c.id(i, j)] = cnum;
                    }
                }
                return c;
            }
            else{
                matrix c(0, 0);
                cout << "Can't multiply!" << endl;
                return c;
            }
        }
        int print(){
            for(int i=0; i<row; i++){
                for(int j=0; j<col; j++)
                    cout << setw(5) << num[id(i, j)];
                cout << endl;
            }
            return 0;
        }
};

#define RE 0
#define CE 1
#define RP 2
#define CP 3
#define P 4
#define Q 5

int cinclear(){
    cin.clear();
    fflush(stdin);
    return 0;
}

matrix* newmatrix(){
    int row, col;
    cout << "Enter the num of row and col" << endl;
    cin >> row >> col;
    matrix* pmatrix = new matrix(row, col);
    cout << "Enter the matrix" << endl;
    for(int i=0; i<row*col; i++)
        cin >> pmatrix->num[i];
    pmatrix->print();
    return pmatrix;
}

struct namedmatrix{
    string name;
    matrix* address;
};

namedmatrix matrixs[10];
int numofmatrix=0;

int addmatrix(){
    string addname;
    cout << "Enter the name of the matrix" << endl;
    cin >> addname;

}

int main(){
    char input;
    int oper, quit=1;
    int a, b;
    float k;
    while(quit){
        cout << "Enter the operator: re(0),ce(1),rp(2),cp(3),p(4),q(5)" << endl;
        cin >> input;
        cinclear();
        if((int)input > (int)'5' || (int)input < (int)'0')
            continue;
        oper = (int)input - 48;
        switch(oper){
            case RE:
                cout << "Enter the 2 nums of row" << endl;
                while(!(cin >> a >> b))
                    cinclear();
                matrixa.rowexchange(a, b);
                break;
            case CE:
                cout << "Enter the 2 nums of col" << endl;
                while(!(cin >> a >> b))
                    cinclear();
                matrixa.colexchange(a, b);
                break;
            case RP:
                cout << "Enter the 3 nums:a, k, b" << endl;
                while(!(cin >> a >> k >> b))
                    cinclear();
                matrixa.rowplus(a, k, b);
                break;
            case CP:
                cout << "Enter the 3 nums:a, k, b" << endl;
                while(!(cin >> a >> k >> b))
                    cinclear();
                matrixa.colplus(a, k, b);
                break;
            case P:
                matrixa.print();
                break;
            case Q:
                quit = 0;
                break;
            default:
                break;
        }
        if(quit == 0)
            break;
    }
    delete[] matrixa.num;
    return 0;
}

int limmain(){
    double x;
    for(x=1; x>10e-5; x/=2){
        double result=0;
        x += 1;
        result = (x*x-1)*(exp(1/(x-1)))/(x-1);
        cout << result << endl;
        x -= 1;
    }
    return 0;
}
