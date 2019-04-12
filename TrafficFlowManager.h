#include <iostream>
#include <fstream>
#include "ListNode.h"
#include "GenDoublyLinkedList.h"
#include "GenQueue.h"
#include <iomanip>  //precision modifier(2 decimal places)
using namespace std;

using namespace std;

class TrafficFlowManager
{
public:
  TrafficFlowManager(); //Constructor
  ~TrafficFlowManager();//Destructor


private:
  ifstream OfficeTraffic;
  int NumOFStudents = 0, NumOFWindows, timer = 0, Idle, NumTwindows = 0;
  int x, y, z, sum = 0, S_WaitTimes = 0;
  //Student Calculations
  double S_mean, S_median, I_median, longestS,longestW, student_WAIT_10minOVER, total;
  //Window Idle calculations
  double idle_mean, idle_long, Window_Idle_5minOVER;
};
