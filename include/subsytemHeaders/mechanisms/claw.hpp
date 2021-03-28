#include "main.h"

static bool autoClaw;
static bool aquiredObject;
void openClaw();
void closeClaw();
void checkClaw();
void clawControl();
void control(double power);
void updatePID();
