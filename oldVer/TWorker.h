#pragma once //без этой директивы ошибка "переопределение типа TWorker"
class TWorker {
    char name [30];
    int code;
    float salary;
public:
TWorker ();  //инициализатор по умолчанию
TWorker (char* _name, int _code, float _salary);
char* GetName(){return name;};
int GetCode(){return code;};
float GetSalary(){return salary;};
void SetName(char* value);
void SetCode(int value);
void SetSalary(float _salary);
};