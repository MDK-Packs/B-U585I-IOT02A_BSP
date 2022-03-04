Platform project
================

The **Platform** project configures the hardware of the evaluation board
and is a CMSIS-RTOS2 based software template that can be further expanded.

RTOS: Keil RTX5 Real-Time Operating System
------------------------------------------

The real-time operating system [Keil RTX5](https://arm-software.github.io/CMSIS_5/RTOS2/html/rtx5_impl.html) implements the resource management. 

It is configured with the following settings:

- [Global Dynamic Memory size](https://arm-software.github.io/CMSIS_5/RTOS2/html/config_rtx5.html#systemConfig): 32768 bytes
- [Default Thread Stack size](https://arm-software.github.io/CMSIS_5/RTOS2/html/config_rtx5.html#threadConfig): 3072 bytes
- [Event Recorder Configuration](https://arm-software.github.io/CMSIS_5/RTOS2/html/config_rtx5.html#evtrecConfig)
  - [Global Initialization](https://arm-software.github.io/CMSIS_5/RTOS2/html/config_rtx5.html#evtrecConfigGlobIni): 1
    - Start Recording: 1

Refer to [Configure RTX v5](https://arm-software.github.io/CMSIS_5/RTOS2/html/config_rtx5.html) for a detailed description of all configuration options.

Board: STMicroelectronics B-U585I-IOT02A
----------------------------------------

The tables below list the device configuration for this board. This setup is configured using **STM32CubeMX**, 
an interactive tool provided by ST for device configuration. Refer to ["Create Projects with STM32Cube HAL and STM32CubeMX"](https://www.keil.com/pack/doc/STM32Cube) for additional information.

The heap/stack setup and the CMSIS-Driver assignment is in configuration files of related software components.
**STM32CubeMX** is used for all other settings.

The example project can be re-configured to work on custom hardware. Refer to ["Migrate STM32 Based Example Projects to Custom Hardware"](https://github.com/MDK-Packs/Documentation/tree/master/Porting_to_Custom_Hardware) for information. 

### System Configuration

| System Component        | Setting
|:------------------------|:----------------------------------------
| Device                  | STM32U585AIIx
| ICACHE                  | Mode: 2-ways set associative cache
| Heap                    | 64 kB (configured in startup file)
| Stack (MSP)             | 1 kB (configured in startup file)

### Clock Configuration

| Clock                   | Setting
|:------------------------|:----------------------------------------
| HCLK                    | 160 MHz
| FCLK                    | 160 MHz
| APB1                    | 160 MHz
| APB2                    | 160 MHz
| APB3                    | 160 MHz
| To USART1               | 160 MHz
| To UART4                | 160 MHz
| To I2C1                 | 160 MHz
| To I2C2                 | 160 MHz
| To OCTOSPI              | 160 MHz
| To ADF1                 | 160 MHz
| To SPI2                 | 160 MHz


### GPIO Configuration and usage

| GPIO | Signal / Label   | GPIO Settings                                 | Usage
|:-----|:-----------------|:----------------------------------------------|:---------------------------------------------
| PA10 | USART1_RX        | Alternate Function, Speed=Very High           | ST-LINK Virtual COM port (T_VCP_RX)
| PA9  | USART1_TX        | Alternate Function, Speed=Very High           | ST-LINK Virtual COM port (T_VCP_TX)
| PC10 | UART4_TX         | Alternate Function, Speed=Very LOW            | STM32WB5MMG Bluetooth (UART RX)
| PC11 | UART4_RX         | Alternate Function, Speed=Very LOW            | STM32WB5MMG Bluetooth (UART TX)
| PG6  | WRLS.WKUP_B      | Output Push Pull, Level=Low, Speed=Low        | STM32WB5MMG Bluetooth (WakeUp)
| PF15 | WRLS.WKUP_W      | Output Push Pull, Level=Low, Speed=Low        | MXCHIP EMW3080 WiFi module (Chip_En)
| PD1  | SPI2_SCK         | Alternate Function, Speed=Very LOW            | MXCHIP EMW3080 WiFi module (SCK)
| PD3  | SPI2_MISO        | Alternate Function, Speed=Very LOW            | MXCHIP EMW3080 WiFi module (MISO)
| PD4  | SPI2_MOSI        | Alternate Function, Speed=Very LOW            | MXCHIP EMW3080 WiFi module (MOSI)
| PB12 | SPI2_NSS         | Alternate Function, Speed=Very LOW            | MXCHIP EMW3080 WiFi module (NSS)
| PG15 | WRLS.FLOW        | Input mode                                    | MXCHIP EMW3080 WiFi module (WRLS.FLOW)
| PD14 | WRLS.NOTIFY      | Input mode                                    | MXCHIP EMW3080 WiFi module (WRLS.NOTIFY)
| PB8  | I2C1_SCL         | Alternate Function, Speed=Very LOW            | I2C1 SCL
| PB9  | I2C1_SDA         | Alternate Function, Speed=Very LOW            | I2C1 SDA
| PE9  | ADF1_CCK0        | Alternate Function, Speed=Very LOW            | MIC CCK
| PE10 | ADF1_SDI0        | Alternate Function, Speed=Very LOW            | MIC SDIN
| PA11 | USB_OTG_FS_DM    | Alternate Function, Speed=Very LOW            | USP_OTG_FS DM
| PA12 | USB_OTG_FS_DP    | Alternate Function, Speed=Very LOW            | USP_OTG_FS DP
| PB10 | OCTOSPIM_P1_CLK  | Alternate Function, Speed=Very High           | OCTOSPI1 CLK
| PB11 | OCTOSPIM_P1_NCS  | Alternate Function, Speed=Very High           | OCTOSPI1 NCS
| PE3  | OCTOSPIM_P1_DQS  | Alternate Function, Speed=Very High           | OCTOSPI1 DQS
| PD7  | OCTOSPIM_P1_IO7  | Alternate Function, Speed=Very High           | OCTOSPI1 IO7
| PC3  | OCTOSPIM_P1_IO6  | Alternate Function, Speed=Very High           | OCTOSPI1 IO6
| PI0  | OCTOSPIM_P1_IO5  | Alternate Function, Speed=Very High           | OCTOSPI1 IO5
| PH2  | OCTOSPIM_P1_IO4  | Alternate Function, Speed=Very High           | OCTOSPI1 IO4
| PF6  | OCTOSPIM_P1_IO3  | Alternate Function, Speed=Very High           | OCTOSPI1 IO3
| PF7  | OCTOSPIM_P1_IO2  | Alternate Function, Speed=Very High           | OCTOSPI1 IO2
| PF9  | OCTOSPIM_P1_IO1  | Alternate Function, Speed=Very High           | OCTOSPI1 IO1
| PF8  | OCTOSPIM_P1_IO0  | Alternate Function, Speed=Very High           | OCTOSPI1 IO0
| PF4  | OCTOSPIM_P2_CLK  | Alternate Function, Speed=Very High           | OCTOSPI2 CLK
| PI5  | OCTOSPIM_P2_NCS  | Alternate Function, Speed=Very High           | OCTOSPI2 NCS
| PF12 | OCTOSPIM_P2_DQS  | Alternate Function, Speed=Very High           | OCTOSPI2 DQS
| PH12 | OCTOSPIM_P2_IO7  | Alternate Function, Speed=Very High           | OCTOSPI2 IO7
| PH11 | OCTOSPIM_P2_IO6  | Alternate Function, Speed=Very High           | OCTOSPI2 IO6
| PH10 | OCTOSPIM_P2_IO5  | Alternate Function, Speed=Very High           | OCTOSPI2 IO5
| PH9  | OCTOSPIM_P2_IO4  | Alternate Function, Speed=Very High           | OCTOSPI2 IO4
| PF3  | OCTOSPIM_P2_IO3  | Alternate Function, Speed=Very High           | OCTOSPI2 IO3
| PF2  | OCTOSPIM_P2_IO2  | Alternate Function, Speed=Very High           | OCTOSPI2 IO2
| PF1  | OCTOSPIM_P2_IO1  | Alternate Function, Speed=Very High           | OCTOSPI2 IO1
| PF0  | OCTOSPIM_P2_IO0  | Alternate Function, Speed=Very High           | OCTOSPI2 IO0
| PB5  | UCPD_PWR         | Output Push Pull, Level=Low, Speed=Low        | USB Type-C FS Power Delivery (EN)
| PD13 | USB.IANA         | Input mode                                    | USB Type-C FS Power Delivery (ANA)
| PA15 | UCPD1_CC1        | Analog mode                                   | USB Type-C FS Power Delivery (CC1)
| PB15 | UCPD1_CC2        | Analog mode                                   | USB Type-C FS Power Delivery (CC2)
| PE8  | USB.UCPD_FLT     | Input mode                                    | USB Type-C FS Power Delivery (FLGn)
| PF14 | USB.VBUS_SENSE   | Input mode                                    | USB Type-C FS Power Delivery (USB.VBUS_SENSE)
| PH4  | I2C2_SCL         | Alternate Function, Speed=Very LOW            | USB Type-C FS Power Delivery (SCL)
| PH5  | I2C2_SDA         | Alternate Function, Speed=Very LOW            | USB Type-C FS Power Delivery (SDA)
| PA8  | ARDUINO_IO_D9    | Input mode                                    | Arduino UNO R3 pin D9
| PE12 | ARDUINO_IO_D10   | Output Push Pull, Level=High, Speed=Very High | Arduino UNO R3 pin D10
| PC13 | vioBUTTON0       | not configured via CubeMX                     | Button USER
| PH6  | vioLED0          | not configured via CubeMX                     | LD6 RED
| PH7  | vioLED1          | not configured via CubeMX                     | LD7 GREEN

### NVIC Configuration

 - Priority Group = 3 bits for preemption priority 0 bits for subpriority

| NVIC Interrupt                          | Preempt Priority | Code Generation
|:----------------------------------------|:-----------------|:---------------
| Non maskable interrupt                  | 0                | Generate IRQ handler
| Hard fault interrupt                    | 0                | Generate IRQ handler
| Memory Management fault                 | 0                | Generate IRQ handler
| Prefetch fault, memory access fault     | 0                | Generate IRQ handler
| Undefined instruction or illegal state  | 0                | Generate IRQ handler
| System service call via SWI instruction | 14               | none
| Debug monitor                           | 0                | Generate IRQ handler
| Pendable request for system service     | 15               | none
| Time base: System tick timer            | 15               | none

### Connectivity Peripherals Configuration

| Peripheral   | Mode / Settings                                                                                                    | IRQ | DMA | Note
|:-------------|:-------------------------------------------------------------------------------------------------------------------|:----|:----|:----
| USART1       | Asynchronous, Hardware Flow Control=off, Baud Rate: 115200 Bits/s, Word Length: 8 Bits, Parity: None, Stop Bits: 1 | no  | no  | ST-LINK Virtual COM port

**STDIO** is routed to ST-LINK Virtual COM port (USART1)

### CMSIS-Driver mapping

| CMSIS-Driver VIO  | Physical board hardware
|:------------------|:-----------------------
| vioBUTTON0        | Button USER (PC13)
| vioLED0           | LD9 RED (PH6)
| vioLED1           | LD10 GREEN (PH7)
| vioMotionGyro     | iNEMO 3D gyroscope (ISM330DLC)
| vioMotionAccelero | iNEMO 3D accelerometer (ISM330DLC)
| vioMotionMagneto  | High accuracy 3-axis magnetometer (IIS2MDC)
