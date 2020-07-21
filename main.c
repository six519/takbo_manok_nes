#include "libs/neslib.h"
#include "libs/nesdoug.h"
#include "game.h"
#include "main.h"
#include <stdlib.h> 

#pragma bss-name(push, "ZEROPAGE")

const unsigned char bg_palette[]={
    DK_BL, DK_RD, MD_YL, WHITE,
    0,0,0,0,
    0,0,0,0,
    0,0,0,0
};

const unsigned char sprite_palette[]={
    ORANG, LT_VL, BLACK, LT_GY,
    0,0,0,0,
    0,0,0,0,
    0,0,0,0
};

int game_state = 0;
unsigned int default_scroll = 85;
unsigned int scroll_x;
unsigned char pad1;
int title_animation_index = 0;
int chicken_animation_index = 0;
struct GameSprite chickenSprite = {10, 151, 15, 15};
struct GameSprite obstacle1 = {254, 159, 7, 7}; //254 max
struct GameSprite obstacle2 = {254, 159, 7, 7};
struct GameSprite obstacle3 = {254, 159, 7, 7};
struct GameSprite obstacle4 = {254, 159, 7, 7};
int is_jumping = 0;
int jump_tracker = 0;
int is_reverse = 0;
int score = 0;
int threshold_score = 0;
int threshold_collide = 0;
int threshold_show_obstacle2 = 0;
int obstacle2_showed = 0;
int threshold_show_obstacle3 = 0;
int obstacle3_showed = 0;
int threshold_show_obstacle4 = 0;
int obstacle4_showed = 0;
int lives = 3;

void scroll_bg() {
    if (game_state == 0) {
        scroll_x = default_scroll;
    } else if(game_state == 1) {
        scroll_x += 1;
    }

    set_scroll_x(scroll_x);
}

void draw_sprites() {
    char buffer[7];
    int i = 0;
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

        if (title_animation_index >= 0 && title_animation_index <= 11) {
            oam_spr(80, 46 + 16, 186, 0);
            oam_spr(88, 46 + 16, 187, 0);
        } else if (title_animation_index >= 12 && title_animation_index <= 23) {
            oam_spr(80, 46 + 16, 170, 0);
            oam_spr(88, 46 + 16, 171, 0);
        } else if (title_animation_index >= 24 && title_animation_index <= 35) {
            oam_spr(80, 46 + 16, 202, 0);
            oam_spr(88, 46 + 16, 203, 0);
        }

        title_animation_index += 1;

        if (title_animation_index == 35) {
            title_animation_index = 0;
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
        if (game_state == 1) {
            if (is_jumping) {

                if (is_reverse) {
                    jump_tracker -= 2;
                    chickenSprite.y += 2;
                } else {
                    jump_tracker += 1;
                    chickenSprite.y -= 1;
                }

                oam_meta_spr(chickenSprite.x, chickenSprite.y, chicken_jump);
                if (jump_tracker == 30) {
                    is_reverse = 1;
                }
                if (jump_tracker == 0) {
                    is_reverse = 0;
                    is_jumping = 0;
                }
            } else {
                if (chicken_animation_index >= 0 && chicken_animation_index <=8) {
                    oam_meta_spr(chickenSprite.x, chickenSprite.y, chicken_left);
                } else if (chicken_animation_index >= 9 && chicken_animation_index <= 17) {
                    oam_meta_spr(chickenSprite.x, chickenSprite.y, chicken_right);
                }
            }
            
            chicken_animation_index += 1;
            if (chicken_animation_index == 17) {
                chicken_animation_index = 0;
            }

            //show obstacles
            oam_spr(obstacle1.x, obstacle1.y, 192, 0);
            obstacle1.x -= 2;

            if(obstacle1.x == 0) {
                obstacle1.x = 254;
            }

            if (!obstacle2_showed) {
                threshold_show_obstacle2 += 1;
            }

            if (threshold_show_obstacle2 == 90) {
                obstacle2_showed = 1;
            }


            if (obstacle2_showed) {
                oam_spr(obstacle2.x, obstacle2.y, 193, 0);
                obstacle2.x -= 2;

                if(obstacle2.x == 0) {
                    obstacle2.x = 254;
                }
            }

            if (!obstacle3_showed) {
                threshold_show_obstacle3 += 1;
            }

            if (threshold_show_obstacle3 == 120) {
                obstacle3_showed = 1;
            }


            if (obstacle3_showed) {
                oam_spr(obstacle3.x, obstacle3.y, 194, 0);
                obstacle3.x -= 2;

                if(obstacle3.x == 0) {
                    obstacle3.x = 254;
                }
            }

            if (!obstacle4_showed) {
                threshold_show_obstacle4 += 1;
            }

            if (threshold_show_obstacle4 == 200) {
                obstacle4_showed = 1;
            }


            if (obstacle4_showed) {
                oam_spr(obstacle4.x, obstacle4.y, 195, 0);
                obstacle4.x -= 2;

                if(obstacle4.x == 0) {
                    obstacle4.x = 254;
                }
            }

            threshold_score += 1;

            if (threshold_score == 15) {
                score += 1;
                threshold_score = 0;
            }

            //show lives
            for (i = 0; i < lives; i++) {
                oam_spr(2 + (i * 9), 18, 141, 0);
            }
        }
        //show score
        oam_spr(2, 2, 83, 0);
        oam_spr(2 + 8, 2, 99, 0);
        oam_spr(2 + (8 * 2), 2, 111, 0);
        oam_spr(2 + (8 * 3), 2, 114, 0);
        oam_spr(2 + (8 * 4), 2, 101, 0);
        oam_spr(2 + (8 * 5), 2, 58, 0);

        itoa(score, buffer, 10);

        for(i = 0; i < 7; i++) {
            switch (buffer[i]) {
                case '0':
                    oam_spr(2 + (i * 8), 2 + 8, 48, 0);
                break;
                case '1':
                    oam_spr(2 + (i * 8), 2 + 8, 49, 0);
                break;
                case '2':
                    oam_spr(2 + (i * 8), 2 + 8, 50, 0);
                break;
                case '3':
                    oam_spr(2 + (i * 8), 2 + 8, 51, 0);
                break;
                case '4':
                    oam_spr(2 + (i * 8), 2 + 8, 52, 0);
                break;
                case '5':
                    oam_spr(2 + (i * 8), 2 + 8, 53, 0);
                break;
                case '6':
                    oam_spr(2 + (i * 8), 2 + 8, 54, 0);
                break;
                case '7':
                    oam_spr(2 + (i * 8), 2 + 8, 55, 0);
                break;
                case '8':
                    oam_spr(2 + (i * 8), 2 + 8, 56, 0);
                break;
                case '9':
                    oam_spr(2 + (i * 8), 2 + 8, 57, 0);
                break;
                default:
                break;
            }
        }

    }
}

void check_input() {
    if (pad1 & PAD_START) {
        if (game_state == 0) {
            sfx_play(0, 0);
            game_state = 1;
        }
    } else if (pad1 & PAD_A) {
        if (game_state == 1) {
            if (!is_jumping) {
                sfx_play(1, 0);
                is_jumping = 1;
            }
        }
    }
}

void is_collided()  {
    if (game_state == 1) {

        if (threshold_collide > 0) {
            threshold_collide += 1;

            if (threshold_collide == 40) {
                threshold_collide = 0;
            }
        }

        if (check_collision(&chickenSprite, &obstacle1) || check_collision(&chickenSprite, &obstacle2) || check_collision(&chickenSprite, &obstacle3) || check_collision(&chickenSprite, &obstacle4)) {
            pal_col(0,DK_GR);
            if(threshold_collide == 0) {
                sfx_play(2, 0);
                threshold_collide += 1;
                lives -= 1;

                if (lives == 0) {
                    game_state = 2;
                }
            }
        } else {
            pal_col(0,DK_BL);
        }
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
        pad1 = pad_poll(0);
        scroll_bg();
        draw_sprites();
        check_input();
        is_collided();
    }
}