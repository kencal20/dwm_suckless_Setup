# Automate Suckless Setup (Debian)

This project automates the installation and configuration of a minimal Suckless desktop environment on Debian.

It is designed for a lightweight, keyboard-driven workflow using dwm and related tools.

---

## 📦 Included Components

- dwm — dynamic tiling window manager
- st — simple terminal
- slstatus — status bar
- dmenu — application launcher
- picom — compositor for transparency
- feh — wallpaper setter
- pywal — automatic color theming

---

## ⚙️ What This Setup Does

- Installs required Debian packages
- Builds Suckless tools from source (if included in your setup)
- Configures startup automatically
- Detects session type:
  - GDM / display manager -> ~/.xprofile
  - startx -> ~/.xinitrc
- Sets up:
  - Compositor (picom)
  - Wallpaper (feh)
  - Xresources loading
  - dwm startup

---

## 📥 Installation

1. Extract the folder

unzip automate_suckless_debian.zip
cd automate

2. Install dependencies

chmod +x install-deps.sh
./install-deps.sh

This installs:
- Xorg / Xinit
- Build tools (gcc, make, git)
- Required development libraries
- picom, feh, dmenu
- pywal
- Fonts

3. Configure startup

chmod +x setup-startup.sh
./setup-startup.sh

This script:
- Detects session type (GDM or startx)
- Writes the correct startup file
- Configures picom, feh wallpaper, xrdb, and dwm

---

## 🧠 File Overview

~/.xprofile -> Used by display managers (GDM)
~/.xinitrc -> Used by startx
~/.Xresources -> Terminal/UI configuration
~/.config/picom/picom.conf -> Transparency settings
~/wallpapers/ -> Wallpaper directory

---

## 🚀 Starting Your System

Using GDM:
Just log in and select the dwm session (if available).

Using startx:
startx

---

## 🎨 Theming

This setup supports pywal for automatic color generation:

wal -i ~/wallpapers/wall.jpg

---

## 🪟 Core Applications

dwm: A fast, minimal tiling window manager controlled entirely by keyboard.

st: A lightweight terminal with scrollback support, clipboard integration, and Xresources support.

slstatus: Displays system information such as CPU, RAM, battery, and time.

dmenu: Fast program launcher.

---

## ⚠️ Important Notes

- Suckless programs must be recompiled after configuration changes.
- Ensure your wallpaper exists at ~/wallpapers/wall.jpg or update the script accordingly.
- This setup follows the Suckless philosophy: minimal, readable, and source-based configuration.

---

## 🧩 Optional Enhancements

You can extend this setup with:
- dwm patches (gaps, scratchpads, systray)
- dunst notification daemon
- Auto wallpaper rotation
- Brightness & volume keybinds
- Multi-monitor support

---

## 🏁 Result

After setup you will have:
- A minimal tiling desktop environment
- Fast keyboard-driven workflow
- Lightweight system usage
- Fully reproducible configuration
