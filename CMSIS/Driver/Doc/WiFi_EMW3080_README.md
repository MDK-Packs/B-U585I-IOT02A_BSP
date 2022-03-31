# CMSIS-Driver WiFi for the MXCHIP EMW3080 module

## Requirements

### Packs

 - **ARM::CMSIS** version **5.8.0** or later
 - **Keil::STM32U5xx_DFP** version **1.2.0** or later

### Module

 - Firmware **v2.1.11** (for update procedure please consult
   [Firmware Update](https://www.st.com/en/development-tools/x-wifi-emw3080b.html) procedure)

### Limitations of the MXCHIP EMW3080B Firmware v2.1.11

 - Supports only SPI interface
 - Does not properly support Access Point
 - Does not detect socket connection closure by the server
 - Does not differentiate between socket connection command failure,
   connection to non-existent port or connection to non-existent server
 - Does not support dissolution of the datagram socket address
 - Occasionally does not properly return IP and port of the received datagram
 - Reports data sent success on socket closed by the server

## STM32CubeMX Setup

The description below shows the **STM32CubeMX** settings for the **B-U585I-IOT02A** board.

Select or enter the values that are marked in **bold**.

### Pinout & Configuration tab
  1. Select functions of all of the interface pins
     - Click on pin **PD1** in the chip diagram and select **SPI2_SCK**
     - Click on pin **PD3** in the chip diagram and select **SPI2_MISO**
     - Click on pin **PD4** in the chip diagram and select **SPI2_MOSI**
     - Click on pin **PB12** in the chip diagram and select **GPIO_Output**
     - Click on pin **PD14** in the chip diagram and select **GPIO_EXTI14**
     - Click on pin **PF15** in the chip diagram and select **GPIO_Output**
     - Click on pin **PG15** in the chip diagram and select **GPIO_EXTI15**

  2. Configure the **SPI** peripheral
     - Under category **Connectivity** select **SPI2** and set:
       - Mode: **Full-Duplex Master**
       - Hardware NSS Signal: **Disable**
       - Hardware RDY Signal: **Disable**
     - Select **Parameter Settings** tab and set:
       - Basic Parameters
         - Frame Format: **Motorola**
         - Data Size: **8 Bits**
         - First Bit: **MSB First**
       - Clock Parameters
         - Prescaler (for Baud Rate): **8**
         - Baud Rate: 20.0 MBits/s
         - Clock Polarity (CPOL): **Low**
         - Clock Phase (CPHA): **1 Edge**
       - Autonomous Mode
         - State: **Disable**
       - CRC Parameters
         - CRC Calculation: **Disabled**
       - Advanced Parameters
         - NSSP Mode: **Disabled**
         - NSS Signal Type: **Software**
         - Fifo Threshold: **Fifo Threashold 01 Data**
         - Nss Polarity: **Nss Polarity Low**
         - Master Ss Idleness: **00 Cycle**
         - Master Inter Data Idleness: **00 Cycle**
         - Master Receiver Auto Susp: **Disable**
         - Master Keep Io State: **Master Keep Io State Disable**
         - IO Swap: **Disabled**
         - Ready Master Management: **Internal**
         - Ready Signal Polarity: **High**

  3. Configure **DMA** for the SPI peripheral (optional)
     - Under category **System Core** select **GPDMA1** and set:
       - Channel 5 - 2 Words Internal FIFO: **Standard Request Mode**
       - Channel 4 - 2 Words Internal FIFO: **Standard Request Mode**
     - Select **CH5** tab and set:
       - Circular configuration
         - Circular Mode: **Disable**
       - Request Configuration
         - Request: **SPI2_TX**
         - DMA Handle in IP Structure: **hdmatx**
         - Block HW request protocol: **Single/Burst Level**
       - Channel configuration
         - Priority: **High**
         - Transaction Mode: **Normal**
         - Direction: **Memory To Peripheral**
       - Source Data Setting
         - Source Address Increment After Transfer: **Enabled**
         - Data Width: **Byte**
         - Burst Length: **1**
         - Allocated Port for Transfer: **Port 0**
       - Destination Data Setting
         - Destination Address Increment After Transfer: **Disabled**
         - Data Width: **Byte**
         - Burst Length: **1**
         - Allocated Port for Transfer: **Port 1**
       - Data Handling
         - Data Handling Configuration: **Disable**
       - Trigger
         - Trigger Configuration: **Disable**
       - Transfer Event Configuration
         - Transfer Event Generation: **The TC (and the HT) event is generated at the (respectively half) end of each block**
     - Select **CH4** tab and set:
       - Circular configuration
         - Circular Mode: **Disable**
       - Request Configuration
         - Request: **SPI2_RX**
         - DMA Handle in IP Structure: **hdmarx**
         - Block HW request protocol: **Single/Burst Level**
       - Channel configuration
         - Priority: **High**
         - Transaction Mode: **Normal**
         - Direction: **Peripheral To Memory**
       - Source Data Setting
         - Source Address Increment After Transfer: **Disabled**
         - Data Width: **Byte**
         - Burst Length: **1**
         - Allocated Port for Transfer: **Port 0**
       - Destination Data Setting
         - Destination Address Increment After Transfer: **Enabled**
         - Data Width: **Byte**
         - Burst Length: **1**
         - Allocated Port for Transfer: **Port 1**
       - Data Handling
         - Data Handling Configuration: **Disable**
       - Trigger
         - Trigger Configuration: **Disable**
       - Transfer Event Configuration
         - Transfer Event Generation: **The TC (and the HT) event is generated at the (respectively half) end of each block**

  4. Configure all of the interface pins
     - Under category **System Core** select **GPIO** and select **SPI** tab and set:
       Pin Name | Signal on Pin     | GPIO mode           | GPIO Pull-up/Pull-down      | Maximum out | User Label
       :--------|:------------------|:--------------------|:----------------------------|:------------|:----------
       PD1      | SPI2_SCK          | Alternate           | No pull-up and no pull-down | High        |.
       PD3      | SPI2_MISO         | Alternate           | No pull-up and no pull-down | High        |.
       PD4      | SPI2_MOSI         | Alternate           | No pull-up and no pull-down | High        |.

     - Under category **System Core** select **GPIO** and select **GPIO** tab and set:
       Pin Name | GPIO output level | GPIO mode           | GPIO Pull-up/Pull-down      | Maximum out | User Label
       :--------|:------------------|:--------------------|:----------------------------|:------------|:----------
       PB12     | High              | Output Push Pull    | No pull-up and no pull-down | High        | **MXCHIP_NSS**
       PD14     | n/a               | Ext Int Rising edge | No pull-up and no pull-down | n/a         | **MXCHIP_NOTIFY**
       PF15     | Low               | Output Push Pull    | No pull-up and no pull-down | Low         | **MXCHIP_RESET**
       PG15     | n/a               | Ext Int Rising edge | No pull-up and no pull-down | n/a         | **MXCHIP_FLOW**

  5. Configure the **NVIC**
     - Under category **System Core** select **NVIC** and select **NVIC** tab and set:
       - Priority Group: **4 bits for pre-emption priority 0 bits for subpriority**
       - Force DMA channel Interrupts: **yes**

     NVIC Interrupt Table                 | Enable | Preemption Priority | Sub Priority
     :------------------------------------|:-------|:--------------------|:--------------
     EXTI Line14 interrupt                |  yes   | 8                   | 0
     EXTI Line15 interrupt                |  yes   | 8                   | 0
     GPDMA1 Channel 4 global interrupt    |  yes   | 8                   | 0
     GPDMA1 Channel 5 global interrupt    |  yes   | 8                   | 0
     SPI2 global interrupt                |  yes   | 8                   | 0

### Clock Configuration tab
  1. Configure the **SPI clock**
     - Setup **To SPI2 (MHz)** to **160 MHz** (same as HCLK clock)

### Project Manager tab
  1. Select **Advanced Settings** tab and:
     - in the **Register Callback** window change value for **SPI** to **ENABLE**
     - if DMA is configured for SPI transfers then in the **Generated Function Calls** window,
       ensure that **MX_GPDMA1_Init** function is ranked higher (has lower rank number) than **MX_SPI2_Init** function
       (that means MX_GPDMA1_Init function will be called before MX_SPI2_Init function)

## Source Code Setup

 - Open the STM32CubeMX generated **main.c** file.
   Add the following include into the section between `USER CODE BEGIN Includes` and `USER CODE END Includes`:

```C
#include "WiFi_EMW3080.h"
```

 - Add code for handling External Interrupts by copy-pasting the following code snippet into the section
   between `USER CODE BEGIN 0` and `USER CODE END 0`:

```C
void HAL_GPIO_EXTI_Rising_Callback(uint16_t GPIO_Pin) {
  switch (GPIO_Pin) {
    case (MXCHIP_FLOW_Pin):
      WiFi_EMW3080_Pin_FLOW_Rising_Edge();
      break;
    case (MXCHIP_NOTIFY_Pin):
      WiFi_EMW3080_Pin_NOTIFY_Rising_Edge();
      break;
    default:
      break;
  }
}
```

## Driver Configuration

This driver is built on top of the **MX_WIFI Component Driver**, so the configuration is also done separately in two configuration files.
Respectively **WiFi_EMW3080_Config.h** file is used for the CMSIS-Driver configuration and **mx_wifi_conf.h** file is used for the
MX_WIFI Component Driver configuration.

### CMSIS-Driver Configuration Settings: WiFi_EMW3080_Config.h file

 - **WIFI_EMW3080_DRV_NUM** specifies the exported driver number (default value is **0**, default exported driver structure is **Driver_WiFi0**)
 - **WIFI_EMW3080_SCAN_BUF_SIZE** specifies the maximum size of the buffer used for Scan function (default value is **2048** bytes)
 - **WIFI_EMW3080_SOCKETS_NUM** specifies the maximum number of sockets supported by the driver (default value is **4**)
 - **WIFI_EMW3080_SOCKETS_RX_BUF_SIZE** specifies the maximum size of the Socket Receive buffer (default value is **1500** bytes)
 - **WIFI_EMW3080_SOCKETS_TIMEOUT** specifies the timeout for locking of the socket structure to prevent concurrent access (default value is **10000** ms)
 - **WIFI_EMW3080_SOCKETS_RCVTIMEO** specifies the default Socket Receive timeout (default value is **20000** ms)
 - **WIFI_EMW3080_SOCKETS_INTERVAL** specifies the polling interval for emulating blocking sockets (default value is **250** ms)

### MX_WIFI Component Driver Configuration Settings: mx_wifi_conf.h file

 - **MX_WIFI_USE_SPI** specifies SPI Interface usage. Since this Firmware only supports SPI Interface this setting must be set to **1**.
 - **MX_WIFI_SPI_NUM** specifies the SPI peripheral number. On this board SPI2 is used, so this setting should be set to **2**.
   If different SPI peripheral number is used this setting should be changed accordingly.
 - **MX_WIFI_SPI_DMA** specifies DMA usage for the SPI transfers. If DMA is used set this setting to **1**, otherwise set it to **0**.
 - **MX_WIFI_USE_CMSIS_OS** specifies usage of the CMSIS RTOS2. This setting must be set to **1**.
 - **MX_WIFI_API_DEBUG** specifies if Host driver API functions output debugging messages. Define this macro to enable debugging messages.
 - **MX_WIFI_HCI_DEBUG** specifies if Host driver HCI protocol functions output debugging messages. Define this macro to enable debugging messages.
 - **MX_WIFI_SLIP_DEBUG** specifies if SLIP protocol functions output debugging messages. Define this macro to enable debugging messages.
 - **MX_WIFI_SPI_DEBUG** specifies if Host driver SPI functions output debugging messages. Define this macro to enable debugging messages.
 - for other settings please consult source file implementation on their usage

## Driver Validation

Results of the CMSIS-Driver Validation for this driver can be found in the [WiFi_EMW3080_TestReport.txt](../Validation/WiFi_EMW3080_TestReport.txt) file.
The environment used for validation of the driver is described in the [WiFi_EMW3080_Environment.txt](../Validation/WiFi_EMW3080_Environment.txt) file.
