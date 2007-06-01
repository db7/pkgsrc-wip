# $NetBSD: buildlink3.mk,v 1.1.1.1 2007/06/01 00:57:58 hoka_adam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LUA50_PTY_BUILDLINK3_MK:=	${LUA50_PTY_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	lua50-pty
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlua50-pty}
BUILDLINK_PACKAGES+=	lua50-pty
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}lua50-pty

.if ${LUA50_PTY_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.lua50-pty+=	lua50-pty>=0.1
BUILDLINK_PKGSRCDIR.lua50-pty?=	../../wip/lua50-pty
.endif	# LUA50_PTY_BUILDLINK3_MK

.include "../../wip/lua50-compat51/buildlink3.mk"
.include "../../wip/lua50/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
