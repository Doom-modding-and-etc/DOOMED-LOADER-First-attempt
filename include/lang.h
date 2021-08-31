#ifndef __LANG_H
#define __LANG_H

// list of localized string ids
enum _STR_IDS {
    _STR_LOCALE = 0, // Localized language name
    _STR_SAVE_CHANGES,
    _STR_BACK,
    _STR_NETCONFIG,
    _STR_SHOW_ADVANCED_OPTS,
    _STR_NO_ITEMS,
    _STR_SETTINGS_SAVED,
    _STR_ERROR_SAVING_SETTINGS,
    _STR_EXIT,
    _STR_SETTINGS,
    _STR_MENU,
    _STR_BDM_GAMES,
    _STR_HDD_GAMES,
    _STR_NET_GAMES,
    _STR_APPS,
    _STR_THEME,
    _STR_LANGUAGE,
    _STR_CONFIRMATION_POFF,
    _STR_CONFIRMATION_EXIT,
    _STR_CONFIRMATION_CANCEL_UPDATE,
    _STR_HDD_NOT_CONNECTED_ERROR,
    _STR_HDD_NOT_FORMATTED_ERROR,
    _STR_NETWORK_STARTUP_ERROR, // Generic network error message.
    _STR_NETWORK_STARTUP_ERROR_NETIF,
    _STR_NETWORK_STARTUP_ERROR_CONN,
    _STR_NETWORK_STARTUP_ERROR_LOGON,
    _STR_NETWORK_STARTUP_ERROR_SHARE,
    _STR_NETWORK_SHARE_LIST_ERROR,
    _STR_NETWORK_GAMES_LIST_ERROR,
    _STR_NETWORK_ERROR_DHCP_FAIL,
    _STR_NETWORK_ERROR_LINK_FAIL,
    _STR_ON,
    _STR_OFF,
    _STR_OK,
    _STR_SELECT,
    _STR_CANCEL,
    _STR_CIRCLE,
    _STR_CROSS,
    _STR_GAMES_LIST,
    _STR_COMPAT_SETTINGS,
    _STR_REMOVE_ALL_SETTINGS,
    _STR_SCROLLING,
    _STR_SLOW,
    _STR_MEDIUM,
    _STR_FAST,
    _STR_DEFDEVICE,
    _STR_LOAD_FROM_DISC,
    _STR_PLEASE_WAIT,
    _STR_ERROR_LOADING_ID,
    _STR_AUTOSORT,
    _STR_ERR_LOADING_LANGFILE,
    _STR_DEBUG,
    _STR_NO_CONTROLLER,
    _STR_COVERART,
    _STR_WIDE_SCREEN,
    _STR_POWEROFF,
    _STR_LOADING_SETTINGS,
    _STR_SAVING_SETTINGS,
    _STR_START_DEVICE,
    _STR_REFRESH,
    _STR_BDMMODE,
    _STR_HDDMODE,
    _STR_ETHMODE,
    _STR_APPMODE,
    _STR_AUTO,
    _STR_MANUAL,
    _STR_STARTNBD,
    _STR_STARTINGNBD,
    _STR_RUNNINGNBD,
    _STR_STARTFAILNBD,
    _STR_UNLOADNBD,
    _STR_EXITTO,
    _STR_BGCOLOR,
    _STR_TXTCOLOR,
    _STR_CAT_SMB_SERVER,
    _STR_IP_ADDRESS_TYPE,
    _STR_IP_ADDRESS_TYPE_STATIC,
    _STR_IP_ADDRESS_TYPE_DHCP,
    _STR_IP_ADDRESS,
    _STR_ADDRESS,
    _STR_MASK,
    _STR_GATEWAY,
    _STR_DNS_SERVER,
    _STR_PORT,
    _STR_SHARE,
    _STR_USER,
    _STR_PASSWORD,
    _STR_NOT_SET,
    _STR_ADDRESS_TYPE,
    _STR_ADDR_TYPE_IP,
    _STR_ADDR_TYPE_NETBIOS,
    _STR_ACCEPT,
    _STR_DELETE_WARNING,
    _STR_RENAME,
    _STR_DELETE,
    _STR_RUN,
    _STR_GFX_SETTINGS,
    _STR_ENABLE_WRITE,
    _STR_LASTPLAYED,
    _STR_SELECTBUTTON,
    _STR_ERR_FRAGMENTED,
    _STR_ERR_FILE_INVALID,
    _STR_TEST,
    _STR_HINT_GUEST,
    _STR_HINT_MODE1,
    _STR_HINT_MODE2,
    _STR_HINT_MODE3,
    _STR_HINT_MODE4,
    _STR_HINT_MODE5,
    _STR_HINT_MODE6,
    _STR_HINT_VMC_SIZE,
    _STR_CREATE,
    _STR_START,
    _STR_MODIFY,
    _STR_ABORT,
    _STR_RESET,
    _STR_USE_GENERIC,
    _STR_VMC_SCREEN,
    _STR_VMC_NAME,
    _STR_SIZE,
    _STR_VMC_STATUS,
    _STR_VMC_PROGRESS,
    _STR_VMC_FILE_EXISTS,
    _STR_VMC_FILE_ERROR,
    _STR_VMC_FILE_NEW,
    _STR_ERR_VMC_CONTINUE,
    _STR_AUTOREFRESH,
    _STR_ABOUT,
    _STR_DEVS,
    _STR_QANDA,
    _STR_BDM_PREFIX,
    _STR_HINT_EXITPATH,
    _STR_HINT_SPINDOWN,
    _STR_HDD_SPINDOWN,
    _STR_VMODE,
    _STR_UICOLOR,
    _STR_SELCOLOR,
    _STR_RESETCOLOR,
    _STR_INFO,
    _STR_ALTSTARTUP,
    _STR_COLOR_SELECTION,
    _STR_RECONNECT,
    _STR_HINT_SHARENAME,
    _STR_ETH_PREFIX,
    _STR_BACKSPACE,
    _STR_SPACE,
    _STR_ENTER,
    _STR_MODE,
    _STR_VMC_SLOT1,
    _STR_VMC_SLOT2,
    _STR_GAME_ID,
    _STR_DMA_MODE,
    _STR_VSYNC,
    _STR_MODE1,
    _STR_MODE2,
    _STR_MODE3,
    _STR_MODE4,
    _STR_MODE5,
    _STR_MODE6,
    _STR_GSCONFIG,
    _STR_ETH_OPMODE,
    _STR_ETH_100MFDX,
    _STR_ETH_100MHDX,
    _STR_ETH_10MFDX,
    _STR_ETH_10MHDX,
    _STR_GSM_SETTINGS,
    _STR_ENABLEGSM,
    _STR_HINT_ENABLEGSM,
    _STR_HINT_GSMVMODE,
    _STR_XOFFSET,
    _STR_HINT_XOFFSET,
    _STR_YOFFSET,
    _STR_HINT_YOFFSET,
    _STR_OVERSCAN,
    _STR_HINT_OVERSCAN,
    _STR_GSMSKIPVIDEOS,
    _STR_HINT_GSMSKIPVIDEOS,
    _STR_CHEAT_SETTINGS,
    _STR_ENABLECHEAT,
    _STR_HINT_ENABLECHEAT,
    _STR_CHEATMODE,
    _STR_HINT_CHEATMODE,
    _STR_CHEATMODEAUTO,
    _STR_CHEATMODESELECT,
    _STR_ERR_CHEATS_LOAD_FAILED,
    _STR_NO_CHEATS_FOUND,
    _STR_DL_DEFAULTS,
    _STR_NET_UPDATE,
    _STR_NET_UPDATE_ALL,
    _STR_NET_UPDATE_FAILED,
    _STR_NET_UPDATE_CONN_FAILED,
    _STR_NET_UPDATE_DONE,
    _STR_NET_UPDATE_CANCELLED,
    _STR_CONFIRMATION_SETTINGS_UPDATE,
    _STR_CUSTOMIZED_SETTINGS,
    _STR_DOWNLOADED_DEFAULTS,
    _STR_AUTO_START_IN_N_SECS,
    _STR_AUTOSTARTLAST,
    _STR_HINT_AUTOSTARTLAST,
    _STR_PS2LOGO,
    _STR_HINT_PS2LOGO,
    _STR_PADEMUCONFIG,
    _STR_PADEMU_SETTINGS,
    _STR_PADEMU_ENABLE,
    _STR_HINT_PADEMU_ENABLE,
    _STR_PADEMU_MODE,
    _STR_HINT_PADEMU_MODE,
    _STR_DS34USB_MODE,
    _STR_DS34BT_MODE,
    _STR_PADPORT,
    _STR_HINT_PAD_PORT,
    _STR_PADEMU_PORT,
    _STR_HINT_PADEMU_PORT,
    _STR_PADEMU_VIB,
    _STR_HINT_PADEMU_VIB,
    _STR_USBDG_MAC,
    _STR_PAD_MAC,
    _STR_PAIR,
    _STR_PAIR_PAD,
    _STR_HINT_PAIRPAD,
    _STR_NOT_CONNECTED,
    _STR_BTINFO,
    _STR_HINT_BTINFO,
    _STR_HCIVER,
    _STR_LMPVER,
    _STR_MANUFACTURER,
    _STR_SUPFEATURES,
    _STR_YES,
    _STR_NO,
    _STR_BT_SUPPORTED,
    _STR_BT_NOTSUPPORTED,
    _STR_MTAP_ENABLE,
    _STR_HINT_MTAP_ENABLE,
    _STR_MTAP_PORT,
    _STR_HINT_MTAP_PORT,
    _STR_PADEMU_WORKAROUND,
    _STR_HINT_PADEMU_WORKAROUND,
    _STR_GSM_FIELD_FIX,
    _STR_HINT_GSM_FIELD_FIX,
    _STR_PARENLOCKCONFIG,
    _STR_PARENLOCK_PASSWORD,
    _STR_PARENLOCK_PASSWORD_HINT,
    _STR_PARENLOCK_ENTER_PASSWORD_TITLE,
    _STR_PARENLOCK_PASSWORD_INCORRECT,
    _STR_PARENLOCK_DISABLE_WARNING,
    _STR_BUILD_DETAILS,
    _STR_PARENLOCK_INVALID_PASSWORD,
    _STR_ERR_VMC_FRAGMENTED_CONTINUE,
    _STR_AUDIO_SETTINGS,
    _STR_SFX,
    _STR_BOOT_SND,
    _STR_SFX_VOLUME,
    _STR_BOOT_SND_VOLUME,
    _STR_CFM_VMODE_CHG,
    _STR_CACHE_HDD_GAME_LIST,
    _STR_ENABLE_NOTIFICATIONS,
    _STR_CFG_NOTIFICATION,
    _STR_THM_NOTIFICATION,
    _STR_LNG_NOTIFICATION,
    _STR_PARTITION_NOTIFICATION,
    _STR_OPTIONS,
    _STR_GAME_SETTINGS_SAVED,
    _STR_GAME_SETTINGS_REMOVED,
    _STR_NET_UPDATE_HINT,
    _STR_SETTINGS_SOURCE,
    _STR_GLOBAL_SETTINGS,
    _STR_PERGAME_SETTINGS,
    _STR_ALL_SETTINGS,
    _STR_GAME_SETTINGS_PROMPT,
    _STR_FORUM_DETAILS,
    _STR_INFO_TITLE,
    _STR_INFO_GENRE,
    _STR_INFO_RELEASE,
    _STR_INFO_DEVELOPER,
    _STR_INFO_DESCRIPTION,
    _STR_BLOCKDEVICE_SETTINGS,
    _STR_CONTROLLER_SETTINGS,
    _STR_HINT_BDM_START,
    _STR_HINT_BLOCK_DEVICES,
    _STR_WAD_GAMES,
    LANG_STR_COUNT
};

// Maximum external languages supported
#define MAX_LANGUAGE_FILES 15

// getter for a localised string version
extern char *_l(unsigned int id);

typedef struct
{
    char *filePath;
    char *name;
} language_t;

int lngAddLanguages(char *path, const char *separator, int mode);
void lngInit(void);
char *lngGetValue(void);
void lngEnd(void);

// Indices are shifted in GUI, as we add the internal english language at 0
int lngSetGuiValue(int langID);
int lngGetGuiValue(void);
int lngFindGuiID(const char *lang);
char **lngGetGuiList(void);
char *lngGetFilePath(int langID);

#endif
