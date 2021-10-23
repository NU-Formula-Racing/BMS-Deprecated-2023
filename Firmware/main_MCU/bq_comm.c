#include "bq_comm.h"

void setFaultCallback(void (*cb)()) {
  attachInterrupt(digitalPinToInterrupt(fault_pin), pin_ISR, LOW);
}

void calculateCRC(char* msg) {
  
}
