#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
class juzhen{
	public:
		int line, col;
		float** num;
		juzhen(int m,int n){
			this->line = m;
			this->col = n;
			float anum[m][n];
			this->num = anum;
		}
		
		int init(){
			cout << "Please enter the juzhen:" << endl;
			for(int i=0; i<this->line; i++){
				for(int j=0; j<this->col; j++)
					cin >> this->num[i][j];
			}
		}
		
		int print(){
			for(int i=0; i<this->line; i++){
				for(int j=0; j<this->col; j++)
					cout << this->num[i][j];
				cout << endl;
			}
		}
		
		juzhen operator*(juzhen b){
			juzhen out(this->line, b.col);
			if(this->col == b.line){
				for(int i=0; i<this->line; i++){
					for(int j=0; j<b.col; j++){
						for(int k=0; k<this->col; k++){
							out.num[i][j] += this->num[i][k]*b.num[k][j];
						}
					}
				}
			}
			else{
				cout<<"Wrong operate!";
				1/0;
			}
			return out;
		}
};

int main(int argc, char** argv) {
	int m, n;
	cout<<"请输入矩阵的行数和列数："<<endl;
	cin>>m>>n;
	juzhen juzhen1(m, n);
	juzhen1.init();
	
	cout<<"请输入矩阵的行数和列数："<<endl;
	cin>>m>>n;
	juzhen juzhen2(m, n);
	juzhen2.init();
	cout << "the answer is:" << endl;
	(juzhen1*juzhen2).print;
	return 0;
}
