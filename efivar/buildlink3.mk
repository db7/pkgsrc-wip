# $NetBSD$

BUILDLINK_TREE+=	efivar

.if !defined(EFIVAR_BUILDLINK3_MK)
EFIVAR_BUILDLINK3_MK:=

# XXX	BUILDLINK_DEPMETHOD.efivar?=	build

BUILDLINK_API_DEPENDS.efivar+=	efivar>=38
BUILDLINK_PKGSRCDIR.efivar?=	../../wip/efivar
.endif	# EFIVAR_BUILDLINK3_MK

BUILDLINK_TREE+=	-efivar
