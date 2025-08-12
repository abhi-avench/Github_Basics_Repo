# Dual RCU PDO Documentation

## Screen 1-9 PDO

## EVENT DRIVEN DATA

| S.No | Subsystem ID | Icon No | Icons                    | Payload                | Description                                                                                                                     |
| ---- | ------------ | ------- | ------------------------ | ---------------------- | ------------------------------------------------------------------------------------------------------------------------------- |
| 1.   | R1           | 14      | Overload Winch R1        | `1C1#0000010000000000` | PDO: 0x1C1 (Winch R1 Status) Byte 3, Bit 16 (0x01 in Byte 3) Icon :- Activate when Byte3.Bit16=1, Deactivate when Byte3.Bit16=0 |
| 2.   | R2           | 14      | Overload Winch R2        | `1C2#0000010000000000` | PDO: 0x1C2 (Winch R2 Status) Byte 3, Bit 16 (0x01 in Byte 3) Icon :- Activate when Byte3.Bit16=1, Deactivate when Byte3.Bit16=0 |
| 3.   | SYS1         | 18      | System Error             | `181#1000000000000000` | PDO: 0x181 (System Status) Byte 1, Bit 04 (0x10 in Byte 1) Icon :- Activate when Byte1.Bit04=1, Deactivate when Byte1.Bit04=0   |
| 4.   | R1           | 16      | Rope End Winch R1        | `1C1#0000020000000000` | PDO: 0x1C1 (Winch R1 Status) Byte 3, Bit 17 (0x02 in Byte 3) Icon :- Activate when Byte3.Bit17=1, Deactivate when Byte3.Bit17=0 |
| 5.   | R2           | 16      | Rope End Winch R2        | `1C2#0000020000000000` | PDO: 0x1C2 (Winch R2 Status) Byte 3, Bit 17 (0x02 in Byte 3) Icon :- Activate when Byte3.Bit17=1, Deactivate when Byte3.Bit17=0 |
| 6.   | SYS1         | 30      | 15 t Mode                | `181#0000010000000000` | PDO: 0x181 (System Status) Byte 3, Bit 16 (0x01 in Byte 3) Icon :- Activate when Byte3.Bit16=1, Deactivate when Byte3.Bit16=0   |
| 7.   | SYS1         | 31      | E-Stop                   | `181#0800000000000000` | PDO: 0x181 (System Status) Byte 1, Bit 03 (0x08 in Byte 1) Icon :- Activate when Byte1.Bit03=1, Deactivate when Byte1.Bit03=0   |
| 8.   | R1           | 24      | Rope Thimble Winch R1    | `1C1#0080000000000000` | PDO: 0x1C1 (Winch R1 Status) Byte 2, Bit 15 (0x80 in Byte 2) Icon :- Activate when Byte2.Bit15=1, Deactivate when Byte2.Bit15=0 |
| 9.   | R2           | 24      | Rope Thimble Winch R2    | `1C2#0080000000000000` | PDO: 0x1C2 (Winch R2 Status) Byte 2, Bit 15 (0x80 in Byte 2) Icon :- Activate when Byte2.Bit15=1, Deactivate when Byte2.Bit15=0 |
| 10.  | SYS1         | 189     | Emergency Operation Mode | -                      | -                                                                                                                               |
| 11.  | H1           | 188     | Cooler Fan Reversal On   | -                      | -                                                                                                                               |
| 12.  | H1           | 187     | Manual Cooling On        | -                      | -                                                                                                                               |
| 13.  | H1           | 186     | Manual Heating On        | -                      | -                                                                                                                               |

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

| S.No | Subsystem ID | Widget No | Widget Name                               | Payload                | Description                                       |
| ---- | ------------ | --------- | ----------------------------------------- | ---------------------- | ------------------------------------------------- |
| 1.   | R2           | WD:59     | `_winch_type_no_gear_stat_std_L_00`       | `1C2#0000XX0000000000` | See Table 1: Gear Status for R2.                  |
| 2.   | R1           | WD:60     | `_winch_type_no_gear_stat_std_R_00`       | `1C1#0000XX0000000000` | See Table 2: Gear Status for R1                   |
| 3.   | R2           | WD:61     | `_3_45_load_unit_graphic_L_std_00`        | `1C2#0000000000XXXXXX` | See Tables 3 for load bar and force value for R2. |
| 4.   | R1           | WD:62     | `_3_45_load_unit_graphic_R_std_00`        | `1C1#0000000000XXXXXX` | See Tables 4 for load bar and force value for R1  |
| 5.   | R1           | WD:63     | `_3_45_rope_length_unit_graphic_R_std_00` | -                      |                                                   |
| 6.   | R2           | WD:64     | `_3_45_rope_length_unit_graphic_L_std_00` | -                      |                                                   |

---

# Table 1: Gear Status for R2

| Condition | Icon               | Example Payload        |
| --------- | ------------------ | ---------------------- |
| `XX=00`   | 0002 (Turtle)      | `1C2#0000000000000000` |
| `XX=04`   | 0027 (Hare)        | `1C2#0000040000000000` |
| `XX=08`   | 0003 (Turtle-Auto) | `1C2#0000080000000000` |
| `XX=0C`   | 0001 (Hare-Auto)   | `1C2#00000C0000000000` |

---

# Table 2: Gear Status for R1

| Condition | Icon               | Example Payload        |
| --------- | ------------------ | ---------------------- |
| `XX=00`   | 0002 (Turtle)      | `1C1#0000000000000000` |
| `XX=04`   | 0027 (Hare)        | `1C1#0000040000000000` |
| `XX=08`   | 0003 (Turtle-Auto) | `1C1#0000080000000000` |
| `XX=0C`   | 0001 (Hare-Auto)   | `1C1#00000C0000000000` |

---

# Tables 3: Load bar and force value for Winch R2.

### WD:61 - `_3_45_load_unit_graphic_L_std_00` (Winch R2)

#### Force Calculation (kN, if Bit 60 → 1)

| CAN payload            | Actual % | Max Force | Calculation       | Result (kN) |
| :--------------------- | :------- | :-------- | :---------------- | :---------- |
| `1C2#0000000000FFFF13` | 127.5    | 1023      | (127.5/100)\*1023 | 1304        |
| `1C2#0000000000FF0110` | 127.5    | 1         | (127.5/100)\*1    | 1           |
| `1C2#000000000001FF13` | 0.5      | 1023      | (0.5/100)\*1023   | 5           |
| `1C2#0000000000FEFE13` | 127      | 1022      | (127/100)\*1022   | 1297        |
| `1C2#0000000000FF0011` | 127.5    | 256       | (127.5/100)\*256  | 326         |

---

#### Force Calculation (Tonne, if Bit 60 → 0)

| CAN payload            | Actual % | Max Force | Calculation        | Result (Tonne) |
| :--------------------- | :------- | :-------- | :----------------- | :------------- |
| `1C2#0000000000FFFF03` | 127.5    | 1023      | 1304.325×0.1019716 | 132.9          |
| `1C2#0000000000FF0100` | 127.5    | 1         | 1.275×0.1019716    | 0.13           |
| `1C2#000000000001FF03` | 0.5      | 1023      | 5.115×0.1019716    | 0.52           |
| `1C2#0000000000FEFE03` | 127      | 1022      | 1297.94×0.1019716  | 132.3          |
| `1C2#0000000000FF0001` | 127.5    | 256       | 326.4×0.1019716    | 33.26          |

---

#### Load Bar Percentage which is manipulated by BYTE 6.

| Payload                | Byte 6 | Calculation | Result              |
| :--------------------- | :----- | :---------- | :------------------ |
| `1C2#0000000000000000` | 0x00   | 0×0.5       | 0.0%                |
| `1C1#0000000000640000` | 0x64   | 100\*0.5    | 50%                 |
| `1C2#00000000007F0000` | 0x7F   | 127×0.5     | 63.5%               |
| `1C2#0000000000FF0000` | 0xFF   | 255×0.5     | 127->100% (clamped) |
| `1C2#0000000000C80000` | 0xC8   | 200×0.5     | 100% (clamped)      |
| `1C2#0000000000C60000` | 0xC6   | 198×0.5     | 99.0%               |

---

# Table 4: Load bar and force value for winch R1

### WD:62 - `_3_45_load_unit_graphic_R_std_00` (Winch R1)

#### Force Calculation (kN, if Bit 60 → 1)

| CAN payload            | Actual % | Max Force | Calculation       | Result (kN) |
| :--------------------- | :------- | :-------- | :---------------- | :---------- |
| `1C1#0000000000FFFF13` | 127.5    | 1023      | (127.5/100)\*1023 | 1304        |
| `1C1#0000000000FF0110` | 127.5    | 1         | (127.5/100)\*1    | 1           |
| `1C1#000000000001FF13` | 0.5      | 1023      | (0.5/100)\*1023   | 5           |
| `1C1#0000000000FEFE13` | 127      | 1022      | (127/100)\*1022   | 1297        |
| `1C1#0000000000FF0011` | 127.5    | 256       | (127.5/100)\*256  | 326         |

---

#### Force Calculation (Tonne, if Bit 60 → 0)

| CAN payload            | Actual % | Max Force | Calculation        | Result (Tonne) |
| :--------------------- | :------- | :-------- | :----------------- | :------------- |
| `1C1#0000000000FFFF03` | 127.5    | 1023      | 1304.325×0.1019716 | 132.9          |
| `1C1#0000000000FF0100` | 127.5    | 1         | 1.275×0.1019716    | 0.13           |
| `1C1#0000000000FFFF03` | 0.5      | 1023      | 5.115×0.1019716    | 0.52           |
| `1C1#0000000000FEFE03` | 127      | 1022      | 1297.94×0.1019716  | 132.3          |
| `1C1#0000000000FF0001` | 127.5    | 256       | 326.4×0.1019716    | 33.26          |

---

#### Load Bar Percentage which is manipulated by BYTE 6

| Payload                | Byte 6 | Calculation | Result                |
| :--------------------- | :----- | :---------- | :-------------------- |
| `1C1#0000000000000000` | 0x00   | 0×0.5       | 0.0%                  |
| `1C1#0000000000640000` | 0x64   | 100\*0.5    | 50%                   |
| `1C1#00000000007F0000` | 0x7F   | 127×0.5     | 63.5%                 |
| `1C1#0000000000FF0000` | 0xFF   | 255×0.5     | 127.5->100% (clamped) |
| `1C1#0000000000C80000` | 0xC8   | 200×0.5     | 100% (clamped)        |
| `1C1#0000000000C60000` | 0xC6   | 198×0.5     | 99.0%                 |

|

# HPU Information (REMOTE 5) - Documentation

## EVENT DRIVEN ICONS

| S.No | Subsystem ID | Icon No | Icons                    | Payload                | Description                                                                                                                   |
| ---- | ------------ | ------- | ------------------------ | ---------------------- | ----------------------------------------------------------------------------------------------------------------------------- |
| 1.   | SYS1         | 18      | System Error             | `181#1000000000000000` | PDO: 0x181 (System Status) Byte 1, Bit 04 (0x10 in Byte 1) Icon :- Activate when Byte1.Bit04=1, Deactivate when Byte1.Bit04=0 |
| 2.   | SYS1         | 31      | E-Stop                   | `181#0800000000000000` | PDO: 0x181 (System Status) Byte 1, Bit 03 (0x08 in Byte 1) Icon :- Activate when Byte1.Bit03=1, Deactivate when Byte1.Bit03=0 |
| 3.   | SYS1         | 189     | Emergency Operation Mode | -                      | -                                                                                                                             |
| 4.   | H1           | 188     | Cooler Fan Reversal On   | -                      | -                                                                                                                             |
| 5.   | H1           | 187     | Manual Cooling On        | -                      | -                                                                                                                             |
| 6.   | H1           | 186     | Manual Heating On        | -                      | -                                                                                                                             |

## FUNCTION BUTTON SELECT SET

| S.No | Subsystem ID | Icon No | Widgets/Icons | Payload | Description                 |
| ---- | ------------ | ------- | ------------- | ------- | --------------------------- |
| 1.   | -            | 48      | Page Up       | -       | Static icon. UI controlled. |
| 2.   | -            | 49      | Page Down     | -       | Static icon. UI controlled. |

## JOYSTICK ASSIGNMENT

- None.

## MAIN SCREEN INFORMATION

| S.No | Subsystem ID | Widget No | Widgets               | Payload | Description |
| ---- | ------------ | --------- | --------------------- | ------- | ----------- |
| 1.   | H1           | WD: 69    | Pressure Value        | -       | -           |
| 2.   | H1           | WD: 70    | Flow Value            | -       | -           |
| 3.   | H1           | WD: 71    | Oil Temperature Value | -       | -           |
| 4.   | H1           | WD: 72    | Oil Type Setting      | -       | -           |

---

<br>
<br>
<br>

# System Information (REMOTE 6) - Documentation

## EVENT DRIVEN ICONS

| S.No | Subsystem ID | Icon No | Icons        | Payload                | Description                                                                                                                |
| ---- | ------------ | ------- | ------------ | ---------------------- | -------------------------------------------------------------------------------------------------------------------------- |
| 1.   | SYS1         | 18      | System Error | `181#1000000000000000` | PDO: 0x181 (System Status) Byte 1, Bit 04 (0x10 in Byte 1) Icon Activate when Byte1.Bit04=1, Deactivate when Byte1.Bit04=0 |
| 2.   | SYS1         | 31      | E-Stop       | `181#0800000000000000` | PDO: 0x181 (System Status) Byte 1, Bit 03 (0x04 in Byte 1) Icon Activate when Byte1.Bit03=1, Deactivate when Byte1.Bit03=0 |

## FUNCTION BUTTON SELECT SET

- None.

## JOYSTICK ASSIGNMENT

| S.No | Subsystem ID | Icon No | Joysticks                                         | Payload | Description                  |
| ---- | ------------ | ------- | ------------------------------------------------- | ------- | ---------------------------- |
| 1.   | -            | 185     | Safe Function Button on FSM F2 - restart function | -       | Need to be changed in future |

## MAIN SCREEN INFORMATION

| S.No | Subsystem ID | Widget No | Widgets            | Payload | Description |
| ---- | ------------ | --------- | ------------------ | ------- | ----------- |
| 1.   | R1           | WD: 184   | System information | -       | -           |
| 2.   | R2           | WD: 184   | System information | -       | -           |
| 3.   | H1           | WD: 184   | System information | -       | -           |
| 4.   | SYS1         | WD: 184   | System information | -       | -           |
| 5.   | G1           | WD: 184   | System information | -       | -           |
| 6.   | E1           | WD: 184   | System information | -       | -           |
