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
void TWorker::SetName(char *value) {
    if (strcmp(" ", value) != 1){
        strcpy(name, value);
    }
}
void TWorker::SetCode(int value) {
    if (value != 0){ code = value;
    }
}
void TWorker::SetSalary(float _salary) {
    if (_salary != 0){salary = _salary;
    }
}