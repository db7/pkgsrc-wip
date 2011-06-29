# $NetBSD: options.mk,v 1.1 2011/06/29 11:22:04 reinoudz70 Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.xfce4-exo
PKG_SUPPORTED_OPTIONS=	hal
PKG_SUGGESTED_OPTIONS=	hal

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mhal)
.include "../../sysutils/hal/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-hal
.else
CONFIGURE_ARGS+=	--disable-hal
.endif
