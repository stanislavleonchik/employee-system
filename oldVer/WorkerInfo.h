#include "TWorker.h"

#define max_count_workers 5
//const int max_count_workers=20; так не делать, делать через #define, но в колледже работает только через конст


class TWorkersInfo {
	TWorker staff [max_count_workers];
	static TWorkersInfo* workersInfo;
public:
    TWorkersInfo();
    TWorker tmp;  //пустой структурный объект для операции удаления
    int numberOfWorkers = 0; //счётчик работников
//	void GetMaxSalary ();
	void bubbleSort();
	char* linSearch(int requiredKey);
	TWorker& GetWorker(int _num){return staff[_num];};
    TWorker& GetTMP(){return tmp;};
    static TWorkersInfo* CreateInstanceDun(TWorkersInfo* workersInfo);
};

