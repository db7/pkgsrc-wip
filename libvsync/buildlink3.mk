BUILDLINK_TREE+=        libvsync

.if !defined(LIBVSYNC_BUILDLINK3_MK)
LIBVSYNC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libvsync+=    libvsync>=4.2.0
BUILDLINK_ABI_DEPENDS.libvsync+=    libvsync>=4.2.0
BUILDLINK_PKGSRCDIR.libvsync?=      ../../wip/libvsync

.endif # LIBVSYNC_BUILDLINK3_MK

BUILDLINK_TREE+=        -libvsync
