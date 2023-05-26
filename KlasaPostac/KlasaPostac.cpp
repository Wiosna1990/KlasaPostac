

#include <iostream>
using namespace std;

class Postac
{
    static int licznikPostaci;
    string imie;
    int hp;
    int nrPostaci;


public:
    Postac() { licznikPostaci++; nrPostaci = licznikPostaci; }
    Postac(Postac& p)
    {
        imie = p.imie;
        hp = p.hp;

    }
    Postac(string _imie, int _hp)
        :imie(_imie), hp(_hp)
    {
        licznikPostaci++;
        nrPostaci = licznikPostaci;
    }
    string GetImie()
    {
        return imie;
    }
    void Prezentuj()const
    {
        cout << "Imie postaci: " << imie << " ,ilosc HP postaci: " << hp << " ,stan licznika Postaci: " << licznikPostaci << endl;
    }

    friend void ZmienImie(Postac& p, string noweImie);

};
int Postac::licznikPostaci = 0;

class Mag : public Postac
{
    static int licznikMagow;
    string atrybut;
    int nrMaga;
public:
    Mag() { licznikMagow++; nrMaga = licznikMagow; }
    Mag(string i, int h, string _atrybut)
        :Postac(i, h)
    {
        atrybut = _atrybut;
        licznikMagow++;
        nrMaga = licznikMagow;
    }
    Mag(Postac& p, string _atrybut)
        :Postac(p)
    {
        atrybut = _atrybut;
        licznikMagow++;
        nrMaga = licznikMagow;
    }
    void PrezentujMaga()
    {
        Prezentuj();

        cout << "Atrybut: " << atrybut << " ,licznik Magow: " << licznikMagow << ", Numer maga:  " << nrMaga << endl << endl;
    }

    string GetAtrybut()
    {
        return atrybut;
    }
    void SetAtrybut(string atr)
    {
        atrybut = atr;
    }
};
int Mag::licznikMagow = 0;

class Rycerz :public Postac
{
    static int licznikRycerzy;
    string bron;
    int nrRycerza;
public:
    Rycerz() { licznikRycerzy++; nrRycerza = licznikRycerzy; }
    Rycerz(string i, int h, string _bron)
        :Postac(i, h)
    {
        bron = _bron;
        licznikRycerzy++;
        nrRycerza = licznikRycerzy;
    }
    Rycerz(Postac& p, string _bron)
        :Postac(p)
    {
        bron = _bron;
        licznikRycerzy++;
        nrRycerza = licznikRycerzy;
    }
    void PrezentujRycerza()
    {
        Prezentuj();
        cout << "Bron: " << bron << " ,licznik Rycerzy: " << licznikRycerzy << ", Numer rycerza: " << nrRycerza << endl << endl;

    }
    string GetBron()
    {
        return bron;
    }
    void SetBron(string br)
    {
        bron = br;
    }

};
int Rycerz::licznikRycerzy = 0;

void ZmienImie(Postac& p, string noweImie)
{
    p.imie = noweImie;
}
class Akademia
{
    static const int maxMagow = 2;
    Mag magowie[maxMagow];
    string nazwa;
    int licznik = 0;
public:
    Akademia() {}
    Akademia(string _nazwa)
        :nazwa(_nazwa)
    {

    }
    void DodajMaga(Mag& mag)
    {
        if (licznik >= maxMagow)
        {
            cout << endl;
            cout << "Maksymalna liczba magow to: " << maxMagow;
        }
        else
        {
            magowie[licznik] = mag;
            licznik++;
        }
    }
    void WypiszMagow()
    {
        cout << endl;
        cout << "Pokaz magow w Akademii " << nazwa << " : " << endl;
        for (int i = 0; i < licznik; i++)
        {
            cout << magowie[i].GetImie() << endl;
        }
    }




};


int main()
{
    Postac p1("Adriel", 100);
    p1.Prezentuj();
    ZmienImie(p1, "Yennefer");
    p1.Prezentuj();

    Mag m1(p1, "inteligencja");
    m1.SetAtrybut("madrosc");
    m1.PrezentujMaga();

    Mag m2("Gandalf ", 150, "zdrowie");
    m2.PrezentujMaga();

    Mag m3("Maya", 170, "wytrzymalosc");
    m3.PrezentujMaga();



    Rycerz r1("Lancelot", 200, "miecz");
    r1.PrezentujRycerza();
    cout << "Rodzaj broni: " << r1.GetBron() << endl;

    Akademia a1("Skyrim");
    a1.DodajMaga(m1);
    a1.DodajMaga(m2);
    a1.DodajMaga(m3);
    a1.WypiszMagow();



}
