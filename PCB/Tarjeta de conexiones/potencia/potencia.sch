EESchema Schematic File Version 4
LIBS:potencia-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Connector:Screw_Terminal_01x06 J2
U 1 1 5D5C4727
P 3650 2350
F 0 "J2" V 3522 2630 50  0000 L CNN
F 1 "+12 Voltios" V 3613 2630 50  0000 L CNN
F 2 "TerminalBlock_Altech:Altech_AK300_1x06_P5.00mm_45-Degree" H 3650 2350 50  0001 C CNN
F 3 "~" H 3650 2350 50  0001 C CNN
	1    3650 2350
	0    1    1    0   
$EndComp
$Comp
L Connector:Screw_Terminal_01x02 J4
U 1 1 5D5C5B19
P 3200 3650
F 0 "J4" H 3118 3325 50  0000 C CNN
F 1 "Entrada 12 Voltios" H 3150 3900 50  0000 C CNN
F 2 "TerminalBlock_Altech:Altech_AK300_1x02_P5.00mm_45-Degree" H 3200 3650 50  0001 C CNN
F 3 "~" H 3200 3650 50  0001 C CNN
	1    3200 3650
	-1   0    0    1   
$EndComp
$Comp
L Connector:Screw_Terminal_01x02 J9
U 1 1 5D5C639C
P 6200 3600
F 0 "J9" H 6280 3592 50  0000 L CNN
F 1 "Alimentación Reles 5v" H 6280 3501 50  0000 L CNN
F 2 "TerminalBlock_Altech:Altech_AK300_1x02_P5.00mm_45-Degree" H 6200 3600 50  0001 C CNN
F 3 "~" H 6200 3600 50  0001 C CNN
	1    6200 3600
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female J5
U 1 1 5D5C8209
P 4150 3400
F 0 "J5" H 4178 3426 50  0000 L CNN
F 1 "Vin +" H 4178 3335 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x01_P2.54mm_Vertical" H 4150 3400 50  0001 C CNN
F 3 "~" H 4150 3400 50  0001 C CNN
	1    4150 3400
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female J6
U 1 1 5D5C8737
P 4150 3800
F 0 "J6" H 4178 3826 50  0000 L CNN
F 1 "Vin -" H 4178 3735 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x01_P2.54mm_Vertical" H 4150 3800 50  0001 C CNN
F 3 "~" H 4150 3800 50  0001 C CNN
	1    4150 3800
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female J7
U 1 1 5D5C8BDB
P 5350 3450
F 0 "J7" H 5242 3225 50  0000 C CNN
F 1 "Vout -" H 5242 3316 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x01_P2.54mm_Vertical" H 5350 3450 50  0001 C CNN
F 3 "~" H 5350 3450 50  0001 C CNN
	1    5350 3450
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x01_Female J8
U 1 1 5D5C90E7
P 5350 3850
F 0 "J8" H 5242 3625 50  0000 C CNN
F 1 "Vout +" H 5242 3716 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x01_P2.54mm_Vertical" H 5350 3850 50  0001 C CNN
F 3 "~" H 5350 3850 50  0001 C CNN
	1    5350 3850
	-1   0    0    1   
$EndComp
$Comp
L Connector:Screw_Terminal_01x02 J1
U 1 1 5D5C9675
P 4250 1500
F 0 "J1" V 4214 1312 50  0000 R CNN
F 1 "Entrada 12 Voltios" V 4123 1312 50  0000 R CNN
F 2 "TerminalBlock_Altech:Altech_AK300_1x02_P5.00mm_45-Degree" H 4250 1500 50  0001 C CNN
F 3 "~" H 4250 1500 50  0001 C CNN
	1    4250 1500
	0    -1   -1   0   
$EndComp
$Comp
L Connector:Screw_Terminal_01x06 J3
U 1 1 5D5C9F72
P 5150 2350
F 0 "J3" V 5022 2630 50  0000 L CNN
F 1 "GND Tierra de los 12 Voltios" V 5113 2630 50  0000 L CNN
F 2 "TerminalBlock_Altech:Altech_AK300_1x06_P5.00mm_45-Degree" H 5150 2350 50  0001 C CNN
F 3 "~" H 5150 2350 50  0001 C CNN
	1    5150 2350
	0    1    1    0   
$EndComp
Wire Wire Line
	6200 3600 6000 3600
Wire Wire Line
	6000 3600 6000 3450
Wire Wire Line
	6000 3450 5550 3450
Connection ~ 6000 3600
Wire Wire Line
	5550 3850 6000 3850
Wire Wire Line
	6000 3850 6000 3700
Wire Wire Line
	3950 3400 3400 3400
Wire Wire Line
	3400 3400 3400 3550
Wire Wire Line
	3400 3650 3400 3800
Wire Wire Line
	3400 3800 3950 3800
Wire Wire Line
	4250 1700 3350 1700
Wire Wire Line
	3350 1700 3350 2100
Wire Wire Line
	3450 2150 3450 2100
Wire Wire Line
	3450 2100 3350 2100
Connection ~ 3350 2100
Wire Wire Line
	3350 2100 3350 2150
Wire Wire Line
	3550 2150 3550 2100
Wire Wire Line
	3550 2100 3450 2100
Connection ~ 3450 2100
Wire Wire Line
	3650 2150 3650 2100
Wire Wire Line
	3650 2100 3550 2100
Connection ~ 3550 2100
Wire Wire Line
	3750 2150 3750 2100
Wire Wire Line
	3750 2100 3650 2100
Connection ~ 3650 2100
Wire Wire Line
	3850 2150 3850 2100
Wire Wire Line
	3850 2100 3750 2100
Connection ~ 3750 2100
Wire Wire Line
	4350 1700 5350 1700
Wire Wire Line
	5350 1700 5350 2100
Wire Wire Line
	5250 2150 5250 2100
Wire Wire Line
	5250 2100 5350 2100
Connection ~ 5350 2100
Wire Wire Line
	5350 2100 5350 2150
Wire Wire Line
	5150 2150 5150 2100
Wire Wire Line
	5150 2100 5250 2100
Connection ~ 5250 2100
Wire Wire Line
	5050 2150 5050 2100
Wire Wire Line
	5050 2100 5150 2100
Connection ~ 5150 2100
Wire Wire Line
	4950 2150 4950 2100
Wire Wire Line
	4950 2100 5050 2100
Connection ~ 5050 2100
Wire Wire Line
	4850 2150 4850 2100
Wire Wire Line
	4850 2100 4950 2100
Connection ~ 4950 2100
$Comp
L Connector:Screw_Terminal_01x02 J10
U 1 1 5D5DE03F
P 7600 3600
F 0 "J10" H 7680 3592 50  0000 L CNN
F 1 "Alimentación Arduino 5v" H 7680 3501 50  0000 L CNN
F 2 "TerminalBlock_Altech:Altech_AK300_1x02_P5.00mm_45-Degree" H 7600 3600 50  0001 C CNN
F 3 "~" H 7600 3600 50  0001 C CNN
	1    7600 3600
	1    0    0    -1  
$EndComp
Wire Wire Line
	7400 3600 7400 3450
Wire Wire Line
	7400 3450 6000 3450
Connection ~ 6000 3450
Wire Wire Line
	7400 3700 7400 3850
Wire Wire Line
	7400 3850 6000 3850
Connection ~ 6000 3850
Wire Notes Line
	8550 1400 8550 4200
Wire Notes Line
	2750 4200 2750 1400
Wire Notes Line
	2750 1400 8550 1400
Wire Notes Line
	2750 4200 8550 4200
$EndSCHEMATC
