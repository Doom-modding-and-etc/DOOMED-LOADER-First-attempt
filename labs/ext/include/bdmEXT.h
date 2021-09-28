/*
** ______     _____  _____  __      __  _____ ______       _         ______      _      ______      ______  ______
**|      \   |     ||     ||  \    /  ||     |      \     | |       |      |    / \    |      \    |       |      |
**|       \  |     ||     ||   \  /   ||____ |       \    | |       |      |   /___\   |       \   |______ |   ___|
**|        \ |     ||     ||    \/    ||     |        \   | |_____  |      |  /     \  |        \  |       |   \  
**|_________\|_____||_____||          ||_____|_________\  |_______| |______| /       \ |_________\ |______ |    \ 
** 
** Licensed under Academic Free license v3.0
** Review LICENSE file for further details.
** Copyright 2021 André Guilherme mendes da luz bastos(Wolf3s)
** Based on the source code of dimok -> https://github.com/wiidev/usbloadergx/blob/enhanced/source/libs/libext2fs/ext2.h 
** and rickgaiser or Maximus32 work -> https://github.com/rickgaiser/ps2sdk/tree/bdm-clean/iop/fs/bdmfs_ext2
*/


#include "bdmsupport.h"
#include "mcemu.h"
#include "iosupport.h"

#define DISC_INTERFACE
#define sec_t

int startSector;

//EXT2 INITIAL SUPPORT
#define EXT2_CACHE_DEFAULT_PAGE_COUNT   64      /* The default number of pages in the cache */
#define EXT2_CACHE_DEFAULT_PAGE_SIZE    32      /* The default number of sectors per cache page */
#define EXT2_CLUSTERS 4096
#define EXT2_READ
#define EXT2_WRITE

/* EXT2 mount flags */
#define EXT2_FLAG_RW                    0x00001 /* Open the filesystem for reading and writing.  Without this flag, the filesystem is opened for reading only. */
#define EXT2_FLAG_FORCE                 0x00400 /* Open the filesystem regardless of the feature sets listed in the superblock */
#define EXT2_FLAG_JOURNAL_DEV_OK        0x01000 /* Only open external journal devices if this flag is set (e.g. ext3/ext4) */
#define EXT2_FLAG_64BITS                0x20000 /* Use the new style 64-Bit bitmaps. For more information see gen_bitmap64.c */
#define EXT2_FLAG_PRINT_PROGRESS        0x40000 /* If this flag is set the progress of file operations will be printed to stdout */
#define EXT2_FLAG_SKIP_MMP              0x100000 /* Open without multi-mount protection check. */
#define EXT2_FLAG_DEFAULT               (EXT2_FLAG_RW | EXT2_FLAG_64BITS | EXT2_FLAG_JOURNAL_DEV_OK | EXT2_FLAG_SKIP_MMP)

//BDM
#define BDM_MODE_UPDATE_DELAY MENU_UPD_DELAY_GENREFRESH
int bdmEXTPartition(char *target, const char *name, int write, const DISC_INTERFACE *interface, const sec_t **partitions, char path, int fd);
void bdmext2Mount(const char *name, const DISC_INTERFACE *interface, const sec_t **startSector, u32 cachePageCount, u32 cachePageSize, u32 flags, char mountEXTDrive[10], char path);
bool bdmext2Unmount(const char *name);
const char *bdmext2GetVolumeName (const char *name);
void bdmext2SetVolumeName (const char *name, const char *volumeName);
typedef int (*_ext2_frag_append_t)(void *ff, u32 offset, u32 sector, u32 count);
int _EXT2_get_fragments(const char *in_path, _ext2_frag_append_t append_fragment, void *callback_data);

int fs;
int i;

void bdm_connect_fs(struct file_system *fs)
{
  M_DEBUG("EXT2 CONNECTED");

  return ext2_connect_fs(fs);
}

int ext2_connect_bd(struct block_device* bd)
{
	M_DEBUG("ext2_connect_bd\n");

	return ext2_mount(bd);
}

void ext2_disconnect_bd(struct block_device* bd)
{
	M_DEBUG("ext2_disconnect_bd\n");

	ext2_umount(bd);
}


static struct file_system g_fs = {
	.priv = NULL,
	.name = "ext2",
	.connect_bd = ext2_connect_bd,
	.disconnect_bd = ext2_disconnect_bd,
};

void bdm_init()
{
	M_DEBUG("bdm_init\n");

	bdm_connect_fs(&g_fs);
}
