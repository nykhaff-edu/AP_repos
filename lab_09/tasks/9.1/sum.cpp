#include "sum.h"

#include <math.h>

#include "dod.h"
#include "var.h"

using namespace nsDod;
using namespace nsVar;

void nsSum::sum() {
  n = 0;
  a = 1;
  S = a;
  do {
    n++;
    dod();
    S += a;
  } while (fabs(a) > eps);
}