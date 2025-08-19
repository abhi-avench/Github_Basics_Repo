# Dual RCU PDO Documentation

## Screen 1-9 PDO

## EVENT DRIVEN DATA

| S.No | Subsystem ID | Icon No | Icons                    | Payload                              | Description                                                                                                                     |
| ---- | ------------ | ------- | ------------------------ | ------------------------------------ | ------------------------------------------------------------------------------------------------------------------------------- |
| 1.   | R1           | 14      | Overload Winch R1        | `cansend vcan0 1C1#0000010000000000` | PDO: 0x1C1 (Winch R1 Status) Byte 3, Bit 16 (0x01 in Byte 3) Icon :- Activate when Byte3.Bit16=1, Deactivate when Byte3.Bit16=0 |
| 2.   | R2           | 14      | Overload Winch R2        | `cansend vcan0 1C2#0000010000000000` | PDO: 0x1C2 (Winch R2 Status) Byte 3, Bit 16 (0x01 in Byte 3) Icon :- Activate when Byte3.Bit16=1, Deactivate when Byte3.Bit16=0 |
| 3.   | SYS1         | 18      | System Error             | `cansend vcan0 181#1000000000000000` | PDO: 0x181 (System Status) Byte 1, Bit 04 (0x10 in Byte 1) Icon :- Activate when Byte1.Bit04=1, Deactivate when Byte1.Bit04=0   |
| 4.   | R1           | 16      | Rope End Winch R1        | `cansend vcan0 1C1#0000020000000000` | PDO: 0x1C1 (Winch R1 Status) Byte 3, Bit 17 (0x02 in Byte 3) Icon :- Activate when Byte3.Bit17=1, Deactivate when Byte3.Bit17=0 |
| 5.   | R2           | 16      | Rope End Winch R2        | `cansend vcan0 1C2#0000020000000000` | PDO: 0x1C2 (Winch R2 Status) Byte 3, Bit 17 (0x02 in Byte 3) Icon :- Activate when Byte3.Bit17=1, Deactivate when Byte3.Bit17=0 |
| 6.   | SYS1         | 30      | 15 t Mode                | `cansend vcan0 181#0000010000000000` | PDO: 0x181 (System Status) Byte 3, Bit 16 (0x01 in Byte 3) Icon :- Activate when Byte3.Bit16=1, Deactivate when Byte3.Bit16=0   |
| 7.   | SYS1         | 31      | E-Stop                   | `cansend vcan0 181#0800000000000000` | PDO: 0x181 (System Status) Byte 1, Bit 03 (0x08 in Byte 1) Icon :- Activate when Byte1.Bit03=1, Deactivate when Byte1.Bit03=0   |
| 8.   | R1           | 24      | Rope Thimble Winch R1    | `cansend vcan0 1C1#0080000000000000` | PDO: 0x1C1 (Winch R1 Status) Byte 2, Bit 15 (0x80 in Byte 2) Icon :- Activate when Byte2.Bit15=1, Deactivate when Byte2.Bit15=0 |
| 9.   | R2           | 24      | Rope Thimble Winch R2    | `cansend vcan0 1C2#0080000000000000` | PDO: 0x1C2 (Winch R2 Status) Byte 2, Bit 15 (0x80 in Byte 2) Icon :- Activate when Byte2.Bit15=1, Deactivate when Byte2.Bit15=0 |
| 10.  | SYS1         | 189     | Emergency Operation Mode | -                                    | -                                                                                                                               |
| 11.  | H1           | 188     | Cooler Fan Reversal On   | -                                    | -                                                                                                                               |
| 12.  | H1           | 187     | Manual Cooling On        | -                                    | -                                                                                                                               |
| 13.  | H1           | 186     | Manual Heating On        | -                                    | -                                                                                                                               |

## FUNCTION BUTTON SELECT SET

- None.

## JOYSTICK ASSIGNMENT

| S.No | Subsystem ID | Icon No | Joystick                   | Payload | Description                          |
| ---- | ------------ | ------- | -------------------------- | ------- | ------------------------------------ |
| 1.   | R1           | 25      | Main Winch Operation Right | -       | Static icon. Not coming through CAN. |
| 2.   | R2           | 25      | Main Winch Operation Left  | -       | Static icon. Not coming through CAN. |
| 3.   | E1           | 47      | Earth Anchor Retract       | -       | Static icon. Not coming through CAN. |
| 4.   | E1           | 46      | Earth Anchor Extend        | -       | Static icon. Not coming through CAN. |

## MAIN SCREEN INFORMATION

| S.No | Subsystem ID | Widget No | Widget Name                               | Payload                              | Description                                            |
| ---- | ------------ | --------- | ----------------------------------------- | ------------------------------------ | ------------------------------------------------------ |
| 1.   | R2           | WD:59     | `_winch_type_no_gear_stat_std_L_00`       | `cansend vcan0 1C2#0000XX0000000000` | See Table 1: Gear Status for R2.                       |
| 2.   | R1           | WD:60     | `_winch_type_no_gear_stat_std_R_00`       | `cansend vcan0 1C1#0000XX0000000000` | See Table 2: Gear Status for R1                        |
| 3.   | R2           | WD:61     | `_3_45_load_unit_graphic_L_std_00`        | `cansend vcan0 1C2#0000000000XXXXXX` | See Table 3: for load bar% and force value for R2.     |
| 4.   | R1           | WD:62     | `_3_45_load_unit_graphic_R_std_00`        | `cansend vcan0 1C1#0000000000XXXXXX` | See Table 4: for load bar% and force value for R1      |
| 5.   | R1           | WD:63     | `_3_45_rope_length_unit_graphic_R_std_00` | `cansend vcan0 1C1#0000XXXXXX000000` | See Table 5: for load bar% and Rope length value of R1 |
| 6.   | R2           | WD:64     | `_3_45_rope_length_unit_graphic_L_std_00` | `cansend vcan0 1C2#0000XXXXXX000000` | See Table 5: for load bar% and Rope length value of R2 |

---

# Table 1: Gear Status for R2

| Condition | Icon               | Example Payload                      |
| --------- | ------------------ | ------------------------------------ |
| `XX=00`   | 0002 (Turtle)      | `cansend vcan0 1C2#0000000000000000` |
| `XX=04`   | 0027 (Hare)        | `cansend vcan0 1C2#0000040000000000` |
| `XX=08`   | 0003 (Turtle-Auto) | `cansend vcan0 1C2#0000080000000000` |
| `XX=0C`   | 0001 (Hare-Auto)   | `cansend vcan0 1C2#00000C0000000000` |

---

# Table 2: Gear Status for R1

| Condition | Icon               | Example Payload                      |
| --------- | ------------------ | ------------------------------------ |
| `XX=00`   | 0002 (Turtle)      | `cansend vcan0 1C1#0000000000000000` |
| `XX=04`   | 0027 (Hare)        | `cansend vcan0 1C1#0000040000000000` |
| `XX=08`   | 0003 (Turtle-Auto) | `cansend vcan0 1C1#0000080000000000` |
| `XX=0C`   | 0001 (Hare-Auto)   | `cansend vcan0 1C1#00000C0000000000` |

---

# Tables 3: Load bar and force value for Winch R2.

### WD:61 - `_3_45_load_unit_graphic_L_std_00` (Winch R2)

#### Force Calculation (kN, if Bit 60 → 1)

| CAN payload                          | Actual % | Max Force | Calculation       | Result (kN) |
| :----------------------------------- | :------- | :-------- | :---------------- | :---------- |
| `cansend vcan0 1C2#0000000000FFFF13` | 127.5    | 1023      | (127.5/100)\*1023 | 1304        |
| `cansend vcan0 1C2#0000000000FF0110` | 127.5    | 1         | (127.5/100)\*1    | 1           |
| `cansend vcan0 1C2#000000000001FF13` | 0.5      | 1023      | (0.5/100)\*1023   | 5           |
| `cansend vcan0 1C2#0000000000FEFE13` | 127      | 1022      | (127/100)\*1022   | 1297        |
| `cansend vcan0 1C2#0000000000FF0011` | 127.5    | 256       | (127.5/100)\*256  | 326         |

---

#### Force Calculation (Tonne, if Bit 60 → 0)

| CAN payload                          | Actual % | Max Force | Calculation          | Result (Tonne) |
| :----------------------------------- | :------- | :-------- | :------------------- | :------------- |
| `cansend vcan0 1C2#0000000000FFFF03` | 127.5    | 1023      | 1304.325×0.101971621 | 133.0          |
| `cansend vcan0 1C2#0000000000FF0100` | 127.5    | 1         | 1.275×0.101971621    | 0.1            |
| `cansend vcan0 1C2#000000000001FF03` | 0.5      | 1023      | 5.115×0.101971621    | 0.5            |
| `cansend vcan0 1C2#0000000000FEFE03` | 127      | 1022      | 1297.94×0.101971621  | 132.3          |
| `cansend vcan0 1C2#0000000000FF0001` | 127.5    | 256       | 326.4×0.101971621    | 33.2           |

---

#### Load Bar Percentage which is manipulated by BYTE 6.

| Payload                              | Byte 6 | Calculation | Result              |
| :----------------------------------- | :----- | :---------- | :------------------ |
| `cansend vcan0 1C2#0000000000000000` | 0x00   | 0×0.5       | 0.0%                |
| `cansend vcan0 1C1#0000000000640000` | 0x64   | 100\*0.5    | 50%                 |
| `cansend vcan0 1C2#00000000007F0000` | 0x7F   | 127×0.5     | 63.5%               |
| `cansend vcan0 1C2#0000000000FF0000` | 0xFF   | 255×0.5     | 127->100% (clamped) |
| `cansend vcan0 1C2#0000000000C80000` | 0xC8   | 200×0.5     | 100% (clamped)      |
| `cansend vcan0 1C2#0000000000C60000` | 0xC6   | 198×0.5     | 99.0%               |

---

# Table 4: Load bar and force value for winch R1

### WD:62 - `_3_45_load_unit_graphic_R_std_00` (Winch R1)

#### Force Calculation (kN, if Bit 60 → 1)

| CAN payload                          | Actual % | Max Force | Calculation       | Result (kN) |
| :----------------------------------- | :------- | :-------- | :---------------- | :---------- |
| `cansend vcan0 1C1#0000000000FFFF13` | 127.5    | 1023      | (127.5/100)\*1023 | 1304        |
| `cansend vcan0 1C1#0000000000FF0110` | 127.5    | 1         | (127.5/100)\*1    | 1           |
| `cansend vcan0 1C1#000000000001FF13` | 0.5      | 1023      | (0.5/100)\*1023   | 5           |
| `cansend vcan0 1C1#0000000000FEFE13` | 127      | 1022      | (127/100)\*1022   | 1297        |
| `cansend vcan0 1C1#0000000000FF0011` | 127.5    | 256       | (127.5/100)\*256  | 326         |

---

#### Force Calculation (Tonne, if Bit 60 → 0)

| CAN payload                          | Actual % | Max Force | Calculation          | Result (Tonne) |
| :----------------------------------- | :------- | :-------- | :------------------- | :------------- |
| `cansend vcan0 1C1#0000000000FFFF03` | 127.5    | 1023      | 1304.325×0.101971621 | 133.0          |
| `cansend vcan0 1C1#0000000000FF0100` | 127.5    | 1         | 1.275×0.101971621    | 0.1            |
| `cansend vcan0 1C1#0000000000FFFF03` | 0.5      | 1023      | 5.115×0.101971621    | 0.5            |
| `cansend vcan0 1C1#0000000000FEFE03` | 127      | 1022      | 1297.94×0.101971621  | 132.3          |
| `cansend vcan0 1C1#0000000000FF0001` | 127.5    | 256       | 326.4×0.101971621    | 33.2           |

---

#### Load Bar Percentage which is manipulated by BYTE 6

| Payload                              | Byte 6 | Calculation | Result                |
| :----------------------------------- | :----- | :---------- | :-------------------- |
| `cansend vcan0 1C1#0000000000000000` | 0x00   | 0×0.5       | 0.0%                  |
| `cansend vcan0 1C1#0000000000640000` | 0x64   | 100\*0.5    | 50%                   |
| `cansend vcan0 1C1#00000000007F0000` | 0x7F   | 127×0.5     | 63.5%                 |
| `cansend vcan0 1C1#0000000000FF0000` | 0xFF   | 255×0.5     | 127.5->100% (clamped) |
| `cansend vcan0 1C1#0000000000C80000` | 0xC8   | 200×0.5     | 100% (clamped)        |
| `cansend vcan0 1C1#0000000000C60000` | 0xC6   | 198×0.5     | 99.0%                 |

# Table 5: Load Bar % and Rope length value for R1.

| PAYLOADS                             | Remaining Rope length (Decimal) | Remaining Rope length (Hex) | Maximum Rope length (Decimal) | Maximum Rope length (Hex) | Calculation = (Remaining / Maximum) × 100 | Load Bar % | Load Unit (m) = Remaining × 0.1 |
| :----------------------------------- | :------------------------------ | :-------------------------- | :---------------------------- | :------------------------ | :---------------------------------------- | :--------- | :------------------------------ |
| `cansend vcan0 4C1#0064800C00000000` | 100                             | `0x064`                     | 200                           | `0x0C8`                   | (100 / 200) × 100                         | 50%        | 100 × 0.1 = 10 m                |
| `cansend vcan0 4C1#003240F100000000` | 50                              | `0x032`                     | 500                           | `0x1F4`                   | (50 / 500) × 100                          | 10%        | 50 × 0.1 = 5 m                  |
| `cansend vcan0 4C1#00FAA00F00000000` | 250                             | `0x0FA`                     | 250                           | `0x0FA`                   | (250 / 250) × 100                         | 100%       | 250 × 0.1 = 25 m                |
| `cansend vcan0 4C1#007D803E00000000` | 125                             | `0x07D`                     | 1000                          | `0x3E8`                   | (125 / 1000) × 100                        | 12.5%      | 125 × 0.1 = 12.5 m              |
| `cansend vcan0 4C1#0001100000000000` | 1                               | `0x001`                     | 1                             | `0x001`                   | (1 / 1) × 100                             | 100%       | 1 × 0.1 = 0.1 m                 |
| `cansend vcan0 4C1#00FFFFFF00000000` | 4095                            | `0xFFF`                     | 4095                          | `0xFFF`                   | (4095 / 4095) × 100                       | 100%       | 4095 × 0.1 = 409.5 m            |
| `cansend vcan0 4C1#0001F0FF00000000` | 1                               | `0x001`                     | 4095                          | `0xFFF`                   | (1 / 4095) × 100                          | 0.024%     | 1 × 0.1 = 0.1 m                 |

---

# Table 6: Load Bar % and Rope length value for R2.

| PAYLOADS                             | Remaining Rope length (Decimal) | Remaining Rope length (Hex) | Maximum Rope length (Decimal) | Maximum Rope length (Hex) | Calculation = (Remaining / Maximum) × 100 | Load Bar % | Load Unit (m) = Remaining × 0.1 |
| :----------------------------------- | :------------------------------ | :-------------------------- | :---------------------------- | :------------------------ | :---------------------------------------- | :--------- | :------------------------------ |
| `cansend vcan0 4C2#0064800C00000000` | 100                             | `0x064`                     | 200                           | `0x0C8`                   | (100 / 200) × 100                         | 50%        | 100 × 0.1 = 10 m                |
| `cansend vcan0 4C2#003240F100000000` | 50                              | `0x032`                     | 500                           | `0x1F4`                   | (50 / 500) × 100                          | 10%        | 50 × 0.1 = 5 m                  |
| `cansend vcan0 4C2#00FAA00F00000000` | 250                             | `0x0FA`                     | 250                           | `0x0FA`                   | (250 / 250) × 100                         | 100%       | 250 × 0.1 = 25 m                |
| `cansend vcan0 4C2#007D803E00000000` | 125                             | `0x07D`                     | 1000                          | `0x3E8`                   | (125 / 1000) × 100                        | 12.5%      | 125 × 0.1 = 12.5 m              |
| `cansend vcan0 4C2#0001100000000000` | 1                               | `0x001`                     | 1                             | `0x001`                   | (1 / 1) × 100                             | 100%       | 1 × 0.1 = 0.1 m                 |
| `cansend vcan0 4C2#00FFFFFF00000000` | 4095                            | `0xFFF`                     | 4095                          | `0xFFF`                   | (4095 / 4095) × 100                       | 100%       | 4095 × 0.1 = 409.5 m            |
| `cansend vcan0 4C2#0001F0FF00000000` | 1                               | `0x001`                     | 4095                          | `0xFFF`                   | (1 / 4095) × 100                          | 0.024%     | 1 × 0.1 = 0.1 m                 |

---

# HPU Information (REMOTE 5) - Documentation

## EVENT DRIVEN ICONS

| S.No | Subsystem ID | Icon No | Icons                    | Payload                              | Description                                                                                                                   |
| ---- | ------------ | ------- | ------------------------ | ------------------------------------ | ----------------------------------------------------------------------------------------------------------------------------- |
| 1.   | SYS1         | 18      | System Error             | `cansend vcan0 181#1000000000000000` | PDO: 0x181 (System Status) Byte 1, Bit 04 (0x10 in Byte 1) Icon :- Activate when Byte1.Bit04=1, Deactivate when Byte1.Bit04=0 |
| 2.   | SYS1         | 31      | E-Stop                   | `cansend vcan0 181#0800000000000000` | PDO: 0x181 (System Status) Byte 1, Bit 03 (0x08 in Byte 1) Icon :- Activate when Byte1.Bit03=1, Deactivate when Byte1.Bit03=0 |
| 3.   | SYS1         | 189     | Emergency Operation Mode | -                                    | -                                                                                                                             |
| 4.   | H1           | 188     | Cooler Fan Reversal On   | -                                    | -                                                                                                                             |
| 5.   | H1           | 187     | Manual Cooling On        | -                                    | -                                                                                                                             |
| 6.   | H1           | 186     | Manual Heating On        | -                                    | -                                                                                                                             |

## FUNCTION BUTTON SELECT SET

| S.No | Subsystem ID | Icon No | Widgets/Icons | Payload | Description                 |
| ---- | ------------ | ------- | ------------- | ------- | --------------------------- |
| 1.   | -            | 48      | Page Up       | -       | Static icon. UI controlled. |
| 2.   | -            | 49      | Page Down     | -       | Static icon. UI controlled. |

## JOYSTICK ASSIGNMENT

- None.

## MAIN SCREEN INFORMATION

| S.No | Subsystem ID | Widget No | Widgets               | Payload                              | Description             |
| ---- | ------------ | --------- | --------------------- | ------------------------------------ | ----------------------- |
| 1.   | H1           | WD: 69    | Pressure Value        | `cansend vcan0 1CD#000000XX00000000` | See Table:1 Given Below |
| 2.   | H1           | WD: 70    | Flow Value            | `cansend vcan0 1CD#000000000000XX00` | See Table:2 Given Below |
| 3.   | H1           | WD: 71    | Oil Temperature Value | `cansend vcan0 1CD#0000000000XX0000` | See Table:3 Given Below |
| 4.   | H1           | WD: 72    | Oil Type Setting      | `cansend vcan0 1CD#0000000000000000` | UI is not Mapped Yet    |

---

# Table 1: WD:69->Pressure Value manipulated By Byte 4.

| PAYLOAD                              | Raw Data (Dec) | Raw Data (Hex) | Actual Value Displayed on UI in Bar (Raw data \* 2) |
| ------------------------------------ | -------------- | -------------- | --------------------------------------------------- |
| `cansend vcan0 1CD#0000006400000000` | 100            | 0x64           | (100\*2) = 200 Bar                                  |
| `cansend vcan0 1CD#000000C800000000` | 200(Maximum)   | 0xC8           | (200\*2) = 400 Bar                                  |
| `cansend vcan0 1CD#0000000000000000` | 0(Minimum)     | 0x00           | (0\*0) = 0 Bar                                      |
| `cansend vcan0 1CD#000000C600000000` | 198            | 0xC6           | (198\*2) = 396 Bar                                  |
| `cansend vcan0 1CD#0000007F00000000` | 127            | 0x7F           | (127\*2) = 254 Bar                                  |

## **Note : We cannot send raw value more than 200.**

---

# Table 2: WD:70->Oil flow Value manipulated By Byte 7.

| PAYLOAD                              | Raw Data (Dec) | Raw Data (Hex) | Actual Value Displayed on UI in Bar (Raw data \* 2) |
| ------------------------------------ | -------------- | -------------- | --------------------------------------------------- |
| `cansend vcan0 1CD#0000000000006400` | 100            | 0x64           | (100\*2) = 200 l/min                                |
| `cansend vcan0 1CD#0000000000009600` | 150(Maximum)   | 0x96           | (150\*2) = 300 l/min                                |
| `cansend vcan0 1CD#0000000000000000` | 0(Minimum)     | 0x00           | (0\*0) = 0 l/min                                    |
| `cansend vcan0 1CD#0000C00000003200` | 50             | 0x32           | (50\*2) = 100 l/min                                 |
| `cansend vcan0 1CD#0000000000007F00` | 127            | 0x7F           | (127\*2) = 254 l/min                                |

## **Note : We cannot send raw value more than 150.**

---

# Table 3: WD:71->Hydraulic Temperature Flow value manipulated By Byte 6.

| PAYLOAD                              | Raw Data (Dec) | Raw Data (Hex) | Actual Value Displayed on UI in Bar (Raw data \* 2) |
| ------------------------------------ | -------------- | -------------- | --------------------------------------------------- |
| `cansend vcan0 1CD#0000000000640000` | 100            | 0x64           | (100-50) = 50°C                                     |
| `cansend vcan0 1CD#0000000000FA0000` | 250(Maximum)   | 0xFA           | (250-50) = 200°C                                    |
| `cansend vcan0 1CD#0000000000000000` | 0(Minimum)     | 0x00           | (0) = 0°C                                           |
| `cansend vcan0 1CD#0000C00000320000` | 50             | 0x32           | (50-50) = 0°C                                       |
| `cansend vcan0 1CD#00000000007F0000` | 127            | 0x7F           | (127 - 50) = 77°C                                   |

## **Note : We cannot send raw value more than 250.**

# Table 4: WD:72->Oil Type Level Hydraulic value manipulated By Byte 8.

**It will be Added Later**

# System Information (REMOTE 6) - Documentation

## EVENT DRIVEN ICONS

| S.No | Subsystem ID | Icon No | Icons        | Payload                              | Description                                                                                                                |
| ---- | ------------ | ------- | ------------ | ------------------------------------ | -------------------------------------------------------------------------------------------------------------------------- |
| 1.   | SYS1         | 18      | System Error | `cansend vcan0 181#1000000000000000` | PDO: 0x181 (System Status) Byte 1, Bit 04 (0x10 in Byte 1) Icon Activate when Byte1.Bit04=1, Deactivate when Byte1.Bit04=0 |
| 2.   | SYS1         | 31      | E-Stop       | `cansend vcan0 181#0800000000000000` | PDO: 0x181 (System Status) Byte 1, Bit 03 (0x04 in Byte 1) Icon Activate when Byte1.Bit03=1, Deactivate when Byte1.Bit03=0 |

## FUNCTION BUTTON SELECT SET

- None.

## JOYSTICK ASSIGNMENT

| S.No | Subsystem ID | Icon No | Joysticks                                         | Payload | Description                  |
| ---- | ------------ | ------- | ------------------------------------------------- | ------- | ---------------------------- |
| 1.   | -            | 185     | Safe Function Button on FSM F2 - restart function | -       | Need to be changed in future |

## MAIN SCREEN INFORMATION

| S.No | Subsystem ID | Widget No | Widgets            | Payload                | Description |
| ---- | ------------ | --------- | ------------------ | ---------------------- | ----------- |
| 1.   | R1           | WD: 184   | System information | `1C1#XX00000000000000` | See Table 1 |
| 2.   | R2           | WD: 184   | System information | `1C2#XX00000000000000` | See Table 2 |
| 3.   | H1           | WD: 184   | System information | `1CD#XX00000000000000` | See Table 3 |
| 4.   | SYS1         | WD: 184   | System information | `181#XX00000000000000` | See Table 4 |
| 5.   | G1           | WD: 184   | System information | `1E7#XX00000000000000` | See Table 5 |
| 6.   | E1           | WD: 184   | System information | `1D6#XX00000000000000` | See Table 6 |

# Table 1: Main screen Information for Winch R1(WD 184)

| S.No | R1(Status) | Payloads                              |
| ---- | ---------- | ------------------------------------- |
| 1.   | "EMCY"     | `cansend vcan0 1C1#0800000000000000 ` |
| 2.   | "ERROR"    | `cansend vcan0 1C1#1000000000000000`  |
| 3.   | "ERROR"    | `cansend vcan0 1C1#2000000000000000`  |
| 4.   | "READY"    | `cansend vcan0 1C1#0200000000000000`  |
| 5.   | "NA"       | `cansend vcan0 1C1#0000000000000000`  |
| 6.   | "NA"       | `cansend vcan0 1C1#0100000000000000`  |
| 7.   | "NA"       | `cansend vcan0 1C1#4000000000000000`  |

# Table 2: Main screen Information for Winch R2(WD 184)

| S.No | R1(Status) | Payloads                              |
| ---- | ---------- | ------------------------------------- |
| 1.   | "EMCY"     | `cansend vcan0 1C2#0800000000000000 ` |
| 2.   | "ERROR"    | `cansend vcan0 1C2#1000000000000000`  |
| 3.   | "ERROR"    | `cansend vcan0 1C2#2000000000000000`  |
| 4.   | "READY"    | `cansend vcan0 1C2#0200000000000000`  |
| 5.   | "NA"       | `cansend vcan0 1C2#0000000000000000`  |
| 6.   | "NA"       | `cansend vcan0 1C2#0100000000000000`  |
| 7.   | "NA"       | `cansend vcan0 1C2#4000000000000000`  |

# Table 3: Main screen Information for H1(WD 184)

| S.No | R1(Status) | Payloads                              |
| ---- | ---------- | ------------------------------------- |
| 1.   | "EMCY"     | `cansend vcan0 1CD#0800000000000000 ` |
| 2.   | "ERROR"    | `cansend vcan0 1CD#1000000000000000`  |
| 3.   | "ERROR"    | `cansend vcan0 1CD#2000000000000000`  |
| 4.   | "READY"    | `cansend vcan0 1CD#0200000000000000`  |
| 5.   | "NA"       | `cansend vcan0 1CD#0000000000000000`  |
| 6.   | "NA"       | `cansend vcan0 1CD#0100000000000000`  |
| 7.   | "NA"       | `cansend vcan0 1CD#4000000000000000`  |

# Table 4: Main screen Information for SYS(WD 184)

| S.No | R1(Status) | Payloads                              |
| ---- | ---------- | ------------------------------------- |
| 1.   | "EMCY"     | `cansend vcan0 181#0800000000000000 ` |
| 2.   | "ERROR"    | `cansend vcan0 181#1000000000000000`  |
| 3.   | "ERROR"    | `cansend vcan0 181#2000000000000000`  |
| 4.   | "READY"    | `cansend vcan0 181#0200000000000000`  |
| 5.   | "NA"       | `cansend vcan0 181#0000000000000000`  |
| 6.   | "NA"       | `cansend vcan0 181#0100000000000000`  |
| 7.   | "NA"       | `cansend vcan0 181#4000000000000000`  |

# Table 5: Main screen Information for G1(WD 184)

**It will be added later.**

# Table 6: Main screen Information for E1(WD 184)

| S.No | R1(Status) | Payloads                              |
| ---- | ---------- | ------------------------------------- |
| 1.   | "EMCY"     | `cansend vcan0 1D6#0800000000000000 ` |
| 2.   | "ERROR"    | `cansend vcan0 1D6#1000000000000000`  |
| 3.   | "ERROR"    | `cansend vcan0 1D6#2000000000000000`  |
| 4.   | "READY"    | `cansend vcan0 1D6#0200000000000000`  |
| 5.   | "NA"       | `cansend vcan0 1D6#0000000000000000`  |
| 6.   | "NA"       | `cansend vcan0 1D6#0100000000000000`  |
| 7.   | "NA"       | `cansend vcan0 1D6#4000000000000000`  |
