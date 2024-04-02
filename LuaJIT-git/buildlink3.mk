# $NetBSD$

BUILDLINK_TREE+=	LuaJIT-git

.if !defined(LUAJIT_GIT_BUILDLINK3_MK)
LUAJIT_GIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.LuaJIT-git+=	LuaJIT-git>=2.1
BUILDLINK_PKGSRCDIR.LuaJIT-git?=	../../wip/LuaJIT-git

BUILDLINK_CFLAGS.LuaJIT-git+=	-I${BUILDLINK_PREFIX.LuaJIT-git}/include/luajit-2.1
.endif	# LUAJIT_GIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-LuaJIT-git
