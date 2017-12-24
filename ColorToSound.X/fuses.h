/*!
 * @file Nursery_it_config.h
 * @brief エコナーセリーシステム IT基板 PIC用ファームウェア Config設定ヘッダファイル
 *
 * @author 第一開発部 システム設計グループ 西輝之
 * @date 2017.10.19
 * @version 1.00
 * @copyright 2017 Elm, Inc. All rights reserved.
 *
 * @attention
 * 動作環境、開発環境などは以下のとおりです。
 *   - Microcontroller : Microchip PIC18F25K22
 *   - IDE : MPLAB X V4.05
 *   - Compiler : XC8 v1.44
 *
 * @note
 *  - このソースコードはdoxygen (http://www.doxygen.jp/)で出力可能です。
 *
 * @todo
 *
 * @bug
 *
 * @attention
 */

#ifndef __CONFIG_H // 重複してincludeされた時の対策
#define __CONFIG_H

/*
 * PIC CONFIGURATION
 */
//#pragma config FOSC = INTIO7 // Internal oscillator block, CLKOUT function on OSC2
#pragma config FOSC = INTIO67 // Internal oscillator block
//#pragma config PLLCFG = ON // Oscillator multiplied by 4
#pragma config PLLCFG = OFF // Oscillator multiplied by 4
#pragma config PRICLKEN = OFF // Primary clock can be disabled by software
#pragma config FCMEN = OFF // Fail-Safe Clock Monitor disabled
#pragma config IESO = OFF // Oscillator Switchover mode disabled

#pragma config PWRTEN = ON // Power up timer enabled
//#pragma config BOREN = OFF // Brown-out Reset disabled in hardware and software
#pragma config BOREN = SBORDIS // Brown-out Reset enabled in hardware only (SBOREN is disabled)
#pragma config BORV = 285 // VBOR set to 2.85 V nominal
//#pragma config WDTEN = OFF // Watch dog timer is always disabled. SWDTEN has no effect.
#pragma config WDTEN = ON // WDT is always enabled. SWDTEN bit has no effect
#pragma config WDTPS = 32768 // Watchdog Timer Postscale Select bits [1:2^n n=1-15]

#pragma config CCP2MX = PORTC1 // CCP2 input/output is multiplexed with RC1
#pragma config PBADEN = OFF // PORTB<5:0> pins are configured as digital I/O on Reset
#pragma config CCP3MX = PORTB5 // P3A/CCP3 input/output is multiplexed with RB5
#pragma config HFOFST = OFF // HFINTOSC output and ready status are delayed by the oscillator stable status
#pragma config T3CMX = PORTB5 // T3CKI is on RB5
#pragma config P2BMX = PORTC0 // P2B is on RC0
#pragma config MCLRE = EXTMCLR // MCLR pin enabled, RE3 input pin disabled

#pragma config STVREN = ON // Stack full/underflow will cause Reset

#pragma config LVP = OFF // Single-Supply ICSP disabled

#pragma config XINST = OFF // Instruction set extension and Indexed Addressing mode disabled (Legacy mode)
#pragma config DEBUG = OFF // Background Debug: Disabled

#if 1
#pragma config CP0 = ON // Block 0 (000800-003FFFh) code-protected
#pragma config CP1 = ON // Block 1 (004000-007FFFh) code-protected
#pragma config CP2 = ON // Block 2 (008000-00BFFFh) code-protected
#pragma config CP3 = ON // Block 3 (00C000-00FFFFh) code-protected
#else
#pragma config CP0 = OFF // Block 0 (000800-003FFFh) code-protected
#pragma config CP1 = OFF // Block 1 (004000-007FFFh) code-protected
#pragma config CP2 = OFF // Block 2 (008000-00BFFFh) code-protected
#pragma config CP3 = OFF // Block 3 (00C000-00FFFFh) code-protected
#endif
        
#pragma config CPB = OFF // Boot block (000000-0007FFh) not code-protected
#pragma config CPD = OFF // Data EEPROM not code-protected
#pragma config WRT0 = OFF // Block 0 (000800-003FFFh) not write-protected 
#pragma config WRT1 = OFF // Block 1 (004000-007FFFh) not write-protected
#pragma config WRT2 = OFF // Block 2 (008000-00BFFFh) not write-protected
#pragma config WRT3 = OFF // Block 3 (00C000-00FFFFh) not write-protected
#pragma config WRTC = OFF // Configuration registers (300000-3000FFh) not write-protected
#pragma config WRTB = OFF // Boot Block (000000-0007FFh) not write-protected
#pragma config WRTD = OFF // Data EEPROM not write-protected
#pragma config EBTR0 = OFF // Block 0 (000800-003FFFh) not protected from table reads executed in other blocks
#pragma config EBTR1 = OFF // Block 1 (004000-007FFFh) not protected from table reads executed in other blocks
#pragma config EBTR2 = OFF // Block 2 (008000-00BFFFh) not protected from table reads executed in other blocks
#pragma config EBTR3 = OFF // Block 3 (00C000-00FFFFh) not protected from table reads executed in other blocks
#pragma config EBTRB = OFF // Boot Block (000000-0007FFh) not protected from table reads executed in other blocks

#endif

// 以下、doxygenで出力される説明ページ用の情報です。Mainpageはmain.cに記載しています。
/*!
 * @page picconf PIC Configuration
 * PIC18F25K22のコンフィグレーション情報です。
 * 
 * @section FOSC Oscillator Selection bits
 * 
 * |設定              |備考                                                                                       |
 * |:----------------|:-----------------------------------------------------------------------------------------|
 * | FOSC = LP       | LP oscillator                                                                            |
 * | FOSC = XT       | XT oscillator                                                                            |
 * | FOSC = HSHP     | HS oscillator (high power > 16 MHz)                                                      |
 * | FOSC = HSMP     | HS oscillator (medium power 4-16 MHz)                                                    |
 * | FOSC = ECHP     | EC oscillator, CLKOUT function on OSC2 (high power, >16 MHz)                             |
 * | FOSC = ECHPIO6  | EC oscillator (high power, >16 MHz)                                                      |
 * | FOSC = RC       | External RC oscillator, CLKOUT function on OSC2                                          |
 * | FOSC = RCIO6    | External RC oscillator                                                                   |
 * | FOSC = INTIO67  | Internal oscillator block                                                                |
 * | FOSC = INTIO7   | Internal oscillator block, CLKOUT function on OSC2                                       |
 * | FOSC = ECMP     | EC oscillator, CLKOUT function on OSC2 (medium power, 500 kHz-16 MHz)                    |
 * | FOSC = ECMPIO6  | EC oscillator (medium power, 500 kHz-16 MHz)                                             |
 * | FOSC = ECLP     | EC oscillator, CLKOUT function on OSC2 (low power, <500 kHz)                             |
 * | FOSC = ECLPIO6  | EC oscillator (low power, <500 kHz)                                                      |
 *
 * @section PLLCFG 4X PLL Enable:
 * 
 * |設定              |備考                                                                                       |
 * |:----------------|:-----------------------------------------------------------------------------------------|
 * | PLLCFG = OFF    | Oscillator used directly                                                                 |
 * | PLLCFG = ON     | Oscillator multiplied by 4                                                               |
 *
 * @section PRICLKEN Primary clock enable bit:
 * 
 * |設定              |備考                                                                                       |
 * |:----------------|:-----------------------------------------------------------------------------------------|
 * | PRICLKEN = OFF  | Primary clock can be disabled by software                                                |
 * | PRICLKEN = ON   | Primary clock enabled                                                                    |
 *
 * @section FCMEN Fail-Safe Clock Monitor Enable bit:
 * |設定              |備考                                                                                       |
 * |:----------------|:-----------------------------------------------------------------------------------------|
 * | FCMEN = OFF     | Fail-Safe Clock Monitor disabled                                                         |
 * | FCMEN = ON      | Fail-Safe Clock Monitor enabled                                                          |
 *
 * @section IESO IESO Internal/External Oscillator Switchover bit:
 *
 * |設定              |備考                                                                                       |
 * |:----------------|:-----------------------------------------------------------------------------------------|
 * | IESO = OFF      | Oscillator Switchover mode disabled                                                      |
 * | IESO = ON       | Oscillator Switchover mode enabled                                                       |
 *
 * @section PWRTEN Power-up Timer Enable bit:
 * 
 * |設定              |備考                                                                                       |
 * |:----------------|:-----------------------------------------------------------------------------------------|
 * | PWRTEN = ON     | Power up timer enabled                                                                   |
 * | PWRTEN = OFF    | Power up timer disabled                                                                  |
 *
 * @section BOREN Brown-out Reset Enable bits:
 * 
 * |設定              |備考                                                                                       |
 * |:----------------|:-----------------------------------------------------------------------------------------|
 * | BOREN = OFF     | Brown-out Reset disabled in hardware and software                                        |
 * | BOREN = ON      | Brown-out Reset enabled and controlled by software (SBOREN is enabled)                   |
 * | BOREN = NOSLP   | Brown-out Reset enabled in hardware only and disabled in Sleep mode (SBOREN is disabled) |
 * | BOREN = SBORDIS | Brown-out Reset enabled in hardware only (SBOREN is disabled)                            |
 *
 * @section BORV Brown Out Reset Voltage bits:
 * 
 * |設定              |備考                                                                                       |
 * |:----------------|:-----------------------------------------------------------------------------------------|
 * | BORV = 285      | VBOR set to 2.85 V nominal                                                               |
 * | BORV = 250      | VBOR set to 2.50 V nominal                                                               |
 * | BORV = 220      | VBOR set to 2.20 V nominal                                                               |
 * | BORV = 190      | VBOR set to 1.90 V nominal                                                               |
 *
 * @seciton WDTEN Watchdog Timer Enable bits:
 * 
 * |設定              |備考                                                                                       |
 * |:----------------|:-----------------------------------------------------------------------------------------|
 * | WDTEN = OFF     | Watch dog timer is always disabled. SWDTEN has no effect.                                |
 * | WDTEN = NOSLP   | WDT is disabled in sleep, otherwise enabled. SWDTEN bit has no effect                    |
 * | WDTEN = SWON    | WDT is controlled by SWDTEN bit of the WDTCON register                                   |
 * | WDTEN = ON      | WDT is always enabled. SWDTEN bit has no effect                                          |
 *
 * @section WDTPS Watchdog Timer Postscale Select bits:
 * 
 * |設定              |備考                                                                                       |
 * |:----------------|:-----------------------------------------------------------------------------------------|
 * | WDTPS = 1       | 1:01                                                                                     |
 * | WDTPS = 2       | 1:02                                                                                     |
 * | WDTPS = 4       | 1:04                                                                                     |
 * | WDTPS = 8       | 1:08                                                                                     |
 * | WDTPS = 16      | 1:16                                                                                     |
 * | WDTPS = 32      | 1:32                                                                                     |
 * | WDTPS = 64      | 1:64                                                                                     |
 * | WDTPS = 128     | 1:128                                                                                    |
 * | WDTPS = 256     | 1:256                                                                                    |
 * | WDTPS = 512     | 1:512                                                                                    |
 * | WDTPS = 1024    | 1:1024                                                                                   |
 * | WDTPS = 2048    | 1:2048                                                                                   |
 * | WDTPS = 4096    | 1:4096                                                                                   |
 * | WDTPS = 8192    | 1:8192                                                                                   |
 * | WDTPS = 16384   | 1:16384                                                                                  |
 * | WDTPS = 32768   | 1:32768                                                                                  |
 *
 * @section CCP2MX CCP2 MUX bit:
 * 
 * |設定              |備考                                                                                       |
 * |:----------------|:-----------------------------------------------------------------------------------------|
 * | CCP2MX = PORTB3 | CCP2 input/output is multiplexed with RB3                                                |
 * | CCP2MX = PORTC1 | CCP2 input/output is multiplexed with RC1                                                |
 *
 * @section PBADEN PORTB A/D Enable bit:
 * 
 * |設定              |備考                                                                                       |
 * |:----------------|:-----------------------------------------------------------------------------------------|
 * | PBADEN = OFF    | PORTB<5:0> pins are configured as digital I/O on Reset                                   |
 * | PBADEN = ON     | PORTB<5:0> pins are configured as analog input channels on Reset                         |
 *
 * @section CCP3MX P3A/CCP3 Mux bit:
 * 
 * |設定              |備考                                                                                       |
 * |:----------------|:-----------------------------------------------------------------------------------------|
 * | CCP3MX = PORTC6 | P3A/CCP3 input/output is mulitplexed with RC6                                            |
 * | CCP3MX = PORTB5 | P3A/CCP3 input/output is multiplexed with RB5                                            |
 *
 * @section HFOFST HFINTOSC Fast Start-up:
 * 
 * |設定              |備考                                                                                       |
 * |:----------------|:-----------------------------------------------------------------------------------------|
 * | HFOFST = OFF    | HFINTOSC output and ready status are delayed by the oscillator stable status             |
 * | HFOFST = ON     | HFINTOSC output and ready status are not delayed by the oscillator stable status         |
 * 
 * @section T3CMX Timer3 Clock input mux bit:
 * 
 * |設定              |備考                                                                                       |
 * |:----------------|:-----------------------------------------------------------------------------------------|
 * | T3CMX = PORTB5  | T3CKI is on RB5                                                                          |
 * | T3CMX = PORTC0  | T3CKI is on RC0                                                                          |
 * 
 * @section P2BMX ECCP2 B output mux bit:
 * 
 * |設定              |備考                                                                                       |
 * |:----------------|:-----------------------------------------------------------------------------------------|
 * | P2BMX = PORTC0  | P2B is on RC0                                                                            |
 * | P2BMX = PORTB5  | P2B is on RB5                                                                            |
 *
 * @section MCLRE MCLR Pin Enable bit:
 * 
 * |設定              |備考                                                                                       |
 * |:----------------|:-----------------------------------------------------------------------------------------|
 * | MCLRE = INTMCLR | RE3 input pin enabled; MCLR disabled                                                     |
 * | MCLRE = EXTMCLR | MCLR pin enabled, RE3 input pin disabled                                                 |
 *
 * @section STVREN Stack Full/Underflow Reset Enable bit:
 * 
 * |設定              |備考                                                                                       |
 * |:----------------|:-----------------------------------------------------------------------------------------|
 * | STVREN = OFF    | Stack full/underflow will not cause Reset                                                |
 * | STVREN = ON     | Stack full/underflow will cause Reset                                                    |
 *
 * @section LVP Single-Supply ICSP Enable bit:
 * 
 * |設定              |備考                                                                                       |
 * |:----------------|:-----------------------------------------------------------------------------------------|
 * | LVP = OFF       | Single-Supply ICSP disabled                                                              |
 * | LVP = ON        | Single-Supply ICSP enabled if MCLRE is also 1                                            |
 *
 * @section XINST Extended Instruction Set Enable bit:
 * 
 * |設定              |備考                                                                                       |
 * |:----------------|:-----------------------------------------------------------------------------------------|
 * | XINST = OFF     | Instruction set extension and Indexed Addressing mode disabled (Legacy mode)             |
 * | XINST = ON      | Instruction set extension and Indexed Addressing mode enabled                            |
 *
 * @section DEBUG Background Debug:
 * 
 * |設定              |備考                                                                                       |
 * |:----------------|:-----------------------------------------------------------------------------------------|
 * | DEBUG = ON      | Enabled                                                                                  |
 * | DEBUG = OFF     | Disabled                                                                                 |
 *
 * @section CP0 Code Protection Block 0:
 * 
 * |設定              |備考                                                                                       |
 * |:----------------|:-----------------------------------------------------------------------------------------|
 * | CP0 = ON        | Block 0 (000800-003FFFh) code-protected                                                  |
 * | CP0 = OFF       | Block 0 (000800-003FFFh) not code-protected                                              |
 *
 * @section CP1 Code Protection Block 1:
 * 
 * |設定              |備考                                                                                       |
 * |:----------------|:-----------------------------------------------------------------------------------------|
 * | CP1 = ON        | Block 1 (004000-007FFFh) code-protected                                                  |
 * | CP1 = OFF       | Block 1 (004000-007FFFh) not code-protected                                              |
 *
 * @section CP2 Code Protection Block 2:
 * 
 * |設定              |備考                                                                                       |
 * |:----------------|:-----------------------------------------------------------------------------------------|
 * | CP2 = ON        | Block 2 (008000-00BFFFh) code-protected                                                  |
 * | CP2 = OFF       | Block 2 (008000-00BFFFh) not code-protected                                              |
 *
 * @section CP3 Code Protection Block 3:
 * 
 * |設定              |備考                                                                                       |
 * |:----------------|:-----------------------------------------------------------------------------------------|
 * | CP3 = ON        | Block 3 (00C000-00FFFFh) code-protected                                                  |
 * | CP3 = OFF       | Block 3 (00C000-00FFFFh) not code-protected                                              |
 *
 * @section CPB Boot Block Code Protection bit:
 * 
 * |設定              |備考                                                                                       |
 * |:----------------|:-----------------------------------------------------------------------------------------|
 * | CPB = ON        | Boot block (000000-0007FFh) code-protected                                               |
 * | CPB = OFF       | Boot block (000000-0007FFh) not code-protected                                           |
 *
 * @section CPD Data EEPROM Code Protection bit:
 * 
 * |設定              |備考                                                                                       |
 * |:----------------|:-----------------------------------------------------------------------------------------|
 * | CPD = ON        | Data EEPROM code-protected                                                               |
 * | CPD = OFF       | Data EEPROM not code-protected                                                           |
 *
 * @section WRT0 Write Protection Block 0:
 * 
 * |設定              |備考                                                                                       |
 * |:----------------|:-----------------------------------------------------------------------------------------|
 * | WRT0 = ON       | Block 0 (000800-003FFFh) write-protected                                                 |
 * | WRT0 = OFF      | Block 0 (000800-003FFFh) not write-protected                                             |
 *
 * @section WRT1 Write Protection Block 1:
 * 
 * |設定              |備考                                                                                       |
 * |:----------------|:-----------------------------------------------------------------------------------------|
 * | WRT1 = ON       | Block 1 (004000-007FFFh) write-protected                                                 |
 * | WRT1 = OFF      | Block 1 (004000-007FFFh) not write-protected                                             |
 *
 * @section WRT2 Write Protection Block 2:
 * 
 * |設定              |備考                                                                                       |
 * |:----------------|:-----------------------------------------------------------------------------------------|
 * | WRT2 = ON       | Block 2 (008000-00BFFFh) write-protected                                                 |
 * | WRT2 = OFF      | Block 2 (008000-00BFFFh) not write-protected                                             |
 *
 * @section WRT3 Write Protection Block 3:
 * 
 * |設定              |備考                                                                                       |
 * |:----------------|:-----------------------------------------------------------------------------------------|
 * | WRT3 = ON       | Block 3 (00C000-00FFFFh) write-protected                                                 |
 * | WRT3 = OFF      | Block 3 (00C000-00FFFFh) not write-protected                                             |
 * |                 |                                                                                          |
 *
 * @section WRTC Configuration Register Write Protection bit:
 * 
 * |設定              |備考                                                                                       |
 * |:----------------|:-----------------------------------------------------------------------------------------|
 * | WRTC = OFF      | Configuration registers (300000-3000FFh) not write-protected                             |
 *
 * @section WRTB Boot Block Write Protection bit:
 * 
 * |設定              |備考                                                                                       |
 * |:----------------|:-----------------------------------------------------------------------------------------|
 * | WRTB = ON       | Boot Block (000000-0007FFh) write-protected                                              |
 * | WRTB = OFF      | Boot Block (000000-0007FFh) not write-protected                                          |
 *
 * @section WRTD Data EEPROM Write Protection bit:
 * 
 * |設定              |備考                                                                                       |
 * |:----------------|:-----------------------------------------------------------------------------------------|
 * | WRTD = ON       | Data EEPROM write-protected                                                              |
 * | WRTD = OFF      | Data EEPROM not write-protected                                                          |
 *
 * @section EBTR0 Table Read Protection Block 0:
 * 
 * |設定              |備考                                                                                       |
 * |:----------------|:-----------------------------------------------------------------------------------------|
 * | EBTR0 = ON      | Block 0 (000800-003FFFh) protected from table reads executed in other blocks             |
 * | EBTR0 = OFF     | Block 0 (000800-003FFFh) not protected from table reads executed in other blocks         |
 *
 *  @section EBTR1 Table Read Protection Block 1:
 * 
 * |設定              |備考                                                                                       |
 * |:----------------|:-----------------------------------------------------------------------------------------|
 * | EBTR1 = ON      | Block 1 (004000-007FFFh) protected from table reads executed in other blocks             |
 * | EBTR1 = OFF     | Block 1 (004000-007FFFh) not protected from table reads executed in other blocks         |
 *
 *  @section EBTR2 Table Read Protection Block 2:
 * 
 * |設定              |備考                                                                                       |
 * |:----------------|:-----------------------------------------------------------------------------------------|
 * | EBTR2 = ON      | Block 2 (008000-00BFFFh) protected from table reads executed in other blocks             |
 * | EBTR2 = OFF     | Block 2 (008000-00BFFFh) not protected from table reads executed in other blocks         |
 *
 *  @section EBTR3 Table Read Protection Block 3:
 * 
 * |設定              |備考                                                                                       |
 * |:----------------|:-----------------------------------------------------------------------------------------|
 * | EBTR3 = ON      | Block 3 (00C000-00FFFFh) protected from table reads executed in other blocks             |
 * | EBTR3 = OFF     | Block 3 (00C000-00FFFFh) not protected from table reads executed in other blocks         |
 *
 * @section EBTRB Boot Block Table Read Protection bit:
 * 
 * |設定              |備考                                                                                       |
 * |:----------------|:-----------------------------------------------------------------------------------------|
 * | EBTRB = ON      | Boot Block (000000-0007FFh) protected from table reads executed in other blocks          |
 * | EBTRB = OFF     | Boot Block (000000-0007FFh) not protected from table reads executed in other blocks      |
 * 
 * 
 */