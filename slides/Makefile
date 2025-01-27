# $NetBSD$

DISTNAME=	slides-0.9.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=maaslalani/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/maaslalani/slides/
COMMENT=	TODO: Short description of the package
#LICENSE=	# TODO: (see mk/license.mk)

USE_LANGUAGES=  c
BUILD_TARGET= 	build
INSTALL_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/${DISTNAME}/slides \
		${DESTDIR}${PREFIX}/bin/slides

.include "go-modules.mk"

.include "../../mk/bsd.pkg.mk"
.include "../../lang/go/go-module.mk"
