/*
 * GPL HEADER START
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 * GPL HEADER END
 *
 * Derived from ./arch/x86/include/asm/msidef.h
 *
 * Copyright 2011 various Linux Kernel contributors.
 * Copyright 2011 Joyent, Inc. All Rights Reserved.
 */

#ifndef __KVM_MDIDEF_H
#define	__KVM_MSIDEF_H

/*
 * Constants for Intel APIC based MSI messages.
 */

/*
 * Shifts for MSI data
 */

#define	MSI_DATA_VECTOR_SHIFT		0
#define	MSI_DATA_VECTOR_MASK		0x000000ff
#define	MSI_DATA_VECTOR(v)		(((v) << MSI_DATA_VECTOR_SHIFT) & \
					    MSI_DATA_VECTOR_MASK)

#define	MSI_DATA_DELIVERY_MODE_SHIFT	8
#define	MSI_DATA_DELIVERY_FIXED		(0 << MSI_DATA_DELIVERY_MODE_SHIFT)
#define	MSI_DATA_DELIVERY_LOWPRI	(1 << MSI_DATA_DELIVERY_MODE_SHIFT)

#define	MSI_DATA_LEVEL_SHIFT		14
#define	MSI_DATA_LEVEL_DEASSERT		(0 << MSI_DATA_LEVEL_SHIFT)
#define	MSI_DATA_LEVEL_ASSERT		(1 << MSI_DATA_LEVEL_SHIFT)

#define	MSI_DATA_TRIGGER_SHIFT		15
#define	MSI_DATA_TRIGGER_EDGE		(0 << MSI_DATA_TRIGGER_SHIFT)
#define	MSI_DATA_TRIGGER_LEVEL		(1 << MSI_DATA_TRIGGER_SHIFT)

/*
 * Shift/mask fields for msi address
 */

#define	MSI_ADDR_BASE_HI		0
#define	MSI_ADDR_BASE_LO		0xfee00000

#define	MSI_ADDR_DEST_MODE_SHIFT	2
#define	MSI_ADDR_DEST_MODE_PHYSICAL	(0 << MSI_ADDR_DEST_MODE_SHIFT)
#define	MSI_ADDR_DEST_MODE_LOGICAL	(1 << MSI_ADDR_DEST_MODE_SHIFT)

#define	MSI_ADDR_REDIRECTION_SHIFT	3
#define	MSI_ADDR_REDIRECTION_CPU	(0 << MSI_ADDR_REDIRECTION_SHIFT)
					/* dedicated cpu */
#define	MSI_ADDR_REDIRECTION_LOWPRI	(1 << MSI_ADDR_REDIRECTION_SHIFT)
					/* lowest priority */

#define	MSI_ADDR_DEST_ID_SHIFT		12
#define	MSI_ADDR_DEST_ID_MASK		0x00ffff0
#define	MSI_ADDR_DEST_ID(dest)		(((dest) << MSI_ADDR_DEST_ID_SHIFT) & \
					    MSI_ADDR_DEST_ID_MASK)

#define	MSI_ADDR_IR_EXT_INT		(1 << 4)
#define	MSI_ADDR_IR_SHV			(1 << 3)
#define	MSI_ADDR_IR_INDEX1(index)	((index & 0x8000) >> 13)
#define	MSI_ADDR_IR_INDEX2(index)	((index & 0x7fff) << 5)

#endif
