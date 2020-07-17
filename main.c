#include "libs/neslib.h"
#include "libs/nesdoug.h"
#include "main.h" 

#pragma bss-name(push, "ZEROPAGE")

const unsigned char text[]="This is a test!";
const unsigned char palette[]={
    DK_BL, DK_GY, LT_GY, WHITE,
    0,0,0,0,
    0,0,0,0,
    0,0,0,0
};
unsigned char i;

void main (void) {
    
    ppu_off();

    pal_bg(palette);
        
    vram_adr(NTADR_A(0,0));

    i = 0;
    while(text[i]){
        vram_put(text[i]);
        ++i;
    }	

    
    ppu_on_all();
    
    
    while (1){   
    }
}
    
    