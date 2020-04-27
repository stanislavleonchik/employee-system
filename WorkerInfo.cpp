#include "stdafx.h"
#include "TUserInterface.h"
#include "WorkerInfo.h"
TWorkersInfo* TWorkersInfo::workersInfo = nullptr;
void TWorkersInfo::bubbleSort() {
    TWorker x;
	for (int i = 0; i < staff_qty; i++) {
		for (int j = staff_qty - 1; j > i; j--) {
			if (GetWorker(j - 1).GetCode() > GetWorker(j).GetCode()) {
				x = GetWorker(j);
				GetWorker(j) = GetWorker(j - 1);
				GetWorker(j - 1) = x;
			}
		}
	}
}
char* TWorkersInfo::linSearch(int requiredKey) {//линейный поиск по коду
	int i=0;
	char _name[30];
	do {i++;
	} while (i <= staff_qty && GetWorker(i).GetCode() != requiredKey);
	if (i == (staff_qty + 1)) {
		cout << "код не найден" << endl;
	}
	strcpy_s(_name, GetWorker(i).GetName());
	return _name;
}
void TWorkersInfo::GetMaxSalary () {
	float max_salary = GetWorker(0).GetSalary();
	char name[30];
	strcpy_s(name, GetWorker(0).GetName());
	for (int i=1; i< staff_qty; i++){
		if(GetWorker(i).GetSalary()>max_salary) {
		max_salary=GetWorker(i).GetSalary();
		strcpy_s(name, GetWorker(i).GetName());
		}
	}
	cout<<"Максимальный оклад = "<<max_salary<<endl;
	cout<<"Имя сотрудника = "<<name<<endl;
}
TWorkersInfo::TWorkersInfo(){
    staff = nullptr;
    staff_qty = 0;
}
TWorkersInfo* TWorkersInfo::CreateInstanceDun(){
    if (workersInfo == nullptr) {
        workersInfo = new TWorkersInfo();
    }
    return workersInfo;
}
void TWorkersInfo::AddWorker(const TWorker& worker) {
    if(staff != nullptr){
        auto* temp_staff = new TWorker[++staff_qty];
        for(int i = 0; i < staff_qty - 1; i++){
            temp_staff[i] = staff[i];
        }
        temp_staff[staff_qty - 1] = worker;
        delete staff;
        staff = temp_staff;
    }
    else {
        staff = new TWorker[++staff_qty];
    }
    staff[staff_qty - 1] = worker;
}
void TWorkersInfo::UpdateWorker(TWorkersInfo* wi) {
    int _code;   //номер записи, которую нужно обновить
    cout << "Введите номер записи, которую необходимо изменить" << endl;
    cin >> _code;

    cout << "Введите новое имя: " ;
    char newname[30];
    cin >> newname;
    wi->GetWorker(_code - 1).SetName(newname);

    cout << "Введите новый код: " ;
    int num;
    cin >> num;
    wi->GetWorker(_code - 1).SetCode(num);

    cout << "Введите новый оклад: " ;
    float newsalary;
    cin >> newsalary;
    wi->GetWorker(_code - 1).SetSalary(newsalary);

    cout << "Вы изменили запись № " << _code << endl;
}
void TWorkersInfo::DeleteWorker(TWorkersInfo* wi, int _code) {
    if (_code < 0 && _code > staff_qty) {
        cout << "Не существует записи с таким номером" << endl;}
    TWorker* tmp_staff = nullptr;
    int index = 0; int j = 0;
    for (; index < staff_qty; index++){
        if (wi->staff[index].GetCode() == _code); break;
    }
    tmp_staff = new TWorker[--staff_qty];
    for (int i = 0; i < staff_qty; i++){
        if (i != index){
            tmp_staff[i] = staff[j++];
        }
        }
    delete staff;
    staff = tmp_staff;
}
/*    int delWorkNum;
    cout << "Введите номер записи, которую необходимо удалить" <<endl;
    cout << "Если необходимо удалить все записи, введите 0"<<endl;
    cin >> delWorkNum;
    if (delWorkNum > 0 && delWorkNum <= staff_qty) {
        for (int i = (delWorkNum - 1); i < staff_qty; i++) //цикл для удаления заданной записи, начинаем цикл с удаляемой записи
            wi->GetWorker(i) = wi->GetWorker(i+1);  //замещаем текущую запись следующей
        cout << "Запись удалена" << endl;
        wi-> staff_qty -= 1;
    }
    if (delWorkNum == 0) {
        for (int i = 0; i < staff_qty; i++) //цикл по все записям от первой до staff_qty
            wi->GetWorker(i) = wi->GetTMP();  //замещаем каждую структуру в массиве пустой структурой
        cout << "Все записи удалены" << endl;
        wi-> staff_qty = 0;
    }
    if (delWorkNum < 0 && delWorkNum > staff_qty) {
        cout << "Не существует записи с таким номером" << endl;
    }
}*/
void TWorkersInfo::ShowWorkerList(TWorkersInfo* wi) {
    wi->bubbleSort(); //сортировка по коду
    for  (int i=0; i< wi->staff_qty; i++) { //вывод информации обо всех работниках
        cout << wi->GetWorker(i);
    }
}
void TWorkersInfo::FindWorkerInfo(TWorkersInfo* wi, int _code) {  //линейный поиск
    cin >> _code;
    cout << linSearch(_code) << endl;
}