#include <iostream>
#include <vector>
#include <string>

using namespace std;

class NguoiDung{
protected:
    string hoten;
    string tenDangNhap;
    string PassWord;
    string Email;
    string SDT;
    string type;
public:
    NguoiDung();
    NguoiDung(string,string,string);
    virtual void inputNguoiDung();
    virtual void outputNguoiDung();
    string getTen()
    {
        return this->hoten;
    }

    string getType()
    {
        return this->type;
    }
};

NguoiDung::NguoiDung(){
    this->hoten = "";
    this->tenDangNhap = "";
    this->PassWord = "";
    this->Email = "";
    this->SDT = "";
    type = "";
}

NguoiDung::NguoiDung(string thoten,string tEmail,string tSDT){
    this->hoten = thoten;
    this->tenDangNhap = "";
    this->PassWord = "";
    this->Email = tEmail;
    this->SDT = tSDT;
    type = "";
}

void NguoiDung::inputNguoiDung()
{
    cout << "\n===============================================================";
    cout << "\n\t\t\tNhap thong tin nguoi dung: ";
    cout << "\nNhap ho ten: ";
    fflush(stdin);
    getline(cin,this->hoten);
    cout << "Nhap Email: ";
    getline(cin,this->Email);
    cout << "Nhap SDT: ";
    getline(cin,this->SDT);
}

void NguoiDung::outputNguoiDung(){
    cout << "\nTen nguoi dung: "<< this->hoten;
}

class KhoaHoc{
private:
    string tenKhoaHoc;
    string maKhoaHoc;
    string namHoc;
    string hocKi;
    vector<string> listGiangVien;
    vector<string> listHocSinh;
public:
    KhoaHoc(){
        this->tenKhoaHoc = "";
        this->maKhoaHoc = "";
        this->namHoc = "";
        this->hocKi = "";
        this->listGiangVien = {};
        this->listHocSinh = {};
    }

    KhoaHoc(string tKhoaHoc,string tmaKhoaHoc,string tNamHoc,string tHocki){
        this->tenKhoaHoc = tKhoaHoc;
        this->maKhoaHoc = tmaKhoaHoc;
        this->namHoc = tNamHoc;
        this->hocKi = tHocki;
        this->listGiangVien = {};
        this->listHocSinh = {};
    }

    void inputKhoaHoc()
    {
        cout << "\n=============================================================";
        cout << "\n\t\t\tNhap khoa hoc: ";
        cout << "\nNhap ten khoa hoc: ";
        fflush(stdin);
        getline(cin,tenKhoaHoc);
        cout << "Nhap ma khoa hoc: ";
        getline(cin,maKhoaHoc);
        cout << "Nhap nam hoc: ";
        getline(cin,namHoc);
        cout << "Nhap hoc ki: ";
        getline(cin,hocKi);
        this->listGiangVien = {};
        this->listHocSinh = {};
    }

    void outputKhoaHoc()
    {
        cout << "\n\t\t\tThong tin khoa hoc: ";
        cout << "\nTen khoa hoc: " << this->tenKhoaHoc;
        cout << "\nMa khoa hoc: " << this->maKhoaHoc;
        cout << "\nNam hoc: " << this->namHoc;
        cout << "\nHoc ki: " << this->hocKi;
        cout << "\nThong tin giang vien: ";
        cout << "============================================================";
        for(int i = 0; i < listGiangVien.size(); i++)
            cout << listGiangVien[i];
        cout << "============================================================";
        cout << "\nThong tin hoc sinh: ";
        for(int i = 0; i < listHocSinh.size(); i++)
            cout << listHocSinh[i];
    }

    void addGiangVien(string a)
    {
        listGiangVien.push_back(a);
    }

    void addHocSinh(string a)
    {
        listHocSinh.push_back(a);
    }

    string getTenKhoaHoc()
    {
        return this->tenKhoaHoc;
    }
};


class GiangVien: public NguoiDung{
private:
    vector<KhoaHoc> listMonHoc;
public:
    void inputNguoiDung()
    {
        NguoiDung::inputNguoiDung();
        type = "GV";
        cout << "\nNhap ten dang nhap: "; cin >> this->tenDangNhap;
        cout << "Nhap mat khau: "; cin >> this->PassWord;
    }

    void outputNguoiDung()
    {
        NguoiDung::outputNguoiDung();
        cout << "- Vai tro: Giang Vien.";
    }
    void showCourses()
    {
        for(int i = 0; i < listMonHoc.size(); i++)
            cout << listMonHoc[i].getTenKhoaHoc() << endl;
    }

    void addKhoaHoc(KhoaHoc a)
    {
        this->listMonHoc.push_back(a);
    }
};

class HocSinh: public NguoiDung{
private:
    vector<KhoaHoc> listMonHoc;
public:
    void inputNguoiDung()
    {
        NguoiDung::inputNguoiDung();
        type = "HS";
        cout << "\nNhap ten dang nhap: "; cin >> this->tenDangNhap;
        cout << "Nhap mat khau: "; cin >> this->PassWord;
    }

    void outputNguoiDung()
    {
        NguoiDung::outputNguoiDung();
        cout << "- Vai Tro: Hoc Sinh";
    }

    void showCourses()
    {
        for(int i = 0; i < listMonHoc.size(); i++)
            cout << listMonHoc[i].getTenKhoaHoc() << endl;
    }

    void addKhoaHoc(KhoaHoc a)
    {
        this->listMonHoc.push_back(a);
    }
};


class Moddle{
    vector<NguoiDung*> listUser;
    vector<KhoaHoc> listKhoaHoc;
    int choice;
public:
    void autoPush()
    {
        KhoaHoc a("Nhap mon lap trinh","CSC100","2022","1");
        KhoaHoc b("Toan to hop","CSC102","2022","1");
        listKhoaHoc.push_back(a);
        listKhoaHoc.push_back(b);
    }
    
    
    void Function()
    {
        do
        {
            cout << "\nNhap lua chon: "; cin >> choice;
            if(choice == 1)
            {
                KhoaHoc a;
                a.inputKhoaHoc();
                listKhoaHoc.push_back(a);
                cout << "========================Them khoa hoc thanh cong=======================================";
            }
            else if(choice == 2)
            {
                NguoiDung *a;
                int type;
                cout << "\nNhap loai nguoi dung: "; cin >> type;
                if(type == 1)
                {
                    a = new HocSinh;
                    a->inputNguoiDung();
                    cout << "========================Them hoc sinh thanh cong.=============================";
                }
                else
                {
                    a = new GiangVien;
                    a->inputNguoiDung();
                    cout << "========================Them giang vien thanh cong.===========================";
                }
                listUser.push_back(a);
            }
            else if(choice == 3)
            {
                //add nguoi dung
                for(int i = 0; i < listKhoaHoc.size(); i++)
                {
                    cout << "\n" << i + 1 << "-" << listKhoaHoc[i].getTenKhoaHoc();
                }
                int n;
                cout << "\nNhap khoa hoc ban mun them: "; cin >> n;
                for(int i = 0; i < listUser.size();i++)
                {
                    cout << "\n" << i + 1 << "-" << listUser[i]->getTen();
                }
                int j;
                cout << "\nNhap nguoi dung muon them: "; cin >> j;
                if(listUser[j-1]->getType() == "GV")
                {
                    string name = listUser[j-1]->getTen();
                    listKhoaHoc[n-1].addGiangVien(name);
                }
                else if(listUser[j-1]->getType() == "HS")
                {
                    string name = listUser[j-1]->getTen();
                    listKhoaHoc[n-1].addHocSinh(name);
                }
            }
        } while (choice != 0);
            
    }

    void showKhoaHoc()
    {
        for(int i = 0; i < listKhoaHoc.size(); i++)
        {
            listKhoaHoc[i].outputKhoaHoc();
        }
    }
};

int main()
{
    Moddle a;
    a.autoPush();
    a.Function();
    a.showKhoaHoc();
}