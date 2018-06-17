#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;
void inputScore(string name[3],int score[3][3]);
void showScore(string grade[50][4]);
const string FN="name.txt";
ifstream infile;//read
ofstream outfile;//write
void main(){
	string name[3];
	string grade[50][4];
	int score[3][3];
	char menu;
	while(true){
		cout<<"////// MENU //////\n";
		cout<<"1.InsertScore\n";
		cout<<"2.ShowGrade\n";
		cout<<"Q.Exit\n";
		cout<<"Enter Menu : ";
		cin>>menu;
		switch(menu){
			case '1' : {
				inputScore(name,score);
				break;
			}
			case '2' : {
				showScore(grade);
				break;
			}
			case 'Q' : {
				exit(0);
				break;
			}
			case 'q' : {
				exit(0);
				break;
			}
			default : cout<<"Don't have this menu!!";
		}

	}

}
void inputScore(string name[3],int score[3][3]){
	string ggwp[3][4];
	
	for(int r=0;r<3;r++){
		cout<<"input Name : ";
		cin>>name[r];
		for(int c=0;c<3;c++){
			cout<<"inputScore : ";
			cin>>score[r][c];
		}
	}
	for(int r=0;r<3;r++){
		for(int c=0;c<3;c++){
			if(score[r][c]>=80){
				ggwp[r][c]="A";
			}else if(score[r][c]>=75){
				ggwp[r][c]="B+";
			}else if(score[r][c]>=70){
				ggwp[r][c]="B";
			}else if(score[r][c]>=65){
				ggwp[r][c]="C+";
			}else if(score[r][c]>=60){
				ggwp[r][c]="C";
			}else if(score[r][c]>=55){
				ggwp[r][c]="D+";
			}else if(score[r][c]>=50){
				ggwp[r][c]="D";
			}else{
				ggwp[r][c]="F";
			}//if
		}//for2
	}//for1

	ofstream outfile(FN.c_str(),ios_base::out|ios_base::app);
			if(outfile.is_open()){
				//cout<<"Year"<<"\t"<<"Money"<<"\t"<<"Interest"<<"\t"<<"TotalMoney"<<endl;
				for(int i=0;i<3;i++){
					outfile<<name[i]<<"\t"<<ggwp[i][0]<<"\t"<<ggwp[i][1]<<"\t"<<ggwp[i][2]<<endl;	
				}
		outfile.close();
			}
	
}
void showScore(string grade[50][4]){
	char wait;
	ifstream infile(FN.c_str(),ios_base::in);
	int a=0;
	if(infile.is_open()){
		cout<<"Name"<<"\t"<<"MATH"<<"\t"<<"JAVA"<<"\t"<<"CG"<<endl;
		infile>>grade[0][0]>>grade[0][1]>>grade[0][2]>>grade[0][3];
		while(!infile.eof()){
			cout<<grade[a][0]<<"\t"<<grade[a][1]<<"\t"<<grade[a][2]<<"\t"<<grade[a][3]<<endl;
			a++;
			infile>>grade[a][0]>>grade[a][1]>>grade[a][2]>>grade[a][3];
			}
		infile.close();
	}else{
		cout<<"File could not Write"<<endl;
	}
	cin.get(wait);
	cout<<"\nPress any key to continue........";
	cin.get(wait);
}