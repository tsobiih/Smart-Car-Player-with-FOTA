# 🚗🎶 Smart Car Music Player with FOTA Support

Final project from the ARM Embedded Systems Diploma — a fully functional Smart Car Music Player built using STM32F401CC and ESP32, with integrated Firmware Over-The-Air (FOTA) update capability.

## 🎬 Project Demo Video  
[Watch on YouTube](https://surl.li/hmoprz)

---

## 🛠️ Key Features

- Default player screen with:
  - Track name
  - Progress bar
  - Volume level
  - Wi-Fi connection status
- Animated audio bars during playback
- Full playback controls:  
  `Play / Pause` | `Next` | `Previous` | `Volume Up / Down`
- DFPlayer Mini and R2R DAC-based dual audio output
- Menu navigation for:
  - 🎵 Music Player  
  - ⚙️ Settings (Volume, Brightness, Music Type: Jazz/Pop/etc.)  
  - 🔁 FOTA Setup  

---

## 📡 FOTA Workflow

- Automatically checks for new firmware versions over Wi-Fi
- ESP32 downloads firmware and sends via UART to STM32 bootloader
- Bootloader (Sector 0) writes new code to Sector 5
- Validates and copies new firmware to Sector 4
- Rollback to previous version in case of error
- Handles:
  - Broken hex lines
  - Timeout issues
  - Wi-Fi or update failure

---

## 🔩 Hardware Components

- **MCUs**: STM32F401CC + ESP32 DevKit V1  
- **Audio**: DFPlayer Mini, R2R DAC with RC Filter  
- **Display**: ST7735 TFT 1.8"  
- **Input/Output**:  
  - 7-Segment Display  
  - Push Buttons  
  - LEDs  
- **Communication**: UART between STM32 and ESP32  
- **Other**: Serial-to-Parallel Shift Register IC  
- **Speakers**: Dual outputs (DFPlayer + DAC)

---

## 📁 Project Structure
SmartCarPlayer/
├── Core/ # STM32 Application Code
├── Bootloader/ # Custom Bootloader for FOTA
├── ESP32_Firmware/ # ESP32-side firmware for Wi-Fi & UART handling
├── Media/ # Images and icons for the TFT
├── Docs/ # Schematics and documentation
└── README.md

---

## 💻 How to Use

1. Flash STM32 Bootloader to Sector 0  
2. Flash main application to Sector 4  
3. Run ESP32 firmware to enable OTA  
4. Connect to Wi-Fi and navigate to FOTA menu to update firmware

---

## 🧠 Contributors

This project was developed as a diploma graduation project by a team of embedded systems students.

---

Feel free to fork, contribute, or report issues.  
