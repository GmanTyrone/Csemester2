#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
int main()
{
    //scans employees
    int emp;

    cin >> emp;
    //Sets array of employees
    //Array of "employees" rows and 15 columns
    int n[emp], set[emp][15];


    //Fills the array with -1
    for (int i = 0; i < emp; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            set[i][j] = -1;
        }
    }

    //Fills the arrays
    for (int i = 0; i < emp; i++)
    {
        //Reads the employee number of friends
        cin >> n[i];

        //For "the number of friends" reads the friends id and puts it in the set array
        for (int j = 0; j < n[i]; j++)
        {
            cin >> set[i][j];
        }
    }

    //t is the number of test cases. test is the current test employee
    //Max is the current max an day the current day
    //max and maxday change only when max
    int t, test, know[emp], day = 0, max = 0, count = emp, peo[emp], last = 0, temp,maxday;
    int total;
    queue<int> q;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> test;
        day=0;

        //fills the know array with "123"
        for(int j=0;j<emp;j++){
            know[j]=123;
        }

        //Just checks if the test has 0 friends
        if (n[test] == 0)
        {
            cout << "0" << endl;
        }

        else
        {
            //pushes the test into the queue and sets its "size"=last to 1
            q.push(test);
            last = 1;
            count = emp;

            //puts the test into the last position of the know array
            know[emp - 1] = test;
            count--;
            max=0;

            //Since the queue has now the test case it is not empty
            while (!q.empty())
            {
                //Set the total to 0, it represents the number of people who heard the news that day
                total = 0;

                //from 0 to the size of the queue
                for (int z = 0; z < last; z++)
                {

                    //from 0 to the test id of the employee that is in the queue "q.front"
                    //looks into the employees array
                    for (int j = 0; j < n[q.front()]; j++)
                    {
                        //from 0 to number of employees
                        for (int k = 0; k < emp; k++)
                        {

                            //Checks if the employee knows the person
                            //thats the use of filling it with 123 earlier, because 123 wont be a valid employee
                            if (set[q.front()][j] == know[k])
                            {

                                break;
                            }

                            //Now here it looks if k is the last test case
                            if (k == emp - 1)
                            {
                                //if the
                                know[count - 1] = set[q.front()][j];
                                count--;

                                //pushes the employees the test employee knows into the queue
                                q.push(set[q.front()][j]);

                                //adds one employee to the total of people who heard the news and 1 to temp
                                total = total + 1;
                                temp++;
                            }
                        }
                    }
                    //pops the value from the current value from the queue
                    q.pop();
                }

                //adds one day
                //the size becomes temp since is the number of people added menus the one popped
                //temp is then set to 0 again
                day++;
                last = temp;
                temp = 0;

                //looks if the queue is empty, if it is it exits the loop
                if(last==0){
                    break;
                }

                //Checks to see if the total of people who heard the news is the current max
                //if it is then it changes the values
                if (total > max)
                {
                    max = total;
                    maxday=day;
                }
            }

            //prints the values
            cout << max<<" "<<maxday<<endl;
        }
    }
    return 0;
}
