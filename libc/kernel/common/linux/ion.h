/****************************************************************************
 ****************************************************************************
 ***
 ***   This header was automatically generated from a Linux kernel header
 ***   of the same name, to make information necessary for userspace to
 ***   call into the kernel available to libc.  It contains only constants,
 ***   structures, and macros generated from the original header, and thus,
 ***   contains no copyrightable information.
 ***
 ***   To edit the content of this header, modify the corresponding
 ***   source file (e.g. under external/kernel-headers/original/) then
 ***   run bionic/libc/kernel/tools/update_all.py
 ***
 ***   Any manual change here will be lost the next time this script will
 ***   be run. You've been warned!
 ***
 ****************************************************************************
 ****************************************************************************/
#ifndef _LINUX_ION_H
#define _LINUX_ION_H
#include <linux/ioctl.h>
#include <linux/types.h>
struct ion_handle;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
enum ion_heap_type {
 ION_HEAP_TYPE_SYSTEM,
 ION_HEAP_TYPE_SYSTEM_CONTIG,
 ION_HEAP_TYPE_CARVEOUT,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 ION_HEAP_TYPE_CUSTOM,
 ION_NUM_HEAPS = 16,
};
#define ION_HEAP_SYSTEM_MASK (1 << ION_HEAP_TYPE_SYSTEM)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define ION_HEAP_SYSTEM_CONTIG_MASK (1 << ION_HEAP_TYPE_SYSTEM_CONTIG)
#define ION_HEAP_CARVEOUT_MASK (1 << ION_HEAP_TYPE_CARVEOUT)
#define ION_FLAG_CACHED 1
#define ION_FLAG_CACHED_NEEDS_SYNC 2
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define ION_IS_CACHED(__flags)	((__flags) & ION_FLAG_CACHED)
#ifdef __KERNEL__
struct ion_device;
struct ion_heap;
struct ion_mapper;
struct ion_client;
struct ion_buffer;
#define ion_phys_addr_t unsigned long
struct ion_platform_heap {
	enum ion_heap_type type;
	unsigned int id;
	const char *name;
	ion_phys_addr_t base;
	size_t size;
	unsigned int has_outer_cache;
};
struct ion_platform_data {
	int nr;
	struct ion_platform_heap heaps[];
};
void ion_reserve(struct ion_platform_data *data);
struct ion_client *ion_client_create(struct ion_device *dev,
				     const char *name);
void ion_client_destroy(struct ion_client *client);
struct ion_handle *ion_alloc(struct ion_client *client, size_t len,
			     size_t align, unsigned int heap_id_mask,
			     unsigned int flags);
void ion_free(struct ion_client *client, struct ion_handle *handle);
int ion_phys(struct ion_client *client, struct ion_handle *handle,
	     ion_phys_addr_t *addr, size_t *len);
struct sg_table *ion_sg_table(struct ion_client *client,
			      struct ion_handle *handle);
void *ion_map_kernel(struct ion_client *client, struct ion_handle *handle);
void ion_unmap_kernel(struct ion_client *client, struct ion_handle *handle);
int ion_share_dma_buf(struct ion_client *client, struct ion_handle *handle);
struct ion_handle *ion_import_dma_buf(struct ion_client *client, int fd);
#endif /* __KERNEL__ */
struct ion_allocation_data {
 size_t len;
 size_t align;
 unsigned int heap_mask;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int flags;
 struct ion_handle *handle;
};
struct ion_fd_data {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 struct ion_handle *handle;
 int fd;
};
struct ion_handle_data {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 struct ion_handle *handle;
};
struct ion_custom_data {
 unsigned int cmd;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned long arg;
};
struct ion_flush_data {
	struct ion_handle *handle;
	int fd;
	void *vaddr;
	unsigned int offset;
	unsigned int length;
};
struct ion_flag_data {
	struct ion_handle *handle;
	unsigned long flags;
};
#define ION_IOC_MAGIC 'I'
#define ION_IOC_ALLOC _IOWR(ION_IOC_MAGIC, 0,   struct ion_allocation_data)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define ION_IOC_FREE _IOWR(ION_IOC_MAGIC, 1, struct ion_handle_data)
#define ION_IOC_MAP _IOWR(ION_IOC_MAGIC, 2, struct ion_fd_data)
#define ION_IOC_SHARE _IOWR(ION_IOC_MAGIC, 4, struct ion_fd_data)
#define ION_IOC_IMPORT _IOWR(ION_IOC_MAGIC, 5, struct ion_fd_data)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define ION_IOC_SYNC _IOWR(ION_IOC_MAGIC, 7, struct ion_fd_data)
#define ION_IOC_CUSTOM _IOWR(ION_IOC_MAGIC, 6, struct ion_custom_data)
#define ION_IOC_CLEAN_CACHES	_IOWR(ION_IOC_MAGIC, 20, struct ion_flush_data)
#define ION_IOC_INV_CACHES	_IOWR(ION_IOC_MAGIC, 21, struct ion_flush_data)
#define ION_IOC_CLEAN_INV_CACHES	_IOWR(ION_IOC_MAGIC, 22, struct ion_flush_data)
#endif
