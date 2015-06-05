#ifdef __linux__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers.h"

Resolution fetchRes() {

  FILE *fp;
  char screenSize[12];
  char *pEnd;
  Resolution res;
  fp = popen("/usr/bin/env xrandr 2> /dev/null | grep \\* | cut -d ' ' -f4", "r");
  if (!fp) { return res; }
  fgets(screenSize, sizeof(screenSize) - 1, fp);

  res.width = strtol(strtok(screenSize, "x"), &pEnd, 10);
  res.height = strtol(strtok(NULL, "x"), &pEnd, 10);

  pclose(fp);

  return res;

}

int changeRes(int h, int v) {


}

#endif
