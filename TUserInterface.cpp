#include "stdafx.h"
#include "TUserInterface.h"
#include "WorkerInfo.h"
#include "TWorker.h"
void TUserInterface::UserMenu() {
	TWorkersInfo* wi = TWorkersInfo::CreateInstanceDun();
	int num = 0; int code;
    for (; num != 6;) {
		cout << "Меню\n"
		        "1 - Добавить сотрудника\n"
		        "2 - Найти информацию о сотрудник\n"
                "3 - Изменить информацию о сотруднике\n"
                "4 - Показать список сотрудников"
                "5 - Удалить сотрудника (или всех сотрудников)\n"
                "6 - Выход\n"
                "7 - Показать сотрудника с максимальной зп\r\n"
                "Введите номер опции (1-7)\n";
        while (!(cin >> num) || cin.get() != '\n' || isdigit(num) ) {
            cout << "Wrong operation. Enter again !\n";
            cin.clear();
            cin.sync();
            cout << "Enter number of operation: ";
        }
		switch (num)
		{
		    case 1:{
		        TWorker data;
		        cin >> data;
                wi->TWorkersInfo::AddWorker(data);
                break;}
		    case 2:
                cout << "Введите код сотрудника" << endl;
                cin >> code;
                wi->FindWorkerInfo(wi, code);break;
//		    case 3:
//                TWorker data;
//		        cin >> data;
//		        wi->UpdateWorker(wi);break;
		    case 4:
                wi->ShowWorkerList(wi);break;
//		    case 5:
//		        cin >> code;
//                wi->DeleteWorker(wi, code);break;
//		    case 6:
//		    	break;
//	        case 7:
//	            wi->GetMaxSalary();break;
//		    default:
		    	cout << "Введен неправильный номер"<< endl;
		}
	}
}