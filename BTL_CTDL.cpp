#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;

class GV {
	private:
		string GVId;
		string GVName;
		string GVClass;
		string GVSubject;
		string GVSemester;
		int GVYear;
	public:
		GV(){}
		GV(string _id, string _name, string _class, string _subject, string _semester): GVId(_id), GVName(_name), GVClass(_class), GVSubject(_subject), GVSemester(_semester) {}
		void addGV();
		void delGV(string _id);
		void editGV(string _id);
		void searchGV(string query);
		void showGV();
		void readData();
		void writeData();
		void sortById();
		void sortByName();
		void setName(string _name){
			GVName = _name;
		}
		void setClass(string _class){
			GVClass = _class;
		}
		void setSubject(string _subject){
			GVSubject = _subject;
		}
		void setSemester(string _semester){
			GVSemester = _semester;
		}
		string getId(){
			return GVId;
		}
		string getName(){
			return GVName;
		}
};

vector<GV> listGV;

void GV::addGV(){
	string _id, _name, _Class, _Subject, _Semester;
	cin.ignore(32767,'\n');
	cout << "Nhap ma GV: "; getline(cin, _id);
	cout << "Nhap ten GV: "; getline(cin, _name);
	cout << "Nhap lop: "; getline(cin, _Class);
	cout << "Nhap mon: "; getline(cin, _Subject);
	cout << "Nhap ky: "; getline(cin, _Semester);
	listGV.push_back(GV(_id, _name, _Class, _Subject, _Semester));
}

void GV::showGV(){
	printf("+----------+------------------------------------------------------------+----------------------+----------------------+---------------------------+\n");
	printf("| %-8s | %-58s | %-20s | %-20s | %-25s |\n", "Ma GV", "Ten GV", "Lop", "Mon", "Ky hoc");
	printf("+----------+------------------------------------------------------------+----------------------+----------------------+---------------------------+\n");
	for(long long unsigned int i=0; i<listGV.size(); i++){
		printf("| %-8s | %-58s | %-20s | %-20s | %-25s |\n", listGV[i].GVId.c_str(), listGV[i].GVName.c_str(), listGV[i].GVClass.c_str(), listGV[i].GVSubject.c_str(), listGV[i].GVSemester.c_str());
	}
	printf("+----------+------------------------------------------------------------+----------------------+----------------------+---------------------------+\n");
}

void GV::delGV(string _id){
	for (long long unsigned int i=0; i<listGV.size(); i++){
		if(listGV[i].GVId == _id){
			listGV.erase(listGV.begin()+i);
		}
	}
}

void GV::searchGV(string query){
	printf("+----------+------------------------------------------------------------+----------------------+----------------------+---------------------------+--------------+\n");
	printf("| %-8s | %-58s | %-20s | %-20s | %-25s |\n", "Ma GV", "Ten GV", "Lop", "Mon", "Nam hoc");
	printf("+----------+------------------------------------------------------------+----------------------+----------------------+---------------------------+--------------+\n");
	for(long long unsigned int i=0; i<listGV.size(); i++){
		if(strstr(listGV[i].GVName.c_str(), query.c_str()) != NULL){
			printf("| %-8s | %-58s | %-20s | %-20s | %-25s |\n", listGV[i].GVId.c_str(), listGV[i].GVName.c_str(), listGV[i].GVClass.c_str(), listGV[i].GVSubject.c_str(), listGV[i].GVSemester.c_str());
		}
	}
	printf("+----------+------------------------------------------------------------+----------------------+----------------------+---------------------------+--------------+\n");
}

void GV::editGV(string _id){
	for(long long unsigned int i=0; i<listGV.size(); i++){
		if(listGV[i].GVId == _id){
			string _name, _Class, _Subject, _Semester;
			cout << "Nhap GV: "; cin >> _name;
			cout << "Nhap lop: "; cin>>_Class;
			cout << "Nhap mon: "; cin >> _Subject;
			cout << "Nhap ky "; cin >> _Semester;
			listGV[i].setName(_name);
			listGV[i].setClass(_Class);
			listGV[i].setSubject(_Subject);
			listGV[i].setSemester(_Semester);
		}
	}
}

void GV::readData(){
	string path = "E:\\BTL_CTDLGT\\Luuthongtin.csv"; 
	ifstream GVFile(path);
	string header, line;
	string _id, _name, _Class, _Subject, _Semester, _year;
	getline(GVFile, header);
	while (getline(GVFile, line)){
		stringstream str(line);
		if(getline(str,_id,';') && getline(str,_name,';') && getline(str,_Class,';') && getline(str,_Subject,';') && getline(str,_Semester,';')){
			listGV.push_back(GV(_id, _name, _Class, _Subject, _Semester));
		}
	}
}

void GV::writeData(){
	string path = "E:\\BTL_CTDLGT\\Luuthongtin.csv"; 
	ofstream GVFile(path);
	GVFile << "Ma giang vien,Ten giang vien,Lop,Mon giang day,Ky hoc" << endl;
	for(long long unsigned int i=0; i<listGV.size(); i++){
		GVFile << listGV.at(i).GVId << "," << listGV.at(i).GVName << "," << listGV.at(i).GVClass << "," << listGV.at(i).GVSubject << "," << listGV.at(i).GVSemester << endl;
		cout << listGV.at(i).GVId<< "," << listGV.at(i).GVName << "," << listGV.at(i).GVClass << "," << listGV.at(i).GVSubject << "," << listGV.at(i).GVSemester << endl;
	}
} 

bool compareById(GV GV1, GV GV2){
	return GV1.getId() < GV2.getId();
}

void GV::sortById(){
	sort(listGV.begin(), listGV.end(), compareById);
}

bool compareByName(GV GV1, GV GV2){
	return GV1.getName() < GV2.getName();
}

void GV::sortByName(){
	sort(listGV.begin(), listGV.end(), compareByName);
}

int main(){
	int choice;
	string GV_id, query;
	GV GV;
	
	GV.readData();
	
	while(true){
		cout << "\nCHUONG TRINH QUAN LY THONG TIN SACH TRONG THU VIEN\n";
		cout << "	1. Them giang vien.\n";
		cout << "	2. Sua thong tin giang vien.\n";
		cout << "	3. Xoa thong tin giang vien.\n";
		cout << "	4. Xem danh sach giang vien.\n";
		cout << "	5. Luu danh sach giang vien vao CSDL.\n";
		cout << "	6. Sap xep giang vien theo ma so.\n";
		cout << "	7. Sap xep giang vien theo ten.\n";
		cout << "	8. Tim kiem theo ten giang vien.\n";
		cout << "	0. Thoat chuong trinh.\n";
		cout << "Ban chon chuc nang nao? ";
		cin >> choice;
		
		switch (choice){
			case 1:
				cout << "Nhap thong tin giang vien:\n";
				GV.addGV();
				break;
			case 2:
				cin.ignore();
				cout << "Nhap ma so giang vien can sua: ";
				cin >> GV_id;
				GV.editGV(GV_id);
				break;
			case 3:
				cout << "Nhap ma so giang vien can xoa: ";
				cin >> GV_id;
				GV.delGV(GV_id);
				break;
			case 4:
				cout << "					THONG TIN GIANG VIEN:\n";
				GV.showGV();
				break;
			case 5:
				GV.writeData();
				cout << "Thong tin giang vien da duoc luu \n";
				break;
			case 6:
				GV.sortById();
				GV.showGV();
				break;
			case 7:
				GV.sortByName();
				GV.showGV();
				break;
			case 8:
				cin.ignore();
				cout << "Nhap ten giang vien can tim: ";
				getline(cin, query);
				GV.searchGV(query);
				break;
			case 0:
				return 0;
		}
	}
}																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																
