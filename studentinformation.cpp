#include <bits/stdc++.h>
using namespace std;
using ll = long long;
class SV{
    // dieu chinh thong tin an di ko de bi tk loz nao do no hack vo, la tao la t hack me lay tien di choi cho vui ;v
private:
    string mssv, ten, ns, lop;
    double gpa;

public:
// cong khai ten da dieu chinh
    SV(){}
    SV(string mssv, string ten, string ns, string lop, double gpa) {
        this->mssv = mssv;
        this->ten = ten;
        this->ns = ns;
        this->lop = lop;
        this->gpa = gpa;
    }
    void in() const {
        cout << mssv << " " << ten << " " << ns << " " << lop << " " << fixed << setprecision(2) << gpa << endl;
    }
    //nhap ten de no dinh dang
    void chuanHoaTen() {
        stringstream ss(ten);
        string res = "", w;
        while (ss >> w) {
            res += toupper(w[0]);
            for (size_t i = 1; i < w.size(); i++) {
                res += tolower(w[i]);
            }
            res += " ";
        }
        res.pop_back();
        ten = res;
    }
    void chuanHoaNS() {
        if (ns[1] == '/') ns = "0" + ns;
        if (ns[4] == '/') ns.insert(3, "0");
        // ngay sinh 
    }
//lay lop
    string getLop() const {
        return lop;
    }
    string getTen() const {
        stringstream ss(ten);
        string w;
        vector<string> v;
        while (ss >> w) v.push_back(w);
        return v.back(); 
        // ve ten
    }
};
//sorting
bool cmp(const SV& x, const SV& y) {
    if (x.getLop() != y.getLop())
        return x.getLop() < y.getLop();
    return x.getTen() < y.getTen();
}
int main() {
    int n;
    cin >> n;
    vector<SV> v;
    for (int i = 0; i < n; i++) {
        string mssv, ten, ns, lop;
        double gpa;
        cin.ignore();
        getline(cin, mssv); getline(cin, ten); getline(cin, ns); getline(cin, lop);
        cin >> gpa;
        SV s(mssv, ten, ns, lop, gpa);
        s.chuanHoaTen(); s.chuanHoaNS(); v.push_back(s);
    }
    sort(v.begin(), v.end(), cmp);
    for (const SV& x : v) {
        x.in();
    }
    return 0;
}
