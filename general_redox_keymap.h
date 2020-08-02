#include QMK_KEYBOARD_H
#include "common_macros.h"

#define DOX_BASE 0  // default layer
#define DOX_LYR1 1  // symbols

#define KC_BRTD KC_BRMD
#define KC_BRTU KC_BRMU
#define KC_CAPS KC_CAPSLOCK
#define KC_L_BR KC_LBRACKET
#define KC_R_BR KC_RBRACKET
#define TX_SW_L TMUX_SWAP_L
#define TX_SW_R TMUX_SWAP_R

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [DOX_BASE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC  ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5                                                ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_L_BR ,KC_R_BR ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB  ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,KC_GRV                            ,KC_6    ,KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,KC_BSLS ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     MO(1)   ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,MO(2)                             ,KC_MINUS,KC_H    ,KC_J    ,KC_K    ,KC_L    ,KC_SCLN ,KC_QUOT ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,KC_DEL  ,KC_ENT          ,KC_BSPC ,KC_EQUAL,KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,KC_RSFT ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     KC_LCTRL,KC_LALT ,KC_CAPS ,KC_LALT      ,KC_LGUI     ,KC_SPC  ,KC_BSPC         ,KC_ENT  ,KC_SPC      ,KC_RGUI      ,KC_RALT ,KC_GRV  ,KC_RALT ,KC_RCTRL 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [DOX_LYR1] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV  ,TMUX_1  ,TMUX_2  ,TMUX_3  ,TMUX_4  ,TMUX_5                                              ,TMUX_7  ,TMUX_8  ,TMUX_9  ,_______ ,KC_BRTD ,KC_BRTU ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,WIN_TL  ,WIN_T   ,WIN_TR  ,_______ ,_______ ,_______                           ,TMUX_6  ,TMUX_C,  TMUX_CYC,PRV_WD  ,NXT_WD  ,TMUX_P  ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,WIN_L   ,WIN_B   ,WIN_R   ,WIN_F   ,_______ ,_______                           ,_______ ,KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RGHT ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,WIN_BL  ,WIN_CYC ,WIN_BR  ,WIN_C   ,_______ ,RESET   ,RESET           ,RESET   ,RESET   ,TMUX_N  ,_______ ,TX_SW_L ,TX_SW_R ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     P_CMP   ,P_1PASS ,P_OKTA  ,P_CP         ,P_LP        ,_______ ,KC_DEL          ,_______ ,_______     ,KC_MRWD      ,KC_MPLY ,KC_MFFD ,KC_VOLD ,KC_VOLU  
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  )
};

