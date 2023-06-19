#ifndef sprites_appvar_include_file
#define sprites_appvar_include_file

#ifdef __cplusplus
extern "C" {
#endif

#define sizeof_global_palette 12
#define global_palette (sprites_appvar[0])
#define sprites_palette_offset 0
#define friskIdleDn_width 19
#define friskIdleDn_height 29
#define sprites_sprites_friskIdleDn_index 1
#define friskIdleDn ((gfx_sprite_t*)sprites_appvar[1])
#define friskWalkDn1_width 19
#define friskWalkDn1_height 29
#define sprites_sprites_friskWalkDn1_index 2
#define friskWalkDn1 ((gfx_sprite_t*)sprites_appvar[2])
#define friskWalkDn2_width 19
#define friskWalkDn2_height 29
#define sprites_sprites_friskWalkDn2_index 3
#define friskWalkDn2 ((gfx_sprite_t*)sprites_appvar[3])
#define sprites_entries_num 4
extern unsigned char *sprites_appvar[4];
unsigned char sprites_init(void);

#ifdef __cplusplus
}
#endif

#endif
