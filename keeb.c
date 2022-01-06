#include "keeb.h"

#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <linux/uinput.h>

// Abstraction for sending key events
int emit(int fd, int type, int code, int val) {
  struct input_event ie;

  ie.type = type;
  ie.code = code;
  ie.value = val;
  // Unused
  ie.time.tv_sec = 0;
  ie.time.tv_usec = 0;

  int written = write(fd, &ie, sizeof(ie));
  // If done return
  if (written == sizeof(ie)) return 0;
  // If partial, try to write the rest once
  if (written < 0) {
    if ( (sizeof(ie) - written) == write(fd, ((void*) &ie) + written, sizeof(ie) - written) ) {
      return 0;
    }
  }
  // If none of the success cases, return -1 for error
  return -1;
}

// We take a generalised error, not errno, as input
void check(int error) {
  if (error < 0) {
    int errsv = errno; // save, since printf may overwrite errno
    printf("Error: %s", strerror(errsv));
    exit(errsv);
  }
}

keeb_handle keeb_init() {
  keeb_handle handle = {};

  // First we get a the file descriptor to our device
  // and construct the device from it
  handle.fd = open("/dev/uinput", O_WRONLY | O_NONBLOCK);
  if (handle.fd < 0) { printf("Failed to open device file\n"); exit(1); }
  // Configure the device to pass key events and cursor movement events
  check( ioctl(handle.fd, UI_SET_EVBIT, EV_KEY) );
  //check( ioctl(handle.fd, UI_SET_EVBIT, EV_REL) );
  // Configure what keys we have to all possible
  for(int i = 0; i <= KEY_MICMUTE; i++) {
    check( ioctl(handle.fd, UI_SET_KEYBIT, i) );
  }

  // Allocate memory for local device config
  struct uinput_setup config;
  memset(&config, 0, sizeof(config));
  config.id.bustype = BUS_USB;
  config.id.vendor = 1234; // Dummy
  config.id.product = 5678; // Dummy
  strcpy(config.name, "Dummy device");

  // Apply the config and create the device
  check( ioctl(handle.fd, UI_DEV_SETUP, &config) );
  check( ioctl(handle.fd, UI_DEV_CREATE) );

  // This far means the device has been created
  // Give system a moment to adjust the input stack
  sleep(1);

  // Then return the constructed device
  return handle;
}

void keeb_send_key(keeb_handle *handle, int key) {
  // We need to sync, to avoid events negating eachother
  check( emit(handle->fd, EV_KEY, key, 1) ); // Press
  check( emit(handle->fd, EV_SYN, SYN_REPORT, 0) );
  check( emit(handle->fd, EV_KEY, key, 0) ); // Release
  check( emit(handle->fd, EV_SYN, SYN_REPORT, 0) );
}
void keeb_set_key(keeb_handle *handle, int key, int pressed) {
  // We need to sync, to avoid events negating eachother
  check( emit(handle->fd, EV_KEY, key, pressed) ); // Press
  check( emit(handle->fd, EV_SYN, SYN_REPORT, 0) );
}

void keeb_destroy(keeb_handle handle) {
  // Wait for in-flight presses to be processed
  sleep(1);

  // When done we destroy our device and return
  check( ioctl(handle.fd, UI_DEV_DESTROY) );
  check( close(handle.fd) );
}
