# gnome-mouse-magnifier

gnome magnifier with mouse hotkeys using gsettings

## Usage

set your hotkey in src/main.c

```c
// magnifier hotkeys
#define MAGNIFIER_TOGGLE_KEY 9
#define MAGNIFIER_TOGGLE_MODIFIERS AnyModifier
#define MAGNIFIER_ENLARGE_KEY 8
#define MAGNIFIER_ENLARGE_MODIFIERS AnyModifier
#define MAGNIFIER_SHRINK_KEY None
#define MAGNIFIER_SHRINK_MODIFIERS AnyModifier
```

### mouse number

`1`: left button
`2`: middle button
`3`: right button
`4`: wheel up
`5`: wheel down
`6`: wheel left
`7`: wheel right
`8`: 4th button
`9`: 5th button
