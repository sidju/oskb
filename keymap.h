#pragma once

#include "keeb.h"

typedef struct key_data {
  int keycode;
  gchar* label;
  int type;
} key_data;

#define KEYMAP_NR_ROWS 4
#define KEYMAP_NR_COLUMNS 12
#define SYM(label) {0, label, -2 }
#define NUM(label) {0, label, -1 }
#define MOD(key, label) {key, label, 0 }
#define KEY(key, label) {key, label, 1 }
#define SHFT(key, label) {key, label, 2 }
#define CMP(key, label) {key, label, 3 }
#define SCMP(key, label) {key, label, 4 }

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
    KEY(KEY_COMPOSE,"_")
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
    KEY(KEY_2,"2"),
    KEY(KEY_O,"o"),
    KEY(KEY_F3,"F3"),
    MOD(KEY_LEFTMETA,"Ui")
  },
  {
    KEY(KEY_3,"3"),
    KEY(KEY_E,"e"),
    KEY(KEY_F4,"F4"),
    NUM("a")
  },
  {
    KEY(KEY_4,"4"),
    KEY(KEY_U,"u"),
    KEY(KEY_F5,"F5"),
    KEY(KEY_BACKSPACE,"Bkspc")
  },
  {
    KEY(KEY_5,"5"),
    KEY(KEY_VOLUMEUP,"vol+"),
    KEY(KEY_F6,"F6"),
    KEY(KEY_SPACE, "")
  },
  {
    KEY(KEY_6,"6"),
    KEY(KEY_VOLUMEDOWN,"vol-"),
    KEY(KEY_F7,"F7"),
    KEY(KEY_SPACE,"")
  },
  {
    KEY(KEY_7,"7"),
    KEY(KEY_LEFT,"←"),
    KEY(KEY_F8,"F8"),
    KEY(KEY_ENTER,"Enter")
  },
  {
    KEY(KEY_8,"8"),
    KEY(KEY_UP,"↑"),
    KEY(KEY_F9,"F9"),
    SYM("@")
  },
  {
    KEY(KEY_9,"9"),
    KEY(KEY_DOWN,"↓"),
    KEY(KEY_F10,"F10"),
    KEY(KEY_COMPOSE,"_")
  },
  {
    KEY(KEY_0,"0"),
    KEY(KEY_RIGHT,"→"),
    KEY(KEY_F11,"F11"),
    KEY(KEY_HOME,"Home")
  },
  {
    KEY(KEY_INSERT,"Ins"),
    KEY(KEY_MINUS,"-"),
    KEY(KEY_F12,"F12"),
    KEY(KEY_END,"End")
  }
};
const key_data sym_keymap[KEYMAP_NR_COLUMNS][KEYMAP_NR_ROWS] = {
  {
    KEY(KEY_ESC,"Esc"),
    SHFT(KEY_SLASH,"?"),
    SHFT(KEY_MINUS,"_"),
    MOD(KEY_LEFTCTRL,"Ctrl")
  },
  {
    SHFT(KEY_1,"!"),
    KEY(KEY_LEFTBRACE,"["),
    KEY(KEY_MINUS,"-"),
    MOD(KEY_LEFTALT,"Alt")
  },
  {
    SHFT(KEY_2,"@"),
    KEY(KEY_RIGHTBRACE,"]"),
    SHFT(KEY_EQUAL,"+"),
    MOD(KEY_LEFTMETA,"Ui")
  },
  {
    SHFT(KEY_3,"3"),
    SHFT(KEY_LEFTBRACE,"{"),
    KEY(KEY_EQUAL,"="),
    NUM("1")
  },
  {
    SHFT(KEY_4,"$"),
    SHFT(KEY_RIGHTBRACE,"}"),
    KEY(KEY_SLASH,"/"),
    KEY(KEY_BACKSPACE,"Bkspc")
  },
  {
    SHFT(KEY_5,"%"),
    SHFT(KEY_BACKSLASH,"|"),
    KEY(KEY_BACKSLASH,"\\"),
    KEY(KEY_SPACE, "")
  },
  {
    SHFT(KEY_6,"^"),
    SHFT(KEY_GRAVE,"~"),
    KEY(KEY_GRAVE,"`"),
    KEY(KEY_SPACE,"")
  },
  {
    SHFT(KEY_7,"&"),
    CMP(KEY_O,"_o"),
    KEY(KEY_M,"m"),
    KEY(KEY_ENTER,"Enter")
  },
  {
    SHFT(KEY_8,"*"),
    SCMP(KEY_APOSTROPHE,"_\""),
    CMP(KEY_GRAVE,"_'"),
    SYM("@")
  },
  {
    SHFT(KEY_9,"("),
    CMP(KEY_SLASH,"_/"),
    CMP(KEY_APOSTROPHE,"_'"),
    KEY(KEY_COMPOSE,"_")
  },
  {
    SHFT(KEY_0,")"),
    SCMP(KEY_GRAVE,"_~"),
    SCMP(KEY_6,"_^"),
    KEY(KEY_HOME,"Home")
  },
  {
    KEY(KEY_INSERT,"Ins"),
    KEY(KEY_MINUS,"-"),
    KEY(KEY_LEFTSHIFT,"Shft"),
    KEY(KEY_END,"End")
  }
};
