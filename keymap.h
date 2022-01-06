#pragma once

#include "keeb.h"

typedef struct key_data {
  int keycode;
  gchar* label;
  int width;
  int type;
} key_data;

#define KEYMAP_NR_ROWS 4
#define KEYMAP_NR_COLUMNS 12
#define KEY(key, label) {key, label, 1, 0 }
#define MOD(key, label) {key, label, 1, 1 }
#define BIG(key, label) {key, label, 2, 0 }
#define NUM(label) {0, label, 1, -1 }
#define SYM(label) {0, label, 1, -2 }

const key_data base_keymap[KEYMAP_NR_COLUMNS][KEYMAP_NR_ROWS] = {
  {
    KEY(KEY_ESC,"Esc"),
    KEY(KEY_TAB,"Tab"),
    MOD(KEY_LEFTSHIFT,"Shft"),
    MOD(KEY_LEFTCTRL,"Ctrl")
  },
  {
    KEY(KEY_APOSTROPHE,"'"),
    KEY(KEY_A,"a"),
    KEY(KEY_SEMICOLON,";"),
    MOD(KEY_LEFTALT,"Alt")
  },
  {
    KEY(KEY_COMMA,","),
    KEY(KEY_O,"o"),
    KEY(KEY_Q,"q"),
    MOD(KEY_LEFTMETA,"Ui")
  },
  {
    KEY(KEY_DOT,"."),
    KEY(KEY_E,"e"),
    KEY(KEY_J,"j"),
    NUM("1")
  },
  {
    KEY(KEY_P,"p"),
    KEY(KEY_U,"u"),
    KEY(KEY_K,"k"),
    KEY(KEY_BACKSPACE,"Bkspc")
  },
  {
    KEY(KEY_Y,"y"),
    KEY(KEY_I,"i"),
    KEY(KEY_X,"x"),
    KEY(KEY_SPACE, "")
  },
  {
    KEY(KEY_F,"f"),
    KEY(KEY_D,"d"),
    KEY(KEY_B,"b"),
    KEY(KEY_SPACE,"")
  },
  {
    KEY(KEY_G,"g"),
    KEY(KEY_H,"h"),
    KEY(KEY_M,"m"),
    KEY(KEY_ENTER,"Enter")
  },
  {
    KEY(KEY_C,"c"),
    KEY(KEY_T,"t"),
    KEY(KEY_W,"w"),
    SYM("@")
  },
  {
    KEY(KEY_R,"r"),
    KEY(KEY_N,"n"),
    KEY(KEY_V,"v"),
    KEY(KEY_COMPOSE,".*")
  },
  {
    KEY(KEY_L,"l"),
    KEY(KEY_S,"s"),
    KEY(KEY_Z,"z"),
    KEY(KEY_PAGEUP,"PgUp")
  },
  {
    KEY(KEY_INSERT,"Ins"),
    KEY(KEY_MINUS,"-"),
    KEY(KEY_LEFTSHIFT,"Shft"),
    KEY(KEY_PAGEDOWN,"PgDn")
  }
};
const key_data num_keymap[KEYMAP_NR_COLUMNS][KEYMAP_NR_ROWS] = {
  {
    KEY(KEY_ESC,"Esc"),
    KEY(KEY_TAB,"Tab"),
    MOD(KEY_F1,"F1"),
    MOD(KEY_LEFTCTRL,"Ctrl")
  },
  {
    KEY(KEY_1,"1"),
    KEY(KEY_A,"a"),
    KEY(KEY_F2,"F2"),
    MOD(KEY_LEFTALT,"Alt")
  },
  {
    KEY(KEY_COMMA,","),
    KEY(KEY_O,"o"),
    KEY(KEY_Q,"q"),
    MOD(KEY_LEFTMETA,"Ui")
  },
  {
    KEY(KEY_DOT,"."),
    KEY(KEY_E,"e"),
    KEY(KEY_J,"j"),
    NUM("1")
  },
  {
    KEY(KEY_P,"p"),
    KEY(KEY_U,"u"),
    KEY(KEY_K,"k"),
    KEY(KEY_BACKSPACE,"Bkspc")
  },
  {
    KEY(KEY_Y,"y"),
    KEY(KEY_I,"i"),
    KEY(KEY_X,"x"),
    KEY(KEY_SPACE, "")
  },
  {
    KEY(KEY_F,"f"),
    KEY(KEY_D,"d"),
    KEY(KEY_B,"b"),
    KEY(KEY_SPACE,"")
  },
  {
    KEY(KEY_G,"g"),
    KEY(KEY_H,"h"),
    KEY(KEY_M,"m"),
    KEY(KEY_ENTER,"Enter")
  },
  {
    KEY(KEY_C,"c"),
    KEY(KEY_T,"t"),
    KEY(KEY_W,"w"),
    SYM("@")
  },
  {
    KEY(KEY_R,"r"),
    KEY(KEY_N,"n"),
    KEY(KEY_V,"v"),
    KEY(KEY_COMPOSE,".*")
  },
  {
    KEY(KEY_L,"l"),
    KEY(KEY_S,"s"),
    KEY(KEY_Z,"z"),
    KEY(KEY_PAGEUP,"PgUp")
  },
  {
    KEY(KEY_INSERT,"Ins"),
    KEY(KEY_MINUS,"-"),
    KEY(KEY_LEFTSHIFT,"Shft"),
    KEY(KEY_PAGEDOWN,"PgDn")
  }
};
const key_data sym_keymap[KEYMAP_NR_COLUMNS][KEYMAP_NR_ROWS] = {
  {
    KEY(KEY_ESC,"Esc"),
    KEY(KEY_TAB,"Tab"),
    MOD(KEY_LEFTSHIFT,"Shft"),
    MOD(KEY_LEFTCTRL,"Ctrl")
  },
  {
    KEY(KEY_APOSTROPHE,"'"),
    KEY(KEY_A,"a"),
    KEY(KEY_SEMICOLON,";"),
    MOD(KEY_LEFTALT,"Alt")
  },
  {
    KEY(KEY_COMMA,","),
    KEY(KEY_O,"o"),
    KEY(KEY_Q,"q"),
    MOD(KEY_LEFTMETA,"Ui")
  },
  {
    KEY(KEY_DOT,"."),
    KEY(KEY_E,"e"),
    KEY(KEY_J,"j"),
    NUM("1")
  },
  {
    KEY(KEY_P,"p"),
    KEY(KEY_U,"u"),
    KEY(KEY_K,"k"),
    KEY(KEY_BACKSPACE,"Bkspc")
  },
  {
    KEY(KEY_Y,"y"),
    KEY(KEY_I,"i"),
    KEY(KEY_X,"x"),
    KEY(KEY_SPACE, "")
  },
  {
    KEY(KEY_F,"f"),
    KEY(KEY_D,"d"),
    KEY(KEY_B,"b"),
    KEY(KEY_SPACE,"")
  },
  {
    KEY(KEY_G,"g"),
    KEY(KEY_H,"h"),
    KEY(KEY_M,"m"),
    KEY(KEY_ENTER,"Enter")
  },
  {
    KEY(KEY_C,"c"),
    KEY(KEY_T,"t"),
    KEY(KEY_W,"w"),
    SYM("@")
  },
  {
    KEY(KEY_R,"r"),
    KEY(KEY_N,"n"),
    KEY(KEY_V,"v"),
    KEY(KEY_COMPOSE,".*")
  },
  {
    KEY(KEY_L,"l"),
    KEY(KEY_S,"s"),
    KEY(KEY_Z,"z"),
    KEY(KEY_PAGEUP,"PgUp")
  },
  {
    KEY(KEY_INSERT,"Ins"),
    KEY(KEY_MINUS,"-"),
    KEY(KEY_LEFTSHIFT,"Shft"),
    KEY(KEY_PAGEDOWN,"PgDn")
  }
};
