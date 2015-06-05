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
  if (!h || !v) { return ERR_MISSING_H_OR_V; }
  FILE *fp;
  char active[20];
  char cvt[70];
  char modeline[100];
  char newmode[130];
  char addmode[65];
  char mode[21];
  char setres[60];

  fp = popen("/usr/bin/env xrandr 2> /dev/null | grep -E ' connected (primary )?[1-9]+' | sed -e 's/\\([A-Z0-9]\\+\\) connected.*/\\1/' | cut -d' ' -f1", "r");
  if (!fp) { return ERR_UNABLE_TO_CHANGE_RESOLUTION; }
  fgets(active, sizeof(active) - 1, fp);

  sprintf(cvt, "/usr/bin/env cvt %d %d | grep 'Modeline' | sed 's/Modeline//'", h, v);
  fp = popen(cvt, "r");
  fgets(modeline, sizeof(modeline) - 1, fp);

  strcpy(mode, strtok(modeline, "\""));
  strcat(mode, strtok(NULL, "\""));


  strcpy(newmode, "/usr/bin/env xrandr --newmode ");
  strcat(newmode, modeline);

  system(newmode);

  strcpy(addmode, "/usr/bin/env xrandr --addmode ");
  strcat(addmode, active);
  strcat(addmode, " ");
  strcat(addmode, mode);

  system(addmode);
  strcpy(setres, "/usr/bin/env xrandr --output ");
  strcat(setres, active);
  strcat(setres, " --mode ");
  strcat(setres, mode);

  system(setres);

  return 0;
}

#endif
