#include<iostream>
#include<fstream>
#include<algorithm>
#include<string>
#include<vector>
#include<iomanip>
using namespace std;



class Nguoi {
	string ma, ten, sotien;
	// Private section
	public:
		Nguoi();
		Nguoi(string,string);
		string getTen();
		string getSotien();
		void setSotien(int);
		// Public Declarations
	protected:
		// Protected Declarations
};

Nguoi::Nguoi(){// ham tao
	//
}

Nguoi::Nguoi(string Ten, string Stien){
	ten = Ten;
	sotien= Stien;
}
// thêm tên ms co KH
string Nguoi::getTen(){
	return ten;
}
// nhap tien
string Nguoi::getSotien(){
	return sotien;
}
// cap nhat lai tien
void Nguoi::setSotien(int x)
{
	sotien = x;
}
class giaodich{
	bool loaiGD;// tra ve 1:rut tien 0:goi tien
	int soluong;// so tien muon rut hoac goi
};

class KhachHang :public Nguoi{
	int id;// ma KH dc cap nhat tu dong theo id++ tu cap nhat size
	public://phan chung cua ham 
		KhachHang();// goi ham
		KhachHang(int, string, string);// nhap cac thuoc tinh cho ham
		int getID();
		void setID(int);
		friend istream &operator>>(istream &, KhachHang &);
		friend ostream &operator<<(ostream &, KhachHang &);
		friend void ghiKH(KhachHang);
		friend vector<KhachHang> docKH();
};

KhachHang::KhachHang(){// ham tao
	
}

KhachHang::KhachHang(int i, string Ten, string Stien)
:Nguoi(Ten, Stien){
	id = i;
}

int KhachHang::getID(){
	return id;
}

void KhachHang::setID(int i){
	id = i;
}
// ghi file
istream &operator>>(istream &is, KhachHang &m){
	
	string ten, sotien;
	cout<<"\nNhap ten KH: ";
	getline(is,ten);
	cout<<"\nNhap so tien goi: ";
	getline(is,sotien);
	KhachHang k(0,ten, sotien);
	m = k;
	return is;
}
// doc file
ostream &operator<<(ostream &os, KhachHang &m){
	os<<left<<setw(10)<<m.id<<setw(20)<<m.getTen()<<setw(20)<<m.getSotien()<<endl;
	return os;
}

void ghiKH(KhachHang m){
	ofstream ofs("KH.DAT",ios::app);
	ofs<< m.id<<endl<<m.getTen()<<endl<<m.getSotien()<<endl;
	ofs.close();
}

vector<KhachHang> docKH(){
	vector<KhachHang> list;
	ifstream ifs("KH.DAT");
	if(ifs != NULL){
		while(!ifs.eof()){//doc het file ms dung lai
			string ten, sotien;
			int id;
			ifs>>id;
			getline(ifs,ten);
			getline(ifs,ten);
			getline(ifs,sotien);
			
			KhachHang m(id, ten, sotien);
			if(!ifs.eof())
				list.push_back(m);
		}
	}
	ifs.close();
	return list;
}

int main(){
	int lc;
	vector<KhachHang> listK ;listK= docKH();
	
	do{
		cout<<"\n=====MENU=====\n1. Them KH.\n2. Hien thi DS KH.\n0. Thoat."
			<<"\nBan chon ? ";
		cin>> lc;
		fflush(stdin);// xoa bo nho dem
		
		switch(lc){
			case 0: break;

			
			case 1:{
				KhachHang k;
				cin>> k;
				k.setID(0+listK.size());
				listK.push_back(k);
				ghiKH(k);
				break;
			}
			
			case 2:{
				if(listK.size() > 0){
					cout<<left<<setw(10)<<"ID"<<setw(20)<<"Ten KH"<<setw(20)<<"So Tien Goi"<<endl;//xuat trai voi do rong 10
					for(int i = 0;i< listK.size(); i++){
						cout<< listK[i];
					}
				} else cout<<"\nDS trong.";
				break;
			}
		}
	}while(lc);
	return 0;
}
// vector <giaodich> dstrans..
// bool thuchienGD(char* khID, long soluong, bool loaiGD);
// hai vector cung nam chung mot class su ly ;
// ghi file GD;
// giaodich nhapGDtubp() // nhap tu ban phim
