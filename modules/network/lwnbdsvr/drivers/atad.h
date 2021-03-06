#ifndef ATAD_DRIVERS_NBD_H
#define ATAD_DRIVERS_NBD_H

#include "../irx_imports.h"
#include "../lwNBD/nbd_server.h"

#ifdef __cplusplus
extern "C" {
#endif

int atad_init(struct nbd_context *me);
int atad_read(struct nbd_context *me, void *buffer, uint64_t offset, uint32_t length);
int atad_write(struct nbd_context *me, void *buffer, uint64_t offset, uint32_t length);
int atad_flush(struct nbd_context *me);

#ifdef __cplusplus
}
#endif
#endif /* ATAD_DRIVERS_NBD_H */
