#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 1
#define CLK_PIN   13
#define DATA_PIN  11
#define CS_PIN    10

const int wait = 1000;

// Define the number of devices we have in the chain and the hardware interface
// NOTE: These pin numbers will probably not work with your hardware and may
// need to be adapted

// Hardware SPI connection
MD_Parola matrix = MD_Parola( HARDWARE_TYPE, CS_PIN, MAX_DEVICES );

void setup(){
    matrix.begin();
}

void loop(){
    matrix.print( "1" );
    delay( wait );
}
