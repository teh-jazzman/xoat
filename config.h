// xoat config.

#define BORDER 1
#define BORDER_BLUR "Dark Gray"
#define BORDER_FOCUS "Royal Blue"
#define BORDER_URGENT "Red"
#define GAP 5

// Title bar xft font.
// Setting this to NULL will disable title bars
//#define TITLE NULL
#define TITLE "sans:size=9"

// Title bar style
#define TITLE_BLUR "Black"
#define TITLE_FOCUS "White"
#define TITLE_ELLIPSIS 32

// Window lists
# define MENU "sans:size=8"

// There are three static tiles called SPOT1, SPOT2, and SPOT3.
// Want more tiles? Different layouts? Floating? Go away ;)
// -------------------------------
// |                   |         |
// |                   |         |
// |                   |    2    |
// |         1         |         |
// |                   |---------|
// |                   |         |
// |                   |    3    |
// -------------------------------
// Actually, there are a few layout choices, but only at build time.

// .spot_start = SMART|CURRENT|SPOT1|SPOT2|SPOT3
//   SMART: Make new windows go to the spot of best fit.
//     Works best when apps remember or specify their size.
//   CURRENT: New windows open in the focused spot.

// .spot1_align = LEFT|RIGHT
//   The layout can be flipped so SPOT1 is on the right.
//   If you do this, review the directional move/focus key bindings too.

// .spot1_width_pct = N
//   Width of SPOT1 as percentage of screen width.

// .spot1_height_pct = N
//   Height of SPOT2 as percentage of screen height.

Layout layouts[] = {
	// Look at xrandr output to determine your monitor order.
	{ .spot_start = SMART, .spot1_align = LEFT,  .spot1_width_pct = 60, .spot2_height_pct = 60 }, // primary monitor
	{ .spot_start = SMART, .spot1_align = RIGHT, .spot1_width_pct = 60, .spot2_height_pct = 60 }, // secondary monitor, etc...
};

// Available actions...
// action_move             .num = SPOT1/2/3
// action_focus            .num = SPOT1/2/3
// action_move_direction   .num = UP/DOWN/LEFT/RIGHT
// action_focus_direction  .num = UP/DOWN/LEFT/RIGHT
// action_close
// action_cycle
// action_command
// action_find_or_start
// action_move_monitor
// action_focus_monitor
// action_fullscreen
// action_maximize_vert
// action_maximize_horz
// action_maximize
// action_menu

// If using "AnyModifier" place those keys at the end of the array.
Binding keys[] = {

	// Change focus to a spot by direction.
	{ .mod = Mod4Mask, .key = XK_h,  .act = action_focus_direction, .num = LEFT  },
	{ .mod = Mod4Mask, .key = XK_k,    .act = action_focus_direction, .num = UP    },
	{ .mod = Mod4Mask, .key = XK_l, .act = action_focus_direction, .num = RIGHT },
	{ .mod = Mod4Mask, .key = XK_j,  .act = action_focus_direction, .num = DOWN  },

	// Move the current window to another spot by direction.
	{ .mod = ShiftMask|Mod4Mask, .key = XK_h,  .act = action_move_direction, .num = LEFT  },
	{ .mod = ShiftMask|Mod4Mask, .key = XK_k,    .act = action_move_direction, .num = UP    },
	{ .mod = ShiftMask|Mod4Mask, .key = XK_l, .act = action_move_direction, .num = RIGHT },
	{ .mod = ShiftMask|Mod4Mask, .key = XK_j,  .act = action_move_direction, .num = DOWN  },

	// Flip between the top two windows in the current spot.
	{ .mod = Mod4Mask, .key = XK_Tab, .act = action_raise_nth, .num = 1 },

	// Cycle through all windows in the current spot.
	{ .mod = Mod4Mask, .key = XK_dead_circumflex,  .act = action_cycle },

	// Gracefully close the current window.
	{ .mod = Mod4Mask, .key = XK_Escape, .act = action_close },

	// Popup list of windows in current spot.
	{ .mod = Mod4Mask, .key = XK_Menu, .act = action_menu },

	// Toggle current window full screen.
	{ .mod = Mod4Mask, .key = XK_f, .act = action_fullscreen },
	{ .mod = Mod4Mask, .key = XK_v, .act = action_maximize_vert },
	{ .mod = Mod4Mask, .key = XK_b, .act = action_maximize_horz },
	{ .mod = Mod4Mask, .key = XK_m, .act = action_maximize },

	// Launcher
	{ .mod = Mod4Mask, .key = XK_x,  .act = action_command, .data = "dmenu_run" },
	{ .mod = Mod4Mask, .key = XK_F1, .act = action_command, .data = "st"   },
	{ .mod = Mod4Mask, .key = XK_F2, .act = action_find_or_start, .data = "chromium"  },
	{ .mod = Mod4Mask, .key = XK_F3, .act = action_find_or_start, .data = "spacefm"   },
	{ .mod = Mod4Mask, .key = XK_F4, .act = action_find_or_start, .data = "geany"   },
	{ .mod = Mod4Mask, .key = XK_plus, .act = action_command, .data = "amixer set Master 5+"   },
	{ .mod = Mod4Mask, .key = XK_minus, .act = action_command, .data = "amixer set Master 5-"   },
	{ .mod = AnyModifier, .key = XK_Print, .act = action_command, .data = "import /tmp/screenshot.png"  },

	// Find or start apps by WM_CLASS (lower case match).
	// Only works for apps that use some form of their binary name as their class...
	//{ .mod = AnyModifier, .key = XK_F1, .act = action_find_or_start, .data = "st"  },
	//{ .mod = AnyModifier, .key = XK_F2, .act = action_find_or_start, .data = "chromium" },
	//{ .mod = AnyModifier, .key = XK_F3, .act = action_find_or_start, .data = "spacefm"  },
	//{ .mod = AnyModifier, .key = XK_F4, .act = action_find_or_start, .data = "geany" },

	//{ .mod = AnyModifier, .key = XK_Print, .act = action_command, .data = "xowl"  },
};
