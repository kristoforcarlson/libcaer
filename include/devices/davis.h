/**
 * @file davis.h
 *
 * DAVIS specific configuration defines and information structures.
 */

#ifndef LIBCAER_DEVICES_DAVIS_H_
#define LIBCAER_DEVICES_DAVIS_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "usb.h"
#include "../events/polarity.h"
#include "../events/special.h"
#include "../events/frame.h"
#include "../events/imu6.h"

/**
 * Device type definition for iniLabs DAVIS FX2-based boards, like DAVIS240a/b/c.
 */
#define CAER_DEVICE_DAVIS_FX2 1
/**
 * Device type definition for iniLabs  DAVIS FX3-based boards, like DAVIS640.
 */
#define CAER_DEVICE_DAVIS_FX3 2

#define DAVIS_CHIP_DAVIS240A 0
#define DAVIS_CHIP_DAVIS240B 1
#define DAVIS_CHIP_DAVIS240C 2
#define DAVIS_CHIP_DAVIS128  3
#define DAVIS_CHIP_DAVIS346A 4
#define DAVIS_CHIP_DAVIS346B 5
#define DAVIS_CHIP_DAVIS640  6
#define DAVIS_CHIP_DAVISRGB  7
#define DAVIS_CHIP_DAVIS208  8
#define DAVIS_CHIP_DAVIS346C 9

#define IS_DAVIS128(chipID)  ((chipID) == DAVIS_CHIP_DAVIS128)
#define IS_DAVIS208(chipID)  ((chipID) == DAVIS_CHIP_DAVIS208)
#define IS_DAVIS240A(chipID) ((chipID) == DAVIS_CHIP_DAVIS240A)
#define IS_DAVIS240B(chipID) ((chipID) == DAVIS_CHIP_DAVIS240B)
#define IS_DAVIS240C(chipID) ((chipID) == DAVIS_CHIP_DAVIS240C)
#define IS_DAVIS240(chipID)  (IS_DAVIS240A(chipID) || IS_DAVIS240B(chipID) || IS_DAVIS240C(chipID))
#define IS_DAVIS346A(chipID) ((chipID) == DAVIS_CHIP_DAVIS346A)
#define IS_DAVIS346B(chipID) ((chipID) == DAVIS_CHIP_DAVIS346B)
#define IS_DAVIS346C(chipID) ((chipID) == DAVIS_CHIP_DAVIS346C)
#define IS_DAVIS346(chipID)  (IS_DAVIS346A(chipID) || IS_DAVIS346B(chipID) || IS_DAVIS346C(chipID))
#define IS_DAVIS640(chipID)  ((chipID) == DAVIS_CHIP_DAVIS640)
#define IS_DAVISRGB(chipID)  ((chipID) == DAVIS_CHIP_DAVISRGB)

#define DAVIS_CONFIG_MUX      0
#define DAVIS_CONFIG_DVS      1
#define DAVIS_CONFIG_APS      2
#define DAVIS_CONFIG_IMU      3
#define DAVIS_CONFIG_EXTINPUT 4
#define DAVIS_CONFIG_BIAS     5
#define DAVIS_CONFIG_CHIP     5
#define DAVIS_CONFIG_SYSINFO  6
#define DAVIS_CONFIG_USB      9

#define DAVIS_CONFIG_MUX_RUN                             0
#define DAVIS_CONFIG_MUX_TIMESTAMP_RUN                   1
#define DAVIS_CONFIG_MUX_TIMESTAMP_RESET                 2
#define DAVIS_CONFIG_MUX_FORCE_CHIP_BIAS_ENABLE          3
#define DAVIS_CONFIG_MUX_DROP_DVS_ON_TRANSFER_STALL      4
#define DAVIS_CONFIG_MUX_DROP_APS_ON_TRANSFER_STALL      5
#define DAVIS_CONFIG_MUX_DROP_IMU_ON_TRANSFER_STALL      6
#define DAVIS_CONFIG_MUX_DROP_EXTINPUT_ON_TRANSFER_STALL 7

#define DAVIS_CONFIG_DVS_SIZE_COLUMNS           0
#define DAVIS_CONFIG_DVS_SIZE_ROWS              1
#define DAVIS_CONFIG_DVS_ORIENTATION_INFO       2
#define DAVIS_CONFIG_DVS_RUN                    3
#define DAVIS_CONFIG_DVS_ACK_DELAY_ROW          4
#define DAVIS_CONFIG_DVS_ACK_DELAY_COLUMN       5
#define DAVIS_CONFIG_DVS_ACK_EXTENSION_ROW      6
#define DAVIS_CONFIG_DVS_ACK_EXTENSION_COLUMN   7
#define DAVIS_CONFIG_DVS_WAIT_ON_TRANSFER_STALL 8
#define DAVIS_CONFIG_DVS_FILTER_ROW_ONLY_EVENTS 9
#define DAVIS_CONFIG_DVS_EXTERNAL_AER_CONTROL   10
#define DAVIS_CONFIG_DVS_HAS_PIXEL_FILTER       11
#define DAVIS_CONFIG_DVS_FILTER_PIXEL_0_ROW     12
#define DAVIS_CONFIG_DVS_FILTER_PIXEL_0_COLUMN  13
#define DAVIS_CONFIG_DVS_FILTER_PIXEL_1_ROW     14
#define DAVIS_CONFIG_DVS_FILTER_PIXEL_1_COLUMN  15
#define DAVIS_CONFIG_DVS_FILTER_PIXEL_2_ROW     16
#define DAVIS_CONFIG_DVS_FILTER_PIXEL_2_COLUMN  17
#define DAVIS_CONFIG_DVS_FILTER_PIXEL_3_ROW     18
#define DAVIS_CONFIG_DVS_FILTER_PIXEL_3_COLUMN  19
#define DAVIS_CONFIG_DVS_FILTER_PIXEL_4_ROW     20
#define DAVIS_CONFIG_DVS_FILTER_PIXEL_4_COLUMN  21
#define DAVIS_CONFIG_DVS_FILTER_PIXEL_5_ROW     22
#define DAVIS_CONFIG_DVS_FILTER_PIXEL_5_COLUMN  23
#define DAVIS_CONFIG_DVS_FILTER_PIXEL_6_ROW     24
#define DAVIS_CONFIG_DVS_FILTER_PIXEL_6_COLUMN  25
#define DAVIS_CONFIG_DVS_FILTER_PIXEL_7_ROW     26
#define DAVIS_CONFIG_DVS_FILTER_PIXEL_7_COLUMN  27
#define DAVIS_CONFIG_DVS_HAS_BACKGROUND_ACTIVITY_FILTER    28
#define DAVIS_CONFIG_DVS_FILTER_BACKGROUND_ACTIVITY        29
#define DAVIS_CONFIG_DVS_FILTER_BACKGROUND_ACTIVITY_DELTAT 30
#define DAVIS_CONFIG_DVS_HAS_TEST_EVENT_GENERATOR          31
#define DAVIS_CONFIG_DVS_TEST_EVENT_GENERATOR_ENABLE       32

#define DAVIS_CONFIG_APS_SIZE_COLUMNS           0
#define DAVIS_CONFIG_APS_SIZE_ROWS              1
#define DAVIS_CONFIG_APS_ORIENTATION_INFO       2
#define DAVIS_CONFIG_APS_COLOR_FILTER           3
#define DAVIS_CONFIG_APS_RUN                    4
#define DAVIS_CONFIG_APS_RESET_READ             5
#define DAVIS_CONFIG_APS_WAIT_ON_TRANSFER_STALL 6
#define DAVIS_CONFIG_APS_HAS_GLOBAL_SHUTTER     7
#define DAVIS_CONFIG_APS_GLOBAL_SHUTTER         8
#define DAVIS_CONFIG_APS_START_COLUMN_0         9
#define DAVIS_CONFIG_APS_START_ROW_0            10
#define DAVIS_CONFIG_APS_END_COLUMN_0           11
#define DAVIS_CONFIG_APS_END_ROW_0              12
#define DAVIS_CONFIG_APS_EXPOSURE               13
#define DAVIS_CONFIG_APS_FRAME_DELAY            14
#define DAVIS_CONFIG_APS_RESET_SETTLE           15
#define DAVIS_CONFIG_APS_COLUMN_SETTLE          16
#define DAVIS_CONFIG_APS_ROW_SETTLE             17
#define DAVIS_CONFIG_APS_NULL_SETTLE            18
#define DAVIS_CONFIG_APS_HAS_QUAD_ROI           19
#define DAVIS_CONFIG_APS_START_COLUMN_1         20
#define DAVIS_CONFIG_APS_START_ROW_1            21
#define DAVIS_CONFIG_APS_END_COLUMN_1           22
#define DAVIS_CONFIG_APS_END_ROW_1              23
#define DAVIS_CONFIG_APS_START_COLUMN_2         24
#define DAVIS_CONFIG_APS_START_ROW_2            25
#define DAVIS_CONFIG_APS_END_COLUMN_2           26
#define DAVIS_CONFIG_APS_END_ROW_2              27
#define DAVIS_CONFIG_APS_START_COLUMN_3         28
#define DAVIS_CONFIG_APS_START_ROW_3            29
#define DAVIS_CONFIG_APS_END_COLUMN_3           30
#define DAVIS_CONFIG_APS_END_ROW_3              31
#define DAVIS_CONFIG_APS_HAS_EXTERNAL_ADC       32
#define DAVIS_CONFIG_APS_HAS_INTERNAL_ADC       33
#define DAVIS_CONFIG_APS_USE_INTERNAL_ADC       34
#define DAVIS_CONFIG_APS_SAMPLE_ENABLE          35
#define DAVIS_CONFIG_APS_SAMPLE_SETTLE          36
#define DAVIS_CONFIG_APS_RAMP_RESET             37
#define DAVIS_CONFIG_APS_RAMP_SHORT_RESET       38

// Extra timing settings for DAVISRGB APS module.
#define DAVISRGB_CONFIG_APS_TRANSFER    50
#define DAVISRGB_CONFIG_APS_RSFDSETTLE  51
#define DAVISRGB_CONFIG_APS_GSPDRESET   52
#define DAVISRGB_CONFIG_APS_GSRESETFALL 53
#define DAVISRGB_CONFIG_APS_GSTXFALL    54
#define DAVISRGB_CONFIG_APS_GSFDRESET   55

// Special control for taking snapshots.
#define DAVIS_CONFIG_APS_SNAPSHOT 80

#define DAVIS_CONFIG_IMU_RUN                     0
#define DAVIS_CONFIG_IMU_TEMP_STANDBY            1
#define DAVIS_CONFIG_IMU_ACCEL_STANDBY           2
#define DAVIS_CONFIG_IMU_GYRO_STANDBY            3
#define DAVIS_CONFIG_IMU_LP_CYCLE                4
#define DAVIS_CONFIG_IMU_LP_WAKEUP               5
#define DAVIS_CONFIG_IMU_SAMPLE_RATE_DIVIDER     6
#define DAVIS_CONFIG_IMU_DIGITAL_LOW_PASS_FILTER 7
#define DAVIS_CONFIG_IMU_ACCEL_FULL_SCALE        8
#define DAVIS_CONFIG_IMU_GYRO_FULL_SCALE         9

#define DAVIS_CONFIG_EXTINPUT_RUN_DETECTOR               0
#define DAVIS_CONFIG_EXTINPUT_DETECT_RISING_EDGES        1
#define DAVIS_CONFIG_EXTINPUT_DETECT_FALLING_EDGES       2
#define DAVIS_CONFIG_EXTINPUT_DETECT_PULSES              3
#define DAVIS_CONFIG_EXTINPUT_DETECT_PULSE_POLARITY      4
#define DAVIS_CONFIG_EXTINPUT_DETECT_PULSE_LENGTH        5
#define DAVIS_CONFIG_EXTINPUT_HAS_GENERATOR              6
#define DAVIS_CONFIG_EXTINPUT_RUN_GENERATOR              7
#define DAVIS_CONFIG_EXTINPUT_GENERATE_USE_CUSTOM_SIGNAL 8
#define DAVIS_CONFIG_EXTINPUT_GENERATE_PULSE_POLARITY    9
#define DAVIS_CONFIG_EXTINPUT_GENERATE_PULSE_INTERVAL    10
#define DAVIS_CONFIG_EXTINPUT_GENERATE_PULSE_LENGTH      11

#define DAVIS_CONFIG_SYSINFO_LOGIC_VERSION    0
#define DAVIS_CONFIG_SYSINFO_CHIP_IDENTIFIER  1
#define DAVIS_CONFIG_SYSINFO_DEVICE_IS_MASTER 2
#define DAVIS_CONFIG_SYSINFO_LOGIC_CLOCK      3
#define DAVIS_CONFIG_SYSINFO_ADC_CLOCK        4

#define DAVIS_CONFIG_USB_RUN                0
#define DAVIS_CONFIG_USB_EARLY_PACKET_DELAY 1

#define DAVIS128_CONFIG_BIAS_APSOVERFLOWLEVEL 0
#define DAVIS128_CONFIG_BIAS_APSCAS           1
#define DAVIS128_CONFIG_BIAS_ADCREFHIGH       2
#define DAVIS128_CONFIG_BIAS_ADCREFLOW        3
#define DAVIS128_CONFIG_BIAS_LOCALBUFBN       8
#define DAVIS128_CONFIG_BIAS_PADFOLLBN        9
#define DAVIS128_CONFIG_BIAS_DIFFBN           10
#define DAVIS128_CONFIG_BIAS_ONBN             11
#define DAVIS128_CONFIG_BIAS_OFFBN            12
#define DAVIS128_CONFIG_BIAS_PIXINVBN         13
#define DAVIS128_CONFIG_BIAS_PRBP             14
#define DAVIS128_CONFIG_BIAS_PRSFBP           15
#define DAVIS128_CONFIG_BIAS_REFRBP           16
#define DAVIS128_CONFIG_BIAS_READOUTBUFBP     17
#define DAVIS128_CONFIG_BIAS_APSROSFBN        18
#define DAVIS128_CONFIG_BIAS_ADCCOMPBP        19
#define DAVIS128_CONFIG_BIAS_COLSELLOWBN      20
#define DAVIS128_CONFIG_BIAS_DACBUFBP         21
#define DAVIS128_CONFIG_BIAS_LCOLTIMEOUTBN    22
#define DAVIS128_CONFIG_BIAS_AEPDBN           23
#define DAVIS128_CONFIG_BIAS_AEPUXBP          24
#define DAVIS128_CONFIG_BIAS_AEPUYBP          25
#define DAVIS128_CONFIG_BIAS_IFREFRBN         26
#define DAVIS128_CONFIG_BIAS_IFTHRBN          27
#define DAVIS128_CONFIG_BIAS_BIASBUFFER       34
#define DAVIS128_CONFIG_BIAS_SSP              35
#define DAVIS128_CONFIG_BIAS_SSN              36

#define DAVIS128_CONFIG_CHIP_DIGITALMUX0       128
#define DAVIS128_CONFIG_CHIP_DIGITALMUX1       129
#define DAVIS128_CONFIG_CHIP_DIGITALMUX2       130
#define DAVIS128_CONFIG_CHIP_DIGITALMUX3       131
#define DAVIS128_CONFIG_CHIP_ANALOGMUX0        132
#define DAVIS128_CONFIG_CHIP_ANALOGMUX1        133
#define DAVIS128_CONFIG_CHIP_ANALOGMUX2        134
#define DAVIS128_CONFIG_CHIP_BIASMUX0          135
#define DAVIS128_CONFIG_CHIP_RESETCALIBNEURON  136
#define DAVIS128_CONFIG_CHIP_TYPENCALIBNEURON  137
#define DAVIS128_CONFIG_CHIP_RESETTESTPIXEL    138
#define DAVIS128_CONFIG_CHIP_AERNAROW          140
#define DAVIS128_CONFIG_CHIP_USEAOUT           141
#define DAVIS128_CONFIG_CHIP_GLOBAL_SHUTTER    142
#define DAVIS128_CONFIG_CHIP_SELECTGRAYCOUNTER 143

#define DAVIS208_CONFIG_BIAS_APSOVERFLOWLEVEL 0
#define DAVIS208_CONFIG_BIAS_APSCAS           1
#define DAVIS208_CONFIG_BIAS_ADCREFHIGH       2
#define DAVIS208_CONFIG_BIAS_ADCREFLOW        3
#define DAVIS208_CONFIG_BIAS_RESETHIGHPASS    6
#define DAVIS208_CONFIG_BIAS_REFSS            7
#define DAVIS208_CONFIG_BIAS_LOCALBUFBN       8
#define DAVIS208_CONFIG_BIAS_PADFOLLBN        9
#define DAVIS208_CONFIG_BIAS_DIFFBN           10
#define DAVIS208_CONFIG_BIAS_ONBN             11
#define DAVIS208_CONFIG_BIAS_OFFBN            12
#define DAVIS208_CONFIG_BIAS_PIXINVBN         13
#define DAVIS208_CONFIG_BIAS_PRBP             14
#define DAVIS208_CONFIG_BIAS_PRSFBP           15
#define DAVIS208_CONFIG_BIAS_REFRBP           16
#define DAVIS208_CONFIG_BIAS_READOUTBUFBP     17
#define DAVIS208_CONFIG_BIAS_APSROSFBN        18
#define DAVIS208_CONFIG_BIAS_ADCCOMPBP        19
#define DAVIS208_CONFIG_BIAS_COLSELLOWBN      20
#define DAVIS208_CONFIG_BIAS_DACBUFBP         21
#define DAVIS208_CONFIG_BIAS_LCOLTIMEOUTBN    22
#define DAVIS208_CONFIG_BIAS_AEPDBN           23
#define DAVIS208_CONFIG_BIAS_AEPUXBP          24
#define DAVIS208_CONFIG_BIAS_AEPUYBP          25
#define DAVIS208_CONFIG_BIAS_IFREFRBN         26
#define DAVIS208_CONFIG_BIAS_IFTHRBN          27
#define DAVIS208_CONFIG_BIAS_REGBIASBP        28
#define DAVIS208_CONFIG_BIAS_REFSSBN          30
#define DAVIS208_CONFIG_BIAS_BIASBUFFER       34
#define DAVIS208_CONFIG_BIAS_SSP              35
#define DAVIS208_CONFIG_BIAS_SSN              36

#define DAVIS208_CONFIG_CHIP_DIGITALMUX0       128
#define DAVIS208_CONFIG_CHIP_DIGITALMUX1       129
#define DAVIS208_CONFIG_CHIP_DIGITALMUX2       130
#define DAVIS208_CONFIG_CHIP_DIGITALMUX3       131
#define DAVIS208_CONFIG_CHIP_ANALOGMUX0        132
#define DAVIS208_CONFIG_CHIP_ANALOGMUX1        133
#define DAVIS208_CONFIG_CHIP_ANALOGMUX2        134
#define DAVIS208_CONFIG_CHIP_BIASMUX0          135
#define DAVIS208_CONFIG_CHIP_RESETCALIBNEURON  136
#define DAVIS208_CONFIG_CHIP_TYPENCALIBNEURON  137
#define DAVIS208_CONFIG_CHIP_RESETTESTPIXEL    138
#define DAVIS208_CONFIG_CHIP_AERNAROW          140
#define DAVIS208_CONFIG_CHIP_USEAOUT           141
#define DAVIS208_CONFIG_CHIP_GLOBAL_SHUTTER    142
#define DAVIS208_CONFIG_CHIP_SELECTGRAYCOUNTER 143
#define DAVIS208_CONFIG_CHIP_SELECTPREAMPAVG   145
#define DAVIS208_CONFIG_CHIP_SELECTBIASREFSS   146
#define DAVIS208_CONFIG_CHIP_SELECTSENSE       147
#define DAVIS208_CONFIG_CHIP_SELECTPOSFB       148
#define DAVIS208_CONFIG_CHIP_SELECTHIGHPASS    149

#define DAVIS240_CONFIG_BIAS_DIFFBN             0
#define DAVIS240_CONFIG_BIAS_ONBN               1
#define DAVIS240_CONFIG_BIAS_OFFBN              2
#define DAVIS240_CONFIG_BIAS_APSCASEPC          3
#define DAVIS240_CONFIG_BIAS_DIFFCASBNC         4
#define DAVIS240_CONFIG_BIAS_APSROSFBN          5
#define DAVIS240_CONFIG_BIAS_LOCALBUFBN         6
#define DAVIS240_CONFIG_BIAS_PIXINVBN           7
#define DAVIS240_CONFIG_BIAS_PRBP               8
#define DAVIS240_CONFIG_BIAS_PRSFBP             9
#define DAVIS240_CONFIG_BIAS_REFRBP             10
#define DAVIS240_CONFIG_BIAS_AEPDBN             11
#define DAVIS240_CONFIG_BIAS_LCOLTIMEOUTBN      12
#define DAVIS240_CONFIG_BIAS_AEPUXBP            13
#define DAVIS240_CONFIG_BIAS_AEPUYBP            14
#define DAVIS240_CONFIG_BIAS_IFTHRBN            15
#define DAVIS240_CONFIG_BIAS_IFREFRBN           16
#define DAVIS240_CONFIG_BIAS_PADFOLLBN          17
#define DAVIS240_CONFIG_BIAS_APSOVERFLOWLEVELBN 18
#define DAVIS240_CONFIG_BIAS_BIASBUFFER         19
#define DAVIS240_CONFIG_BIAS_SSP                20
#define DAVIS240_CONFIG_BIAS_SSN                21

#define DAVIS240_CONFIG_CHIP_DIGITALMUX0         128
#define DAVIS240_CONFIG_CHIP_DIGITALMUX1         129
#define DAVIS240_CONFIG_CHIP_DIGITALMUX2         130
#define DAVIS240_CONFIG_CHIP_DIGITALMUX3         131
#define DAVIS240_CONFIG_CHIP_ANALOGMUX0          132
#define DAVIS240_CONFIG_CHIP_ANALOGMUX1          133
#define DAVIS240_CONFIG_CHIP_ANALOGMUX2          134
#define DAVIS240_CONFIG_CHIP_BIASMUX0            135
#define DAVIS240_CONFIG_CHIP_RESETCALIBNEURON    136
#define DAVIS240_CONFIG_CHIP_TYPENCALIBNEURON    137
#define DAVIS240_CONFIG_CHIP_RESETTESTPIXEL      138
#define DAVIS240_CONFIG_CHIP_SPECIALPIXELCONTROL 139
#define DAVIS240_CONFIG_CHIP_AERNAROW            140
#define DAVIS240_CONFIG_CHIP_USEAOUT             141
#define DAVIS240_CONFIG_CHIP_GLOBAL_SHUTTER      142

#define DAVIS346_CONFIG_BIAS_APSOVERFLOWLEVEL 0
#define DAVIS346_CONFIG_BIAS_APSCAS           1
#define DAVIS346_CONFIG_BIAS_ADCREFHIGH       2
#define DAVIS346_CONFIG_BIAS_ADCREFLOW        3
#define DAVIS346_CONFIG_BIAS_ADCTESTVOLTAGE   4
#define DAVIS346_CONFIG_BIAS_LOCALBUFBN       8
#define DAVIS346_CONFIG_BIAS_PADFOLLBN        9
#define DAVIS346_CONFIG_BIAS_DIFFBN           10
#define DAVIS346_CONFIG_BIAS_ONBN             11
#define DAVIS346_CONFIG_BIAS_OFFBN            12
#define DAVIS346_CONFIG_BIAS_PIXINVBN         13
#define DAVIS346_CONFIG_BIAS_PRBP             14
#define DAVIS346_CONFIG_BIAS_PRSFBP           15
#define DAVIS346_CONFIG_BIAS_REFRBP           16
#define DAVIS346_CONFIG_BIAS_READOUTBUFBP     17
#define DAVIS346_CONFIG_BIAS_APSROSFBN        18
#define DAVIS346_CONFIG_BIAS_ADCCOMPBP        19
#define DAVIS346_CONFIG_BIAS_COLSELLOWBN      20
#define DAVIS346_CONFIG_BIAS_DACBUFBP         21
#define DAVIS346_CONFIG_BIAS_LCOLTIMEOUTBN    22
#define DAVIS346_CONFIG_BIAS_AEPDBN           23
#define DAVIS346_CONFIG_BIAS_AEPUXBP          24
#define DAVIS346_CONFIG_BIAS_AEPUYBP          25
#define DAVIS346_CONFIG_BIAS_IFREFRBN         26
#define DAVIS346_CONFIG_BIAS_IFTHRBN          27
#define DAVIS346_CONFIG_BIAS_BIASBUFFER       34
#define DAVIS346_CONFIG_BIAS_SSP              35
#define DAVIS346_CONFIG_BIAS_SSN              36

#define DAVIS346_CONFIG_CHIP_DIGITALMUX0       128
#define DAVIS346_CONFIG_CHIP_DIGITALMUX1       129
#define DAVIS346_CONFIG_CHIP_DIGITALMUX2       130
#define DAVIS346_CONFIG_CHIP_DIGITALMUX3       131
#define DAVIS346_CONFIG_CHIP_ANALOGMUX0        132
#define DAVIS346_CONFIG_CHIP_ANALOGMUX1        133
#define DAVIS346_CONFIG_CHIP_ANALOGMUX2        134
#define DAVIS346_CONFIG_CHIP_BIASMUX0          135
#define DAVIS346_CONFIG_CHIP_RESETCALIBNEURON  136
#define DAVIS346_CONFIG_CHIP_TYPENCALIBNEURON  137
#define DAVIS346_CONFIG_CHIP_RESETTESTPIXEL    138
#define DAVIS346_CONFIG_CHIP_AERNAROW          140
#define DAVIS346_CONFIG_CHIP_USEAOUT           141
#define DAVIS346_CONFIG_CHIP_GLOBAL_SHUTTER    142
#define DAVIS346_CONFIG_CHIP_SELECTGRAYCOUNTER 143
#define DAVIS346_CONFIG_CHIP_TESTADC           144

#define DAVIS640_CONFIG_BIAS_APSOVERFLOWLEVEL 0
#define DAVIS640_CONFIG_BIAS_APSCAS           1
#define DAVIS640_CONFIG_BIAS_ADCREFHIGH       2
#define DAVIS640_CONFIG_BIAS_ADCREFLOW        3
#define DAVIS640_CONFIG_BIAS_ADCTESTVOLTAGE   4
#define DAVIS640_CONFIG_BIAS_LOCALBUFBN       8
#define DAVIS640_CONFIG_BIAS_PADFOLLBN        9
#define DAVIS640_CONFIG_BIAS_DIFFBN           10
#define DAVIS640_CONFIG_BIAS_ONBN             11
#define DAVIS640_CONFIG_BIAS_OFFBN            12
#define DAVIS640_CONFIG_BIAS_PIXINVBN         13
#define DAVIS640_CONFIG_BIAS_PRBP             14
#define DAVIS640_CONFIG_BIAS_PRSFBP           15
#define DAVIS640_CONFIG_BIAS_REFRBP           16
#define DAVIS640_CONFIG_BIAS_READOUTBUFBP     17
#define DAVIS640_CONFIG_BIAS_APSROSFBN        18
#define DAVIS640_CONFIG_BIAS_ADCCOMPBP        19
#define DAVIS640_CONFIG_BIAS_COLSELLOWBN      20
#define DAVIS640_CONFIG_BIAS_DACBUFBP         21
#define DAVIS640_CONFIG_BIAS_LCOLTIMEOUTBN    22
#define DAVIS640_CONFIG_BIAS_AEPDBN           23
#define DAVIS640_CONFIG_BIAS_AEPUXBP          24
#define DAVIS640_CONFIG_BIAS_AEPUYBP          25
#define DAVIS640_CONFIG_BIAS_IFREFRBN         26
#define DAVIS640_CONFIG_BIAS_IFTHRBN          27
#define DAVIS640_CONFIG_BIAS_BIASBUFFER       34
#define DAVIS640_CONFIG_BIAS_SSP              35
#define DAVIS640_CONFIG_BIAS_SSN              36

#define DAVIS640_CONFIG_CHIP_DIGITALMUX0       128
#define DAVIS640_CONFIG_CHIP_DIGITALMUX1       129
#define DAVIS640_CONFIG_CHIP_DIGITALMUX2       130
#define DAVIS640_CONFIG_CHIP_DIGITALMUX3       131
#define DAVIS640_CONFIG_CHIP_ANALOGMUX0        132
#define DAVIS640_CONFIG_CHIP_ANALOGMUX1        133
#define DAVIS640_CONFIG_CHIP_ANALOGMUX2        134
#define DAVIS640_CONFIG_CHIP_BIASMUX0          135
#define DAVIS640_CONFIG_CHIP_RESETCALIBNEURON  136
#define DAVIS640_CONFIG_CHIP_TYPENCALIBNEURON  137
#define DAVIS640_CONFIG_CHIP_RESETTESTPIXEL    138
#define DAVIS640_CONFIG_CHIP_AERNAROW          140
#define DAVIS640_CONFIG_CHIP_USEAOUT           141
#define DAVIS640_CONFIG_CHIP_GLOBAL_SHUTTER    142
#define DAVIS640_CONFIG_CHIP_SELECTGRAYCOUNTER 143
#define DAVIS640_CONFIG_CHIP_TESTADC           144

#define DAVISRGB_CONFIG_BIAS_APSCAS             0
#define DAVISRGB_CONFIG_BIAS_OVG1LO             1
#define DAVISRGB_CONFIG_BIAS_OVG2LO             2
#define DAVISRGB_CONFIG_BIAS_TX2OVG2HI          3
#define DAVISRGB_CONFIG_BIAS_GND07              4
#define DAVISRGB_CONFIG_BIAS_ADCTESTVOLTAGE     5
#define DAVISRGB_CONFIG_BIAS_ADCREFHIGH         6
#define DAVISRGB_CONFIG_BIAS_ADCREFLOW          7
#define DAVISRGB_CONFIG_BIAS_IFREFRBN           8
#define DAVISRGB_CONFIG_BIAS_IFTHRBN            9
#define DAVISRGB_CONFIG_BIAS_LOCALBUFBN         10
#define DAVISRGB_CONFIG_BIAS_PADFOLLBN          11
#define DAVISRGB_CONFIG_BIAS_PIXINVBN           13
#define DAVISRGB_CONFIG_BIAS_DIFFBN             14
#define DAVISRGB_CONFIG_BIAS_ONBN               15
#define DAVISRGB_CONFIG_BIAS_OFFBN              16
#define DAVISRGB_CONFIG_BIAS_PRBP               17
#define DAVISRGB_CONFIG_BIAS_PRSFBP             18
#define DAVISRGB_CONFIG_BIAS_REFRBP             19
#define DAVISRGB_CONFIG_BIAS_ARRAYBIASBUFFERBN  20
#define DAVISRGB_CONFIG_BIAS_ARRAYLOGICBUFFERBN 22
#define DAVISRGB_CONFIG_BIAS_FALLTIMEBN         23
#define DAVISRGB_CONFIG_BIAS_RISETIMEBP         24
#define DAVISRGB_CONFIG_BIAS_READOUTBUFBP       25
#define DAVISRGB_CONFIG_BIAS_APSROSFBN          26
#define DAVISRGB_CONFIG_BIAS_ADCCOMPBP          27
#define DAVISRGB_CONFIG_BIAS_DACBUFBP           28
#define DAVISRGB_CONFIG_BIAS_LCOLTIMEOUTBN      30
#define DAVISRGB_CONFIG_BIAS_AEPDBN             31
#define DAVISRGB_CONFIG_BIAS_AEPUXBP            32
#define DAVISRGB_CONFIG_BIAS_AEPUYBP            33
#define DAVISRGB_CONFIG_BIAS_BIASBUFFER         34
#define DAVISRGB_CONFIG_BIAS_SSP                35
#define DAVISRGB_CONFIG_BIAS_SSN                36

#define DAVISRGB_CONFIG_CHIP_DIGITALMUX0       128
#define DAVISRGB_CONFIG_CHIP_DIGITALMUX1       129
#define DAVISRGB_CONFIG_CHIP_DIGITALMUX2       130
#define DAVISRGB_CONFIG_CHIP_DIGITALMUX3       131
#define DAVISRGB_CONFIG_CHIP_ANALOGMUX0        132
#define DAVISRGB_CONFIG_CHIP_ANALOGMUX1        133
#define DAVISRGB_CONFIG_CHIP_ANALOGMUX2        134
#define DAVISRGB_CONFIG_CHIP_BIASMUX0          135
#define DAVISRGB_CONFIG_CHIP_RESETCALIBNEURON  136
#define DAVISRGB_CONFIG_CHIP_TYPENCALIBNEURON  137
#define DAVISRGB_CONFIG_CHIP_RESETTESTPIXEL    138
#define DAVISRGB_CONFIG_CHIP_AERNAROW          140
#define DAVISRGB_CONFIG_CHIP_USEAOUT           141
#define DAVISRGB_CONFIG_CHIP_SELECTGRAYCOUNTER 143
#define DAVISRGB_CONFIG_CHIP_TESTADC           144
#define DAVISRGB_CONFIG_CHIP_ADJUSTOVG1LO      145
#define DAVISRGB_CONFIG_CHIP_ADJUSTOVG2LO      146
#define DAVISRGB_CONFIG_CHIP_ADJUSTTX2OVG2HI   147

/**
 * DAVIS device-related information.
 */
struct caer_davis_info {
	// Unique device identifier. Also 'source' for events.
	uint16_t deviceID;
	// Device information string, for logging purposes.
	char *deviceString;
	// Logic (FPGA/CPLD) version.
	uint16_t logicVersion;
	// Whether the device is a time-stamp master or slave.
	bool deviceIsMaster;
	// Clock in MHz for main logic (FPGA/CPLD).
	uint16_t logicClock;
	// Clock in MHz for ADC/APS logic (FPGA/CPLD).
	uint16_t adcClock;
	// Chip identifier/type.
	uint16_t chipID;
	// DVS X axis resolution.
	uint16_t dvsSizeX;
	// DVS Y axis resolution.
	uint16_t dvsSizeY;
	// Feature test: DVS pixel-level filtering.
	bool dvsHasPixelFilter;
	// Feature test: DVS Background Activity filter.
	bool dvsHasBackgroundActivityFilter;
	// Feature test: fake event generator (testing/debug).
	bool dvsHasTestEventGenerator;
	// APS X axis resolution.
	uint16_t apsSizeX;
	// APS Y axis resolution.
	uint16_t apsSizeY;
	// APS color filter type.
	uint8_t apsColorFilter;
	// Feature test: APS supports Global Shutter.
	bool apsHasGlobalShutter;
	// Feature test: APS supports Quadruple Region-of-Interest readout.
	bool apsHasQuadROI;
	// Feature test: APS supports External ADC for getting the image.
	bool apsHasExternalADC;
	// Feature test: APS supports Internal (on-chip) ADC for getting the image.
	bool apsHasInternalADC;
	// Feature test: External Input module supports Signal-Generation.
	bool extInputHasGenerator;
};

/**
 * Return basic information on the device, such as its ID, its
 * resolution, the logic version, and so on. See the 'struct
 * caer_davis_info' documentation for more details.
 *
 * @param handle a valid device handle.
 *
 * @return a copy of the device information structure if successful,
 *         an empty structure (all zeros) on failure.
 */
struct caer_davis_info caerDavisInfoGet(caerDeviceHandle handle);

/**
 * On-chip voltage digital-to-analog converter configuration.
 * See 'http://inilabs.com/support/biasing/' for more details.
 */
struct caer_bias_vdac {
	// Voltage, between 0 and 63, as a fraction of 1/64th of VDD=3.3V.
	uint8_t voltageValue;
	// Current, between 0 and 7, that drives the voltage.
	uint8_t currentValue;
};

/**
 * Transform VDAC bias structure into internal integer representation,
 * suited for sending directly to the device via caerDeviceConfigSet().
 *
 * @param vdacBias VDAC bias structure.
 *
 * @return internal integer representation for device configuration.
 */
uint16_t caerBiasVDACGenerate(struct caer_bias_vdac vdacBias);
/**
 * Transform internal integer representation, as received by calls to
 * caerDeviceConfigGet(), into a VDAC bias structure, for easier
 * handling and understanding of the various parameters.
 *
 * @param vdacBias internal integer representation from device.
 *
 * @return VDAC bias structure.
 */
struct caer_bias_vdac caerBiasVDACParse(uint16_t vdacBias);

/**
 * On-chip coarse-fine bias current configuration.
 * See 'http://inilabs.com/support/biasing/' for more details.
 */
struct caer_bias_coarsefine {
	// Coarse current, from 0 to 7, creates big variations in output current.
	uint8_t coarseValue;
	// Fine current, from 0 to 255, creates small variations in output current.
	uint8_t fineValue;
	// Whether this bias is enabled or not.
	bool enabled;
	// Bias sex: true for 'N' type, false for 'P' type.
	bool sexN;
	// Bias type: true for 'Normal', false for 'Cascode'.
	bool typeNormal;
	// Bias current level: true for 'Normal, false for 'Low'.
	bool currentLevelNormal;
};

/**
 * Transform coarse-fine bias structure into internal integer representation,
 * suited for sending directly to the device via caerDeviceConfigSet().
 *
 * @param coarseFineBias coarse-fine bias structure.
 *
 * @return internal integer representation for device configuration.
 */
uint16_t caerBiasCoarseFineGenerate(struct caer_bias_coarsefine coarseFineBias);
/**
 * Transform internal integer representation, as received by calls to
 * caerDeviceConfigGet(), into a coarse-fine bias structure, for easier
 * handling and understanding of the various parameters.
 *
 * @param coarseFineBias internal integer representation from device.
 *
 * @return coarse-fine bias structure.
 */
struct caer_bias_coarsefine caerBiasCoarseFineParse(uint16_t coarseFineBias);

/**
 * Shifted-source bias operating mode.
 */
enum caer_bias_shiftedsource_operating_mode {
	SHIFTED_SOURCE = 0, HI_Z = 1, TIED_TO_RAIL = 2,
};

/**
 * Shifted-source bias voltage level.
 */
enum caer_bias_shiftedsource_voltage_level {
	SPLIT_GATE = 0, SINGLE_DIODE = 1, DOUBLE_DIODE = 2,
};

/**
 * On-chip shifted-source bias current configuration.
 * See 'http://inilabs.com/support/biasing/' for more details.
 */
struct caer_bias_shiftedsource {
	// Shifted-source bias level, from 0 to 63.
	uint8_t refValue;
	// Shifted-source bias current for buffer amplifier, from 0 to 63.
	uint8_t regValue;
	// Shifted-source operating mode (see enum caer_bias_shiftedsource_operating_mode).
	enum caer_bias_shiftedsource_operating_mode operatingMode;
	// Shifted-source voltage level (see enum caer_bias_shiftedsource_voltage_level).
	enum caer_bias_shiftedsource_voltage_level voltageLevel;
};

/**
 * Transform shifted-source bias structure into internal integer representation,
 * suited for sending directly to the device via caerDeviceConfigSet().
 *
 * @param shiftedSourceBias shifted-source bias structure.
 *
 * @return internal integer representation for device configuration.
 */
uint16_t caerBiasShiftedSourceGenerate(struct caer_bias_shiftedsource shiftedSourceBias);
/**
 * Transform internal integer representation, as received by calls to
 * caerDeviceConfigGet(), into a shifted-source bias structure, for easier
 * handling and understanding of the various parameters.
 *
 * @param shiftedSourceBias internal integer representation from device.
 *
 * @return shifted-source bias structure.
 */
struct caer_bias_shiftedsource caerBiasShiftedSourceParse(uint16_t shiftedSourceBias);

#ifdef __cplusplus
}
#endif

#endif /* LIBCAER_DEVICES_DAVIS_H_ */
