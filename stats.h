
typedef struct Stats
{
  float average;
  float max;
  float min;
}Stats;

extern int emailAlertCallCount;
extern int ledAlertCallCount;

typedef void (*alerter_funcptr)();
bool check_and_alert(float maxThreshold, alerter_funcptr alerters[], Stats computedStats);
Stats compute_statistics(const float* numberset, int setlength);

