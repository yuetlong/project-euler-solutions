#include <stdio.h>

int main(void){

  int weekday = 1; // 1 Jan 1900 was a Monday
  int answer = 0;
  
  for (int year = 1900; year <= 2000; year++){
    for (int month = 1; month <= 12; month++){
      int ds;
      
      if (month == 9 || month == 4 || month == 6 || month == 11)
        ds = 30;
      else if (month == 2)
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400  == 0))
           ds = 29;
        else
          ds = 28;
      else
        ds = 31;
      
      for (int day = 1; day <= ds; day++){

        if (year > 1900 && day == 1 && weekday == 0)
          answer++;

        if (++weekday == 7)
          weekday = 0;
      }
    }
  }
  printf("%d\n",answer);
}
