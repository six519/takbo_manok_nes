;this file for FamiTone2 library generated by text2data tool

TakboManok_music_data:
	.byte 1
	.word @instruments
	.word @samples-3
	.word @song0ch0,@song0ch1,@song0ch2,@song0ch3,@song0ch4,307,256

@instruments:
	.byte $b0 ;instrument $01
	.word @env1,@env0,@env0
	.byte $00
	.byte $30 ;instrument $04
	.word @env1,@env2,@env0
	.byte $00

@samples:
@env0:
	.byte $c0,$00,$00
@env1:
	.byte $c3,$c7,$c5,$c4,$c3,$c2,$c1,$c1,$c0,$00,$08
@env2:
	.byte $c0,$c0,$bf,$bd,$00,$03


@song0ch0:
	.byte $fb,$07
@song0ch0loop:
@ref0:
	.byte $bf
@ref1:
	.byte $bf
@ref2:
	.byte $bf
@ref3:
	.byte $bf
@ref4:
	.byte $bf
@ref5:
	.byte $bf
@ref6:
	.byte $bf
@ref7:
	.byte $bf
@ref8:
	.byte $bf
@ref9:
	.byte $bf
@ref10:
	.byte $bf
@ref11:
	.byte $bf
	.byte $fd
	.word @song0ch0loop

@song0ch1:
@song0ch1loop:
@ref12:
	.byte $80,$3b,$3d,$41,$3b,$3d,$41,$3b,$3d,$41,$3b,$3d,$41,$3b,$3d,$41
	.byte $3a,$81
@ref13:
	.byte $3d,$41,$3b,$3d,$41,$3b,$3d,$41,$3b,$3d,$41,$3b,$3d,$41,$3b,$40
	.byte $81
@ref14:
	.byte $3b,$3d,$41,$3b,$3d,$41,$3b,$3d,$41,$3b,$3d,$41,$3b,$3d,$41,$3a
	.byte $81
	.byte $ff,$11
	.word @ref13
	.byte $ff,$11
	.word @ref14
	.byte $ff,$11
	.word @ref13
	.byte $ff,$11
	.word @ref14
@ref19:
	.byte $3d,$41,$3b,$3d,$41,$3b,$3d,$41,$3b,$3d,$41,$3b,$3d,$41,$3b,$3c
	.byte $81
@ref20:
	.byte $41,$3b,$3d,$41,$3b,$3d,$41,$3b,$3d,$41,$3b,$3d,$41,$3b,$3d,$40
	.byte $81
	.byte $ff,$11
	.word @ref14
	.byte $ff,$11
	.word @ref14
	.byte $ff,$11
	.word @ref13
	.byte $fd
	.word @song0ch1loop

@song0ch2:
@song0ch2loop:
@ref24:
	.byte $bf
@ref25:
	.byte $bf
@ref26:
	.byte $bf
@ref27:
	.byte $bf
@ref28:
	.byte $bf
@ref29:
	.byte $bf
@ref30:
	.byte $bf
@ref31:
	.byte $bf
@ref32:
	.byte $bf
@ref33:
	.byte $bf
@ref34:
	.byte $bf
@ref35:
	.byte $bf
	.byte $fd
	.word @song0ch2loop

@song0ch3:
@song0ch3loop:
@ref36:
	.byte $82,$1a,$12,$1a,$1a,$12,$1a,$12,$1a,$1a,$12,$1a,$12,$1a,$1a,$12
	.byte $1a,$12,$1a,$1a,$12,$1a,$12,$1a,$1a,$12,$1a,$12,$1a,$1a,$12,$1a
	.byte $12
@ref37:
	.byte $1a,$1a,$12,$1a,$12,$1a,$1a,$12,$1a,$12,$1a,$1a,$12,$1a,$12,$1a
	.byte $1a,$12,$1a,$12,$1a,$1a,$12,$1a,$12,$1a,$1a,$12,$1a,$12,$1a,$1a
@ref38:
	.byte $1a,$12,$1a,$1a,$12,$1a,$12,$1a,$1a,$12,$1a,$12,$1a,$1a,$12,$1a
	.byte $12,$1a,$1a,$12,$1a,$12,$1a,$1a,$12,$1a,$12,$1a,$1a,$12,$1a,$12
	.byte $ff,$20
	.word @ref37
	.byte $ff,$20
	.word @ref38
	.byte $ff,$20
	.word @ref37
	.byte $ff,$20
	.word @ref38
	.byte $ff,$20
	.word @ref37
	.byte $ff,$20
	.word @ref38
	.byte $ff,$20
	.word @ref37
@ref46:
	.byte $12,$1a,$12,$1a,$1a,$12,$1a,$12,$1a,$1a,$12,$1a,$12,$1a,$1a,$12
	.byte $1a,$12,$1a,$1a,$12,$1a,$12,$1a,$1a,$12,$1a,$12,$1a,$1a,$12,$1a
@ref47:
	.byte $12,$1a,$1a,$12,$1a,$12,$1a,$1a,$12,$1a,$12,$1a,$1a,$12,$1a,$12
	.byte $1a,$1a,$12,$1a,$12,$1a,$1a,$12,$1a,$12,$1a,$1a,$12,$1a,$12,$81
	.byte $fd
	.word @song0ch3loop

@song0ch4:
@song0ch4loop:
@ref48:
	.byte $bf
@ref49:
	.byte $bf
@ref50:
	.byte $bf
@ref51:
	.byte $bf
@ref52:
	.byte $bf
@ref53:
	.byte $bf
@ref54:
	.byte $bf
@ref55:
	.byte $bf
@ref56:
	.byte $bf
@ref57:
	.byte $bf
@ref58:
	.byte $bf
@ref59:
	.byte $bf
	.byte $fd
	.word @song0ch4loop
