#include <iostream>
#include <fstream>
using namespace std;
void inPutFromKeyBoard(int a[100][100], int &n){
	cout<<"Nhap so luong : ";
	cin>>n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>a[i][j];
		}
	}
}
void inPutFromFile(int a[100][100], int &n){
	//doc du lieu tu file
    ifstream DocFile("file.txt");
	//kiem tra xem co ton tai file ko
	if(!DocFile.is_open()){
		cout<<"Not open File :( "<<endl;
	}else{
		DocFile>>n;       //nhap n tu file vao chuong trinh
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				DocFile>>a[i][j];  //nhap cac gia tri cua file vao chuong trinh
			}
		}
	DocFile.close();
	//hien thi ra man hinh
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
				cout<<a[i][j]<<" ";
				
			}
			cout<<"\n";
		}
  }
}
void checkLienThong(int a[100][100], int n){
	char *DanhDau = new char [n];
    char ThanhCong;
    int Dem=0;
	for(int i = 0; i<n; i++)    //Khoi tao moi dinh chua danh dau
     DanhDau[i] = 0;
     DanhDau[0] = 1;    //danh dau dinh dau
     Dem++;      //dem so dinh duoc danh dau
    do {
      ThanhCong =1;  //khong con kha nang loang
      for(int i = 0; i<n; i++)
        if(DanhDau[i]==1){
         for(int j = 0; j<n; j++)
             if (DanhDau[j] == 0 && a[i][j] > 0){
                  DanhDau[j] = 1;
                  ThanhCong = 0;  //con kha nang loang
                   Dem++;
             }
        }
      }while (ThanhCong == 0);  //lap lai cho den khi khong con kha nang loang

   if(Dem == n) {
   	cout<<"Do Thi Lien Thong"<<endl;
   }else{
   	cout<<"Do Thi Khong Lien Thong"<<endl;
   }
    
		
}
int main(){
	int a[100][100];
	int n;
	char in;
	do{
		cout<<"\n======= KIEM TRA TINH LIEN THONG CUA DO THI =======\n";
	    cout<<"\t1. Nhap tu ban phim"<<endl;
	    cout<<"\t2. Doc tu file "<<endl;
	    cout<<"\t3. Kiem tra lien thong"<<endl;
	    cout<<"\t4. Thoat"<<endl;
	    cout<<"==================================================="<<endl;
     	cout<<endl;
    	cout<<"Moi ban chon thao tac:  ";
    	cin>>in;
   
		switch(in){
		case '1':
			inPutFromKeyBoard(a,n);
			break;
		case '2':
			inPutFromFile(a,n);
			break;
		case '3':
			checkLienThong(a,n);
			break;
		case '4':
			exit(0);
		default:
			cout<<"Moi ban chon lai!!!"<<endl;
			break;
	     } 	
      }while(in);
	return 0;
}
