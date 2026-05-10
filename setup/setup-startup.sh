#!/bin/bash

echo "Setting up startup config..."

# Detect if GDM session exists
if [ -n "$XDG_SESSION_TYPE" ] || [ -n "$DESKTOP_SESSION" ]; then
    echo "Detected graphical login (likely GDM)"

    # Use .xprofile for display managers
    TARGET="$HOME/.xprofile"

else
    echo "Detected startx session"

    # Use .xinitrc for startx
    TARGET="$HOME/.xinitrc"
fi

echo "Writing startup config to $TARGET"

cat > "$TARGET" << 'EOF'
# Load Xresources
xrdb -merge ~/.Xresources

# Start compositor
picom --config ~/.config/picom/picom.conf &

# Set wallpaper (change path if needed)
feh --bg-scale ~/wallpapers/wall.jpg &

# Start dwm
exec dwm
EOF

chmod +x "$TARGET"

echo "Done. Startup configured."
