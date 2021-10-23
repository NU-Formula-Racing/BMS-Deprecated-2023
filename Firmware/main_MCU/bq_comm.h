#define fault_pin 2

void setFaultCallback(void (*cb)());
void calculateCRC(char* msg);
bool verifyCRC(char* msg);
