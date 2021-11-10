#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <stdlib.h>
#include <stdio.h>

// magnifier factor
#define MAGNIFIER_FACTOR 1.5
#define MAGNIFIER_FACTOR_CHANGE 0.5

// magnifier hotkeys
#define MAGNIFIER_TOGGLE_KEY 9
#define MAGNIFIER_TOGGLE_MODIFIERS AnyModifier
#define MAGNIFIER_ENLARGE_KEY 8
#define MAGNIFIER_ENLARGE_MODIFIERS AnyModifier
#define MAGNIFIER_SHRINK_KEY None
#define MAGNIFIER_SHRINK_MODIFIERS AnyModifier

int main() {
    int magnified = False;
    float factor = 1.0;

    Display *dpy = XOpenDisplay(0);
    Window root = XDefaultRootWindow(dpy);
    XEvent ev;

// register hotkeys
#if MAGNIFIER_ENLARGE_KEY != None
    XGrabButton(dpy, MAGNIFIER_TOGGLE_KEY, MAGNIFIER_TOGGLE_MODIFIERS, root,
                False, ButtonPressMask, GrabModeAsync, GrabModeAsync, None,
                None);
#endif
#if MAGNIFIER_ENLARGE_KEY != None
    XGrabButton(dpy, MAGNIFIER_ENLARGE_KEY, MAGNIFIER_ENLARGE_MODIFIERS, root,
                False, ButtonPressMask, GrabModeAsync, GrabModeAsync, None,
                None);
#endif
#if MAGNIFIER_SHRINK_KEY != None
    XGrabButton(dpy, MAGNIFIER_SHRINK_KEY, MAGNIFIER_SHRINK_MODIFIERS, root,
                False, ButtonPressMask, GrabModeAsync, GrabModeAsync, None,
                None);
#endif

    // gnome magnifier on
    system("gsettings set org.gnome.desktop.a11y.magnifier mag-factor 1.0");
    system(
        "gsettings set org.gnome.desktop.a11y.applications "
        "screen-magnifier-enabled true");

    XSelectInput(dpy, root, ButtonPressMask);
    while (True) {
        char command[100];

        XNextEvent(dpy, &ev);

        switch (ev.type) {
            case ButtonPress:
                switch (ev.xbutton.button) {
                    case MAGNIFIER_TOGGLE_KEY:
                        if (magnified) {
                            magnified = False;
                            factor = 1.0;
                        } else {
                            magnified = True;
                            factor = MAGNIFIER_FACTOR;
                        }
                        break;
                    case MAGNIFIER_ENLARGE_KEY:
                        if (magnified) {
                            factor += MAGNIFIER_FACTOR_CHANGE;
                        }
                        break;
                    case MAGNIFIER_SHRINK_KEY:
                        if (magnified) {
                            factor -= MAGNIFIER_FACTOR_CHANGE;
                        }
                        break;
                }

                sprintf(command,
                        "gsettings set org.gnome.desktop.a11y.magnifier "
                        "mag-factor %.2f",
                        factor);
                system(command);
                break;
        }
    }
}
