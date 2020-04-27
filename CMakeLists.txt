cmake_minimum_required(VERSION 3.15)
project(TWorkerTWorkersStaff)

set(CMAKE_CXX_STANDARD 20)

add_executable(TW Task13.cpp stdafx.h targetver.h TUserInterface.cpp TUserInterface.h TWorker.cpp TWorker.h WorkerInfo.cpp WorkerInfo.h)