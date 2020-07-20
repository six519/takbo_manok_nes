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
unsigned char pad1;

void scroll_bg() {
    if (game_state == 0) {
        scroll_x = default_scroll;
    } else {
        scroll_x += 1;
    }

    set_scroll_x(scroll_x);
}

void draw_sprites(int * title_animation_index) {
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

        // chicken
        oam_spr(80, 46, 138, 0);
        oam_spr(80, 46 + 8, 154, 0);

        oam_spr(88, 46, 139, 0);
        oam_spr(88, 46 + 8, 155, 0);

        if (*title_animation_index >= 0 && *title_animation_index <= 11) {
            oam_spr(80, 46 + 16, 186, 0);
            oam_spr(88, 46 + 16, 187, 0);
        } else if (*title_animation_index >= 12 && *title_animation_index <= 23) {
            oam_spr(80, 46 + 16, 170, 0);
            oam_spr(88, 46 + 16, 171, 0);
        } else if (*title_animation_index >= 24 && *title_animation_index <= 35) {
            oam_spr(80, 46 + 16, 202, 0);
            oam_spr(88, 46 + 16, 203, 0);
        }

        *title_animation_index += 1;

        if (*title_animation_index == 35) {
            *title_animation_index = 0;
        }

        oam_spr(96, 46, 140, 0);
        oam_spr(96, 46 + 8, 156, 0);
        oam_spr(96, 46 + 16, 172, 0);

        // press start
        oam_spr(100, 84, 80, 0);
        oam_spr(100 + 8, 84, 114, 0);
        oam_spr(100 + (8 * 2), 84, 101, 0);
        oam_spr(100 + (8 * 3), 84, 115, 0);
        oam_spr(100 + (8 * 4), 84, 115, 0);

        oam_spr(100, 94, 83, 0);
        oam_spr(100 + 8, 94, 116, 0);
        oam_spr(100 + (8 * 2), 94, 97, 0);
        oam_spr(100 + (8 * 3), 94, 114, 0);
        oam_spr(100 + (8 * 4), 94, 116, 0);

    } else {

    }
}

void check_input() {
    if (pad1 && PAD_START) {
        if (game_state == 0) {
            game_state = 1;
        }
    }
}

void main (void) {
    int title_animation_index = 0;
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
        pad1 = pad_poll(0);
        scroll_bg();
        draw_sprites(&title_animation_index);
        check_input();
    }
}
    
    