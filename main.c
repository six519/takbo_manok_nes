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
unsigned int default_scroll = 85;
unsigned int scroll_x;

void scroll_bg() {
    if (game_state == 0) {
        scroll_x = default_scroll;
    } else {
        scroll_x += 1;
    }

    set_scroll_x(scroll_x);
}

void draw_sprites() {
    oam_clear();
    if (game_state == 0) {
        // 8 sprites only per horizontal line :( sad
        oam_meta_spr(80, 2, spriteT);
        oam_meta_spr(80 + 16, 6, spriteA);
        oam_meta_spr(80 + (16 * 2), 10, spriteK);
        oam_meta_spr(80 + (16 * 3), 14, spriteB);
        oam_meta_spr(80 + (16 * 4), 18, sprite_O);

        oam_meta_spr(80, 22, spriteM);
        oam_meta_spr(80 + 16, 26, spriteA);
        oam_meta_spr(80 + (16 * 2), 30, spriteN);
        oam_meta_spr(80 + (16 * 3), 34, sprite_O);
        oam_meta_spr(80 + (16 * 4), 38, spriteK);

        oam_spr(80, 46, 138, 0);
        oam_spr(80, 46 + 8, 154, 0);
        oam_spr(80, 46 + 16, 170, 0);

        oam_spr(88, 46, 139, 0);
        oam_spr(88, 46 + 8, 155, 0);
        oam_spr(88, 46 + 16, 171, 0);        

        oam_spr(96, 46, 140, 0);
        oam_spr(96, 46 + 8, 156, 0);
        oam_spr(96, 46 + 16, 172, 0);

    } else {

    }
}

void main (void) {
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
        draw_sprites();
    }
}
    
    