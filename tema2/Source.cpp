#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Student {
private:
    int numarMatricol;
    std::string numePrenume;
    double mediaAdmitere;
    double notaMateria1;
    double notaMateria2;
    double notaMateria3;

public:
    Student(int numarMatricol, string numePrenume, double mediaAdmitere, double notaMateria1, double notaMateria2, double notaMateria3) : numarMatricol(numarMatricol), numePrenume(numePrenume), mediaAdmitere(mediaAdmitere),
        notaMateria1(notaMateria1), notaMateria2(notaMateria2), notaMateria3(notaMateria3) {}

    int getNumarMatricol() const { return numarMatricol; }
    string getNumePrenume() const { return numePrenume; }
    double getMediaAdmitere() const { return mediaAdmitere; }
    double getNotaMateria1() const { return notaMateria1; }
    double getNotaMateria2() const { return notaMateria2; }
    double getNotaMateria3() const { return notaMateria3; }


    void setNumePrenume(const string& numePrenume)
    {
        this->numePrenume = numePrenume;
    }
    void setMediaAdmitere(double mediaAdmitere)
    {
        this->mediaAdmitere = mediaAdmitere;
    }
    void setNotaMateria1(double notaMateria1)
    {
        this->notaMateria1 = notaMateria1;
    }
    void setNotaMateria2(double notaMateria2)
    {
        this->notaMateria2 = notaMateria2;
    }
    void setNotaMateria3(double notaMateria3)
    {
        this->notaMateria3 = notaMateria3;
    }


    bool esteIntegralist() const {
        return notaMateria1 >= 5 && notaMateria2 >= 5 && notaMateria3 >= 5;
    }


    string determinareBursa() const {
        if (esteIntegralist()) {
            double mediaNote = (notaMateria1 + notaMateria2 + notaMateria3) / 3.0;
            if (mediaNote >= 9.5) {
                return "bursa de merit";
            }
            else if (mediaNote >= 8.5) {
                return "bursa de studii";
            }
        }
        return "fara bursa";
    }


    void afiseazaInfoStudent() const {
        cout << "Numar Matricol: " << numarMatricol << endl;
        cout << "Nume Prenume: " << numePrenume << endl;
        cout << "Media Admitere: " << mediaAdmitere << endl;
        cout << "Nota Materia 1: " << notaMateria1 << endl;
        cout << "Nota Materia 2: " << notaMateria2 << endl;
        cout << "Nota Materia 3: " << notaMateria3 << endl;
        cout << "Situatie: " << (esteIntegralist() ? "Integralist" : "Neintegralist") << endl;
        cout << "Bursa: " << determinareBursa() << endl;
    }
};

class Grupa {
private:
    vector<Student> studenti;

public:

    void adaugaStudent(const Student& student) {
        studenti.push_back(student);
    }


    void stergeStudentiNepromovati() {
        studenti.erase(remove_if(studenti.begin(), studenti.end(),
            [](const Student& s) {
                return s.getNotaMateria1() < 5 && s.getNotaMateria2() < 5 && s.getNotaMateria3() < 5;
            }),
            studenti.end());
    }


    void modificaStudent(int numarMatricol, const string& numePrenume, double mediaAdmitere, double notaMateria1, double notaMateria2, double notaMateria3) {
        for (auto& student : studenti) {
            if (student.getNumarMatricol() == numarMatricol) {
                student.setNumePrenume(numePrenume);
                student.setMediaAdmitere(mediaAdmitere);
                student.setNotaMateria1(notaMateria1);
                student.setNotaMateria2(notaMateria2);
                student.setNotaMateria3(notaMateria3);
                break;
            }
        }
    }


    bool apartineGrupa(int numarMatricol) const {
        for (const auto& student : studenti) {
            if (student.getNumarMatricol() == numarMatricol) {
                return true;
            }
        }
        return false;
    }


    int numarStudenti() const {
        return studenti.size();
    }


    void afiseazaStudentiBursaStudii() const {
        for (const auto& student : studenti) {
            if (student.determinareBursa() == "bursa de studii") {
                student.afiseazaInfoStudent();
                cout << endl;
            }
        }
    }


    void afiseazaStudentiBursaMerit() const {
        for (const auto& student : studenti) {
            if (student.determinareBursa() == "bursa de merit") {
                student.afiseazaInfoStudent();
                cout << endl;
            }
        }
    }


    void afiseazaInfoStudent(int numarMatricol) const {
        for (const auto& student : studenti) {
            if (student.getNumarMatricol() == numarMatricol) {
                student.afiseazaInfoStudent();
                return;
            }
        }
        cout << "Studentul cu numarul matricol " << numarMatricol << " nu exista in grupa.\n";
    }
};


int main() {
    Grupa grupa;


    grupa.adaugaStudent(Student(1, "Gunoiu George", 9.0, 8, 9, 10));
    grupa.adaugaStudent(Student(2, "Cladiade Gabriel", 9.5, 10, 10, 10));
    grupa.adaugaStudent(Student(3, "Bunea Marus", 8.7, 7, 8, 9));
    grupa.adaugaStudent(Student(4, "Bratosin Denistorpila", 9.8, 9, 10, 10));
    grupa.adaugaStudent(Student(5, "Bizon Fox Pookiebear", 7.0, 6, 7, 8));
    grupa.adaugaStudent(Student(6, "Dr. Diaconescu Mircea", 6.5, 5, 5, 6));
    grupa.adaugaStudent(Student(7, "Gurita Mea Gurita Ta", 8.0, 8, 8, 8));
    grupa.adaugaStudent(Student(8, "Nickus Bigus", 9.9, 10, 9, 10));
    grupa.adaugaStudent(Student(9, "Lita Alexandru", 5.0, 4, 5, 5));
    grupa.adaugaStudent(Student(10, "Buinoiu Adriana", 7.5, 6, 7, 8));

    cout << "Studenti cu bursa de studii:" << endl;
    grupa.afiseazaStudentiBursaStudii();
    cout << "\n";

    cout << "Studenti cu bursa de merit" << endl;
    grupa.afiseazaStudentiBursaMerit();
    cout << endl;

    grupa.stergeStudentiNepromovati();

    cout << "Numarul de studenti in grupa: " << grupa.numarStudenti() << endl;


    int nm;
    cout << "Scrieti numarul matricol al studentului: ";
    cin >> nm;
    if (grupa.apartineGrupa(nm)) grupa.afiseazaInfoStudent(nm);
    else cout << "Studentul cu numarul matricol " << nm << " nu apartine grupei.";


    return 0;
}