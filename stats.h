
typedef struct Stats
{
  float average;
  float max;
  float min;
}Stats;

typedef void (*alerter_funcptr)();
void check_and_alert(float maxThreshold, alerter_funcptr alerters[], Stats computedStats);

Stats compute_statistics(const float* numberset, int setlength);

extern int emailAlertCallCount;
extern int ledAlertCallCount;
