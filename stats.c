#include <math.h>
#include "stats.h"

/********** Global Variables ***********/
int emailAlertCallCount = 0;
int ledAlertCallCount = 0;

/********* Function Definition ********/
Stats compute_statistics(const float* numberset, int setlength) 
{
    Stats s;
    int length = setlength;
    float current_max;
    float current_min;
    
    s.average = 0;
    s.max     = 0;
    s.min     = 0;
    
    if(setlength == 0)
    {
        //For empty array send NAN
        s.average = sqrt(-1);
        s.max     = sqrt(-1);
        s.min     = sqrt(-1);
    }
    else
    {
        current_max = numberset[setlength-1];
        current_min = numberset[setlength-1];
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
  
        s.average = s.average/length;
        s.max = current_max;
        s.min = current_min;
    }
    return s;
}


bool check_and_alert(float maxThreshold, alerter_funcptr alerters[], Stats computedStats)
{
    bool alert_signal = false;
    
    if(maxThreshold > computedStats.max)
    {
        if(emailAlertCallCount == 0)
        {
            alerters[0]();
        }
        if(ledAlertCallCount == 0)
        {
            alerters[1]();
        }
        alert_signal = true;
    }
    else
    {
        emailAlertCallCount = 0;
        ledAlertCallCount   = 0;
    }
    return alert_signal;
}
