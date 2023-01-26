/*------------------------------------------------------------------------------
 * MDK Middleware - Component ::USB:Device
 * Copyright (c) 2004-2023 Arm Limited (or its affiliates). All rights reserved.
 *------------------------------------------------------------------------------
 * Name:    HID.c
 * Purpose: USB Device - Human Interface Device example
 *----------------------------------------------------------------------------*/

#include "main.h"

#include "cmsis_os2.h"                  // ::CMSIS:RTOS2
#include "cmsis_vio.h"                  // ::CMSIS Driver:VIO

#include "rl_usb.h"                     // Keil.MDK-Plus::USB:CORE

static __NO_RETURN void app_main (void *argument);

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
static __NO_RETURN void app_main (void *argument) {
  uint8_t but;
  uint8_t but_prev = 0U;

  (void)argument;

  USBD_Initialize(0U);                  // USB Device 0 Initialization
  USBD_Connect   (0U);                  // USB Device 0 Connect

  for (;;) {                            // Loop forever
    but = (uint8_t)(vioGetSignal(vioBUTTON0));
    if (but != but_prev) {
      but_prev = but;
      if (USBD_Configured (0)) { USBD_HID_GetReportTrigger(0U, 0U, &but, 1U); }
    }
    osDelay(100U);                      // 100 ms delay for sampling buttons
  }
}
