# Automate Suckless Setup (Debian)

This project automates the installation and configuration of a minimal, high-performance Suckless desktop environment on Debian. It is tailored for a lightweight, keyboard-driven workflow using dwm and modern system enhancements like rounded corners, animations, and dynamic theming.

---

## Included Components

* dwm — Dynamic tiling window manager
* st — Simple terminal with scrollback and Xresources integration
* slstatus — Status monitor for CPU, RAM, battery, and time
* dmenu — Fast, minimal application launcher
* Rofi Cheatsheet — Custom, read-only interactive palette designed to mimic LazyVim's which-key layout mapped to Alt + /
* picom — Compositor featuring rounded corners (12px), dual-kawase blur, and fading
* feh — Lightweight wallpaper utility
* pywal — Automated color palette generation from wallpapers

---

## What This Setup Does

* Installs prerequisite system packages (gcc, make, libx11-dev, libxft-dev, fonts, rofi, xdotool, etc.)
* Deploys custom configurations into system directories like ~/.config/picom/
* Places picom.conf automatically into the correct location
* Deploys custom interactive dwm-cheatsheet tool automatically into your local path binaries (~/.local/bin/)
* Detects session type dynamically:
  * Display Manager (GDM/LightDM) -> uses ~/.xprofile
  * TTY + startx -> uses ~/.xinitrc
* Automatically starts compositor, wallpaper, Xresources, and the dwm session

---

## Installation & Setup Flow

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

*(Run this command inside each suckless directory group layout like dwm, st, slstatus, and dmenu)*

---

## System Architecture Overview

~/.xprofile                -> Used by display managers (GDM, LightDM)  
~/.xinitrc                 -> Used when starting X with startx  
~/.Xresources              -> Terminal fonts, colors, and X settings  
~/.config/picom/picom.conf -> Picom compositor configuration  
~/.local/bin/dwm-cheatsheet-> Read-only interactive chord keyboard panel
~/wallpapers/              -> Wallpaper directory  

---

## Booting into Your Environment

### Using a Display Manager:
* Select the dwm session from your display manager login screen profile menu.

### Using a TTY:
  startx  

---

## Theming with Pywal

  wal -i ~/wallpapers/wall.jpg  

---

## Important Notes

* Not Plug-and-Play: This setup may require manual adjustments depending on your hardware display server and graphic drivers.
* Font Configuration: Ensure your environment has ComicShannsMono Nerd Font and Symbols Nerd Font installed to render custom glyph strings accurately.
* Rebuild Rule: Remember to erase stale headers after altering settings or changes inside your layout keys or config.h source files:
  rm -f config.h && sudo make clean install
