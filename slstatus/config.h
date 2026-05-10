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
    /* function         format                argument */
    { wifi_perc,       " %s%% | ",          "wlo1" },
    { battery_perc,    " %s%% | ",          "BAT1" },
    { battery_state,   "%s | ",              "BAT1" },
    { ram_perc,        " %s%% | ",          NULL },
    { cpu_perc,        " %s%% | ",          NULL },
    { datetime,        " %s",               "%a %d %b %Y, %r" },
};
