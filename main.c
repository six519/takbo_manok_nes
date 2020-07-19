#include "libs/neslib.h"
#include "libs/nesdoug.h"
#include "title.h"
#include "main.h" 

#pragma bss-name(push, "ZEROPAGE")

const unsigned char bg_palette[]={
    DK_BL, DK_RD, MD_YL, WHITE,
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

    pal_bg(bg_palette);

    vram_adr(NAMETABLE_A);
    vram_unrle(title);

    music_play(0);

    write_text("Press Start", 42, 146);
    ppu_on_all();
    
    
    while (1){   
    }
}
    
    