# $NetBSD$

BUILDLINK_TREE+=	partio

.if !defined(PARTIO_BUILDLINK3_MK)
PARTIO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.partio+=	partio>=1.17.1
BUILDLINK_PKGSRCDIR.partio?=	../../wip/partio

.endif	# PARTIO_BUILDLINK3_MK

BUILDLINK_TREE+=	-partio
