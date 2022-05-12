#include "stats.h"

/********** Global Variables ***********/
int emailAlertCallCount = 0;
int ledAlertCallCount = 0;

/********* Function Definition ********/
struct Stats compute_statistics(const float* numberset, int setlength) 
{
    struct Stats s;
    float current_max = 0;
    float current_min = 0;
    
    s.average = 0;
    
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

void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats)
{
    if(maxThreshold > computedStats)
    {
        if(emailAlertCallCount == 0)
        {
            alerters[0];
        }
        if(ledAlertCallCount == 0)
        {
            alerters[1];
        }
    }
    else
    {
        emailAlertCallCount = 0;
        ledAlertCallCount = 0;
    }
}
