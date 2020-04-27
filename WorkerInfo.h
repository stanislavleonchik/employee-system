#include "TWorker.h"
class TWorkersInfo {
    TWorker* staff;
    int staff_qty;
	static TWorkersInfo* workersInfo;
public:
    TWorkersInfo();
    TWorker& GetWorker(int _code){return staff[_code];};
    static TWorkersInfo* CreateInstanceDun();
    void GetMaxSalary ();
    char* linSearch(int requiredKey);
    void bubbleSort();
    void FindWorkerInfo(TWorkersInfo* wi, int _num);         //найти работника по коду
    void ShowWorkerList(TWorkersInfo* wi);         //показать всех после сортировки
    void DeleteWorker(TWorkersInfo* wi, int _code);           //удалить одну запись или все
    void UpdateWorker(TWorkersInfo* wi);           //обновить информацию о работнике
    void AddWorker(const TWorker& worker);              //ввод информации обо всех работниках
};

