#pragma once

// For reference when inserting the event codes
// https://github.com/torvalds/linux/blob/master/include/uapi/linux/input-event-codes.h

#include <linux/uinput.h>

// Define types
typedef struct keeb_handle {
  int fd;
} keeb_handle;

// Define functions
keeb_handle keeb_init();
void keeb_send_key(keeb_handle *handle, int key);
void keeb_set_key(keeb_handle *handle, int key, int pressed);
void keeb_destroy(keeb_handle handle);
