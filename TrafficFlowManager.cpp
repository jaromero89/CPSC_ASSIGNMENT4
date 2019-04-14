#include "TrafficFlowManager.h"
using namespace std;


TrafficFlowManager::TrafficFlowManager()
{
  timer = 0;
  NumOFWindows = 0;
  idle = Window_Idle_5minOVER = idle_mean = idle_long = 0;
  NumOFStudents = 0;
  S_WaitTime = 0;
  z = longestW = 0;
  sum = 0;
  mean = 0.0;
  total = 0;
  t = 0;
  median = I_median = tudent_WAIT_10minOVER = 0;
}

TrafficFlowManager::~TrafficFlowManager() {}

int TrafficFlowManager::startTrafficFlowManager (string filename)
{
  OfficeTraffic.open (filename);
  //Error message will occur if file is incorrect
  if (!OfficeTraffic) {
    cout << "Error has occurred. Please re-enter the file name again -" << endl;
    exit(1);
  }


/*GenQueue will similate the registrar office in a sense that as  students arrive in the registrar’s office,
 they will wait in a queue. When a window becomes available they will exit the queue and remain at the service
 window for however long they need.
*/
 ////Set to rules specified in Assigment 4 problem document
  GenQueue <int> S_Arrival;   //S_Arrival: Pending arrival time of the student
  GenQueue <int> NumOFStudents; //NumOFStudents: GenQueue will keep count number of students in the queue
  GenQueue <int> S_TimeNeeded; //S_TimeNeeded: The time that student needs while being seen at registrar winndow
  GenQueue <int> S_ArrivalTimeTracker;  //S_ArrivalTimeTracker : Keeps track at the number of student whom arrive at a specific time
  GenQueue <int> Start_Time;    //capture the start time when student enters a queue
  GenDoublyLinkedList <int> S_WaitTime; //S_WaitTime: Gets student wait time in the queue
  GenDoublyLinkedList <int> T_windows;  //windows busy-idle time

  OfficeTraffic >> a;
  NumOFWindows = a;
  int RegistarWindow[NumOFWindows] = {};//Array used to store the number of windows

  while (!OfficeTraffic.eof()) { //This flag is set by all standard input operations when the End-of-File is reached in the sequence associated with the stream.(http://www.cplusplus.com/reference/ios/ios/eof/)
    OfficeTraffic >> a;
    S_Arrival.enqueue(a);
    OfficeTraffic >> a;
    S_ArrivalTimeTracker.enqueue(a);
    for (int i = 0; i < S_ArrivalTimeTracker.back(); i++) {
      OfficeTraffic >> a;
      Start_Time.enqueue(a);
    }
  }

  while (true) {

    while (T_windows.contains(0) == true)	{  //removing all 0's from twindows
      T_windows.remove(0);//Process of removing zeros
      --NumTwindows;//decrements "NumTwindows"
    }
    //Citation: https://www.tutorialspoint.com/data_structures_algorithms/dsa_queue.htm
//This if and for loop puts the students in the quene
    if (timer == arrival.front()) {
      for (int i = 1; i <= S_ArrivalTimeTracker.front(); i++) {
        NumOFStudents.enqueue(i);
        Start_Time.enqueue(timer);
        ++nstudents;
      }
      S_Arrival.dequeue();
      S_ArrivalTimeTracker.dequeue();
    }
    // Equation used to find what windows that are available
    idle = NumOFWindows - NumTwindows;

    if (idle != 0)// If idle where to equal zero , no windows would be available
    {
      if (NumOFStudents.isEmpty() != true)
      {
        b = NumOFStudents;
        if (idle > NumOFStudents)
        {
          for (int j = 0; j < b; j++)
          {		//remove the students from the queue and
                                          //take them to the idle windows as applicable


             NumOFStudents.dequeue();
             S_WaitTime.sort (timer, Start_Time.front(), sum, I_median);
             median = I_median;
             I_median = 0;
             if (timer - Start_Time.front() > 10) {
               ++tudent_WAIT_10minOVER;
             }
             twindows.addBack (Start_Time.front());
             Start_Time.dequeue();
             Start_Time.dequeue();
             ++NumTwindows;
             --NumOFStudents;
             ++S_WaitTime;
           }
        }
        else if ((idle < NumOFStudents) || (idle == NumOFStudents)) {
          for (int j = 0; j < idle; j++) {		//remove the students from the queue and
                                       //take them to the idle windows as applicable
             NumOFStudents.dequeue();
             S_WaitTime.sort (timer, Start_Time.front(), sum, I_median);
             cout << "Sum: " << sum << endl;
             median = I_median;  //median set equal to Idle median
             I_median = 0;//italize the idle median

             if (timer - Start_Time.front() > 10)//Algoritm used to find to find the amount of students waiting over 10 minutes
             {
               ++student_WAIT_10minOVER; // adds each and every student which waits over 10 minutes
             }
             twindows.addBack (Start_Time.front());
             Start_Time.dequeue();
             Start_Time.dequeue();
             ++NumTwindows;
             --NumOFStudents;
             ++S_WaitTime;
           }
        }
       }
    }

    idle_long = NumOFWindows - NumTwindows;//Now I was able to calculate the longest idle time

    for (int i = 0; i < idle_long; i++) {
      myWindow[i] = myWindow[i] + 1;
    }

    if (T_windows.isEmpty() != true) {	//reducing all the elements in twindows by 1
      T_windows.reduce();
    }

    if (S_Arrival.isEmpty() == true) {	//if twindows is empty at the end of timer i,
                                  //exit the simulation as there is nothing more to TrafficFlowManager
      if (T_windows.isEmpty() == true) {
        break;
      }
    }

    ++timer;
  }

  for (int i = 0; i < NumOFWindows; i++) {
    if (myWindow[i] == 0) {
      continue;
    }
    else {
      myWindow[i] = myWindow[i] - 1;
    }
  }

  for (int i = 0; i < NumOFWindows; i++) {
    t = t + myWindow[i];
    if (l < myWindow[i]) {
      l = myWindow[i];
    }
    if (myWindow[i] > 5) {
      ++Window_Idle_5minOVER;//Finds windows which are idle over 5 minutes
    }
  }

  total = sum;
  mean = total/S_WaitTime; //Mean is equal to the every total divided by the studennt wait time
  idle_mean = t/NumOFWindows;

  ///////////////////////////////
  //////Print Results///////////
  /////////////////////////////

  cout << "The student mean waittime is " << mean << " mins" << endl;
  cout << "The median student wait time is " << median << " mins" << endl;
  cout << "The longest student wait time is " << S_WaitTime.back() << " mins" << endl;
  cout << "The number of students waiting over 10 minutes is " << tudent_WAIT_10minOVER << endl;
  cout << "The mean window idle time is " << idle_mean << " mins" << endl;
  cout << "The longest window idle time is " << idle_long << " mins" << endl;
  cout << "Number of windows idle for over 5 minutes is " << Window_Idle_5minOVER << endl;

  OfficeTraffic.close();
}
