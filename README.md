# Automate Suckless Setup (Debian)

This project automates the installation and configuration of a minimal, high-performance Suckless desktop environment on Debian. It is tailored for a lightweight, keyboard-driven workflow using `dwm` and modern system enhancements like rounded corners, animations, and dynamic theming.

---

## 📦 Included Components

* **dwm** — Dynamic tiling window manager
* **st** — Simple terminal with scrollback and Xresources integration
* **slstatus** — Status monitor for CPU, RAM, battery, and time
* **dmenu** — Fast, minimal application launcher
* **picom** — Compositor featuring rounded corners (12px), dual-kawase blur, and fading
* **feh** — Lightweight wallpaper utility
* **pywal** — Automated color palette generation from wallpapers

---

## ⚙️ What This Setup Does

* Installs prerequisite packages (gcc, make, libx11-dev, libxft-dev, fonts, etc.)
* Deploys custom configurations into system directories like ~/.config/picom/
* Places picom.conf automatically into the correct location
* Detects session type dynamically:
  * Display Manager (GDM/LightDM) → uses ~/.xprofile
  * TTY + startx → uses ~/.xinitrc
* Automatically starts compositor, wallpaper, Xresources, and dwm session

---

## 📥 Installation & Setup Flow

### Step 1: Clone the Repository
git clone https://github.com/kencal20/dwm_suckless_Setup.git  
cd dwm_suckless_Setup  

---

### Step 2: Install System Dependencies
chmod +x ./setup/install-deps.sh  
./setup/install-deps.sh  

---

### Step 3: Run Automated Configuration Setup
chmod +x ./setup/setup-startup.sh  
./setup/setup-startup.sh  

---

### Step 4: Compile and Install Suckless Tools
sudo make clean install  

(Do this inside each suckless directory like dwm, st, slstatus, dmenu)

---

## 🧠 System Architecture Overview

~/.xprofile → Used by display managers (GDM, LightDM)  
~/.xinitrc → Used when starting X with startx  
~/.Xresources → Terminal fonts, colors, and X settings  
~/.config/picom/picom.conf → Picom compositor configuration  
~/wallpapers/ → Wallpaper directory  

---

## 🚀 Booting into Your Environment

Using Display Manager:
- Select dwm session from login screen

Using TTY:
startx  

---

## 🎨 Theming with Pywal

wal -i ~/wallpapers/wall.jpg  

---

## ⚠️ Important Notes

Not Plug-and-Play:
This setup may require manual fixes depending on hardware and drivers.

Troubleshooting:
If startx fails, check logs and configuration files.

Rebuild Rule:
After changing config.h:
sudo make clean install  

Wallpaper Requirement:
Ensure this file exists:
~/wallpapers/wall.jpg
