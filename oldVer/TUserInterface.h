#include "stdafx.h"
#include "TWorker.h"
#include "WorkerInfo.h"

struct TUserInterface {
static void BuildUserInterfaceMenu();
static TWorker& EnterWorkerInfo(TWorker& worker);     //ввод информации об одном работнике, запускается в AddWorker
static void FindWorkerInfo(TWorkersInfo* wi);         //найти работника по коду
static void ShowWorkerList(TWorkersInfo* wi);         //показать всех после сортировки
static void DeleteWorker(TWorkersInfo* wi);           //удалить одну запись или все
static void UpdateWorker(TWorkersInfo* wi);           //обновить информацию о работнике
static void AddWorker(TWorkersInfo* wi);              //ввод информации обо всех работниках
static void PrintWorkerInfo(TWorker &worker);         //вывод информации об одном работнике, запускается в ShowWorkerList
};
	




