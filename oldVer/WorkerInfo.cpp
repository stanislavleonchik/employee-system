#include "stdafx.h"
#include "WorkerInfo.h"
//сортировка пр€мым выбором
void TWorkersInfo::bubbleSort() {
TWorker x;
	for (int i = 0; i < numberOfWorkers; i++) {
		for (int j = numberOfWorkers-1; j > i; j--) {
			if (GetWorker(j - 1).GetCode() > GetWorker(j).GetCode()) {
				x = GetWorker(j);
				GetWorker(j) = GetWorker(j - 1);
				GetWorker(j - 1) = x;
			}
		}
	}
}
//линейный поиск по коду
char* TWorkersInfo::linSearch(int requiredKey) {
	int i=0;
	static char keyName[30];
	do {
		i++;
	} while (i <= max_count_workers && GetWorker(i).GetCode() != requiredKey);

	if (i == (max_count_workers+1)) {
		cout << "код не найден" << endl;
	}

	strcpy_s(keyName, GetWorker(i).GetName());
	return keyName;
}
/*
void TWorkersInfo::GetMaxSalary () {
	float max_salary = GetWorker(0).GetSalary();
	char name[30];
	strcpy_s(name, GetWorker(0).GetName());
	for (int i=1; i< max_count_workers; i++){
		if(GetWorker(i).GetSalary()>max_salary) {
		max_salary=GetWorker(i).GetSalary();
		strcpy_s(name, GetWorker(i).GetName());
		}
	}
	cout<<"ћаксимальный оклад ="<<max_salary<<endl;
	cout<<"»м€ сотрудника ="<<name<<endl;
}
*/
TWorkersInfo::TWorkersInfo() = default;

TWorkersInfo* TWorkersInfo::CreateInstanceDun(TWorkersInfo* workersInfo){
    if (workersInfo == nullptr){
        workersInfo = new TWorkersInfo();
            }
    return workersInfo;
}