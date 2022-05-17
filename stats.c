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
    bool alert_signal = FALSE;
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
        alert_signal = TRUE;
    }
    else
    {
        emailAlertCallCount = 0;
        ledAlertCallCount = 0;
    }
    return alert_signal;
}
