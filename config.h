#ifndef CONFIG_H
#define CONFIG_H

// String used to delimit block outputs in the status.
#define DELIMITER " | "

// Maximum number of Unicode characters that a block can output.
#define MAX_BLOCK_OUTPUT_LENGTH 45

// Control whether blocks are clickable.
#define CLICKABLE_BLOCKS 0

// Control whether a leading delimiter should be prepended to the status.
#define LEADING_DELIMITER 0

// Control whether a trailing delimiter should be appended to the status.
#define TRAILING_DELIMITER 0

// Define blocks for the status feed as X(icon, cmd, interval, signal).
#define BLOCKS(X)             \
    X("CPU: ", "{ awk '/^cpu / {t=0; for(i=2;i<=NF;i++) t+=$i; print t,$5+$6; exit}' /proc/stat; sleep 1; awk '/^cpu / {t=0; for(i=2;i<=NF;i++) t+=$i; print t,$5+$6; exit}' /proc/stat; } | awk 'NR==1 {t=$1; i=$2; next} {printf \"%.2f%%\", 100*(1-($2-i)/($1-t))}'", 1, 9) \
    X("RAM: ", "free --mebi | awk '/^Mem:/ {printf \"%.2fGiB\", $3/1024}'", 1, 11) \
    X("", "date '+%d/%m/%y %H:%M:%S'", 1, 10)
// X("", "cat /sys/class/power_supply/BAT1/capacity | xargs -I {} echo {}%", 5, 9)

#endif  // CONFIG_H
