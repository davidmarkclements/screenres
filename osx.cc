/*
*  osx.cc
*  David Mark Clements 2015
*  @davidmarkclem
*
*  Based on 'setgetscreenres' 
*   juanfc 2009-04-13
*   Based on newscreen
*      Created by Jeffrey Osterman on 10/30/07.
*      Copyright 2007 Jeffrey Osterman. All rights reserved. 
*      PROVIDED AS IS AND WITH NO WARRANTIES WHATSOEVER
*      http://forums.macosxhints.com/showthread.php?t=59575
*
*/

#ifdef __APPLE__


#include <ApplicationServices/ApplicationServices.h>

#include "headers.h"

bool MyDisplaySwitchToMode (CGDirectDisplayID display, CFDictionaryRef mode);

Resolution fetchRes() {
    CGRect screenFrame = CGDisplayBounds(kCGDirectMainDisplay);
    CGSize screenSize  = screenFrame.size;
    Resolution res = {
      .width = screenSize.width,
      .height = screenSize.height
    };
    return res;
}

int changeRes (int h, int v) {
  CFDictionaryRef switchMode;   // mode to switch to
  CGDirectDisplayID mainDisplay;  // ID of main display
  CFDictionaryRef CGDisplayCurrentMode(CGDirectDisplayID display);
  
  if (!h || !v) {
    return ERR_MISSING_H_OR_V;
  }

  mainDisplay = CGMainDisplayID();
  switchMode = CGDisplayBestModeForParameters(mainDisplay, 32, h, v, NULL);

  if (!MyDisplaySwitchToMode(mainDisplay, switchMode)) {
    return ERR_UNABLE_TO_CHANGE_RESOLUTION;
  }

  return 0;
}

bool MyDisplaySwitchToMode (CGDirectDisplayID display, CFDictionaryRef mode) {
  CGDisplayConfigRef config;
  if (CGBeginDisplayConfiguration(&config) == kCGErrorSuccess) {
    CGConfigureDisplayMode(config, display, mode);
    CGCompleteDisplayConfiguration(config, kCGConfigureForSession );
    return true;
  }
  return false;
}

#endif
