#include <math.h>
#include "stats.h"

/********** Global Variables ***********/
int emailAlertCallCount = 0;
int ledAlertCallCount = 0;

/********* Function Definition ********/
Stats compute_statistics(const float* numberset, int setlength) 
{
    Stats s;
    float current_max = 0;
    float current_min = 0;
    
    s.average = 0;
    s.max = 0;
    s.min = 0;
    
    if(setlength == 0)
    {
        //For empty array send NAN
        s.average = sqrt(-1);
        s.max = sqrt(-1);
        s.min = sqrt(-1);
        return s;
    }
    
    while(setlength--)
    {
        s.average += numberset[setlength];
        if(current_max < numberset[setlength])
        {
            current_max = numberset[setlength];
        }
        if(current_min > numberset[setlength])
        {
            current_min = numberset[setlength];
        }
    }
    
    s.max = current_max;
    s.min = current_min;
    return s;
}

bool check_and_alert(float maxThreshold, alerter_funcptr alerters[], Stats computedStats)
{
    bool alert_signal = false;
    if(maxThreshold > computedStats.max)
    {
        if(emailAlertCallCount == 0)
        {
            alerters;
        }
        if(ledAlertCallCount == 0)
        {
            alerters+1;
        }
        alert_signal = true;
    }
    else
    {
        emailAlertCallCount = 0;
        ledAlertCallCount = 0;
    }
    return alert_signal;
}
