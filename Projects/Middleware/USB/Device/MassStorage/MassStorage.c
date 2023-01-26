/*------------------------------------------------------------------------------
 * MDK Middleware - Component ::USB:Device
 * Copyright (c) 2004-2023 Arm Limited (or its affiliates). All rights reserved.
 *------------------------------------------------------------------------------
 * Name:    MassStorage.c
 * Purpose: USB Device - Mass Storage example
 *----------------------------------------------------------------------------*/

#include "main.h"

#include "cmsis_os2.h"                  // ::CMSIS:RTOS2
#include "rl_usb.h"                     // Keil.MDK-Plus::USB:CORE

static void app_main (void *argument);

// Main stack size must be multiple of 8 Bytes
#define APP_MAIN_STK_SZ (4096U)
static uint64_t app_main_stk[APP_MAIN_STK_SZ / 8];
static const osThreadAttr_t app_main_attr = {
  .stack_mem  = &app_main_stk[0],
  .stack_size = sizeof(app_main_stk)
};

/*---------------------------------------------------------------------------
 * Application initialization
 *---------------------------------------------------------------------------*/
void app_initialize (void) {
  osThreadNew(app_main, NULL, &app_main_attr);
}

/*---------------------------------------------------------------------------
 * Application main thread
 *---------------------------------------------------------------------------*/
static void app_main (void *argument) {
  (void)argument;

  USBD_Initialize(0U);                  // USB Device 0 Initialization
  USBD_Connect   (0U);                  // USB Device 0 Connect

  osThreadExit();
}
