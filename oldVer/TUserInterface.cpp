#include "stdafx.h"
#include "TUserInterface.h"
void TUserInterface::BuildUserInterfaceMenu() {
	TWorkersInfo* wi = new TWorkersInfo;
	TWorkersInfo::CreateInstanceDun(wi);
	int num = 0;
	for (; num != 6;) {
		cout << "Меню" <<endl;
		cout << "1 - Добавить сотрудника"<< endl;                           // AddWorker
		cout << "2 - Найти информацию о сотруднике"<< endl;                 //FindWorkerInfo
		cout << "3 - Изменить информацию о сотруднике"<< endl;              //UpdateWorker
		cout << "4 - Показать список сотрудников"<< endl;                   //ShowWorkerList
		cout << "5 - Удалить сотрудника (или всех сотрудников)"<< endl;     //DeleteWorker  
		cout << "6 - Выход"<< endl; 
		cout << endl;

		cout << "Введите номер опции (1-6) " << endl;
		cin >> num;

		switch (num) {
		case 1:
			AddWorker(wi); break;
		case 2: 
			FindWorkerInfo(wi);break;
		case 3:
			UpdateWorker(wi);break;
		case 4:
			ShowWorkerList(wi);break;
		case 5:
			DeleteWorker(wi);break;
		case 6:
			break;
		default:
			cout << "Введен неправильный номер"<< endl;
		}
	}
}

void TUserInterface::AddWorker(TWorkersInfo* wi) {
	if (wi->numberOfWorkers < max_count_workers) {
		cout << "Номер записи: " << wi->numberOfWorkers + 1 << endl;
		EnterWorkerInfo(wi->GetWorker(wi->numberOfWorkers));
		wi->numberOfWorkers += 1;
	}
	else {
		cout << "Список переполнен" << endl;
	}	
}


void TUserInterface::UpdateWorker(TWorkersInfo* wi) {
	int UpdateWorkNum;   //номер записи, которую нужно обновить
	cout << "Введите номер записи, которую необходимо изменить" << endl;
	cin >> UpdateWorkNum;

	cout << "Введите новое имя: " ;
	char newname[30];
	cin >> newname;
	wi->GetWorker(UpdateWorkNum - 1).SetName(newname);

	cout << "Введите новый код: " ;
	int num;
	cin >> num;
	wi->GetWorker(UpdateWorkNum - 1).SetCode(num);

	cout << "Введите новый оклад: " ;
	float newsalary;
	cin >> newsalary;
	wi->GetWorker(UpdateWorkNum - 1).SetSalary(newsalary);

	cout << "Вы изменили запись № "<< UpdateWorkNum << endl;
}


void TUserInterface::DeleteWorker(TWorkersInfo* wi) {
	int delWorkNum; //номер записи, которую нужно удалить
	cout << "Введите номер записи, которую необходимо удалить" <<endl;
	cout << "Если необходимо удалить все записи, введите 0"<<endl;
	cin >> delWorkNum;
	if (delWorkNum > 0 && delWorkNum <= max_count_workers) {
		for (int i = (delWorkNum - 1); i < max_count_workers; i++) //цикл для удаления заданной записи, начинаем цикл с удаляемой записи
			wi->GetWorker(i) = wi->GetWorker(i+1);  //замещаем текущую запись следующей
		cout << "Запись удалена" << endl;
		wi->numberOfWorkers -= 1;
	}
	if (delWorkNum == 0) {
		for (int i = 0; i < max_count_workers; i++) //цикл по все записям от первой до max_count_workers
			wi->GetWorker(i) = wi->GetTMP();  //замещаем каждую структуру в массиве пустой структурой
		cout << "Все записи удалены" << endl;
		wi->numberOfWorkers = 0;
	}
	if (delWorkNum < 0 && delWorkNum > max_count_workers) {
		cout << "Не существует записи с таким номером" << endl;
	}
}

void TUserInterface::ShowWorkerList(TWorkersInfo* wi) {
	
	wi->bubbleSort(); //сортировка по коду
	
	for  (int i=0; i< wi->numberOfWorkers; i++) { //вывод информации обо всех работниках
		cout << i + 1 <<". ";
		PrintWorkerInfo(wi->GetWorker(i));
	}
}

void TUserInterface::FindWorkerInfo(TWorkersInfo* wi) {  //линейный поиск
	int requiredKey;
	cout << "Какой код необходимо найти? " << endl;
	cin >> requiredKey;
	cout << wi->linSearch(requiredKey) << endl;
}
void TUserInterface::PrintWorkerInfo(TWorker& worker) { //вывод информации об одном работнике
	cout<<"Имя сотрудника: "<<worker.GetName() << endl;
	cout<<"Код сотрудника: "<<worker.GetCode() << endl;
	cout<<"Оклад сотрудника: "<<worker.GetSalary() << endl;
}
TWorker& TUserInterface::EnterWorkerInfo(TWorker& worker) {
    char SampleName [30];
    int num;
    float aFloat;
    cout << "Введите имя сотрудника: ";
    cin >> SampleName;
    worker.SetName(SampleName);
    cout << "Введите код сотрудника: ";
    cin >> num;
    worker.SetCode(num);
    cout << "Введите оклад сотрудника: ";
    cin >> aFloat;
    worker.SetSalary(aFloat);
    return worker;
}

