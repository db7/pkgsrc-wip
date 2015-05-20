# $NetBSD: buildlink3.mk,v 1.1 2015/05/20 21:54:19 alnsn Exp $

BUILDLINK_TREE+=	mpfi

.if !defined(MPFI_BUILDLINK3_MK)
MPFI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mpfi+=	mpfi>=1.5.1
BUILDLINK_ABI_DEPENDS.mpfi+=	mpfi>=1.5.1
BUILDLINK_PKGSRCDIR.mpfi?=	../../wip/mpfi

.include "../../math/mpfr/buildlink3.mk"
.endif # MPFI_BUILDLINK3_MK

BUILDLINK_TREE+=	-mpfi
