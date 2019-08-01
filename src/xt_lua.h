/*
 * Copyright (C) 2017-2019  CUJO LLC
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef _XT_LUA_H
#define _XT_LUA_H

#include <linux/types.h>

#define XT_LUA_FUNC_SIZE	(1024)

#define NETLINK_NFLUA      	31     /* NFLua netlink protocol family */

#ifndef XT_LUA_MEM_LIMIT
#define XT_LUA_MEM_LIMIT        (32 * 1024 * 1024)
#endif

enum {
	XT_NFLUA_TCP_PAYLOAD = 0x01
};

struct xt_lua_mtinfo {
	char func[XT_LUA_FUNC_SIZE];
	__u8 flags;
};

#ifdef _KERNEL
struct nf_conn;
struct lua_State;
struct nf_conn *nflua_findconnid(lua_State *L);
void nflua_getdirection(lua_State *L, int arg, int *from, int *to);
#endif /* _KERNEL */

#endif
