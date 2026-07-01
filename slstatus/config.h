/* See LICENSE file for copyright and license details. */

/* interval between updates (in ms) */
const unsigned int interval = 1000;

/* text to show if no value can be retrieved */
static const char unknown_str[] = "n/a";

/* maximum output string length */
#define MAXLEN 2048

/*
 * function            description
 *
 * battery_perc        battery percentage
 * battery_state       battery charging state
 * battery_remaining   battery remaining HH:MM
 * cpu_perc            cpu usage in percent
 * ram_perc            memory usage in percent
 * vol_perc            volume in percent (PulseAudio/PipeWire)
 * wifi_perc           WiFi signal in percent
 * datetime            date and time
 */

static const struct arg args[] = {
    /* Network: Ethernet / USB Tethering / WiFi (Icon ONLY, no numbers) / Offline */
    { run_command,  "%s | ",              "if grep -q 'up' /sys/class/net/en*/operstate 2>/dev/null; then if ip route get 1.1.1.1 2>/dev/null | grep -q 'enx'; then echo ' 󰈁 USB '; else echo ' 󰈀 Wired '; fi; elif grep -q 'up' /sys/class/net/wlo1/operstate 2>/dev/null; then q=$(cat /proc/net/wireless 2>/dev/null | awk 'NR==3 {print int($3*100/70)}'); if [ $q -ge 80 ]; then echo ' 󰤨  '; elif [ $q -ge 60 ]; then echo ' 󰤥  '; elif [ $q -ge 40 ]; then echo ' 󰤢  '; elif [ $q -ge 20 ]; then echo ' 󰤟  ' ; else echo '󰤭 ' ; fi; else echo ' 󰪎 Offline '; fi" },

    /* Battery: Uses your system-compatible icons for both states with a '+' indicator for charging */
/* Battery: Uses your reliable vertical icon sets, plus the nf-oct-plug glyph for charging status */
    { run_command,  "%s | ",              "s=$(cat /sys/class/power_supply/BAT1/status 2>/dev/null); p=$(cat /sys/class/power_supply/BAT1/capacity 2>/dev/null); if [ \"$s\" = \"Charging\" ] || [ \"$s\" = \"Full\" ]; then case $p in 9[0-9]|100) echo \"󰁹  $p\";; 7[0-9]|8[0-9]) echo \"󰂀  $p\";; 5[0-9]|6[0-9]) echo \"󰁾  $p\";; 3[0-9]|4[0-9]) echo \"󰁼  $p\";; 1[0-9]|2[0-9]) echo \"󰁺  $p\";; *) echo \"󰂎  $p\";; esac; else case $p in 9[0-9]|100) echo \"󰁹 $p\";; 7[0-9]|8[0-9]) echo \"󰂀 $p\";; 5[0-9]|6[0-9]) echo \"󰁾 $p\";; 3[0-9]|4[0-9]) echo \"󰁼 $p\";; 1[0-9]|2[0-9]) echo \"󰁺 $p\";; *) echo \"󰂎 $p\";; esac; fi" },
    /* System */
    { ram_perc,      "󰍛 %s%% | ",         NULL },
    { cpu_perc,      "󰻠 %s%% | ",         NULL },

    /* Time */
    { datetime,      "󰅐 %s",              "%a %d %b %Y, %I:%M %p" },
};
