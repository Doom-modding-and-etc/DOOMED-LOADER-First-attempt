/*
** ______     _____  _____  __      __  _____ ______       _         ______      _      ______      ______  ______
**|      \   |     ||     ||  \    /  ||     |      \     | |       |      |    / \    |      \    |       |      |
**|       \  |     ||     ||   \  /   ||____ |       \    | |       |      |   /___\   |       \   |______ |  ____|
**|        \ |     ||     ||    \/    ||     |        \   | |_____  |      |  /     \  |        \  |       |  \  
**|_________\|_____||_____||          ||_____|_________\  |_______| |______| /       \ |_________\ |______ |   \ 
** 
** Licensed under Academic Free license v3.0
** Review LICENSE file for further details.
** Copyright 2021 André Guilherme mendes da luz bastos(Wolf3s)
** Based on the source code of dimok -> https://github.com/wiidev/usbloadergx/blob/enhanced/source/libs/libext2fs/ext2.h 
*/

#include "ex/opl.h"
#include "ex/lang.h"
#include "ex/gui.h"
#include "ex/supportbase.h"
#include "ex/bdmsupport.h"
#include "ex/util.h"
#include "ex/themes.h"
#include "ex/textures.h"
#include "ex/ioman.h"
#include "ex/system.h"
#include "ex/extern_irx.h"
#include "ex/cheatman.h"
#include "modules/iopcore/common/cdvd_config.h"
#include "ex/bdmEXT.h"



int clusters;

static char bdmPrefix[40]; // Contains the full path to the folder where all the games are.
static int bdmULSizePrev = -2;
static time_t bdmModifiedCDPrev;
static time_t bdmModifiedDVDPrev;
static int bdmGameCount = 0;
static base_game_info_t *bdmGames;
static char bdmDriver[5];

static int iLinkModLoaded = 0;
static int mx4sioModLoaded = 0;

// forward declaration
static item_list_t bdmGameList;


//Primary mount of the ext drive 
void bdmext2Mount(const char *name, const DISC_INTERFACE *interface, const sec_t **startSector, u32 cachePageCount, u32 cachePageSize, u32 flags, char mountEXTDrive[10], char path)
{
  for(i; i < interface; i++)
  {
     if (read)
     {
       sprintf(path, "mass%d:%d/%d/%s/\n\n\n\n", startSector, i, cachePageSize, cachePageCount, flags);
     } 
  }
}

void bdmext2SetVolumeName(const char *name, const char *volumeName);


int bdmEXTPartition(char *target, const char *name, int write, const DISC_INTERFACE *interface, const sec_t **partitions, char path, int fd)
{
  for(i; i < MAX_BDM_DEVICES; i++) 
  {
    if (gBDMPrefix[0] != '\0')
    sprintf(path, "mass%d:%s/%s", i, gBDMPrefix, name);
    else
    sprintf(path, "mass%d:%s", i, name);
    if (write)
    fd = open(path, O_WRONLY | O_TRUNC | O_CREAT, 0666);
    else
    fd = open(path, O_RDONLY);
    if (fd >= 0) 
    {
      if (gBDMPrefix[0] != '\0')
      sprintf(target, "mass%d:%s/", i, gBDMPrefix);
      else
      sprintf(target, "mass%d:", i);
      close(fd);
       return 1;
    }
    if (fd >= 0) 
    {
      if (gBDMPrefix[0] != '\0')
      sprintf(target, "mass%d:%s/", i, gBDMPrefix);
      else
      sprintf(target, "mass%d:", i);
      close(fd);            return 1;
    }
      // default to first partition (for themes, ...)
    if (gBDMPrefix[0] != '\0')
        sprintf(target, "mass0:%s/", gBDMPrefix);
    else
        sprintf(target, "mass0:");
    return 0;  
  }
}

bool bdmext2Unmount(const char *name)
{
  return true;
}

static void bdmLoadBlockDeviceModules(void)
{
    if (gEnableILK && !iLinkModLoaded) {
        // Load iLink Block Device drivers
        sysLoadModuleBuffer(&iLinkman_irx, size_iLinkman_irx, 0, NULL);
        sysLoadModuleBuffer(&IEEE1394_bd_irx, size_IEEE1394_bd_irx, 0, NULL);

        iLinkModLoaded = 1;
    }

    if (gEnableMX4SIO && !mx4sioModLoaded) {
        // Load MX4SIO Block Device drivers
        sysLoadModuleBuffer(&mx4sio_bd_irx, size_mx4sio_bd_irx, 0, NULL);

        mx4sioModLoaded = 1;
    }
}

