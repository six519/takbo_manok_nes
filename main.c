#include "libs/neslib.h"
#include "libs/nesdoug.h"
#include "game.h"
#include "main.h" 

#pragma bss-name(push, "ZEROPAGE")

const unsigned char bg_palette[]={
    DK_BL, DK_RD, MD_YL, WHITE,
    0,0,0,0,
    0,0,0,0,
    0,0,0,0
};

const unsigned char sprite_palette[]={
    ORANG, DK_GR, BLACK, LT_GY,
    0,0,0,0,
    0,0,0,0,
    0,0,0,0
};

int game_state = 0;
unsigned int default_scroll = 100;
unsigned int scroll_x;

void scroll_bg() {
    if (game_state == 0) {
        scroll_x = default_scroll;
    } else {
        scroll_x += 1;
    }

    set_scroll_x(scroll_x);
}

void draw_sprites(int * opp) {
    oam_clear();
    if (game_state == 0) {
        // 8 sprites only per horizontal line :( sad
        if (*opp) {
            *opp = 0;
            oam_meta_spr(80, 10, spriteT);
            oam_meta_spr(80 + (16 * 2), 10, spriteK);
            oam_meta_spr(80 + (16 * 4), 10, sprite_O);
            oam_meta_spr(80 + 16, 10 + 16, spriteA);
            oam_meta_spr(80 + (16 * 3), 10 + 16, sprite_O);
        } else {
            *opp = 1;
            oam_meta_spr(80 + 16, 10, spriteA);
            oam_meta_spr(80 + (16 * 3), 10, spriteB);
            oam_meta_spr(80, 10 + 16, spriteM);
            oam_meta_spr(80 + (16 * 2), 10 + 16, spriteN);
            oam_meta_spr(80 + (16 * 4), 10 + 16, spriteK);
        }

    } else {

    }
}

void main (void) {
    int opposite = 0;
    
    ppu_off();

    pal_bg(bg_palette);
    pal_spr(sprite_palette);

    vram_adr(NAMETABLE_A);
    vram_unrle(game);
    vram_adr(NAMETABLE_B);
    vram_unrle(game);

    music_play(0);
    ppu_on_all();
    
    
    while (1){
        ppu_wait_nmi();
        scroll_bg();
        draw_sprites(&opposite);
    }
}
    
    