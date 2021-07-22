#pragma once
#include"person.h"
using namespace std;
void printFullStudent(const Person & student)
{
    cout<< student.nazwa()<<" srednia:"<< std::setw(5)<<averageScore(student)<<" suma:"
    <<std::setw(5)<<student.getSum()<<" oceny: " << std::setw(6);
    for(auto const &elem: student.oceny())
    {
        cout<<elem<<setw(6);
    }
    cout<<endl;
}
void printStudent(const Person & student)
{
    std::cout<<student.nazwa()<<":"<< std::setw(5);
    for(auto const &elem: student.oceny())
    {
        std::cout << elem << std::setw(5);
    }
    cout<<endl;
}
bool greaterAverage(const Person & stud1, const Person & stud2)
{
    return averageScore(stud1) > averageScore(stud2);
}

class Data
{
public:
	void operator+=(const Person & osoba)
    {
        _studenci.push_back(osoba);
    }
    void fullprint()
    {
    	for_each(_studenci.begin(), _studenci.end(), printFullStudent);
    }
    Person& operator[](int i)
    {
        return _studenci[i];
    }
    Data& sort(int n)
    {
        int s=n+10;
	    for_each(_studenci.begin(), _studenci.end(), [&s](Person p){if(p.dlugosc()<s) s=p.dlugosc();});
	    if(n>=s-1){
	      std::cout<<"Indeks "<<n<<" nieprawidlowy!\n";
	      return *this;
	    }
        std::sort(_studenci.begin(), _studenci.end(), [n](Person p1, Person p2){ return p1[n]<p2[n]; });
        return *this;
    }
    void print()
    {
        std::for_each(_studenci.begin(), _studenci.end(), printStudent);
    }
    Data& sortBy(bool (*compare)(const Person &, const Person &))
    {
        std::sort(_studenci.begin(),_studenci.end(), compare);
        return *this;
    }
private:
	vector<Person> _studenci;
};
