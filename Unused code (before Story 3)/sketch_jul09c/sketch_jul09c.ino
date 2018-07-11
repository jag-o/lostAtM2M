#include <ArduinoUnit.h>
bool is_a_leap_year(int year)
{
  return (year % 4 == 0 and not year % 100 == 0);
}

bool is_an_atypical_leap_year(int year)
{
  return (year % 400 == 0);
}

test(a_typical_common_year_return_false)
{
  assertFalse(is_a_leap_year(2001));  
}

test(a_typical_leap_year_return_true)

{
  assertTrue(is_a_leap_year(1996));
}

test(an_atypical_common_year_return_false)
{
  assertFalse(is_an_atypical_leap_year(1900));
}

test(an_atypical_leap_year_return_true)
{
  assertTrue(is_an_atypical_leap_year(2000));
}
void setup() {
  Serial.begin(115200);
  bool lol = is_a_leap_year(1982);
  if(lol == true) {
    Serial.write("It is a common leap year!\n");
  } else if (lol == false) {
    Serial.write("It is not a common leap year!\n");
  } 
}

void loop() {
  Test::run();
}
