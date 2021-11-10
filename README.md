# gnome-mouse-magnifier

gnome magnifier with mouse hotkeys using gsettings

## usage

set your hotkey in src/main.c

```
// magnifier hotkeys
#define MAGNIFIER_TOGGLE_KEY 9
#define MAGNIFIER_TOGGLE_MODIFIERS AnyModifier
#define MAGNIFIER_ENLARGE_KEY 8
#define MAGNIFIER_ENLARGE_MODIFIERS AnyModifier
#define MAGNIFIER_SHRINK_KEY None
#define MAGNIFIER_SHRINK_MODIFIERS AnyModifier
```