#include<bits/stdc++.h>

using namespace std;

int main() {
    //boi vi deu la luy thua cua 2, nen neu so a b a voi b lon hon a thi chac chan a * 2 se be hon hoac bang b, do do cu nham vao so be hon ma loai bo no
    int n;
    cin >> n;
    vector<string> a(n);
    for (auto& x : a) cin >> x;
    stack<string> st;      //tao 1 stack luu gia tri tu lon den be  va giu lai cac gia tri tiem nang trong nay
    for (auto x : a) {
        while (!st.empty() && x > st.top()) st.pop();         //neu gia tri x lon hon dinh cua stack thi loai bo (vi dinh be hon x)
        while (!st.empty() && x == st.top()) {      //neu dinh cua stack bang x 
            st.pop();      //loai bo no di
            x = x + x;          // nhan doi len (hieu don gian la gop 2 so giong nhau vao ay
        }
        st.push(x);         //sau khi ket thuc thi push thg x vao
        // hieu don gian thi st.top = 4 va x = 4 thi x = 8 va st pop 4 ra roi thi phai them 8 vao ay
    }
    while (st.size() > 1) st.pop();          //vi no giu lai cac gia tri tiem nang nen gia tri o day moi la lon nhat, loai bo toi khi con 1 phan tu
    //vi du 16 8
    cout << st.top() << endl;  //in ra gia tri con lai
}