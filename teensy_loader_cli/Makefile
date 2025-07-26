# $NetBSD$

DISTNAME=	2.3
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_GITHUB:=PaulStoffregen/}
GITHUB_PROJECT=	teensy_loader_cli
GITHUB_TAG=	refs/tags/2.3
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/PaulStoffregen/teensy_loader_cli/
COMMENT=	Teensy loader
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/teensy_loader_cli-2.3
MAKE_FILE=	Makefile.bsd
MAKE_ENV=	OS=NetBSD
BUILD_TARGET=	teensy_loader_cli

do-install:
	mkdir -p ${DESTDIR}/usr/pkg/bin
	${INSTALL} ${WRKSRC}/teensy_loader_cli ${DESTDIR}/usr/pkg/bin

.include "../../mk/bsd.pkg.mk"
