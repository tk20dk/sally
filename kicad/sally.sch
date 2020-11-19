EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Sally"
Date "2018-09-22"
Rev "v1.0"
Comp "www.2-0.dk"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L power:GND #PWR02
U 1 1 5B702452
P 4150 5000
F 0 "#PWR02" H 4150 4750 50  0001 C CNN
F 1 "GND" H 4155 4827 50  0000 C CNN
F 2 "" H 4150 5000 50  0001 C CNN
F 3 "" H 4150 5000 50  0001 C CNN
	1    4150 5000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR08
U 1 1 5B702DAE
P 8750 4050
F 0 "#PWR08" H 8750 3800 50  0001 C CNN
F 1 "GND" V 8755 3922 50  0000 R CNN
F 2 "" H 8750 4050 50  0001 C CNN
F 3 "" H 8750 4050 50  0001 C CNN
	1    8750 4050
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR010
U 1 1 5B702E8B
P 8750 5150
F 0 "#PWR010" H 8750 4900 50  0001 C CNN
F 1 "GND" V 8755 5022 50  0000 R CNN
F 2 "" H 8750 5150 50  0001 C CNN
F 3 "" H 8750 5150 50  0001 C CNN
	1    8750 5150
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR05
U 1 1 5B702F61
P 4800 3700
F 0 "#PWR05" H 4800 3450 50  0001 C CNN
F 1 "GND" H 4805 3527 50  0000 C CNN
F 2 "" H 4800 3700 50  0001 C CNN
F 3 "" H 4800 3700 50  0001 C CNN
	1    4800 3700
	1    0    0    -1  
$EndComp
$Comp
L Device:C C2
U 1 1 5B705323
P 5250 4850
F 0 "C2" H 5365 4896 50  0000 L CNN
F 1 "100n" H 5365 4805 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 5288 4700 50  0001 C CNN
F 3 "~" H 5250 4850 50  0001 C CNN
	1    5250 4850
	1    0    0    -1  
$EndComp
$Comp
L Device:C C3
U 1 1 5B705365
P 5650 4850
F 0 "C3" H 5765 4896 50  0000 L CNN
F 1 "100n" H 5765 4805 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 5688 4700 50  0001 C CNN
F 3 "~" H 5650 4850 50  0001 C CNN
	1    5650 4850
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C1
U 1 1 5B705491
P 4850 4850
F 0 "C1" H 4968 4896 50  0000 L CNN
F 1 "470u" H 4968 4805 50  0000 L CNN
F 2 "Capacitor_Tantalum_SMD:CP_EIA-7343-15_Kemet-W" H 4888 4700 50  0001 C CNN
F 3 "~" H 4850 4850 50  0001 C CNN
	1    4850 4850
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR07
U 1 1 5B7055DE
P 5250 5000
F 0 "#PWR07" H 5250 4750 50  0001 C CNN
F 1 "GND" H 5255 4827 50  0000 C CNN
F 2 "" H 5250 5000 50  0001 C CNN
F 3 "" H 5250 5000 50  0001 C CNN
	1    5250 5000
	1    0    0    -1  
$EndComp
Wire Wire Line
	4850 4700 5250 4700
Connection ~ 5250 4700
Wire Wire Line
	5250 4700 5650 4700
Wire Wire Line
	4850 5000 5250 5000
Connection ~ 5250 5000
Wire Wire Line
	5250 5000 5650 5000
Text GLabel 8750 5050 2    50   Input ~ 0
sdn_radio
Text GLabel 8750 4950 2    50   Output ~ 0
nirq_radio
Text GLabel 8750 4850 2    50   Input ~ 0
nsel_radio
Text GLabel 8750 4750 2    50   Input ~ 0
spi_sck
Text GLabel 8750 4650 2    50   Input ~ 0
spi_mosi
Text GLabel 8750 4550 2    50   3State ~ 0
spi_miso
Text GLabel 8750 4150 2    50   BiDi ~ 0
gpio0_radio
Text GLabel 8750 4250 2    50   BiDi ~ 0
gpio1_radio
Text GLabel 8750 4350 2    50   BiDi ~ 0
gpio2_radio
Text GLabel 5400 2300 2    50   BiDi ~ 0
i2c_scl
Text GLabel 5400 2200 2    50   BiDi ~ 0
i2c_sda
Text GLabel 4200 3400 0    50   Input ~ 0
spi_miso
Text GLabel 4200 3300 0    50   Output ~ 0
spi_mosi
Text GLabel 4200 3200 0    50   Output ~ 0
spi_sck
Text GLabel 4200 3100 0    50   Output ~ 0
nsel_radio
Text GLabel 4200 2400 0    50   Output ~ 0
pa2
Text GLabel 4200 2500 0    50   Output ~ 0
pb4
Text GLabel 5400 2400 2    50   Output ~ 0
pc4
Text GLabel 5400 2800 2    50   Input ~ 0
nirq_radio
Text GLabel 4200 2700 0    50   Output ~ 0
sdn_radio
Text GLabel 4200 2200 0    50   BiDi ~ 0
swim
Text GLabel 4200 2300 0    50   BiDi ~ 0
nrst
Text GLabel 5400 2500 2    50   Output ~ 0
uart_tx
Text GLabel 5400 2600 2    50   Input ~ 0
uart_rx
Text GLabel 4200 3000 0    50   BiDi ~ 0
gpio0_radio
Text GLabel 4200 2900 0    50   BiDi ~ 0
gpio1_radio
Text GLabel 4200 2800 0    50   BiDi ~ 0
gpio2_radio
$Comp
L Mechanical:MountingHole MH1
U 1 1 5B707653
P 3050 4500
F 0 "MH1" H 3150 4546 50  0000 L CNN
F 1 "MountingHole" H 3150 4455 50  0000 L CNN
F 2 "MountingHole:MountingHole_2.5mm" H 3050 4500 50  0001 C CNN
F 3 "~" H 3050 4500 50  0001 C CNN
	1    3050 4500
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole MH2
U 1 1 5B707729
P 3050 4700
F 0 "MH2" H 3150 4746 50  0000 L CNN
F 1 "MountingHole" H 3150 4655 50  0000 L CNN
F 2 "MountingHole:MountingHole_2.5mm" H 3050 4700 50  0001 C CNN
F 3 "~" H 3050 4700 50  0001 C CNN
	1    3050 4700
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole MH3
U 1 1 5B707765
P 3050 4900
F 0 "MH3" H 3150 4946 50  0000 L CNN
F 1 "MountingHole" H 3150 4855 50  0000 L CNN
F 2 "MountingHole:MountingHole_2.5mm" H 3050 4900 50  0001 C CNN
F 3 "~" H 3050 4900 50  0001 C CNN
	1    3050 4900
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole MH4
U 1 1 5B7077A3
P 3050 5100
F 0 "MH4" H 3150 5146 50  0000 L CNN
F 1 "MountingHole" H 3150 5055 50  0000 L CNN
F 2 "MountingHole:MountingHole_2.5mm" H 3050 5100 50  0001 C CNN
F 3 "~" H 3050 5100 50  0001 C CNN
	1    3050 5100
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR03
U 1 1 5B702E06
P 7750 5050
F 0 "#PWR03" H 7750 4800 50  0001 C CNN
F 1 "GND" V 7755 4922 50  0000 R CNN
F 2 "" H 7750 5050 50  0001 C CNN
F 3 "" H 7750 5050 50  0001 C CNN
	1    7750 5050
	0    1    1    0   
$EndComp
Wire Wire Line
	7750 5150 7300 5150
$Comp
L Connector_Generic:Conn_01x01 J1
U 1 1 5B70DCBD
P 7100 5150
F 0 "J1" H 7020 4925 50  0000 C CNN
F 1 "Antenna" H 7020 5016 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x01_P2.54mm_Vertical" H 7100 5150 50  0001 C CNN
F 3 "~" H 7100 5150 50  0001 C CNN
	1    7100 5150
	-1   0    0    1   
$EndComp
$Comp
L Device:C C4
U 1 1 5B7DAE7A
P 6100 4850
F 0 "C4" H 6215 4896 50  0000 L CNN
F 1 "100n" H 6215 4805 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 6138 4700 50  0001 C CNN
F 3 "~" H 6100 4850 50  0001 C CNN
	1    6100 4850
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR021
U 1 1 5B7DAF57
P 6100 4700
F 0 "#PWR021" H 6100 4450 50  0001 C CNN
F 1 "GND" H 6105 4527 50  0000 C CNN
F 2 "" H 6100 4700 50  0001 C CNN
F 3 "" H 6100 4700 50  0001 C CNN
	1    6100 4700
	-1   0    0    1   
$EndComp
Text GLabel 6100 5000 3    50   Output ~ 0
nrst
$Comp
L power:VCC #PWR0101
U 1 1 5B8AA4EC
P 4150 4700
F 0 "#PWR0101" H 4150 4550 50  0001 C CNN
F 1 "VCC" H 4167 4873 50  0000 C CNN
F 2 "" H 4150 4700 50  0001 C CNN
F 3 "" H 4150 4700 50  0001 C CNN
	1    4150 4700
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0102
U 1 1 5B8AA557
P 5250 4700
F 0 "#PWR0102" H 5250 4550 50  0001 C CNN
F 1 "VCC" H 5267 4873 50  0000 C CNN
F 2 "" H 5250 4700 50  0001 C CNN
F 3 "" H 5250 4700 50  0001 C CNN
	1    5250 4700
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0103
U 1 1 5B8AA685
P 8750 4450
F 0 "#PWR0103" H 8750 4300 50  0001 C CNN
F 1 "VCC" V 8767 4578 50  0000 L CNN
F 2 "" H 8750 4450 50  0001 C CNN
F 3 "" H 8750 4450 50  0001 C CNN
	1    8750 4450
	0    1    1    0   
$EndComp
$Comp
L power:VCC #PWR0104
U 1 1 5B8AA778
P 4800 1900
F 0 "#PWR0104" H 4800 1750 50  0001 C CNN
F 1 "VCC" H 4817 2073 50  0000 C CNN
F 2 "" H 4800 1900 50  0001 C CNN
F 3 "" H 4800 1900 50  0001 C CNN
	1    4800 1900
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0105
U 1 1 5B8AA86B
P 8750 2450
F 0 "#PWR0105" H 8750 2300 50  0001 C CNN
F 1 "VCC" V 8750 2600 50  0000 L CNN
F 2 "" H 8750 2450 50  0001 C CNN
F 3 "" H 8750 2450 50  0001 C CNN
	1    8750 2450
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0106
U 1 1 5B8AA9C5
P 7750 2350
F 0 "#PWR0106" H 7750 2100 50  0001 C CNN
F 1 "GND" V 7750 2150 50  0000 C CNN
F 2 "" H 7750 2350 50  0001 C CNN
F 3 "" H 7750 2350 50  0001 C CNN
	1    7750 2350
	0    1    1    0   
$EndComp
Text GLabel 7750 3150 0    50   BiDi ~ 0
swim
Text GLabel 8750 3150 2    50   BiDi ~ 0
nrst
Text GLabel 7750 2850 0    50   BiDi ~ 0
pa2
Text GLabel 7750 2750 0    50   BiDi ~ 0
pb4
Text GLabel 8750 2750 2    50   BiDi ~ 0
gpio2_radio
Text GLabel 8750 2550 2    50   BiDi ~ 0
gpio0_radio
Text GLabel 8750 3050 2    50   Input ~ 0
spi_sck
Text GLabel 8750 2950 2    50   Input ~ 0
spi_mosi
Text GLabel 8750 2850 2    50   Output ~ 0
spi_miso
Text GLabel 8750 2650 2    50   BiDi ~ 0
gpio1_radio
Text GLabel 7750 3050 0    50   Output ~ 0
uart_rx
Text GLabel 7750 2950 0    50   Input ~ 0
uart_tx
Text GLabel 7750 2450 0    50   BiDi ~ 0
pc4
Text GLabel 7750 2550 0    50   BiDi ~ 0
i2c_scl
Text GLabel 7750 2650 0    50   BiDi ~ 0
i2c_sda
$Comp
L Device:R R1
U 1 1 5BF05F8C
P 6500 4850
F 0 "R1" H 6570 4896 50  0000 L CNN
F 1 "4k7" H 6570 4805 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 6430 4850 50  0001 C CNN
F 3 "~" H 6500 4850 50  0001 C CNN
	1    6500 4850
	1    0    0    -1  
$EndComp
$Comp
L Device:R R2
U 1 1 5BF06006
P 6750 4850
F 0 "R2" H 6820 4896 50  0000 L CNN
F 1 "4k7" H 6820 4805 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 6680 4850 50  0001 C CNN
F 3 "~" H 6750 4850 50  0001 C CNN
	1    6750 4850
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0107
U 1 1 5BF0603E
P 6500 4700
F 0 "#PWR0107" H 6500 4550 50  0001 C CNN
F 1 "VCC" H 6517 4873 50  0000 C CNN
F 2 "" H 6500 4700 50  0001 C CNN
F 3 "" H 6500 4700 50  0001 C CNN
	1    6500 4700
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0108
U 1 1 5BF06067
P 6750 4700
F 0 "#PWR0108" H 6750 4550 50  0001 C CNN
F 1 "VCC" H 6767 4873 50  0000 C CNN
F 2 "" H 6750 4700 50  0001 C CNN
F 3 "" H 6750 4700 50  0001 C CNN
	1    6750 4700
	1    0    0    -1  
$EndComp
Text GLabel 6500 5000 3    50   BiDi ~ 0
i2c_scl
Text GLabel 6750 5000 3    50   BiDi ~ 0
i2c_sda
$Comp
L sally:STM8L051F3P U1
U 1 1 5FAA7FF5
P 4800 2800
F 0 "U1" H 5000 3700 50  0000 C CNN
F 1 "STM8L051F3P" H 5150 3600 50  0000 C CNN
F 2 "Package_SO:TSSOP-20_4.4x6.5mm_P0.65mm" H 4850 3800 50  0001 L CNN
F 3 "" H 4800 2400 50  0001 C CNN
	1    4800 2800
	1    0    0    -1  
$EndComp
$Comp
L sally:Battery_Cell BT1
U 1 1 5FAAB650
P 4150 4900
F 0 "BT1" H 4268 4996 50  0000 L CNN
F 1 "CR2450" H 4268 4905 50  0000 L CNN
F 2 "sally:CR2450H" V 4150 4960 50  0001 C CNN
F 3 "" V 4150 4960 50  0001 C CNN
	1    4150 4900
	1    0    0    -1  
$EndComp
$Comp
L sally:PROTO_SALLY U2
U 1 1 5FAB0623
P 8250 2800
F 0 "U2" H 8250 3475 50  0000 C CNN
F 1 "PROTO_SALLY" H 8250 3384 50  0000 C CNN
F 2 "sally:PROTO_SALLY" H 8250 2800 50  0001 C CNN
F 3 "" H 8250 2800 50  0001 C CNN
	1    8250 2800
	1    0    0    -1  
$EndComp
$Comp
L sally:XL4432-SMD M1
U 1 1 5FAB359E
P 8250 4600
F 0 "M1" H 8250 5397 60  0000 C CNN
F 1 "XL4432-SMD" H 8250 5291 60  0000 C CNN
F 2 "sally:RF4462PRO" H 8700 4600 60  0001 C CNN
F 3 "" H 8700 4600 60  0000 C CNN
	1    8250 4600
	1    0    0    -1  
$EndComp
$EndSCHEMATC
