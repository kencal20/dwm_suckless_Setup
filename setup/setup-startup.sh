#!/bin/bash

echo "Setting up picom configuration..."
# Create the target directory if it doesn't exist
mkdir -p "$HOME/.config/picom"

# Copy the picom config from the local directory to ~/.config/picom/
if [ -f "./picom.conf" ]; then
    cp ./picom.conf "$HOME/.config/picom/picom.conf"
    echo "✓ picom.conf successfully copied to ~/.config/picom/"
else
    echo "⚠ Warning: ./picom.conf not found in the current directory!"
fi

echo "Setting up startup config..."

# Detect if GDM session exists
if [ -n "$XDG_SESSION_TYPE" ] || [ -n "$DESKTOP_SESSION" ]; then
    echo "Detected graphical login (likely GDM)"
    TARGET="$HOME/.xprofile"
else
    echo "Detected startx session"
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
