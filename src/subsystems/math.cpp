#include "main.h"

//returns sign of number
int getSign(double number) {
  //defaulted 1 (positive), can be changed to -1 (negative)
  if(number < 0) {
    return -1;
  }
  return 1;
}
