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
    /* Network: USB / WiFi signal / Offline */
    { run_command,  "%s | ",              "if ip route get 1.1.1.1 2>/dev/null | grep -q 'enx'; then echo '󰁆 USB'; elif grep -q 'up' /sys/class/net/wlo1/operstate 2>/dev/null; then q=$(cat /proc/net/wireless 2>/dev/null | awk 'NR==3 {print int($4*100/70)}'); if [ $q -ge 80 ]; then echo '󰤨 WiFi' $q'%'; elif [ $q -ge 60 ]; then echo '󰤥 WiFi' $q'%'; elif [ $q -ge 40 ]; then echo '󰤢 WiFi' $q'%'; elif [ $q -ge 20 ]; then echo '󰤟 WiFi' $q'%'; else echo '󰤭 WiFi' $q'%'; fi; else echo '󰤭 Offline'; fi" },

    /* Battery: Shows different icons based on charge AND state (ternary chain) */
    { run_command,  "%s | ",              "s=$(cat /sys/class/power_supply/BAT1/status); p=$(cat /sys/class/power_supply/BAT1/capacity); if [ \"$s\" = \"Charging\" ]; then echo \"󰂄 $p%\"; else case $p in 9[0-9]|100) echo \"󰁹 $p%\";; 7[0-9]|8[0-9]) echo \"󰂀 $p%\";; 5[0-9]|6[0-9]) echo \"󰁾 $p%\";; 3[0-9]|4[0-9]) echo \"󰁼 $p%\";; 1[0-9]|2[0-9]) echo \"󰁺 $p%\";; *) echo \"󰂎 $p%\";; esac; fi" },

    /* System */
    { ram_perc,      "󰍛 %s%% | ",         NULL },
    { cpu_perc,      "󰻠 %s%% | ",         NULL },

    /* Time */
    { datetime,      "󰅐 %s",              "%a %d %b %Y, %I:%M %p" },
};
