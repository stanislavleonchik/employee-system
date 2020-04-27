#include "stdafx.h"
#include "TWorker.h"

TWorker::TWorker (){   //инициализация по умолчанию
	strcpy_s(name, " ");
	code = 0;
	salary = 0.0;
}
TWorker::TWorker(char* _name, int _code, float _salary){ //инициализация с параметрами
    strcpy_s(name, _name);
	code = _code;
	salary = _salary;
}
char* TWorker::GetName(){return name;};
int TWorker::GetCode(){return code;};
float TWorker::GetSalary(){return salary;};
void TWorker::SetName(char *value) {
    if (strcmp(" ", value) != 1){
        strcpy(name, value);
    }
}
void TWorker::SetCode(int value) {
    if (value != 0){ code = value;}}
void TWorker::SetSalary(float _salary) {
    if (_salary != 0){salary = _salary;}}
istream& operator >> (istream& os, TWorker& c){
    os >> c.name >> c.code >> c.salary;
    return os;
}
ostream& operator << (ostream& os, TWorker& c){
    os << "(Name: " << c.name << ", code: " << c.code << ", salary: " << c.salary << ")" << endl;
    return os;
}
