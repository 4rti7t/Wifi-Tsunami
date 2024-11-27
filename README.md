

---

# 🌊 **WiFi Tsunami** 🌐

A **powerful C-based** tool designed for **educational** and **testing** purposes. **WiFi Tsunami** simulates a **UDP flood attack** to help you understand network security and test resilience. This tool targets **Wi-Fi networks** and allows you to flood them with UDP packets in a **lab environment**.

**⚠️ Caution**: This tool should **only** be used on systems or networks you own or have explicit permission to test. Unauthorized use may result in legal consequences.

---

## 📜 Features:
- 🌐 **Wi-Fi Network Flood**: Sends multiple UDP packets to a target IP.
- 🖥️ **User-Friendly Interface**: Interactive command-line interface for easy operation.
- ⏱️ **Customizable Settings**: Allows you to choose your target IP and customize settings.
- 🎮 **Main Menu**: Choose between starting the attack, restarting, or exiting.
- 🟩 **Neon Green Theme**: Enjoy a stylish matrix-like interface for a more immersive experience.
- 🔒 **Graceful Exit**: Handles interruptions like `Ctrl+C` and gives you options to either restart or exit.

---

## ⚙️ Requirements:

### 🖥️ **System Requirements**:
- **Linux** (Tested on Ubuntu, Kali Linux, CentOS)
- C Compiler (`gcc`)

### 🔧 **Required Libraries**:
- `sys/socket.h`
- `arpa/inet.h`
- `unistd.h`
- `signal.h`
- `stdio.h`
- `stdlib.h`

---

## 🛠️ Setup & Installation:

### 1. **Clone or Download the Repository**:
```bash
git clone https://github.com/4rti7t/Wifi_Tsunami.git
cd WiFi_Tsunami
```

### 2. **Compile the Code**:
Use `gcc` to compile the program:

```bash
gcc wifi_tsunami.c -o wifi_tsunami
```

### 3. **Run the Tool**:
After compiling, run the program:

```bash
./wifi_tsunami
```

---

## 📝 Usage:

1. **Main Menu**: When the program starts, you will be presented with options to begin or exit.
2. **Start the Attack**: Select option **1** to start the **Wi-Fi Tsunami** attack.
3. **Enter the Target IP**: Specify the **Wi-Fi router IP address** to flood.
4. The tool will continuously send UDP packets to the target IP. Press `Ctrl+C` to stop the attack at any time.
5. **Post-Interruption**: Once the attack is stopped, you will have the option to:
   - **Return to the Main Menu** to restart the attack, or
   - **Exit** with a message: *Happy Hacking! 😎*

---

## 💡 Example Run:

```bash
===============================
  Welcome to WiFi Tsunami 🌊
===============================

Main Menu:
1. Start Wi-Fi Tsunami Attack
2. Exit
Enter your choice: 1

Enter target IP address: 192.168.1.1
Starting Wi-Fi Tsunami flood on 192.168.1.1...

Packet 1 sent.
Packet 2 sent.
Packet 3 sent.
...

Flooding Complete!
Sent 100 packets to 192.168.1.1
====================================
Do you want to go to main menu (m) or exit (e)? m
```

---

## ⚠️ Important Notes:

- **Use Responsibly**: This tool is designed for **testing** in a **controlled lab environment**. Only use it on networks you own or have permission to test.
- **Legal Concerns**: Unauthorized use of this tool can have legal consequences. Always ensure you have **explicit permission**.
- **Network Testing**: Ideal for simulating **DoS** attacks on your **Wi-Fi network** to understand its resilience.

---

## 💬 Contribute:
Want to contribute to **WiFi Tsunami**? Feel free to **open an issue** or submit a **pull request**!

---

## 👨‍💻 License:
This tool is **open-source** under the **MIT License**.

---

### 🌟 **Happy Hacking!** 🌟


