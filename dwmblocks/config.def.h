/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx       = 0;   /* border pixel of windows */
static const unsigned int snap           = 0;  /* snap pixel */
static const char autostartblocksh[]     = "autostart_blocking.sh";
static const char autostartsh[]          = "autostart.sh";
static const char dwmdir[]               = "dwm";
static const char localshare[]           = ".local/share";
static const int showbar                 = 1;   /* 0 means no bar */
static const int topbar                  = 1;   /* 0 means bottom bar */
/* Status is to be shown on: -1 (all monitors), 0 (a specific monitor by index), 'A' (active monitor) */
static const int statusmon               = 'A';
/* Indicators: see patch/bar_indicators.h for options */
static int tagindicatortype              = INDICATOR_TOP_LEFT_SQUARE;
static int tiledindicatortype            = INDICATOR_NONE;
static int floatindicatortype            = INDICATOR_TOP_LEFT_SQUARE;
static const char *fonts[]     = {"Monospace:size=10:antialias=true:autohint=true",
                                  "JoyPixels:size=10:antialias=true:autohint=true"
                                                        };
static const char dmenufont[]            = "Monospace:size=10";

static char c000000[]                    = "#131313"; // placeholder value

static char normfgcolor[]                = "#f9f7ff";
static char normbgcolor[]                = "#00a3ff";
static char normbordercolor[]            = "#00a3ff";
static char normfloatcolor[]             = "#00a3ff";

static char selfgcolor[]                 = "#f9f7ff";
static char selbgcolor[]                 = "#005eff";
static char selbordercolor[]             = "#005eff";
static char selfloatcolor[]              = "#005eff";

static char titlenormfgcolor[]           = "#f9f7ff";
static char titlenormbgcolor[]           = "#00a3ff";
static char titlenormbordercolor[]       = "#00a3ff";
static char titlenormfloatcolor[]        = "#00a3ff";

static char titleselfgcolor[]            = "#f9f7ff";
static char titleselbgcolor[]            = "#005eff";
static char titleselbordercolor[]        = "#005eff";
static char titleselfloatcolor[]         = "#005eff";

static char tagsnormfgcolor[]            = "#f9f7ff";
static char tagsnormbgcolor[]            = "#00a3ff";
static char tagsnormbordercolor[]        = "#00a3ff";
static char tagsnormfloatcolor[]         = "#00a3ff";

static char tagsselfgcolor[]             = "#f9f7ff";
static char tagsselbgcolor[]             = "#005eff";
static char tagsselbordercolor[]         = "#005eff";
static char tagsselfloatcolor[]          = "#005eff";

static char hidnormfgcolor[]             = "#f9f7ff";
static char hidselfgcolor[]              = "#00a3ff";
static char hidnormbgcolor[]             = "#00a3ff";
static char hidselbgcolor[]              = "#00a3ff";

static char urgfgcolor[]                 = "#f9f7ff";
static char urgbgcolor[]                 = "#005eff";
static char urgbordercolor[]             = "#005eff";
static char urgfloatcolor[]              = "#005eff";



static char *colors[][ColCount] = {
	/*                       fg                bg                border                float */
	[SchemeNorm]         = { normfgcolor,      normbgcolor,      normbordercolor,      normfloatcolor },
	[SchemeSel]          = { selfgcolor,       selbgcolor,       selbordercolor,       selfloatcolor },
	[SchemeTitleNorm]    = { titlenormfgcolor, titlenormbgcolor, titlenormbordercolor, titlenormfloatcolor },
	[SchemeTitleSel]     = { titleselfgcolor,  titleselbgcolor,  titleselbordercolor,  titleselfloatcolor },
	[SchemeTagsNorm]     = { tagsnormfgcolor,  tagsnormbgcolor,  tagsnormbordercolor,  tagsnormfloatcolor },
	[SchemeTagsSel]      = { tagsselfgcolor,   tagsselbgcolor,   tagsselbordercolor,   tagsselfloatcolor },
	[SchemeHidNorm]      = { hidnormfgcolor,   hidnormbgcolor,   c000000,              c000000 },
	[SchemeHidSel]       = { hidselfgcolor,    hidselbgcolor,    c000000,              c000000 },
	[SchemeUrg]          = { urgfgcolor,       urgbgcolor,       urgbordercolor,       urgfloatcolor },
};





/* Tags
 * In a traditional dwm the number of tags in use can be changed simply by changing the number
 * of strings in the tags array. This build does things a bit different which has some added
 * benefits. If you need to change the number of tags here then change the NUMTAGS macro in dwm.c.
 *
 * Examples:
 *
 *  1) static char *tagicons[][NUMTAGS*2] = {
 *         [DEFAULT_TAGS] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F", "G", "H", "I" },
 *     }
 *
 *  2) static char *tagicons[][1] = {
 *         [DEFAULT_TAGS] = { "•" },
 *     }
 *
 * The first example would result in the tags on the first monitor to be 1 through 9, while the
 * tags for the second monitor would be named A through I. A third monitor would start again at
 * 1 through 9 while the tags on a fourth monitor would also be named A through I. Note the tags
 * count of NUMTAGS*2 in the array initialiser which defines how many tag text / icon exists in
 * the array. This can be changed to *3 to add separate icons for a third monitor.
 *
 * For the second example each tag would be represented as a bullet point. Both cases work the
 * same from a technical standpoint - the icon index is derived from the tag index and the monitor
 * index. If the icon index is is greater than the number of tag icons then it will wrap around
 * until it an icon matches. Similarly if there are two tag icons then it would alternate between
 * them. This works seamlessly with alternative tags and alttagsdecoration patches.
 */
static char *tagicons[][NUMTAGS] = {
	[DEFAULT_TAGS]        = { "🤨", "👽", "🔪", "👌", "💀", "🔥", "🌈", "✨", "😳" },
	[ALTERNATIVE_TAGS]    = { "A", "B", "C", "D", "E", "F", "G", "H", "I" },
	[ALT_TAGS_DECORATION] = { "<1>", "<2>", "<3>", "<4>", "<5>", "<6>", "<7>", "<8>", "<9>" },
};


/* There are two options when it comes to per-client rules:
 *  - a typical struct table or
 *  - using the RULE macro
 *
 * A traditional struct table looks like this:
 *    // class      instance  title  wintype  tags mask  isfloating  monitor
 *    { "Gimp",     NULL,     NULL,  NULL,    1 << 4,    0,          -1 },
 *    { "Firefox",  NULL,     NULL,  NULL,    1 << 7,    0,          -1 },
 *
 * The RULE macro has the default values set for each field allowing you to only
 * specify the values that are relevant for your rule, e.g.
 *
 *    RULE(.class = "Gimp", .tags = 1 << 4)
 *    RULE(.class = "Firefox", .tags = 1 << 7)
 *
 * Refer to the Rule struct definition for the list of available fields depending on
 * the patches you enable.
 */
static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 *	WM_WINDOW_ROLE(STRING) = role
	 *	_NET_WM_WINDOW_TYPE(ATOM) = wintype
	 */
	RULE(.wintype = WTYPE "DIALOG", .isfloating = 1)
	RULE(.wintype = WTYPE "UTILITY", .isfloating = 1)
	RULE(.wintype = WTYPE "TOOLBAR", .isfloating = 1)
	RULE(.wintype = WTYPE "SPLASH", .isfloating = 1)
	RULE(.class = "Steam", .tags = 1 << 8)
};



/* Bar rules allow you to configure what is shown where on the bar, as well as
 * introducing your own bar modules.
 *
 *    monitor:
 *      -1  show on all monitors
 *       0  show on monitor 0
 *      'A' show on active monitor (i.e. focused / selected) (or just -1 for active?)
 *    bar - bar index, 0 is default, 1 is extrabar
 *    alignment - how the module is aligned compared to other modules
 *    widthfunc, drawfunc, clickfunc - providing bar module width, draw and click functions
 *    name - does nothing, intended for visual clue and for logging / debugging
 */
static const BarRule barrules[] = {
	/* monitor   bar    alignment         widthfunc                drawfunc                clickfunc                name */
	{ -1,        0,     BAR_ALIGN_LEFT,   width_tags,              draw_tags,              click_tags,              "tags" },
	{ -1,        0,     BAR_ALIGN_LEFT,   width_ltsymbol,          draw_ltsymbol,          click_ltsymbol,          "layout" },
	{ statusmon, 0,     BAR_ALIGN_RIGHT,  width_status,            draw_status,            click_status,            "status" },
	{ -1,        0,     BAR_ALIGN_NONE,   width_wintitle,          draw_wintitle,          click_wintitle,          "wintitle" },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */



static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ NULL,       NULL },
};


/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },



/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = {
	"dmenu_run",
	"-m", dmenumon,
	"-fn", dmenufont,
	"-nb", normbgcolor,
	"-nf", normfgcolor,
	"-sb", selbgcolor,
	"-sf", selfgcolor,
	NULL
};
static const char *termcmd[]  = { "st", NULL };



static Key keys[] = {
	/* modifier                     key            function                argument */
        { MODKEY,                       XK_Return,     spawn,                  {.v = termcmd } },
        { MODKEY,                       XK_b,          togglebar,              {0} },
	{ MODKEY|ShiftMask,             XK_Right,      rotatestack,            {.i = +1 } },
        { MODKEY|ShiftMask,             XK_Left,       rotatestack,            {.i = -1 } },
        { MODKEY,                       XK_Right,      focusstack,             {.i = +1 } },
        { MODKEY,                       XK_Left,       focusstack,             {.i = -1 } },
        { MODKEY,                       XK_j,          incnmaster,             {.i = +1 } },
        { MODKEY,                       XK_k,          incnmaster,             {.i = -1 } },
        { MODKEY,                       XK_u,          setmfact,               {.f = -0.05} },
        { MODKEY,                       XK_i,          setmfact,               {.f = +0.05} },
        { MODKEY|ControlMask,           XK_Return,     zoom,                   {0} },
        { Mod1Mask,                     XK_Tab,        view,                   {0} },
        { MODKEY|ShiftMask,             XK_q,          killclient,             {0} },
        { MODKEY,                       XK_F11,        quit,                   {0} },
        { MODKEY|ShiftMask,             XK_F11,        self_restart,           {0} },
	{ MODKEY|ShiftMask,             XK_t,          setlayout,              {.v = &layouts[0]} },
        { MODKEY,                       XK_f,          setlayout,              {.v = &layouts[1]} },
        { MODKEY,                       XK_space,      setlayout,              {0} },
        { MODKEY|ShiftMask,             XK_space,      togglefloating,         {0} },
        { MODKEY,                       XK_0,          view,                   {.ui = ~0 } },
        { MODKEY|ShiftMask,             XK_0,          tag,                    {.ui = ~0 } },
        { MODKEY,                       XK_comma,      focusmon,               {.i = -1 } },
        { MODKEY,                       XK_period,     focusmon,               {.i = +1 } },
        { MODKEY|ShiftMask,             XK_comma,      tagmon,                 {.i = -1 } },
        { MODKEY|ShiftMask,             XK_period,     tagmon,                 {.i = +1 } },
        { MODKEY,                       XK_Tab,        cyclelayout,            {.i = -1 } },
        { MODKEY|ControlMask,           XK_period,     cyclelayout,            {.i = +1 } },
	TAGKEYS(                        XK_1,                                  0)
	TAGKEYS(                        XK_2,                                  1)
	TAGKEYS(                        XK_3,                                  2)
	TAGKEYS(                        XK_4,                                  3)
	TAGKEYS(                        XK_5,                                  4)
	TAGKEYS(                        XK_6,                                  5)
	TAGKEYS(                        XK_7,                                  6)
	TAGKEYS(                        XK_8,                                  7)
	TAGKEYS(                        XK_9,                                  8)
};


/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask           button          function        argument */
	{ ClkLtSymbol,          0,                   Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,                   Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,                   Button2,        zoom,           {0} },
	{ ClkStatusText,        0,                   Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,              Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,              Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,              Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,                   Button1,        view,           {0} },
	{ ClkTagBar,            0,                   Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,              Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,              Button3,        toggletag,      {0} },
};



