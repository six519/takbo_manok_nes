#include "libs/neslib.h"
#include "libs/nesdoug.h"
#include "main.h" 

#pragma bss-name(push, "ZEROPAGE")

const unsigned char palette[]={
    DK_BL, DK_GY, LT_GY, WHITE,
    0,0,0,0,
    0,0,0,0,
    0,0,0,0
};

void write_text(unsigned char text[], int x, int y) {
    unsigned char i;
    vram_adr(NTADR_A(x,y));

    i = 0;
    while(text[i]){
        vram_put(text[i]);
        ++i;
    }
}

void main (void) {
    
    ppu_off();

    pal_bg(palette);
        
	write_text("This is a test!", 0, 0);

    music_play(0);
    ppu_on_all();
    
    
    while (1){   
    }
}
    
    